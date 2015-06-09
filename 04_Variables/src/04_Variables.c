#include <stdio.h>

#define amount = 20; // #define variables are read-only. The value of this variable will be parsed before the compiler compiles this file!

int minimal = 5; // Global variables are accessible throughout the entire process. Every function can change this variable!

void testFunction()
{
	static int maximal = 100; // static variables are only accessible in one function, but the variable will keep its current value when the function is finished!

	maximal -= 20;

	printf("new maximal: %d!\n", maximal);

	if (maximal <= 0)
		printf("maximal finally <= 0!\n");

}

int main()
{
	int check = 33; // local variables are only accessible in one function and will lose its current value, when the function is finished!

	int i;
	for (i = 0; i < minimal; i++)
	{
		testFunction();
	}

	return 1;
}
