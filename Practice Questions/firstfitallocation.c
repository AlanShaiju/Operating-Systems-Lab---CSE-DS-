#include<stdio.h>
#include<stdlib.h>
int memoryblocks[5];
int main()
{
    int i,j,n;
    int process[4][10];
    printf("Enter sizes of memory blocks\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&memoryblocks[i]);
    }
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the process sizes\n");
    for(int i=0;i<n;i++)
    {
        process[0][i]=i;
        scanf("%d",&process[1][i]);
        process[2][i]=0;
        process[3][i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            if(process[2][i]==0)
            {
                if(process[1][i]<=memoryblocks[j])
                {
                    memoryblocks[j]=memoryblocks[j]-process[1][i];
                    process[2][i]=1;
                    process[3][i]=j+1;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Process ID:%d\n",i+1);
        printf("Process Size:%d",process[1][i]);
        if(process[2][i]=1)
        printf("Status:Allocated to memory Block %d\n",process[3][i]);
        else
        printf("Status: Not Allocated\n");
    }
    printf("Available Spaces\n");
    for(i=0;i<5;i++)
    printf("Memory Block %d : %d",i+1,memoryblocks[i]);
}