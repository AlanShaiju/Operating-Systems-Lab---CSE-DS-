#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,i,j,f,frames[10],pages[200];
    int pagefaults=0,last=0;
    printf("Enter no of pages:");
    scanf("%d",&p);
    printf("Enter the page string:");
    for(i=0;i<p;i++)
        scanf("%d",&pages[i]);
    printf("Enter no of frames:");
    scanf("%d",&f);
    for(i=0;i<f;i++)
        frames[i]=-1;
    for(i=0;i<p;i++)
    {
        int found=0;
        int currentpage=pages[i];
        for(j=0;j<f;j++)
        {
            if(frames[j]==currentpage)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            frames[last]=currentpage;
            last=(last+1)%f;
            pagefaults++;
        }
        printf("Page reference: %d--->[ ",currentpage);
        for(j=0;j<f;j++)
        {
            if(frames[j]==-1)
                printf("- ");
            else
                printf("%d ",frames[j]);
        }
        if(found==1)
        printf("] No Page Fault\n");
        else
        printf("]  Page Fault\n");
    }
    printf("Total no of page faults:%d\n",pagefaults);
}