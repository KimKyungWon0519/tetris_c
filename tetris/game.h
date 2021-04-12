#pragma once
#include <stdio.h>
#include <Windows.h>

#define COUT GetStdHandle(STD_OUTPUT_HANDLE)

extern int background[22][12];

void printBackground();