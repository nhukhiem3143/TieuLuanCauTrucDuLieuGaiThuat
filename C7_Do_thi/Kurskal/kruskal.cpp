#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000 // Giá trị tượng trưng cho vô cực, biểu thị không có cạnh.

// Cấu trúc lưu thông tin một cạnh trong đồ thị.
struct Edge {
    int weight; // Trọng số của cạnh.
    int start, end; // Hai đỉnh nối với cạnh.
};

// Hàm tìm tập hợp chứa đỉnh `v` (sử dụng thuật toán Union-Find).
int findParent(int v, vector<int>& parent) {
    if (v == parent[v]) 
        return v; // Nếu `v` là gốc của chính nó, trả về `v`.
    return parent[v] = findParent(parent[v], parent); // Kết hợp nén đường để tối ưu.
}

// Hàm hợp hai tập hợp chứa hai đỉnh `u` và `v`.
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent); // Tìm gốc của `u`.
    int rootV = findParent(v, parent); // Tìm gốc của `v`.

    if (rootU != rootV) { // Nếu hai gốc khác nhau, hợp hai tập hợp.
        if (rank[rootU] > rank[rootV]) 
            parent[rootV] = rootU; // Gốc của `v` trỏ vào gốc của `u`.
        else if (rank[rootU] < rank[rootV]) 
            parent[rootU] = rootV; // Gốc của `u` trỏ vào gốc của `v`.
        else {
            parent[rootV] = rootU; // Chọn ngẫu nhiên, tăng rank của gốc `u`.
            rank[rootU]++;
        }
    }
}

// Hàm thực hiện thuật toán Kruskal để tìm cây khung nhỏ nhất (MST).
vector<Edge> kruskal(int n, vector<Edge>& edges) {
    vector<Edge> mst; // Lưu các cạnh của cây khung nhỏ nhất.
    vector<int> parent(n), rank(n, 0); // `parent` lưu gốc, `rank` lưu cấp bậc.

    // Khởi tạo mỗi đỉnh là một tập hợp riêng biệt.
    for (int i = 0; i < n; i++) 
        parent[i] = i;

    // Sắp xếp các cạnh theo trọng số tăng dần.
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Duyệt qua từng cạnh, chọn cạnh nếu hai đầu không thuộc cùng một tập hợp.
    for (Edge edge : edges) {
        if (findParent(edge.start, parent) != findParent(edge.end, parent)) {
            mst.push_back(edge); // Thêm cạnh vào cây khung nhỏ nhất.
            unionSets(edge.start, edge.end, parent, rank); // Hợp hai tập hợp.
        }
    }

    return mst; // Trả về danh sách các cạnh của cây khung nhỏ nhất.
}

int main() {
    // Ma trận trọng số của đồ thị (sử dụng ngày sinh: 3, 1, 0, 5, 2, 0, 0, 4).
    int graph[8][8] = {
        {0, 3, INF, INF, INF, INF, INF, INF}, // Đỉnh 0
        {3, 0, 1, INF, INF, INF, INF, INF},  // Đỉnh 1
        {INF, 1, 0, 0, 5, INF, INF, INF},   // Đỉnh 2
        {INF, INF, 0, 0, INF, 2, INF, INF}, // Đỉnh 3
        {INF, INF, 5, INF, 0, INF, 4, INF}, // Đỉnh 4
        {INF, INF, INF, 2, INF, 0, INF, 0}, // Đỉnh 5
        {INF, INF, INF, INF, 4, INF, 0, 0}, // Đỉnh 6
        {INF, INF, INF, INF, INF, 0, 0, 0}  // Đỉnh 7
    };
	/*
	    (0)
       /   \
      3     3
     /       \
    (1)---1---(2)
             /   \
            5     0
           /       \
         (4)       (3)
          |         |
          4         2
          |         |
         (6)-------(5)
             \     /
              0   0
               \ /
              (7)
            */

    int n = 8; // Số đỉnh trong đồ thị.
    vector<Edge> edges; // Danh sách cạnh.

    // Chuyển ma trận trọng số thành danh sách cạnh.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Chỉ duyệt một nửa ma trận trên.
            if (graph[i][j] != INF && graph[i][j] != 0) { // Nếu có cạnh giữa hai đỉnh.
                edges.push_back({graph[i][j], i, j}); // Thêm cạnh vào danh sách.
            }
        }
    }

    // Thực hiện thuật toán Kruskal.
    vector<Edge> mst = kruskal(n, edges);

    // Hiển thị các cạnh của cây khung nhỏ nhất.
    cout << "Cac canh cua cay khung nho nhat:\n";
    for (Edge edge : mst) {
        cout << "Canh: (" << edge.start << ", " << edge.end << ") - Trong so: " << edge.weight << "\n";
    }

    return 0;
}
