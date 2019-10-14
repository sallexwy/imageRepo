#ifndef REPO
#define REPO
#include <string>
#include <vector>
#include "image.h"
#include "user.h"
using namespace std;

class Repo{
	vector <Image *> images; //list of pointers to availble images
	vector <User *> users; //list of users
	int countImage; //how many images
	int countUser; //how many users
	long pictureId; //picture id counter
	long userId; //user id counter
	User * defaultUser;
	User * loggedInUser; //current user
	public:
		Repo();//constructor
		~Repo();//destructor
		void addImage(string nm, string addr); //add an image according to the current user
		void addUser(string userName, string passWord); //add a user to the system
		void searchImageByName(string name); //show a list of all images matching the name
		void displayAccountInfo(); //display information of the current login user
};	
#endif
