#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date
{
    char name[20];
    float day;
    struct date *next;
};
struct date *head=NULL;
struct date *tail=NULL;
struct date *p;
int main()
{
    system("chcp 65001");
    char a[20];
    struct date *team;
    float b;
    while(1)
    {
    scanf("%s %f",a,&b);
    if(b==0)
    {
        break;
    }
    struct date *newnode=(struct date *)malloc(sizeof(struct date));
    strcpy(newnode->name,a);
    newnode->day=b;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    } else {
        tail->next=newnode;
        tail=newnode;
    }
    }
    p=head;
    while(p!=NULL)
    {
    printf("%s %.2f\n",p->name,p->day);
    p=p->next;
    }
    p=head;
    while(p!=NULL)
    {
    team=p;
    p=p->next;
    free(team);
    }
    head=NULL;
    return 0;
}
