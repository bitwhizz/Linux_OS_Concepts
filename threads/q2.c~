/*wap that creates 2 threads, one that keeps printing hello and other that keeps printing world.*/
#include<stdio.h>
#include<pthread.h>
void* hello(void* x)
{
	while(1)
	{
	sleep(3);
	printf("the value o thread1 is %d\n",pthread_self());	
	printf("hello\t");
	}	
	return NULL;
}

int main()
{
	pthread_t thread_id;
	if(pthread_create(&thread_id,NULL,&hello,0)==-1)
	{
		printf("could not create thread\n");
		return -1;
	}
	while(1)
	{	
	sleep(3);	
	printf("world\n");
	printf("the value o thread2 is %d\n",pthread_self());
	}	
	return 0;
}
	
