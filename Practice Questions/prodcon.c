#include<stdio.h>
#include<stdlib.h>
int darray[5],top=-1;
int main()
{
    int n=0;
    while(n!=4)
    {
        printf("1)Producer 2)Consumer 3)Display 4) Exit\n");
        scanf("%d",&n);
        if(n==1)
        producer();
        else if(n==2)
        consumer();
        else if(n==3)
        display();
        else if(n==4)
        printf("Exiting");
        else
        printf("Enter a proper option");
    }

}
int producer()
{
    int data;
    if(top+1==5)
    {
        printf("Array full\n");
        return;
    }
    else
    {
        printf("enter the data\n");
        scanf("%d",&data);
        top=top+1;
        darray[top]=data;
        printf("Data stored to array\n");
    }
}
int consumer()
{
    int data;
    if(top==-1)
    {
        printf("Array is empty no data to consume\n");
        return;
    }
    else
    {
        printf("data consumed is %d",darray[top]);
        top=top-1;
    }
}
int display()
{
    if(top==-1)
    {
        printf("No data to display\n");
        return;
    }
    else
    {
        for(int i=top;i>=0;i--)
        printf("%d ",darray[i]);
    }
}