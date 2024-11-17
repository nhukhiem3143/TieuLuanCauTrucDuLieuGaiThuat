#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Giá trị vô cực

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size(); // Số đỉnh của đồ thị

    // Áp dụng thuật toán Floyd-Warshall
    for (int k = 0; k < n; k++) { // Duyệt qua từng đỉnh làm đỉnh trung gian
        for (int i = 0; i < n; i++) { // Duyệt qua từng đỉnh nguồn
            for (int j = 0; j < n; j++) { // Duyệt qua từng đỉnh đích
                // Kiểm tra nếu có thể đi từ i đến j qua đỉnh k để có đường đi ngắn hơn
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // In kết quả
    cout << "Khoang cach ngan nhat giua cac dinh:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                cout << "Dinh " << i << " -> Dinh " << j << ": Khong co duong di\n";
            else
                cout << "\nDinh " << i << " -> Dinh " << j << ": " << graph[i][j] << "\n";
        }
    }
}

int main() {
    // Biểu diễn ngày sinh của bạn thành các đỉnh: 3, 1, 0, 5, 2, 0, 0, 4
    vector<vector<int>> graph = {
        {0, 2, INF, 6, INF, INF, INF, 8},
        {2, 0, 3, 8, 5, INF, INF, INF},
        {INF, 3, 0, INF, 7, INF, INF, INF},
        {6, 8, INF, 0, 9, INF, INF, INF},
        {INF, 5, 7, 9, 0, INF, INF, INF},
        {INF, INF, INF, INF, INF, 0, 2, 4},
        {INF, INF, INF, INF, INF, 2, 0, 1},
        {8, INF, INF, INF, INF, 4, 1, 0}
    };
	/*
	Đỉnh 0 --2-- Đỉnh 1 --3-- Đỉnh 2 --7-- Đỉnh 4
	 |          |         |         |         |
	 6          8         INF       9         5
	 |          |         |         |         |
	 Đỉnh 3 --INF-- Đỉnh 5 --2-- Đỉnh 6 --1-- Đỉnh 7
	     \                  |       /       /
	      8                4       2       4
*/
    floydWarshall(graph);

    return 0;
}
