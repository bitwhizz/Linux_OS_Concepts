#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


void do_some_work(char *name)
{
	int i;
	const int NUM_TIMES=5;
	for(i=0;i<NUM_TIMES;i++)
	{
		sleep(rand() % 4);			//rand() -generate pseudo-random bytes
		printf("Done pass %d for %s\n",i,name);
	}
}


int main(int argc,char *argv[])
{
	printf("i am: %d \n",(int)getpid());
	pid_t pid=fork();
	srand((int)pid);				//pseudo random number generator
	printf("fork returned: %d \n",(int) pid);

	if(pid<0)
	{
		perror("fork failed");			//print a sytem error message
	}
	else if(pid==0)
	{
		printf("i am the child with pid: %d \n",(int) getpid());
		do_some_work("child");
		exit(55);				//child returned some value other than 0
	}
	//we must be in parent proccess

	printf("i am the parent,waiting for the childs to end\n");
	do_some_work("parent");				

	int child_status=0;		          //init daemon control tool

	pid_t childpid=wait(&child_status);
/*wait returns a status code via an integer pointer argument, from which
 you can extract information about how the child process exited.*/

	printf("parent knows child %d is finished with status %d \n",(int)childpid,child_status);

	int child_return_value=WEXITSTATUS(child_status);		//WEXITSTATUS macro extracts the child process’s exit code.

	printf("Return value was %d\n",child_return_value);
	return 0;
} 

/* execute program in terminal 1 and see the changes in terminal 2 by using   ps -a  command while program is running */
