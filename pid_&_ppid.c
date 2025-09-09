#include<stdio.h>
#include<unistd.h>
//#include<sys/types.h>


int main()
{
	while(1)
	{
		sleep(1);						//pause for no of seconds
		printf("i am running in the process with pid=%d\n",getpid());
		printf("my parent process pid is =%d \n",getppid());
		sleep(1);
	}
	return 0;
}

/*if you invoke this program several times different pid is reported,but parent pid will be same */

/* this program gives the address of the pid(process id) and ppid (parent process id) */

/*ps -o pid,ppid,cmd for bash ,and 
ps -e -o pid,ppid,cmd for all the process */

