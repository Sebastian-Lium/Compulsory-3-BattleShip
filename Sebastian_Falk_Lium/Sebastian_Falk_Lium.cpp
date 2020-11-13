#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "Variables.h"
#include <string>

void Menu();
void Login();
void Printlock(char lock[4][4]);
void Readfromfile();
void PasswordChange();
void PlayBattleship();
int letterToNumber(char letter);
void Shoot();

void Login() {
	char lock[4][4];
	int failCounter = 0;	
	Readfromfile();
	do {
		int currentX = 0;
		int currentY = 0;
		int correct = 0;
		int counter = 0;
		char combination[10]{ 'A', '-', '-', '-', '-', '-', '-' , '-' , '-' , '-'};

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				lock[i][j] = i * 4 + j + 65;
			}
			
		}
		lock[currentY][currentX] = '*';

		system("cls");
		std::cout << "Move with WASD, you have three attempts\n";

		Printlock(lock);
		std::cout << "\n    [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";
		do {
			char input = _getch();
			system("cls");

			lock[currentY][currentX] = currentY * 4 + currentX + 65;
			if (toupper(input) == 'S' && currentY != 3) {
				currentY += 1;
			}
			else if (toupper(input) == 'W' && currentY != 0) {
				currentY -= 1;
			}
			else if (toupper(input) == 'A' && currentX != 0) {
				currentX -= 1;
			}
			else if (toupper(input) == 'D' && currentX != 3) {
				currentX += 1;
			}

			counter++;
			combination[counter] = lock[currentY][currentX];
			lock[currentY][currentX] = '*';
			Printlock(lock);

			std::cout << "\n    [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";
		} while (counter < 9);

		for (int i = 0; i < 10; i++) {
			if (combination[i] == correctCombination[i]) {
				correct++;
			}
		}
		if (correct == 10) {
			Menu();
			failCounter = 3;
		}
		else {
			failCounter++;
		}
	} while (failCounter < 3);
}
void Printlock(char lock[4][4]) {

	std::cout << "\n\t      ";
	for (int i{ 0 }; i < 4; i++) {
		for (int j{ 0 }; j < 4; j++) {

			std::cout << lock[i][j] << ' ';

			if (j == 3 && i != 3) {
				std::cout << "\n\t      ";
			}
		}
	}
}
void PasswordChange() {
		std::fstream File("Password.txt", std::ios::out);
		char lock[4][4];
		int currentX = 0;
		int currentY = 0;
		int counter = 0;
		char combination[10]{ 'A', '-', '-', '-', '-', '-', '-' , '-' , '-' , '-' };

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				lock[i][j] = i * 4 + j + 65;
			}

		}
		lock[currentY][currentX] = '*';

		system("cls");
		std::cout << "Move with WASD, you have three attempts\n";

		Printlock(lock);
		std::cout << "\n    [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";
		std::cout << "\n\This combination will become the new Password\n";
		do {
			char input = _getch();
			system("cls");

			lock[currentY][currentX] = currentY * 4 + currentX + 65;
			if (toupper(input) == 'S' && currentY != 3) {
				currentY += 1;
			}
			else if (toupper(input) == 'W' && currentY != 0) {
				currentY -= 1;
			}
			else if (toupper(input) == 'A' && currentX != 0) {
				currentX -= 1;
			}
			else if (toupper(input) == 'D' && currentX != 3) {
				currentX += 1;
			}


			counter++;
			combination[counter] = lock[currentY][currentX];
			lock[currentY][currentX] = '*';
			Printlock(lock);
			std::cout << "\n    [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";
			std::cout << "\n\This combination will become the new Password\n";
		} while (counter < 9);

		for (int i = 0; i < 10; i++) {
			File << combination[i];

		}
		File.close();
}
void Readfromfile() {
	std::fstream File("Password.txt", std::ios::in);
	if (File.is_open()) {
	//perror("Text Exists");
		while (!File.eof()) {
			for (int i = 0; i < 10; i++) {
				File >> correctCombination[i];
			}
		}
	}
	else {
		perror("Password.txt");
	}
	File.close();
}
void Menu() {
	fflush(stdin);
	bool Quit = false;
	system("cls");	

	do {
	std::cout << "-----------------------" << std::endl;
	std::cout << "Welcome to the Main Menu" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "What would you like to do?\n\n" << std::endl;
	std::cout << "1.Change the password" << std::endl;
	std::cout << "2.Play Battleship" << std::endl;
	std::cout << "3.Quit" << std::endl;	

		switch (_getch()) {
		case '1':
			PasswordChange();
			system("cls");
			break;
		case '2':
			PlayBattleship();
			system("cls");
			break;
		case '3':
			Quit = true;
			break;
		default:
			system("cls");
			std::cout << "Invalid input, choose something else\n" << std::endl;
			break;
		}
	} while (!Quit);
}
void Shoot() {
	std::string Bang = "";
	int X = 0;
	int Y = 0;

	std::cout << "You have " << Shots << " shots remaining\n" << "Shots fired: " << NumberofShots << "\tHits: " << NumberofHits << "\n";
	std::cout << "Where do you want to shoot?  (Example:C3)";
	std::cin >> Bang;

	for (int i = 0; i < Bang.length(); i++){
		if (i == 0) {
			X = letterToNumber(toupper(Bang[i]));
		}
		else {
			Y = Bang[i] - 49;
		}
	}
	if (EnemyField[Y][X] == SHIP) {
		PlayerField[Y][X] = HIT;
		NumberofHits++;
		NumberofShots++;
	}
	else {
		PlayerField[Y][X] = MISS;
		NumberofShots++;
	}
	Shots--;
}
int letterToNumber(char letter) // only big letters
{
	return static_cast<int>(letter) - 65;
}

void PlayBattleship() {
	bool GameOver = false;
	bool Xdirection = 1;
	bool Ydirection = 0;
	int Shipsize = 5;
	int RanX = 0;
	int RanY = 0;
	int number = 1;
	char letter = 65;
	int Clear = 0;
	int Test = 0;
	NumberofHits = 0;

	//-----------------------------Making the board-----------------------------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Field[i][j] = BLANK;
			PlayerField[i][j] = BLANK;
			EnemyField[i][j] = BLANK;
		}
	}
	
	//-----------Placing ships-----------
	for (int i = 0; i < numberofShips * 2; i++) {
		do {		
			Clear = 0;
				do {
					Xdirection = rand() % 2;
					Ydirection = !Xdirection;

					RanX = rand() % (M - (Shipsize)*Xdirection);
					RanY = rand() % (N - (Shipsize)*Ydirection);

					//Checks that the ship will be inside the grid
				} while (Field[RanY][RanX] != BLANK && (RanX < 0 || RanY < 0) && (RanX > M || RanY > N));
			if (i < numberofShips) {
				if (Xdirection) {// Checks if there would be any horizontal overlapping for the ship placement
					for (int j = 0; j < Shipsize; j++) {
						if (Field[RanY][RanX] != SHIP) {
							Clear++;
						}
						RanX++;
					}
				}
				else {// Checks if there would be any vertical overlapping for the ship placement
					for (int j = 0; j < Shipsize; j++) {
						if (Field[RanY][RanX] != SHIP) {
							Clear++;
						}
						RanY++;
					}
				}
			}
			else {
				if (Xdirection) {// Checks if there would be any horizontal overlapping for the ship placement  |  For the AI
					for (int j = 0; j < Shipsize; j++) {
						if (EnemyField[RanY][RanX] != SHIP) {
							Clear++;
						}
						RanX++;
					}
				}
				else {// Checks if there would be any vertical overlapping for the ship placement  |  For the AI
					for (int j = 0; j < Shipsize; j++) {
						if (EnemyField[RanY][RanX] != SHIP) {
							Clear++;
						}
						RanY++;
					}
				}
			}
		} while (Clear != Shipsize);
		if(i < numberofShips){
			if (Xdirection) {// Places the ships in the field horizontally 
				for (int j = 0; j < Shipsize; j++) {
					Field[RanY][RanX] = SHIP;
					RanX--;
				}
			}
			else {// Places the ships in the field vertically 
				for (int j = 0; j < Shipsize; j++) {
					Field[RanY][RanX] = SHIP;
					RanY--;
				}
			}
		}
		else{
			if (Xdirection) {// Places the ships in the field horizontally   |   For the AI
				for (int j = 0; j < Shipsize; j++) {
					EnemyField[RanY][RanX] = SHIP;
					RanX--;
				}
			}
			else {// Places the ships in the field vertically   |   For the AI
				for (int j = 0; j < Shipsize; j++) {
					EnemyField[RanY][RanX] = SHIP;
					RanY--;
				}
			}
		}
		if (i == 2) {
			Shipsize++;
		}
		Shipsize--;
		if (Shipsize == 1) {
			Shipsize = 5;
		}
	}
	//-----------------------------Making the board-----------------------------
		//-----------Placing ships-----------



	do {//-----------------------------------Game Loop-----------------------------------
		for (int k = 0; k < TotalShots; k++) {

			if (Shots == 0) {//---------------------------------AI Start---------------------------------
				int AIX = 0;
				int AIY = 0;
				for (int i = 0; i < TotalShots; i++) {
					do {
						AIX = rand() % N;
						AIY = rand() % M;
					} while (Field[AIY][AIX] == HIT || Field[AIY][AIX] == MISS);
					if (Field[AIY][AIX] == SHIP) {
						Field[AIY][AIX] = HIT;
					}
					else {
						Field[AIY][AIX] = MISS;
					}

				}
				Shots = TotalShots;
			}

			system("cls");	
			number = 1;
			for (int i = 0; i < N; i++) {
				std::cout << " " << number << "   ";
				for (int j = 0; j < M; j++) {
					std::cout << "|" << PlayerField[i][j];
				}
				std::cout << "|\n";
				++number;
			}
			std::cout << "\n     ";
			//---------Printing Board---------

			//---------Printing letters---------
			letter = 65;
			for (int i = 0; i < M; i++) {
				std::cout << " " << letter;
				letter++;
			}
			//---------Printing letters---------
			number = 1;
			std::cout << "\n\n";
			for (int i = 0; i < N; i++) {
				std::cout << " " << number << "   ";
				for (int j = 0; j < M; j++) {
					std::cout << "|" << Field[i][j];
				}
				std::cout << "|\n";
				++number;
			}
			std::cout << "\n     ";

			Shoot();
		
			if (NumberofHits == 15) {
				GameOver = true;
				k = 3;
				std::cout << "Congratulations you have shot all the enemy ships!\n";
			}
			if (NumberofShots == 35) {
				GameOver = true;
				k = 3;
				std::cout << "You have run out of shots before you could sink the enemy ships, better luck next time\n";
			}
		}
	} while (!GameOver);

	system("pause");
}


int main()
{
	srand(time(NULL));
	Login();
}