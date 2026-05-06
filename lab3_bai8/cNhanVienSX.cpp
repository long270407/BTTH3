#include <iostream>
#include <iomanip> // Hỗ trợ định dạng khoảng cách khi in
#include "cNhanVienSX.h"
using namespace std;

cNhanVienSX::cNhanVienSX() {
    maNV = "";
    hoTen = "";
    namSinh = 0;
    soSP = 0;
    donGia = 0;
}

void cNhanVienSX::Nhap() {
    cout << "Nhap ma NV: ";
    cin >> maNV;

    cout << "Nhap ho ten: ";
    cin.ignore(); // Xóa bộ đệm bàn phím trước khi nhập chuỗi có khoảng trắng
    getline(cin, hoTen);

    cout << "Nhap nam sinh: ";
    cin >> namSinh;

    cout << "Nhap so san pham: ";
    cin >> soSP;

    cout << "Nhap don gia: ";
    cin >> donGia;
}

void cNhanVienSX::Xuat() {
    // In theo định dạng cột cho đẹp
    cout << left << setw(10) << maNV
        << "| " << setw(20) << hoTen
        << "| " << setw(10) << namSinh
        << "| " << setw(15) << (long long)TinhLuong() << " VND" << endl;
}

float cNhanVienSX::TinhLuong() {
    return soSP * donGia;
}

int cNhanVienSX::GetNamSinh() {
    return namSinh;
}

string cNhanVienSX::GetHoTen() {
    return hoTen;
}