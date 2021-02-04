// Jakeb Barnett
// Kevin Nguyen
// Nevarious Hampton
//
// Challenge 1
// Checks if Tic Tac Toe is valid

#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char *argv[]){
	// Checks command line arguments
	if(argc != 2){
		printf("Error!  Invalid no. of command line arguments!\n");
		return -1;
	}

	// Initialization
	char* sGridSize = argv[1];
	char cGridSize = sGridSize[0];
	unsigned int gridSize = cGridSize - 48; // Convert ASCII to int
	
	// Testing input
	std::string line;
	
	while(std::getline(std::cin, line)){
		if((line.length() / 2 + 1) > gridSize){
			printf("Too many cells for a %d x %d board\n", gridSize, gridSize);
			return -1;
		}else if((line.length() / 2 + 1) < gridSize){
			printf("Too few cells for a %d x %d board\n", gridSize, gridSize);
			return -1;
		}
	}

	printf("Valid board\n");
}
