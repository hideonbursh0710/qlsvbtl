#pragma once
#ifndef _QLSV
#define _QLSV

#include "SinhVien.h";

class QLSV : public SinhVien {
private:
	int n;
	SinhVien* sv;
public:
	QLSV();
	void Nhap();
	void Xuat();
	void ThemSinhVien();
	bool kiemTraDanhSach();
	int timKiemTheoID(int ms);
	int timMaSoTrung(int ms);
	SinhVien getSinhVien(int ms);
	SinhVien* timKiemTheoTen(string ten);
	void SapXepSinhVienTheoDiem();
	void chinhSuaThongTin(int ms);
	void xoaSinhVienTheoID(int ms);
	void ghiFile();
};

#endif // !_QLSV


