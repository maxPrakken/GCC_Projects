#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	if (argc < 1) { // checks if amount of arguments is enough
		printf("No argument given: usage %s [path]\n", *argv);
		return -1;
	}

	FILE* F;
	char *filePath = (char*)argv[1];

	if (F = fopen(filePath, "r")) {
		fclose(F);
		F = fopen(filePath, "w");
		fclose(F);
		int status = remove(filePath);

		if (status == 0) {
			printf("\nFile destroyed and removed succesfully \n");
		}
		else {
			printf("\nRemoval failed.\n");
			perror("Following error occurred\n");
		}
	}
	else {
		printf("\nPath is not valid or file doens't exist\n");
	}

	
	return 1;
}

