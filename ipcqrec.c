#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
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
  key=8643;
  id=msgget(key,0666);
  msgrcv(id,&ptr,30,4,0);
  printf("The message is received\n");
  printf("%s\n",ptr.mtext);
}
