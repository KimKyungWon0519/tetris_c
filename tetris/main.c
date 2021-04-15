#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() {
	int x = 0;
	int random = 0;

	while (1) {
		if (x == 0) {
			random = rand() % 7;
		}
		
		printTetromino(4, 1 + x++, random);
		
		if (x == 18) {
			x = 0;
		}
		Sleep(50);
	}
}