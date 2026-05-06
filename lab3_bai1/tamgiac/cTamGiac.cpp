#include <iostream>
#include <cmath>
#include "cTamGiac.h"
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

// --- Cài đặt lớp cTamGiac ---
cTamGiac::cTamGiac() {
    // Thiết lập mặc định là 3 đỉnh tạo thành 1 tam giác hợp lệ
    A = cDiem(0, 0);
    B = cDiem(0, 1);
    C = cDiem(1, 0);
}

void cTamGiac::Nhap() {
    cout << "Nhap dinh A (x, y): "; A.Nhap();
    cout << "Nhap dinh B (x, y): "; B.Nhap();
    cout << "Nhap dinh C (x, y): "; C.Nhap();
}

void cTamGiac::Xuat() {
    A.Xuat(); cout << ", "; B.Xuat(); cout << ", "; C.Xuat();
}

float cTamGiac::ChuVi() {
    return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);
}

float cTamGiac::DienTich() {
    float a = B.KhoangCach(C);
    float b = A.KhoangCach(C);
    float c = A.KhoangCach(B);
    float p = (a + b + c) / 2; // Nửa chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Công thức Heron
}

void cTamGiac::PhanLoai() {
    float a = B.KhoangCach(C), b = A.KhoangCach(C), c = A.KhoangCach(B);
    // Sử dụng sai số epsilon để so sánh số thực
    float eps = 0.001;

    if (abs(a - b) < eps && abs(b - c) < eps) {
        cout << "Tam giac deu";
    }
    else if (abs(a - b) < eps || abs(b - c) < eps || abs(a - c) < eps) {
        // Kiểm tra thêm có vuông cân không
        if (abs(a * a + b * b - c * c) < eps || abs(a * a + c * c - b * b) < eps || abs(b * b + c * c - a * a) < eps)
            cout << "Tam giac vuong can";
        else
            cout << "Tam giac can";
    }
    else if (abs(a * a + b * b - c * c) < eps || abs(a * a + c * c - b * b) < eps || abs(b * b + c * c - a * a) < eps) {
        cout << "Tam giac vuong";
    }
    else {
        cout << "Tam giac thuong";
    }
}

void cTamGiac::TinhTien(float dx, float dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void cTamGiac::Quay(float goc) {
    // Đổi góc từ độ sang radian
    float rad = goc * PI / 180.0;

    // Thuật toán xoay điểm quanh gốc toạ độ (0,0)
    float newAx = A.x * cos(rad) - A.y * sin(rad);
    float newAy = A.x * sin(rad) + A.y * cos(rad);
    A.x = newAx; A.y = newAy;

    float newBx = B.x * cos(rad) - B.y * sin(rad);
    float newBy = B.x * sin(rad) + B.y * cos(rad);
    B.x = newBx; B.y = newBy;

    float newCx = C.x * cos(rad) - C.y * sin(rad);
    float newCy = C.x * sin(rad) + C.y * cos(rad);
    C.x = newCx; C.y = newCy;
}

void cTamGiac::PhongTo(float k) {
    // Phóng to dựa trên gốc toạ độ
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}

void cTamGiac::ThuNho(float k) {
    if (k != 0) {
        A.x /= k; A.y /= k;
        B.x /= k; B.y /= k;
        C.x /= k; C.y /= k;
    }
}