
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<string.h>
struct student
{
char nu[99];
char ss[10][30];
 long long int num; //ѧ��
 char cla[30];  //�༶
 char name[30];//����
 char xi[30];                //�Ա�
 int s[10];                  //C���ԡ�������Ӣ������ԭ����ɢ��ѧ
 int zp[10];                 // zp1,zp2�ܷ�,�ܷ�����
 }std[100];
 int sum=1;
 void f1(struct student std[]);
 void f2(struct student std[]);
 void f3(struct student std[]);
 void f4(struct student std[]);
 void f5(struct student std[]);
 void f6(struct student std[]);
 void f7(struct student std[]);
 void f8(struct student std[]);
 void f9(struct student std[]);
 int main()
{
    int i,t;
    int sa;
    begin:system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t     ѧ���ɼ�����ϵͳ��\n");
    printf("\t\t\t\t\t\t����в�����\n\t\t\t\t\t\t1-�½��ɼ���¼�ļ�\n\t\t\t\t\t\t2-����ѧ����¼\n");
    printf("\t\t\t\t\t\t3-ɾ��\n\t\t\t\t\t\t4-�޸�\n\t\t\t\t\t\t5-����\n\t\t\t\t\t\t6-��ѯ\n\t\t\t\t\t\t7-��ʾ�ڴ��¼\n");
    printf("\t\t\t\t\t\t8-���ļ����ѧ������\n\t\t\t\t\t\t9-���浽�ļ�\n\t\t\t\t\t\t0-\n\t\t\t\t\t\tEsc-�˳�����\n");
    sa=getch();
    if(sa==49)          //�½��ļ�
        f1(std);
    else if(sa==50)     //���Ӽ�¼
        f2(std);
    else if(sa==51)     //ɾ��
        f3(std);
    else if(sa==52)     //�޸�
        f4(std);
    else if(sa==53)     //����
        f5(std);
    else if(sa==54)     //��ѯ
        f6(std);
    else if(sa==55)     //��ʾ
        f7(std);
    else if(sa==56)     //���ļ��л��
        f8(std);
    else if(sa==57)     //���浽�ļ�
        f9(std);
    else if(sa==27)     //�˳�����
        exit(1);
    goto begin;
    return 0;
 }
void f1(struct student std[])                                                   //�½���¼
{
    system("cls");
    int a;
    if(sum!=1)
    {
        printf("\t\t\t�ڴ�����ѧ���ĳɼ���¼���½��ļ���\n\t\t\t���ǵ�ԭ�м�¼���Ƿ����Ƚ��д洢��\n----ȷ�ϴ����밴�س���\n----�����밴������λ");
        a=getche();
        if(a==13)
            f9(std);
        else
            MessageBox(NULL,TEXT("ԭ�м�¼�ѱ�����"),TEXT("ԭ��ѧ����¼"),MB_OK);
    }
    sum=1;
    MessageBox(NULL,TEXT("�ѳɹ��½����ڴ棡"),TEXT("�½�"),MB_OK);
    return ;
}
 void f2(struct student std[])                                                  //����ѧ��
 {
     int pai[100];
     int i,t;
     int x;
     int b;
     system("cls");
     while(1)
     {
        printf("\n\n\n\t\t\t������ѧ����ѧ��(����0��ֹ):\n");
        scanf("%s",&std[sum].nu);
        if(std[sum].nu[0]=='0'&&std[sum].nu[1]==NULL)
                break;
        if(strlen(std[sum].nu)>15)
        {
            MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
            continue;
        }
        std[sum].num=0;
        for(i=0;std[sum].nu[i]!=NULL;i++)
            std[sum].num=std[sum].num*10+std[sum].nu[i]-48;
        if(std[sum].num>999999999999)
        {
            MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
            continue;
        }
        printf("\t\t\t������ѧ���İ༶:\n");
        do
        {
            scanf("%s",&std[sum].cla);
            if(strlen(std[sum].cla)>10)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(strlen(std[sum].cla)>10);
        printf("\t\t\t������ѧ��������:\n");
        do
        {
            scanf("%s",&std[sum].name);
            if(strlen(std[sum].name)>10)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(strlen(std[sum].name)>10);
        printf("\t\t\t������ѧ�����Ա�:\n");
        do
        {
            scanf("%s",&std[sum].xi);
            if(strlen(std[sum].xi)>5)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(strlen(std[sum].xi)>5);
        printf("\t\t\t������ѧ����c���Գɼ�:\n");
        do{
            std[sum].s[1]=0;
            scanf("%s",&std[sum].ss[1]);
            for(i=0;std[sum].ss[1][i]!=NULL;i++)
                std[sum].s[1]=std[sum].s[1]*10+std[sum].ss[1][i]-48;
            if(std[sum].s[1]>100||std[sum].s[1]<0)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(std[sum].s[1]>100||std[sum].s[1]<0);
        printf("\t\t\t������ѧ���ĸ����ɼ�:\n");
        do{
            std[sum].s[2]=0;
            scanf("%s",&std[sum].ss[2]);
               for(i=0;std[sum].ss[2][i]!=NULL;i++)
                std[sum].s[2]=std[sum].s[2]*10+std[sum].ss[2][i]-48;
            if(std[sum].s[2]>100||std[sum].s[2]<0)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(std[sum].s[2]>100||std[sum].s[2]<0);
        printf("\t\t\t������ѧ����Ӣ��ɼ�:\n");
         do{
            std[sum].s[3]=0;
            scanf("%s",&std[sum].ss[3]);
            for(i=0;std[sum].ss[3][i]!=NULL;i++)
                std[sum].s[3]=std[sum].s[3]*10+std[sum].ss[3][i]-48;
            if(std[sum].s[3]>100||std[sum].s[3]<0)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(std[sum].s[3]>100||std[sum].s[3]<0);
        printf("\t\t\t������ѧ���ļ����ԭ��ɼ�:\n");
        do{
            std[sum].s[4]=0;
            scanf("%s",&std[sum].ss[4]);
            for(i=0;std[sum].ss[4][i]!=NULL;i++)
                std[sum].s[4]=std[sum].s[4]*10+std[sum].ss[4][i]-48;
            if(std[sum].s[4]>100||std[sum].s[4]<0)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(std[sum].s[4]>100||std[sum].s[4]<0);
        printf("\t\t\t������ѧ������ɢ��ѧ�ɼ�:\n");
        do{
            std[sum].s[5]=0;
            scanf("%s",&std[sum].ss[5]);
            for(i=0;std[sum].ss[5][i]!=NULL;i++)
                std[sum].s[5]=std[sum].s[5]*10+std[sum].ss[5][i]-48;
            if(std[sum].s[5]>100||std[sum].s[5]<0)
                MessageBox(NULL,TEXT("����Ϊ�Ƿ����ݣ����������룡"),TEXT("����"),MB_OK);
        }while(std[sum].s[5]>100||std[sum].s[5]<0);
        std[sum].zp[1]=(std[sum].s[1]+std[sum].s[2]+std[sum].s[3]+std[sum].s[4]+std[sum].s[5]);
        pai[sum]=std[sum].zp[1];
        sum++;
     }
     for(t=1;t<=sum;t++)
     {
         for(i=1;i<sum-t;i++)
         {
             if(pai[i]<pai[i+1])
             {
                 x=pai[i];
                 pai[i]=pai[i+1];
                 pai[i+1]=x;
             }
         }
     }
    for(t=1;t<=sum;t++)
    {
        for(i=1;i<sum;i++)
        {
            if(pai[t]==std[i].zp[1])
            {
                std[i].zp[2]=t;
                pai[t]=-1;
            }
        }
    }
    return ;
}
  void f3(struct student std[])                                                 //ɾ��
{
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
     int i,t=0;
     int fa;
     int a;
     long long int xue;
     int ming;
     char name[30];
     printf("\t\t\t\t\tɾ����\n");
     printf("\t\t��ѡ��ɾ����ʽ��1-��ѧ��ɾ����2-������ɾ����3-���ܷ�����ɾ����\n");
     fa=getch();
     if(fa==49)
     {
         printf("������Ҫɾ����ѧ�ţ����س���������\n");
         scanf("%lld",&xue);
         for(i=1;i<=sum;i++)
         {
             if(std[i].num==xue)
                {t=i;
                break;}
         }
     }
     else if(fa==50)
     {
         printf("������Ҫɾ�������������س���������\n");
         scanf("%s",&name);
        for(i=1;i<=sum;i++)
         {
             if(strcmp(std[i].name,name)==0)
                {t=i;
                break;}
         }
     }
    else if(fa==51)
     {
         printf("������Ҫɾ�������Σ����س���������\n");
         scanf("%d",&ming);
        for(i=1;i<=sum;i++)
         {
             if(ming==std[i].zp[2])
                {t=i;
                break;}
         }
     }
     if(t==0)
     {
        MessageBox(NULL, TEXT("δ�ҵ�,�������룡"), TEXT("����"), MB_OK);         //��������
        return;
     }
    printf("��ɾ������ϢΪ��\n");
    printf("ѧ��\t  �༶      ����\t\t�Ա�   C����  ����   Ӣ��  �����ԭ�� ��ɢ��ѧ\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("ȷ��ɾ���밴�س�����ȡ���밴������λ\n");
    a=getch();
    if(a!=13)
        return ;
     for(i=t;i<sum;i++)
     {
        std[99]=std[i];
        std[i]=std[i+1];
        std[i+1]=std[99];
     }
     sum--;
    MessageBox(NULL, TEXT("ɾ���ɹ���"), TEXT("ɾ��"), MB_OK);         //��������
    return ;
}
void f4(struct student std[])                                                   //�޸���Ϣ
{
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    long long int gai;
    int i,t=0;
    int ji;
    int a;
    system("cls");
    printf("����뱻�޸���ѧ�ţ��Իس�����������\n");
    scanf("%lld",&gai);
    for(i=1;i<=sum;i++)
        if(std[i].num==gai)
            t=i;
    if(t==0)
    {
        MessageBox(NULL, TEXT("δ�ҵ����޸��ߣ�"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    printf("���޸�����ϢΪ��\n");
    printf("ѧ��\t  �༶      ����\t\t�Ա�   C����  ����   Ӣ��  �����ԭ�� ��ɢ��ѧ\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("ȷ���޸��밴�س�����ȡ���޸��밴������λ\n");
    a=getch();
    if(a==13)
    {
         printf("�����μ����޸���C���ԡ�������Ӣ������ԭ����ɢ��ѧ���Ƴɼ�\n");
        scanf("%d%d%d%d%d",&std[t].s[1],&std[t].s[2],&std[t].s[3],&std[t].s[4],&std[t].s[5]);
        MessageBox(NULL, TEXT("�޸ĳɹ�"), TEXT("�޸�ѧ����Ϣ���ɼ�"), MB_OK);         //��������
    }
    printf("�����޸��밴�س����������˵��밴Esc��\n");
    ji=getch();
    if(ji==13)
        f4(std);
    else
        return;
}
void f5(struct student std[])                                                   //�ַ�ʽ����
{
    int i,t;
    int shun;
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    printf("\n\n\n\t  ��ѡ������ʽ��\n\t1-��ѧ�ŵ������������\n\t2-��ѧ�ŵĽ����������\n");
    shun=getch();
    if(shun==49)
    {
        for(i=1;i<=sum;i++)
            for(t=1;t<sum-i;t++)
        {
            if(std[t].num>std[t+1].num)
            {
                std[sum+1]=std[t];
                std[t]=std[t+1];
                std[t+1]=std[sum+1];
            }
        }
    }
    else
    {
        for(i=1;i<=sum;i++)
            for(t=1;t<sum-i;t++)
        {
           if(std[t].num<std[t+1].num)
            {
                std[sum+1]=std[t];
                std[t]=std[t+1];
                std[t+1]=std[sum+1];
            }
        }
    }
    MessageBox(NULL, TEXT("������ɣ�"), TEXT("����"), MB_OK);                   //��������
    return ;
}
 void f6(struct student std[])                                                  //�ַ�ʽ��ѯ
 {
     system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
     int i,t=0;
     int fa;
     long long int xue;
     int ming;
     char name[30];
     printf("\t\t\t\t\t��ѯ��\n");
     printf("\t\t��ѡ���ѯ��ʽ��1-ѧ�Ų�ѯ��2-������ѯ��3-�ܷ����β�ѯ��\n");
     fa=getch();
     if(fa==49)
     {
         printf("������Ҫ��ѯ��ѧ�ţ����س���������\n");
         scanf("%lld",&xue);
         for(i=1;i<=sum;i++)
         {
             if(std[i].num==xue)
                {t=i;
                break;}
         }
     }
     else if(fa==50)
     {
         printf("������Ҫ��ѯ�����������س���������\n");
         scanf("%s",&name);
        for(i=1;i<=sum;i++)
         {
             if(strcmp(std[i].name,name)==0)
                {t=i;
                break;}
         }
     }
    else if(fa==51)
     {
         printf("������Ҫ��ѯ�����Σ����س���������\n");
         scanf("%d",&ming);
        for(i=1;i<=sum;i++)
         {
             if(ming==std[i].zp[2])
                {t=i;
                break;}
         }
     }
     if(t==0)
     {
        MessageBox(NULL, TEXT("δ�ҵ�,�������룡"), TEXT("����"), MB_OK);         //��������
        return;
     }
    printf("ѧ��\t  �༶      ����\t\t�Ա�   C����  ����   Ӣ��  �����ԭ�� ��ɢ��ѧ\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("\t\t\t��������������˵�......");
    t=getch();
     return ;
 }
 void f7(struct student std[])                                       //��ʾ
 {
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    int i,t;
    printf("\n\n\t*************************************************************************************************\n");
    printf("\t\t\t\t\t\t   ѧ����Ϣ���ɼ�\n");
    printf("\tѧ��\t  �༶      ����\t\t�Ա�     C����  ����   Ӣ��  �����ԭ�� ��ɢ��ѧ  �ܷ�   ����\n");
    for(i=1;i<sum;i++)
        printf("\t%-10lld%-10s%-20s%-8s   %-8d%-8d%-8d%-8d%-8d%-8d%-8d\n",std[i].num,std[i].cla,std[i].name,std[i].xi,std[i].s[1],std[i].s[2],std[i].s[3],std[i].s[4],std[i].s[5],std[i].zp[1],std[i].zp[2]);
    printf("\t\t��������������˵�......");
    t=getch();
    return ;
 }
void f8(struct student std[])
{
    FILE * fp=fopen("student.txt","r");
    int pai[100];
    int i,t,x;
    if((fp)==NULL)
    {
        MessageBox(NULL, TEXT("û���ҵ�ѧ���ɼ��ļ���"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    while(fscanf(fp,"%lld %s %s %s %d %d %d %d %d",&std[sum].num,std[sum].cla,std[sum].name,std[sum].xi,&std[sum].s[1],&std[sum].s[2],&std[sum].s[3],&std[sum].s[4],&std[sum].s[5])!=EOF)
    {
        std[sum].zp[1]=(std[sum].s[1]+std[sum].s[2]+std[sum].s[3]+std[sum].s[4]+std[sum].s[5]);
        pai[sum]=std[sum].zp[1];
        sum++;
    }
    for(t=1;t<=sum;t++)
     {
         for(i=1;i<sum-t;i++)
         {
             if(pai[i]<pai[i+1])
             {
                 x=pai[i];
                 pai[i]=pai[i+1];
                 pai[i+1]=x;
             }
         }
     }
    for(t=1;t<=sum;t++)
    {
        for(i=1;i<sum;i++)
        {
            if(pai[t]==std[i].zp[1])
            {
                std[i].zp[2]=t;
                pai[t]=-1;
            }
        }
    }
    MessageBox(NULL, TEXT("���ļ�������ݳɹ���"), TEXT("���ļ��������"), MB_OK);         //��������
    fclose(fp);
    return ;
}
void f9(struct student std[])
{
    if(sum==1)
    {
        MessageBox(NULL, TEXT("�ڴ����޼�¼��"), TEXT("����"), MB_OK);         //��������
        return ;
    }
    int a;
    printf("�洢��ʽ��\n1-Ĭ���ļ����洢\n2-�Զ����ļ����洢\n");
    a=getch();
    FILE * fp;
    if(a==50)
    {
        char wenjian[100];
        printf("����������Ҫ����ڻ����½����ı��ļ����֣�����student.txt\n");
        gets(wenjian);
        fp=fopen(wenjian,"w");
    }
    else
        fp=fopen("student1.txt","w");
    int i;
    fprintf(fp,"\n\n\t*************************************************************************************************\n");
    fprintf(fp,"\t\t\t\t\t\t   ѧ����Ϣ���ɼ�\n");
    fprintf(fp,"\tѧ��\t  �༶      ����\t\t�Ա�     C����  ����   Ӣ��  �����ԭ�� ��ɢ��ѧ  �ܷ�   ����\n");
    for(i=1;i<sum;i++)
        fprintf(fp,"\t%-10lld%-10s%-20s%-8s   %-8d%-8d%-8d%-8d%-8d%-8d%-8d\n",std[i].num,std[i].cla,std[i].name,std[i].xi,std[i].s[1],std[i].s[2],std[i].s[3],std[i].s[4],std[i].s[5],std[i].zp[1],std[i].zp[2]);
    fclose(fp);
    MessageBox(NULL, TEXT("�������ݳɹ���"), TEXT("��������"), MB_OK);         //��������
    return ;
}
