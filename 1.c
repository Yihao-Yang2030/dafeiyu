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
void qingchuhuancun();
void duqu();
char * duqu1();
struct data *head=NULL;
struct data *tail=NULL;
struct data *p;
int main()
{
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
    printf("请输入1-6的数字\n");
    while(1)
    {
        int number;
        if(scanf("%d",&number)!=1)
        {
            if(feof(stdin))
            {
                break;
            }
            scanf("%d",&number);
            printf("输入有误,请输入1-6的数字\n");
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
        out:
        printf("存储结束\n");
        printf("请输入1-6的数字\n");
        qingchuhuancun();
        break;}
        case 2:
        {duqu();
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
        qingchuhuancun();
        printf("查找结束\n");
        printf("请输入1-6的数字\n");
        break;
    }
        case 3:
        {
            duqu();
        p=head;
        while(p!=NULL)
        {
            printf("%s %d %s %lld %s\n",p->name,p->age,p->sex,p->phone,p->address);
            p=p->next;
        }
        qingchuhuancun();
        printf("显示完毕\n");
        printf("请输入1-6的数字\n");
        break;
    }
        case 4:
        {
        char * filename=duqu1();
        p=head;
        char str1[20];
        char a[20];
        int b;
        char c[20];
        long long d;
        char e[20];
        FILE *fp1;
        int found1=0;
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
        if((fp1=fopen(filename,"w"))==NULL)
            {
                printf("cen't open file\n");
                exit(0);
            }
        p=head;
        while(p!=NULL)
        {
            fprintf(fp1, "%s %d %s %lld %s\n", p->name, p->age, p->sex, p->phone, p->address);
            p=p->next;
        }
        fclose(fp1);
        qingchuhuancun();
        printf("请输入1-6的数字\n");
        break;
    }
        case 5:
        {
        char * filename1=duqu1();
        struct data *q=NULL;
        int found2=0;
        p=head;
        char str2[20];
        FILE *fp2;
        printf("请输入想要删除的联系人\n");
        scanf("%s",str2);
        while(p!=NULL)
        {
        if(strcmp(str2,p->name)==0)
        {
            found2=1;
            if(p==head)
            {
                head=p->next;
                p->next=NULL;
            }
            else if(p!=head&&p!=tail)
            {
                q->next=p->next;
                p->next=NULL;
            }
            else if(p==tail)
            {
                q->next=NULL;
                tail=q;
            }
            free(p);
            break;
        }
        q=p;
        p=p->next;
    }
    if(found2==0)
    {
        printf("查无此人,没有删除任何联系人\n");
        exit(0);
    }
    if((fp2=fopen(filename1,"w"))==NULL)
        {
            printf("can't open file\n");
            exit(0);
        }
    p=head;
    while(p!=NULL)
        {
            fprintf(fp2, "%s %d %s %lld %s\n", p->name, p->age, p->sex, p->phone, p->address);
            p=p->next;}
            fclose(fp2);
            qingchuhuancun();
            printf("该联系人已删除\n");
            printf("请输入1-6的数字\n");
            break;
        }
        case 6:
        {p=head;
        struct data *temp;
        while(p!=NULL)
        {   
            temp=p;
            p=p->next;
            free(temp);
        }
        head=NULL;
        tail=NULL;
        printf("系统退出，内存以释放\n");
        exit(0);
        }}}}
        void duqu()
{
    char a[20];
    int b;
    char c[20];
    long long d;
    char e[20];
    char filename[200];
    FILE *fp;
    printf("请输入想要查找的文件夹\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("can't open file");
        exit(0);
    }
    while(fscanf(fp,"%s%d%s%lld%s",a,&b,c,&d,e)!=EOF)
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
    char * duqu1()
{
    char a[20];
    int b;
    char c[20];
    long long d;
    char e[20];
    static char filename[200];
    FILE *fp;
    printf("请输入想要查找的文件夹\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("can't open file");
        exit(0);
    }
    while(fscanf(fp,"%s%d%s%lld%s",a,&b,c,&d,e)!=EOF)
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
        return filename;
    }
    void qingchuhuancun()
    {
        p=head;
        struct data *temp;
        while(p!=NULL)
        {   
            temp=p;
            p=p->next;
            free(temp);
        }
        head=NULL;
        tail=NULL;
    }