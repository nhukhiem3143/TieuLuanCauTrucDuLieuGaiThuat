#include <iostream>
#define MAX 8
using namespace std;

int intArray[MAX] = {3, 1, 0, 5, 2, 0, 0, 4};

// Hàm hiển thị các phần tử của mảng
void In(){
    cout << "[ ";
    for (int i = 0; i < MAX; i++) {
        cout << intArray[i] << " ";
    }
    cout << "]" << endl;
}

// Hàm để trao đổi giá trị
void swap(int num1, int num2){
    int temp = intArray[num1];
    intArray[num1] = intArray[num2];
    intArray[num2] = temp;
}

// Hàm chia mảng thành 2 phần, sử dụng phần tử chốt (pivot)
int partition(int left, int right, int pivot){
    int leftPointer = left - 1;
    int rightPointer = right;

    while (true) {
        while (intArray[++leftPointer] < pivot) {
            // không làm gì
        }

        while (rightPointer > 0 && intArray[--rightPointer] > pivot) {
            // không làm gì
        }

        if (leftPointer >= rightPointer) {
            break;
        } else {
            cout << "Phan tu duoc trao doi: " << intArray[leftPointer] << " , " << intArray[rightPointer] << endl;
            swap(leftPointer, rightPointer);
        }
    }

    cout << "Phan tu chot duoc trao doi: " << intArray[leftPointer] << " , " << intArray[right] << endl;
    swap(leftPointer, right);
    
    cout << "\nHien thi mang sau moi lan trao doi: ";
    In();
    return leftPointer;
}

// Hàm sắp xếp nhanh
void quickSort(int left, int right) {
    if (right - left <= 0) {
        return;
    } else {
        int pivot = intArray[right]; // Chọn phần tử cuối cùng làm pivot
        int partitionPoint = partition(left, right, pivot); // Phân chia mảng và tìm điểm phân tách
        quickSort(left, partitionPoint - 1); // Đệ quy gọi cho phần bên trái
        quickSort(partitionPoint + 1, right); // Đệ quy gọi cho phần bên phải
    }
}

int main(){
    cout << "Mang du lieu dau vao: ";
    In(); // In mảng ban đầu
    cout <<"====================================================\n";
    quickSort(0, MAX - 1); // Gọi hàm quickSort để sắp xếp mảng
    
    cout <<"====================================================\n";
    cout << "Mang sau khi da sap xep: ";
    In(); // In mảng sau khi đã sắp xếp
    return 0;
}
