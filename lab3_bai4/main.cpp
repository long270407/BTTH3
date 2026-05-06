#include <iostream>
#include "cArray.h"
using namespace std;

int main() {
    cArray a;
    int n, x;

    cout << "--- KHOI TAO MANG NGAU NHIEN ---\n";
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    a.TaoNgauNhien(n);
    cout << "Mang ngau nhien vua tao: ";
    a.Xuat(); cout << "\n";

    cout << "\n--- THONG KE & TIM KIEM ---\n";
    cout << "Nhap gia tri x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << a.DemX(x) << "\n";

    if (a.KiemTraTangDan()) cout << "-> Mang hien tai dang xep tang dan.\n";
    else cout << "-> Mang hien tai KHONG xep tang dan.\n";

    int leNhoNhat = a.TimLeNhoNhat();
    if (leNhoNhat != -1) cout << "So le nho nhat trong mang: " << leNhoNhat << "\n";
    else cout << "Khong co so le nao trong mang.\n";

    int sntLonNhat = a.TimSNTLonNhat();
    if (sntLonNhat != -1) cout << "So nguyen to lon nhat trong mang: " << sntLonNhat << "\n";
    else cout << "Khong co so nguyen to nao trong mang.\n";

    cout << "\n--- SAP XEP MANG ---\n";
    a.SapXepTang();
    cout << "Mang sau khi sap xep tang: ";
    a.Xuat(); cout << "\n";

    a.SapXepGiam();
    cout << "Mang sau khi sap xep giam: ";
    a.Xuat(); cout << "\n";

    return 0;
}