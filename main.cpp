#include <iostream>
#include "class/GoRestFactory.h"
#include <fstream>

using namespace std;

void generateRest(string content);

int main() {
	
	//Gerar Api Rest em Go  
	
	GoRestFactory grf;

	cout << grf.getDocument() << endl;
	
	generateRest(grf.getDocument());
	
	return 0;
}

void generateRest(string content) {
		
	
	string rest = "myRest.go";
	
	ofstream file(rest.c_str());
	
	file << content;
	
	file.close();
	
	cout << "\nWeb Server Rest gerado com sucesso!";	
}
