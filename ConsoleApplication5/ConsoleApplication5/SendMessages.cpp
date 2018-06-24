#include "stdafx.h"
#include "SendMessages.h"
#include <iostream>
using namespace std;
string SendMessages::getusernamefrom() {
	return usernamefrom;
}
string SendMessages::getusernameto() {
	return usernameto;
}

string SendMessages::gettimesend(){
	return timesend;
}

string SendMessages::getsms() {
	return sms;
}

void SendMessages::setusernamefrom(string usf) {
	usernamefrom = usf;
}
void SendMessages::setusernameto(string ust) {
	usernameto = ust;
}

void SendMessages::settimesend(string ts) {
	timesend = ts;
}

void SendMessages::setsms(string sm) {
	sms = sm;
}
SendMessages::SendMessages()
{
}


SendMessages::~SendMessages()
{
}
