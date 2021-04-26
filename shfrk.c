#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#define size 30
int main()
{
  int f,id;
  f=fork();
  char *g;
  key_t key;
  key=9999;
  if(f==0)
  {
    id=shmget(key,size,IPC_CREAT | 0666);
    g=shmat(id,NULL,0);
    printf("The message send by the server is %s\n",g);
  }
  else if(f>0)
  {
    id=shmget(key,size,IPC_CREAT | 0666);
    if(id==-1)
    {
      printf("Error\n");
    }
    else
    {
      g=shmat(id,NULL,0);
      strcpy(g,"hello");
      printf("server sends msg to client\n");
    }
  }
  else
  {
    printf("Error\n");
  }
}
