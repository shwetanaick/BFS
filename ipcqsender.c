#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
struct mymsg
{
  long mtype;
  char *mtext;
};
int main()
{
  struct mymsg ptr;
  int id;
  key_t key;
  key=9999;
  id=msgget(key,IPC_CREAT|0666);
  if(id==-1)
  {
    printf("message creation failed\n");
  }
  else
  {
    ptr.mtype=4;
    printf("Enter the msg\n");
    scanf("%s",ptr.mtext );
    msgsnd(id,&ptr,30,0);
    printf("message send successfully\n");
  }
}
