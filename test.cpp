#include <iostream>
#include <pthread.h>
#include <ctime>

using namespace std;

void *runnable(void *ptr)
{
	char* msg;
	std::time_t t;
	msg = (char*) ptr;

	for(int i = 0; i <= 1000; i++)
	{
		t = time(NULL);
		cout << asctime(localtime(&t));
		cout << " " << msg << endl;
	}
	pthread_exit(0);
}

int main()
{
	pthread_t t1, t2;

	char* msg1 = "Hello World";
	char* msg2 = "Goodbye World";

	pthread_create(&t1, NULL, runnable, (void*) msg1);
	pthread_create(&t2, NULL, runnable, (void*) msg2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	return 0;
}