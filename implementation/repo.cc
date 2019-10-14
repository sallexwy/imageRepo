#include "../include/repo.h"
#include <string>
#include <vector>
#include <iostream>

Repo::Repo(){
	loggedInUser = NULL; //no user logged in, everything is anonymous at this point
	countImage = 0;
	countUser = 0;
	pictureId = 10000;
	userId = 50000;
	defaultUser = new User ("anonymous", "", userId);
	loggedInUser = defaultUser;
	++userId;
}


Repo::~Repo(){
	loggedInUser = NULL; 
	//delete all the picturees
	delete defaultUser;
	for (int i = 0; i < countImage; i++){
		delete images[i];
	}
	//delete all accounts
	for (int i = 0; i < countUser; i++){
		delete users[i];
	}
}


void Repo::addImage(string nm, string addr){
	//create new picture
	Image * newImage = new Image(nm, addr, loggedInUser, pictureId);
	++pictureId;
	++countImage;
	//insert into images
	if (countImage == 0){
		images.push_back(newImage);
	}
	else{
		for (int i = 0; i < countImage-1; i++){
			if (images[i]->getName() > nm){
				images.insert(images.begin()+i, newImage);
				return;
			}
		}
		images.push_back(newImage);
	}
	if (countUser > 0){
		loggedInUser->addToInventory(newImage);
	}
}


void Repo::addUser(string userName, string passWord){
	//create new user
	User * newUser = new User (userName, passWord, userId);
	loggedInUser = newUser;
	++userId;//make sure Id is unique for each user
	++countUser;
	if (countUser == 0){
		users.push_back(newUser);
	}
	else{
		for (int i = 0; i < countUser-1; i++){
			if (users[i]->getUsername() > userName){
				users.insert(users.begin()+i, newUser);
				return;
			}
		}
		users.push_back(newUser);
	}
}


/////helper function to locate the first occurence of a name///////
static int findFirstOccurence(vector <Image *> imageToSearch, string key, int start, int end){
	int mid;
	while (start < end){
		mid = ((end - start)/2)+start;
		if (imageToSearch[mid]->getName() >= key){
			end = mid;
		} 
		else {
			start = mid+1;
		}
	}
	if (imageToSearch[start]->getName() == key){
		return start;
	}
	else {
		return -1;
	}

}

void Repo::searchImageByName(string name){
	//since the images are sorted, we can binary search through it
	if (countImage == 0){
		cout << "sorry, no image are currently present in the repo" << endl;
		return;
	}
	int firstOccur = findFirstOccurence(images, name, 0, countImage-1);
	if (firstOccur == -1){
		cout << "Sorry, no results are found for images named " << name << endl;
	}
	else {
		cout << images[firstOccur]->displayImageField();
		int cur = firstOccur;
		while (cur < countImage && images[cur]->getName() == name){
			cout << images[cur]->displayImageInfo();
			++cur;
		}
	}
}


void Repo::displayAccountInfo(){
	if (countUser == 0){//if the first user is still not created
		cout << "You are not logged in as an account" << endl;
	}
	else {
		loggedInUser->displayUserInfo();
	}
}