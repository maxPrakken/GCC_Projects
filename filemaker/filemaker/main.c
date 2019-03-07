#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#pragma warning(disable : 4996)

int main(int argc, char*argv[]) {
	if (argc < 2) {
		printf("Not enough arguments given: usage %s [name]\n", *argv);
		return -1;
	}

	size_t alen = strlen(argv[1]);
	char * h = malloc(alen + 3);
	char * cpp = malloc(alen + 5);

	if ((h == NULL) || (cpp == NULL)) {
		puts("not enough memory");
		return -1;
	}

	strcpy(h, argv[1]);
	strcpy(h + alen, ".h");
	strcpy(cpp, argv[1]);
	strcpy(cpp + alen, ".cpp");

	FILE * fph = fopen(h, "w");

	if (fph == NULL) {
		printf("cannot open %s\n", h);
		return -1;
	}

	FILE * fpcpp = fopen(cpp, "w");

	if (fpcpp == NULL) {
		printf("cannot open %s\n", cpp);
		return -1;
	}


	free(h);
	free(cpp);

	/* write in files */

	fclose(fph);
	fclose(fpcpp);

	return 0;
}