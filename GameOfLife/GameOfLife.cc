
/* <Mitchell Brandone>
 * <10-5-2015>
 *
 * <The Game Of Life>
 ***************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define MAX_WIDTH 40

// function prototypes
void ParseCmdLine(int, char**);
void ShowUsage(char*);
int ReadGen0(bool[MAX_WIDTH][MAX_WIDTH]);
void DisplayBoard(bool[MAX_WIDTH][MAX_WIDTH], int, int);
void NextGen(bool[MAX_WIDTH][MAX_WIDTH],int);

// command line parameters (default values)
int numGens = 10;
int genInt = 1;

/*******
 * MAIN
 *******/
int main(int argc, char **argv)
{
	//This clock does spooky timer things
	clock_t startTime = clock();
	// "*" => true, " " => false
	bool board[MAX_WIDTH][MAX_WIDTH];
	int len;
	// parse the command line, read gen0, and display the board
	ParseCmdLine(argc, argv);
	len = ReadGen0(board);
	DisplayBoard(board, 0, len);
	//Iterate through every generation, excluding gen 0
	for(int n = 1;n<=numGens;n++)
	{
		//Update alive/dead status on board
		NextGen(board,len);
		//Displays board only at requested generation intervals
		if(! (n % genInt))
			DisplayBoard(board, n, len);	
	}
	//calculates time taken to execute game, for giggles 
	clock_t endTime = clock();
	clock_t clockTicksTaken = endTime - startTime;
	double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
	//Prints time elapsed (s) since start of program
	cout << timeInSeconds;
}

// parses the command line for parameters
void ParseCmdLine(int argc, char **argv)
{
	if (argc == 1)
	{
		ShowUsage(argv[0]);
		exit(0);
	}

	for (int i=1; i<argc; i++)
	{
		// default values
		if (!strcmp(argv[i], "-D"))
			break;
		// help/usage
		if (!strcmp(argv[i], "-h"))
		{
			ShowUsage(argv[0]);
			exit(0);
		}
		// number of generations to produce
		else if (strcmp(argv[i], "-n") > 0)
		{
			argv[i] += 2;
			numGens = atoi(argv[i]);
		}
		// display generation interval
		else if (strcmp(argv[i], "-i") > 0)
		{
			argv[i] += 2;
			genInt = atoi(argv[i]);
		}
	}
}

// displays help/usage
void ShowUsage(char *filename)
{
	cout << "Usage: " << filename << " [-h] -D [-(ni)<val>]\n";
	cout << " e.g.: " << filename << " -D < gen0\n";
	cout << "  -D\t\tUse default values\n";
	cout << "  -n<val>\tSet the number of generations to produce to <val> (=10)\n";
	cout << "  -i<val>\tSet the generation display interval to <val> (=1)\n";
	cout << "  -h\t\tShow this screen\n";
}

// reads the initial generation
int ReadGen0(bool board[MAX_WIDTH][MAX_WIDTH])
{
	char line[MAX_WIDTH];
	int i = 0;
	int len = 0;
	// we assume that the input contains a blank border as specified in class
	while (cin.getline(line, MAX_WIDTH))
	{
		// grab each character of each line and make the board
		for (int j=0; j<strlen(line); j++)
			board[i][j] = (line[j] == '*');
		i++;
		// note the board size (redundant)
		len = strlen(line);
	}
	return len;
}

// displays the current board
void DisplayBoard(bool board[MAX_WIDTH][MAX_WIDTH], int gen, int len)
{
	// display the generation number
	cout << "Gen " << gen << ": \n";
	//Shifts row to match future positions of board elements
	cout << "  ";
	//Displays column #s for whole board (Note: displays at most 9, then restarts at 0)
	for(int i =1; i< len-1;i++)
		cout << (i%10) << " ";
	cout << "\n";
	//Iterate through every row of the board
	for(int i = 1; i< len-1; i++) 
	{
		//Displays row # for current row (as with Column above, proceeds 8,9,0,1)
		cout << (i%10) << " "; 
		//Displays each element in current row
		for(int j = 1; j < len-1; j++)
			//Alive displays as asterisk, dead displays as empty space
			(board[i][j]) ? cout << "* " : cout << "  ";
		//Print to next row
		cout << "\n";
	}
}
void NextGen(bool board[MAX_WIDTH][MAX_WIDTH], int len)
{
	//code to generate the next generation oh  ,,god help
	bool boardCopy[MAX_WIDTH][MAX_WIDTH]; 
	//Live neighbor counter
	int numAlive;
	//Nested loops to copy each value of board to a new grid, allowing simultaneous life/death checking
	for(int i = 0; i < MAX_WIDTH; i++)
	{
		for(int j=0;j < MAX_WIDTH; j++)
		{		
			boardCopy[i][j]=board[i][j];
		}
	}
	//Nested loops to iterate through every valid element of the board
	for(int i=1; i<len-1;i++)
	{
		for(int j =1; j<len-1; j++)
		{
			//Live neighbor counter
			numAlive=0;
			//Nested loops to iterate through all neighbors and determine if alive or dead
			for(int k =-1; k<=1;k++)
			{		
				for(int l =-1; l<=1;l++)
				{
					//Ignore Current position
					if(k==0&l==0)
						continue;
					//Truen if selected neighbor is alive, false otherwise
					if(boardCopy[i+k][j+l])
						//Increment live neighbor counter when neighbor is alive
						numAlive++;
				}
			}
			//Cell dies if overcrowded or too lonely
			if(numAlive<2 || numAlive > 3)
				board[i][j]=false;
			//Cell comes to life if already dead and has 3 neighbors
			else if(!boardCopy[i][j])
				 if(numAlive == 3)
					board[i][j]=true;
		}
	}
}
