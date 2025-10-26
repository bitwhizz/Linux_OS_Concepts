#include<stdio.h>
#include<pthread.h>
void* hello(void* x)
{
	pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, NULL);	
	 printf("thread_func(): started; cancellation disabled\n");
           //sleep(5);	
	int i;	
	for(i=0;i<5;i++)
	{
	sleep(1);
	printf("hello\t");
	}
	printf("thread_func(): about to enable cancellation\n");	
	pthread_setcancelstate (PTHREAD_CANCEL_ENABLE, NULL);
	printf("thread1 is NOT canceled\n");
	//return NULL;
}

int main()
{
	pthread_t thread1_id;
	int i;
	if(pthread_create(&thread1_id,NULL,&hello,0)==-1)
	{
		printf("could not create thread\n");
		return -1;
	}
	sleep(2);
	printf("main(): sending cancellation request\n");
	pthread_cancel(thread1_id);
	for(i=0;i<15;i++)
	{
	sleep(1);
	printf("world\n");
	}
	//pthread_join(thread1_id,0);	
	return 0;
}
	
