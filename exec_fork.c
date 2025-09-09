#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Spawn a child process running a new program.
(1) program_name is the name of the program to run; the path will be searched for this program.

(2) arg_list is a NULL-terminated list of character strings to be passed as the program’s argument list.
 Returns the process ID ofthe spawned process. */


int spawn (char* program_name, char** arg_list)
{
	pid_t child_pid;
	/* Duplicate this process. */
	child_pid = fork ();

	if (child_pid != 0)
	{
	/* This is the parent process. */
	printf("pid2:%d\n",getpid());
	return child_pid;
	}
	else
	 {
	/* This is the child process. */
	printf("pid3:%d\n",getpid());

	/* Now execute program_name(ls), searching for it in the path. */
	execvp (program_name, arg_list);

	/* The execvp function returns only if an error occurs. */
	fprintf (stderr, "an error occurred in execvp\n");
	abort ();
	}	
}
int main ()
{
	/* The argument list to pass the “ls” command. */
	char* arg_list[] = {"ls","-l","/",NULL};
	/* argv[0], the name of the program. */
	/* The argument list must end with a NULL.*/


	/* Spawn a child process running the “ls” command.Ignore the returned child process ID. */
	printf("pid1:%d\n",getpid());
	//spawn("ls", arg_list);
	spawn(arg_list[0], arg_list);
	
	printf("done with main program\n");

	wait(NULL);
	return 0;
}


