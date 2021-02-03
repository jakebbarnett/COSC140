// Lab 0
// Jakeb Barnett
// 1/19/20

#include <iostream>

int countGold(std::string line) {
	int curLineGold = 0;

	for(int i = 0; i < line.length(); i++) {
		int charVal = line[i];
		if(charVal >= 65 && charVal <= 90)
			curLineGold += charVal - 64;
	}

	return curLineGold;
}

int main(int argc, char* argv[]) {
	int totalGold = 0;
	std::string line;

	while (std::cin >> line){
		totalGold += countGold(line);
	}
	
	std::cout << totalGold << std::endl;
}
