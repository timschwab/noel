#include <stdio.h>
#include <stdlib.h>

char N(int i)
{
	switch (i)
	{
		case 0:
			return 'n';
		case 1:
			return 'i';
		case 2:
			return 'z';
		case 3:
			return 's';
		default:
			printf("Error: index overflow in N().\n");
			exit(-1);
	}
}

char O(int i)
{
	switch (i)
	{
		case 0:
			return 'o';
		case 1:
			return 'i';
		default:
			printf("Error: index overflow in O().\n");
			exit(-1);
	}
}

char E(int i)
{
	switch (i)
	{
		case 0:
			return 'e';
		case 1:
			return 'i';
		case 2:
			return 'w';
		case 3:
			return 'm';
		default:
			printf("Error: index overflow in E().\n");
			exit(-1);
	}
}

char L(int i)
{
	switch (i)
	{
		case 0:
			return 'l';
		case 1:
			return 'i';
		case 2:
			return 'c';
		case 3:
			return 'v';
		case 4:
			return 'j';
		default:
			printf("Error: index overflow in L().\n");
			exit(-1);
	}
}

void cycle(FILE *f, char n, char o, char e, char l)
{
	fprintf(f, "%c%c%c%c\n", n, o, e, l);
	fprintf(f, "%c%c%c%c\n", n, o, l, e);
	fprintf(f, "%c%c%c%c\n", n, e, o, l);
	fprintf(f, "%c%c%c%c\n", n, e, l, o);
	fprintf(f, "%c%c%c%c\n", n, l, o, e);
	fprintf(f, "%c%c%c%c\n", n, l, e, o);
	fprintf(f, "%c%c%c%c\n", o, n, e, l);
	fprintf(f, "%c%c%c%c\n", o, n, l, e);
	fprintf(f, "%c%c%c%c\n", o, e, n, l);
	fprintf(f, "%c%c%c%c\n", o, e, l, n);
	fprintf(f, "%c%c%c%c\n", o, l, n, e);
	fprintf(f, "%c%c%c%c\n", o, l, e, n);
	fprintf(f, "%c%c%c%c\n", e, n, o, l);
	fprintf(f, "%c%c%c%c\n", e, n, l, o);
	fprintf(f, "%c%c%c%c\n", e, o, n, l);
	fprintf(f, "%c%c%c%c\n", e, o, l, n);
	fprintf(f, "%c%c%c%c\n", e, l, n, o);
	fprintf(f, "%c%c%c%c\n", e, l, o, n);
	fprintf(f, "%c%c%c%c\n", l, n, o, e);
	fprintf(f, "%c%c%c%c\n", l, n, e, o);
	fprintf(f, "%c%c%c%c\n", l, o, n, e);
	fprintf(f, "%c%c%c%c\n", l, o, e, n);
	fprintf(f, "%c%c%c%c\n", l, e, n, o);
	fprintf(f, "%c%c%c%c\n", l, e, o, n);
}

int main(int argc, char *argv[])
{
	int nI, oI, eI, lI;
	FILE *f = fopen("all-noel-combos.txt", "w");

	for (nI = 0 ; nI < 4 ; nI++)
		for (oI = 0 ; oI < 2 ; oI++)
			for (eI = 0 ; eI < 4 ; eI++)
				for (lI = 0 ; lI < 5 ; lI++)
					cycle(f, N(nI), O(oI), E(eI), L(lI));

	printf("Output written to all-noel-combos.txt.\n");
	fclose (f);
	return 0;
}