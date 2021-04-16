#pragma once
#include <stdio.h>
#include <Windows.h>

#define COUT GetStdHandle(STD_OUTPUT_HANDLE)
#define WHITE 7

extern int background[22][12];
extern int tetromino[7][4][4];

void printBackground();
void printTetromino(int x, int y, int tetrominoIndex);
void clearTetromino(int x, int y, int tetrominoIndex);
void setColor(int color);
void setCursor(int x, int y);
void resetCMD();
int isBlock(int x, int y, int tetrominoIndex);