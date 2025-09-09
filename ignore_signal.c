#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

void handleit(int a);

int main()
{
	if(signal(SIGINT,handleit)!=SIG_ERR)
	{
		printf("signal handler is installed sucessfully\n");
		
	}
	while(1)
	{
		sleep(1);
		printf("hello..%d \n",getpid());
	}
	return 0;
}

void handleit(int a)
{
	signal(SIGINT,SIG_IGN);
	printf("signal not ignored\n");
}


	



