#include <stdio.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  int fd[2],f;
  char s[20],a[20];
  pipe(fd);
  f=fork();
  if(f>0)
  {
    close(fd[0]);
    printf("Enter the msg:");
    scanf("%s",s);
    write(fd[1],s,sizeof(s));
  }
  else if(f==0)
  {
    close(fd[1]);
    read(fd[0],a,sizeof(a));
    printf("The msg is:%s\n",a);
  }
  else
  {
    perror("Error");
  }
  return(0);
}
