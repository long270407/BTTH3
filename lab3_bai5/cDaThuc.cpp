#include <iostream>
#include <cmath>
#include <algorithm> // Để dùng hàm max()
#include "cDaThuc.h"
using namespace std;

// Khởi tạo mặc định: Đa thức bậc 0, tất cả hệ số = 0
cDaThuc::cDaThuc() {
    n = 0;
    for (int i = 0; i < MAX; i++) {
        a[i] = 0;
    }
}

void cDaThuc::Nhap() {
    do {
        cout << "Nhap bac cua da thuc (0 -> " << MAX - 1 << "): ";
        cin >> n;
    } while (n < 0 || n >= MAX);

    // Reset lại toàn bộ mảng về 0 trước khi nhập mới
    for (int i = 0; i < MAX; i++) a[i] = 0;

    for (int i = n; i >= 0; i--) {
        cout << "He so cua x^" << i << ": ";
        cin >> a[i];
    }
}

void cDaThuc::Xuat() {
    // Nếu là đa thức 0 hoàn toàn
    if (n == 0 && a[0] == 0) {
        cout << "0" << endl;
        return;
    }

    bool laHangTuDauTien = true;
    for (int i = n; i >= 0; i--) {
        if (a[i] == 0) continue; // Bỏ qua hạng tử có hệ số 0

        // Xử lý in dấu
        if (a[i] > 0 && !laHangTuDauTien) cout << " + ";
        if (a[i] < 0) cout << " - ";

        // In giá trị tuyệt đối của hệ số (bỏ qua nếu hệ số là 1 hoặc -1, trừ hạng tử tự do)
        if (abs(a[i]) != 1 || i == 0) cout << abs(a[i]);

        // In phần biến x
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i; // Chỉ in mũ nếu bậc > 1
        }
        laHangTuDauTien = false;
    }
    cout << endl;
}

float cDaThuc::TinhGiaTri(float x) {
    float ketQua = 0;
    for (int i = 0; i <= n; i++) {
        ketQua += a[i] * pow(x, i); // Hệ số * x^i
    }
    return ketQua;
}

cDaThuc cDaThuc::Cong(cDaThuc dt) {
    cDaThuc kq;
    kq.n = max(n, dt.n); // Bậc lớn nhất
    for (int i = 0; i <= kq.n; i++) {
        kq.a[i] = a[i] + dt.a[i];
    }
    return kq;
}

cDaThuc cDaThuc::Tru(cDaThuc dt) {
    cDaThuc kq;
    kq.n = max(n, dt.n); // Bậc lớn nhất
    for (int i = 0; i <= kq.n; i++) {
        kq.a[i] = a[i] - dt.a[i];
    }
    // Thu gọn đa thức (tìm bậc thực sự) sau khi trừ (nếu hạng tử cao nhất bị triệt tiêu)
    while (kq.n > 0 && kq.a[kq.n] == 0) {
        kq.n--;
    }
    return kq;
}