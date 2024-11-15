#include<stdio.h>
#include<stdlib.h>
int n, i, j, op, check, front=-1, rear=-1, queue[100];
struct process{
int AT,WT,TAT,BT;
}a[10];
void swap(int *b,int *c)
{
    int temp=*c;
    *c=*b;
    *b=temp;
}
void sjf_non_pre()
{
    int check=0, CT=0, min;
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time & Burst time of \n");
    for(i=0;i<n;i++)
    {
        printf("process %d: ", i+1);
        scanf("%d %d", &a[i].AT, &a[i].BT);
        if(i==0)
        check=a[i].AT;
        if(check!=a[i].AT )
        check=1;
    }
    if(check!=0)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j].AT>a[j+1].AT)
                {
                    swap(&a[j].AT, &a[j+1].AT);
                    swap(&a[j].BT, &a[j+1].BT);
                }
            }
        }
        a[0].WT=a[0].AT;
        a[0].TAT=a[0].BT-a[0].AT;
        CT=a[0].TAT;
        total_WT+=a[0].WT;
        total_TAT+=a[0].TAT;
        for(i=1;i<n;i++)
        {
            min=a[i].BT;
            for(j=i+1;j<n;j++)
            {
                if(min>a[j].BT && a[j].AT<=CT)
                {
                    min=a[j].BT;
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                }
            }
            a[i].WT=CT-a[i].AT;
            total_WT+=a[i].WT;
            CT+=a[i].BT;
            a[i].TAT=CT-a[i].AT;
            total_TAT+=a[i].TAT;
        }
    }
    else
    {
        for( i=0;i<n;i++)
        {
            min=a[i].BT;
            for(j=i+1;j<n;j++)
            {
                if(min>a[j].BT && a[j].AT<=CT)
                {
                    min=a[j].BT;
                    swap(&a[i].AT, &a[j].AT);
                    swap(&a[i].BT, &a[j].BT);
                }
            }
            a[i].WT=CT-a[i].AT;
            CT+=a[i].BT;
            a[i].TAT=CT-a[i].AT;
            total_WT+=a[i].WT;
            total_TAT+=a[i].TAT;
        }
    }
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i].AT,a[i].BT,a[i].WT,a[i].TAT);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
struct prio
{
    int WT,AT,BT,TAT,PR;
}b[10];
void Prio_nonpre()
{
    int check=0, CT=0, min;
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time, Burst time & Priority of \n");
    for(i=0;i<n;i++)
    {
        printf("process %d: ", i+1);
        scanf("%d %d %d", &b[i].AT, &b[i].BT, &b[i].PR);
        if(i==0)
        check=b[i].AT;
        if(check!=b[i].AT )
        check=1;
    }
    if(check!=0)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(b[j].AT>b[j+1].AT)
                {
                    swap(&b[j].AT, &b[j+1].AT);
                    swap(&b[j].BT, &b[j+1].BT);
                    swap(&b[j].PR, &b[j+1].PR);
                }
            }
        }
        b[0].WT=b[0].AT;
        b[0].TAT=b[0].BT-b[0].AT;
        CT=b[0].TAT;
        total_WT+=b[0].WT;
        total_TAT+=b[0].TAT;
        for(i=1;i<n;i++)
        {
            min=b[i].PR;
            for(j=i+1;j<n;j++)
            {
            if(min>b[j].PR && b[j].AT<=CT)
                {
                    min=b[j].PR;
                    swap(&b[i].AT, &b[j].AT);
                    swap(&b[i].BT, &b[j].BT);
                    swap(&b[j].PR, &b[j+1].PR);
                }   
            }
            b[i].WT=CT-b[i].AT;
            total_WT+=b[i].WT;
            CT+=b[i].BT;
            b[i].TAT=CT-b[i].AT;
            total_TAT+=b[i].TAT;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            min=b[i].PR;
            for(j=i+1;j<n;j++)
            {
                if(min>b[j].PR && b[j].AT<=CT)
                {
                    min=b[j].PR;
                    swap(&b[i].AT, &b[j].AT);
                    swap(&b[i].BT, &b[j].BT);
                    swap(&b[j].PR, &b[j+1].PR);
                }
            }
            b[i].WT=CT-b[i].AT;
            CT+=b[i].BT;
            b[i].TAT=CT-b[i].AT;
            total_WT+=b[i].WT;
            total_TAT+=b[i].TAT;
        }
    }
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i].AT,a[i].BT,a[i].WT,a[i].TAT);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
int main()
{
    int i=1;
    while(i!=0)
    {
        int cho;
        printf("3.SJF\n4.Non Preemptive Priority Scheduling\n7.Exit\nEnter your choice:\n");
        scanf("%d",&cho);
        switch(cho)
        {
            case 3:
                sjf_non_pre();
                break;
            case 5:  
                Prio_nonpre();
                break;
            case 7:
                printf("Exiting...");
                i=0;
                exit(0);
                break;
        }
    }
}