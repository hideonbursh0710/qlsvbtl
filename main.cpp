#include "QLSV.h";

int main() {
	QLSV q;

	int menu = 1;
	while (menu != 0) {
		cout << "-----------------------Quan Ly Sinh Vien-------------------------\n";
		cout << "| 1. Nhap danh sach sinh vien                                   |\n";
		cout << "| 2. Xuat danh sach sinh vien                                   |\n";
		cout << "| 3. Them sinh vien                                             |\n";
		cout << "| 4. Tim kiem sinh vien theo ten                                |\n";
		cout << "| 5. Tim kiem sinh vien theo ma so                              |\n";
		cout << "| 6. Sap xep sinh vien theo diem so tang dan                    |\n";
		cout << "| 7. Chinh sua sinh vien theo ma so                             |\n";
		cout << "| 8. Xoa bo sinh vien theo ma so                                |\n";
		cout << "| 9. Xuat danh sach sinh vien ra file                           |\n";
		cout << "| 0. Thoat chuong trinh                                         |\n";
		cout << "-----------------------------------------------------------------\n";

		cout << "\nBan chon chuong trinh nao: ";
		cin >> menu;

		switch (menu) {
		case 0:
		{
			cout << "Cam on ban da su dung chuong trinh";
			break;
		}
		case 1:
		{
			q.Nhap();
			break;
		}
		case 2:
		{
			if (q.kiemTraDanhSach()) q.Xuat();
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			break;
		}
		case 3:
		{
			q.ThemSinhVien();
			break;
		}
		case 4:
		{
			if (q.kiemTraDanhSach()) {
				cin.ignore();
				string ten;
				cout << "Nhap ten sinh vien can tim: ";
				getline(cin, ten);
				SinhVien* arr = q.timKiemTheoTen(ten);
				int sl = sizeof(arr) / sizeof(int);
				if (sl != 0)
				{
					cout << "\nDanh sach sinh vien co ten " << ten << " la: ";
					for (int i = 0; i < sl; i++) {
						if (arr[i].getName() != "")
						{
							cout << "\nSinh vien thu " << i + 1 << ": \n";
							arr[i].xuatThongTin();
						}
						else break;
					}
					delete[]arr;
				}
				else cout << "Khong co sinh vien nao co ten " << ten << " nhu vay!\n";
			}
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			break;
		}
		case 5:
		{
			if (q.kiemTraDanhSach()) {
				int ms;
				cout << "Nhap ma so sinh vien can tim kiem: ";
				cin >> ms;

				SinhVien res = q.getSinhVien(ms);
				if (res.getName() != "") {
					cout << "\nThong tin cua sinh vien co ma so " << ms << " la: \n";
					res.xuatThongTin();
				}
				else {
					cout << "\nKhong co sinh vien nao co ma so " << ms << " trong he thong\n";
				}
			}
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";

			break;
		}
		case 6:
		{
			if (q.kiemTraDanhSach()) {
				q.SapXepSinhVienTheoDiem();

				cout << "\nDanh sach sinh vien sau khi sap xep la: \n";
				q.Xuat();
			}
			else {
				cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			}

			break;
		}
		case 7:
		{
			if (q.kiemTraDanhSach()) {
				int ms;
				cout << "Nhap ma so sinh vien can sua doi thong tin: ";
				cin >> ms;

				q.chinhSuaThongTin(ms);
			}
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			break;
		}
		case 8:
		{
			if (q.kiemTraDanhSach()) {
				int ms;
				cout << "Nhap ma so sinh vien can xoa bo: ";
				cin >> ms;
				q.xoaSinhVienTheoID(ms);
			}
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			break;
		}
		case 9:
		{
			if (q.kiemTraDanhSach()) {
				q.ghiFile();
			}
			else cout << "\nVui long nhap vao danh sach sinh vien truoc!";
			break;
		}
		default:
			cout << "\nRat tiec, khong co menu nao hop le";
		};
		cout << "\n";
		system("pause");
		system("cls");
	}
	return 0;
}