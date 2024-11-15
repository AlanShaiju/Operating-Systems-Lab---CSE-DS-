#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    int startblock;
    int len;
}File;
int main()
{
    int blocksize=0,allocated=0,n,i,j;
    printf("Enter no of blocks:");
    scanf("%d",&n);
    File files[10];
    printf("Enter details of file:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter file %d details(Id,Startblock,Length):",i+1);
        scanf("%d,%d,%d",&files[i].id,&files[i].startblock,&files[i].len);
    }
    printf("Enter blocksize:");
    scanf("%d",&blocksize);
    for(i=0;i<n;i++)
    {
        File file=files[i];
        int indexsize=(file.len+blocksize-1)/blocksize;
        int *index=(int*)malloc(indexsize*sizeof(int));
        if(index==NULL)
        {
            printf("Error allocating memory\n");
            return;
        }
        for(j=0;j<indexsize;j++)
        {
            index[j]=rand()%blocksize;
        }
        allocated+=indexsize;
        printf("The allocated blocks are:");
        for(j=0;j<indexsize;j++)
        {
            printf("%d ",index[j]);
        }
        printf("\n");
        free(index);
    }
    printf("Total Allocated Blocks:%d",allocated);
}