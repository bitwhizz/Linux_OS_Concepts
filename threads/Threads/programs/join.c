#include<pthread.h>
#include<stdio.h>

/* when main thread dies,all the other thread dies*/
/* Any non-main thread dies, other thread are not affected */



struct mystruct
{
	char data;
	int times;
};


void * mythread1(void *param)
{
	int loop;
	struct mystruct *ptr;
	
	ptr=param;	
	for(loop=0;loop<ptr->times;loop++)
	{		
		sleep(1);
		printf("thread1=%c\n",ptr->data);
	}
	
	return (void *)1;
}

void * mythread2(void *param)
{
	int loop;
	struct mystruct *ptr;
	
	ptr=param;	
	for(loop=0;loop<ptr->times;loop++)
	{		
		sleep(1);
		printf("thread2=%c\n",ptr->data);
	}
	
	return (void *)2;
}

int main()
{
	struct mystruct myvar1={'A',5};
	struct mystruct myvar2={'B',10};
	
	int mydata=10;
	int return1;
	int return2;
	
	pthread_t threadid1,threadid2;
	
	pthread_create(&threadid1,NULL,mythread1,&myvar1);
	pthread_create(&threadid2,NULL,mythread2,&myvar2);
	
	pthread_join(threadid1,(void *)&return1);
	pthread_join(threadid2,(void *)&return2);
	
	printf("Value returned from threads:\n");
	printf("r1=%d,r2=%d\n",return1,return2);
	printf("Main dying\n");
	

}	
