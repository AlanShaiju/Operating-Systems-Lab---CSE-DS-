#include<stdio.h>
#include<stdlib.h>
int main()
{
    int head,max,min=0,j,i,n,val,currentindex;
    printf("Enter max sizeof disk:");
    scanf("%d",&max);
    printf("enter head position:");
    scanf("%d",&head);
    int left[10],right[10],temp1=0,temp2=0;
    printf("Enter no.of disk requests:");
    scanf("%d",&n);
    printf("enter the disk requests:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        if(val<head)
        {
            left[temp1]=val;
            temp1++;
        }
        else
        {
            right[temp2]=val;
            temp2++;
        }
    }
    //sort right in ascending order
    for(i=0;i<temp2-1;i++)
    {
        for(j=0;j<temp2-i-1;j++)
        {
            if(right[j]>right[j+1])
            {
                int temp=right[j];
                right[j]=right[j+1];
                right[j+1]=temp;
            }
        }
    }
    //sort left in ascending order order
    for(i=0;i<temp1-1;i++)
    {
        for(j=0;j<temp1-i-1;j++)
        {
            if(left[j]>left[j+1])
            {
                int temp=left[j];
                left[j]=left[j+1];
                left[j+1]=temp;
            }
        }
    }
    int totalseektime=0,seektime;
    //for right side
    for(i=0;i<temp2;i++)
    {
        currentindex=right[i];
        seektime=abs(head-currentindex);
        printf("Head movement: %d ---> %d | Seek time:%d\n",head,currentindex,seektime);
        totalseektime+=seektime;
        head=currentindex;
    }
    currentindex=max;
    seektime=abs(head-currentindex);
    printf("Head movement: %d ---> %d | Seek time:%d\n",head,currentindex,seektime);
    totalseektime+=seektime;
    head=currentindex;
    currentindex=min;
    seektime=abs(head-currentindex);
    printf("Head movement: %d ---> %d | Seek time:%d\n",head,currentindex,seektime);
    totalseektime+=seektime;
    head=currentindex;
    //for left side
    for(i=0;i<temp1;i++)
    {
        currentindex=left[i];
        seektime=abs(head-currentindex);
        printf("Head movement: %d ---> %d | Seek time:%d\n",head,currentindex,seektime);
        totalseektime+=seektime;
        head=currentindex;
    }
    printf("Total seek time:%d\n",totalseektime);
}