#include <iostream>
#include "cTamGiac.h"
using namespace std;

int main() {
    cTamGiac tg;
    cout << "--- NHAP TAM GIAC ---\n";
    tg.Nhap();

    cout << "\nToa do cac dinh: "; tg.Xuat();
    cout << "\nLoai tam giac: "; tg.PhanLoai();
    cout << "\nChu vi: " << tg.ChuVi();
    cout << "\nDien tich: " << tg.DienTich();

    cout << "\n\n--- THAO TAC BIEN DOI ---";
    tg.TinhTien(2, 3);
    cout << "\nSau khi tinh tien (dx=2, dy=3): "; tg.Xuat();

    tg.PhongTo(2);
    cout << "\nSau khi phong to (k=2): "; tg.Xuat();

    tg.ThuNho(2);
    cout << "\nSau khi thu nho (k=2): "; tg.Xuat();

    tg.Quay(90);
    cout << "\nSau khi quay 90 do: "; tg.Xuat();
    cout << "\n";

    return 0;
}