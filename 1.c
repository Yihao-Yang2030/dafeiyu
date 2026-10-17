#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data 
{
    char name[20];
    int age;
    char sex[20];
    long long phone;
    char address[20];
    struct data *next;
};
struct data *head=NULL;
struct data *tail=NULL;
struct data *p;
/* 释放整条链表并把 head/tail 复位，
   这样 duqu() 才能被重复调用而不重复追加已经读过的记录 */
void qingkong()
{
    struct data *q=head;
    struct data *temp;
    while(q!=NULL)
    {
        temp=q;
        q=q->next;
        free(temp);
    }
    head=NULL;
    tail=NULL;
}
int main()
{
    void duqu();
    system("chcp 65001");
    printf("欢迎使用通讯录管理系统！\n");
    printf("=================== 通讯录管理系统 ===================\n");
    printf("  1.存储联系人");
    printf("                     2.查找联系人\n");
    printf("  3.显示所有联系人");
    printf("                 4.修改联系人\n");
    printf("  5.删除联系人");
    printf("                     6.保存并退出\n");
    printf("               使用完后请务必选择6保存并退出,否则文件会被清空\n");
    printf("请输入1-9的数字\n");
    while(1)
    {
        int number;
        if(scanf("%d",&number)!=1)
        {
            if(feof(stdin))
            {
                break;              /* 输入结束了，别死循环 */
            }
            scanf("%*[^\n]");       /* 把这一行剩下的杂字符丢掉 */
            scanf("%*c");
            printf("输入有误,请输入1-9的数字\n");
            continue;
        }
        switch(number){
        case 1:
        {
    struct data *before=tail;
    while(1)
    {
    char a[20];
    int b;
    char c[20];
    long long d;
    char e[20];
        printf("请输入名字，年龄，性别，电话号码，地址\n");
        scanf("%s%d%s%lld%s",a,&b,c,&d,e);
        if(b==0)
        break;          
        struct data *new=(struct data*)malloc(sizeof(struct data));
        if(new==NULL)
        {
            printf("创建节点失败");
            goto out;
        }
        strcpy(new->name,a);
        new->age=b;
        strcpy(new->sex,c);
        new->phone=d;
        strcpy(new->address,e);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }}
        p=(before==NULL)?head:before->next;
        FILE *fp;
        char num[200];
        printf("请输入想要存入的文件名\n");
        scanf("%s",num);
        if((fp=fopen(num,"a+"))==NULL)
        {
            printf("can't open file\n");
            exit(0);
        }
        while(p!=NULL)
        {
            printf("%s %d %s %lld %s\n",p->name,p->age,p->sex,p->phone,p->address);
            fprintf(fp, "%s %d %s %lld %s\n", p->name, p->age, p->sex, p->phone, p->address);
            p=p->next;
        }
        fclose(fp);
        }
        out:
        printf("存储结束\n");
        printf("请输入1-9的数字\n");
        break;
        case 2:
        duqu();
        char str[20];
        int found=0;
        printf("请输入想要查找的联系人\n");
        scanf("%s",str);
        p=head;
        while(p!=NULL)
        {
            if(strcmp(str,p->name)==0)
            {
                printf("%s %d %s %lld %s\n",p->name,p->age,p->sex,p->phone,p->address);
                found=1;
                break;
            }
            p=p->next;
        }
        if(found==0)
        {
            printf("查无此人\n");
        }
        printf("查找结束\n");
        printf("请输入1-9的数字\n");
        break;
        case 3:
        duqu();
        p=head;
        while(p!=NULL)
        {
            printf("%s %d %s %lld %s\n",p->name,p->age,p->sex,p->phone,p->address);
            p=p->next;
        }
        printf("显示完毕\n");
        printf("请输入1-9的数字\n");
        break;
        case 4:
        duqu();
        p=head;
        char str1[20];
        char a[20];
        int b;
        char c[20];
        long long d;
        char e[20];
        char filename[20];
        FILE *fp1;
        int found1=0;
        printf("请输入想要修改的文件夹\n");
        scanf("%s",filename);
            if((fp1=fopen(filename,"w"))==NULL)
            {
                printf("cen't open file\n");
                exit(0);
            }
            printf("请输入想要修改的联系人\n");
            scanf("%s",str1);
        while(p!=NULL)
        {
            if(strcmp(str1,p->name)==0)
            {
                printf("%s %d %s %lld %s\n",p->name,p->age,p->sex,p->phone,p->address);
                printf("请输入想要修改的名字\n");
                scanf("%s",a);
                strcpy(p->name,a);
                printf("请输入想要修改的年龄\n");
                scanf("%d",&b);
                p->age=b;
                printf("请输入想要修改的性别\n");
                scanf("%s",c);
                strcpy(p->sex,c);
                printf("请输入想要修改的电话号码\n");
                scanf("%lld",&d);
                p->phone=d;
                printf("请输入想要修改的地址\n");
                scanf("%s",e);
                strcpy(p->address,e);
                printf("修改完毕\n");
                found1=1;
                break;
            }
            p=p->next;
        }
        if(found1==0)
        {
            printf("查无此人，没有修改任何联系人\n");
        }
        p=head;
        while(p!=NULL)
        {
            fprintf(fp1, "%s %d %s %lld %s\n", p->name, p->age, p->sex, p->phone, p->address);
            p=p->next;
        }
        fclose(fp1);
        printf("请输入1-9的数字\n");
        break;
        case 6:
        qingkong();
        printf("系统退出，内存以释放\n");
        exit(0);
        }}}
        void duqu()
{
    /* 注意：这里千万不要再写 struct data *head=NULL; head/tail 必须用第13、14行的全局变量，
       否则会遮蔽(同名局部变量)全局 head/tail，duqu() 读进来的链表只在函数内部有效，
       返回后全局 head 还是 NULL，case 2/3/4 就一个联系人也看不到。 */
    char a[20];
    int b;
    char c[20];
    long long d;
    char e[20];
    char filename[20];
    FILE *fp;
    printf("请输入想要查找的文件夹\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("can't open file，本次没有加载任何记录\n");
        return;         /* 文件名打错就返回，不要 exit 把整个程序结束掉 */
    }
    qingkong();         /* 关键：读之前先清空旧链表，否则会重复读入 */
    while(fscanf(fp,"%s%d%s%lld%s",a,&b,c,&d,e)==5)
    {
        struct data *new=(struct data*)malloc(sizeof(struct data));
        strcpy(new->name,a);
        new->age=b;
        strcpy(new->sex,c);
        new->phone=d;
        strcpy(new->address,e);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }}
    }