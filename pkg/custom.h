#include <iostream>
#include <stdlib.h>	 // função rand, srand
#include <time.h>	// função time
#include <sstream>	// classe ostringstream
#include <iomanip> // função setprecision
using namespace std;

string toString(int);
string toString(float);

bool question() {
	char r;
	cout << "Stop? (Y/n) ";
	cin >> r;
	
	r = tolower(r);
	
	if(r != 'n') {
		return true;
	}
	return false;
}

void bar(string symbol, int repeat) {
	cout << "\n";
	for(int i = 0; i < repeat; i++) {
		cout << symbol;
	}
	cout << "\n";
}

string typeValues(string type) {
	
	string value = "";
	
	srand(time(NULL));
	
    if(type == "int") {
    	 
		value += "0";
		
	} else if (type == "float64"){
		
		float rd = (float)rand() / RAND_MAX;
		int ri = rand() % 100;
		
		value += toString(ri);
		value += toString(rd);
		
	} else {
		value += "\"text\"";
	}
	return value;
}

string toString(int val) {
	ostringstream ss;
	ss << val;
	return ss.str();
}

string toString(float val) {
	ostringstream ss;
	ss << setprecision(2) << val;
	return ss.str();
}
