#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int* print1()
{
  while(1)
  {
    printf("thread1\n");
  }
  pthread_exit(0);
}
int* print2()
{
  while(1)
  {
    printf("thread2\n");
  }
}
int main()
{
  pthread_t td1,td2;
  pthread_create(&td1,NULL,print1,NULL);
  pthread_create(&td2,NULL,print2,NULL);
  pthread_join(td1,NULL);
  pthread_join(td2,NULL);
}
