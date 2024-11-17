#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children; // Danh sách các node con
    TreeNode(int val) {
        data = val;
    }
};

class GeneralTree {
public:
    // Hàm để thêm một node con vào một node cha
    void addChild(TreeNode* parent, int childData) {
        TreeNode* child = new TreeNode(childData);
        parent->children.push_back(child);
    }

    // Hàm xây dựng cây tổng quát từ nhập liệu
    TreeNode* buildTree() {
        int rootData;
        cout << "Nhap gia tri cua node goc: ";
        cin >> rootData;
        TreeNode* root = new TreeNode(rootData);

        // Gọi hàm đệ quy để xây dựng cây
        buildTreeHelper(root);

        return root;
    }

    // Hàm đệ quy để nhập các node con
    void buildTreeHelper(TreeNode* parent) {
        int numChildren;
        cout << "Nhap so luong node con cua " << parent->data << ": ";
        cin >> numChildren;

        for (int i = 0; i < numChildren; ++i) {
            int childData;
            cout << "Nhap gia tri cua node con " << (i + 1) << " cua " << parent->data << ": ";
            cin >> childData;
            TreeNode* child = new TreeNode(childData);
            parent->children.push_back(child);

            // Gọi đệ quy để thêm các node con của node hiện tại
            buildTreeHelper(child);
        }
    }
    // Duyệt trước (NLR) cho cây tổng quát
    void preOrder(TreeNode* root) {
        if (root == NULL) return;
        cout << root->data << " "; // Duyệt node gốc trước
        for (auto child : root->children) {
            preOrder(child); // Sau đó duyệt các node con
        }
    }

    // Duyệt sau (LRN) cho cây tổng quát
    void postOrder(TreeNode* root) {
        if (root == NULL) return;
        for (auto child : root->children) {
            postOrder(child); // Duyệt các node con trước
        }
        cout << root->data << " "; // Sau đó duyệt node gốc
    }
    
       // Duyệt giữa LNR 
	void inOrder(TreeNode* root) {
    if (root == NULL) return;
    int n = root->children.size();
    // Duyệt một nửa số node con đầu tiên
    for (int i = 0; i < n / 2; ++i) {
        inOrder(root->children[i]);
    }
    cout << root->data << " ";
    // Duyệt nửa số node con còn lại
    for (int i = n / 2; i < n; ++i) {
        inOrder(root->children[i]);
  		  }
	}
};

int main() {
    GeneralTree tree;

    // Xây dựng cây từ nhập liệu
    TreeNode* root = tree.buildTree();

    // In kết quả duyệt trước và sau
    cout << "\n-Duyet truoc(NLR): ";
    tree.preOrder(root);

    cout << "\n-Duyet sau(LRN): ";
    tree.postOrder(root);
	
	cout << "\n-Duyet giua(LNR): ";
    tree.inOrder(root);
    return 0;
}

