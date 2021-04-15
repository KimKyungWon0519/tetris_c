#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() {
	int y = 0;
	int random = 0;

	printBackground();

	while (1) {
		printTetromino(8, 1 + y++, 6);

		Sleep(1000);
	}
}