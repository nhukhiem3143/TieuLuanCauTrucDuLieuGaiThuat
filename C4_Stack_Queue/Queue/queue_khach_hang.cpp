#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    string* QArray;    // Mảng để chứa các phần tử trong queue
    int QMax;          // Kích thước tối đa của queue
    int QFront;        // Vị trí phần tử đầu tiên trong queue
    int QRear;         // Vị trí phần tử cuối cùng trong queue
    int QNumItems;     // Số phần tử hiện có trong queue

public:
    Queue(int size) {
        QArray = new string[size];
        QMax = size;
        QFront = QRear = -1;  
        QNumItems = 0;        
    }

    ~Queue() {
        delete[] QArray;
    }

    bool IsEmpty() {
        return (QNumItems == 0);
    }

    bool IsFull() {
        return (QNumItems == QMax);
    }

    bool Enqueue(string newItem) {
        if (IsFull()) return false;
        if (QNumItems == 0) QFront = 0;
        QRear = (QRear + 1) % QMax;
        QArray[QRear] = newItem;
        QNumItems++;
        return true;
    }

    bool Dequeue(string &itemOut) {
        if (IsEmpty()) return false;
        itemOut = QArray[QFront];
        QFront = (QFront + 1) % QMax;
        QNumItems--;
        if (QNumItems == 0) QFront = QRear = -1;
        return true;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Hang trong.\n";
        } else {
            cout << "Nguoi trong hang: ";
            int count = QNumItems;
            int index = QFront;
            while (count > 0) {
                cout << QArray[index] << " ";
                index = (index + 1) % QMax;
                count--;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue bankQueue(5);  // Khởi tạo hàng đợi với kích thước 5
    string customer;
    int luachon=-1;  // Biến để lưu lựa chọn người dùng

    // Hiển thị menu một lần ở đầu
    cout << "\n------------Queue------------\n";
    cout << "1. Them khach hang vao hang doi\n";
    cout << "2. Lay khach hang ra khoi hang doi\n";
    cout << "3. Hien thi hang\n";
    cout << "0. Thoat\n";
    cout << "----------------------------\n";

    // Vòng lặp thực hiện theo lựa chọn của người dùng
    while (luachon != 0) {
        cout << "\nNhap lua chon: ";cin >> luachon;
        cin.ignore();  // Loại bỏ ký tự xuống dòng thừa sau khi nhập số

        switch (luachon) {
        case 1:
            cout << "Nhap ten cua khach hang: ";
            getline(cin, customer);
            if (bankQueue.Enqueue(customer)) {
                cout << "Them khach hang thanh cong.\n";
            } else {
                cout << "Hang da chat, khong the them khach hang.\n";
            }
            break;

        case 2:
            if (bankQueue.Dequeue(customer)) {
                cout << "Da phuc vu: " << customer << endl;
            } else {
                cout << "Hang trong, khong co khach hang de phuc vu.\n";
            }
            break;

        case 3:
            bankQueue.Display();
            break;

        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }
    }

    return 0;
}
