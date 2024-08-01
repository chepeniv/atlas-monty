#include "monty.h"

int main(int argc, char **argv)
{
	FILE *mfile;
	char *file_line = NULL;
	size_t read_bytes;
	char *open_mode = "r";
	/* create stack variable */

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty <file>\n" );
		return (EXIT_FAILURE);
	}

	mfile = fopen(argv[1], open_mode);
	if (mfile == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Cant't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&file_line, &read_bytes, mfile) > -1)
	{
		/* track line_num variable
		 * interpret(file_line) or parse(file_line)
		 * tokenisize line
		 * get first item
		 * match item
		 * call matching func and pass arg
		 * if no match print error ?
		 *
		 * use atoi(), don't worry about overflows
		 */
	}

	free(file_line);
	fclose(mfile);

	return (EXIT_SUCCESS);
}
