#include <iostream>
#include <stdio.h>
#include <string>

int main(){
	// Get grid size
	int gridSize;
	std::cin >> gridSize;

	// Initialization
	char** board = new char*[gridSize];
	for(int i = 0; i < gridSize; i++){
		board[i] = new char[gridSize];
	}
	
	// Populating board array
	std::string line;
	std::getline(std::cin, line); // First line has been read already
	for(int i = 0; i < gridSize; i++){;
		std::getline(std::cin, line);
		for(int j = 0; j < gridSize; j++){
			int spaceExp = j * 2;
			board[i][j] = line[spaceExp];
		}
	}

	char winner = '-';
	
	// Checking vertical columns
	for(int i = 0; i < gridSize; i++){
		char player = board[0][i];
		bool hasStreak = true;
		for(int j = 0; j < gridSize; j++){
			if(player != board[j][i]){
				hasStreak = false;
			}
		}
		if(hasStreak){
			winner = player;
		}
	}

	// Checking horizontal columns
	for(int i = 0; i < gridSize; i++){
		char player = board[i][0];
		bool hasStreak = true;
		for(int j = 0; j < gridSize; j++){
			if(player != board[i][j]){
				hasStreak = false;
			}
		}
		if(hasStreak){
			winner = player;
		}
	}

	// Checking diagonals
	char playerTop = board[0][0];
	char playerBottom = board[gridSize - 1][0];
	bool topStreak = true;
	bool bottomStreak = true;
	for(int i = 1; i < gridSize; i++){
		if(board[i][i] != playerTop){
			topStreak = false;
		}

		if(board[gridSize - 1 - i][i] != playerBottom){
			bottomStreak = false;
		}
	}
	if(topStreak){
		winner = playerTop;
	}else if(bottomStreak){
		winner = playerBottom;
	}

	// Prints final result
	if(winner != '-'){
		printf("%c wins\n", winner);
	}else{
		printf("Tie\n");
	}
}
