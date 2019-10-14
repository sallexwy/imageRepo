#ifndef IMAGE
#define IMAGE
#include <string>
#include <vector>
#include <iostream>
using namespace std; 

class User;
class Image {
	string name; //mame of the image
	string address; //address of the image
	long pid; //primary Id for the image
	User * owner;
	public:
		Image(string nm, string addr, User * own, int picId); //constructor
		string getName(); //name of the image
		string getAddress(); //image's address relative to main.cc
		User * getOwner(); //owner of the image
		long getPid(); //primary id of the image
		string displayImageInfo(); //display the image information
		string displayImageField();
		~Image(); //destructor
};
#endif
