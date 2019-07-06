#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int count;
double score[3];//英语、数学、计算机课程平均成绩；
struct Students{
    unsigned num;
    char name[10];
    int score[4];//English,math,computer;
}student[50];
void first();
void input();
void cal();
void find(int ch);
void output(int c);
void stu_ave();
void cla_ave();
void sort();//将数据按照学号排序；
int getinfo();

int main()
{
    int in;
    count=0;
    for(int i=0;i<3;i++) score[i]=-1;
    for(int i=0;i<50;i++) student[i].score[3]=-1;
    while(1){
        system("cls");//清屏
        first();
        printf("请输入：");
        scanf("%d",&in);
        if(in==0) break;
        else{
            system("cls");
            switch(in){
                case 1:
                    input();//成绩输入
                    break;
                case 2:
                    getinfo();
                    cal();//数据计算
                    break;
                case 3:
                    getinfo();
                    find(0);//数据查找
                    break;
                case 4:
                {   int c=getinfo();
                    output(c);//输出成绩
                    break;
                }
            }
        }
    }
    return 0;
}
void first()  //起始页面
{
    printf("*******学生成绩统计程序*******\n");
    printf("\n");
    printf("***** 按1 ----- 成绩输入 *****\n");
    printf("***** 按2 ----- 数据计算 *****\n");
    printf("***** 按3 ----- 数据查找 *****\n");
    printf("***** 按4 ----- 输出成绩 *****\n");
    printf("***** 按0 ----- 退出程序 *****\n");
    printf("\n");
}
int getinfo()
{
    FILE *fp;
    count=0;
    if((fp=fopen("student.txt","r"))==NULL) {printf("Open File Error!");exit(0);}
    else{
        while(!feof(fp)){
            fscanf(fp,"%u%s%d%d%d\n",&student[count].num,&student[count].name,&student[count].score[0],&student[count].score[1],&student[count].score[2]);
            count++;
        }
    }
    if(fclose(fp)){printf("Can not close the file!\n");exit(0);}
    return count;
}

void input()  //成绩输入
{
    FILE *fp;
    while(1){
        if(count>=50) printf("Full!\n");
        else{
            printf("请输入学号：");
            scanf("%u",&student[count].num);
            printf("\n请输入姓名：");
            scanf("%s",student[count].name);
            printf("\n请输入英语成绩：");
            scanf("%d",&student[count].score[0]);
            printf("请输入数学成绩：");
            scanf("%d",&student[count].score[1]);
            printf("请输入计算机成绩：");
            scanf("%d",&student[count].score[2]);
            printf("\n");
            if(count>0) sort();
            if((fp=fopen("student.txt","w"))==NULL) {printf("Open File Error!");exit(0);}
            else{
                for(int i=0;i<=count;i++){
                    fprintf(fp,"%u %s %d %d %d\n",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
                }
            }
            count++;
            if(fclose(fp)){printf("Can not close the file!\n");exit(0);}
        }
        printf("***** 按1 ----- 输入下一个 *****\n");
        printf("***** 按0 ----- 返回上一层 *****\n");
        printf("请输入：");
        int k;
        scanf("%d",&k);
        if(k) system("cls");
        else break;
    }
}
void sort()//按学号从小到大排序
{
    int index=count;
    struct Students t;
    for(int i=0;i<=count;i++){
        if(student[index].num < student[i].num) {
            t=student[index];
            for(int j=count-1;j>=i;j--){
                student[j+1]=student[j];
            }
            student[i]=t;
            break;
        }
    }
}



void cal()//数据计算
{
    int in;
    while(1){
        int k;
        printf("***** 按1 ----- 学生平均 *****\n");
        printf("***** 按2 ----- 课程平均 *****\n");
        printf("***** 按0 ----- 返回上层 *****\n");
        printf("\n请输入：");
        scanf("%d",&in);
        system("cls");
        if(in==1){
            stu_ave();
            printf("学生平均成绩已经全部计算完毕，是否查阅？\n\n");
            printf("*********** 按1 ------- 是 ***********\n");
            printf("*********** 按0 ------- 否 ***********\n");
            printf("请输入：");
            scanf("%d",&k);
            if(k) {find(in);break;}
            system("cls");
        }
        else if(in==2){
            cla_ave();
            printf("课程平均成绩已经全部计算完毕，是否查阅？\n\n");
            printf("*********** 按1 ------- 是 ***********\n");
            printf("*********** 按0 ------- 否 ***********\n");
            printf("请输入：");
            scanf("%d",&k);
            if(k) find(in);
            system("cls");
        }
        else if(in==0) break;
        else;
    }
}
void stu_ave()//学生平均
{
    int ave;
    for(int i=0;i<count;i++){
        ave=(student[i].score[0]+student[i].score[1]+student[i].score[2])/3;
        student[i].score[3]=ave;
    }
}
void cla_ave()//课程平均
{
    double en=0,math=0,compu=0;
    for(int i=0;i<count;i++){
        en+=student[i].score[0];
        math+=student[i].score[1];
        compu+=student[i].score[2];
    }
    score[0]=en*1.0/count; score[1]=math*1.0/count; score[2]=compu*1.0/count;
}


void find(int ch)
{
    int in,num;
    system("cls");
    if(ch==0){
        while(1){
            printf("***** 按1 ----- 查学生信息 *****\n");
            printf("***** 按2 ----- 查课程平均分 *****\n");
            printf("***** 按0 ----- 返回上一层 *****\n");
            printf("\n");
            printf("请输入：");
            scanf("%d",&in);
            if(in==1 || in==2) find(in);
            if(in==0) break;
            system("cls");
        }
    }
    else if(ch==1){     //输入学号查找学生信息
        int flag=1;
        printf("请输入学号:");
        scanf("%u",&num);
        for(int i=0;i<count;i++){
            if(num==student[i].num) {
                printf("%u \n%s \n英语：%d \n数学：%d \n计算机：%d \n平均分",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
                if(student[i].score[3]==-1) printf("未计算\n");
                else printf("：%d \n",student[i].score[3]);
                flag=0;
                break;
            }
        }
        if(flag) printf("没有该学生信息。\n");
        printf("\n");
        printf("***** 按1 ----- 查询下一个 *****\n");
        printf("***** 按0 ----- 返回上一层 *****\n");
        printf("请输入：");
        scanf("%d",&in);
        if(in) find(1);
        system("cls");
    }
    else if(ch==2){     //查课程平均分
        printf("请输入课程:\n");
        printf("***** 按1 ------ 英语 ******\n");
        printf("***** 按2 ------ 数学 ******\n");
        printf("***** 按3 ----- 计算机 *****\n");
        printf("***** 按0 ------ 返回 ******\n");
        printf("\n");
        printf("请输入：");
        scanf("%d",&in);
        if(in==1 || in==2 || in==3) {
            if(score[in-1]==-1) printf("未进行计算");
            else printf("%.2f\n",score[in-1]);
            printf("\n");
            printf("***** 按1 ----- 查询下一个 *****\n");
            printf("***** 按0 ----- 返回上一层 *****\n");
            printf("请输入：");
            scanf("%d",&in);
            if(in) find(2);
            system("cls");
        }
    }
    else;
}


void output(int c)
{
    for(int i=0;i<c;i++){
        printf("%u %s %d %d %d\n",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
    }
    printf("\n");
    system("pause");
}
