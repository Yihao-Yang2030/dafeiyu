#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("chcp 65001");
    struct student
    {
        int num;
        char name[20];
        float score;
    } student1,student2;
    scanf("%d%s%f",&student1.num,student1.name,&student1.score);
    scanf("%d%s%f",&student2.num,student2.name,&student2.score);
    if(student1.score>student2.score)
    {
        printf("%s",student1.name);
    }else if(student1.score<student2.score)
    {
        printf("%s",student2.name);
    }else {
        printf("分数相同");
    }
    return 0;
}