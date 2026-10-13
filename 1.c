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
int main()
{
    system("chcp 65001");
    char a[20];
    int b;
    char c[20];
    long long d;
    char e[20];
    while(1)
    {
        printf("请输入名字，年龄，性别，电话号码，地址\n");
        scanf("%s%d%s%lld%s",a,&b,c,&d,e);
        if(b==0)
        break;
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
        p=head;
        FILE *fp;
        char num[200];
        printf("请输入想要存入的文件名");
        scanf("%s",num);
        if((fp=fopen(num,"w"))==NULL)
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
        p=head;
        struct data *temp;
        while(p!=NULL)
        {
            temp=p;
            free(temp);
            p=p->next;
        }
        head=NULL;
        tail=NULL;
    return 0;
}