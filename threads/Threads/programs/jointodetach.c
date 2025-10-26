#include<stdio.h>
#include<pthread.h>

void * mythread( void *unused)
{
	printf("I am created in joinable state...\n");
	printf("Turning my state to detached\n");
	
	//enable below line and check if main is able to join to
	//this thread successfully or not
	
	//if(pthread_detach(pthread_self())==0)
	//	printf("Detached successfully\n");
	sleep(2);
	printf("I am dying now\n");
}

int main()
{
	pthread_t threadid;
	
	pthread_create(&threadid,NULL,mythread,NULL);
	
	sleep(2);		
	if(pthread_join(threadid,NULL)==0)
		printf("Joined successfully\n");
	printf("Main is dying\n");
	
}		
