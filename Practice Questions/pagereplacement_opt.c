#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,p,f,pagefaults=0;
    int pages[30],frames[10],next[10];
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
        next[i]=0;
    }
    for(i=0;i<p;i++)
    {
        int found=0;
        int currentpage=pages[i];
        for(j=0;j<f;j++)
        {
            if(currentpage==frames[j])
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            int farthest=0;
            int replace=0;
            for(j=0;j<f;j++)
            {
                int nextfound=0;
                for(int k=i+1;k<p;k++)
                {
                    if(pages[k]==frames[j])
                    {
                        next[j]=k;
                        nextfound=k;
                        break;
                    }
                }
                if(nextfound==0)
                {
                    replace=j;
                    break;
                }
                else
                {
                    if(next[j]>farthest)
                    {
                        farthest=next[j];
                        replace=j;
                    }
                }

            }
            frames[replace]=currentpage;
            pagefaults++;
        }
        printf("Page Reference:%d--->[ ");
        for(j=0;j<f;j++)
        {
            if(frames[j]==-1)
            printf("- ");
            else
            printf("%d ",frames[j]);
        }
        if(found==0)
        printf("] PageFault\n");
        else
        printf("] No PageFault\n");
    }
    printf("No of Page Faults:%d",pagefaults);
}