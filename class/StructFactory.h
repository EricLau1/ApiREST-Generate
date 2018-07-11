#include <iostream>
#include <string>
#include "../pkg/custom.h"
using namespace std;

class StructFactory {
	
	public:
		
		string typeVar;
		string nameVar;
		
		StructFactory() {
			this->typeVar = "";
			this->nameVar = "";
		}
		
		void read() {
			
			cout << "Digite o tipo da variavel: ";
			cin >> this->typeVar;
			
			setbuf(stdin, NULL);
			
			if(this->typeVar == "float") {
				this->typeVar += "64";
			}
			
			cout << "Digite o nome da variavel: ";
			cin >> this->nameVar;
			
			this->nameVar[0] = toupper(this->nameVar[0]);
			
			setbuf(stdin, NULL);		
		}
		
		void show() {
			cout << "\n";
			cout << this->nameVar << "\t" << this->typeVar;
		}
		
		string getVarJson() {
			string n_var = this->nameVar;
			n_var[0] = tolower(n_var[0]);
			string json = "`json:";
			json += ("\"" + n_var + "\"");
			json += "`";
			
			return json;
		}	
};
