#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int id;
    int sblock;
    int len;
}File;
int main()
{
    int allocated=0,disksize=0,n,i;
    File files[10];
    printf("Enter no of files:");
    scanf("%d",&n);
    printf("Enter file details for each file(FileId,StartBlock,Length:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter details for File %d:",i+1);
        scanf("%d,%d,%d",&files[i].id,&files[i].sblock,&files[i].len);
    }
    printf("Enter disk size:");
    scanf("%d",&disksize);
    for(i=0;i<n;i++)
    {
        File file=files[i];
        if(file.sblock+file.len-1<=disksize)
        {
            allocated=allocated+file.len;
            printf("File:%d  Allocated from %d to %d\n",file.id,file.sblock,file.sblock+file.len-1);
        }
        else
        {
            printf("Cannot allocate file:%d\n",file.id);
        }
    }
    printf("Total Allocated Blocks:%d\n",allocated);
}
