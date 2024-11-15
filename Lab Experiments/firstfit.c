#include<stdio.h>
#include<stdlib.h>
int main()
{
    int np,nr;
    int processsize[10],blocksize[10];
    int allocated[10];
    printf("Entyer no of processes\n");
    scanf("%d",&np);
    printf("enter no of block");
    scanf("%d",&nr);
    printf("enter process sizes\n");
    for(int i=0;i<np;i++)
    {
        printf("process %d:",i);
        scanf("%d",&processsize[i]);
    }
    printf("enter block sizes\n");
    for(int i=0;i<nr;i++)
    {
        printf("process %d:",i);
        scanf("%d",&blocksize[i]);
    }
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nr;j++)
        {
            if(processsize[i]<blocksize[j])
            {
                allocated[i]=j+1;
                blocksize[j]=blocksize[j]-processsize[i];
                break;
            }
        }
    }
    printf("Process Id \t Process Size\t Allocated\n");
    for(int i=0;i<np;i++)
    {
        printf("%d\t%d\t",i+1,processsize[i]);
        if(allocated[i]>0)
        printf("%d\n",allocated[i]);
        else
        printf("not allocated\n");
    }
}