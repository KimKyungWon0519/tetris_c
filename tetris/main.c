#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() {
	int y = 1;
	int random = 0;

	printBackground();

	while (1) {
		if (y == 1) {
			random = rand() % 9;
		} 

		clearTetromino(8, 1 + y - 1, random);
		printTetromino(8, 1 + y, random);

		y++;

		if (y == 18) {
			y = 1;
		}

		Sleep(50);
	}
}