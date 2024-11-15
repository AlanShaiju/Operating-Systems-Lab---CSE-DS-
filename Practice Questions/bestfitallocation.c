#include<stdio.h>
#include<stdlib.h>
int main()
{
    int b,p,i,j;
    int process[10],blocks[10],allocated[10];
    printf("Enter no of processes:");
    scanf("%d",&p);
    printf("Enter no of blocks:");
    scanf("%d",&b);
    printf("Enter process sizes\n");
    for(i=0;i<p;i++)
        scanf("%d",&process[i]);
    printf("Enter block sizes\n");
    for(i=0;i<b;i++)
        scanf("%d",&blocks[i]);
    for(i=0;i<p;i++)
    {
        allocated[i]=-1;
        int bestindex=-1;
        for(j=0;j<b;j++)
        {
            if(process[i]<=blocks[j])
            {
                if(bestindex==-1)
                    bestindex=j;
                    else
                    {
                        if(blocks[bestindex]>blocks[j])
                        {
                            bestindex=j;
                        }
                    }

            }
        }
        if(bestindex!=-1)
        {
            allocated[i]=bestindex+1;
            blocks[bestindex]=blocks[bestindex]-process[i];
        }
    }
    for(i=0;i<p;i++)
    {
        if(allocated[i]!=-1)
        {
            printf("Process Id:%d , Allocated to:%d\n",i+1,allocated[i]);
        }
        else
            printf("Process Id:%d , Not Allocated\n");
    }
    printf("Free Space Available\n");
    for(i=0;i<b;i++)
    {
        printf("Block No:%d , Available Space:%d\n",i+1,blocks[i]);
    }  
}