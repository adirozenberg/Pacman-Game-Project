#ifndef UTILLS_H
#define UTILLS_H

#include "Position.h"

#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

void gotoxy(int x, int y);
void hideCursor();
void clearScreen();
void setTextColor(Color colorToSet);



#endif

