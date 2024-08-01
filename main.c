#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty <file>\n" );
		return (EXIT_FAILURE);
	}

	printf("filename given: %s\n", argv[1]);

	return (EXIT_SUCCESS);
}
