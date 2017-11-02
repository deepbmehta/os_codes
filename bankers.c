#include<stdio.h>

int main()
{
    int i,j,r,p,k,deadlock,finishall,count=0;
    int alloc[10][10],need[10][10],max[10][10],finish[10]={0},avail[10];

    printf("enter total resources\n");
    scanf("%d",&r);
    printf("enter total processes\n");
    scanf("%d",&p);
    printf("enter alloc matrix");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter max matrix");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter avail array");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    do{
        for(i=0;i<p;i++)
        {
            count=0;
            if(finish[i]==0)
            {
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>avail[j])
                        break;
                }
                if(j==r)
                {
                    for(k=0;k<r;k++)
                    {
                        avail[k] = avail[k] + alloc[i][k];
                        finish[i]=1;
                    }
                    printf("Process P%d --> ",i+1);

                }
                else
                {
                    count++;
                }
            }
            else
            {
                count++;
            }
            for(j=0;j<p;j++)
            {
                if(finish[j]==0)
                    break;
            }
            if(j==p)
                finishall=1;
            if(count==p)
                deadlock=1;
        }
    }while(finishall!=1 && deadlock!=1);
    if(deadlock==1) printf("system in deadlock state");
    else printf("system in safe mode");
    printf("\ndisplay time\n");
    printf("Allocation matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("\n");
    }
    printf("Max matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\n");
    }
    printf("Need matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("Available matrix\n");
    for(i=0;i<r;i++)
        printf("%d ",avail[i]);
    
}