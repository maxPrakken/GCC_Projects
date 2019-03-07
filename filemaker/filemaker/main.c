#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#pragma warning(disable : 4996) // makes sure you dont get warning about "outdated" functions like fopen isntead of fopen_s (only if you're gonna compile for yourself)

int main(int argc, char*argv[]) {
	if (argc < 2) { // checks if amount of arguments is enough
		printf("Not enough arguments given: usage %s [name]\n", *argv);
		return -1;
	}

	size_t alen = strlen(argv[1]); // gets appropriate lenght of char*
	char * h = malloc(alen + 3); // reserves space on memory for char* h
	char * cpp = malloc(alen + 5); // reserves space on memory for char* cpp

	if ((h == NULL) || (cpp == NULL)) { // checks if h or cpp are not null
		puts("not enough memory");
		return -1;
	}

	strcpy(h, argv[1]); // copies name argument into h
	strcpy(h + alen, ".h"); // adds .h to the end of h
	strcpy(cpp, argv[1]); // copies name argument into cpp
	strcpy(cpp + alen, ".cpp"); // add .cpp to the end of cpp

	FILE * fph = fopen(h, "w"); // makes file with name h with write permissions

	if (fph == NULL) { // checks if file openend is not null
		printf("cannot open %s\n", h);
		return -1;
	}

	FILE * fpcpp = fopen(cpp, "w"); // makes file with name cpp with write permissions

	if (fpcpp == NULL) { // checks if file openend is not null
		printf("cannot open %s\n", cpp);
		return -1;
	}


	free(h); // free space on memory of location h
	free(cpp); // free space on memory of location cpp

	// ==================================================================
	// makes default .h file
	// ==================================================================
	fprintf(fph, "#pragma once\n\n#include <iostream>\n\nclass %"); // sets default includes and pragma once
	fprintf(fph, argv[1]); // class name
	fprintf(fph, " \{ %\n"); // opening bracket for class
	fprintf(fph, "public: %\n"); // public variable declaration
	fprintf(fph, "	//default constructor %\n"); //comment
	fprintf(fph, "	"); // spaces for indentation
	fprintf(fph, argv[1], "%\n"); // constructor declaration
	fprintf(fph, "(); %\n"); // brackets for constructor
	fprintf(fph, "	//default deconstructor %\n"); // comment
	fprintf(fph, "	virtual \~%"); //virtual declaration for deconstructor
	fprintf(fph, argv[1], "%\n"); // deconstructor name
	fprintf(fph, "(); %\n\n"); //brackets for deconstructor
	fprintf(fph, "private: %\n\n"); // private variables declaration
	fprintf(fph, "\}; %"); // closing bracket for class
	// ==================================================================
	// makes default .cpp file for .h file
	// ==================================================================
	fprintf(fpcpp, "#include \"%"); // include call
	fprintf(fpcpp, argv[1], "%\n"); // include name
	fprintf(fpcpp, ".h\" %\n\n"); // get include name extention
	fprintf(fpcpp, argv[1], "%"); // .h class name
	fprintf(fpcpp, "::%"); // double double dots
	fprintf(fpcpp, argv[1], "%"); // constructor
	fprintf(fpcpp, "() \{ \n\n\} % \n\n"); // brackets for constructor
	fprintf(fpcpp, argv[1], "%"); // .h class name
	fprintf(fpcpp, "::%"); // double double dots
	fprintf(fpcpp, "~%");
	fprintf(fpcpp, argv[1], "%"); // deconstructor
	fprintf(fpcpp, "() \{ \n\n\} % \n\n"); // brackets for deconstructor
	// ==================================================================

	fclose(fph); // close file fph
	fclose(fpcpp); //close file fpcpp

	return 0; // end of program
}