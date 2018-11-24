#include <iostream>
#include <string>

using namespace std;
string board [12][15];
int a =0;
int turns =0;

int introduction() {
// Start off by asking if player knows how to play the game.
string greetings = "Are you ready to play connect four? If yes, type y. If you need a clarification of the rules, type n";
string rule1 = "Good! Let us start the game. Player one will be the O, player two will be the X.";
string rule2 = "Connect Four is a game for two players, O and X, who take turns dropping discs from the top of a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the next available space within the column. The objective of the game is to connect four of one's own discs next to each other vertically, horizontally, or diagonally before your opponent.";
char yesno ;
char yes = 'y';
char no = 'n';

cout << "" << endl;
cout << greetings << endl;
cin >> yesno;

if (yesno == yes){
	cout << rule1 << endl;
}

else if(yesno == no){
	cout << rule2 << endl;
}

cout << endl;
return 0;
}

// The idea of the snake functions is that after every move, a check will be performed on the board at the position of
// the new move. Checks performed in seven directions (all except up). If same symbol found, then do the same check in
// those directions. If four in a row, then gameend becomes 1 and the game ends.

int snakehoriz(int rowslot,int colslot){
int gameend=0;
	if(colslot-2>0){ //to check if left side is part of the grid or not. If indeed it is greater than zero then we are still in the grid.
		if(board[rowslot][colslot] == board[rowslot][colslot-2]){
			if(colslot-4>0){
				if(board[rowslot][colslot] == board[rowslot][colslot-4]){
					if(colslot-6>0){
						if(board[rowslot][colslot] == board[rowslot][colslot-6]){
							gameend = 1;
							cout<<"Victory horizontal"<<endl;
						}
						else{
							if(board[rowslot][colslot] == board[rowslot][colslot+2]){
							gameend = 1;
							cout<<"Victory horizontal"<<endl;
							}
						}
					}
					else{
						if(board[rowslot][colslot] == board[rowslot][colslot+2]){
							gameend = 1;
							cout<<"Victory horizontal"<<endl;
						}
					}
				}
				else{
					if(board[rowslot][colslot] == board[rowslot][colslot+2]){
						if(board[rowslot][colslot] == board[rowslot][colslot+4]) {
							gameend = 1;
							cout<<"Victory0 horizontal"<<endl;
						}
					}
				}
			}
			else{
				if(board[rowslot][colslot] == board[rowslot][colslot+2]){
					if(board[rowslot][colslot] == board[rowslot][colslot+4]) {
							gameend = 1;
							cout<<"Victory horizontal"<<endl;
					}
				}
			}
		}
		else{
			if(board[rowslot][colslot] == board[rowslot][colslot+2]){
				if(board[rowslot][colslot] == board[rowslot][colslot+4]) {
					if(board[rowslot][colslot] == board[rowslot][colslot+6]) {
					gameend = 1;
					cout<<"Victory horizontal"<<endl;
					}
				}
			}
		}
	}
	else{
		if(board[rowslot][colslot] == board[rowslot][colslot+2]){
			if(board[rowslot][colslot] == board[rowslot][colslot+4]) {
				if(board[rowslot][colslot] == board[rowslot][colslot+6]) {
				gameend = 1;
				cout<<"Victory horizontal"<<endl;
				}
			}
		}
	}
return gameend;
}

int snakeleftdownrightup(int rowslot,int colslot){
int gameend=0;
	if(rowslot+2<11&&colslot-2>0){ //to check if left side is part of the grid or not. If indeed it is greater than zero then we are still in the grid.
		if(board[rowslot][colslot] == board[rowslot+2][colslot-2]){
			if(rowslot+4<11&&colslot-4>0){
				if(board[rowslot][colslot] == board[rowslot+4][colslot-4]){
					if(rowslot+6<11&&colslot-6>0){
						if(board[rowslot][colslot] == board[rowslot+6][colslot-6]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
						else if(rowslot-2>0&&colslot+2<14){
							if(board[rowslot][colslot] == board[rowslot-2][colslot+2]) {
								gameend = 1;
								cout<<"Victory diagonal"<<endl;
							}
						}
					}
					else if(rowslot-2>0&&colslot+2<14){
						if(board[rowslot][colslot] == board[rowslot-2][colslot+2]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
				else if(rowslot-2>0&&colslot+2<14){
					if(board[rowslot][colslot] == board[rowslot-2][colslot+2]){
						if(rowslot-4>0&&colslot+4<14) {
							if(board[rowslot][colslot] == board[rowslot-4][colslot+4]) {
								gameend = 1;
								cout<<"Victory diagonal"<<endl;
							}
						}
					}
				}
			}
			else if(rowslot-2>0&&colslot+2<14){
				if(board[rowslot][colslot] == board[rowslot-2][colslot+2]){
					if(rowslot-4>0&&colslot+4<14) {
						if(board[rowslot][colslot] == board[rowslot-4][colslot+4]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
			}
		}
		else if(rowslot-2>0&&colslot+2<14){
			if(board[rowslot][colslot] == board[rowslot-2][colslot+2]){
				if(rowslot-4>0&&colslot+4<14){
					if(board[rowslot][colslot] == board[rowslot-4][colslot+4]) {
						if(rowslot-6>0&&colslot+6<14){
							if(board[rowslot][colslot] == board[rowslot-6][colslot+6]) {
								gameend = 1;
								cout<<"Victory diagonal"<<endl;
							}
						}
					}
				}
			}
		}
	}
	else if(rowslot-2>0&&colslot+2<14){
		if(board[rowslot][colslot] == board[rowslot-2][colslot+2]){
			if(rowslot-4>0&&colslot+4<14){
				if(board[rowslot][colslot] == board[rowslot-4][colslot+4]) {
					if(rowslot-6>0&&colslot+6<14){
						if(board[rowslot][colslot] == board[rowslot-6][colslot+6]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
			}
		}
	}
return gameend;
}

int snakeleftuprightdown(int rowslot,int colslot){
int gameend=0;
	if(rowslot+2<11&&colslot+2<14){
		if(board[rowslot][colslot] == board[rowslot+2][colslot+2]){
			if(rowslot+4<11&&colslot+4<14){
				if(board[rowslot][colslot] == board[rowslot+4][colslot+4]){
					if(rowslot+6<11&&colslot+6<14){
						if(board[rowslot][colslot] == board[rowslot+6][colslot+6]){
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
						else if(rowslot-2>0&&colslot-2>0){
							if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
							}
						}
					}
					else if(rowslot-2>0&&colslot-2>0){
						if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
				else if(rowslot-2>0&&colslot-2>0){
					if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
						if(rowslot-4>0&&colslot-4>0) {
							if(board[rowslot][colslot] == board[rowslot-4][colslot-4]) {
								gameend = 1;
								cout<<"Victory diagonal"<<endl;
							}
						}
					}
				}
			}
			else if(rowslot-2>0&&colslot-2>0){
				if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
					if(rowslot-4>0&&colslot-4>0) {
						if(board[rowslot][colslot] == board[rowslot-4][colslot-4]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
			}
		}
		else if(rowslot-2>0&&colslot-2>0){
			if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
				if(rowslot-4>0&&colslot-4>0) {
					if(board[rowslot][colslot] == board[rowslot-4][colslot-4]) {
						if(rowslot-6>0&&colslot-6>0) {
							if(board[rowslot][colslot] == board[rowslot-6][colslot-6]) {
								gameend = 1;
								cout<<"Victory diagonal"<<endl;
							}
						}
					}
				}
			}
		}
	}
	else if(rowslot-2>0&&colslot-2>0){
		if(board[rowslot][colslot] == board[rowslot-2][colslot-2]){
			if(rowslot-4>0&&colslot-4>0) {
				if(board[rowslot][colslot] == board[rowslot-4][colslot-4]) {
					if(rowslot-6>0&&colslot-6>0) {
						if(board[rowslot][colslot] == board[rowslot-6][colslot-6]) {
							gameend = 1;
							cout<<"Victory diagonal"<<endl;
						}
					}
				}
			}
		}
	}
return gameend;
}

int snakedown(int rowslot,int colslot) {
int gameend=0;
	if (rowslot<=4){
		if(board[rowslot][colslot] == board[rowslot+2][colslot]){
			if(board[rowslot][colslot] == board[rowslot+4][colslot]) {
				if(board[rowslot][colslot] == board[rowslot+6][colslot]) {
					gameend = 1;
					cout<<"Victory down"<<endl;
				}
			}
		}
	}
return gameend;
}

int play() {
int empty =0;
int gameend =0;
int choiceo;
int choicex;
int slot=2;
int mul =1;

do {
	empty =0;
	slot =2;
	mul =1;

	if(a%2 ==0) {

		cout << "Player O's turn. Pick a column to fill in." << endl;
		cin >> choiceo;

				if(choiceo ==1 || choiceo ==2 || choiceo ==3 || choiceo ==4 || choiceo ==5 || choiceo ==6 || choiceo ==7) {

					if (board[10][(2*choiceo)-1] == " " ){
						empty = 1;
						board[10][(2*choiceo)-1] = "O"; //adds an O at the desired location
						gameend = snakehoriz(10,(2*choiceo)-1);
							if (gameend == 0){
								gameend = snakeleftuprightdown(10,(2*choiceo)-1);
								if (gameend == 0){
									gameend = snakeleftdownrightup(10,(2*choiceo)-1);
								}
							}
			turns++;	}

				else {
					while(empty != 1) {
						if (board[10-(slot*mul)][(2*choiceo)-1] == " ") {
							empty = 1;
							board[10-(slot*mul)][(2*choiceo)-1] = "O";
							gameend = snakedown(10-(slot*mul),(2*choiceo)-1);
							if (gameend == 0){
								gameend = snakehoriz(10-(slot*mul),(2*choiceo)-1);
								if (gameend == 0){
								gameend = snakeleftuprightdown(10-(slot*mul),(2*choiceo)-1);
									if (gameend == 0){
										gameend = snakeleftdownrightup(10-(slot*mul),(2*choiceo)-1);
									}
								}
							}
						}
						else { mul++; // necessary to move "upwards" in the board to check for empty slots.
							}
						}
					turns++;
					}
					cout << " 1 2 3 4 5 6 7" << endl;

					for(int p=0; p<12; p++){

						for(int q=0; q<15; q++){

						cout<<board[p][q];

						}
					cout<<endl;
					}
				}
			}
	else {
			cout << "Player X's turn. Pick a column to fill in." << endl;
			cin >> choicex;

				if(choicex ==1 || choicex ==2 || choicex ==3 || choicex ==4 || choicex ==5 || choicex ==6 || choicex ==7) {

					if (board[10][(2*choicex)-1] == " " ){
						empty = 1;
						board[10][(2*choicex)-1] = "X"; //adds an X at the desired location
						gameend = snakehoriz(10,(2*choicex)-1);
						if (gameend == 0){
							gameend = snakeleftuprightdown(10,(2*choicex)-1);
							if (gameend == 0){
								gameend = snakeleftdownrightup(10,(2*choicex)-1);
							}
						}
		turns++;	}

					else {
					while(empty != 1) {
						if (board[10-(slot*mul)][(2*choicex)-1] == " ") {
							empty = 1;
							board[10-(slot*mul)][(2*choicex)-1] = "X";
							gameend = snakedown(10-(slot*mul),(2*choicex)-1);
							if (gameend == 0){
								gameend = snakehoriz(10-(slot*mul),(2*choicex)-1);
								if (gameend == 0){
								gameend = snakeleftuprightdown(10-(slot*mul),(2*choicex)-1);
									if (gameend == 0){
										gameend = snakeleftdownrightup(10-(slot*mul),(2*choicex)-1);
									}
								}
							}
						}
						else { mul++; // necessary to move "upwards" in the board to check for empty slots.
							}
						}
					turns++;
					}

					cout << " 1 2 3 4 5 6 7" << endl;

					for(int p=0; p<12; p++){

						for(int q=0; q<15; q++){

						cout<<board[p][q];

						}
					cout<<endl;
					}
				}
		}
		if(turns==42){
			gameend=1;
		}
	a++; // increments in order to satisfy the condition for player 2 to play.
	} while(gameend==0);


	cout << "Game over!" << endl;
	gameend=1;
	return 0;
}


int main() {
introduction();

cout << "Connect Four Game" << endl;
cout << " 1 2 3 4 5 6 7" << endl;

for(int m=0; m<12; m++){
	if(m%2==1) {
		for(int n=0; n <15; n++) {
			board[m][n] = "-"; // - needs to be printed out on all pair lines
		}
	}

	else {
		for(int o=0; o<15; o++) {
			if(o%2==0){
				board[m][o] = "|"; // - needs to be printed out on all odd lines.
				}
			else {
				board[m][o] = " ";
				}
			}
		}
	}

	for(int p=0; p<12; p++){
		for(int q=0; q<15; q++){
			cout<<board[p][q];
		}
		cout<<endl;
	}

play();

if(a%2==0&&turns!=42){
	cout<<"Player X wins!";
}

else if(a%2==1&&turns!=42){
	cout<<"Player O wins!";
}
else if(turns==42){
	cout<<"Tie! No one wins!";
}

return 0;

}
