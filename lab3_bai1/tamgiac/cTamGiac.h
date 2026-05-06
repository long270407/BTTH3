#ifndef CTAMGIAC_H
#define CTAMGIAC_H

class cDiem {
public:
    float x, y;
    cDiem(); // Hàm thiết lập mặc định
    cDiem(float _x, float _y);
    void Nhap();
    void Xuat();
    float KhoangCach(cDiem d);
};

class cTamGiac {
private:
    cDiem A, B, C;
public:
    cTamGiac(); // Hàm thiết lập mặc định
    void Nhap();
    void Xuat();
    float ChuVi();
    float DienTich();
    void PhanLoai();
    void TinhTien(float dx, float dy);
    void Quay(float goc); // Góc tính bằng độ
    void PhongTo(float k);
    void ThuNho(float k);
};

#endif