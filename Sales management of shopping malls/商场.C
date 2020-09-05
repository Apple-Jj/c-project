// #include <stdio.h>
//  int main(){
    
//     printf("Hello World");
    
//     return 0 ;
// }


#include<stdio.h>  //头文件
#include<string.h> //头文件
#include<stdlib.h> //头文件
#define M 100      //货物种类
#define N 100      //顾客数目
struct goods       //单个货物信息格式
{
    int  number;   //产品编号
    char name[20]; //产品名称
    int  price1;   //进价（或利润）
    int  price2;   //售价
    int  amount;   //数量
};
struct orderlist           //订单格式
{
    struct goods L[M];
};
struct customer            //客户信息内容和格式
{
    char name[20];         //姓名
    char password[6];      //服务密码
    int count;             //订单号
};
struct customer khl[N];    //所有客户信息
struct goods base[M];      //库存信息
struct orderlist odl[10*N];//订单表
struct goods lackl[M];     //缺货表
struct goods suml[M+1];    //销售报表
int PP=0;                  //订单编号
int QQ=0;                   //客户编号    
int goodssum=0;              //货物总数


int main()                    //主函数开始!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
{
    int SysUseWay();        //系统使用说明函数声明
    int chushihua();       //系统初始化函数声明
    int welcome();        //欢迎界面函数声明
    int kh();            //客户函数声明
    int buyer();        //采购部函数声明
    int manager();     //公司经理函数声明
    int goodbye();    //欢送函数声明
    int n,m=9;       //变量声明
    SysUseWay();    //系统使用说明书
    chushihua();   //系统初始化
    while(m==9)   //循环三岔口
    {
    welcome();  //欢迎界面
    scanf("%d",&n);
    switch(n) //各奔东西
    {
    case 0 : ;break;
    case 1 : kh(); break;       //客户之家
    case 2 : buyer(); break;    //采购之家
    case 3 : manager(); break;  //经理之家
    default : printf("输入错误!请退出重从新输入");
    }
    if(n==0)                   
        break;
    printf("              继续进入主界面请按 9  退出请按0\n");
    scanf("%d",&m);
    }
    goodbye();                  //欢送界面
    return 0;
}                               //主函数结束!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                       

int SysUseWay()                 //系统使用说明书函数定义
{
    FILE *fp;
    fp=fopen("D://商品销售系统使用说明书.txt","w");
    fprintf(fp,"                                                  商品销售系统使用说明书\n");
    fprintf(fp,"    作者  谢斌龙    学号  17407438   长治学院计算机系网络工程1701班   2019.9.10\n");
    fprintf(fp,"    主要分为三个模块。客户--销售部门--公司经理。\n");
    fprintf(fp,"    1--客户。客户主要是通过该系统进行订货。进入系统后，需要注册，登陆。系统会自主分配\n");
    fprintf(fp,"一个服务编号给客户，由客户自己设定密码。订购之后，可以登录查询自己的订货情况.不足之处\n");
    fprintf(fp,"在于该系统是一次性的---关闭系统之后，系统会丢失一切数据。这涉及数据库的知识，恕我现在\n");
    fprintf(fp,"无能为力。还有，每一个服务编号只能对应一个订货单，即客户每定一次货就得重新注册一次,否\n");
    fprintf(fp,"则就会覆盖以前的数据。\n");
    fprintf(fp,"    2--采购部门。主管仓库，查看处理缺货，进货。使用该系统前，首先必须由采购部门建立仓\n");
    fprintf(fp,"库。填写货物名称，进价，售价，库存数量。货物编号由系统自主按序分配。接下来，采购部门需\n");
    fprintf(fp,"要经常查看是否缺货。及时进货。\n");
    fprintf(fp,"    3--经理只需要抽时间查看一下销售报表。了解每一种货物的销售情况，以及总的销售利润。\n");
    fprintf(fp,"\n");
    fclose(fp);
    printf("................................................................................\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    return 0;
}



int welcome()                   //欢迎界面函数定义
{
    
    printf("................................................................................\n");
    printf("\n");
    printf("                      ~~~~~~~~欢迎使用商品销售系统~~~~~~~~\n");
    printf("\n");
    printf("..............................................................................\n");
    printf("                              公司客户请按       1\n");
    printf("\n");
    printf("..............................................................................\n");
    printf("                              采购人员请按       2\n");
    printf("\n");
    printf("...............................................................................\n");
    printf("                              公司经理请按       3\n");
    printf("\n");
    printf("................................................................................");
    printf("\n");
    printf("                              退出主界面请按     0\n");
    printf("\n");
    printf("\n");
    printf("................................................................................\n");
    return 0;
}


int chushihua()                  //初始化函数
{
    int i=0,j=0;
    for(i=0;i<M;i++)
    {
     suml[i].number=lackl[i].number=base[i].number=-1;
     base[i].amount=0;
     base[i].price1=base[i].price2=0;
     lackl[i].amount=0;
     suml[i].price1=0;
     suml[i].amount=0;
    }
    suml[M].price1=0;
    for(i=0;i<N;i++)
    khl[i].count=-1;
    for(i=0;i<10*N;i++)
    {
        for(j=0;j<M;j++)
        {
        odl[i].L[j].number=j;
        odl[i].L[j].amount=0;
        odl[i].L[j].price1=base[j].price1;
        odl[i].L[j].price2=base[j].price2;
        }
    }
    
    return 0;
}



int goodbye()                 //欢送界面函数定义
{
    printf("                 ~~~~感谢您使用商品销售系统~~~~\n");
    printf(".........................................................................\n");
    printf("作者    谢斌龙     学号    17407438    长治学院计算机系网络工程1701班 \n");
    printf(".........................................................................\n");
    printf("\n");
    printf(".........................................................................\n");
    return 0;
}
int buyer()                 //采购函数
{
    int welcomebuyer();     //欢迎函数
    int buildbaser();       //仓库建设
    int solvelack();        //查询缺货情况
    int chackbase();        //查询仓库情况
    int n;
    int m=9;
    while(m==9)             //循环三岔口
    {
    welcomebuyer();             //欢迎欢迎
    scanf("%d",&n);             //各奔东西
    switch(n)
    {
    case 0 : ;break;            //退出
    case 1: solvelack();break;  //查缺货
    case 2: buildbaser();break; //建设仓库
    case 3: chackbase();break;  //检查仓库
    default :printf("输入错误!\n");
    }
    if(n==0)
        break;
    printf("              继续采购请按 9  否则请按0\n");
    scanf("%d",&m);
    }
    return 0;
}
    

int welcomebuyer()
{
    printf("................................................................................\n");
    printf("\n");
    printf("                      ~~~~~~~~欢迎来到采购之家~~~~~~~~\n");
    printf("\n");
    printf("..............................................................................\n");
    printf("                              处理缺货                请按   1\n");
    printf("\n");
    printf("..............................................................................\n");
    printf("                              进货                    请按   2\n");
    printf("\n");
    printf("...............................................................................\n");
    printf("                              查询当前存货情况        请按   3\n");
    printf("\n");
    printf("................................................................................");
    printf("                              退出采购                请按   0\n");
    printf("\n");
    printf("\n");
    printf("................................................................................\n");    
return 0;
}


int buildbaser()                //采购函数--进货函数
{
    int i=0;
    printf("            若想停止进货,请在货物数量上输入 0\n\n");
    for(i=0;i<M;i++)
    {
        printf("\n货物名称:");
        scanf("%s",base[i].name);
        base[i].number=i;
        printf("\n货物数量:");
        scanf("%d",&base[i].amount);
        if(base[i].amount<=0){
            base[i].amount=0;
            break;
        }
        goodssum+=base[i].amount;
        printf("\n货物进价:");
        scanf("%d",&base[i].price1);
        printf("\n货物售价:");
        scanf("%d",&base[i].price2);
        }
    return 0;
}


int chackbase()                //采购函数---查询当前存货函数
{
    int i=0;
    printf("................................................................................\n");
    if(goodssum==0)
    {
        printf("           仓库没货!!!         请采购部门及时进货!!!\n");
        return 0;
    }
    for(i=0;i<M;i++)
    {
        if(base[i].amount>0){
              printf("................................................................................\n");
              printf("货物编号  货物名称             货物数量          进价       售价\n");
              printf(" %3d      %-20s %6d          %6d     %6d \n",base[i].number,base[i].name,base[i].amount,base[i].price1,base[i].price2);
              printf("................................................................................\n");
        }
        else
            continue;
    }
    printf("................................................................................\n");
    return 0;
}



int solvelack()                //采购函数--处理缺货函数
{
    int i=0,k=0;
    int printlack();           //采购函数--处理缺货函数--查看函数声明
    int supplement();          //采购函数--处理缺货函数--添货函数声明
    printlack();               //查看是否缺货
    printf("           如果需要进货，请按1  ； 否则，请按0   \n");
    scanf("%d",&k);
    switch(k)
    {
    case 1:supplement();break;
    case 0:;break;
    default :printf("输入错误!\n");
    }
    return 0;
}
int printlack()                //采购函数--处理缺货函数--查看函数定义
{
    int i=0,count=0;
    if(goodssum==0){
          printf("                  !!!仓库没货!!!请采购人员及时进货!!!\n");
          return 0;
          }
    printf("................................................................................\n");
    for(i=0;i<M;i++)
    {
        if(lackl[i].amount==0){
            count++;
            continue;
         }
        else{
         printf("................................................................................\n");
         printf("货物编号  货物名称             缺货数量\n");
         printf(" %3d      %-20s %6d          \n",lackl[i].number,base[i].name,lackl[i].amount);
        }
    }
    printf("................................................................................\n");
    if(count==M)
        printf("              ~~~不缺~~~货物充足~~~\n");
    else 
        printf("                    缺!   缺!   缺!\n");
return 0;
}
int supplement()              //采购函数--处理缺货函数--添货函数定义
{
    int i=0,j=1;
    int printlack();
    printlack();
    printf("     若想停止进货，请在货物数量上输入0\n");
    while(j>0)
    {
        printf("产品编号\n");
        scanf("%d",&i);
        while(i>=M){
        printf("此货物不存在，请重新输入\n");
        scanf("%d",&i);}
        base[i].number=i;
        printf("产品名称:\n");
        scanf("%s",base[i].name);
        printf("进货数量:\n");
        scanf("%d",&j);
        if(j>0){
           base[i].amount+=j;
           goodssum+=j;
        }
        else 
            break;
        printf("\n货物进价:");
        scanf("%d",&base[i].price1);
        printf("\n货物售价:");
        scanf("%d",&base[i].price2);
    }
    return 0;
}



int kh()                          //客户函数
{

int login();                      //客户函数--登陆函数声明
int registe();                    //客户函数--注册函数声明
int welcomekh();                  //客户函数--欢迎函数声明
int searchkh(int falg);           //客户函数--查询订货情况的函数声明
int order(int falg);              //客户函数--订货函数声明
int i,k=0,flag=0;
int n=9,m=9;
welcomekh();                     //欢迎欢迎
while(m==9)                      //登陆？注册循环二岔路
{
printf("        登陆请按1，          注册请按2,          否则请按 0\n");                    
scanf("%d",&i);                  
switch(i)
{
case 0 : ;break;
case 1 : flag=login(); break;
case 2 : registe(); break;
default :printf("输入错误!\n");
}
if(i==0)
        break;
printf("           登陆或注册请按 9  否则请按0\n");
scanf("%d",&m);
}

while(n==9)                      //订购？查询循环二岔路
{
printf("         查询请按 1,   订购请按 2,      否则请按 0\n");
scanf("%d",&i);
switch(i)
{
case 0 : ;break;
case 1 : searchkh(flag); break;
case 2 : order(flag); break;
default :printf("输入错误!\n");
}
if(i==0)
    break;
printf("           继续查询或订购请按 9  否则请按0\n");
scanf("%d",&n);
}
return 0;
}


int welcomekh()                    //客户函数---欢迎函数定义
{ 
  
    printf("................................................................................\n");
    printf("\n");
    printf("                      ~~~~~~~~欢迎来到客户之家~~~~~~~~\n");
    printf("\n");
    printf("..............................................................................\n");
    return 0;
}


int login()                       //客户函数---登陆函数定义
{
int n,count=0;
char password[6];
printf("-------------------请输入服务编号-----------------------\n");
scanf("%d",&n);
printf("-------------------请输入六位密码-----------------------\n");
scanf("%s",password);
while(strcmp(password,khl[n].password))
{
    printf("~~~~~~~~~~~~~~~请重新输入六位密码~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("               退出登陆,请输入123456\n");
    scanf("%s",password);
    if(!strcmp(password,"123456"))
        break;
}
if(!strcmp(password,"123456"))
return 0;
else 
return n;
}


int registe()                      //客户函数---注册函数定义
{
printf("~~~~~~~~~~~~~~~~~~~~~~~~~您的服务编号是: %d ,请你一定要记牢您! ~~~~~~~~~~~~~~~~~~~~~~~~~\n",QQ);
printf("\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~请输入您的用户名:~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\n");
scanf("%s",khl[QQ].name);
printf("~~~~~~~~~~~~~~~~~~~~~~~~~请输入六位密码:~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\n");
scanf("%s",khl[QQ].password);
QQ++;
return 0;
}


int searchkh(int flag)             //客户函数---查询函数定义
{
int n,i=0;
n=flag;
printf("................................................................................\n");
printf("               Hello   %s   您的服务编号是: %d\n",khl[n].name,n);
printf("................................................................................\n");
if(khl[n].count!=-1){
    for(i=0;i<M;i++){
        if(odl[khl[n].count].L[i].amount==0)
            i++;
        else{
             printf("................................................................................\n");
             printf("货物编号  货物名称             订货数量          单价\n");
             printf(" %3d      %-20s %6d          %6d\n",base[i].number,base[i].name,odl[khl[n].count].L[i].amount,base[i].price2);
             printf("................................................................................\n");
        }
           
    }
}
else{
      printf("\n");
      printf("................................................................................\n");
      printf("                                您当前没有订货。                                \n");
      printf("................................................................................\n");
}
printf("................................................................................\n");
return 0;
}



int order(int flag)              //客户函数---订购函数
{
int i=0,k=0,m=0,n=0,count=0;
printf("\n");
n=flag;
printf("货物编号  货物名称               售价\n");
printf("\n");
for(i=0;i<M;i++){
    if(base[i].number==-1){
        count++;
        continue;}
    else
      printf(" %3d      %-20s %6d\n",base[i].number,base[i].name,base[i].price2);
}
if(count==M)
{
    printf("仓库现在没货，请稍后再来。麻烦您通知采购部门及时补货。。。谢谢。。。\n");
    return 0;
}
printf("请输入产品编号和数量,若想结束,在订购数量上输入 0 \n");
printf("产品编号\n");
scanf("%d",&k);
while((k>=M)||(base[k].number==-1)){
    printf("此货物不存在，请重新输入\n");
    scanf("%d",&k);}
printf("数量\n");
scanf("%d",&m);
while(m>0)
{
    if(base[k].amount<m)
    {
    odl[PP].L[k].amount=base[k].amount;
    base[k].amount=0;
    printf("存货不足,缺 %d 个,先卖给您%d个,剩下的请您稍后重新注册服务编号再预定!同时麻烦您通知采购部门及时补货。。。谢谢。。。\n",odl[PP].L[k].amount-base[k].amount,base[k].amount);
    lackl[k].amount+=(m-base[k].amount);
    }
    else{
        odl[PP].L[k].amount=m;
        base[k].amount-=m;
    }
    goodssum-=odl[PP].L[k].amount;
    suml[k].price1+=(odl[PP].L[k].amount*(base[k].price2-base[k].price1));
    suml[M].price1+=suml[k].price1;
    suml[k].amount+=odl[PP].L[k].amount;
    printf("产品编号\n");
    scanf("%d",&k);
    while((k>=M)||(base[k].number==-1)){
    printf("此货物不存在，请重新输入\n");
    scanf("%d",&k);}
    printf("订购数量\n");
    scanf("%d",&m);
}
khl[n].count=PP;
PP++;
return 0;
}

int manager()                    //经理函数定义
{

    int i=0;
    for(i=0;i<M;i++)
    {
     if(suml[i].amount==0)
         i++;
     else{
              printf("................................................................................\n");
              printf("货物编号  货物名称           该货物利润\n");
              printf(" %3d      %-20s %6d          \n",suml[i].number,base[i].name,suml[i].price1);
              printf("................................................................................\n");

     }
       
    }
    printf("\n--------------------总货量为  %d  个-----------------------------\n",goodssum);
    printf("\n--------------------总利润为  %d  美元-----------------------------\n",suml[M].price1);
    return 0;
}
FILE *fp=fopen("H:\软件工程\销售\数据.txt","r");




  #include "stdio.h" 
  #include "string.h" 
  #include "stdlib.h"
  #define PR printf 
  #define SC scanf   

struct goods{ 
    long int num;    
    char name[20];    
    char sort[20];    
    long int count;   
    long int price; 
 } goods[200];  

int k,n,i;   
void main (){      
    void input(); 
    void sequence(); 
    void purchase();    
    void sell();     
    void edit();     
    oid correct();    
    void search();    
    void scan();     
    void reserve();  
    void exit();      
    PR("\n     ******************************************************************\n     *\t\t\t\t\t\t\t\t      *\n");
    PR("     *    ▏▎▍ ▌  ▋  ▊   █   ▇   ▆  ▅  ▄  ▃ ▂  ▁         *"); 
    PR("\n     *\t\t\t\t\t\t\t\t      *\n     *       Welcome\t\t\t\t\t\t      *\n     *\t\t\t\t\t\t\t\t      *\n"); 
    PR("     *\t\t    to go into ....\t\t\t\t      * ");  PR("\n     *\t\t\t\t\t\t\t\t      *\n");  
    PR("     *        -the Goods Information Manageaent System-               *\n     *\t\t\t\t\t\t\t\t      *\n "); 
    PR("    *     ▁  ▂  ▃  ▄  ▅  ▆   ▇   █   ▉  ▊  ▋  ▌ ▍▏     *\n");  PR("     *\t\t\t\t\t\t\t\t      *\n     ******************************************************************");  
    PR("\n\n\tPlease press any key to continue:");  
    getch();   
    system("cls"); 
    PR("\n\n   ---$-----$--------$----------$-----------$---------$-------$------$-----$---");  
    PR("\n    系统使用--温馨提示:\n\n     →商品编号、数量、单价：采用十进制数，规定长度最长为8位；\n\n        →商品名称为26位字母组成字符串，长度最长为20位；\n\n\t  →商品类别：以26个小写字母分别代表着26种商品类别；\n\n\t     →该商品需要进货的库存量：count<50；\n");  
    PR("   ---$-----$--------$----------$-----------$---------$-------$------$-----$---");  
    PR(" \nplease press any key to continue");  
    getch();  system("cls"); /*清屏*/  
    lp: for(i=0;i<1;i++) 
     PR("\n\n——★—☆——★—☆——☆—★——☆—★——☆—☆——★—\n");    
     PR("\n\t\t\t    商品信息管理系统\t\n\n");     
     PR("\t  1 →输入商品信息\n\n");     
     PR("\t  2 →排序商品信息\n\n");     
     PR("\t  3 →输入进货信息\t\t6 →修改商品信息\n\n");     
     PR("\t  4 →输入销售信息\t\t7 →查询商品信息\n\n");     
     PR("\t  5 →增加/删除商品\t\t8 →浏览商品信息\n\n");     
     PR("\t\t\t\t\t9 →保存商品信息\n\n");     
    PR(" \t\t  ——☆—★——☆—★——☆—☆——★—☆——★—☆——★—");/*菜单选择界面*/ 
     PR("\n\n");     PR("\t请选择您所要的操作(或选择(0)退出):");     
     SC("%d",&k);     
     system("cls");     
     switch(k)  /*用switch语句实现功能选择*/   {   
      case 1: input();break;       
      case 2: sequence();break;       
      case 3: purchase();break;       
      case 4: sell();break;       
      case 5: edit();break;       
      case 6: correct();break;      
      case 7: search();break;       
      case 8: scan();break;       
      case 9: reserve();break;          
      case 0: PR("\n\n\t        / / / / /  ^_^  \\ \\ \\ \\ \\ \n\n\t…………谢谢使用，欢迎再来，再见O(∩_∩)O…………");
      exit(0);  /*退出系统*/
      default: puts("输入错误,请按任意健返回主菜单：\n"); break;     
        }    
       system("cls");   /*清屏*/    
       goto lp;  /*返回主界面*/ 
    } 
    void input()  /*功能1：输入商品信息*/   {    
    PR("\n     请输入需要建立新库存的商品种类数量:");    
    SC("%d",&n);    system("cls");      
    PR("\n …………………………………………………………………………………………………\n");   
    for(i=0;i<n;i++)   /*用循环实现输入n个商品*/    {     
    PR("\n\t*请输入商品的编号:");     
    SC("%ld",&goods[i].num);     
    PR("\n\t 请输入商品的名称:");    
    SC("%s",goods[i].name);     
    PR("\n\t 请输入商品的种类:");    
    SC("%s",goods[i].sort);    
    PR("\n\t 请输入商品的数量:");    
    SC("%d",&goods[i].count);    
    PR("\n\t 请输入商品的单价:");    
    SC("%d",&goods[i].price);    
    PR("\n …………………………………………………………………………………………………\n");    
 }    
    PR("\tPlease press any key to continue:");    
    getch();   
    return;   /*返回主界面*/    
}
void sequence()   /*功能2：排序商品信息*/  {     
long temp;   
 char p1[30],p2[30];    
 for(k=0;k<n-1;k++)   /*(1): 按编号排序*/   
 for(i=0;i<n-k-1;i++)  /*用起泡法排序*/   
 if(goods[i].num>goods[i+1].num)  /*按编号由小到大排序*/    {    
 temp=goods[i].num;     
 goods[i].num=goods[i+1].num;     
 goods[i+1].num=temp;     
 strcpy(p1,goods[i].name);    
 strcpy(goods[i].name,goods[i+1].name);     
 strcpy(goods[i+1].name,p1); 
 strcpy(p2,goods[i].sort);     
 strcpy(goods[i].sort,goods[i+1].sort);     
 strcpy(goods[i+1].sort,p2);     
}     
  PR("--------------------------------------------------------------------------------");    
  PR("\n\t\t按商品编号排序后的商品信息\n\n");     
  PR("\t商品编号     商品名称     商品类别      商品数量      商品单价\n");   /*输出排序后商品信息*/     for(i=0;i<n;i++)     {       PR("\t %5ld       %5s       %5s        %5ld        %5ld\n",goods[i].num,goods[i].name,goods[i].sort,goods[i].count,goods[i].price);      }          for(k=0;k<n-1;k++)   /*(2): 按商品名称排序*/    for(i=0;i<n-k-1;i++)    
  if(strcmp(goods[i].name,goods[i+1].name)>0)
    {    
         strcpy(p1,goods[i].name);     
    strcpy(goods[i].name,goods[i+1].name);     
    strcpy(goods[i+1].name,p1);     
    temp=goods[i].num;     
    goods[i].num=goods[i+1].num;     
    goods[i+1].num=temp;     
    strcpy(p2,goods[i].sort);     
    strcpy(goods[i].sort,goods[i+1].sort);    
     strcpy(goods[i+1].sort,p2);    
}    
    PR("--------------------------------------------------------------------------------");     
    PR("\n\t\t按商品名称排序后的商品信息\n");     
    PR("\n\t商品名称     商品编号     商品类别      商品数量      商品单价\n");    /*输出排序后商品信息*/     
    for(i=0;i<n;i++)   
    { 
        PR("\t %5s       %5ld       %5s        %5ld        %5ld\n",
        goods[i].name,goods[i].num,goods[i].sort,goods[i].count,goods[i].price);      
    }        
        for(k=0;k<n-1;k++)    /*(3): 按商品类别排序*/    for(i=0;i<n-k-1;i++)   /*用起泡法排序*/    
        if(strcmp(goods[i].sort,goods[i+1].sort)>0) {
            strcpy(p2,goods[i].sort);    
             strcpy(goods[i].sort,goods[i+1].sort);     
            strcpy(goods[i+1].sort,p2);     
            temp=goods[i].num;     
            goods[i].num=goods[i+1].num;     
            goods[i+1].num=temp;     
            strcpy(p1,goods[i].name);     
            strcpy(goods[i].name,goods[i+1].name);    
             strcpy(goods[i+1].name,p1);     
            }     
            PR("--------------------------------------------------------------------------------");    
             PR("\n\t\t按商品类别排序后的商品信息\n\n");     
            PR("\t商品类别     商品编号     商品名称      商品数量      商品单价\n");    /*输出排序后商品信息*/     
            for(i=0;i<n;i++)      
            {     PR("\t %5s       %5ld       %5s        %5ld        %5ld\n",
            goods[i].sort,goods[i].num,goods[i].name,goods[i].count,goods[i].price);     
            }     
            PR("--------------------------------------------------------------------------------");    
             PR("please press any key to continue:");     
            getch();    
             return;   /*返回主界面*/  
            }     
             void purchase()  /*功能3：进货商品信息*/                                  
             {    
             long temp;    /*定义临时变量表示刚进货的商品编号*/     
            int j;     
            PR("\n\t\5请输入刚进货的商品编号:");     
            SC("%ld",&temp);     
            PR("\n\t\5请输入刚进货的商品数量:");     
            SC("%d",&j);     
            PR("\n\n\n\tpress any key to contiue:");     
            getch();     
            system("cls");    
             PR("\n\t输出进货后的商品信息：");   
              for(i=0;i<n;i++)    /*循环，寻找与进货相同的商品信息*/       
             if(temp==goods[i].num)           
             goods[i].count=goods[i].count+j;  /*自动更改商品数量*/     
            PR("\n\t商品编号    商品名    商品类别    商品数量    商品价格");    
             for(i=0;i<n;i++)     /*循环，输出进货后的商品信息*/     
            {
                PR("\n\t  %4ld      %4s       %4s        %ld       %4ld",
                goods[i].num,goods[i].name,goods[i].sort,goods[i].count,goods[i].price);      
            }     
                 PR("\n\n\t\tPress any key to enter menu:");      
                 getch();  /*返回功能选择界面*/     return; }     
                 void sell()  /*功能4：销售商品信息*/  
                {    long temp;    /*定义临时变量temp表示刚销售的商品编号*/    
                  int j;    
                  PR("\n\t\5请输入刚销售的商品编号:");    
                  SC("%ld",&temp);    
                  PR("\n\t\5请输入刚销售的商品数量:");   
                  SC("%d",&j);
                }       
                for(i=0;i<n;i++)  /*循环，找到刚销售的商品信息*/      
                {         if(temp==goods[i].num)        
                 {          for(;j>goods[i].count;)   /*如果销售额大于库存量，则出现错误提示*/         
                  {           
                    PR("\n\t售出数量大于商品原有数量，出现错误，请重新输入:");           
                    SC("%d",&j);           
                  }           
                goods[i].count=goods[i].count-j;   /*完成自动更改商品数量的功能*/         
                 }        
                }   
                  PR("\n\tpress any key to contiue:");   
                  getch();    
                  system("cls");   /*清屏*/   
                  PR("\n\n     *销售后商品信息：");    
                  PR("\n\t商品类别     商品编号     商品名称      商品数量      商品单价\n");    
                  for(i=0;i<n;i++)      /*循环，输出销售后商品信息*/    
                {      PR("\t %4s       %4ld        %4s          %4ld          %4ld\n",
                    goods[i].sort,goods[i].num,goods[i].name,goods[i].count,goods[i].price);      
                }   
             PR("\n\tPress any key to enter menu:");      
             getch();    
                return;    /*返回功能选择界面*/
        }
        

