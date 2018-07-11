
package main

import(
	"fmt"
	"log"
	"net/http"
	"encoding/json"
	"github.com/gorilla/mux"
	"io/ioutil"
	"strconv"
)

type User struct {
	Id int `json:"id"`
	Name string `json:"name"`
}

var users []User

func main() {

	// gerando variaveis
	u1 := User{ 0, "text" }
	users = append(users, u1)

	u2 := User{ 0, "text" }
	users = append(users, u2)

	u3 := User{ 0, "text" }
	users = append(users, u3)

		fmt.Println(users)

	route := mux.NewRouter().StrictSlash(true)

	route.HandleFunc("/users", getUsers).Methods("GET")

	route.HandleFunc("/users/{id}", getUser).Methods("GET")

	route.HandleFunc("/users", postUser).Methods("POST")

	route.HandleFunc("/users/update/{id}", putUser).Methods("PUT")

	route.HandleFunc("/users/delete/{id}", deleteUser).Methods("DELETE")

	log.Fatal(http.ListenAndServe(":3000", route))


}


func getUsers(w http.ResponseWriter, r *http.Request) {

	w.Header().Set("Content-Type", "application/json")
	w.Header().Set("Access-Control-Allow-Origin", "*")

	json.NewEncoder(w).Encode(users)

}


func getUser(w http.ResponseWriter, r *http.Request) {

	w.Header().Set("Content-Type", "application/json")
	w.Header().Set("Access-Control-Allow-Origin", "*")


	param := mux.Vars(r)

	id, _ := strconv.Atoi(param["id"])

	for _,u := range users {
		if u.Id == id {
			json.NewEncoder(w).Encode(u)
			return

		}
	}

	json.NewEncoder(w).Encode(&User{})

}

func postUser(w http.ResponseWriter, r *http.Request) {

	w.Header().Set("Content-Type", "application/json")
	w.Header().Set("Access-Control-Allow-Origin", "*")


	var u User

	body, _ := ioutil.ReadAll(r.Body)

	json.Unmarshal(body, &u)

	users = append(users, u)

	json.NewEncoder(w).Encode(users)

}


func putUser(w http.ResponseWriter, r *http.Request) {

	w.Header().Set("Content-Type", "application/json")
	w.Header().Set("Access-Control-Allow-Origin", "*")


	param := mux.Vars(r)

	id, _ := strconv.Atoi(param["id"])

	for index,u := range users {
		if u.Id == id {

			users = append(users[:index], users[index + 1:]...)

			var u User
			_ = json.NewDecoder(r.Body).Decode(&u)
			users = append(users, u)
			json.NewEncoder(w).Encode(u)
			return

		}
	}

	json.NewEncoder(w).Encode(users)

}

func deleteUser(w http.ResponseWriter, r *http.Request) {

	w.Header().Set("Content-Type", "application/json")
	w.Header().Set("Access-Control-Allow-Origin", "*")


	param := mux.Vars(r)

	id, _ := strconv.Atoi(param["id"])

	for index,u := range users {
		if u.Id == id {

			users = append(users[:index], users[index + 1:]...)


			json.NewEncoder(w).Encode(users)
			return

		}
	}

	json.NewEncoder(w).Encode(users)

}