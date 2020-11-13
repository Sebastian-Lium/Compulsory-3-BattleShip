#pragma once

const int N = 6, M = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
char correctCombination[10];
int numberofShips = 5;
std::vector <std::vector<char>> Field(N, std::vector<char>(M));
std::vector <std::vector<char>> PlayerField(N, std::vector<char>(M));
std::vector <std::vector<char>> EnemyField(N, std::vector<char>(M));
int NumberofShots = 0;
int NumberofHits = 0;
int Shots = 3;
int TotalShots = 3;