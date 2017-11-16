#include<stdio.h>
#include<mqueue.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <bits/types.h>
#include<string.h>
struct mq_attr  mq_comm_attr;
char buffer[128];
/*typedef int mqd_t;*/
int main()
{

	mqd_t mqcommand;
  mq_comm_attr .mq_flags=0;	/* Message queue flags.  */
  mq_comm_attr .mq_maxmsg=4;	/* Maximum number of messages.  */
  mq_comm_attr .mq_msgsize=128;	/* Maximum message size.  */
  mq_comm_attr .mq_curmsgs=0;	/* Number of messages currently queued.  */
	  
	mqcommand=mq_open("/mqcommand",O_CREAT | O_RDONLY,0600, &mq_comm_attr);
	mq_receive(mqcommand,buffer,128,0);
	printf("%s\n",buffer);
	mq_close(mqcommand);
	return 0;
}
