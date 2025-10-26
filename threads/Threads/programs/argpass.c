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
	//while(1)
	{
		printf("thread1 sleeping...\n");
		sleep(1);
		printf("thread1 awake... and dying\n");
		//printf("thread1=%d\n",*(int *)param);
	}
}

void * mythread2(void *param)
{
	int loop;
	struct mystruct *ptr;
	
	ptr=param;
	
	for(loop=0;loop<ptr->times;loop++)
	{
		printf("thread2 sleeping...\n");
		sleep(1);
		printf("thread2 awake...\n");
		//printf("thread2=%c\n",ptr->data);
	}
}

int main()
{
	struct mystruct myvar={'A',10};
	int mydata=10;
	pthread_t threadid1,threadid2;
	pthread_create(&threadid1,NULL,mythread1,&mydata);
	pthread_create(&threadid2,NULL,mythread2,&myvar);
	sleep(12);
	printf("Main dying\n");
	

}
