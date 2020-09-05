
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<string.h>
struct student
{
char nu[99];
char ss[10][30];
 long long int num; //学号
 char cla[30];  //班级
 char name[30];//姓名
 char xi[30];                //性别
 int s[10];                  //C语言、高数、英语、计算机原理、离散数学
 int zp[10];                 // zp1,zp2总分,总分排名
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
    printf("\n\n\n\n\n\t\t\t\t\t     学生成绩管理系统：\n");
    printf("\t\t\t\t\t\t请进行操作：\n\t\t\t\t\t\t1-新建成绩记录文件\n\t\t\t\t\t\t2-增加学生记录\n");
    printf("\t\t\t\t\t\t3-删除\n\t\t\t\t\t\t4-修改\n\t\t\t\t\t\t5-排序\n\t\t\t\t\t\t6-查询\n\t\t\t\t\t\t7-显示内存记录\n");
    printf("\t\t\t\t\t\t8-从文件获得学生数据\n\t\t\t\t\t\t9-保存到文件\n\t\t\t\t\t\t0-\n\t\t\t\t\t\tEsc-退出程序\n");
    sa=getch();
    if(sa==49)          //新建文件
        f1(std);
    else if(sa==50)     //增加记录
        f2(std);
    else if(sa==51)     //删除
        f3(std);
    else if(sa==52)     //修改
        f4(std);
    else if(sa==53)     //排序
        f5(std);
    else if(sa==54)     //查询
        f6(std);
    else if(sa==55)     //显示
        f7(std);
    else if(sa==56)     //从文件中获得
        f8(std);
    else if(sa==57)     //保存到文件
        f9(std);
    else if(sa==27)     //退出程序
        exit(1);
    goto begin;
    return 0;
 }
void f1(struct student std[])                                                   //新建记录
{
    system("cls");
    int a;
    if(sum!=1)
    {
        printf("\t\t\t内存中有学生的成绩记录，新建文件会\n\t\t\t覆盖掉原有记录，是否将其先进行存储？\n----确认储存请按回车键\n----覆盖请按其他键位");
        a=getche();
        if(a==13)
            f9(std);
        else
            MessageBox(NULL,TEXT("原有记录已被覆盖"),TEXT("原有学生记录"),MB_OK);
    }
    sum=1;
    MessageBox(NULL,TEXT("已成功新建在内存！"),TEXT("新建"),MB_OK);
    return ;
}
 void f2(struct student std[])                                                  //增加学生
 {
     int pai[100];
     int i,t;
     int x;
     int b;
     system("cls");
     while(1)
     {
        printf("\n\n\n\t\t\t请输入学生的学号(输入0终止):\n");
        scanf("%s",&std[sum].nu);
        if(std[sum].nu[0]=='0'&&std[sum].nu[1]==NULL)
                break;
        if(strlen(std[sum].nu)>15)
        {
            MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
            continue;
        }
        std[sum].num=0;
        for(i=0;std[sum].nu[i]!=NULL;i++)
            std[sum].num=std[sum].num*10+std[sum].nu[i]-48;
        if(std[sum].num>999999999999)
        {
            MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
            continue;
        }
        printf("\t\t\t请输入学生的班级:\n");
        do
        {
            scanf("%s",&std[sum].cla);
            if(strlen(std[sum].cla)>10)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(strlen(std[sum].cla)>10);
        printf("\t\t\t请输入学生的姓名:\n");
        do
        {
            scanf("%s",&std[sum].name);
            if(strlen(std[sum].name)>10)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(strlen(std[sum].name)>10);
        printf("\t\t\t请输入学生的性别:\n");
        do
        {
            scanf("%s",&std[sum].xi);
            if(strlen(std[sum].xi)>5)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(strlen(std[sum].xi)>5);
        printf("\t\t\t请输入学生的c语言成绩:\n");
        do{
            std[sum].s[1]=0;
            scanf("%s",&std[sum].ss[1]);
            for(i=0;std[sum].ss[1][i]!=NULL;i++)
                std[sum].s[1]=std[sum].s[1]*10+std[sum].ss[1][i]-48;
            if(std[sum].s[1]>100||std[sum].s[1]<0)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(std[sum].s[1]>100||std[sum].s[1]<0);
        printf("\t\t\t请输入学生的高数成绩:\n");
        do{
            std[sum].s[2]=0;
            scanf("%s",&std[sum].ss[2]);
               for(i=0;std[sum].ss[2][i]!=NULL;i++)
                std[sum].s[2]=std[sum].s[2]*10+std[sum].ss[2][i]-48;
            if(std[sum].s[2]>100||std[sum].s[2]<0)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(std[sum].s[2]>100||std[sum].s[2]<0);
        printf("\t\t\t请输入学生的英语成绩:\n");
         do{
            std[sum].s[3]=0;
            scanf("%s",&std[sum].ss[3]);
            for(i=0;std[sum].ss[3][i]!=NULL;i++)
                std[sum].s[3]=std[sum].s[3]*10+std[sum].ss[3][i]-48;
            if(std[sum].s[3]>100||std[sum].s[3]<0)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(std[sum].s[3]>100||std[sum].s[3]<0);
        printf("\t\t\t请输入学生的计算机原理成绩:\n");
        do{
            std[sum].s[4]=0;
            scanf("%s",&std[sum].ss[4]);
            for(i=0;std[sum].ss[4][i]!=NULL;i++)
                std[sum].s[4]=std[sum].s[4]*10+std[sum].ss[4][i]-48;
            if(std[sum].s[4]>100||std[sum].s[4]<0)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
        }while(std[sum].s[4]>100||std[sum].s[4]<0);
        printf("\t\t\t请输入学生的离散数学成绩:\n");
        do{
            std[sum].s[5]=0;
            scanf("%s",&std[sum].ss[5]);
            for(i=0;std[sum].ss[5][i]!=NULL;i++)
                std[sum].s[5]=std[sum].s[5]*10+std[sum].ss[5][i]-48;
            if(std[sum].s[5]>100||std[sum].s[5]<0)
                MessageBox(NULL,TEXT("输入为非法数据！请重新输入！"),TEXT("警告"),MB_OK);
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
  void f3(struct student std[])                                                 //删除
{
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
     int i,t=0;
     int fa;
     int a;
     long long int xue;
     int ming;
     char name[30];
     printf("\t\t\t\t\t删除：\n");
     printf("\t\t请选择删除方式：1-按学号删除、2-按姓名删除、3-按总分名次删除：\n");
     fa=getch();
     if(fa==49)
     {
         printf("请输入要删除的学号，按回车键结束：\n");
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
         printf("请输入要删除的姓名，按回车键结束：\n");
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
         printf("请输入要删除的名次，按回车键结束：\n");
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
        MessageBox(NULL, TEXT("未找到,请检查输入！"), TEXT("错误"), MB_OK);         //跳出窗口
        return;
     }
    printf("待删除者信息为：\n");
    printf("学号\t  班级      姓名\t\t性别   C语言  高数   英语  计算机原理 离散数学\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("确认删除请按回车键，取消请按其他键位\n");
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
    MessageBox(NULL, TEXT("删除成功！"), TEXT("删除"), MB_OK);         //跳出窗口
    return ;
}
void f4(struct student std[])                                                   //修改信息
{
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
    long long int gai;
    int i,t=0;
    int ji;
    int a;
    system("cls");
    printf("请键入被修改者学号（以回车键结束）：\n");
    scanf("%lld",&gai);
    for(i=1;i<=sum;i++)
        if(std[i].num==gai)
            t=i;
    if(t==0)
    {
        MessageBox(NULL, TEXT("未找到待修改者！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
    printf("待修改者信息为：\n");
    printf("学号\t  班级      姓名\t\t性别   C语言  高数   英语  计算机原理 离散数学\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("确认修改请按回车键，取消修改请按其他键位\n");
    a=getch();
    if(a==13)
    {
         printf("请依次键入修改者C语言、高数、英语、计算机原理、离散数学各科成绩\n");
        scanf("%d%d%d%d%d",&std[t].s[1],&std[t].s[2],&std[t].s[3],&std[t].s[4],&std[t].s[5]);
        MessageBox(NULL, TEXT("修改成功"), TEXT("修改学生信息及成绩"), MB_OK);         //跳出窗口
    }
    printf("继续修改请按回车，返回主菜单请按Esc键\n");
    ji=getch();
    if(ji==13)
        f4(std);
    else
        return;
}
void f5(struct student std[])                                                   //分方式排序
{
    int i,t;
    int shun;
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
    printf("\n\n\n\t  请选择排序方式：\n\t1-按学号的升序进行排序\n\t2-按学号的降序进行排序\n");
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
    MessageBox(NULL, TEXT("排序完成！"), TEXT("排序"), MB_OK);                   //跳出窗口
    return ;
}
 void f6(struct student std[])                                                  //分方式查询
 {
     system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
     int i,t=0;
     int fa;
     long long int xue;
     int ming;
     char name[30];
     printf("\t\t\t\t\t查询：\n");
     printf("\t\t请选择查询方式：1-学号查询、2-姓名查询、3-总分名次查询：\n");
     fa=getch();
     if(fa==49)
     {
         printf("请输入要查询的学号，按回车键结束：\n");
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
         printf("请输入要查询的姓名，按回车键结束：\n");
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
         printf("请输入要查询的名次，按回车键结束：\n");
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
        MessageBox(NULL, TEXT("未找到,请检查输入！"), TEXT("错误"), MB_OK);         //跳出窗口
        return;
     }
    printf("学号\t  班级      姓名\t\t性别   C语言  高数   英语  计算机原理 离散数学\n");
    printf("%-10lld%-10s%-20s%-8s%-8d%-8d%-8d%-8d%-8d\n",std[t].num,std[t].cla,std[t].name,std[t].xi,std[t].s[1],std[t].s[2],std[t].s[3],std[t].s[4],std[t].s[5]);
    printf("\t\t\t按任意键返回主菜单......");
    t=getch();
     return ;
 }
 void f7(struct student std[])                                       //显示
 {
    system("cls");
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
    int i,t;
    printf("\n\n\t*************************************************************************************************\n");
    printf("\t\t\t\t\t\t   学生信息及成绩\n");
    printf("\t学号\t  班级      姓名\t\t性别     C语言  高数   英语  计算机原理 离散数学  总分   名次\n");
    for(i=1;i<sum;i++)
        printf("\t%-10lld%-10s%-20s%-8s   %-8d%-8d%-8d%-8d%-8d%-8d%-8d\n",std[i].num,std[i].cla,std[i].name,std[i].xi,std[i].s[1],std[i].s[2],std[i].s[3],std[i].s[4],std[i].s[5],std[i].zp[1],std[i].zp[2]);
    printf("\t\t按任意键返回主菜单......");
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
        MessageBox(NULL, TEXT("没有找到学生成绩文件！"), TEXT("错误"), MB_OK);         //跳出窗口
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
    MessageBox(NULL, TEXT("从文件获得数据成功！"), TEXT("从文件获得数据"), MB_OK);         //跳出窗口
    fclose(fp);
    return ;
}
void f9(struct student std[])
{
    if(sum==1)
    {
        MessageBox(NULL, TEXT("内存中无记录！"), TEXT("错误"), MB_OK);         //跳出窗口
        return ;
    }
    int a;
    printf("存储方式：\n1-默认文件名存储\n2-自定义文件名存储\n");
    a=getch();
    FILE * fp;
    if(a==50)
    {
        char wenjian[100];
        printf("请输入您想要存放在或者新建的文本文件名字，例如student.txt\n");
        gets(wenjian);
        fp=fopen(wenjian,"w");
    }
    else
        fp=fopen("student1.txt","w");
    int i;
    fprintf(fp,"\n\n\t*************************************************************************************************\n");
    fprintf(fp,"\t\t\t\t\t\t   学生信息及成绩\n");
    fprintf(fp,"\t学号\t  班级      姓名\t\t性别     C语言  高数   英语  计算机原理 离散数学  总分   名次\n");
    for(i=1;i<sum;i++)
        fprintf(fp,"\t%-10lld%-10s%-20s%-8s   %-8d%-8d%-8d%-8d%-8d%-8d%-8d\n",std[i].num,std[i].cla,std[i].name,std[i].xi,std[i].s[1],std[i].s[2],std[i].s[3],std[i].s[4],std[i].s[5],std[i].zp[1],std[i].zp[2]);
    fclose(fp);
    MessageBox(NULL, TEXT("保存数据成功！"), TEXT("保存数据"), MB_OK);         //跳出窗口
    return ;
}
