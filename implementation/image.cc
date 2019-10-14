#include "../include/image.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
//constructor
//params: nm as string for name of the image
//	  addr as string for address of the image
//	  own as Owner * points to the owner of image
Image::Image(string nm, string addr, User * own, int picId){
	name = nm;
	address = addr;
	owner = own;
}


//destructor
//params: none
Image::~Image(){
	owner = NULL;
}


/////////////////////////////////////////////
//////////////////GETTERS////////////////////
/////////////////////////////////////////////

//params: none
//obtain the name of this image
string Image::getName(){
	return name;
}


//params:none
//obtain returns the relative path of the image to main
string Image::getAddress(){
	return address;
}


//params:none
//obtain the image's primary id
long Image::getPid(){
	return pid;
}


//params:none
//obtain the image's owner
User * Image::getOwner(){
	return owner;
}


/////////////////////////////////////////////
//////////////////OTHERS/////////////////////
/////////////////////////////////////////////
//params: out as ostream & for an output stream
//outputs the image's information
string Image::displayImageInfo(){
	return getName()+"\t"+getAddress()+"\n";
}


//params: out as ostream & for an output stream
//outputs the image's information
string Image::displayImageField(){
	return "Name\tAddress\n";
}




















