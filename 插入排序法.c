#include<stdio.h>
int main()
{
    int a[5],i,j,temp;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<5;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
            else 
            {
                break;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}