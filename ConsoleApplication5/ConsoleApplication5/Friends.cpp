#include "stdafx.h"
#include "Friends.h"

string Friends::getusername() {
	return username;
}
string Friends::getusernamefriend() {
	return usernamefriend;
}
string Friends::gettimeadd() {
	return timeadd;
}
string Friends::getlongtimeadd() {
	return longtimeadd;
}
string Friends::getblock() {
	return block;
}
void Friends::setusername(string usernamee) {
	username = usernamee;
}
void Friends::setusernamefriend(string usernamefriendf) {
	usernamefriend = usernamefriendf;
}
void Friends::settimeadd(string timeaddd) {
	timeadd = timeaddd;
}
void Friends::setlongtimeadd(string longtimeaddd) {
	longtimeadd = longtimeaddd;
}

void Friends::setblock(string blockk) {
	block = blockk;
}
Friends::Friends()
{
}


Friends::~Friends()
{
}
