#include<ctime>
#include<time.h>
#include <iomanip>

User userhihi;
string towho;
bool logout = false;


struct Date
{
	int d, m, y;
};

// To store number of days in all months from January to Dec.
const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

// This function counts number of leap years before the
// given date
int countLeapYears(Date d)
{
	int years = d.y;

	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (d.m <= 2)
		years--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return years / 4 - years / 100 + years / 400;
}

// This function returns number of days between two given
// dates
int getDifference(Date dt1, Date dt2)
{
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'

	// initialize count using years and day
	long int n1 = dt1.y * 365 + dt1.d;

	// Add days for months in given date
	for (int i = 0; i<dt1.m - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(dt1);

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i<dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	// return difference between two counts
	return (n2 - n1);
}



void viettin() {
	ofstream f;
	f.open("sms.txt", ios_base::app);
	ifstream fri,fff;
	fri.open("Friendss.txt");
	Friends frie[100];
	User users[100];
	string dataaa,dt, tinnhan;
	int idddd;
	char *dataaaaa,*datt;
	int ii = 0, iii = 0;
	time_t t;
	tm* timePtr;
	bool flag = true;
	bool biblock = false;
	//kiem tra trong file Friendss.txt co ton tai nguoi nhan hay khong.
	while (getline(fri, dataaa))
	{
		if (dataaa == "")
			break;
		const char *v = dataaa.c_str();
		dataaaaa = (char*)malloc(1000 * sizeof(dataaa));
		strcpy(dataaaaa, v);

		char *p = strtok(dataaaaa, ",");
		frie[ii].setusername((string)p);
		char *d = strtok(NULL, ",");
		frie[ii].setusernamefriend((string)d);
		char *timeadd = strtok(NULL, ",");
		frie[ii].settimeadd((string)timeadd);
		char *longtim = strtok(NULL, ",");
		frie[ii].setlongtimeadd((string)longtim);
		char *blo = strtok(NULL, ",");
		frie[ii].setblock((string)blo);
		ii++;
	}
	string nguoinhan;
nhaplai:
	cout << "Nhap ten nguoi nhan"<<endl;


	getline(cin, nguoinhan);
	if (nguoinhan == "")
		goto end;
	
	fff.open("Account.txt");
	
	

	while (getline(fff, dt))
	{
		const char *v = dt.c_str();
		datt = (char*)malloc(1000 * sizeof(dt));
		strcpy(datt, v);

		char *use = strtok(datt, ",");
		users[iii].setUserName((string)use);
		char *pass = strtok(NULL, ",");
		users[iii].setPassword((string)pass);
		char *tenn = strtok(NULL, ",");
		users[iii].setTen((string)tenn);
		char *ngays = strtok(NULL, "-");
		int dd = atoi(ngays);
		users[iii].setNgaySinh(dd);

		char *thangs = strtok(NULL, "-");
		int mm = atoi(thangs);
		users[iii].setThangsinh(mm);
		char *nams = strtok(NULL, ",");
		int yy = atoi(nams);
		users[iii].setNamSinh(yy);
		char *gioiti = strtok(NULL, ",");
		users[iii].setGioitinh((string)gioiti);
		char *noioo = strtok(NULL, ",");
		users[iii].setNoiO((string)noioo);
		iii++;
	}
	fff.close();
	
	for (int i = 0; i < sizeof(users)/ sizeof(*users); i++)
	{
		if (users[i].getTen() == nguoinhan)
		{
			idddd = i;
			break;
		}
		else {
			idddd = -1;
			continue;
		}
	}
	if (idddd ==-1) {
		cout << "Ten nguoi dung khong ton tai!!"<<endl;
		goto nhaplai;
	}
	
	for (int i = 0; i < sizeof(frie) / sizeof(*frie); i++)
	{
		if (frie[i].getblock() == "unblock"&&frie[i].getusername() == users[idddd].getUserName() && frie[i].getusernamefriend() == userhihi.getUserName()) {
			flag = true;
			break;
		}
		else if (frie[i].getblock() == "block"&&frie[i].getusername() == users[idddd].getUserName() && frie[i].getusernamefriend() == userhihi.getUserName()) {
			biblock = true;
			break;
		}
		else {
			flag = false;
			continue;
		}
	}
	if (biblock == true) {
		cout << "Ban bi block boi nguoi nay";
		
		goto end;
	}
	if (flag == false) {
		cout << "Ban chua ket ban voi nguoi nay!!"<<endl;
		goto nhaplai;
	}
	fri.close();
	
	cout << "Nhap tin nhan";
	getline(cin, tinnhan);
	cin.get();
	if (tinnhan == "")
		goto end;
	t = time(NULL);
	 timePtr = localtime(&t);
	// ghi tin nhan ra file sms
	f << userhihi.getUserName() + "," + users[idddd].getUserName() + "," << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << " " << (timePtr->tm_mday) << "-" << (timePtr->tm_mon) + 1 << "-" << (timePtr->tm_year) + 1900 << "," + tinnhan << endl;
	towho = users[idddd].getUserName();
	f.close();
	cout << "Gui tin nhan thanh cong!";
end:
	Sleep(1000);
}
void danhsachbanbe() {

	ifstream fff;
	fff.open("Account.txt");
	User users[100];
	string dataaass;
	char *dataaaaass;
	int iio = 0;
	

	while (getline(fff, dataaass))
	{
		const char *v = dataaass.c_str();
		dataaaaass = (char*)malloc(1000 * sizeof(dataaass));
		strcpy(dataaaaass, v);

		char *use = strtok(dataaaaass, ",");
		users[iio].setUserName((string)use);
		char *pass = strtok(NULL, ",");
		users[iio].setPassword((string)pass);
		char *tenn = strtok(NULL, ",");
		users[iio].setTen((string)tenn);
		char *ngays = strtok(NULL, "-");
		int dd = atoi(ngays);
		users[iio].setNgaySinh(dd);

		char *thangs = strtok(NULL, "-");
		int mm = atoi(thangs);
		users[iio].setThangsinh(mm);
		char *nams = strtok(NULL, ",");
		int yy = atoi(nams);
		users[iio].setNamSinh(yy);
		char *gioiti = strtok(NULL, ",");
		users[iio].setGioitinh((string)gioiti);
		char *noioo = strtok(NULL, ",");
		users[iio].setNoiO((string)noioo);
		iio++;
	}
	fff.close();


	ifstream f;
	f.open("Friendss.txt");
	Friends frie[100];
	string dataaa;
	char *dataaaaa;
	int ii = 0;
	time_t t=time(NULL);
	tm* timenow = localtime(&t);
	Date dt1 = { timenow->tm_mday ,timenow->tm_mon+1, timenow->tm_year +1900};
	while (getline(f, dataaa))
	{
		const char *v = dataaa.c_str();
		dataaaaa = (char*)malloc(1000 * sizeof(dataaa));
		strcpy(dataaaaa, v);

		char *use = strtok(dataaaaa, ",");
		frie[ii].setusername((string)use);
		char *usef = strtok(NULL, ",");
		frie[ii].setusernamefriend((string)usef);
		char *tia = strtok(NULL, ",");
		
		frie[ii].settimeadd((string)tia);
		char *ltadd = strtok(NULL, ",");
		
		char *block = strtok(NULL, ",");
		frie[ii].setblock((string)block);

		char * hourr = strtok(tia, ":");
		char * minutet = strtok(NULL, ":");
		char * secondd = strtok(NULL, " ");
		char * dayyy = strtok(NULL, "-");
		char * monthhh = strtok(NULL, "-");
		char * yearrrr = strtok(NULL, ",");
		Date dt2 = { atoi(dayyy) ,atoi(monthhh) ,atoi(yearrrr) };
		char numberofday[200];
		_itoa(getDifference(dt2, dt1), numberofday,5);
		frie[ii].setlongtimeadd((string)numberofday);
		ii++;
	}
	f.close();

	int dem = 0;
	for (int i = 0; i < sizeof(frie) / sizeof(*frie); i++)
	{
		if (frie[i].getusername() == userhihi.getUserName()) {
			dem++;
		}
		else
			continue;
	}
	cout << "Danh sach ban be:"<<dem<<" ban"<<endl;
	cout << setw(10) <<  "Ten" << setw(30) << "Thoi gian them" << setw(30) << "Thoi gian la ban" << setw(15) <<"Block" << endl;
	for (int i = 0; i < sizeof(frie) / sizeof(*frie); i++)
	{
		if (frie[i].getusername() == userhihi.getUserName()) {

			if (frie[i].getblock() == "block") {
				for (int j = 0; j < sizeof(users) / sizeof(*users); j++)
				{
					if (users[j].getUserName() == frie[i].getusernamefriend()) {
						cout << setw(10) << users[j].getTen() << setw(30) << frie[i].gettimeadd() << setw(20) << frie[i].getlongtimeadd() << " ngay" << setw(20) << "Co" << endl;
						break;
					}
				}

			}
			else if (frie[i].getblock() == "unblock") {
				for (int j = 0; j < sizeof(users) / sizeof(*users); j++)
				{
					if (users[j].getUserName() == frie[i].getusernamefriend()) {
						cout << setw(10) << users[j].getTen() << setw(30) << frie[i].gettimeadd() << setw(20) << frie[i].getlongtimeadd() << " ngay" << setw(20) << "Khong" << endl;
						break;

					}

				}
			}
			else
				continue;
		}
	}
}
void addFriends() {
	ifstream f;
	f.open("Account.txt");
	User users[100];
	string dataaa;
	char *dataaaaa;
	int ii = 0;
	bool flag = true;
	int index;

	while (getline(f, dataaa))
	{
		const char *v = dataaa.c_str();
		dataaaaa = (char*)malloc(1000 * sizeof(dataaa));
		strcpy(dataaaaa, v);

		char *use = strtok(dataaaaa, ",");
		users[ii].setUserName((string)use);
		char *pass = strtok(NULL, ",");
		users[ii].setPassword((string)pass);
		char *tenn = strtok(NULL, ",");
		users[ii].setTen((string)tenn);
		char *ngays = strtok(NULL, "-");
		int dd = atoi(ngays);
		users[ii].setNgaySinh(dd);

		char *thangs = strtok(NULL, "-");
		int mm = atoi(thangs);
		users[ii].setThangsinh(mm);
		char *nams = strtok(NULL, ",");
		int yy = atoi(nams);
		users[ii].setNamSinh(yy);
		char *gioiti = strtok(NULL, ",");
		users[ii].setGioitinh((string)gioiti);
		char *noioo = strtok(NULL, ",");
		users[ii].setNoiO((string)noioo);
		ii++;
	}
	f.close();
	cout << "Danh sach:" << endl;
	printf("%20s|%12s|%10s|%40s\n", "Ten", "Ngay sinh", "Gioi tinh", "Noi o");

	for (int i = 0; i < sizeof(users) / sizeof(*users); i++)
	{
		if (users[i].getUserName() != "" || users[i].getPassword() != "")
			cout << setw(20) << users[i].getTen()<<"|" << setw(3) << users[i].getNgaySinh() << setw(3) << users[i].getThangsinh() << setw(6) << users[i].getNamSinh() << "|"<<setw(10) << users[i].getGioitinh() <<"|"<< setw(40) << users[i].getNoiO() << endl;
		else
			continue;
	}
	
	string ten;
	cout << "Nhap ten:";
	quaylai:
	getline(cin, ten);
	if (ten == "")
		goto end;
	
	for (int i = 0; i < sizeof(users) / sizeof(*users); i++)
	{
		if (users[i].getTen() == ten) {
			flag = true;
			index = i;
			break;
		}
		else {
			flag = false;
			continue;
		}
			
	}
	if (flag == false) {
		cout << "Khong tim thay nguoi nay!!";
		goto quaylai;
	}
	else {

		ifstream ff;
		ff.open("Friendss.txt");
		Friends frie[100];
		string datddd;
		char *dataa;
		int iii = 0;

		while (getline(ff, datddd))
		{
			const char *v = datddd.c_str();
			dataa = (char*)malloc(1000 * sizeof(datddd));
			strcpy(dataa, v);

			char *use = strtok(dataa, ",");
			frie[iii].setusername((string)use);
			char *usef = strtok(NULL, ",");
			frie[iii].setusernamefriend((string)usef);
			char *tia = strtok(NULL, ",");
			frie[iii].settimeadd((string)tia);
			char *ltadd = strtok(NULL, ",");
			frie[iii].setlongtimeadd((string)ltadd);
			char *block = strtok(NULL, ",");
			frie[iii].setblock((string)block);
			iii++;
		}
		ff.close();
		bool phat=true;
		for (int i = 0; i < sizeof(frie)/ sizeof(*frie); i++)
		{
			if ((frie[i].getusername() == userhihi.getUserName() && frie[i].getusernamefriend() == users[index].getUserName())||(frie[i].getusername() == users[index].getUserName() && frie[i].getusernamefriend() == userhihi.getUserName()))
			{
				phat = true;
				break;
			}
			else
			{
				phat = false;
				continue;
			}
		}
		if (phat == true) {
			cout << "Ban da them ban voi nay roi!! Tim ban khac nhe :v";
			goto end;
		}
		else {
			ofstream oft;
			oft.open("Friendss.txt", ios_base::app);
			time_t t = time(NULL);
			tm* timePtr = localtime(&t);
			oft << userhihi.getUserName() << "," << users[index].getUserName() << "," << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << " " << (timePtr->tm_mday) << "-" << (timePtr->tm_mon) + 1 << "-" << (timePtr->tm_year) + 1900 << "," << "new" << ",unblock" << endl;
			oft << users[index].getUserName() << "," << userhihi.getUserName() << "," << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << " " << (timePtr->tm_mday) << "-" << (timePtr->tm_mon) + 1 << "-" << (timePtr->tm_year) + 1900 << "," << "new" << ",unblock" << endl;
			oft.close();
			cout << "Them ban thanh cong" << endl;
		}
	}
end:
	Sleep(1000);
}
void doctin() {

	ifstream faa;
	faa.open("Account.txt");
	User usersss[100];
	string dataaa;
	char *dataaaaa;
	int iiii = 0,ix=0;
	

	while (getline(faa, dataaa))
	{
		const char *v = dataaa.c_str();
		dataaaaa = (char*)malloc(1000 * sizeof(dataaa));
		strcpy(dataaaaa, v);

		char *use = strtok(dataaaaa, ",");
		usersss[iiii].setUserName((string)use);
		char *pass = strtok(NULL, ",");
		usersss[iiii].setPassword((string)pass);
		char *tenn = strtok(NULL, ",");
		usersss[iiii].setTen((string)tenn);
		char *ngays = strtok(NULL, "-");
		int dd = atoi(ngays);
		usersss[iiii].setNgaySinh(dd);

		char *thangs = strtok(NULL, "-");
		int mm = atoi(thangs);
		usersss[iiii].setThangsinh(mm);
		char *nams = strtok(NULL, ",");
		int yy = atoi(nams);
		usersss[iiii].setNamSinh(yy);
		char *gioiti = strtok(NULL, ",");
		usersss[iiii].setGioitinh((string)gioiti);
		char *noioo = strtok(NULL, ",");
		usersss[iiii].setNoiO((string)noioo);
		iiii++;
	}
	faa.close();


	ifstream fr;
	fr.open("sms.txt");
	string tennguoinhan;
	string usernameee;
	SendMessages s[100];
	string data;
	char *dataa;
	bool co = true;
	cout << "Nhap ten nguoi ban muon xem:";
	getline(cin,tennguoinhan);


	if (tennguoinhan == "")
		goto end;
	//doc file sms
	for (int i = 0; i < sizeof(usersss) / sizeof(*usersss); i++)
	{
		if (usersss[i].getTen() == tennguoinhan)
		{	
			usernameee = usersss[i].getUserName();
			break;
		}
		else
			continue;

	}
	while (getline(fr, data))
	{
		const char *v = data.c_str();
		dataa = (char*)malloc(1000 * sizeof(data));
		strcpy(dataa, v);

		char *p = strtok(dataa, ",");
		s[ix].setusernamefrom((string)p);
		char *d = strtok(NULL, ",");
		s[ix].setusernameto((string)d);
		char *tim = strtok(NULL, ",");
		s[ix].settimesend((string)tim);
		char *sm = strtok(NULL, ",");
		s[ix].setsms((string)sm);

		ix++;
	}

	fr.close();
	
		for (int i = 0; i < sizeof(s) / sizeof(*s); i++)
		{
			if (s[i].getusernamefrom() == usernameee || s[i].getusernameto() == usernameee) {
				co = true;
				break;
			}
			else {
				co = false;
				continue;
			}
		}
		if (co == false) {
			cout << "Ban chua gui bat ki tin nhan nao voi nguoi nay. Hay viet tin nhan di!!" << endl;
			viettin();
		}
		else {

			cout << "Danh sach tin nhan:" << endl;
			for (int i = 0; i < sizeof(s) / sizeof(*s); i++)
			{
				if (s[i].getusernamefrom() == userhihi.getUserName() && s[i].getusernameto() == usernameee) {
					cout << "I said:" << s[i].gettimesend() << "  " << s[i].getsms() << endl;
				}
				else if (s[i].getusernameto() == userhihi.getUserName() && s[i].getusernamefrom() == usernameee) {
					cout << s[i].getusernamefrom() << " said:" << s[i].gettimesend() << "  " << s[i].getsms() << endl;
				}
				else
				{
					continue;
				}
			}
		}
	end:
		Sleep(1000);
}
void blockfriend() {
	ifstream faa;
	faa.open("Account.txt");
	User usersss[100];
	string dataaaasd;
	char *dataaasad;
	int iiii = 0;


	while (getline(faa, dataaaasd))
	{
		const char *v = dataaaasd.c_str();
		dataaasad = (char*)malloc(1000 * sizeof(dataaaasd));
		strcpy(dataaasad, v);

		char *use = strtok(dataaasad, ",");
		usersss[iiii].setUserName((string)use);
		char *pass = strtok(NULL, ",");
		usersss[iiii].setPassword((string)pass);
		char *tenn = strtok(NULL, ",");
		usersss[iiii].setTen((string)tenn);
		char *ngays = strtok(NULL, "-");
		int dd = atoi(ngays);
		usersss[iiii].setNgaySinh(dd);

		char *thangs = strtok(NULL, "-");
		int mm = atoi(thangs);
		usersss[iiii].setThangsinh(mm);
		char *nams = strtok(NULL, ",");
		int yy = atoi(nams);
		usersss[iiii].setNamSinh(yy);
		char *gioiti = strtok(NULL, ",");
		usersss[iiii].setGioitinh((string)gioiti);
		char *noioo = strtok(NULL, ",");
		usersss[iiii].setNoiO((string)noioo);
		iiii++;
	}
	faa.close();

	string search_string = "unblock";
	string replace_string = "block";
	string inbuf;
	string tenblock2;
	fstream input_file("Friendss.txt", ios::in);
	ofstream output_file("result.txt");
	char *dataaaaa;
	int ii = 0;
	string tenblock;
	cout << "Nhap ten nguoi can chan:";
	getline(cin,tenblock);
	if (tenblock == "")
		goto end;

	for (int i = 0; i < sizeof(usersss)/ sizeof(*usersss); i++)
	{
		if (usersss[i].getTen() == tenblock) {
			tenblock2 = usersss[i].getUserName();
			break;
		}

	}
	while (getline(input_file, inbuf))
	{
		if (inbuf == "")
			break;
		const char *v = inbuf.c_str();
		dataaaaa = (char*)malloc(1000 * sizeof(inbuf));
		strcpy(dataaaaa, v);

		char *use = strtok(dataaaaa, ",");
		char *usef = strtok(NULL, ",");
		if (use == userhihi.getUserName() && usef == tenblock2) {
			int spot = inbuf.find(search_string);
			if (spot >= 0)
			{
				string tmpstring = inbuf.substr(0, spot);
				tmpstring += replace_string;
				tmpstring += inbuf.substr(spot + search_string.length(), inbuf.length());
				inbuf = tmpstring;
			}

			output_file << inbuf << endl;
			cout << "Block thanh cong!";
			continue;
		}
		else {
			output_file << inbuf << endl;
			continue;
		}
	}
	input_file.close();
	output_file.close();
	remove("Friendss.txt");
	rename("result.txt","Friendss.txt");
end:
	Sleep(1000);
}
void manhinhchat() {
	
	int chon;
	while (1) {
		system("cls");
		cout << "1. Gui tin nhan" << endl;
		cout << "2. Doc tin nhan" << endl;
		cout << "3. Danh sach ban be" << endl;
		cout << "4. Them ban" << endl;
		cout << "5. Block" << endl;
		cout << "6. Dang xuat" << endl;
		cout << "Chon chuc nang:" << endl;
		do {
			cin >> chon;
		} while (chon < 1 || chon>6);
		switch (chon)
		{
		case 1:system("cls"); cin.get(); viettin(); cin.get(); break;
		case 2:system("cls"); cin.get(); doctin(); cin.get(); break;
		case 3:system("cls"); cin.get(); danhsachbanbe(); cin.get(); break;
		case 4:system("cls"); cin.get(); addFriends(); cin.get(); break;
		case 5:system("cls"); cin.get(); danhsachbanbe(); blockfriend(); cin.get(); break;
		case 6:logout = true; goto end; break;
		default:
			break;
		}
	}
end:
	system("cls");
	gotoxy(31, 15);
	cout << "Dang dang xuat...................";
	Sleep(2000);
}

void xulylogin() {
	
	User s[1024];
	ifstream f;
	f.open("Account.txt");
	string data;

	char *dataa;
	int i = 0;
	//doc tu file theo tung dong
	while (getline(f, data))
	{
		const char *v = data.c_str();
		dataa = (char*)malloc(1000*sizeof(data));
		strcpy(dataa, v);

		char *p = strtok(dataa, ",");
		s[i].setUserName((string)p);
		char *d = strtok(NULL, ",");
		s[i].setPassword((string)d);
		i++;
	}
	
	free(dataa);
	f.close();
	string a, b;
label:
	gotoxy(39, 12);
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 12, ' ', 0);

	}
	gotoxy(39, 12);

	getline(cin, a);

	gotoxy(39, 16);
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 16, ' ', 0);

	}


	gotoxy(39, 16);
	getline(cin, b);
	//kiem tra dang nhap
	bool flag = true;
	for (int i = 0; i < sizeof(s)/sizeof(*s); i++)
	{
		if (a == "" || b == "")
			goto label;
		if (a == s[i].getUserName() && b == s[i].getPassword()) {
			flag = true;
			gotoxy(39, 25);
			for (int j = 39; j < 68; j++)
			{
				ToMau1kitu(j, 25, ' ', 0);

			}
			gotoxy(39, 25);
			cout << "Dang nhap thanh cong";
			userhihi.setUserName(s[i].getUserName());
			
			break;
		}
		else {
			flag = false;
			continue;
		}
	}
	if (flag == false)
	{
		gotoxy(39, 25);
		for (int j = 39; j < 68; j++)
		{
			ToMau1kitu(j, 25, ' ', 0);

		}
		gotoxy(39, 25);
		cout << "Sai UserName va PassWord";

		goto label;
	}
	
	manhinhchat();
}


void manhinhbatdau() {
	resizeConsole(800, 600);
	char vien[3] = "::", title[100] = "UNG DUNG CHAT", login[100] = "Dang nhap", username[100] = "Username:";
	char password[100] = "Password:", regis[100] = "DANG KY";
	char *b = vien, *d = title, *e = login, *f = username, *g = password, *h = regis;

	for (int i = 0; i < 95; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			if (i >= 25 && i < 71 && j >= 8 && j < 27)
				ToMau(i, j, b, 3);
			else
				ToMau(i, j, b, 2);
		}
	}
	ToMau(42, 8, d, 4);
	ToMau(43, 10, e, 4);
	ToMau(28, 12, f, 4);
	ToMau(28, 16, g, 4);
	ToMau(30, 20, h, 4);



	ToMau1kitu(38, 11, (char)218, 7);
	ToMau1kitu(38, 13, (char)192, 7);
	ToMau1kitu(38, 12, (char)179, 7);
	ToMau1kitu(68, 12, (char)179, 7);

	ToMau1kitu(68, 11, (char)191, 7);
	ToMau1kitu(68, 13, (char)217, 7);

	ToMau1kitu(38, 15, (char)218, 7);
	ToMau1kitu(38, 17, (char)192, 7);
	ToMau1kitu(38, 16, (char)179, 7);
	ToMau1kitu(68, 16, (char)179, 7);

	ToMau1kitu(68, 15, (char)191, 7);
	ToMau1kitu(68, 17, (char)217, 7);
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 16, ' ', 0);

	}
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 12, ' ', 0);

	}
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 15, (char)196, 7);

	}
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 11, (char)196, 7);

	}
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 17, (char)196, 7);

	}
	for (int i = 39; i < 68; i++)
	{
		ToMau1kitu(i, 13, (char)196, 7);

	}
	for (int i = 25; i < 72; i++)
	{
		ToMau1kitu(i, 7, (char)220, 7);
	}
	for (int i = 8; i < 27; i++)
	{
		ToMau1kitu(25, i, (char)221, 7);
	}
	for (int i = 25; i < 72; i++)
	{
		ToMau1kitu(i, 27, (char)223, 7);
	}
	for (int i = 8; i < 27; i++)
	{
		ToMau1kitu(71, i, (char)222, 7);
	}

}