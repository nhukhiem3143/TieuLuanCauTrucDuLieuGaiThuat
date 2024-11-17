#include <iostream>
#include <stdbool.h>
#define MAX 8

using namespace std;

// Khai báo mảng list chứa 8 phần tử.
int list[MAX] = {3, 1, 0, 5, 2, 0, 0, 4};

// Hàm để in mảng list ra màn hình.
void In() {
    cout << "[";
    for(int i = 0; i < MAX; i++) {
        cout << list[i] << " ";  // In từng phần tử trong mảng.
    }
    cout << "]\n";  // Kết thúc và chuyển dòng.
}

// Hàm sắp xếp mảng sử dụng thuật toán Bubble Sort.
void bubbleSort() {
    int temp;  // Biến tạm để hoán đổi giá trị của các phần tử.
    int i, j;
    bool swapped = false;  // Biến để kiểm tra xem có trao đổi gì không.

    // Vòng lặp ngoài kiểm tra số lần lặp lại.
    for(i = 0; i < MAX - 1; i++) {
        swapped = false;  // Mỗi vòng lặp ngoài bắt đầu lại với swapped = false.

        // Vòng lặp trong duyệt qua các cặp phần tử liền kề.
        for(j = 0; j < MAX - 1 - i; j++) {
            cout << "\tSo sanh : [ " << list[j] << ", " << list[j+1] << " ] ";

            // So sánh hai phần tử liền kề và hoán đổi nếu phần tử trước lớn hơn.
            if(list[j] > list[j+1]) {
                temp = list[j];  // Lưu giá trị list[j] vào temp.
                list[j] = list[j+1];  // Đổi giá trị của list[j] với list[j+1].
                list[j+1] = temp;  // Đổi giá trị của list[j+1] với giá trị đã lưu trong temp.

                swapped = true;  // Đánh dấu là đã có trao đổi.
                cout << " => trao doi [" << list[j] << ", " << list[j+1] << "]\n";  // In ra thông tin hoán đổi.
            } else {
                cout << " => khong can trao doi\n";  // Nếu không cần trao đổi.
            }
        }

        // Nếu không có bất kỳ trao đổi nào xảy ra, thuật toán đã hoàn tất.
        if(!swapped) {
            break;
        }

        // In ra mảng sau mỗi vòng lặp ngoài.
        cout << "\nVong lap thu " << (i + 1) << " : ";
        In();
    }
}

int main() {
    cout << "\033[1;33mMang du lieu dau vao: ";
    In();  // In ra mảng ban đầu.
    cout << "\n";

    bubbleSort();  // Gọi hàm bubbleSort để sắp xếp mảng.

    cout << "\nMang sau khi da sap xep: ";
    In();  // In ra mảng sau khi đã sắp xếp.
    return 0;  // Kết thúc chương trình.
}
