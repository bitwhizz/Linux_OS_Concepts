#include<stdio.h>
#include<sys/types.h>

void original_parent(void);
void original_child(void);

int main()
{


	if(fork()==0)
	{
		printf("original child process=%d %d\n",getppid(),getpid());
		original_child();
	}
	else
	{
		printf("original parent process %d %d\n",getppid(),getpid());
		original_parent();	
	}
}
void original_child(void)
{
	 if(fork()==0)
	printf("child in original child process=%d %d\n",getppid(),getpid());
	else
	printf("parent in original child process=%d %d\n",getppid(),getpid());
}

void original_parent(void)
{
	 if(fork()==0)
	printf("child in original parent process %d %d\n",getppid(),getpid());
	else
	printf("parent in original parent process %d %d\n",getppid(),getpid());
}

