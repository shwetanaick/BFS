#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#define size 50
int main()
{
  int x;
  key_t key=5678;
  x=shmget(key,size,IPC_CREAT|0666);
  if(x==-1)
  {
    printf("Failed\n");
  }
  else
  {
    printf("Success ID:%d\n",x);
  }
}
