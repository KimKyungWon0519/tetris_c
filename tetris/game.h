#pragma once
#include <stdio.h>
#include <Windows.h>

#define COUT GetStdHandle(STD_OUTPUT_HANDLE)

extern int background[22][12];
extern int tetromino[7][4][4];

void printBackground();
void printTetromino(int x, int y, int tetrominoIndex);
void setColor(int color);