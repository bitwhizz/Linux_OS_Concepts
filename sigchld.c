#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
/*clean up the child process */
int status;
wait(&status);

/*store its exit status in a global variable */
child_exit_status=status;

printf("child exit status= %d \n",child_exit_status);
}


int main()
{
/* handle SIGCHLD by calling clean_up_child_process  */
struct sigaction sigchld_action;

memset(&sigchld_action,0,sizeof(sigchld_action));

sigchld_action.sa_handler = &clean_up_child_process;

sigaction(SIGCHLD,&sigchld_action,NULL);

pid_t child_pid;

child_pid=fork();

if(child_pid==0)
{
printf("child pid =%d \n",getpid());
raise(SIGCHLD);
sleep(10);
}
//printf("child exit status= %d \n",child_exit_status);
return 0;
}
