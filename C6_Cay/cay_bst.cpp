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

Node* maxOfLeft(Node* root) {
    Node* p = root->left;
    while (p && p->right != NULL) 
        p = p->right;
    return p;
}

class Solution {
public:
    // Thêm 1 node
    Node* insert(Node* root, int data) {
        Node* p = new Node(data);
        if (root == NULL) root = p;
        else if (root->data > data)
            root->left = insert(root->left, data);
        else if (root->data < data)
            root->right = insert(root->right, data);
        else
            delete p; // Tránh thêm node có giá trị trùng lặp
        return root;
    }

    // Xóa 1 node
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return NULL;
        
        if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else { 
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* maxNode = maxOfLeft(root);
                root->data = maxNode->data;
                root->left = deleteNode(root->left, maxNode->data);
            }
        }
        return root;
    }

    // Hàm tìm node có giá trị lớn nhất
    Node* findMax(Node* root) {
        if (root == NULL) return NULL;
        while (root->right != NULL)
            root = root->right;
        return root;
    }

    // Hàm tìm node có giá trị nhỏ nhất
    Node* findMin(Node* root) {
        if (root == NULL) return NULL;
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    // Duyệt trước NLR
    void preOrder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // Duyệt giữa LNR
    void inOrder(Node* root) {
        if (root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    // Duyệt sau LRN
    void postOrder(Node* root) {
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

    // Hiển thị node lớn nhất và nhỏ nhất ban đầu
    Node* maxNode = myTree.findMax(root);
    Node* minNode = myTree.findMin(root);
    if (maxNode != NULL) cout << "\nNode co gia tri lon nhat: " << maxNode->data;
    if (minNode != NULL) cout << "\nNode co gia tri nho nhat: " << minNode->data;

    //---------------------------------------------------
    // Thêm node mới
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

    // Hiển thị node lớn nhất và nhỏ nhất sau khi thêm node
    maxNode = myTree.findMax(root);
    minNode = myTree.findMin(root);
    if (maxNode != NULL) cout << "\nNode co gia tri lon nhat sau khi them: " << maxNode->data;
    if (minNode != NULL) cout << "\nNode co gia tri nho nhat sau khi them: " << minNode->data;

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

    // Hiển thị node lớn nhất và nhỏ nhất sau khi xóa node
    maxNode = myTree.findMax(root);
    minNode = myTree.findMin(root);
    if (maxNode != NULL) cout << "\nNode co gia tri lon nhat sau khi xoa: " << maxNode->data;
    if (minNode != NULL) cout << "\nNode co gia tri nho nhat sau khi xoa: " << minNode->data;

    return 0;
}