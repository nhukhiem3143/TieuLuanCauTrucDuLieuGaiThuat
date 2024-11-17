#include <iostream>
using namespace std;

// Hàm tìm kiếm tuần tự
int SEQUEN_SEARCH(int k[], int n, int X) {
    int i = 0;
    k[n] = X;  // Đặt khóa X vào vị trí k[n]
    int dem = 0;  // Biến đếm số lần so sánh

    // Tìm kiếm khóa X trong mảng
    while (k[i] != X) {
        dem++;  // Tăng số lần so sánh
        cout << "So sanh lan " << dem << ": k[" << (i + 1) << "] = " << k[i] << endl; // In chi tiết so sánh
        i++;
    }

    dem++;  // Đếm so sánh cuối khi tìm thấy hoặc kết thúc
    cout << "So sanh lan " << dem << ": k[" << (i + 1) << "] = " << k[i] << endl;

    return i + 1;  // Trả về vị trí của phần tử (tính từ 1)
}

int main() {
    int k[] = {3, 1, 0, 5, 2, 0, 0, 4};  // Dữ liệu mảng
    int n = sizeof(k) / sizeof(k[0]);  // Số phần tử trong mảng
    int X;

    // In ra mảng
    cout << "Mang du lieu nhap vao: [";
    for (int i = 0; i < n; i++) {
        cout << k[i] << " ";
    }
    cout << "]" << endl;

    cout << "=============================================" << endl;

    // Nhập giá trị cần tìm
    cout << "Nhap gia tri can tim: "; cin >> X;  
    cout <<endl;

    // Gọi hàm tìm kiếm và in kết quả
    int ket_qua = SEQUEN_SEARCH(k, n, X);
    
    cout << "=============================================" << endl;
    if (ket_qua == n + 1) {
        cout << "\nKhong tim thay phan tu." << endl;
    } else {
        // In kết quả với vị trí bắt đầu từ 1
        cout << "\nTim thay phan tu tai vi tri: " << ket_qua << endl;
    }

    return 0;
}
