#include "../include/user.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

User::User(string userName, string passWord, long userId){
	username = userName;
	password = passWord;
	uid = userId;
}

User::~User(){
	for (int i = 0; i < inventory.size(); i++){
		inventory[i] = NULL;
	}
}


vector <Image *> * User::getInventory(){
	return &inventory;
}


string User::getUsername(){
	return username;
}


long User::getUid(){
	return uid;
}

string User::displayInventoryInfo(){
	int inventorySize = getInventory()->size();
	string output = "";
	if (inventorySize == 0){
		output = "You have not added any photos yet\n";
	}
	else if (inventorySize > 0){
		output += inventory[0]->displayImageField();
	}
	for (int i = 0; i < inventorySize; ++i){
		output += "\t"+inventory[i]->displayImageInfo()+ "\n";
	}
	return output;
}


void User::displayUserInfo(){
	cout << "UserName " << getUsername() << endl;
	cout << "Your images uploaded: " << endl;
	cout << displayInventoryInfo(); 
}


void User::addToInventory(Image * image){
	int inventorySize = getInventory()->size();
	if (inventorySize == 0){
		inventory.push_back(image);
		return;
	}
	for (int i = 0; i < inventorySize; i++){
		if (inventory[i]->getName() > image->getName()){
			inventory.insert(inventory.begin()+i, image);
			return;
		}
	}
	inventory.push_back(image);
}
