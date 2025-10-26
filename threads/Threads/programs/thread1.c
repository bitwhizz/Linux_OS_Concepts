#include<pthread.h>
#include<stdio.h>

void * mythread(void *param)
{
	while(1)
	{
		printf("thread1=%d\n",getpid());
		sleep(1);
	}
}

int main()
{
	pthread_t threadid;
	pthread_create(&threadid,NULL,mythread,NULL);
	while(1)
	{
		sleep(1);
		printf("main=%d\n",getpid());
	}

}
