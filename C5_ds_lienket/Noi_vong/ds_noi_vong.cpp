#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

// Hàm cấp phát động một node mới
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Kiểm tra danh sách rỗng
bool empty(node a){
    return a == NULL;
}

// Hàm đếm số lượng phần tử trong danh sách
int Size(node a){
    if (empty(a)) return 0;
    int cnt = 1;
    node tmp = a;
    while (tmp->next != a){
        ++cnt;
        tmp = tmp->next;
    }
    return cnt;
}

// Thêm 1 phần tử vào đầu danh sách liên kết vòng
void insertFirst(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
        tmp->next = a;
    } else {
        node p = a;
        while (p->next != a) {
            p = p->next;
        }
        tmp->next = a;
        p->next = tmp;
        a = tmp;
    }
}

// Thêm 1 phần tử vào cuối danh sách liên kết vòng
void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
        tmp->next = a;
    } else {
        node p = a;
        while (p->next != a) {
            p = p->next;
        }
        p->next = tmp;
        tmp->next = a;
    }
}

// Thêm 1 phần tử vào giữa danh sách liên kết vòng
void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if (pos <= 0 || pos > n + 1){
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    if (pos == 1){
        insertFirst(a, x);
        return;
    }
    if (pos == n + 1){
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

// Xoá phần tử ở đầu
void deleteFirst(node &a){
    if (a == NULL) return;
    if (a->next == a) {
        delete a;
        a = NULL;
    } else {
        node p = a;
        while (p->next != a) {
            p = p->next;
        }
        node tmp = a;
        a = a->next;
        p->next = a;
        delete tmp;
    }
}

// Xoá phần tử ở cuối
void deleteLast(node &a){
    if (a == NULL) return;
    if (a->next == a) {
        delete a;
        a = NULL;
    } else {
        node truoc = NULL, sau = a;
        while (sau->next != a){
            truoc = sau;
            sau = sau->next;
        }
        truoc->next = a;
        delete sau;
    }
}

// Xoá phần tử ở giữa
void deleteMiddle(node &a, int pos){
    int n = Size(a);
    if (pos <= 0 || pos > n) return;
    if (pos == 1) {
        deleteFirst(a);
        return;
    }
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    truoc->next = sau->next;
    delete sau;
}

// In danh sách liên kết vòng
void in(node a){
    cout << "\t\tDanh sach hien tai:\n";
    if (a == NULL) {
        cout << "\t\tDanh sach trong\n";
        return;
    }
    
    node p = a;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != a);
    cout << "\n--------------------------------\n";
}

int main(){
    node head = NULL;
    int lc; 
    do {
        system("cls"); 
        cout << "-----------------MENU---------------\n";
        cout << "1. Chen 1 phan tu vao dau danh sach\n";
        cout << "2. Chen 1 phan tu vao cuoi danh sach\n";
        cout << "3. Chen 1 phan tu vao giua danh sach\n";
        cout << "4. Xoa 1 phan tu o dau\n";
        cout << "5. Xoa 1 phan tu o cuoi\n";
        cout << "6. Xoa 1 phan tu o giua\n";
        cout << "0. Thoat!\n";
        cout << "-------------------------------------\n";
        
        in(head); // In danh sách hiện tại sau mỗi lần trở về menu

        cout << "Nhap lua chon: "; cin >> lc;
        switch (lc) {
            case 1: {
                int x; cout << "Nhap gia tri can chen: "; cin >> x;
                insertFirst(head, x);
            } break;
            case 2: {
                int x; cout << "Nhap gia tri can chen: "; cin >> x;
                insertLast(head, x);
            } break;
            case 3: {
                int x; cout << "Nhap gia tri can chen: "; cin >> x;
                int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
                insertMiddle(head, x, pos);
            } break;
            case 4: {
                deleteFirst(head);
            } break;
            case 5: {
                deleteLast(head);
            } break;
            case 6: {
                int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
                deleteMiddle(head, pos);
            } break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                break;
        }
        	 // Sau mỗi thao tác, danh sách sẽ được tự động in ra
        cout << "---- Cap nhat danh sach ----\n";
        in(head);
        
        system("pause");
    } while (lc != 0);
     return 0;
}
