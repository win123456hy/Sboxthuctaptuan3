#include "stdafx.h"
#include "User.h"
#include <iostream>

using namespace std;

string User::getUserName() {
	return Username;
}
string User::getPassword() {
	return Password;
}
string User::getNoiO() {
	return noio;
}
string User::getGioitinh() {
	return gioitinh;
}
string User::getTen() {
	return Ten;
}
int User::getNgaySinh() {
	return ngaysinh;
}
int User::getThangsinh() {
	return thangsinh;
}
int User::getNamSinh() {
	return namsinh;
}

void User::setUserName(string usernamee) {
	Username = usernamee;
}
void User::setPassword(string password) {
	Password = password;
}
void User::setNoiO(string noioo) {
	noio = noioo;
}
void User::setTen(string ten) {
	Ten = ten;
}

void User::setNgaySinh(int ngaysinhh) {
	ngaysinh = ngaysinhh;
}
void User::setThangsinh(int thangsinhh) {
	thangsinh = thangsinhh;
}
void User::setNamSinh(int namsinhh) {
	namsinh = namsinhh;
}
void User::setGioitinh(string gioitinhh) {
	gioitinh = gioitinhh;
}
User::User()
{

}



User::~User()
{
}
