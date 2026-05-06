#ifndef CDATHUC_H
#define CDATHUC_H

const int MAX = 100; // Giới hạn bậc đa thức tối đa là 99

class cDaThuc {
private:
    int n;          // Bậc của đa thức
    float a[MAX];   // Mảng tĩnh lưu hệ số. a[i] là hệ số của x^i

public:
    cDaThuc();      // Khởi tạo mặc định
    void Nhap();
    void Xuat();
    float TinhGiaTri(float x);
    cDaThuc Cong(cDaThuc dt);
    cDaThuc Tru(cDaThuc dt);
};

#endif