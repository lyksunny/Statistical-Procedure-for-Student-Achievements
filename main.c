#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int count;
double score[3];//Ӣ���ѧ��������γ�ƽ���ɼ���
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
void sort();//�����ݰ���ѧ������
int getinfo();

int main()
{
    int in;
    count=0;
    for(int i=0;i<3;i++) score[i]=-1;
    for(int i=0;i<50;i++) student[i].score[3]=-1;
    while(1){
        system("cls");//����
        first();
        printf("�����룺");
        scanf("%d",&in);
        if(in==0) break;
        else{
            system("cls");
            switch(in){
                case 1:
                    input();//�ɼ�����
                    break;
                case 2:
                    getinfo();
                    cal();//���ݼ���
                    break;
                case 3:
                    getinfo();
                    find(0);//���ݲ���
                    break;
                case 4:
                {   int c=getinfo();
                    output(c);//����ɼ�
                    break;
                }
            }
        }
    }
    return 0;
}
void first()  //��ʼҳ��
{
    printf("*******ѧ���ɼ�ͳ�Ƴ���*******\n");
    printf("\n");
    printf("***** ��1 ----- �ɼ����� *****\n");
    printf("***** ��2 ----- ���ݼ��� *****\n");
    printf("***** ��3 ----- ���ݲ��� *****\n");
    printf("***** ��4 ----- ����ɼ� *****\n");
    printf("***** ��0 ----- �˳����� *****\n");
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

void input()  //�ɼ�����
{
    FILE *fp;
    while(1){
        if(count>=50) printf("Full!\n");
        else{
            printf("������ѧ�ţ�");
            scanf("%u",&student[count].num);
            printf("\n������������");
            scanf("%s",student[count].name);
            printf("\n������Ӣ��ɼ���");
            scanf("%d",&student[count].score[0]);
            printf("��������ѧ�ɼ���");
            scanf("%d",&student[count].score[1]);
            printf("�����������ɼ���");
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
        printf("***** ��1 ----- ������һ�� *****\n");
        printf("***** ��0 ----- ������һ�� *****\n");
        printf("�����룺");
        int k;
        scanf("%d",&k);
        if(k) system("cls");
        else break;
    }
}
void sort()//��ѧ�Ŵ�С��������
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



void cal()//���ݼ���
{
    int in;
    while(1){
        int k;
        printf("***** ��1 ----- ѧ��ƽ�� *****\n");
        printf("***** ��2 ----- �γ�ƽ�� *****\n");
        printf("***** ��0 ----- �����ϲ� *****\n");
        printf("\n�����룺");
        scanf("%d",&in);
        system("cls");
        if(in==1){
            stu_ave();
            printf("ѧ��ƽ���ɼ��Ѿ�ȫ��������ϣ��Ƿ���ģ�\n\n");
            printf("*********** ��1 ------- �� ***********\n");
            printf("*********** ��0 ------- �� ***********\n");
            printf("�����룺");
            scanf("%d",&k);
            if(k) {find(in);break;}
            system("cls");
        }
        else if(in==2){
            cla_ave();
            printf("�γ�ƽ���ɼ��Ѿ�ȫ��������ϣ��Ƿ���ģ�\n\n");
            printf("*********** ��1 ------- �� ***********\n");
            printf("*********** ��0 ------- �� ***********\n");
            printf("�����룺");
            scanf("%d",&k);
            if(k) find(in);
            system("cls");
        }
        else if(in==0) break;
        else;
    }
}
void stu_ave()//ѧ��ƽ��
{
    int ave;
    for(int i=0;i<count;i++){
        ave=(student[i].score[0]+student[i].score[1]+student[i].score[2])/3;
        student[i].score[3]=ave;
    }
}
void cla_ave()//�γ�ƽ��
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
            printf("***** ��1 ----- ��ѧ����Ϣ *****\n");
            printf("***** ��2 ----- ��γ�ƽ���� *****\n");
            printf("***** ��0 ----- ������һ�� *****\n");
            printf("\n");
            printf("�����룺");
            scanf("%d",&in);
            if(in==1 || in==2) find(in);
            if(in==0) break;
            system("cls");
        }
    }
    else if(ch==1){     //����ѧ�Ų���ѧ����Ϣ
        int flag=1;
        printf("������ѧ��:");
        scanf("%u",&num);
        for(int i=0;i<count;i++){
            if(num==student[i].num) {
                printf("%u \n%s \nӢ�%d \n��ѧ��%d \n�������%d \nƽ����",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
                if(student[i].score[3]==-1) printf("δ����\n");
                else printf("��%d \n",student[i].score[3]);
                flag=0;
                break;
            }
        }
        if(flag) printf("û�и�ѧ����Ϣ��\n");
        printf("\n");
        printf("***** ��1 ----- ��ѯ��һ�� *****\n");
        printf("***** ��0 ----- ������һ�� *****\n");
        printf("�����룺");
        scanf("%d",&in);
        if(in) find(1);
        system("cls");
    }
    else if(ch==2){     //��γ�ƽ����
        printf("������γ�:\n");
        printf("***** ��1 ------ Ӣ�� ******\n");
        printf("***** ��2 ------ ��ѧ ******\n");
        printf("***** ��3 ----- ����� *****\n");
        printf("***** ��0 ------ ���� ******\n");
        printf("\n");
        printf("�����룺");
        scanf("%d",&in);
        if(in==1 || in==2 || in==3) {
            if(score[in-1]==-1) printf("δ���м���");
            else printf("%.2f\n",score[in-1]);
            printf("\n");
            printf("***** ��1 ----- ��ѯ��һ�� *****\n");
            printf("***** ��0 ----- ������һ�� *****\n");
            printf("�����룺");
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
