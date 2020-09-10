#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n = 1, i = 0;
	if (argc == 1)
	{
		printf("\n");
	}
	else
	{	
		if (!strcmp(argv[1], "-n"))
		{
			n = 2;
		}
		
		for(i = n; i < argc; i++)
		{
			char *arg = argv[i];
			printf("%s ", arg);
		}
		if (n != 2)
		{
			printf("\n");
		}
		
	}
	
}
