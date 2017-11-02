#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void clook(int a[], int n)
{
    int t=0,i,j,temp,head,pos;
    printf("assuming start and end as 0 and 200 and a decreasing order of access\n");
    head=a[0];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //look for head
    for(i=0;i<=n;i++)
        if(a[i]==head)
            pos=i;
    printf("processing order che ");
    for(j=pos-1;j>=0;j--)
    {
        t=t+abs(a[j]-a[j+1]);
        printf("%d  ",a[j]);
    }
    t=t+abs(a[0]-a[n]);
    for(j=n;j>pos+1;j--)
    {
        t=t+abs(a[j]-a[j-1]);
        printf("%d  ",a[j]);
    }
    printf("%d ",a[pos+1]);
    printf("t ka value is %d ",t);
}
void look(int a[], int n)
{
    int t=0,i,j,temp,head,pos;
    printf("assuming start and end as 0 and 200 and a decreasing order of access\n");
    head=a[0];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //look for head
    for(i=0;i<=n;i++)
        if(a[i]==head)
            pos=i;
    printf("processing order che ");
    for(j=pos-1;j>=0;j--)
    {
        t=t+abs(a[j]-a[j+1]);
        printf("%d  ",a[j]);
    }
    t=t+abs(a[0]-a[pos+1]);
    for(j=pos+1;j<n;j++)
    {
        t=t+abs(a[j]-a[j+1]);
        printf("%d  ",a[j]);
    }
    printf("%d ",a[j]);
    printf("t ka value is %d ",t);
}
void scan(int a[], int n)
{
    int t=0,i,j,temp,head,pos;
    printf("assuming start and end as 0 and 200 and a decreasing order of access\n");
    head=a[0];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //look for head
    for(i=0;i<=n;i++)
        if(a[i]==head)
            pos=i;
    printf("processing order che ");
    printf("%d",head);
    for(j=pos-1;j>=0;j--)
    {
        t=t+abs(a[j]-a[j+1]);
        printf("%d  ",a[j]);
    }
    printf(" 0 ");

    t=t+a[0]+a[pos+1];
    for(j=pos+1;j<n;j++)
    {
        t=t+abs(a[j]-a[j+1]);
        printf("%d  ",a[j]);
    }
    printf("%d ",a[j]);
    printf("t ka value is %d ",t);
}
void sstf(int a[], int n)
{
    int i,j,t=0,pos,s,min,d,temp;

    printf("processing order is: ");
    for(i=0;i<n;i++)
    {
        min=1000;
        for(j=i+1;j<=n;j++)
        {
            d=abs(a[i]-a[j]);
            if(d<min)
            {
                min=d;
                pos=j;
            }
        }
        t=t+abs(a[i]-a[pos]);
        temp=a[i+1];
        a[i+1]=a[pos];
        a[pos]=temp;
    }
    printf("t ka value is %d",t);
    printf("enter time to cross one disk");
    scanf("%d",&s);
    printf("seek time = %d",s*t);
    printf("processing order  ");
    for(i=0;i<=n;i++)
        printf("%d   ",a[i]);
}
void fifo(int a[], int n)
{
    int i,j,t=0,s;

    printf("processing order is: ");
    for(i=0;i<n;i++)
    {
        printf("%d   ",a[i]);
        t=t+abs(a[i]-a[i+1]);

    }
    printf("t ka value is %d",t);
    printf("enter time to cross one disk");
    scanf("%d",&s);
    printf("seek time = %d",s*t);
}
int main()
{
    int i,j,k,a[10]={100,27,129,110,186,147,41,10,64,120},n=9,c;
    /*printf("enter head pos");
    scanf("%d",&a[0]);
    printf("enter no of cylinders");
    scanf("%d",&n);
    printf("enter values");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);*/
    do{

    printf("MENU: \n1.FCFS\n2.SSTF\n3.LOOK\n4.SCAN\n6.CSCAN\n5.CLOOK");
    printf("enter choice");
    scanf("%d",&c);
    switch(c)
    {
        case 1: fifo(a,n);
            break;
    case 2: sstf(a,n);
            break;
    case 3: look(a,n);
            break;
    case 4: scan(a,n);
            break;
    case 5: clook(a,n);
            break;
    case 10: printf("lol bye");
            break;
    }

    } while(c!=10);
    return 0;
}