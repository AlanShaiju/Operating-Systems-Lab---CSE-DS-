#include<stdio.h>
#include<stdlib.h>
struct process
{
    int at,bt,wt,tat;
}a[10],temp;
int main()
{
    int n,i,ct=0;
    float tat=0.00,wt=0.00;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter the arival and burst times of the processes:\n");
    for(i=0;i<n;i++)
    {
        printf("Process %d:",i+1);
        scanf("%d %d",&a[i].at,&a[i].bt);
    }
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].at>a[j+1].at)
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Pid\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        if(i==0)
        a[i].wt=0;
        else
        a[i].wt=ct-a[i].at;
        ct=ct+a[i].bt;
        a[i].tat=ct-a[i].at;
        wt+=a[i].wt;
        tat+=a[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,a[i].at,a[i].bt,ct,a[i].tat,a[i].wt);
    }
    wt=wt/n;
    tat=tat/n;
    printf("avg tat:%f\n",tat);
    printf("avg wt:%f\n",wt);
}