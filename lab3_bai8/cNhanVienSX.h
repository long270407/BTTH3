#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H
#include <string>
using namespace std;

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    int namSinh;
    int soSP;
    float donGia;

public:
    // Constructor mặc định
    cNhanVienSX();

    // Các phương thức cơ bản
    void Nhap();
    void Xuat();
    float TinhLuong();

    // Getter để hỗ trợ tìm kiếm ở hàm main
    int GetNamSinh();
    string GetHoTen();
};

#endif#pragma once
