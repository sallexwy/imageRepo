#ifndef USER
#define USER
#include <string>
#include <vector>
#include <iostream>
#include "image.h"
using namespace std;

class User{
        string username; //owner's name
        string password; 
        long uid; //owner's unique id
        vector <Image *> inventory; //all the images uploaded by the user
    public:
    	User(string userName, string passWord, long userId);
    	vector <Image *> * getInventory();
    	long getUid();
        string getUsername();
        string displayInventoryInfo();
        void displayUserInfo();
    	void addToInventory (Image * image);
    	~User();
};
#endif
