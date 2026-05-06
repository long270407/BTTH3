#include <iostream>
#include "cDaThuc.h"
using namespace std;

int main() {
    cDaThuc p1, p2;

    cout << "--- Nhap da thuc P1 ---\n";
    p1.Nhap();
    cout << "--- Nhap da thuc P2 ---\n";
    p2.Nhap();

    cout << "\nP1(x) = "; p1.Xuat();
    cout << "P2(x) = "; p2.Xuat();

    cDaThuc tong = p1.Cong(p2);
    cout << "\nTong P1 + P2 = "; tong.Xuat();

    cDaThuc hieu = p1.Tru(p2);
    cout << "Hieu P1 - P2 = "; hieu.Xuat();

    float x;
    cout << "\nNhap gia tri x de tinh P1(x): ";
    cin >> x;
    cout << "Gia tri P1(" << x << ") = " << p1.TinhGiaTri(x) << endl;

    return 0;
}