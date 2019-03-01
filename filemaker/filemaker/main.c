#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#define GetCurrentDir _getcwd
#define FILENAME_MAX

int main(int argc, char*argv[]) {
	if (argc < 2 ) {
		printf("Not enough arguments given: usage [name]");
		return;
	}
	char* path = argv[0];

	for (int i = strlen(argv[0]); i > 0; i--) {
		if (path[i] == '\\') {
			path[i + 1] = '\0';
			break;
		}
		path[i] = 0;
	}

	strcat(path, argv[1]);
	char* path2 = malloc(strlen(path));
	strcpy(path2, path);

	strcat(path, ".cpp");
	strcat(path2, ".h");
	printf(path);
	FILE * fp = fopen(path, "w");
	FILE * fp2 = fopen(path2, "w");

	return;
}