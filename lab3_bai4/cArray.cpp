#include <iostream>
#include <cstdlib> // Cung cấp hàm rand(), srand()
#include <ctime>   // Cung cấp hàm time()
#include "cArray.h"
using namespace std;

// --- Khởi tạo và Hủy ---
cArray::cArray() {
    arr = nullptr;
    n = 0;
}

cArray::~cArray() {
    if (arr != nullptr) {
        delete[] arr; // Giải phóng bộ nhớ
    }
}

// --- Hàm phụ trợ ---
bool cArray::KiemTraSNT(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// --- Các phương thức chính ---
void cArray::TaoNgauNhien(int size) {
    if (arr != nullptr) delete[] arr; // Xóa mảng cũ nếu có
    n = size;
    arr = new int[n];

    srand(time(0)); // Khởi tạo hạt giống (seed) ngẫu nhiên theo thời gian thực
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Sinh số ngẫu nhiên từ 0 đến 99
    }
}

void cArray::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int cArray::DemX(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

bool cArray::KiemTraTangDan() {
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int cArray::TimLeNhoNhat() {
    int minLe = -1; // Giả sử -1 là không tìm thấy (do mảng rand() toàn số dương)
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) { // Kiểm tra số lẻ
            if (!found || arr[i] < minLe) {
                minLe = arr[i];
                found = true;
            }
        }
    }
    return minLe;
}

int cArray::TimSNTLonNhat() {
    int maxSNT = -1; // Giả sử -1 là không tìm thấy
    for (int i = 0; i < n; i++) {
        if (KiemTraSNT(arr[i])) {
            if (maxSNT == -1 || arr[i] > maxSNT) {
                maxSNT = arr[i];
            }
        }
    }
    return maxSNT;
}

void cArray::SapXepTang() {
    // Thuật toán Selection Sort (Sắp xếp chọn)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void cArray::SapXepGiam() {
    // Thuật toán Selection Sort 
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
    }
}