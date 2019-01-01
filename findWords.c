#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char noel[6];
	FILE *noelList;
	FILE *dictionaryFile;
	char *dictionary;
	unsigned int size;
	FILE *out;
	
	if (argc != 2)
	{
		printf("You must specifiy a dictionary to compare to.\n");
		exit(-1);
	}

	if ((noelList = fopen("all-noel-combos.txt", "r")) == NULL)
	{
		printf("Error: could not open all-noel-combos.txt.\n");
		exit(-1);
	}
	
	if ((dictionaryFile = fopen(argv[1], "r")) == NULL)
	{
		printf("Error: could not open the specified dictionary.\n");
		exit(-1);
	}

	fseek(dictionaryFile, 0, SEEK_END);
	size = ftell(dictionaryFile);
	dictionary = malloc(sizeof(char) * size);
	fseek(dictionaryFile, 0, SEEK_SET);
	fread(dictionary, 1, size, dictionaryFile);
	fclose(dictionaryFile);
	
	out = fopen("matches.txt", "w");
	while (fgets(noel, 6, noelList) != NULL)
	{
		if (strstr(dictionary, noel) != NULL)
			fprintf(out, "%s", noel);
	}

	free(dictionary);
	fclose(out);
	fclose(noelList);
	printf("Output written to matches.txt");
	return 0;
}