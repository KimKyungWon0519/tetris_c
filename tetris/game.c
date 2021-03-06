#include "game.h"

int background[22][12] = {
   {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
   {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
};

int tetromino[7][4][4] = {
	{
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
		{0, 1, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 14, 0, 0},
		{0, 14, 14, 0},
		{0, 14, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 6, 6, 0},
		{0, 6, 6, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 0, 0},
		{0, 2, 2, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 0, 5, 0},
		{0, 0, 5, 0},
		{0, 5, 5, 0},
	},
	{
		{0, 0, 0, 0},
		{4, 4, 0, 0},
		{0, 4, 4, 0},
		{0, 0, 0, 0},
	},
	{
		{0, 0, 0, 0},
		{0, 11, 11, 0},
		{11, 11, 0, 0},
		{0, 0, 0, 0},
	},
};

void printBackground() {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (background[i][j]) {
				setColor(background[i][j]);
				printf("??");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}

void printTetromino(int x, int y, int tetrominoIndex) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tetromino[tetrominoIndex][i][j]) {
				setColor(tetromino[tetrominoIndex][i][j]);
				setCursor(x + j * 2, i + y);
				printf("??");
			}
		}
	}

	resetCMD();
}

void clearTetromino(int x, int y, int tetrominoIndex) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (tetromino[tetrominoIndex][i][j]) {
				setColor(tetromino[tetrominoIndex][i][j]);
				setCursor(x + j * 2, i + y);
				printf("  ");
			}
		}
	}

	resetCMD();
}

void resetCMD() {
	setColor(WHITE);
	setCursor(0, 22);
}

void setColor(int color) {
	SetConsoleTextAttribute(COUT, color);
}

void setCursor(int x, int y) {
	COORD cur;

	cur.X = x;
	cur.Y = y;

	SetConsoleCursorPosition(COUT, cur);
}

int isBlock(int x, int y, int tetrominoIndex) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (background[i + y][j + x] && tetromino[tetrominoIndex][i][j]) {
				return 1;
			}
		}
	}

	return 0;
}