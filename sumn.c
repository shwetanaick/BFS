#include <stdio.h>
#include <unistd.h>
int main()
{
  int a[2],b[2],x,s=0;
  int ar[20],i,p,n,sum;
  pipe(a);
  pipe(b);
  x=fork();
  if(x>0)
  {
    close(a[0]);
    printf("Enter the limit\n");
    scanf("%d",&n);
    write(a[1],&n,sizeof(n));
    // sleep(2);
    close(b[1]);
    read(b[0],&sum,sizeof(sum));
    printf("Sum=%d\n",sum);
  }
  else if(x==0)
  {
    close(a[1]);
    read(a[0],&p,sizeof(p));
    printf("Enter the elements\n");
    for(i=0;i<p;i++)
    {
      scanf("%d",&ar[i]);
    }
    for(i=0;i<p;i++)
    {
      s=s+ar[i];
    }
    close(b[0]);
    write(b[1],&s,sizeof(s));
  }
}
