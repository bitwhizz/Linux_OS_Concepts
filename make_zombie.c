#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t child_pid;
	/* Create a child process. */
	child_pid = fork ();
	if (child_pid > 0) 
	{
		/* This is the parent process. Sleep for a minute. */
		sleep (60);
	}
	else
	 {
		/* This is the child process. Exit immediately. */
		exit (0);
	}
	return 0;
} 

/* from another terminal type ps -e -o pid,ppid,stat,cmd and 
observe the zombie status code as Z+ it's child process marked as <defunct> */

/* When a program exits, its children are inherited by a special process, the init program, which
	always runs with process ID of 1 (it’s the first process started when Linux boots).The
	init process automatically cleans up any zombie child processes that it inherits. */

