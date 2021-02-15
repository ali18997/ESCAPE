//																			ESCAPE

//A SHORT GAME THAT TAKES YOU INTO A DANGEROUS WORLD WHERE YOU MUST ESCAPE TO SURVIVE!

//HEADERS
#include <iostream>
#include <iomanip>

using namespace std;

//MAZE PATTERNS
char maze1[10][10] = {     ' ',		' ',		' ',		' ',		' ',		' ',		' ',		' ',		' ',		' ',
									' ',		' ',		'#',		'#',		'#',		'#',		'#',		'#',		'#',		'#'
									,' ',		' ',		'#',		'#',		'#',		 ' ',		' ',		' ',		'#',		'#'
									,' ',		' ',		' ',		' ',		' ',		' ',		'#',		' ',		'#',		'#'
									,'#',	'#',		'#',		'#',		'#',		'#',		'#',		' ',		' ',		'#'
									,'#',	' ',		' ',		' ',		' ',		' ',		'#',		'#',		' ',		' '
									,'#',	' ',		'#',		'#',		'#',		' ',		'#',		'#',		'#',		' '
									,'#',	' ',		' ',		' ',		'#',		' ',		' ',		' ',		'#',		' '
									,'#',	'#',		'#',		' ',		'#',		'#',		'#',		' ',		' ',		' '
									,' ',		' ',		' ',		' ',		'#',		'#',		'#',		' ',		' ',		' '};

char maze2[10][10] = {    
									' ',		' ',		' ',		' ',		' ',		' ',		' ',		' ',		'#',		'#',
									'#',		'#',		'#',		'#',		'#',		'#',		'#',		' ',		'#',		'#'
									,' ',		' ',		'#',		'#',		'#',		 '#',	'#',		' ',		'#',		' '
									,' ',		' ',		'#',		' ',		' ',		' ',		'#',		' ',		' ',		' '
									,' ',		' ',		'#',		' ',		' ',		' ',		'#',		' ',		' ',		'#'
									,' ',		'#',		'#',		' ',		' ',		' ',		'#',		'#',		'#',		'#'
									,' ',		 ' ',	 	 ' ',		' ',		' ',		' ',		' ',		' ',		' ',		' '
									,'#',	' ',		'#',		'#',		'#',		'#',		' ',		'#',		' ',		' '
									,' ',		' ',		' ',		' ',		'#',		' ',		' ',		'#',		' ',		' '
									,'#',	'#',		'#',		' ',		' ',		' ',		'#',		'#',		' ',		' '};

//INTEGER DECLARATIONS
int level = 1, Px = 1, Py = 10, x = 10, y = 10, score = 0, health = 100, E1x = 9, E1y = 9, E2x = 1, E2y = 3, E3x = 9,
	E3y = 8, E4x = 4, E4y = 5, E5x = 6, E5y = 5, E6x = 6, E6y = 7, E7x = 4, E7y = 7, Dx = 10,  Dy = 1, C1x = 4, 
	C1y = 8, C2x = 8, C2y = 8, C3x = 3, C3y = 4, Tx = 1, Ty = 4, O1x = 10, O1y = 3, O2x = 1, O2y = 9, Kx = 10, Ky = 10, Pos;

//CHARACTER AND BOOL DECLARATIONS
char start, user_move;
bool running, key;

//FUNCTION PROTOTYPES 
void run();
void logo(); 
void clearScreen();

//LEVEL ORGANIZERS
void levelRun();
void level1();
void level2();
void level3();

//MAPS
void map1();
void map2();
void map3();

//POSITION MAPPING
void position1();
void position2();
void position3();

//MISC
void instructions1();
void instructions2();
void user_progress1();
void user_progress2();
void enemyAI1();
void enemyAI2();

//MAIN FUNCTION (THE CONTROL STARTS HERE)
int main() {
	//PRINTING GAME LOGO ON START SCREEN
	logo();
	//USER ASKED TO START GAME
	cout << "\t    Enter \'Y\' to Start the Game!" << endl;
	cout << "\t\t\t";
	cin >> start;

	if(start == 'y' || start == 'Y') {
		//MOVING CONTROL TO RUN FUNCTION
		run();
	}
	else {
		cout << "OK, come back later!" << endl;
	}
	system("pause");
	return 0;
}

//RUN FUNCTION
void run() {
	//FLAGS THE STATUS OF THE GAME AS RUNNING
	running = true;
	while(running) {
		//IF GAME IS RUNNING, CLEAR SCREEN AND MOVE CONTROL TO LEVEL RUN FUNCTION
		clearScreen();
		levelRun();
		break;
	}
}

//LEVEL RUN FUNCTION
void levelRun() {
	//MOVES CONTROL TO LEVEL 1 FUNCTION
	if(level == 1) {
		level1();
	}
	//MOVES CONTROL TO LEVEL 2 FUNCTION
	if(level == 2) {
		level2();
	}
	//MOVES CONTROL TO LEVEL 3 FUNCTION
	if(level == 3) {
		level3();
	}
}

//LEVEL 1 FUNCTION
void level1() {
	//ONLY WORK IF GAME IS RUNNING
	while(running){
		//CLEAR SCREEN
		clearScreen();

		//PRINT MAP 1
		map1();

		//TELL USER THE INSTRUCTIONS AND ASK FOR INPUT TO MOVE
		instructions1();

		//CALCULATE NEW POSITIONS BASED ON USER ENTERED VALUES
		position1();
		
		//EVALUATE USER PROGRESS, INCLUDING SCORE AND HEALTH
		//ALSO TELL THE USER IF HE HAS PASSED OR FAILED A LEVEL
		user_progress1();

		//REPEAT THE WHOLE PROCESS AGAIN AND AGAIN TILL THE LEVEL IS PASSED OR FAILED
		//IF THE LEVEL IS PASSED, CONTROL MOVES TO NEXT LEVEL
		//IF THE LEVEL IS FAILED, THE GAME ENDS
	}
}

//MAP 1 FUNCTION
void map1() {
	cout << endl;
	//DISPLAY THE CURRENT LEVEL NUMBER
	cout << "\t\t\tLEVEL 1";

	cout << endl;
	cout << endl;
	//PRINT THE UPPER BOUNDARY OF MAP
	cout << "\t\t# # # # # # # # # # # #" << endl;

	for(int j = 1; j <= y; j++){
		//PRINT THE BLOCK OF LEFT BOUNDARY BEFORE PRINTING EVERY LINE
		cout << "\t\t# ";
		//PRINT THE CONTENTS OF EACH LINE
		for(int i = 1; i <= x; i++) {
			//LOOPS THROUGH ALL THE ELEMENTS IN THE LINE
			//PRINT DOOR IF COORDINATES MATCH
			if( i == Dx && j == Dy) {
				cout << "D";
			}
			//PRINT PLAYER IF COORDINATES MATCH
			else if(i == Px && j == Py) {
				cout << "P";
			}
			//PRINT ENEMY IF COORDINATES MATCH
			else if((i == E1x && j == E1y) || (i == E2x && j == E2y)) {
				cout << "E";
			}
			//PRINT COINS IF COORDINATES MATCH
			else if((i == C1x && j == C1y) || (i == C2x && j == C2y) || (i == C3x && j == C3y)) {
				cout << "C";
			}
			//IF THERE IS NO MATCH, PRINT THE MAZE ELEMENT FOR THIS COORDINATE
			else 
				//MAZE IS AN ARRAY AND STARTS FROM 0, WHILE THE COORDINATES OF MAP START FROM 1
				//THIS DIFFERENCE IS ACCOUNTED FOR BY SUBTRACTING 1 FROM MAP COORDINATES WHILE GIVING TO MAZE
				cout << maze1[j-1][i-1];

			//PRINTS A BLANK SPACE AFTER EVERY ELEMENT TO WIDEN THE MAP HORIZONTALLY
			cout << " ";
		}
		//PRINTS THE BLOCK OF RIGHT BOUNDARY AFTER EVERY LINE AND MOVES TO NEXT LINE
		cout << "#" << endl;
	}
	//PRINTS THE LOWER BOUNDARY AFTER THE WHOLE MAP IS PRINTED
	cout << "\t\t# # # # # # # # # # # #";
}

//INSTRUCTIONS 1 FUNCTION
void instructions1() {
	cout << endl;
	cout << endl;
	//DISPLAY SCORE AND HEALTH
	cout << "\tSCORE: " << score << setw(30) << "HEALTH: " << health << endl;
	cout << endl;
	//DISPLAY INSTRUCTIONS
	cout << "\nYou \'P\' are Trapped in a maze and you have to find your way out to the Door \'D\', while avoiding the Enemies \'E\'. Getting the Coins \'C\' will increase your score!" << endl;
	cout << endl;
	cout << endl;
	//ASK FOR USER ACTION
	cout << "Enter your Move (W = UP, A = Left, S = DOWN, D = RIGHT, you can enter a combination of moves to make a long move): ";
	cin >> user_move;
	//MOVES CONTROL TO ENEMY AI FUNCTION TO MOVE ENEMIES BASED ON USER MOVEMENT
	enemyAI1();
	//CHEAT
	static int health_count = 0;
	if(user_move == 'h' || user_move == 'e' || user_move == 'a' || user_move == 'l'){
		health_count++;
		if (health_count == 4) {
			health = 100;
			health_count = 0;
		}
	}
}

//ENEMY AI 1 FUNCTION
void enemyAI1(){

	//COMPARES PREVIOUS POSTIONS AND DECIDE NEXT TO MAKE THE ENEMY MOVE IN A CIRCLE

		//MOVEMENT OF ENEMY 1
		if(E1x == 9 && E1y == 9){
			E1x++;
		}

		else if (E1x == 10 && E1y == 9){
			E1y++;
		}

		else if (E1x == 10 && E1y == 10){
			E1x--;
		}
		
		else if (E1x == 9 && E1y == 10){
			E1x--;
		}
		
		else if (E1x == 8 && E1y == 10){
			E1y--;
		}
		
		else if (E1x == 8 && E1y == 9){
			E1x++;
		}
		
		//MOVEMENT OF ENEMY 2
		if(E2x == 1 && E2y == 3){
			E2y--;
		}
		
		else if (E2x == 1 && E2y == 2){
			E2x++;
		}
		
		else if (E2x == 2 && E2y == 2){
			E2y++;
		}
		
		else if (E2x == 2 && E2y == 3){
			E2y++;
		}
		
		else if (E2x == 2 && E2y == 4){
			E2x--;
		}
		
		else if (E2x == 1 && E2y == 4){
			E2y--;
		}
}

//USER PROGRESS 1 FUNCTION
void user_progress1() {
	//DECREASE HEALTH BY 50 IF ATTACKED BY ENEMY
	if(Px == E1x && Py == E1y) {
		health -=50;
		E1x = -1; E1y = -1;
	}
	else if (Px == E2x && Py == E2y) {
		health -=50;
		E2x = -1; E2y = -1;
	}
	//INCREASE SCORE BY 10 FOR TAKING COINS
	else if (Px == C1x && Py == C1y) {
		score +=10;
		C1x = -1; C1y = -1;
	}
	else if (Px == C2x && Py == C2y) {
		score +=10;
		C2x = -1; C2y = 1;
	}
	else if (Px == C3x && Py == C3y) {
		score +=10;
		C3x = -1; C3y  = 1;
	}
	//DIES IF HEALTH IS 0 AND ENDS GAME
	if(health == 0) {
		running = false;
		clearScreen();

		cout << endl;
		cout << endl;
		
		cout << "YOU DIED!" << endl;
		
		cout << endl;
		cout << endl;
	}
	//IF ARRIVED AT DOOR, LEVEL IS SUCCESSFUL
	//ASK USER TO GO TO NEXT LEVEL
	if(Px == Dx && Py == Dy) {
		running = false;
		clearScreen();
		
		cout << "You Survived this Level!" << endl;
		cout << endl;
		char proceed;
		cout << "Enter \'Y\' to Proceed to Next Level!" << endl;
		cin >> proceed;

		if(proceed == 'y' || proceed == 'Y') {
			level = 2;
			run();
		}
	}
}

//POSITION 1 FUNCTION
void position1() {
	switch (user_move) {
		//CHANGE COORDINATES OF PLAYER ACCORDING TO THE MOVEMENT KEY ENTERED
		//ONLY MOVE IF THERE IS NO WALL OR BOUNDARY IN THE WAY

		//LEFT MOVEMENT
		case 'a':
			if(Px != 1 && maze1[Py-1][Px-1-1] != '#') {
				Px--;
			}
			break;

		//DOWN MOVEMENT
		case 's':
			if(Py != 10 && maze1[Py+1-1][Px-1] != '#') {
				Py++;
			}
			break;
		
		//RIGHT MOVEMENT
		case 'd':
			if(Px != 10 && maze1[Py-1][Px+1-1] != '#') {
				Px++;
			}
			break;

		//UP MOVEMENT
		case 'w':
			if(Py != 1 && maze1[Py-1-1][Px-1] != '#') {
				Py--;
			}
			break;
	}
}

//LEVEL 2 FUNCTION
void level2() {
	//RE-ASSIGNING VALUES TO SOME INT VARIABLES
	Px = 1; Py = 1; E1x = 1; E1y = 3; E2x = 8; E2y = 4; C1x = 4; C1y = 4; C2x = 5; C2y = 4; C3x = 6; C3y = 4, Dx = 5, Dy = 6;
	//ONLY WORK IF GAME IS RUNNING
	while(running){
		//CLEAR SCREEN
		clearScreen();

		//PRINT MAP 2
		map2();

		//TELL USER THE INSTRUCTIONS AND ASK FOR INPUT TO MOVE
		instructions2();

		//CALCULATE NEW POSITIONS BASED ON USER ENTERED VALUES
		position2();
		
		//EVALUATE USER PROGRESS, INCLUDING SCORE AND HEALTH
		//ALSO TELL THE USER IF HE HAS PASSED OR FAILED A LEVEL
		user_progress2();

		//REPEAT THE WHOLE PROCESS AGAIN AND AGAIN TILL THE LEVEL IS PASSED OR FAILED
		//IF THE LEVEL IS PASSED, CONTROL MOVES TO NEXT LEVEL
		//IF THE LEVEL IS FAILED, THE GAME ENDS
	}
}

//MAP 2 FUNCTION
void map2() {
	cout << endl;
	//DISPLAY THE CURRENT LEVEL NUMBER
	cout << "\t\t\tLEVEL 2";

	cout << endl;
	cout << endl;
	//PRINT THE UPPER BOUNDARY OF MAP
	cout << "\t\t# # # # # # # # # # # #" << endl;

	for(int j = 1; j <= y; j++){
		//PRINT THE BLOCK OF LEFT BOUNDARY BEFORE PRINTING EVERY LINE
		cout << "\t\t# ";
		//PRINT THE CONTENTS OF EACH LINE
		for(int i = 1; i <= x; i++) {
			//LOOPS THROUGH ALL THE ELEMENTS IN THE LINE
			//PRINT DOOR IF COORDINATES MATCH
			if( i == Dx && j == Dy) {
				cout << "D";
			}
			//PRINT PLAYER IF COORDINATES MATCH
			else if(i == Px && j == Py) {
				cout << "P";
			}
			//PRINT TREASURE IF COORDINATES MATCH
			else if(i == Tx && j == Ty) {
				cout << "T";
			}
			else if(i == Kx && j == Ky) {
				cout << "K";
			}
			//PRINT PORTAL IF COORDINATES MATCH
			else if((i == O1x && j == O1y) || (i == O2x && j == O2y)) {
				cout << "O";
			}
			//PRINT ENEMY IF COORDINATES MATCH
			else if((i == E1x && j == E1y) || (i == E2x && j == E2y) || (i == E3x && j == E3y) || (i == E4x && j == E4y) || 
				     (i == E5x && j == E5y) || (i == E6x && j == E6y) || (i == E7x && j == E7y)) {
				cout << "E";
			}
			//PRINT COINS IF COORDINATES MATCH
			else if((i == C1x && j == C1y) || (i == C2x && j == C2y) || (i == C3x && j == C3y)) {
				cout << "C";
			}
			//IF THERE IS NO MATCH, PRINT THE MAZE ELEMENT FOR THIS COORDINATE
			else 
				//MAZE IS AN ARRAY AND STARTS FROM 0, WHILE THE COORDINATES OF MAP START FROM 1
				//THIS DIFFERENCE IS ACCOUNTED FOR BY SUBTRACTING 1 FROM MAP COORDINATES WHILE GIVING TO MAZE
				cout << maze2[j-1][i-1];

			//PRINTS A BLANK SPACE AFTER EVERY ELEMENT TO WIDEN THE MAP HORIZONTALLY
			cout << " ";
		}
		//PRINTS THE BLOCK OF RIGHT BOUNDARY AFTER EVERY LINE AND MOVES TO NEXT LINE
		cout << "#" << endl;
	}
	//PRINTS THE LOWER BOUNDARY AFTER THE WHOLE MAP IS PRINTED
	cout << "\t\t# # # # # # # # # # # #";
}

void level3() {
	clearScreen();
	cout << endl;
	cout << "Level 3 is Coming Soon!" << endl;
	cout << endl;
	cout << "Pre-Order for Only $99.95 to Get Premium Features!" << endl;
	cout << endl;
	running = false;
}

void map3() {}

void position2() {
	switch (user_move) {
		//CHANGE COORDINATES OF PLAYER ACCORDING TO THE MOVEMENT KEY ENTERED
		//ONLY MOVE IF THERE IS NO WALL OR BOUNDARY IN THE WAY

		//LEFT MOVEMENT
		case 'a':
			if(Px != 1 && maze2[Py-1][Px-1-1] != '#') {
				Px--;
			}
			break;

		//DOWN MOVEMENT
		case 's':
			if(Py != 10 && maze2[Py+1-1][Px-1] != '#') {
				Py++;
			}
			break;
		
		//RIGHT MOVEMENT
		case 'd':
			if(Px != 10 && maze2[Py-1][Px+1-1] != '#') {
				Px++;
			}
			break;

		//UP MOVEMENT
		case 'w':
			if(Py != 1 && maze2[Py-1-1][Px-1] != '#') {
				Py--;
			}
			break;
	}
	if(Px == O1x && Py == O1y){
		Px = O2x+1;
		Py = O2y;
	}
	else if(Px == O2x && Py == O2y){
		Px = O1x;
		Py = O1y+1;
	}
}
//INSTRUCTIONS 2 FUNCTION
void instructions2() {
	cout << endl;
	cout << endl;
	//DISPLAY SCORE AND HEALTH
	cout << "\tSCORE: " << score << setw(30) << "HEALTH: " << health << endl;
	cout << endl;
	//DISPLAY INSTRUCTIONS
	cout << "\nYou \'P\' are Trapped in a maze and you have to find your way out to the Door \'D\', while avoiding the Enemies \'E\'. Getting the Coins \'C\' will increase your score. Getting the Treasure \'T\' will increase your score massively." << endl;
	cout << endl;
	cout << endl;
	//ASK FOR USER ACTION
	cout << "Enter your Move (W = UP, A = Left, S = DOWN, D = RIGHT, you can enter a combination of moves to make a long move): ";
	cin >> user_move;
	//MOVES CONTROL TO ENEMY AI FUNCTION TO MOVE ENEMIES BASED ON USER MOVEMENT
	enemyAI2();
	//CHEAT
	static int health_count = 0;
	if(user_move == 'h' || user_move == 'e' || user_move == 'a' || user_move == 'l'){
		health_count++;
		if (health_count == 4) {
			health = 100;
			health_count = 0;
		}
	}

}

//ENEMY AI 2 FUNCTION
void enemyAI2(){

	//COMPARES PREVIOUS POSTIONS AND DECIDE NEXT TO MAKE THE ENEMY MOVE IN A CIRCLE

		//MOVEMENT OF ENEMY 1
		if(E1x == 1 && E1y == 3){
			Pos = 0;
			E1x++;
		}

		else if (E1x == 2 && E1y == 3 && Pos == 0){
			E1y++;
		}

		else if (E1x == 2 && E1y == 4 && Pos == 0){
			E1y++;
		}
		
		else if (E1x == 2 && E1y == 5 && Pos == 0){
			E1x--;
		}
		
		else if (E1x == 1 && E1y == 5){
			Pos = 1;
			E1x++;
		}
		else if (E1x == 2 && E1y == 5 && Pos == 1){
			E1y--;
		}
		else if (E1x == 2 && E1y == 4 && Pos == 1){
			E1y--;
		}
		else if (E1x == 2 && E1y == 3 && Pos == 1){
			E1x--;
		}
		
		//MOVEMENT OF ENEMY 2
		if(E2x == 8 && E2y == 4){
			E2x++;
		}
		
		else if (E2x == 9 && E2y == 4){
			E2y++;
		}
		
		else if (E2x == 9 && E2y == 5){
			E2x--;
		}
		
		else if (E2x == 8 && E2y == 5){
			E2y--;
		}

		//MOVEMENT OF ENEMY 3
		if(E3x == 9 && E3y == 8){
			E3y++;
		}
		
		else if (E3x == 9 && E3y == 9){
			E3x++;
		}
		
		else if (E3x == 10 && E3y == 9){
			E3y--;
		}
		
		else if (E3x == 10 && E3y == 8){
			E3x--;
		}

		//MOVEMENT OF ENEMY 4
		if(E4x == 4 && E4y == 5){
			E4x++;
		}

		else if (E4x == 5 && E4y == 5){
			E4x++;
		}

		else if (E4x == 6 && E4y == 5){
			E4y++;
		}
		
		else if (E4x == 6 && E4y == 6){
			E4y++;
		}
		
		else if (E4x == 6 && E4y == 7){
			E4x--;
		}
		else if (E4x == 5 && E4y == 7){
			E4x--;
		}
		else if (E4x == 4 && E4y == 7){
			E4y--;
		}
		else if (E4x == 4 && E4y == 6){
			E4y--;
		}

		//MOVEMENT OF ENEMY 5
		if(E5x == 4 && E5y == 5){
			E5x++;
		}

		else if (E5x == 5 && E5y == 5){
			E5x++;
		}

		else if (E5x == 6 && E5y == 5){
			E5y++;
		}
		
		else if (E5x == 6 && E5y == 6){
			E5y++;
		}
		
		else if (E5x == 6 && E5y == 7){
			E5x--;
		}
		else if (E5x == 5 && E5y == 7){
			E5x--;
		}
		else if (E5x == 4 && E5y == 7){
			E5y--;
		}
		else if (E5x == 4 && E5y == 6){
			E5y--;
		}

		//MOVEMENT OF ENEMY 6
		if(E6x == 4 && E6y == 5){
			E6x++;
		}

		else if (E6x == 5 && E6y == 5){
			E6x++;
		}

		else if (E6x == 6 && E6y == 5){
			E6y++;
		}
		
		else if (E6x == 6 && E6y == 6){
			E6y++;
		}
		
		else if (E6x == 6 && E6y == 7){
			E6x--;
		}
		else if (E6x == 5 && E6y == 7){
			E6x--;
		}
		else if (E6x == 4 && E6y == 7){
			E6y--;
		}
		else if (E6x == 4 && E6y == 6){
			E6y--;
		}

		//MOVEMENT OF ENEMY 7
		if(E7x == 4 && E7y == 5){
			E7x++;
		}

		else if (E7x == 5 && E7y == 5){
			E7x++;
		}

		else if (E7x == 6 && E7y == 5){
			E7y++;
		}
		
		else if (E7x == 6 && E7y == 6){
			E7y++;
		}
		
		else if (E7x == 6 && E7y== 7){
			E7x--;
		}
		else if (E7x== 5 && E7y == 7){
			E7x--;
		}
		else if (E7x == 4 && E7y == 7){
			E7y--;
		}
		else if (E7x == 4 && E7y == 6){
			E7y--;
		}
}

//USER PROGRESS 2 FUNCTION
void user_progress2() {
	//DECREASE HEALTH BY 50 IF ATTACKED BY ENEMY
	if(Px == E1x && Py == E1y) {
		health -=50;
		E1x = -1; E1y = -1;
	}
	else if (Px == E2x && Py == E2y) {
		health -=50;
		E2x = -1; E2y = -1;
	}
	else if (Px == E3x && Py == E3y) {
		health -=50;
		E3x = -1; E3y = -1;
	}
	else if (Px == E4x && Py == E4y) {
		health -=50;
		E4x = -1; E4y = -1;
	}
	else if (Px == E5x && Py == E5y) {
		health -=50;
		E5x = -1; E5y = -1;
	}
	else if (Px == E6x && Py == E6y) {
		health -=50;
		E6x = -1; E6y = -1;
	}
	else if (Px == E7x && Py == E7y) {
		health -=50;
		E7x = -1; E7y = -1;
	}
	//INCREASE SCORE BY 10 FOR TAKING COINS
	else if (Px == C1x && Py == C1y) {
		score +=10;
		C1x = -1; C1y = -1;
	}
	else if (Px == C2x && Py == C2y) {
		score +=10;
		C2x = -1; C2y = 1;
	}
	else if (Px == C3x && Py == C3y) {
		score +=10;
		C3x = -1; C3y  = 1;
	}
	//INCREASE SCORE BY 100 FOR TAKING TREASURE
	else if (Px == Tx && Py == Ty) {
		score +=100;
		Tx = -1; Ty = -1;
	}
	//GET THE KEY
	else if (Px == Kx && Py == Ky) {
		key = true;
		Kx = -1; Ky = -1;
	}
	//DIES IF HEALTH IS 0 AND ENDS GAME
	if(health == 0) {
		running = false;
		clearScreen();

		cout << endl;
		cout << endl;

		cout << "YOU DIED!" << endl;

		cout << endl;
		cout << endl;
	}
	//IF ARRIVED AT DOOR, LEVEL IS SUCCESSFUL
	//ASK USER TO GO TO NEXT LEVEL
	if(Px == Dx && Py == Dy && key == true) {
		running = false;
		clearScreen();
		
		cout << "You Survived this Level!" << endl;
		cout << endl;
		char proceed;
		cout << "Enter \'Y\' to Proceed to Next Level!" << endl;
		cin >> proceed;

		if(proceed == 'y' || proceed == 'Y') {
			level = 3;
			run();
		}
	}
	if(Px == Dx && Py == Dy && key != true){
		char c;
		system("cls");
		cout << endl;
		cout << "Get the Key \'K\' to Pass through the Door!" << endl;
		cout << endl;
		cout << "Enter Anything to Continue............." << endl;
		cin >> c;
		cout << endl;
	}
}
void position3() { }

//CLEAR SCREEN FUNCTION
void clearScreen() {
	system("cls");
}

//LOGO FUNCTION
void logo() {
	//PRINTS UPPER BOUNDARY
	cout << "  #################################################" << endl;

	//PRINT LEFT BOUNDARY BLOCK, THEN CONTENTS OF THE LINE, THEN RIGHT BOUNDARY BLOCK
	cout << "  #" << setw(48) << "#"<< endl;
	cout << "  #" <<setw(6) << "#####" << setw(8) << "#####" << setw(8) << "#####" << setw(8) << "#####" << setw(8) << "#####" << setw(8) << "#####" << setw(2)<< "#" << endl;
	cout << "  #" <<setw(2) <<"#" << setw(8) << "#" << setw(8) << "#" << setw(8) << "#" << setw(4) << "#" << setw(4) << "#" << setw(4) << "#" << setw(4)<<  "#" << setw(6)<< "#"<< endl;
	cout << "  #" <<setw(6) <<"#####" << setw(8) << "#####" << setw(4) << "#" << setw(12) << "#####" << setw(8) << "#####" << setw(8) << "#####" << setw(2)<< "#"<< endl;
	cout << "  #" <<setw(2) <<"#"  << setw(12) << "#" << setw(4) <<  "#"   << setw(8) << "#"  << setw(4) <<  "#" << setw(4) << "#" << setw(8) <<"#" << setw(6)<< "#"<< endl;
	cout << "  #" <<setw(6) <<"#####" << setw(8) << "#####" << setw(8) << "#####" << setw(4) <<  "#" << setw(4) << "#" << setw(4) << "#"<< setw(12) << "#####" << setw(2)<< "#"<< endl;
	cout << "  #" << setw(48) << "#"<< endl;

	//PRINT THE LOWER BOUNDARY
	cout << "  #################################################" << endl;
	cout << endl;
	
	//CREDITS
	cout << "\t\tPresented to you by:" << endl;
	cout << endl;
	
	cout << "\t\tSyed  Mohammad  Ali" << endl;
	cout << "\t\t Qazi Talha Hamid" << endl;
	cout << "\t\t    Ammar Amjad" << endl;
	
	cout << endl;
	cout << endl;
}
