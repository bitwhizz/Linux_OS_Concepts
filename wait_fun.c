#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int child_status;
	
	printf("before forking %d\n",(int)getpid());

	pid_t pid=fork();


	/*if fork is running in parent process then return the pid of child process
	but if fork is running in the child process then return pid as zero(0)   */

	if(pid==0)
	{
			printf("i'm in child process=%d\n",(int)getpid());		//gives  pid of parent and child process
			sleep(10);			//child process is running in background in this time send signal
			exit(59);					//exit code ( 0 is the standard for success)
	}
		
	printf("i'm in parent process %d\n",(int)getpid());		//gives pid of bash and parent process

	wait(&child_status);

	if (WIFEXITED (child_status))
	printf ("the child process exited normally, with exit code %d\n",WEXITSTATUS(child_status));
	else
	printf ("the child process exited abnormally because of signal no:%d\n",WTERMSIG(child_status));
	//return 0;					//check in cmd terminal return value using echo $?
}

/*wait() returns a status code via an integer pointer argument,
 	from which you can extract information about how the child process exited.*/

/*WIFEXITED macro to determine from a child process’s exit status whether 
that process exited normally (via the exit function or returning from main )
  or died from an unhandled signal. */

/*WEXITSTATUS macro extracts the child process’s exit code*/

/*WTERMSIG macro to extract from its exit status the signal number by which it died.*/

/*send any signal using kill -(signal no) childpid from one terminal and oberve in another terminal */



