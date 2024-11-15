#include<stdio.h>
#include<stdlib.h>
int top=-1;
int n;
int array[10];
int producer(int data)
{
    int val=data;
    if(top==(n-1))
    {
        printf("Producer is full\n");
        return ;
    }
    else
    {
        top=top+1;
        array[top]=data;
    }
}
int consumer()
{
    if(top==-1)
        printf("No data present to be consumed\n");
    else
    {
        printf("Data is consumed\n");
        printf("Data deleted is:%d\n",array[top]);
        top=top-1;
    }
}
int view()
{
    printf("The data present is as follows\n");
    for(int i=top;i!=-1;i--)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main()
{
    int x,data;
    printf("Enter size of the array");
    scanf("%d",&n);
    x=1;
    while(x==1)
    {
        printf("1)Produce Data 2)Consume Data 3)View Data 4)Exit\n");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter Data:");
                scanf("%d",&data);
                producer(data);
                break;
            case 2:
                consumer();
                break;
            case 3:
                view();
                break;
            case 4:
                printf("Exiting");
                x=0;
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    }

}
