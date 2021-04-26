#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t ch[5];
pthread_t a[5];
int* p1(int i)
{
  printf("philosopher %d thinking\n",i);
  pthread_mutex_lock(&ch[i]);
  pthread_mutex_lock(&ch[(i+1)%5]);
  printf("philosopher %d eating\n",i);
  sleep(2);
  pthread_mutex_unlock(&ch[i]);
  pthread_mutex_unlock(&ch[(i+1)%5]);
  printf("philosopher %d finishes eating\n",i);
  pthread_exit(NULL);
}
int main()
{
  int i;
  for(i=0;i<5;i++)
  {
    pthread_mutex_init(&ch[i],NULL);
  }
  for(i=0;i<5;i++)
  {
    pthread_create(&a[i],NULL,(int *)p1,(int *)i);
  }
  for(i=0;i<5;i++)
  {
    pthread_join(a[i],NULL);
  }
  for(i=0;i<5;i++)
  {
    pthread_mutex_destroy(&ch[i]);
  }
}
