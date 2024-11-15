#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[3]={67,124,63};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<3;i++)
    printf("%d ",a[i]);
}