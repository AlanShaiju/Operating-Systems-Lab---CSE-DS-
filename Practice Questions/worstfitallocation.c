#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,b,bestindex=-1,i,j,process[10],blocks[10],allocated[10];
    printf("Enter no of processes:");
    scanf("%d",&p);
    printf("Enter the process sizes:\n");
    for(i=0;i<p;i++)
        scanf("%d",&process[i]);
    printf("Enter the no of blocks:");
    scanf("%d",&b);
    for(i=0;i<b;i++)
        scanf("%d",&blocks[i]);
    for(i=0;i<p;i++)
    {
        allocated[i]=-1;
        bestindex=-1;
        for(j=0;j<b;j++)
        {
            if(blocks[j]>=process[i])
            {
                if(bestindex==-1)
                    bestindex=j;
                else
                {
                    if(blocks[bestindex]<blocks[j])
                        bestindex=j;
                }
            }
        }
        if(bestindex!=-1)
        {
            allocated[i]=bestindex+1;
            blocks[bestindex]=blocks[bestindex]-process[i];
        }
    }
    printf("Process Allocation:\n");
    for(i=0;i<p;i++)
    {
        if(allocated[i]!=-1)
        {
            printf("Process Id: %d | Allocated Block: %d\n",i+1,allocated[i]);
        }
        else
            printf("Process Id: %d Not Allocated\n",i+1);
    }
    printf("Available Space:\n");
    for(j=0;j<b;j++)
    {
        printf("Block Id: %d | Available Space: %d\n",j+1,blocks[j]);
    }

}