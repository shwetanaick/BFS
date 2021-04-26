#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
struct mymsg
{
  long mtype;
  char *mtext;
};
int main()
{
  struct mymsg p;
  int id,f;
  key_t key;
  key=9999;
  f=fork();
  if(f==0)
  {
    id=msgget(key,0666);
    msgrcv(id,&p,30,3,0);
    printf("the message is received\n");
    printf("%s\n",p.mtext);
  }
  else if(f>0)
  {
    id=msgget(key,IPC_CREAT|0666);
    if(id==-1)
    {
      printf("Enter the msg\n");
      scanf("%s",p.mtext);
      msgsnd(id,&p,30,0);
      printf("The msg send successfully\n");
    }
  }
  else
  {
    printf("Error\n");
  }
}
