#ifndef _SinhVien
#define _SinhVien

#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

class SinhVien {
private:
	int id;
	string name;
	int date;
	int month;
	int year;
	string gender;
	string email;
	float diem;
public:
	SinhVien();
	SinhVien(int, string, int, int, int, string, string, float);
	int getID();
	int getDate();
	int getMonth();
	int getYear();
	string getName();
	string getGender();
	string getEmail();
	float getDiem();
	bool checkName(string);
	bool checkBirthday(string);
	bool checkGender(string);
	bool checkBirthday(int, int, int);
	bool isChar(char);
	bool isDigit(char);
	bool checkDiem(float);
	bool checkEmail(string);
	void nhapThongTin();
	void suaThongTin();
	void xuatThongTin();
};

#endif
#pragma once
