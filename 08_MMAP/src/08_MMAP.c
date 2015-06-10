#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int file;
	void *memoryPointer;
	char filePath[] = "./08_MMAP";

	file = open(filePath, O_CREAT || O_RDWR);

	memoryPointer = mmap(0, 1024, PROT_READ, MAP_PRIVATE, file, sizeof(file));

	printf("Pointer to file: %d\n", (int) memoryPointer);

	close(file);

	return 1;
}
