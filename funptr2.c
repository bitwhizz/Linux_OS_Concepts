
#include<stdio.h>
//#define simple_way
#define function_pointer

#ifdef simple_way
/* function prototype */
int func(int, int);
int main(void)
{
    int result;
    /* calling a function named func */
    result = func(10,20);       
    printf("result = %d\n",result);
    return 0;
}
 
/* func definition goes here */
int func(int x, int y)             
{
	return x+y;
}
#endif


#ifdef function_pointer
int func(int, int);
int main(void)
{
    int result1,result2;
    /* declaring a pointer to a function which takes
       two int arguments and returns an integer as result */
    int (*ptrFunc)(int,int);
 
    /* assigning ptrFunc to func's address */                     
    ptrFunc=func;
 
    /* calling func() through explicit dereference */
    result1 = (*ptrFunc)(10,20);
 
    /* calling func() through implicit dereference */         
    result2 = ptrFunc(10,20);               
    printf("result1 = %d result2 = %d\n",result1,result2);
    return 0;
}
 
int func(int x, int y)
{
    return x+y;
}
#endif
