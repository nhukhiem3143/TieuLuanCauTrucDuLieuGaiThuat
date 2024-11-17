#include <iostream>
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

// Hàm duy trì cấu trúc heap
void heapify(int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    // Kiểm tra xem con trái có lớn hơn không
    if (left < n && intArray[left] > intArray[largest]) {
        largest = left;
    }

    // Kiểm tra xem con phải có lớn hơn không
    if (right < n && intArray[right] > intArray[largest]) {
        largest = right;
    }

    // Nếu largest không phải là i, đổi chỗ và tiếp tục heapify
    if (largest != i) {
        cout << "	Trao doi phan tu: [" << intArray[i] << " , " << intArray[largest] << "]\n";
        int temp = intArray[i];
        intArray[i] = intArray[largest];
        intArray[largest] = temp;

        // Đảm bảo cấu trúc heap được duy trì
        heapify(n, largest);
    }
}

// Hàm xây dựng heap từ mảng ban đầu
void buildHeap(int n) {
    // Bắt đầu từ nút không phải lá, đảm bảo heapify cho toàn bộ cây
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
}

// Thuật toán Heap Sort
void heapSort() {
    int n = MAX;

    // Xây dựng heap
    buildHeap(n);

    // Tiến hành sắp xếp
    for (int i = n - 1; i > 0; i--) {
        // Đổi chỗ phần tử gốc với phần tử cuối
        cout << "	Trao doi phan tu: [" << intArray[0] << " , " << intArray[i] << "]\n";
        int temp = intArray[0];
        intArray[0] = intArray[i];
        intArray[i] = temp;

        // Duy trì cấu trúc heap
        heapify(i, 0);

        cout << "\nVong lap thu " << (n - i) << " : ";
        In();
    }
}

int main() {
    cout << "Mang du lieu dau vao: ";
    In();
    cout << "===========================================\n";
    heapSort();
    
    cout << "===========================================\n";
    cout << "Mang sau khi da sap xep: ";
    In();
    return 0;
}
