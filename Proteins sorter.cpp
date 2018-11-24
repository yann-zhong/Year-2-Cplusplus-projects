#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

struct protein {
		unsigned int itemid;
		vector<char> vgiid;
		vector<char> vrefid;
		vector<char> vname;
		vector<char> vsequence;
		unsigned int aminocount; // counts the number of amino acids
		unsigned int acount; // acount to vcount are for the protein statistics
		unsigned int rcount;
		unsigned int ncount;
		unsigned int dcount;
		unsigned int bcount;
		unsigned int ccount;
		unsigned int qcount;
		unsigned int ecount;
		unsigned int gcount;
		unsigned int hcount;
		unsigned int icount;
		unsigned int lcount;
		unsigned int kcount;
		unsigned int mcount;
		unsigned int fcount;
		unsigned int pcount;
		unsigned int scount;
		unsigned int tcount;
		unsigned int wcount;
		unsigned int ycount;
		unsigned int vcount;
		unsigned int zcount;
		unsigned int xcount;
		
};

string choosefile();
void getfile(ifstream&); //opens abridged or complete database
int mainmenu(); //to choose option
int proteincheck(ifstream&); //counts number of proteins
void aminoacids(); //displays all amino acids
protein searchitem(ifstream&,protein); //searches for item id and returns protein info
protein searchgi(ifstream&,protein); //searches for gi id and returns protein info
protein searchref(ifstream&,protein); //searches for ref id and returns protein info
protein searchkeyword(ifstream&,protein); //searches for keyword and returns protein info
void searchhit(protein); // allows all info to be displayed on a specific protein

int main()
{
    ifstream file;
	int m = -1;
	protein protein;
	protein.itemid = 0;
	protein.aminocount = 0;
	protein.acount = 0, protein.rcount = 0,protein.ncount = 0,protein.dcount = 0,protein.bcount = 0;
	protein.ccount = 0, protein.qcount = 0,protein.ecount = 0,protein.gcount = 0,protein.hcount = 0;
	protein.icount = 0, protein.lcount = 0,protein.kcount = 0,protein.mcount = 0,protein.fcount = 0;
	protein.pcount = 0, protein.scount = 0,protein.tcount = 0,protein.wcount = 0,protein.ycount = 0;
	protein.vcount = 0, protein.zcount = 0,protein.xcount = 0;
	
    getfile(file);//opens either abridged or complete database
	m = mainmenu();
	
	if (m == 1) {
		aminoacids();//displays the amino acid table
		proteincheck(file);//checks numbers of proteins
    }
	
	else if (m==2) {
		protein = searchitem(file,protein);//runs function to search for item ID
		searchhit(protein);
	}
	
	else if (m ==3) {
		protein = searchgi(file,protein);//runs function to search for GI ID
		searchhit(protein);
	}
	
	else if (m==4) {
		protein = searchref(file,protein);//runs function to search for reference ID
		searchhit(protein);
	}
	
	else if (m==5) {
		protein = searchkeyword(file,protein);
		searchhit(protein);
	}
	
	else if(m==6) {
		cout << "Exiting the database." << endl;
		exit(EXIT_FAILURE); //exits the program
	}
	file.close();

}

string choosefile()
{
	string filename;
	int firstchoice = 0;
	
	cout << "Welcome. Would you like to use the abridged database (1) or the complete database (2)?" << endl;
	cin >> firstchoice; 
	
	if(firstchoice == 1) {
		filename = "protein_a.fa";
		return filename;
	}
	
	else if(firstchoice == 2) {
		filename = "protein_c.fa";
		return filename;
	}

}

void getfile(ifstream& file)
{
	string filename;
	filename = choosefile();
    file.open(filename.c_str());
}

int mainmenu() {
	
	int secondchoice = 0;
	
	cout << " Please select one of the options below:" << endl;
	cout << " 1.Overview of the database" << endl;
	cout << " 2.Search by item id" << endl;
	cout << " 3.Search by gi id" << endl;
	cout << " 4.Search by ref id" << endl;
	cout << " 5.Search by keyword" << endl;
	cout << " 6.Quit the program" << endl;
	cout << endl;
	cin >> secondchoice;
	
	return secondchoice;
	
}

int proteincheck(ifstream& file) {
	
	char c;
	int protcount = 0;
	
	while(file.get(c)) {        
		if(c == '>') { // > is at the start of every protein
			protcount++;
		}
	}	
	
	cout << "This database has " << protcount << " proteins." << endl;
	file.close();	
	return protcount;
	
}

void aminoacids() {
	
	cout << "      	Amino acids and their abbreviations" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << " A = Alanine		| R = Arginine" << endl;
	cout << " N = Asparagine		| D = Aspartic acid" << endl;
	cout << " C = Cysteine		| Q = Glutamine" << endl;
	cout << " E = Glutamic Acid	| G = Glycine" << endl;
	cout << " H = Histidine		| I = Isoleucine" << endl;
	cout << " L = Leucine		| K = Lysine" << endl;
	cout << " M = Methionine		| F = Phenylalanine" << endl;
	cout << " P = Proline		| S = Serine" << endl;
	cout << " T = Threonine		| W = Tryptophan" << endl;
	cout << " Y = Tyrosine		| V = Valine" << endl;
	cout << " Z = Glutamate/Glutamine| B = Aspartate/Asparagine" << endl;
	cout << " * = Translation stop	| - = Gap of indeterminate length" << endl;
	cout << " X = Any		|";
	cout << endl;
}

protein searchitem(ifstream& file,protein protein) {
	
	int itemid;
	unsigned int searchvalid;
	char c = '>'; // char indicating start of a protein
	int cnumber = 0;
	string line;
	char d;
	unsigned int m = 4; //increment for ref id
	unsigned int l; //increment for protein name
	string test;
	
	cout << "Please enter the item ID of the protein you'd like to search for." << endl;
	cin >> itemid;
	
	protein.itemid = itemid;
	
	do {
		getline(file,line);
		searchvalid = line.find(c); //find returns an unsigned integer which is the position of the character found
			if (searchvalid != string::npos) {	//npos is the "end of the string" so if search is valid then returned value is anything but npos
			cnumber++; // counts which protein number we are at
			}
	}while(cnumber != itemid); //at this point, stops getting line due to having found the < character.
	
	for(int n = 4; n<line.length();n++){ // we count from 4 as the | character is a position 3.
		d = line[n];
		m++; // note it is already at 4 so increments along as n increments
		if(d == '|') {
			break;
		}
		protein.vgiid.push_back(d); // GI ID is now assigned to this particular vector.
	}
	
	for(m = m+4; m<line.length();m++){ // we count from m+4 as ref id comes in 4 characters after giid.
		d = line[m]; 
		l = m;
		if(d == '|') {
			break;
		}
		protein.vrefid.push_back(d); // ref ID is now assigned to this particular vector.
	}
	
	for(l = l+2; l<line.length();l++){ // we count from l+2 as name comes in 2 characters after ref id.
		d = line[l]; 
		protein.vname.push_back(d); // Name is now in this vector.
	}
	
	//searchvalid = 1;

	do {
		getline(file,line);
		for(int z = 0; z<line.length();z++) {
			if(d == '>') {
				break; // this was necessary as the vector would take in one line extra.
			}
			d = line[z];
			
			switch(d) {
				case 'A': protein.acount++;protein.aminocount++;
				break;
				case 'R': protein.rcount++;protein.aminocount++;
				break;
				case 'N': protein.ncount++;protein.aminocount++;
				break;
				case 'D': protein.dcount++;protein.aminocount++;
				break;
				case 'C': protein.ccount++;protein.aminocount++;
				break;
				case 'Q': protein.qcount++;protein.aminocount++;
				break;
				case 'E': protein.ecount++;protein.aminocount++;
				break;
				case 'G': protein.gcount++;protein.aminocount++;
				break;
				case 'H': protein.hcount++;protein.aminocount++;
				break;
				case 'I': protein.icount++;protein.aminocount++;
				break;
				case 'L': protein.lcount++;protein.aminocount++;
				break;
				case 'K': protein.kcount++;protein.aminocount++;
				break;
				case 'M': protein.mcount++;protein.aminocount++;
				break;
				case 'F': protein.fcount++;protein.aminocount++;
				break;
				case 'P': protein.pcount++;protein.aminocount++;
				break;
				case 'S': protein.scount++;protein.aminocount++;
				break;
				case 'T': protein.tcount++;protein.aminocount++;
				break;
				case 'W': protein.wcount++;protein.aminocount++;
				break;
				case 'Y': protein.ycount++;protein.aminocount++;
				break;
				case 'V': protein.vcount++;protein.aminocount++;
				break;
				case 'Z': protein.zcount++;protein.aminocount++;
				break;
				case 'B': protein.bcount++;protein.aminocount++;
				break;
				case 'X': protein.xcount++;protein.aminocount++;
				break;
			}
			
			protein.vsequence.push_back(d); // issue: gets one extra line into vsequence
		}
		searchvalid = line.find(c);
	}while(searchvalid != 0);//< is at the 0th position so as long as it isn't found then 0 will not be returned.
	protein.vsequence.pop_back(); //removes extra ">".
	
	return protein;
		
}

protein searchgi(ifstream& file,protein protein) {
	
	string giid;
	unsigned int searchvalid;
	unsigned int searchvalid2;
	string line;
	char c = '>';
	char d;
	unsigned int m = 4; //increment for ref id
	unsigned int l; //increment for protein name
	
	cout << "Please enter the GI ID of the protein you'd like to search for." << endl;
	cin >> giid;
	
	while(getline(file,line)) {
		searchvalid2 = line.find(c);
			if (searchvalid2 != string::npos) {
			protein.itemid++; // increases to get item ID
			}
		searchvalid = line.find(giid); // as above
			if(searchvalid != string::npos) {
				break;
		}
	}
		for(int n = 4; n<line.length();n++){ // we count from 4 as the | character is a position 3.
		d = line[n];
		m++; // note it is already at 4 so increments along as n increments
		if(d == '|') {
			break;
		}
		protein.vgiid.push_back(d); // GI ID is now assigned to this particular vector.
	}
	
	for(m = m+4; m<line.length();m++){ // we count from m+4 as ref id comes in 4 characters after giid.
		d = line[m]; 
		l = m;
		if(d == '|') {
			break;
		}
		protein.vrefid.push_back(d); // ref ID is now assigned to this particular vector.
	}
	
	for(l = l+2; l<line.length();l++){ // we count from l+2 as name comes in 2 characters after ref id.
		d = line[l]; 
		protein.vname.push_back(d); // Name is now in this vector.
	}

	do {
		getline(file,line);
		for(int z = 0; z<line.length();z++) {
			if(d == '>') {
				break; // this was necessary as the vector would take in one line extra.
			}
			d = line[z];	
			
			switch(d) {
				case 'A': protein.acount++;protein.aminocount++;
				break;
				case 'R': protein.rcount++;protein.aminocount++;
				break;
				case 'N': protein.ncount++;protein.aminocount++;
				break;
				case 'D': protein.dcount++;protein.aminocount++;
				break;
				case 'C': protein.ccount++;protein.aminocount++;
				break;
				case 'Q': protein.qcount++;protein.aminocount++;
				break;
				case 'E': protein.ecount++;protein.aminocount++;
				break;
				case 'G': protein.gcount++;protein.aminocount++;
				break;
				case 'H': protein.hcount++;protein.aminocount++;
				break;
				case 'I': protein.icount++;protein.aminocount++;
				break;
				case 'L': protein.lcount++;protein.aminocount++;
				break;
				case 'K': protein.kcount++;protein.aminocount++;
				break;
				case 'M': protein.mcount++;protein.aminocount++;
				break;
				case 'F': protein.fcount++;protein.aminocount++;
				break;
				case 'P': protein.pcount++;protein.aminocount++;
				break;
				case 'S': protein.scount++;protein.aminocount++;
				break;
				case 'T': protein.tcount++;protein.aminocount++;
				break;
				case 'W': protein.wcount++;protein.aminocount++;
				break;
				case 'Y': protein.ycount++;protein.aminocount++;
				break;
				case 'V': protein.vcount++;protein.aminocount++;
				break;
				case 'Z': protein.zcount++;protein.aminocount++;
				break;
				case 'B': protein.bcount++;protein.aminocount++;
				break;
				case 'X': protein.xcount++;protein.aminocount++;
				break;
			}
			
			protein.vsequence.push_back(d); // issue: gets one extra line into vsequence
		}
		searchvalid = line.find(c);
	}while(searchvalid != 0);//< is at the 0th position so as long as it isn't found then 0 will not be returned.
	protein.vsequence.pop_back();
	
	return protein;
}

protein searchref(ifstream& file,protein protein) {
	
	string refid;
	unsigned int searchvalid;
	unsigned int searchvalid2;
	string line;
	char c = '>';
	char d;
	unsigned int m = 4; //increment for ref id
	unsigned int l; //increment for protein name
	
	cout << "Please enter the reference id of the protein you'd like to search for." << endl;
	cin >> refid;
	
	while(getline(file,line)) {
		searchvalid2 = line.find(c);
			if (searchvalid2 != string::npos) {
			protein.itemid++; // increases to get item ID
			}
		searchvalid = line.find(refid); // as above 
			if(searchvalid != string::npos) {
				break;
			}
	}
	
	for(int n = 4; n<line.length();n++){ // we count from 4 as the | character is a position 3.
		d = line[n];
		m++; // note it is already at 4 so increments along as n increments
		if(d == '|') {
			break;
		}
		protein.vgiid.push_back(d); // GI ID is now assigned to this particular vector.
	}
	
	for(m = m+4; m<line.length();m++){ // we count from m+4 as ref id comes in 4 characters after giid.
		d = line[m]; 
		l = m;
		if(d == '|') {
			break;
		}
		protein.vrefid.push_back(d); // ref ID is now assigned to this particular vector.
	}
	
	for(l = l+2; l<line.length();l++){ // we count from l+2 as name comes in 2 characters after ref id.
		d = line[l]; 
		protein.vname.push_back(d); // Name is now in this vector.
	}
	
	//searchvalid = 1;

	do {
		getline(file,line);
		for(int z = 0; z<line.length();z++) {
			if(d == '>') {
				break; // this was necessary as the vector would take in one line extra.
			}
			d = line[z];	
			
			switch(d) {
				case 'A': protein.acount++;protein.aminocount++;
				break;
				case 'R': protein.rcount++;protein.aminocount++;
				break;
				case 'N': protein.ncount++;protein.aminocount++;
				break;
				case 'D': protein.dcount++;protein.aminocount++;
				break;
				case 'C': protein.ccount++;protein.aminocount++;
				break;
				case 'Q': protein.qcount++;protein.aminocount++;
				break;
				case 'E': protein.ecount++;protein.aminocount++;
				break;
				case 'G': protein.gcount++;protein.aminocount++;
				break;
				case 'H': protein.hcount++;protein.aminocount++;
				break;
				case 'I': protein.icount++;protein.aminocount++;
				break;
				case 'L': protein.lcount++;protein.aminocount++;
				break;
				case 'K': protein.kcount++;protein.aminocount++;
				break;
				case 'M': protein.mcount++;protein.aminocount++;
				break;
				case 'F': protein.fcount++;protein.aminocount++;
				break;
				case 'P': protein.pcount++;protein.aminocount++;
				break;
				case 'S': protein.scount++;protein.aminocount++;
				break;
				case 'T': protein.tcount++;protein.aminocount++;
				break;
				case 'W': protein.wcount++;protein.aminocount++;
				break;
				case 'Y': protein.ycount++;protein.aminocount++;
				break;
				case 'V': protein.vcount++;protein.aminocount++;
				break;
				case 'Z': protein.zcount++;protein.aminocount++;
				break;
				case 'B': protein.bcount++;protein.aminocount++;
				break;
				case 'X': protein.xcount++;protein.aminocount++;
				break;
			}
			protein.vsequence.push_back(d); // issue: gets one extra line into vsequence
		}
		searchvalid = line.find(c);
	}while(searchvalid != 0);//< is at the 0th position so as long as it isn't found then 0 will not be returned.
	protein.vsequence.pop_back();

	return protein;
}

protein searchkeyword(ifstream& file,protein protein) {
	string keywordsearch;
	unsigned int matches = 0;
	unsigned int proteinid;
	unsigned int searchvalid;
	unsigned int searchvalid2;
	unsigned int searchvalid3;
	string line;
	char c = '>';
	char d;
	unsigned int m = 4; //increment for ref id
	unsigned int l; //increment for protein name
	
	cout << "Please enter the keyword associated to the protein you'd like to search for." << endl;
	cin >> keywordsearch;
	
	while(getline(file,line)) {
		searchvalid3 = line.find(c);
			if (searchvalid3 != string::npos) {
			protein.itemid++; // increases to get item ID
			}
		searchvalid = line.find(keywordsearch); // as above 
			if(searchvalid != string::npos) {
				matches++;
				cout << "Match number " << matches << " :" << endl;
				cout << line << endl;
				cout << endl;
			}
	}
	cout << "Number of matches:" << matches << endl;
	
	cout << endl;
	cout << "Would you like to access one of the proteins displayed above? If yes, please type in the match number. If not, please type 0. You will be brought back to the main menu." << endl;
	cin >> proteinid;
	
	if(proteinid == 0) {
		main();
	}
	
	matches = 0; //resets so can count again
	file.clear(); 
	file.seekg(0, ios::beg); //resets to start of file
	
	do {
		getline(file,line);
		searchvalid = line.find(keywordsearch);
		searchvalid2 = line.find(c); //find returns an unsigned integer which is the position of the character found
			if (searchvalid != string::npos && searchvalid2 != string::npos) {	
			matches++; // counts up when keyword is matched and protein is matched
			}
	}while(matches != proteinid);
	
	for(int n = 4; n<line.length();n++){ // we count from 4 as the | character is a position 3.
		d = line[n];
		m++; // note it is already at 4 so increments along as n increments
		if(d == '|') {
			break;
		}
		protein.vgiid.push_back(d); // GI ID is now assigned to this particular vector.
	}
	
	for(m = m+4; m<line.length();m++){ // we count from m+4 as ref id comes in 4 characters after giid.
		d = line[m]; 
		l = m;
		if(d == '|') {
			break;
		}
		protein.vrefid.push_back(d); // ref ID is now assigned to this particular vector.
	}
	
	for(l = l+2; l<line.length();l++){ // we count from l+2 as name comes in 2 characters after ref id.
		d = line[l]; 
		protein.vname.push_back(d); // Name is now in this vector.
	}
	
	//searchvalid = 1;

	do {
		getline(file,line);
		for(int z = 0; z<line.length();z++) {
			if(d == '>') {
				break; // this was necessary as the vector would take in one line extra.
			}
			d = line[z];	
			
			switch(d) {
				case 'A': protein.acount++;protein.aminocount++;
				break;
				case 'R': protein.rcount++;protein.aminocount++;
				break;
				case 'N': protein.ncount++;protein.aminocount++;
				break;
				case 'D': protein.dcount++;protein.aminocount++;
				break;
				case 'C': protein.ccount++;protein.aminocount++;
				break;
				case 'Q': protein.qcount++;protein.aminocount++;
				break;
				case 'E': protein.ecount++;protein.aminocount++;
				break;
				case 'G': protein.gcount++;protein.aminocount++;
				break;
				case 'H': protein.hcount++;protein.aminocount++;
				break;
				case 'I': protein.icount++;protein.aminocount++;
				break;
				case 'L': protein.lcount++;protein.aminocount++;
				break;
				case 'K': protein.kcount++;protein.aminocount++;
				break;
				case 'M': protein.mcount++;protein.aminocount++;
				break;
				case 'F': protein.fcount++;protein.aminocount++;
				break;
				case 'P': protein.pcount++;protein.aminocount++;
				break;
				case 'S': protein.scount++;protein.aminocount++;
				break;
				case 'T': protein.tcount++;protein.aminocount++;
				break;
				case 'W': protein.wcount++;protein.aminocount++;
				break;
				case 'Y': protein.ycount++;protein.aminocount++;
				break;
				case 'V': protein.vcount++;protein.aminocount++;
				break;
				case 'Z': protein.zcount++;protein.aminocount++;
				break;
				case 'B': protein.bcount++;protein.aminocount++;
				break;
				case 'X': protein.xcount++;protein.aminocount++;
				break;
			}
			protein.vsequence.push_back(d); // issue: gets one extra line into vsequence
		}
		searchvalid = line.find(c);
	}while(searchvalid != 0);//< is at the 0th position so as long as it isn't found then 0 will not be returned.
	protein.vsequence.pop_back();
	
	return protein;
}

void searchhit(protein protein) {
	int choicehit;
	ofstream ofile;
	ofile.open("selected_proteins.txt");
	
	cout << "Your search yielded a result! What would you like to do?" << endl;
	
	while(choicehit != 0) {
	cout << endl;
	cout << " 1.Description of the protein" << endl;
	cout << " 2.Protein sequence" << endl;
	cout << " 3.Protein statistics" << endl;
	cout << " 4.Record protein to file" << endl;
	cout << " 5.Return to main menu" << endl;
	cin >> choicehit;
	
		if(choicehit == 1){
			
		cout << "The protein ID is " << protein.itemid << endl;
		cout << "The GI ID for your protein is "; // prints out gi id
			for(int i = 0; i<protein.vgiid.size();i++){
			cout << protein.vgiid[i];
			}
		cout << endl;
		cout << "The ref ID for your protein is "; // prints out ref id
			for(int i = 0; i<protein.vrefid.size();i++){
		cout << protein.vrefid[i];
			}
		cout << endl;
		cout << "The name for your protein is "; // prints out name
			for(int i = 0; i<protein.vname.size();i++){
		cout << protein.vname[i];
			}
		cout << endl;
		}
	
		else if(choicehit == 2) {
		cout << "The sequence for your protein is " << endl; // prints out sequence
			for(int i = 0; i<protein.vsequence.size();i++){
		cout << protein.vsequence[i];
			}
		}
	
		else if(choicehit == 3) {
		cout << "Below, a breakdown of the number of amino acids in your protein:" << endl;

		cout << "Total number of amino acids: " << protein.aminocount << endl;
		cout << "A:" << protein.acount << "	" << "R:" << protein.rcount << endl;
		cout << "N:" << protein.ncount << "	" << "D:" << protein.dcount << endl;
		cout << "C:" << protein.ccount << "	" << "Q:" << protein.qcount << endl;
		cout << "E:" << protein.ecount << "	" << "G:" << protein.gcount << endl;
		cout << "H:" << protein.hcount << "	" << "I:" << protein.icount << endl;
		cout << "L:" << protein.lcount << "	" << "K:" << protein.kcount << endl;
		cout << "M:" << protein.mcount << "	" << "F:" << protein.fcount << endl;
		cout << "P:" << protein.pcount << "	" << "S:" << protein.scount << endl;
		cout << "T:" << protein.tcount << "	" << "W:" << protein.wcount << endl;
		cout << "Y:" << protein.ycount << "	" << "V:" << protein.vcount << endl;
		cout << "Z:" << protein.zcount << "	" << "B:" << protein.bcount << endl;
		cout << "X:" << protein.xcount << endl;
		} 
	
		else if(choicehit == 4) { // writes everything to selected_proteins.txt (overwrites any previous write in)
			ofile << "Protein GI ID:" << endl;
			for(int i = 0; i<protein.vgiid.size();i++){
			ofile << protein.vgiid[i];
			}
			ofile << endl;
		
			ofile << "Protein ref ID:" << endl;
			for(int i = 0; i<protein.vrefid.size();i++){
			ofile << protein.vrefid[i];
			}
			ofile << endl;
		
			ofile << "Protein name:" << endl;
			for(int i = 0; i<protein.vname.size();i++){
			ofile << protein.vname[i];
			}
			ofile << endl;
		
			ofile << "Protein sequence:" << endl;
			for(int i = 0; i<protein.vsequence.size();i++){
			ofile << protein.vsequence[i];
			}
		
			ofile << endl;
			cout << "The protein was written to the file." << endl;
		
		}
	
		else if(choicehit == 5) {
			main(); // returns to main menu
		}
	
	}
}