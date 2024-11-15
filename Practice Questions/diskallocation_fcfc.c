#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,currentrequest,totalseektime=0,seektime,head;
    int requests[15];
    printf("Enter no of requests:");
    scanf("%d",&n);
    printf("Enter the requests string:");
    for(i=0;i<n;i++)
    scanf("%d",&requests[i]);
    printf("Enter position of head:");
    scanf("%d",&head);
    for(i=0;i<n;i++)
    {
        currentrequest=requests[i];
        seektime=abs(currentrequest-head);
        printf("Head movement:%d ---> %d |Seektime:%d\n",head,currentrequest,seektime);
        totalseektime=totalseektime+seektime;
        head=currentrequest;
    }
    printf("Total Head Movement:%d\n",totalseektime);
}