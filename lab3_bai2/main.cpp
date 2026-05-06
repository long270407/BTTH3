#include <iostream>
#include "cDaGiac.h"
using namespace std;

int main() {
    cDaGiac dg;
    cout << "--- KHOI TAO DA GIAC ---\n";
    dg.Nhap();

    cout << "\nDa giac vua nhap: ";
    dg.Xuat();

    cout << "\nChu vi da giac: " << dg.ChuVi();

    cout << "\n\n--- THAO TAC BIEN DOI ---";
    dg.TinhTien(2, 2);
    cout << "\nSau khi tinh tien (dx=2, dy=2): ";
    dg.Xuat();

    dg.PhongTo(2);
    cout << "\nSau khi phong to (k=2): ";
    dg.Xuat();

    dg.Quay(90);
    cout << "\nSau khi quay 90 do quanh goc toa do: ";
    dg.Xuat();
    cout << "\n";

    return 0;
}