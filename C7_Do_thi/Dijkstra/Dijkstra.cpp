#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Giá trị vô cực

void dijkstra(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF); // Khoảng cách từ đỉnh bắt đầu đến các đỉnh
    vector<bool> visited(n, false); // Trạng thái đã thăm của các đỉnh

    dist[start] = 0; // Khoảng cách từ đỉnh bắt đầu đến chính nó là 0

    for (int i = 0; i < n - 1; i++) {
        int minDist = INF, u = -1;

        // Tìm đỉnh chưa thăm có khoảng cách nhỏ nhất
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // Nếu không tìm được đỉnh nào, kết thúc

        visited[u] = true; // Đánh dấu đỉnh u đã được thăm

        // Cập nhật khoảng cách cho các đỉnh kề
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // In kết quả
    cout << "Khoang cach ngan nhat tu dinh " << start << " den cac dinh khac:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Dinh " << i << ": Khong co duong di\n";
        else
            cout << "Dinh " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    // Ma trận trọng số của đồ thị
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
	/*
	   (0)
       | \
      2|  6
       |    \
      (1)---8---(3)
       |       /  \
      3|     9|    7
       |   /    \
      (2)--------- (4)
            5
*/
    int start = 0; // Đỉnh bắt đầu
    dijkstra(graph, start);

    return 0;
}
