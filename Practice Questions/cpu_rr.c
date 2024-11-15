#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,queue[100];
struct process
{
    int at,bt,wt,tat;
}a[10];
int insert(int x)
{
    if(front==-1)
    front++;
    rear++;
    queue[rear]=x;
}
int delete()
{
    int x=queue[front];
    front++;
    return x;
}
int main()
{
    int exists[10]={0},tq=0,time=0,p,n,temp[10];
    float wt=0.00,tat=0.00;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter details of process(at,bt):\n");
    for(int i=0;i<n;i++)
    {
        printf("process%d:",i+1);
        scanf("%d %d",&a[i].at,&a[i].bt);
        temp[i]=a[i].bt;
    }
    printf("Enter timequantum:");
    scanf("%d",&tq);
    insert(0);
    exists[0]=1;
    while(front<=rear)
    {
        p=delete();
        if(a[p].bt>tq)
        {
            a[p].bt-=tq;
            time+=tq;
        }
        else
        {
            time+=a[p].bt;
            a[p].bt=0;
        }
        for(int i=0;i<n;i++)
        {
            if(exists[i]==0&&a[i].at<=time)
            {
                insert(i);
                exists[i]=1;
            }
        }
        if(a[p].bt==0)
        {
            a[p].tat=time-a[p].at;
            a[p].wt=a[p].tat-temp[p];
            tat+=a[p].tat;
            wt+=a[p].wt;
        }
        else
            insert(p);
    }
    printf("Pid\tAT\tBT\tTAT\tWt\n");
    for(int i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\t%d\n",i+1,a[i].at,temp[i],a[i].tat,a[i].wt);
    wt=wt/n;
    tat=tat/n;
    printf("Waiting time:%f\n",wt);
    printf("Turn around time:%f\n",tat);
}