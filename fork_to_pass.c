#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void do_some_work(void)
{
	int i;
	const int num_times=5;
	for(i=0;i<num_times;i++)
	{
		sleep(rand() % 4);			//rand() -generate pseudo-random bytes
		printf("Done pass %d \n",i);
	}
}


int main(int argc,char *argv[])
{
	printf("i am: %d \n",(int)getpid());
	pid_t pid=fork();
	printf("fork returned: %d \n",(int) pid);

	if(pid<0)
	{
		perror("fork failed");
	}
	else if(pid==0)
	{
		printf("i am the child with pid: %d \n",(int) getpid());
		do_some_work();
		exit(0);
	}
	//we must be in parent proccess

	printf("i am the parent,waiting for the child to end\n");
	wait(NULL);				//wait till child proccess becomes null
	printf("parent ending...\n");
	return 0;
} 

/* execute program in terminal 1 and see the changes in terminal 2 by using   ps -a  command while program is running */
