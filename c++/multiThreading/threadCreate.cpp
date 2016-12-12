#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;
typedef struct thread_data{
   char *name;
   char *message;
}THREAD_ARG;
void* threadFunction(void * param){
	cout<<"Thread Body here "<<endl;
	THREAD_ARG *par = (THREAD_ARG *)param;
	cout<<par->name<<" says "<<par->message<<endl;
	for(int i=1;i<=10;i++){
		if(i&1)
			cout<<i<<" is odd"<<endl;
		else
			sleep(2);
	}
	cout<<" Thread exiting "<<endl;
	pthread_exit(NULL);
}
int main(){
	pthread_t thread;
	THREAD_ARG arg;
	arg.name="Akash";
	//fflush(0);
	arg.message="Hello";
	cout<<"thread Created"<<endl;
	int status = pthread_create(&thread,NULL,threadFunction,(void *)&arg);
	cout<<"Thread creation status :"<<status<<endl;

	int rc = pthread_join(thread,NULL);
	for(int i=1;i<=10;i++){
		if(!(i&1))
			cout<<i<<" is even"<<endl;
		else
			sleep(1);
	}
	cout<<"main Finished";
	pthread_exit(NULL);
}