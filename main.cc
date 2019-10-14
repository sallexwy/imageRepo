#include "include/repo.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

long userId = 50000; //account ids start form 50000s
bool loggedIn = false;
string ACCOUNT = "ACCOUNT"; //creating an account
string ACCINFO = "ACCINFO"; //an account's information
string ADD = "ADD"; //add command
string SEARCH = "SEARCH"; //view command
string QUIT = "QUIT";

//reads from a file with welcome messages to output to the user
void welcome(){
	ifstream welcomeFile ("literal/welcomeNote.txt");
	string line;
	while (getline (welcomeFile, line)){
		cout << line << endl;
	}
}

//issue actions associated with command with a user
void dispatchCommand(string cmd, Repo * repository){
	if (cmd == ADD){
		int amount;//amount of images inserted
		string addr;
		string name;
		cout << "How many images?" << endl;
		cin >> amount;
		while (amount > 0){
			cout << "image name:" << endl;
			cin >> name;
			cout << "image address:" << endl;;
			cin >> addr;
            repository->addImage(name, addr);
			--amount;

		}
	}
	else if (cmd == SEARCH){
		//get the user's choice for image
		string name;
		cout << "What is the name of the image you wish to view?" << endl;
		cin >> name;
		repository->searchImageByName(name);
	}
	else if (cmd == ACCOUNT){
		string userName;
		string password;
		cout << "What would you like your username to be?" << endl;
		cin >> userName;
		cout << "Please enter a password: " << endl;
		cin >> password;
        repository->addUser (userName, password);
		loggedIn = true;

	}
	else if (cmd == ACCINFO){
		repository->displayAccountInfo();
	}
	else {
		cout << "invalid command, please try again" << endl;
	}
}


int main(){
	string command;
	welcome(); 
	//global constant to check if user is logged in or anonymous
	cin >> command;
    Repo * repository = new Repo();
	++userId;
	while (command != QUIT){
		dispatchCommand(command, repository);
		cout << "Please enter a command, QUIT to quit" << endl;
		cin >> command;
	}
	delete repository;

}
