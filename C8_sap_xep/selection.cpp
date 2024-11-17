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

void selectionSort() {
    int indexMin;

    for (int i = 0; i < MAX - 1; i++) {
        // Thiết lập phần tử hiện tại là min
        indexMin = i;

        // Kiểm tra phần tử hiện tại có phải là nhỏ nhất không
        for (int j = i + 1; j < MAX; j++) {
            if (intArray[j] < intArray[indexMin]) {
                indexMin = j;
            }
        }

        // Thực hiện trao đổi nếu tìm thấy phần tử nhỏ hơn
        if (indexMin != i) {
            cout << "	Trao doi phan tu: [" << intArray[i] << " , " << intArray[indexMin] << "]\n";
            int temp = intArray[indexMin];
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }

        cout << "\nVong lap thu " << (i + 1) << " : ";
        In();
    }
}

int main() {
    cout << "Mang du lieu dau vao: ";
    In();
    cout << "===========================================\n";
    selectionSort();
    
    cout << "===========================================\n";
    cout << "Mang sau khi da sap xep: ";
    In();
    return 0;
}
