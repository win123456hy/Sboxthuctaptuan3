#pragma once
#include<string>
using namespace std;
class Friends
{
private:
	string username;
	string usernamefriend;
	string timeadd;
	string longtimeadd;
	string block;
public:
	string getusername();
	string getusernamefriend();

	string gettimeadd();

	string getlongtimeadd();

	string getblock();
	void setusername(string usr);
	void setusernamefriend(string usrf);

	void settimeadd(string tma);

	void setlongtimeadd(string lta);

	void setblock(string b);

	Friends();
	~Friends();
};

