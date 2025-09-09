#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;
/* safe to use sig_atomic_t for these global variables in signals*/

void handler (int signal_number)
{
++sigusr1_count;
}	

int main ()
{
	/*sigaction structure have sa_handler*/
	struct sigaction sa;
	
	/*memset fills the sizeof(sa) bytes of memory area at address of sa with  0 bytes */ 
	memset (&sa,0,sizeof(sa));

	sa.sa_handler = &handler;	//function pointer--> assign address of func to the pointer to structure

	/*examine and change a signal action-->sigaction(signal number,pointer to sigaction structure) */
	sigaction(SIGINT, &sa, NULL);		//signum (2)--SIGINT-->sigaction(2, &sa, NULL);

	while(sigusr1_count<10)
	{
		sleep(1);
		printf("hello ...pid=%d\n",getpid());
		/*raise() -send a signal to the caller */
		raise(SIGINT);		//raise(2);
	}

	printf("SIGUSR1 was raised %d times\n", sigusr1_count);
	return 0;
}


/* kill -l ---> to check lis of all signals */

/*sa_handler specifies the action to be associated with signum and may be
 SIG_DFL for the default action, SIG_IGN to ignore  this  signal, or  
a pointer to a signal handling function.  
This function receives the signal number as its only argument.*/


/* The sigaction structure is defined as something like:

           struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };	*/

/*sigaction() returns 0 on success; on error, -1 is returned */

