#include<stdio.h>
#include <unistd.h>
int main()
{
    int pid;
    int p1[2],p2[2];
    pipe(p1);
    pipe(p2);
    int b,n,i,f1,f2;int ar[30],br[30];
    pid=fork();
    if(pid==0)
    {
        printf("enter count:");
        fflush(stdin);
        scanf("%d",&n);
        close(p1[0]);
        write(p1[1],&n,4);

        close(p2[1]);
        read(p2[0],br,30*sizeof(int));
        printf("\nFibonacci:\n");
        for(i=0;i<n;i++)
            printf("%d\n",br[i]);

    }
    else if(pid>0)
    {
    close(p1[1]);
    read(p1[0],&b,4);
    //printf("count is:%d",b);

    f1=0,f2=1;
    ar[0]=0;
    ar[1]=1;
    int i;
    for(i=2;i<b;i++)
    {
        int f3=f1+f2;
        f1=f2;
        f2=f3;
        ar[i]=f3;
    }
    close(p2[0]);
    write(p2[1],ar,30*sizeof(int));
    }
}
