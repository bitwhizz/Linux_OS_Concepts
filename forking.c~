#include<stdio.h>
//#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("before forking %d %d\n",(int)getppid(),(int)getpid());
	if(fork()==0)
	{

		printf("i'm in child process %d %d\n",(int)getppid(),(int)getpid());		//gives  pid of parent and child process
		
	}
	else
	{
		printf("i'm in parent process=%d %d\n",(int)getppid(),(int)getpid());		//gives pid of bash and parent process
	}
	return 0;
}

/*if fork is running in parent process then return the pid of child process
but if fork is running in the child process then return pid as zero(0)   */
