// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<iostream>
#include <fstream>
#include "DoHoa.h"
#include"User.h"
#include"Friends.h"
#include"SendMessages.h"
#include<string>
#include"Reuse.h"
#include <stdlib.h>  
using namespace std;

int kiemtranamnhuan(int nam) {//ham kiem tra nam nhuan(theo lich am). neu nam chia cho 19 du ra 0,3,6,9,11,14,17 thi nam do la nam nhuan. 
							  //ham tra ve 1: nam do la nam nhuan
							  //ham tra ve 0: nam do khong phai la nam nhuan
	if (nam % 19 == 0 || nam % 19 == 3 || nam % 19 == 6 || nam % 19 == 9 || nam % 19 == 11 || nam % 19 == 14 || nam % 19 == 17)
		return 1;
	else
	{
		return 0;
	}
}
int kiemtrathoigianhople(int ngay, int thang, int nam) {
	int kiemtra;
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:if (ngay <= 31)
		kiemtra = 1;
			else kiemtra = 0;
			break;
	case 2:if (ngay <= 29 && kiemtranamnhuan(nam) == 1)
		kiemtra = 1;
		   else if (ngay <= 28 && kiemtranamnhuan(nam) != 1)
			   kiemtra = 1;
		   else kiemtra = 0;
		   break;
	case 4:
	case 6:
	case 9:
	case 11: if (ngay <= 30)
		kiemtra = 1;
			 else kiemtra = 0;
			 break;


	default:
		break;
	}
	return kiemtra;
}

void manhinhdangky() 
{
	system("cls");
	char vien[3] = "::", titledangky[200] = "DANG KY", *titledk = titledangky, *b = vien;

	for (int i = 0; i < 95; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			if (i >= 3 && i < 94 && j >= 2 && j < 34)
				ToMau(i, j, b, 3);
			else
				ToMau(i, j, b, 2);
		}
	}
	gotoxy(6, 6);
	cout << "User Name:";
	gotoxy(6, 10);
	cout << "Password:";
	gotoxy(6, 14);
	cout << "Ten:";
	gotoxy(6, 18);
	cout << "Ngay sinh:";
	gotoxy(6, 22);
	cout << "Gioi tinh:";
	gotoxy(6, 26);
	cout << "Noi o:";
	gotoxy(15, 31);

	cout << "Nhan  phim '0' de quay lai man hinh dang nhap!";
	gotoxy(15, 32);
	cout << "Nhan  phim '1' de hoan thanh viec dang ky!";
	gotoxy(15, 33);
	cout << "Nhan  phim '2' de nhap!";

	ToMau(47, 2, titledk, 7);
	for (int i = 5; i < 26; i = i + 4)
	{
		ToMau1kitu(20, i, (char)218, 7);
		ToMau1kitu(80, i, (char)191, 7);

		ToMau1kitu(20, i + 1, (char)179, 7);
		ToMau1kitu(80, i + 1, (char)179, 7);

		ToMau1kitu(20, i + 2, (char)192, 7);
		ToMau1kitu(80, i + 2, (char)217, 7);
	}



	for (int i = 21; i < 80; i++)
	{
		ToMau1kitu(i, 5, (char)196, 7);
		ToMau1kitu(i, 7, (char)196, 7);
		ToMau1kitu(i, 9, (char)196, 7);
		ToMau1kitu(i, 11, (char)196, 7);
		ToMau1kitu(i, 13, (char)196, 7);
		ToMau1kitu(i, 15, (char)196, 7);
		ToMau1kitu(i, 17, (char)196, 7);
		ToMau1kitu(i, 19, (char)196, 7);
		ToMau1kitu(i, 21, (char)196, 7);
		ToMau1kitu(i, 23, (char)196, 7);
		ToMau1kitu(i, 25, (char)196, 7);
		ToMau1kitu(i, 27, (char)196, 7);
	}
	string usern, pass, name, place, gioitinh;
	int day, month, year;




back:
	gotoxy(30, 1);
	_getch();
	char key = _getch();
	if (key == (char)50) {
		//do {
		gotoxy(21, 6); cin >> usern;

		//} while ();
		gotoxy(21, 10); cin >> pass;
		getchar();
		gotoxy(21, 14); getline(cin, name);
		do {
			gotoxy(21, 18); cin >> day;
			gotoxy(23, 18); cin >> month;
			gotoxy(27, 18); cin >> year;
			if (day > 31 || day < 0 || month>12 || month < 0 || year < 1900 || kiemtrathoigianhople(day, month, year) != 1) {
				gotoxy(30, 4);
				cout << "Ban nhap sai dinh dang.Vui long nhap lai!!!";
			}
			else {
				char xx[44] = ":::::::::::::::::::::::::::::::::::::::::::";
				char *xoa = xx;
				ToMau(30, 4, xoa, 3);
			}
		} while (day > 31 || day < 0 || month>12 || month < 0 || year < 1900 || kiemtrathoigianhople(day, month, year) != 1);
		do {
			gotoxy(21, 22); cin >> gioitinh;
			if (gioitinh != "nam" || gioitinh != "nu") {
				gotoxy(30, 4);
				cout << "Ban nhap sai dinh dang.Vui long nhap lai!!!";
			}
			else  {
				
				char xx[44] = ":::::::::::::::::::::::::::::::::::::::::::";
				char *xoa = xx;
				ToMau(30, 4, xoa, 3);
			}
		} while (gioitinh!="nam"&&gioitinh!="nu");
			getchar();
			gotoxy(21, 26); getline(cin, place);

			goto back;
		
	}
	else if (key == (char)49) {
		if (usern == ""&&pass == "")
			goto back;
		ofstream outfile;
		ifstream infile;
		infile.open("Account.txt");
		string data;
		char *dataa;
		bool laco;
		while (getline(infile, data)) {
			const char *v = data.c_str();
			dataa = (char*)malloc(sizeof(data));
			strcpy(dataa, v);

			char *userna = strtok(dataa, ",");
			char *passwor = strtok(NULL, ",");

			if (usern == userna && pass == passwor) {
				laco = false;
				break;
			}
			else
				laco = true;

		}
		if (laco == true) {
			outfile.open("Account.txt", ios_base::app);
			char d[100], m[100], y[100];
			outfile << "\n" + usern + "," + pass + "," + name + "," + _itoa(day, d, 10) + "-" + _itoa(month, m, 10) + "-" + _itoa(year, y, 10) + "," + gioitinh + "," + place;
			gotoxy(30, 3);
			cout << "Dang ky thanh cong!";
			outfile.close();
			goto back;
		}
		else
		{
			gotoxy(30, 3);
			cout << "Trung du lieu trong database! Vui long nhap lai!!";
			goto back;
		}
	}
	else if (key == (char)48)
	{
		system("cls");
		manhinhbatdau();


		gotoxy(30, 32);
		cout << "Nhan '1' de di chuyen den o dang ky!";
		gotoxy(30, 33);
		cout << "Nhan '2' de di chuyen den o dang nhap!";

		_getch();
		char key1 = _getch();
		if (key1 == (char)50) {
			gotoxy(30, 20);
			char dnn[200] = "Dang nhap";
			char *dn = dnn;
			ToMau(43, 10, dn, 7);
			xulylogin();
		}
		else if (key1 == (char)49) {
			gotoxy(30, 20);
			char dkk[200] = "DANG KY";
			char *dk = dkk;
			ToMau(30, 20, dk, 7);
			manhinhdangky();
		}
	label:

		manhinhbatdau();

		gotoxy(30, 32);
		cout << "Nhan '1' de di chuyen den o dang ky!";
		gotoxy(30, 33);
		cout << "Nhan '2' de di chuyen den o dang nhap!";
		_getch();
		char key2 = _getch();
		if (key2 == (char)50) {
			gotoxy(30, 20);
			char dnn[200] = "Dang nhap";
			char *dn = dnn;
			ToMau(43, 10, dn, 7);
			xulylogin();
		}
		else if (key2 == (char)49) {
			gotoxy(30, 20);
			char dkk[200] = "DANG KY";
			char *dk = dkk;
			ToMau(30, 20, dk, 7);
			manhinhdangky();
		}


	}
	else
		goto back;

	}

void login() {
	
	gotoxy(30, 32);
	cout << "Nhan '1' de di chuyen den o dang ky!";
	gotoxy(30, 33);
	cout << "Nhan '2' de di chuyen den o dang nhap!";
	label:
	back:
	char key = _getch();
	if (key == (char)50) {
		gotoxy(30, 20);
		char dnn[200] = "Dang nhap";
		char *dn = dnn;
		ToMau(43, 10, dn, 7);
		xulylogin();
	}
	else if (key == (char)49) {
		gotoxy(30, 20);
		char dkk[200] = "DANG KY";
		char *dk = dkk;
		ToMau(30, 20, dk, 7);
		manhinhdangky();
	}
	else
		goto back;
}


void main()
{
	quaylaimanhinh:
	manhinhbatdau();
	login();
	if (logout == true)
		goto quaylaimanhinh;
	cin.get();
}

