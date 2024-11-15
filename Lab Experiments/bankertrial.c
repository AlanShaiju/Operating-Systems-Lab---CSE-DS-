 #include<stdio.h>
 #include<stdlib.h>
 int available[10],max[10][10],allocated[10][10],need[10][10],work[10],finish[10],safesequence[10];
 int p,r;
 int input()
{
    int i,j;
    printf("Entrer no of processes:");
    scanf("%d",&p);
    printf("Enter no of resources:");
    scanf("%d",&r);
    printf("Enter Available resources:");
    for(i=0;i<r;i++)
        scanf("%d",&available[i]);
    printf("Enter allocated resource for each process:\n");
    for(i=0;i<p;i++)
    {
        printf("Process %d: ",i);
        for(j=0;j<r;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
        printf("\n");
    }
    printf("Enter max resource for each process:\n");
     for(i=0;i<p;i++)
    {
        printf("Process %d: ",i);
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
}
int safetycheck()
{
    int i,j,count=0;
    for(j=0;j<r;j++)
        work[j]=available[j];
    for(i=0;i<p;i++)
        finish[i]=0;
    while(count<p)
    {
        int found=0;
        for(i=0;i<p;i++)
        {
            if(finish[i]==0)
            {
                int safe=1;
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        safe=0;
                        break;
                    }
                }
                if(safe==1)
                {
                    found=1;
                    finish[i]=1;
                    for(j=0;j<r;j++)
                    work[j]=work[j]+allocated[i][j];
                    safesequence[count++]=i;
                }
            }
        }
        if(found==0)
        {
            printf("System in unsafe state\n");
            return 0;
        }
    }
    printf("SafeSequence:");
    for(i=0;i<p;i++)
    {
        printf("%d ",safesequence[i]);
    }
    printf("\n");
    return 1;
}
int request(int id)
{
    int pid=id;
    int i,j;
    printf("Enter resources requested by process %d:",pid);
    for(i=0;i<r;i++)
    {
        scanf("%d",&allocated[pid][i]);
        need[pid][j]=max[pid][j]-allocated[pid][j];
    }
    for(i=0;i<r;i++)
    {
        if(allocated[pid][i]>available[i])
        {
            printf("Process must wait\n");
            return 0;
        }
    }
    for(i=0;i<r;i++)
    {
        available[i]=available[i]-allocated[pid][i];
        need[pid][i]=need[pid][i]-allocated[pid][i];
    }
    if(safetycheck())
    {
        printf("System in safestate\n");
        printf("recources allocated to process %d",pid);
        return 1;
    }
    else
    {
        for(i=0;i<r;i++)
        {
            available[i]=available[i]+allocated[pid][i];
            need[pid][i]=need[pid][i]+allocated[pid][i];
        }
        return 0;
    }
}
int main()
{
    input();
    safetycheck();
    int pid;
    printf("To request for resources enter process id/To exit press -1:");
    scanf("%d",&pid);
    while(pid!=-1)
    {
        request(pid);
        printf("To request for resources enter process id/To exit press -1:");
        scanf("%d",&pid);
    }
    return 0;
}