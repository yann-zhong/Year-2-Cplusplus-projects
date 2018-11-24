#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<time.h>

using namespace std;

class Cell {
	
	protected:
	bool state; // Alive or dead where true is alive and false is dead
	char c; // 'O' or ' '
	unsigned int alive; // number of alive neighbours
	
	public:
	Cell(); // default constructor
	Cell(bool input, char input2); // constructor 2
	
	void set(bool input,char input2); // changes elements of cell
	bool get_state(){return state;} // gets cell state
	char get_cell(){return c;} // gets cell content
	void print(); // prints content of a cell
	
	void addalive() {alive++;} // increments every time an alive neighbour is found 
	void alivenull() {alive = 0;} // resets alive counter (more of a precaution than anything else
	virtual void birth(); // allows birth of cell
	virtual void change_states_death(); // kills a cell
	virtual void change_states_birth(); // births a cell
	virtual char return_cell_shape(); // returns 'O'
	
	~Cell();
	
};

Cell::Cell() {
	state = false;
	c = ' ';
}

Cell::Cell(bool input, char input2) {
	state = input;
	c = input2;
}

void Cell::set(bool input,char input2) {
	state = input;
	c = input2;
}

void Cell::print() {
	cout << c; 
}

void Cell::birth() { // allows birth regardless of neighbours, used in seed cells
	state = true;
	c = 'O';
}

void Cell::change_states_death() {
	switch(alive) { // one more case for death than cancer
		case 0: state = false; c= ' ';
		break;
		case 1: state = false; c= ' ';
		break;
		case 4: state = false; c= ' ';
		break;
		case 5: state = false; c= ' ';
		break;
		case 6: state = false; c= ' ';
		break;
		case 7: state = false; c= ' ';
		break;
		case 8: state = false; c= ' ';
		break;
	}
}

void Cell::change_states_birth() {
	switch(alive) {
		case 3: state = true; c= 'O';
	}
}

char Cell::return_cell_shape() {
	char O;
	O = 'O';
	return O;
}

Cell::~Cell() {
}

class Cancer: public Cell {

	public:
	void birth(); // allows birth of cell
 	void change_states_birth(); // kills a cell
	void change_states_death(); // births a cell
	char return_cell_shape(); // returns 'X'
};

void Cancer::birth(){
	state = true;
	c = 'X';
}

void Cancer::change_states_death() {
	switch(alive) { // one less case for death than cell
		case 0: state = false; c= ' ';
		break;
		case 1: state = false; c= ' ';
		break;
		case 5: state = false; c= ' ';
		break;
		case 6: state = false; c= ' ';
		break;
		case 7: state = false; c= ' ';
		break;
		case 8: state = false; c= ' ';
		break;
	}
}

void Cancer::change_states_birth() {
	switch(alive) {
		case 3: state = true; c= 'X';
	}
}

char Cancer::return_cell_shape() {
	char X;
	X = 'X';
	return X;
}

class Board { 
	
	private:
	vector< vector<Cell*> > board; // vector of vector of Cells instead of Array

	unsigned int row;
	unsigned int column;
	unsigned int boardtime;
	unsigned int cellnumber;
						
	public:	
	Board(); // default constructor
	Board(unsigned int row, unsigned int column,unsigned int selection); // constructor 1
	
	void seed_cells(unsigned int confluence); // randomizes board with cells
	unsigned int get_time(); // gets time
	unsigned int get_num_cells(); // gets number of cells
	void display(); // displays the whole board
	void next_state(); // board changes state
	
	~Board(); // destructor
	
};

Board::Board() { // default constructor - for cell 
 	row = 3;
	column = 3;
	
	Cell cell(true,'O'); // initializes a 3 by 3 alive cells board by default
	
	for(int r=0; r < row; r++) {
		vector<Cell*> row; // generate empty row
		for(int c=0; c< column; c++) {
			row.push_back(&cell); // puts cell elements in every element of the row
		}
		board.push_back(row); // puts row elements in every element of the column 
	}
	
	for(int r =0; r < row; r++) {
		for(int c=0; c< column; c++) {
				board[r][c]->print();
		}
		cout << endl;
	} 
}

Board::Board(unsigned int userrow, unsigned int usercol,unsigned int selection) {
 	
	row = userrow;
	column = usercol;
	boardtime = -1;
	if (selection == 1) {
		for(int r=0; r < row; r++) {
			vector<Cell*> row; //generate empty row
			for(int c=0; c< column; c++) {
				Cell* ptr_cell = new Cell; // pushes cell elements in 
				row.push_back(ptr_cell);
			}
			board.push_back(row);
		}
	}
	else if (selection == 2) {
		for(int r=0; r < row; r++) {
			vector<Cell*> row; //generate empty row
			for(int c=0; c< column; c++) {
				Cancer* ptr_cancer = new Cancer; // pushes cancer elements in 
				row.push_back(ptr_cancer);
			}
			board.push_back(row);
		}
	}
}

void Board::seed_cells(unsigned int confluence) { // initializes the random cells at the start
 	srand(time(NULL));
	unsigned int initcell = (row*column);
	unsigned int randrow = 0;
	unsigned int randcol = 0;
	unsigned int min = 0;
	unsigned int max = 0;
	bool state;
	char cell;
	
	initcell = (confluence*initcell)/100; // allows us to count for number of cells initialized from the confluence percentage.

	for(int n = 0; n < initcell; n++) {
		do{
			max = row - 1; // counts from 0 to n-1 where n is number of rows
			randrow = min + (rand() % (unsigned int)(max - min + 1)); // random between 0 and number of rows
			max = column - 1; // counts from 0 to n-1 where n is number of cols
			randcol = min + (rand() % (unsigned int)(max - min + 1)); // random between 0 and number of cols
			cell = board[randrow][randcol]->get_cell();
		}while(cell != ' ');
		board[randrow][randcol]->birth();
	}
}

unsigned int Board::get_time() {
	boardtime++; // adds one each loop (
	return boardtime;
}

void Board::display() {
	for(int r = 0; r < row; r++) {
			for(int c = 0; c < column; c++) {
				board[r][c]->print();
			}
			cout << endl;
		}
}

unsigned int Board::get_num_cells() {
	bool checkstate;
	cellnumber = 0;
	
		for(int r = 0; r < row; r++) {
			for(int c = 0; c < column; c++) {
				checkstate = board[r][c]->get_state();
				if(checkstate) {
					cellnumber++;
				}
			}
		}
	return cellnumber;
}

void Board::next_state() {
 	char checkcell;
	bool checkstate;
	
	for(int r = 0; r < row; r++) {
		for(int c = 0; c< column; c++) {

			board[r][c]->alivenull(); // as said earlier, reset alive counter just in case
	
			if(r>0) { // every direction (all eight) have a limiting condition for search as to not exceed size of the board
				if(board[r-1][c]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(r+1<row) {
				if(board[r+1][c]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(c>0) {
				if(board[r][c-1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(c+1<column) {
				if(board[r][c+1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(r>0&&c>0) {
				if(board[r-1][c-1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(r>0&&c+1<column) {
				if(board[r-1][c+1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(r+1<row&&c>0) {
				if(board[r+1][c-1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}
			if(r+1<row&&c+1<column) {
				if(board[r+1][c+1]->get_cell() == board[r][c]->return_cell_shape()) {
					board[r][c]->addalive();
				}
			}			
		} 	
	}

	for(int r = 0; r < row; r++) { // changes state of cells after whole board is checked
		for(int c = 0; c< column; c++) {
			checkstate = board[r][c]->get_state();
			if(checkstate) {
				board[r][c]->change_states_death(); 
			}
			else {
				board[r][c]->change_states_birth();
			}
		}
	}	
}

Board::~Board(){
}

int main() {
	
	unsigned int row = 0;
	unsigned int col = 0;
	unsigned int selection = 0;
	unsigned int confluence = 0;
	int c;

/* 	Cell cell;
	Cancer cancer; */

	cout << "Welcome to the cell simulator" << endl;
	cout << endl;
	cout << "Select your cell type: (1) normal cells or (2) cancer cells" << endl;
	while ( (selection < 1) || (selection > 2)){
		cout << ">";	
		cin >> selection;
	}
	cout << "Select your board size: number of rows: (recommended: 20)" << endl;
	while (row <= 0){
		cout << ">";	
		cin >> row;
	}
	cout << "Select your board size: number of columns: (recommended: 75)" << endl;
	while (col <= 0){
		cout << ">";	
		cin >> col;
	}
	cout << "Select the confluence percentage (%)" << endl;
	while ( (confluence <= 0) || (confluence > 100)){
		cout << ">";
		cin >> confluence;
	}
	
	Board board(row,col,selection);
	board.seed_cells(confluence);
	
 	c = cin.get();
	while(c!='q'){
		system("cls");
		cout << "time: " << board.get_time() << endl;
		cout << "number of cells: " << board.get_num_cells() << endl;
		board.display();
		c = cin.get();
		board.next_state();
	} 
	return 0;
}