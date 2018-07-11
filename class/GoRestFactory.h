#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "StructFactory.h"
#include "MethodsFactory.h"

using namespace std;

class GoRestFactory {

	private:
		
		string document;
		vector<string> imports;
		vector<StructFactory> structs;
		string nameStruct;
		string listStruct;
	
	public:
		GoRestFactory () {
		
			initDocument();
			
			initStruct();
			
			initRoutes();
			
			initMethods();			
		}
		
		
		string initStructValues(int i) {
			
			int count = 0;
			
			string s_var = "\n\t";
			string n_var = "";
			
			while(count < i) {
					
				n_var += this->listStruct[0]; 
				
				n_var += toString(count + 1);
				
				s_var += n_var;
				s_var += " := ";
				s_var += this->nameStruct;
				s_var += "{ "; 
				
				for(int i = 0; i < this->structs.size(); i++) {
					
					if(i < this->structs.size() - 1) {
						
						s_var += typeValues(this->structs[i].typeVar);
						s_var += ", ";
							
					} else {
						s_var += typeValues(this->structs[i].typeVar);
						s_var += " ";
					}
				
				}
				
				s_var += "}";
				s_var +="\n\t";
				
				s_var += this->listStruct;
				s_var += " = append(";
				s_var += this->listStruct;
				s_var += ", ";
				s_var += n_var;
				s_var += ")\n";
				
				s_var +="\n\t";
				
				n_var = "";
				count++;	
				
			}
			
			s_var += "\tfmt.Println(";
			s_var += this->listStruct;
			s_var += ")";
			
			s_var += "\n\n";
						
			return s_var;
		}
		
		// Sobrecarga
		string initStructValues(vector<string> nameVars) {
			
			int count = 0;
			
			string s_var = "\n\t";
			
			while(count < nameVars.size()) {
								
				s_var += nameVars[count];
				s_var += " := ";
				s_var += this->nameStruct;
				s_var += "{ "; 
				
				for(int i = 0; i < this->structs.size(); i++) {
					
					if(i < this->structs.size() - 1) {
						
						s_var += typeValues(this->structs[i].typeVar);
						s_var += ", ";
							
					} else {
						s_var += typeValues(this->structs[i].typeVar);
						s_var += " ";
					}
				
				}
				
				s_var += "}";
				s_var +="\n\t";
				
				s_var += this->listStruct;
				s_var += " = append(";
				s_var += this->listStruct;
				s_var += ", ";
				s_var += nameVars[count];
				s_var += ")\n";
				
				s_var +="\n\t";
			
				count++;
			}
			
			s_var += "\n\n";			
			return s_var;
		}
		
		
		void initMethods() {
			
			MethodsFactory methods(this->nameStruct);
			
			this->document += methods.method_GET(this->listStruct);
			
			this->document += methods.method_GET_ID(this->listStruct, this->nameStruct);
			
			this->document += methods.method_POST(this->listStruct, this->nameStruct);
			
			this->document += methods.method_PUT(this->listStruct, this->nameStruct);
			
			this->document += methods.method_DELETE(this->listStruct);
		}
		
		void initRoutes() {
		
			this->document += "func main() {\n\n";
			
			this->document += "\t// gerando variaveis";
			this->document += this->initStructValues(3);
			
			MethodsFactory routes(this->nameStruct);
			
			this->document += routes.getRoutes();
			
			this->document += "\n}";
			this->document += "\n\n";
			
		}

		
		void initDocument() {
		
			this->document += "\n";
			this->document += "package main";
			this->document += "\n\n";
			
			this->imports.push_back("\t\"fmt\"");
			this->imports.push_back("\t\"log\"");
			this->imports.push_back("\t\"net/http\"");
			this->imports.push_back("\t\"encoding/json\"");
			this->imports.push_back("\t\"github.com/gorilla/mux\"");
			this->imports.push_back("\t\"io/ioutil\"");
			this->imports.push_back("\t\"strconv\"");
			
			this->document += "import(\n";
			for(int i = 0; i < this->imports.size(); i++) {
				document += this->imports[i];
				document += "\n";
			}
			this->document += ")";
			this->document += "\n\n";
		}
		
		void initStruct() {
			
			system("cls");

			cout << "Nome da estrutura: ";
			cin >> this->nameStruct;
			
			setbuf(stdin, NULL);
			
			this->nameStruct[0] = toupper(this->nameStruct[0]);
			
			this->document += "type ";
			this->document += this->nameStruct;
			this->document += " struct {\n";
			
			while(1) {
				
				cout << "\nCriando estrutura de dados" << endl;
				
				cout << "\ntype " << this->nameStruct << " struct {\n";
								
				this->showStructs();
				
				cout << "\n}\n";
				
				bar("*", 50);
					
				StructFactory sf;
				sf.read();
				
				structs.push_back(sf);
				
				if(question()) {
					system("cls");
					break;
				}
				system("cls");	
			}
			
			for(int i = 0; i < this->structs.size(); i++) {
				
				this->document += "\t";
				this->document += this->structs[i].nameVar;
				this->document += " ";
				this->document += this->structs[i].typeVar;
				this->document += " ";
				this->document += this->structs[i].getVarJson();
				this->document += "\n"; 
			}
			this->document += "}";
			this->document += "\n\n";
			
			this->document += "var ";
			
			this->listStruct = this->nameStruct;
			this->listStruct[0] = tolower(this->listStruct[0]);
			
			if(this->nameStruct[this->nameStruct.length() - 1] != 's') {
				this->listStruct += "s";
			}
			
			this->document += this->listStruct;
			this->document += " []";
			this->document += this->nameStruct;
			this->document += "\n\n";
		}
			
		void showStructs() {
			if(this->structs.size() > 0) {
				for(int i = 0; i < this->structs.size(); i++) {
					this->structs[i].show();
				}
			}
		}
		

		
		void setImports(string import) {
			this->imports.push_back(import);
		}

		vector<string> getImports() {
			return this->imports;
		}
		
		string getDocument() {
			return this->document;
		}
			
};
