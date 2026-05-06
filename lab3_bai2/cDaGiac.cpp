#include <iostream>
#include <cmath>
#include "cDaGiac.h"
using namespace std;

const float PI = 3.14159265358979323846;

// --- Cài đặt lớp cDiem ---
cDiem::cDiem() : x(0), y(0) {}
cDiem::cDiem(float _x, float _y) : x(_x), y(_y) {}
void cDiem::Nhap() { cin >> x >> y; }
void cDiem::Xuat() { cout << "(" << x << ", " << y << ")"; }
float cDiem::KhoangCach(cDiem d) {
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

// --- Cài đặt lớp cDaGiac ---
cDaGiac::cDaGiac() {
    n = 0;
    dinh = nullptr;
}

cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh;
    }
}

void cDaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;
    } while (n < 3);

    dinh = new cDiem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
        dinh[i].Nhap();
    }
}

void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        dinh[i].Xuat();
        if (i < n - 1) cout << ", ";
    }
}

float cDaGiac::ChuVi() {
    if (n < 3) return 0;
    float cv = 0;
    for (int i = 0; i < n; i++) {
        // Cộng khoảng cách từ đỉnh i tới đỉnh i+1 (đỉnh cuối nối về đỉnh 0)
        cv += dinh[i].KhoangCach(dinh[(i + 1) % n]);
    }
    return cv;
}

void cDaGiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].x += dx;
        dinh[i].y += dy;
    }
}

void cDaGiac::Quay(float goc) {
    float rad = goc * PI / 180.0;
    for (int i = 0; i < n; i++) {
        float newX = dinh[i].x * cos(rad) - dinh[i].y * sin(rad);
        float newY = dinh[i].x * sin(rad) + dinh[i].y * cos(rad);
        dinh[i].x = newX;
        dinh[i].y = newY;
    }
}

void cDaGiac::PhongTo(float k) {
    for (int i = 0; i < n; i++) {
        dinh[i].x *= k;
        dinh[i].y *= k;
    }
}

void cDaGiac::ThuNho(float k) {
    if (k != 0) {
        for (int i = 0; i < n; i++) {
            dinh[i].x /= k;
            dinh[i].y /= k;
        }
    }
}