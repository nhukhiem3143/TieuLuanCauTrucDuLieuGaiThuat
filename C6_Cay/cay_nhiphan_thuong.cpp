#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // Thêm 1 node vào vị trí trống đầu tiên theo cấp độ
    Node* insert(Node* root, int data) {
        Node* newNode = new Node(data);
        if (root == NULL) return newNode;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            } else {
                q.push(temp->left);
            }
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            } else {
                q.push(temp->right);
            }
        }
        return root;
    }
    // Xóa 1 node
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) {
            if (root->data == key) return NULL;
            else return root;
        }
        Node* keyNode = NULL;
        Node* temp;
        Node* last;
        queue<Node*> q;
        q.push(root);
        // Tìm nút cần xóa và nút cuối cùng
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp->data == key) keyNode = temp;
            if (temp->left) {
                last = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                last = temp;
                q.push(temp->right);
            }
        }
        // Nếu tìm thấy nút cần xóa
        if (keyNode != NULL) {
            keyNode->data = temp->data; // Thay thế dữ liệu của nút cần xóa bằng dữ liệu của nút cuối cùng
            // Xóa nút cuối cùng
            if (last->right == temp) {
                last->right = NULL;
            } else {
                last->left = NULL;
            }
            delete temp;
        }
        return root;
    }
    // Duyệt trước NLR
    void preOrder(Node *root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    // Duyệt giữa LNR
    void inOrder(Node *root) {
        if (root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    // Duyệt sau LRN
    void postOrder(Node *root) {
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
};
int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;
    cout << "Nhap so luong node: "; cin >> t;
    cout << "Nhap cac node: ";
    while (t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }

    cout << "\n-Duyet truoc: ";
    myTree.preOrder(root);

    cout << "\n-Duyet giua : ";
    myTree.inOrder(root);

    cout << "\n-Duyet sau  : ";
    myTree.postOrder(root);

    //---------------------------------------------------
    // Thêm node
    int newData;
    cout << "\n\nNhap node muon them: "; cin >> newData;
    root = myTree.insert(root, newData);

    // In cây sau khi thêm node mới
    cout << "Sau khi them: ";
    cout << "\n-Duyet truoc: ";
    myTree.preOrder(root);

    cout << "\n-Duyet giua : ";
    myTree.inOrder(root);

    cout << "\n-Duyet sau  : ";
    myTree.postOrder(root);

    //---------------------------------------------------
    // Xóa node
    int key;
    cout << "\n\nNhap node muon xoa: "; cin >> key;

    root = myTree.deleteNode(root, key);

    // In cây sau khi xóa node
    cout << "Sau khi xoa: ";
    
    cout << "\n-Duyet truoc: ";
    myTree.preOrder(root);

    cout << "\n-Duyet giua : ";
    myTree.inOrder(root);

    cout << "\n-Duyet sau  : ";
    myTree.postOrder(root);
}