#include <stdio.h>
#include <pthread.h>

void* thread_one(void *args)
{
	printf("This is the first Thread!\n");

	sleep(1);

	pthread_exit(999); // pthread_exit will return the value into the pointer.
}

void* thread_two(void *args)
{
	printf("This is the second Thread!\n");

	sleep(2);

	return 1; // return will not return the given value
}

int main()
{
	pthread_t threadOneId, threadTwoId;

	void *ptrOne, *ptrTwo;

	int rcOne = pthread_create(&threadOneId, NULL, thread_one, NULL);
	int rcTwo = pthread_create(&threadTwoId, NULL, thread_two, NULL);

	int rcOneJoin = pthread_join(threadOneId, &ptrOne);
	int rcTwoJoin = pthread_join(threadOneId, &ptrTwo);

	printf("Waited for both Threads, until exit of main!");

	return 1;
}
