#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    // A long long wait so that we can easily issue a signal to this process
printf("hi linux pid=%d \n",getpid());
    while(1) 
{
sleep(1);
printf("hello \n");
}
    return 0;
}
/*kill -USR1 pid_no from another terminal to see o/p */

/*We see that in the above code, we have tried to handle a user defined signal USR1. 
Also, as we know that two signals KILL and STOP cannot be handled. 
So we have also tried to handle these two signals 
so as to see how the ‘signal’ system call responds in this case.*/

/*run executable file in one terminal and send commands from another terminal  */

/*
use the list and check for no of particular signal , cmd: kill -l
kill -2 pid_no-->interrupt
kill -19 pid_no-->stop
kill -18 pid_no-->continue
kill -9 pid_no-->killed
etc....
*/
