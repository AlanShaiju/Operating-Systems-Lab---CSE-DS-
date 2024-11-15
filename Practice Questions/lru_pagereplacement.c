#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,i,j,f,pagefaults=0;
    int pages[30],frames[10],used[10];
    printf("Enter the no of pages:");
    scanf("%d",&p);
    printf("Enter the page string:");
    for(i=0;i<p;i++)
    scanf("%d",&pages[i]);
    printf("Enter the no of frames:");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        frames[i]=-1;
        used[i]=0;
    }
    for(i=0;i<p;i++)
    {
        int found=0;
        int leastindex=0;
        int currentpage=pages[i];
        for(j=0;j<f;j++)
        {
            if(frames[j]==currentpage)
            {
                found=1;
                used[j]=i;
                break;
            }
        }
        if(found==0)
        {
            for(j=1;j<f;j++)
            {
                if(used[leastindex]>used[j])
                leastindex=j;
            }
            frames[leastindex]=currentpage;
            used[leastindex]=i;
            pagefaults++;
        }
        printf("Page Reference: %d--->[ ",currentpage);
        for(j=0;j<f;j++)
        {
            if(frames[j]==-1)
            printf("- ");
            else
            printf("%d ",frames[j]);
        }
        if(found==0)
        printf("] Page Fault\n");
        else
        printf("] No Page Fault\n");  
    }
    printf("No of Page Faults:%d\n",pagefaults);
}