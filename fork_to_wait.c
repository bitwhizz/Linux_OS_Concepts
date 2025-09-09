#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

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
		sleep(5);
		printf("child exiting...\n");
		exit(0);
	}
	//we must be in parent proccess

	printf("i am the parent,waiting for the child to end\n");
	wait(NULL);				//wait till child proccess becomes null
	printf("parent ending...\n");
	return 0;
} 
