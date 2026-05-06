#include <iostream>
#include <iomanip>
#include "cNhanVienSX.h"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;

    // Cấp phát mảng động lưu danh sách nhân viên
    cNhanVienSX* ds = new cNhanVienSX[n];

    cout << "\n--- NHAP THONG TIN NHAN VIEN ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    cout << left << setw(10) << "Ma NV"
        << "| " << setw(20) << "Ho Ten"
        << "| " << setw(10) << "Nam Sinh"
        << "| " << setw(15) << "Luong" << endl;
    cout << "------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    // --- CÁC THAO TÁC THỐNG KÊ ---
    float minLuong = ds[0].TinhLuong();
    float tongLuong = 0;
    int minNamSinh = ds[0].GetNamSinh(); // Năm sinh nhỏ nhất -> Tuổi lớn nhất

    int idxLuongThap = 0;
    int idxTuoiCao = 0;

    for (int i = 0; i < n; i++) {
        float luongHT = ds[i].TinhLuong();
        tongLuong += luongHT;

        if (luongHT < minLuong) {
            minLuong = luongHT;
            idxLuongThap = i;
        }

        if (ds[i].GetNamSinh() < minNamSinh) {
            minNamSinh = ds[i].GetNamSinh();
            idxTuoiCao = i;
        }
    }

    cout << "\n--- KET QUA THONG KE ---\n";
    cout << "+ Tong luong cong ty phai tra: " << (long long)tongLuong << " VND\n";
    cout << "+ Nhan vien co luong thap nhat: " << ds[idxLuongThap].GetHoTen() << " (" << (long long)minLuong << " VND)\n";
    cout << "+ Nhan vien co tuoi cao nhat: " << ds[idxTuoiCao].GetHoTen() << " (Sinh nam " << ds[idxTuoiCao].GetNamSinh() << ")\n";

    // --- SẮP XẾP TĂNG DẦN THEO LƯƠNG ---
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\n--- DANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG ---\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    // Giải phóng bộ nhớ
    delete[] ds;
    return 0;
}