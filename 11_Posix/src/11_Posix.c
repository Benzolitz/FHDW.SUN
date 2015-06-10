#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
	int sharedFile;
	void *ptr;
	char message[] = "Hello Posix!\n";
	char fileName[] = "/11_Posix";

	sharedFile = shm_open(fileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); // create, or access File
	ftruncate(sharedFile, (off_t) sizeof(message)); // allocate space for file
	ptr = mmap(0, sizeof(message), PROT_READ | PROT_WRITE, MAP_SHARED, sharedFile, 0); // write file into shared memory

	strncpy(ptr, message, sizeof(message)); // write text into file

	shm_unlink(fileName); // remove file fromshared memory

	return 1;
}
