#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    int len;
}File;
int main()
{
    int n,i,j;
    File files[10];
    printf("Enter no of files:");
    scanf("%d",&n);
    printf("Enter details of files:\n");
    for(i=0;i<n;i++)
    {
        printf("File %d details(id,length:",i+1);
        scanf("%d,%d",&files[i].id,&files[i].len);
    }
    for(i=0;i<n;i++)
    {
        File file=files[i];
        int* blocks=(int*)malloc(file.len*sizeof(int));
        if(blocks==NULL)
        {
            printf("Error allocating memory\n");
        }
        for(j=0;j<file.len;j++)
        {
            blocks[j]=rand()%410;
        }
        printf("Allocated Blocks:");
        for(j=0;j<file.len;j++)
        {
            printf("%d ",blocks[j]);
        }
        printf("\n");
        free(blocks);
    }
}
