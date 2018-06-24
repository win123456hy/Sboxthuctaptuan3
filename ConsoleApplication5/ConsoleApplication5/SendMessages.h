#pragma once
#include<string>
using namespace std;
class SendMessages
{
private:
	string usernamefrom;
	string usernameto;
	string timesend;
	string sms;
public:
	string getusernamefrom();
	string getusernameto();

	string gettimesend();

	string getsms();
	void setusernamefrom(string usf);
	void setusernameto(string ust);

	void settimesend(string ts);

	void setsms(string sm);
	SendMessages();
	~SendMessages();
};

