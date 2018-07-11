#include <iostream>
#include <vector>
using namespace std;

class MethodsFactory {
	
	public:
		vector<string> url;
		vector<string> functions;
		string port;
				
		string name;
		string routes;
		vector<string> headers;
		
		vector<string> methods;
		
		int GET;
		int GET_ID;
		int POST;
		int PUT;
		int DELETE;
		
		MethodsFacotry() {
			
		}
		
		
		MethodsFactory(string name){
			this->port = "\":3000\"";
			this->name = name;
			this->initRoutes();
			initHeaders();
		}
		
		string method_GET(string listStruct) {
			
			string method = "\n";
			
			method += "func ";
			method += this->functions[this->GET];
			method += "(w http.ResponseWriter, r *http.Request) {";
			method += "\n";
			
			method += this->getHeadersFormat();
			
			method += "\n";
			
			method += "\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct;
			method += ")\n";
			
			method += "\n}";
			method += "\n";
			
			this->methods.push_back(method);
			
			return method;
		}
		
		string method_GET_ID(string listStruct, string nameStruct) {
			
			string method = "\n\n";
			
			method += "func ";
			method += this->functions[this->GET_ID];
			method += "(w http.ResponseWriter, r *http.Request) {";
			method += "\n";
			
			method += this->getHeadersFormat();
			
			method += "\n\n";
			
			method += "\t";
			method += "param := mux.Vars(r)";
			
			method += "\n\n";
			
			method += "\t";
			method += "id, _ := strconv.Atoi(param[\"id\"])";
			
			method += "\n\n";
			
			method += "\t";
			method += "for _,";
			method += listStruct[0];
			method += " := range ";
			method += listStruct;
			method += " {";
			method += "\n";
			
			method += "\t\t";
			method += "if ";
			method += listStruct[0];
			method += ".Id == id {\n";
			
			method += "\t\t\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct[0];
			method += ")\n";
			method += "\t\t\treturn\n";
			
			method += "\n\t\t}";
			method += "\n";
			method += "\t}\n\n";
			
			method += "\t";
			method += "json.NewEncoder(w).Encode(&";
			method += nameStruct;
			method += "{})\n\n";
			
			method +="}";
			
			this->methods.push_back(method);
			
			return method;
			
			
		}
		
		string method_POST(string listStruct, string nameStruct) {
						
			string method = "\n\n";
			
			method += "func ";
			method += this->functions[this->POST];
			method += "(w http.ResponseWriter, r *http.Request) {";
			method += "\n";
			
			method += this->getHeadersFormat();
			
			method += "\n\n";
			
			method += "\t";
			method += "var ";
			method += listStruct[0];
			method += " ";
			method += nameStruct;
			method += "\n\n";
			
			method += "\t";
			method += "body, _ := ioutil.ReadAll(r.Body)";
			method += "\n\n";
			
			method += "\t";
			method += "json.Unmarshal(body, &";
			method += listStruct[0];
			method += ")";
			method += "\n\n";
			
			method += "\t";
			method += listStruct;
			method += " = append(";
			method += listStruct;
			method += ", ";
			method += listStruct[0];
			method += ")";
			
			method += "\n\n";
			
			method += "\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct;
			method += ")\n";
			
			method += "\n}";
			method += "\n";
			
			this->methods.push_back(method);
			
			return method;
		}
		
		string method_PUT(string listStruct, string nameStruct) {
			
			string method = "\n\n";
			
			method += "func ";
			method += this->functions[this->PUT];
			method += "(w http.ResponseWriter, r *http.Request) {";
			method += "\n";
			
			method += this->getHeadersFormat();
			
			method += "\n\n";
			
			method += "\t";
			method += "param := mux.Vars(r)";
			
			method += "\n\n";
			
			method += "\t";
			method += "id, _ := strconv.Atoi(param[\"id\"])";
			
			method += "\n\n";
			
			method += "\t";
			method += "for index,";
			method += listStruct[0];
			method += " := range ";
			method += listStruct;
			method += " {";
			method += "\n";
			
			method += "\t\t";
			method += "if ";
			method += listStruct[0];
			method += ".Id == id {\n";
			
			method += "\n";
			method += "\t\t\t";
			method += listStruct;
			method += " = append(";
			method += listStruct;
			method += "[:index], ";
			method += listStruct;
			method += "[index + 1:]...)";
			method += "\n\n";
			
			method += "\t\t\t";
			method += "var ";
			method += listStruct[0];
			method += " ";
			method += nameStruct;
			method += "\n";
			
			method += "\t\t\t";
			method += "_ = json.NewDecoder(r.Body).Decode(&";
			method += listStruct[0];
			method += ")";
			method += "\n";
			
			method += "\t\t\t";
			method += listStruct;
			method += " = append(";
			method += listStruct;
			method += ", ";
			method += listStruct[0];
			method += ")";
			
			method += "\n";
			method += "\t\t\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct[0];
			method += ")\n";
			method += "\t\t\treturn\n";
			
			method += "\n\t\t}";
			method += "\n";
			method += "\t}\n\n";
			
			method += "\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct;
			method += ")";
			method += "\n\n";
			
			method +="}";
			
			this->methods.push_back(method);
			
			return method;
			
		}
		
		string method_DELETE(string listStruct) {
			
			string method = "\n\n";
			
			method += "func ";
			method += this->functions[this->DELETE];
			method += "(w http.ResponseWriter, r *http.Request) {";
			method += "\n";
			
			method += this->getHeadersFormat();
			
			method += "\n\n";
			
			method += "\t";
			method += "param := mux.Vars(r)";
			
			method += "\n\n";
			
			method += "\t";
			method += "id, _ := strconv.Atoi(param[\"id\"])";
			
			method += "\n\n";
			
			method += "\t";
			method += "for index,";
			method += listStruct[0];
			method += " := range ";
			method += listStruct;
			method += " {";
			method += "\n";
			
			method += "\t\t";
			method += "if ";
			method += listStruct[0];
			method += ".Id == id {\n";
			
			method += "\n";
			method += "\t\t\t";
			method += listStruct;
			method += " = append(";
			method += listStruct;
			method += "[:index], ";
			method += listStruct;
			method += "[index + 1:]...)";
			method += "\n\n";
			
			method += "\n";
			method += "\t\t\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct;
			method += ")\n";
			method += "\t\t\treturn\n";
			
			method += "\n\t\t}";
			method += "\n";
			method += "\t}\n\n";
			
			method += "\t";
			method += "json.NewEncoder(w).Encode(";
			method += listStruct;
			method += ")";
			method += "\n\n";
			
			method +="}";
			
			this->methods.push_back(method);
			
			return method;
			
		}
		
		void initHeaders() {
			this->headers.push_back("w.Header().Set(\"Content-Type\", \"application/json\")");
			this->headers.push_back("w.Header().Set(\"Access-Control-Allow-Origin\", \"*\")");
		}
		
		string getHeadersFormat() {
			string header = "\n";
			
			for(int i = 0; i < this->headers.size(); i++) {
				header += "\t";
				header += this->headers[i];
				header += "\n";
			}
			
			return header;
		}
		
		void initRoutes() {
			
			this->routes = "\troute := mux.NewRouter().StrictSlash(true)";
			
			this->routes += "\n\n";
			this->routes += "\t";
			this->routes += "route.HandleFunc(";
			
			// Metodo GET
			this->GET = 0;
			string param = "\"/";
			param += this->format(2);
			param += "\"";
			this->url.push_back(param);
			
			this->routes += this->url[this->GET];
			this->routes += ", ";
			
			param = "get";
			param += this->format(1);
			
			this->functions.push_back(param);
			
			this->routes += param;
			this->routes += ").Methods(\"GET\")";
			
			this->routes += "\n\n";
			
			// Metodo GET id
			this->GET_ID = 1;
			this->routes += "\t";
			this->routes += "route.HandleFunc(";		
			param = "\"/";
			param += this->format(2);
			param += "/{id}";
			param += "\"";
			this->url.push_back(param);
			
			this->routes += this->url[this->GET_ID];
			this->routes += ", ";
			
			param = "get";
			param += this->name;
			
			this->functions.push_back(param);
			
			this->routes += param;
			this->routes += ").Methods(\"GET\")";
			
			this->routes += "\n\n";
			
			// Metodo POST
			this->POST = 2;
			this->routes += "\t";
			this->routes += "route.HandleFunc(";		
			param = "\"/";
			param += this->format(2);
			param += "\"";
			this->url.push_back(param);
			
			this->routes += this->url[this->POST];
			this->routes += ", ";
			
			param = "post";
			param += this->name;
			
			this->functions.push_back(param);
			
			this->routes += param;
			this->routes += ").Methods(\"POST\")";
			
			this->routes += "\n\n";
			
		    // Metodo PUT
		    this->PUT = 3;
			this->routes += "\t";
			this->routes += "route.HandleFunc(";		
			param = "\"/";
			param += this->format(2);
			param += "/update/{id}";
			param += "\"";
			this->url.push_back(param);
			
			this->routes += this->url[this->PUT];
			this->routes += ", ";
			
			param = "put";
			param += this->name;
			
			this->functions.push_back(param);
			
			this->routes += param;
			this->routes += ").Methods(\"PUT\")";
			
			this->routes += "\n\n";
			
			// Metodo DELETE
			this->DELETE = 4;
			this->routes += "\t";
			this->routes += "route.HandleFunc(";		
			param = "\"/";
			param += this->format(2);
			param += "/delete/{id}";
			param += "\"";
			this->url.push_back(param);
			
			this->routes += this->url[this->DELETE];
			this->routes += ", ";
			
			param = "delete";
			param += this->name;
			
			this->functions.push_back(param);
			
			this->routes += param;
			this->routes += ").Methods(\"DELETE\")";
			
			this->routes += "\n\n";
		
			setbuf(stdin, NULL);
			
			this->routes += "\tlog.Fatal(http.ListenAndServe(";
			this->routes += this->port;
			this->routes += ", route))";
			
			this->routes += "\n\n";
		}
		
		
		string getRoutes() {
			return this->routes;
		}
		
		vector<string> getUrls() {
			return this->url;
		}
		
		vector<string> getFunctions() {
			return this->functions;
		}
		
				string format(int value) {
			string text = this->name;
			if(value == 1) {
				text += "s";
			} else if (value == 2) {
				text += "s";
				for(int i = 0; i < text.length(); i++) {
					text[i] = tolower(text[i]);
				}
			}
			return text;
		}
		
};
