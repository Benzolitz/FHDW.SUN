#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutexOne;
pthread_mutex_t mutexTwo;

void *lockMutexOne(void *args)
{
	pthread_mutex_lock(&mutexOne);
	sleep(1);
	pthread_mutex_lock(&mutexTwo);

	// Critical area

	pthread_mutex_unlock(&mutexOne);
	pthread_mutex_unlock(&mutexTwo);

	return 1;
}

void *lockMutexTwo(void *args)
{
	pthread_mutex_lock(&mutexTwo);
	sleep(1);
	pthread_mutex_lock(&mutexOne);

	// Critical area

	pthread_mutex_unlock(&mutexTwo);
	printf("All threads are done!\n");
	pthread_mutex_unlock(&mutexOne);

	return 1;
}

int main()
{
	int threadOne, threadTwo;
	pthread_t threadOneId, threadTwoId;
	void *threadOnePointer, *threadTwoPointer;

	pthread_mutex_init(&mutexOne, NULL);
	pthread_mutex_init(&mutexTwo, NULL);

	threadOne = pthread_create(&threadOneId, 0, lockMutexOne, 1);
	threadOne = pthread_create(&threadTwoId, 0, lockMutexTwo, 2);

	pthread_join(threadOneId, &threadOnePointer);
	pthread_join(threadTwoId, &threadTwoPointer);

	// The code will never come this far!

	pthread_mutex_destroy(&mutexOne);
	pthread_mutex_destroy(&mutexTwo);

	return 1;
}
