#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void handleit(int a);

int main()
{

/*signal()  returns  the previous value of the signal handler, or SIG_ERR on error.*/
	if(signal(SIGINT,handleit)!=SIG_ERR)
	{
		printf("signal handler is installed sucessfully\n");
	}
	while(1)
	{
		sleep(1);
		printf("hello..\n");
	}
	return 0;
}

void handleit(int a)
{
	printf("SIGINT handled \n");
}

/* if we send SIGINT (ctrl+c) then signal() function executes handleit() function  */
	
/*signal() sets the disposition of the signal signum to handler, which is
either SIG_IGN, SIG_DFL, or the address of a  programmer-defined  function */

/* If  the signal signum is delivered to the process, then one of the fol‐
       lowing happens:

       *  If the disposition is set to SIG_IGN, then the signal is ignored.

       *  If the disposition is set to SIG_DFL, then the default action  asso‐
          ciated with the signal (see signal(7)) occurs.

       *  If  the disposition is set to a function, then first either the dis‐
          position is reset to SIG_DFL, or the signal is blocked  (see  Porta‐
          bility  below), and then handler is called with argument signum.  If
          invocation of the handler caused the signal to be blocked, then  the
          signal is unblocked upon return from the handler.  */


