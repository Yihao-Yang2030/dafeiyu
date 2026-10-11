#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    system("chcp 65001");
    struct student{
        char name[20];
        int score;
        struct student *next;
    } a,b,c;
    struct student *p;
    strcpy(a.name,"杨");
    a.score=100;
    strcpy(b.name,"李");
    b.score=99;
    strcpy(c.name,"曹");
    c.score=98;
    p=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    while(p!=NULL)
    {
        printf("%s %d\n",p->name,p->score);
        p=p->next;
    }
    return 0;
}