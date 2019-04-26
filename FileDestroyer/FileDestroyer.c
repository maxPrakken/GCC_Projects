#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
	if (argc < 1) { // checks if amount of arguments is enough
		printf("No argument given: usage %s [path]\n", *argv);
		return -1; // exits the program if criteria are met
	}

	FILE* F; // new file instance
	char *filePath = (char*)argv[1]; // filepath

	if (F = fopen(filePath, "r")) { // check if the file exists and open it in the process
		fclose(F); // close the file so it can be reopened
		F = fopen(filePath, "w"); // open the file with the write parameter so it gets whiped in the process
		fclose(F); // close the file again
		int status = remove(filePath); // remove the file from the drive

		if (status == 0) { // check if removal was succesfull
			printf("\nFile destroyed and removed succesfully \n");
		}
		else { // if removal was unsuccesfull 
			printf("\nRemoval failed.\n");
			perror("Following error occurred\n");
		}
	}
	else { // if the file doens't exists
		printf("\nPath is not valid or file doens't exist\n");
	}
	
	return 1; // end program
}

