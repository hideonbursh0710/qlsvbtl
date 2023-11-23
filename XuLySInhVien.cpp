#include "SinhVien.h"

SinhVien::SinhVien() {
	id = 0;
	name = "";
	date = 1;
	month = 1;
	year = 1930;
	gender = "";
	email = "";
	diem = 0;
}

SinhVien::SinhVien(int ms, string ten, int ng, int th, int nm, string gt, string mail, float score) {
	id = ms;
	name = ten;
	date = ng;
	month = th;
	year = nm;
	gender = gt;
	email = mail;
	diem = score;
}

int SinhVien::getID() {
	return id;
}

int SinhVien::getDate() {
	return date;
}

int SinhVien::getMonth() {
	return month;
}

int SinhVien::getYear() {
	return year;
}

string SinhVien::getName() {
	return name;
}

string SinhVien::getGender() {
	return gender;
}

string SinhVien::getEmail() {
	return email;
}

float SinhVien::getDiem() {
	return diem;
}
void SinhVien::nhapThongTin() {
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin, name);

	while (!checkName(name)) {
		cout << "Ten khong hop le, vui long nhap lai: ";
		cin.ignore();
		getline(cin, name);
	}

	cout << "Nhap mssv: ";
	cin >> id;
	while (!checkID(ms)) {
		cout << "ID khong hop le, vui long nhap lai: ";
		cin >> ID;
	}
	cout << "Nhap ngay, thang, nam sinh: ";
	cin >> date >> month >> year;
	while (!checkBirthday(date, month, year)) {
		cout << "Ngay, thang, nam sinh khong hop le, vui long nhap lai: ";
		cin >> date >> month >> year;
	}

	cout << "Nhap gioi tinh: ";
	cin >> gender;
	while (!checkGender(gender)) {
		cout << "Gioi tinh khong hop le, vui long nhap lai: ";
		cin >> gender;
	}

	cout << "Nhap email: ";
	cin >> email;
	while (!checkEmail(email)) {
		cout << "Email khong hop le, vui long nhap lai: ";
		cin >> email;
	}

	cout << "Nhap diem: ";
	cin >> diem;
	while (!checkDiem(diem)) {
		cout << "Diem khong hop le, vui long nhap lai: ";
		cin >> diem;
	}

}

void SinhVien::xuatThongTin() {
	cout << "MSSV: " << id << "\n";
	cout << "Ho va ten: " << name << "\n";
	cout << "Ngay sinh: " << date << "/" << month << "/" << year << "\n";
	cout << "Gioi tinh: " << gender << "\n";
	cout << "Email: " << email << "\n";
	cout << "Diem: " << diem << "\n";
}

void SinhVien::suaThongTin() {
	cout << "Nhap vao cac thong tin can chinh sua: \n";
	SinhVien sv;
	sv.nhapThongTin();
}

bool SinhVien::checkName(string ten) {
	for (char c : ten) {
		if (!isalpha(c) && !isspace(c))
			return false;
	}
	return true;
}

bool SinhVien::checkGender(string gender) {
	transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
	if (gender != "nam" && gender != "nu") return false;
	return true;
}

bool SinhVien::checkEmail(string email)
{
	if (!isalpha(email[0])) {
		return 0;
	}
	int At = -1, Dot = -1;
	for (int i = 0;
		i < email.length(); i++) {
		if (email[i] == '@') {

			At = i;
		}
		else if (email[i] == '.') {

			Dot = i;
		}
	}
	if (At == -1 || Dot == -1)
		return 0;
	if (At > Dot)
		return 0;
	return !(Dot >= (email.length() - 1));
}

bool SinhVien::checkBirthday(int ns, int th, int nm) {
	if (nm < 1923 || nm > 2013) return false;
	if (th == 1) return ns >= 1 && ns <= 31;
	else if (th == 2) return ns >= 1 && ns <= 29;
	else if (th == 3) return ns >= 1 && ns <= 31;
	else if (th == 4) return ns >= 1 && ns <= 30;
	else if (th == 5) return ns >= 1 && ns <= 31;
	else if (th == 6) return ns >= 1 && ns <= 30;
	else if (th == 7) return ns >= 1 && ns <= 31;
	else if (th == 8) return ns >= 1 && ns <= 31;
	else if (th == 9) return ns >= 1 && ns <= 30;
	else if (th == 10) return ns >= 1 && ns <= 31;
	else if (th == 11) return ns >= 1 && ns <= 30;
	else if (th == 12) return ns >= 1 && ns <= 31;
	else return false;
}

bool SinhVien::checkDiem(float diem) {
	if (diem >= 0 && diem <= 10) return true;
	else return false;
}