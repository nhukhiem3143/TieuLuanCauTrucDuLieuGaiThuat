#include <iostream>
#include <stdbool.h>
#define MAX 8

using namespace std;

int intArray[MAX] = {3, 1, 0, 5, 2, 0, 0, 4};

void In() {
    cout << "[";
    for (int i = 0; i < MAX; i++) {
        cout << intArray[i] << " ";
    }
    cout << "]\n";
}

void insertionSort() {
    int valueToInsert;
    int holePosition;

    for (int i = 1; i < MAX; i++) {
        valueToInsert = intArray[i];
        holePosition = i;
        bool moved = false; // Biến để kiểm tra xem có di chuyển phần tử nào hay không

        // Sử dụng vòng lặp để di chuyển các phần tử lớn hơn giá trị cần chèn
        while (holePosition > 0 && intArray[holePosition - 1] > valueToInsert) {
            intArray[holePosition] = intArray[holePosition - 1];
            holePosition--;
            moved = true; // Có di chuyển phần tử
            cout << "\tDi chuyen phan tu : " << intArray[holePosition] << "\n";
        }

        // Nếu có thay đổi vị trí chèn, thực hiện chèn
        if (holePosition != i) {
            cout << "\tChen phan tu : " << valueToInsert << ", tai vi tri : " << holePosition << "\n";
            intArray[holePosition] = valueToInsert;
        } else if (!moved) {
            // Nếu không có thay đổi và không di chuyển, thông báo
            cout << "\tKhong can di chuyen hay chen, phan tu da o dung vi tri\n";
        }

        // Hiển thị trạng thái mảng sau mỗi vòng lặp
        cout << "\nVong lap thu " << i << " : ";
        In();
    }
}

int main() {
    cout << "Mang du lieu dau vao: ";
    In();
    cout << "========================================\n";
    insertionSort();
    
    cout << "========================================\n";
    cout << "Mang sau khi da sap xep: ";
    In();
    return 0;
}
