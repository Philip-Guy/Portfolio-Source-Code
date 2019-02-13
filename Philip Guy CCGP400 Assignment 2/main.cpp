/*
	Philip Guy
	Programming Fundamentals (CGP400) Assignment 2
	09/01/2015
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <algorithm>
using namespace std;

int GemNumber;
int turn = 0;
const int ROWS = 8;
const int COLUMNS = 8;
int MyGameArray[ROWS][COLUMNS];
int Score = 0;
int HighScore;
int HighScore1;
int HighScore2;
int HighScore3;
int HighScore4;
int HighScore5;
int HighScore6;
int HighScore7;
int HighScore8;
int HighScore9;

void DisplayMenu(void);
void SelectOption(void);
void DisplayInstructions(void);
double CreateGame(int MyGameArray[COLUMNS][ROWS]);
void PlayGame(void);
void DisplayHighScores(void);
void Exit(void);
void SetColour(int value);
void DisplayGame(void);
void UpdateGame(void);
void QuitGame(void);
void GameOver(void);

int main()
{
	srand(unsigned int(0)); //Seed value for random number generation
	DisplayMenu();

	_getch();
	return 0;
}

void DisplayMenu()
{
	system("cls");

	printf("			Philip Guy - CGP400 - Assignment 2\n");
	printf("Dejewelled!\n\n");
	printf("Menu\n\n");
	printf("1. Instructions\n\n");
	printf("2. Play Game\n\n");
	printf("3. HighScores\n\n");
	printf("4. Exit\n\n\n");

	SelectOption();
}

void SelectOption() //Function where the user inputs where they would like to go from the menu
{
	enum eMenu	{ //enumeration for each variable option in the menu
		eInstructions = 1,
		ePlayGame,
		eHighScores,
		eExit	};
	int menu;

	printf("Please select an option from 1-3.\n");
	scanf_s("%d", &menu);

	switch (menu)
	{
	case eInstructions:
		DisplayInstructions();
		break;

	case ePlayGame:
		CreateGame(MyGameArray);
		break;

	case eHighScores:
		DisplayHighScores();
		break;

	case eExit:
		Exit();
		break;

	default:
		printf("Wrong number. Please try again!\n");
		DisplayMenu();
		break;
	}
}

void DisplayInstructions()
{
	system("cls");

	printf("Welcome to dejewelled!\n");
	printf("The game consists of Jewels arranged in a 8x8 grid formation.\n");
	printf("The player must select the location of a crystal, and then select\n");
	printf("an adjacent crystal, this will then swap the two crystal locations.\n");
	printf("In this game the crystals will swap regardless of whether they create\n");
	printf("a string, however you can only swap crystals ADJACENT to each other!\n\n");

	printf("The Basics:\n");
	printf("To create a string of crystals you must match 3 or more crystals horizontally\n");
	printf("or vertically to destroy them to earn points. Now the grid if topped up with new\n");
	printf("crystals to fill in the gaps with non-strings, this is a cascade.\n");
	printf("The cascade will continue until no more strings are created.\n\n");

	printf("The Game:\n");
	printf("Upon entering the game you will see the 8x8 grid\n");
	printf("Surrounding the grid is the X and Y co-ordinates of");
	printf("each spot, it is shown as so:\n");
	printf("(X co-ords) 0   1   2   3  etc.\n");
	printf("(Y co-ords) 1\n");
	printf("	    2\n");
	printf("	    3\n");
	printf("	    etc\n\n");

	printf("You will then be asked whether you would like to quit.\n");
	printf("To do so you must enter '8' on the keyboard.\n");
	printf("Otherwise enter any number to continue.\n");
	printf("Now you are prompted to enter the X and Y co-ordinate\n");
	printf("of the first crystal you would like to select.\n");
	printf("Then you will be asked to enter the X and Y co-ordinate\n");
	printf("of the crystal that you would like to swap positions with.\n");

	printf("You continue to play for 20 turns, and must try to get the highest\n");
	printf("score you can. Have fun!\n\n");

	printf("Press any number to return to the menu.\n");

	_getch(); //This prevents crashing that exists with scanf_s("%d") as regardless of what key is pressed, it will not crash.
	DisplayMenu();
}

double CreateGame(int MyGameArray[ROWS][COLUMNS])
{
	enum eGem	{ //enumeration for each colour variable
		eRed = 0,
		eGreen,
		eYellow,
		eBlue,
		eWhite,
		ePurple	};

	system("cls");
	printf("Play Game!\n\n");

	printf("	0	1	2	3	4	5	6	7"); //X-Axis label
	for (int x = 0; x < ROWS; x++)
	{
		SetColour(15);
		printf("\n\n\n%d", x); //Y-Axis label
		for (int y = 0; y < COLUMNS; y++)
		{
			printf("	");
			GemNumber = rand() % 6; //Generates random number from 0-5

			switch (GemNumber)
			{
			case eRed:
				GemNumber = 0;
				SetColour(4); //Calls SetColour function and changes the colour of the ASCII character created
				MyGameArray[x][y] = 'A' + 154;
				break;

			case eGreen:
				GemNumber = 1;
				SetColour(10);
				MyGameArray[x][y] = 'A' + 102;
				break;

			case eYellow:
				GemNumber = 2;
				SetColour(14);
				MyGameArray[x][y] = 'A' + 189;
				break;

			case eBlue:
				GemNumber = 3;
				SetColour(1);
				MyGameArray[x][y] = 'A' + 110;
				break;

			case eWhite:
				GemNumber = 4;
				SetColour(15);
				MyGameArray[x][y] = 'A' + 151;
				break;

			case ePurple:
				GemNumber = 5;
				SetColour(5);
				MyGameArray[x][y] = 'A' + 180;
				break;
			}
			printf("%c", MyGameArray[x][y]); //Prints the current element of the array before incrementing
		}
	}
	printf("\n");

	PlayGame();
	return 0;
}

void PlayGame()
{
	int FirstMoveX;
	int FirstMoveY;
	int SecondMoveX;
	int SecondMoveY;
	int Quit;
	bool ValidSwap = true;

	do
	{
		turn++; //Increments the turn counter
		SetColour(15);
		printf("\n\n								Quit = '8'\n", turn);
		scanf_s("%d", &Quit);

		if (Quit == 8) //Allows the user to quit from the game
		{
			QuitGame();
		}

		printf("\nMove X : ");
		scanf_s("%d", &FirstMoveX);
		printf("\nMove Y : ", &FirstMoveY);
		scanf_s("%d", &FirstMoveY);
		printf("\nTo X: ");
		scanf_s("%d", &SecondMoveX);
		printf("\nTo Y: ");
		scanf_s("%d", &SecondMoveY);

		//This means that the two crystals must be adjacent (diagonally is allowed) to be swapped
		if ((FirstMoveX - SecondMoveX >= -1 && FirstMoveX - SecondMoveX <= 1) && (FirstMoveY - SecondMoveY >= -1 && FirstMoveY - SecondMoveY <= 1))
		{
			swap(MyGameArray[FirstMoveY][FirstMoveX], MyGameArray[SecondMoveY][SecondMoveX]);
			system("cls");

			UpdateGame();
		}
		else
		{
			ValidSwap = false;
		}

	} while (ValidSwap == true);

	if (ValidSwap == false) //Invalid swaps WILL use a turn
	{
		printf("Invalid swap. Press any key to try again.\n");
		_getch();
		DisplayGame();
	}
}

void DisplayHighScores()
{
	system("cls");
	printf("Dejewelled HighScores!\n\n");

	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", HighScore, HighScore1, HighScore2, HighScore3, HighScore4, HighScore5, HighScore6, HighScore7, HighScore8, HighScore9);
	printf("Press any key to return to the menu.\n");
	_getch();
	DisplayMenu();
}
void Exit()
{
	exit(0);
}

void SetColour(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void DisplayGame()
{
	system("cls");

	SetColour(15); //Prevents any text being any colour other than white from the array - this was a brief issue
	printf("\n Turn: %d of 20						Score: %d\n\n", turn, Score);
	printf("	0	1	2	3	4	5	6	7");
	for (int x = 0; x < ROWS; x++)
	{
		SetColour(15);
		printf("\n\n\n%d", x);

		for (int y = 0; y < COLUMNS; y++)
		{
			printf("	");

			if (MyGameArray[x][y] == 'A' + 154)
			{
				SetColour(4);
			}
			if (MyGameArray[x][y] == 'A' + 102)
			{
				SetColour(10);
			}
			if (MyGameArray[x][y] == 'A' + 189)
			{
				SetColour(14);
			}
			if (MyGameArray[x][y] == 'A' + 110)
			{
				SetColour(1);
			}
			if (MyGameArray[x][y] == 'A' + 151)
			{
				SetColour(15);
			}
			if (MyGameArray[x][y] == 'A' + 180)
			{
				SetColour(5);
			}
			printf("%c", MyGameArray[x][y]);
		}
	}
	PlayGame();
}

void UpdateGame()
{
	enum eGem	{
		eRed = 0,
		eGreen,
		eYellow,
		eBlue,
		eWhite,
		ePurple
	};
	//Score values for each string
	int TriCrystal = 50;
	int QuadCrystal = 100;
	int PentaCrystal = 500;
	int HexaCrystal = 2500;

	for (int x = 0; x < 8; x++) //Loops through the column 0-8
	{
		for (int y = 0; y < 8; y++) //Loops through the row (0-8)
		{
			//if statements for how long the string is, decreasing from 6 in a row to 3 and deleting accordingly
			//this checks for strings along a row
			if (MyGameArray[x][y] == MyGameArray[x][y + 1] && MyGameArray[x][y] == MyGameArray[x][y + 2] && MyGameArray[x][y] == MyGameArray[x][y + 3] && MyGameArray[x][y] == MyGameArray[x][y + 4] && MyGameArray[x][y] == MyGameArray[x][y + 5])
			{
				MyGameArray[x][y] = ' '; //Essentially 'deletes' the crystal, replacing it with whitespace
				MyGameArray[x][y + 1] = ' ';
				MyGameArray[x][y + 2] = ' ';
				MyGameArray[x][y + 3] = ' ';
				MyGameArray[x][y + 4] = ' ';
				MyGameArray[x][y + 5] = ' ';

				Score = Score + HexaCrystal; //Updates the score
			}

			if (MyGameArray[x][y] == MyGameArray[x][y + 1] && MyGameArray[x][y] == MyGameArray[x][y + 2] && MyGameArray[x][y] == MyGameArray[x][y + 3] && MyGameArray[x][y] == MyGameArray[x][y + 4])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x][y + 1] = ' ';
				MyGameArray[x][y + 2] = ' ';
				MyGameArray[x][y + 3] = ' ';
				MyGameArray[x][y + 4] = ' ';

				Score = Score + PentaCrystal;
			}

			if (MyGameArray[x][y] == MyGameArray[x][y + 1] && MyGameArray[x][y] == MyGameArray[x][y + 2] && MyGameArray[x][y] == MyGameArray[x][y + 3])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x][y + 1] = ' ';
				MyGameArray[x][y + 2] = ' ';
				MyGameArray[x][y + 3] = ' ';

				Score = Score + QuadCrystal;
			}

			if (MyGameArray[x][y] == MyGameArray[x][y + 1] && MyGameArray[x][y] == MyGameArray[x][y + 2])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x][y + 1] = ' ';
				MyGameArray[x][y + 2] = ' ';

				Score = Score + TriCrystal;
			}
		}
	}

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			//the second if statement, this checks for vertical strings along the columns
			if (MyGameArray[x][y] == MyGameArray[x + 1][y] && MyGameArray[x][y] == MyGameArray[x + 2][y] && MyGameArray[x][y] == MyGameArray[x + 3][y] && MyGameArray[x][y] == MyGameArray[x + 4][y] && MyGameArray[x][y] == MyGameArray[x + 5][y])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x + 1][y] = ' ';
				MyGameArray[x + 2][y] = ' ';
				MyGameArray[x + 3][y] = ' ';
				MyGameArray[x + 4][y] = ' ';
				MyGameArray[x + 5][y] = ' ';

				Score = Score + HexaCrystal;
			}

			if (MyGameArray[x][y] == MyGameArray[x + 1][y] && MyGameArray[x][y] == MyGameArray[x + 2][y] && MyGameArray[x][y] == MyGameArray[x + 3][y] && MyGameArray[x][y] == MyGameArray[x + 4][y])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x + 1][y] = ' ';
				MyGameArray[x + 2][y] = ' ';
				MyGameArray[x + 3][y] = ' ';
				MyGameArray[x + 4][y] = ' ';

				Score = Score + PentaCrystal;
			}

			if (MyGameArray[x][y] == MyGameArray[x + 1][y] && MyGameArray[x][y] == MyGameArray[x + 2][y] && MyGameArray[x][y] == MyGameArray[x + 3][y])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x + 1][y] = ' ';
				MyGameArray[x + 2][y] = ' ';
				MyGameArray[x + 3][y] = ' ';

				Score = Score + QuadCrystal;
			}

			if (MyGameArray[x][y] == MyGameArray[x + 1][y] && MyGameArray[x][y] == MyGameArray[x + 2][y])
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x + 1][y] = ' ';
				MyGameArray[x + 2][y] = ' ';

				Score = Score + TriCrystal;
			}
		}
	}

	/*for (int x = 0; x < 8; x++) // remove dups from rows
	{
		int count = 1;
		
		for (int y = 0; y < 8; y++)
		{
			if (MyGameArray[x][y] == MyGameArray[x][y - 1])
			{
				count++;
			}

			if (count > 3)
			{
				if (count == 6)
				{
					Score = Score + HexaCrystal;
				}
				if (count == 5)
				{
					Score = Score + PentaCrystal;
				}
				if (count == 4)
				{
					Score = Score + QuadCrystal;
				}
				if (count == 3)
				{
					Score = Score + TriCrystal;
				}

				MyGameArray[x][y] = ' ';
				MyGameArray[x][y - 1] = ' ';
				MyGameArray[x][y - 1 - 1] = ' ';
				MyGameArray[x][y - 1 - 1 - 1] = ' ';
			}*/

			/* /////////////////////////////////////////////////////
			if (count > 3)
			{
				MyGameArray[x][y] = ' ';
				for (int remove = location; remove >= 0; --remove)
				{
					//MyGameArray[x][y] = ' ';
					MyGameArray[x][remove] = ' ';
				}
			}
			*//////////////////////////////////////////////////////
		//}
	//}
	
	/*for (int x = 8; x > 0; x--) ////////////////////////////////////////
	{
		int count = 1;

		for (int y = 0; y < 8; y++)
		{
			if (MyGameArray[x][y] == MyGameArray[x - 1][y] && MyGameArray[x][y] != ' ')
			{
				count++;
			}

			if (count > 3)
			{
				MyGameArray[x][y] = ' ';
				MyGameArray[x - 1][y] = ' ';
				MyGameArray[x - 1 - 1][y] = ' ';
				MyGameArray[x - 1 - 1 - 1][y] = ' ';
			}*/ /////////////////////////////////////////

			/*
			if (count > 3)
			{

				for (int remove = count; remove >= 0; remove--)
				{
					MyGameArray[remove][y] = ' ';
				}
			}
			*/
		//}
	//}

	for (int x = ROWS; x > 0; x--)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			//Loops through the array to check for any whitespaces
			if (MyGameArray[x][y] == ' ')
			{
				MyGameArray[x + 1][y] = MyGameArray[x][y]; //Shifts the element above downwards to fill the space
			}
		}
		if (turn > 20) //20 turns limit, to provide a limit to the user
		{
			//A series of if statements to determine where the score from the current game will end up in the high score table
			//this is to prevent the high score table from being incorrectly ranked
			if (Score > HighScore)
			{
				HighScore = Score;
			}
			if (Score < HighScore && Score > HighScore2)
			{
				HighScore1 = Score;
			}
			if (Score < HighScore1 && Score > HighScore3)
			{
				HighScore2 = Score;
			}
			if (Score < HighScore2 && Score > HighScore4)
			{
				HighScore3 = Score;
			}
			if (Score < HighScore3 && Score > HighScore5)
			{
				HighScore4 = Score;
			}
			if (Score < HighScore4 && Score > HighScore6)
			{
				HighScore5 = Score;
			}
			if (Score < HighScore5 && Score > HighScore7)
			{
				HighScore6 = Score;
			}
			if (Score < HighScore6 && Score > HighScore8)
			{
				HighScore7 = Score;
			}
			if (Score < HighScore7 && Score > HighScore9)
			{
				HighScore8 = Score;
			}
			if (Score < HighScore8)
			{
				HighScore9 = Score;
			}

			//Resets the score and turn to 0 for the next game
			Score = 0;
			turn = 0;
			printf("You have run out of moves! Game Over!");
			_getch();
			GameOver();
		}
	}

	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			//Goes through the array to look for remaining whitespace
			if (MyGameArray[x][y] == ' ')
			{
				//Refills the array by generating a new random number and assigning it and an ASCII character to that index
				//Possibly could have altered the CreateGame(MyGameArray) function to reduce code duplication however I did not have enough time to test it
				GemNumber = rand() % 6;

				switch (GemNumber)
				{
				case eRed:
					SetColour(4);
					MyGameArray[x][y] = 'A' + 154;
					break;

				case eGreen:
					SetColour(10);
					MyGameArray[x][y] = 'A' + 102;
					break;

				case eYellow:
					SetColour(14);
					MyGameArray[x][y] = 'A' + 189;
					break;

				case eBlue:
					SetColour(1);
					MyGameArray[x][y] = 'A' + 110;
					break;

				case eWhite:
					SetColour(15);
					MyGameArray[x][y] = 'A' + 151;
					break;

				case ePurple:
					SetColour(5);
					MyGameArray[x][y] = 'A' + 180;
					break;
				}
			}
		}
	}

	DisplayGame();
}

void GameOver()
{
	DisplayMenu(); //Returns to the menu after the turns has reached 20
}

void QuitGame()
{
	Exit(); //Exits the game when the user quits from the gameplay screen
}