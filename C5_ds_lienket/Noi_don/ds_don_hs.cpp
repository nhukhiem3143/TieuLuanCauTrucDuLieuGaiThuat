#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    Student* next;
};

typedef Student* Node;

// Hàm tạo một node mới
Node createNode(int id, string name) {
    Node newNode = new Student;
    newNode->id = id;
    newNode->name = name;
    newNode->next = nullptr;
    return newNode;
}

// Thêm sinh viên vào đầu danh sách
void insertFirst(Node &head, int id, string name) {
    Node newNode = createNode(id, name);
    newNode->next = head;
    head = newNode;
}

// Thêm sinh viên vào cuối danh sách
void insertLast(Node &head, int id, string name) {
    Node newNode = createNode(id, name);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Thêm sinh viên vào giữa danh sách
void insertMiddle(Node &head, int id, string name, int position) {
    if (position <= 0) return;  // Vị trí không hợp lệ
    Node newNode = createNode(id, name);
    if (position == 1) {
        insertFirst(head, id, name);
        return;
    }
    Node temp = head;
    int index = 1;
    while (temp != nullptr && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (temp == nullptr) return;  // Nếu vị trí vượt quá phạm vi danh sách
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xóa sinh viên ở đầu danh sách
void deleteFirst(Node &head) {
    if (head != nullptr) {
        Node temp = head;
        head = head->next;
        delete temp;
    }
}

// Xóa sinh viên ở cuối danh sách
void deleteLast(Node &head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Xóa sinh viên ở vị trí giữa
void deleteMiddle(Node &head, int position) {
    if (head == nullptr || position <= 0) return;
    if (position == 1) {
        deleteFirst(head);
        return;
    }
    Node temp = head;
    int index = 1;
    while (temp != nullptr && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (temp == nullptr || temp->next == nullptr) return;  // Vị trí không hợp lệ
    Node nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Duyệt và in danh sách sinh viên
void printList(Node head) {
    cout << "\t\tDanh sach sinh vien:\n";
    if (head == nullptr) {
        cout << "\t\tDanh sach rong!\n";
        return;
    }
    while (head != nullptr) {
        cout << "ID: " << head->id << ", Ten: " << head->name << endl;
        head = head->next;
    }
    cout << endl;  // Dòng trống giữa các lần in danh sách
}

// Hàm chính
int main() {
    Node head = nullptr;
    int choice;
    do {
        system("cls");
        cout << "-----------------MENU-----------------\n";
        cout << "1. Them sinh vien vao dau danh sach\n";
        cout << "2. Them sinh vien vao cuoi danh sach\n";
        cout << "3. Them sinh vien vao giua danh sach\n";
        cout << "4. Xoa sinh vien o dau\n";
        cout << "5. Xoa sinh vien o cuoi\n";
        cout << "6. Xoa sinh vien o giua\n";
        cout << "0. Thoat\n";
        
        // In danh sách sinh viên mỗi lần menu xuất hiện
        printList(head);
        
        cout << "Nhap lua chon: "; cin >> choice;
        
        int id, position;
        string name;
        switch (choice) {
            case 1: {
               cout << "Nhap ID, Ten (123 khiem): ";
                cin >> id;
                cin.ignore();  // Bỏ qua ký tự xuống dòng
                getline(cin, name);
                insertFirst(head, id, name);
                break;
            }
            case 2: {
                cout << "Nhap ID, Ten (123 khiem): ";
                cin >> id;
                cin.ignore();  // Bỏ qua ký tự xuống dòng
                getline(cin, name);
                insertLast(head, id, name);
                break;
            }
            case 3: {
                cout << "Nhap vi tri chen, ID, Ten (2 123 khiem) : ";
                cin >> position >> id;
                cin.ignore();  // Bỏ qua ký tự xuống dòng
                getline(cin, name);
                insertMiddle(head, id, name, position);
                break;
            }
            case 4: {
                deleteFirst(head);
                break;
            }
            case 5: {
                deleteLast(head);
                break;
            }
            case 6: {
                cout << "Nhap vi tri can xoa: ";
                cin >> position;
                deleteMiddle(head, position);
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
        // Sau mỗi thao tác, danh sách sẽ được tự động in ra
        cout << "---- Cap nhat danh sach ----\n";
        printList(head);

        system("pause");
    } while (choice != 0);

    return 0;
}
