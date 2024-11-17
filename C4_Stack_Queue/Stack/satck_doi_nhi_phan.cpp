#include <iostream>
using namespace std;

class Cstack {
private:
    int* StkArr;  // Mảng để lưu các phần tử của stack
    int StkMax;   // Kích thước tối đa của stack
    int StkTop;   // Vị trí đỉnh của stack

public:
    // Hàm khởi tạo stack với kích thước cho trước
    Cstack(int size) {
        StkArr = new int[size];
        StkMax = size;
        StkTop = -1;
    }

    // Hàm kiểm tra stack có rỗng hay không
    bool isEmpty() {
        return StkTop == -1;
    }

    // Hàm kiểm tra stack có đầy hay không
    bool isFull() {
        return StkTop == StkMax - 1;
    }

    // Hàm đẩy phần tử vào stack
    void push(int value) {
        if (!isFull()) {
            StkArr[++StkTop] = value;
        } else {
            cout << "Stack đầy, không thể thêm phần tử!\n";
        }
    }

    // Hàm lấy phần tử từ stack ra
    int pop() {
        if (!isEmpty()) {
            return StkArr[StkTop--];
        } else {
            cout << "Stack rỗng, không thể lấy phần tử!\n";
            return -1;
        }
    }

    // Hàm hủy (destructor) để giải phóng bộ nhớ
    ~Cstack() {
        delete[] StkArr;
    }
};

void thap_sang_nhi(int n) {
    Cstack nhi_phan(32);  // Khởi tạo stack với kích thước 32 (đủ lớn cho số nguyên)
    
    // Chuyển đổi số thập phân sang nhị phân
    while (n > 0) {
        nhi_phan.push(n % 2); // Lưu phần dư vào stack
        n /= 2;
    }

    // In ra các phần tử trong stack để biểu diễn số nhị phân
    while (!nhi_phan.isEmpty()) {
        cout << nhi_phan.pop();
    }
}

int main() {
    int k;
    cout << "Nhap so thap phan : "; cin >>k;
    cout << k << " (thap phan) = ";
    thap_sang_nhi(k);
    cout << " (nhi phan)" ;
}
