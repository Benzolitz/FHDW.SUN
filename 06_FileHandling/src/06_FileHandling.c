#include <stdio.h>
#include <fcntl.h>

int main()
{
	int file;
	char buf[] = "Hallo Welt!"; // String (char-Array) which will be written into the file
	char filePath[] = "./06_FileHandling"; // relative-filepath

	file = open(filePath, O_CREAT || O_RDWR);

	if (file == -1)
		printf("ERROR! No File found!");

	write(file, buf, sizeof(buf) - 1);
	read(file, buf, sizeof(buf) - 1);
	close(file);
}
