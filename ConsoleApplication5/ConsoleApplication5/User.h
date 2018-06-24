#include<string>
using namespace std;
class User
{
private:
	string Username;
	string  Password;
	string Ten;
	int ngaysinh;
	int thangsinh;
	int namsinh;
	string gioitinh;
	string noio;

public:
	string getUserName();
	string getPassword();

	string getTen();

	string getNoiO();

	int getNgaySinh();

	int getThangsinh();
	int getNamSinh();
	string getGioitinh();

	void setUserName(string username);
	void setPassword(string pasword);

	void setTen(string ten);

	void setNoiO(string noio);

	void setNgaySinh(int ngaysinh );

	void setThangsinh(int thangsinh);
	void setNamSinh(int namsinh);
	void setGioitinh(string gioitinh);
	User();
	~User();
};

