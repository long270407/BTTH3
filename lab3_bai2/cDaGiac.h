#ifndef CDAGIAC_H
#define CDAGIAC_H

class cDiem {
public:
    float x, y;
    cDiem();
    cDiem(float _x, float _y);
    void Nhap();
    void Xuat();
    float KhoangCach(cDiem d);
};

class cDaGiac {
private:
    int n;          // Số lượng đỉnh
    cDiem* dinh;    // Mảng động lưu các đỉnh
public:
    cDaGiac();
    ~cDaGiac();     // Hàm hủy để giải phóng bộ nhớ

    void Nhap();
    void Xuat();
    float ChuVi();

    // Các phép biến đổi hình học
    void TinhTien(float dx, float dy);
    void Quay(float goc);
    void PhongTo(float k);
    void ThuNho(float k);
};

#endif