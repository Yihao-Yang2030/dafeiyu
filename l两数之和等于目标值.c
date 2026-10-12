#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *nums;
    int target,coint=0,i=0,u=0;
    scanf("%d",&target);
    nums=(int*)malloc(1000*sizeof(int));
    while(1)
    {
        scanf("%d",&nums[i]);
        if(nums[i]!=-1)
        {
        i++;
        coint++;
        }else {
            break;
        }
    }
    for(i=0;i<coint;i++)
    {
        for(u=0;u<coint;u++)
        {
            if(i!=u&&nums[i]+nums[u]==target)
            {
                printf("[%d,%d]",i,u);
                goto out;
            }
        }
    }
    out:
    return 0;
}