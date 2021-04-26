#include<stdio.h>
#include<sys/ipc.h>
#include <unistd.h>
int main()
{
  int a[2],b[2],x,f=0,n,i,p,s,y;
  int fib[20],fib1[20];
  pipe(a);
  pipe(b);
  x=fork();
  if(x>0)
  {
    close(a[0]);
    printf("Enter the limit\n");
    scanf("%d",&n);
    write(a[1],&n,sizeof(n));
    // sleep(3);
    close(b[1]);
    read(b[0],fib1,sizeof(fib1));
    printf("Fibonacci Series\n");
    for(i=0;i<n;i++)
    {
      printf("%d\t",fib1[i]);
    }
  }
  else if(x==0)
  {
    close(a[1]);
    read(a[0],fib,sizeof(fib));
    printf("Enter the limit\n");
    for(i=0;i<p;i++)
    {
      f=f+s;
      fib[i]=f;
      s=y;
      y=fib[i];
    }
    close(b[0]);
    write(b[1],fib,sizeof(fib));
  }
}
