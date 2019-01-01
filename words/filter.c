#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 1000

int main(int argc, char *argv[])
{
	FILE *in;
	FILE *out;
	char *word = malloc(sizeof(char) * WORD_SIZE);
	
	if (argc != 2)
	{
		printf("You must specify a file to filter.\n");
		exit(-1);
	}
	
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		printf("Could not find the specified file.\n");
		exit(-1);
	}

	out = fopen("output.txt", "w");
	while (fgets(word, WORD_SIZE, in) != NULL)
	{
		if (strlen(word) == 5)
			fprintf(out, "%s", word);
	}

	fclose(out);
	fclose(in);
	printf("Output written to output.txt\n");
	return 0;
}