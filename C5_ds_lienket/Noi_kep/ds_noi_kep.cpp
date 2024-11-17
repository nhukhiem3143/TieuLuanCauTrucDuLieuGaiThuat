#include <iostream>
using namespace std;

// Định nghĩa node
struct Node {
    int data;
    Node* next;
    Node* prev; // thêm con trỏ prev để liên kết với node trước đó
};

// Khởi tạo danh sách
Node* head = NULL;

// Hàm tạo node mới
Node* taoNode(int n) {
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Thêm 1 node vào đầu danh sách
void insert_dau(int n) {
    Node* newNode = taoNode(n);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Thêm 1 node vào cuối danh sách
void insert_cuoi(int n) {
    Node* newNode = taoNode(n);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Thêm 1 node vào giữa danh sách sau node có giá trị m
void insert_giua(int m, int n) {
    Node* newNode = taoNode(n);
    if (head == NULL) {
        cout << "Danh sach trong, khong the chen giua.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != m) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Khong tim thay gia tri " << m << " trong danh sach.\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

// Xóa 1 node ở đầu danh sách
void delete_dau() {
    if (head == NULL) {
        cout << "Danh sach trong\n";
    } else {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }
}

// Xóa 1 node ở cuối danh sách
void delete_cuoi() {
    if (head == NULL) {
        cout << "Danh sach trong\n";
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
}

// Xóa node có giá trị n
void delete_value(int n) {
    if (head == NULL) {
        cout << "Danh sach trong\n";
        return;
    }

    if (head->data == n) {
        delete_dau();
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != n) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Gia tri " << n << " khong ton tai trong danh sach\n";
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    delete temp;
}

// In danh sách
void printList() {
	 cout << "\t\tDanh sach:\n";
    if (head == NULL) {
        cout << "\t\tDanh sach trong\n";
        return;
    }
    cout << "NULL <=> ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <=> ";
        }
        temp = temp->next;
    }
    cout << " <=> NULL\n";
}

// Hàm menu và các thao tác
int main() {
    int choice, value, posValue;
    do {
    	system("cls");
        cout << "\n------------ MENU ------------\n";
        cout << "1. Them node vao dau danh sach\n";
        cout << "2. Them node vao cuoi danh sach\n";
        cout << "3. Them node vao giua danh sach\n";
        cout << "4. Xoa node o dau danh sach\n";
        cout << "5. Xoa node o cuoi danh sach\n";
        cout << "6. Xoa node co gia tri x\n";
        cout << "8. Thoat\n";
   
		printList();  // Hiển thị danh sách rỗng khi chương trình bắt đầu
		    
		cout << "Nhap lua chon cua ban: "; cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them vao dau danh sach: ";
                cin >> value;
                insert_dau(value);
                break;

            case 2:
                cout << "Nhap gia tri can them vao cuoi danh sach: ";
                cin >> value;
                insert_cuoi(value);
                break;

            case 3:
                cout << "Nhap gia tri cua node phia truoc can chen: ";
                cin >> posValue;
                cout << "Nhap gia tri can them vao giua danh sach: ";
                cin >> value;
                insert_giua(posValue, value);
                break;

            case 4:
                delete_dau();
                cout << "Node o dau da bi xoa.\n";
                break;

            case 5:
                delete_cuoi();
                cout << "Node o cuoi da bi xoa.\n";
                break;

            case 6:
                cout << "Nhap gia tri node can xoa: ";
                cin >> value;
                delete_value(value);
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                break;

             default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
		 // Sau mỗi thao tác, danh sách sẽ được tự động in ra
        cout << "---- Cap nhat danh sach ----\n";
        printList();

        system("pause");
    
    } while (choice != 0);

    return 0;
}