#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t child;
  int fd[2],fd1[2];
  char s[10],s1[10],a[10],a1[10];
  pipe(fd);
  pipe(fd1);
  if((child=fork())>0)
  {
    close(fd[0]);
    printf("Parent write:");
    scanf("%s",s);
    write(fd[1],s,sizeof(s));
    // sleep(4);
    close(fd1[1]);
    read(fd1[0],a1,sizeof(a1));
    printf("Parent read:%s\n",a1);
  }
  else
  {
    close(fd[1]);
    read(fd[0],s1,sizeof(s1));
    printf("Child read:%s\n",s1);
    close(fd1[0]);
    printf("Child write:");
    scanf("%s",a);
    write(fd1[1],a,sizeof(a));
  }
}
