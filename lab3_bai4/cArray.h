#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
    int* arr;       // Con trỏ quản lý mảng động
    int n;          // Số lượng phần tử

    // Hàm phụ trợ (không cho phép truy cập từ ngoài)
    bool KiemTraSNT(int x);

public:
    cArray();
    ~cArray();

    void TaoNgauNhien(int size);
    void Xuat();
    int DemX(int x);
    bool KiemTraTangDan();
    int TimLeNhoNhat();
    int TimSNTLonNhat();
    void SapXepTang();
    void SapXepGiam();
};

#endif