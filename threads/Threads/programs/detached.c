#include<stdio.h>
#include<pthread.h>

void * mythread(void *var)
{
	printf("mythread executing...\n");
}

int main()
{
	pthread_t threadid;
	
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_create(&threadid,&attr,mythread,NULL);
	
	sleep(1);
	printf("Main thread is dying\n");
}	
