/* Duyệt đồ thị theo chiều rộng (BFS) để in ra dãy số đại diện cho ngày sinh theo thứ tự liên kết các đỉnh */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 8 // Cập nhật số đỉnh tối đa

struct Vertex {
    int label;     // Nhãn của đỉnh (giá trị của đỉnh).
    bool visited;  // Trạng thái đã duyệt hay chưa.
};

// Danh sách các đỉnh
Vertex* lstVertices[MAX]; // Mảng con trỏ lưu các đỉnh trong đồ thị.

// Ma trận kề
int adjMatrix[MAX][MAX];  // Ma trận kề biểu diễn các cạnh của đồ thị.

// Đếm số đỉnh
int vertexCount = 0; // Số lượng đỉnh hiện tại trong đồ thị.

// Thêm đỉnh
void addVertex(int label) {
    Vertex* vertex = new Vertex; // Tạo một đỉnh mới.
    vertex->label = label;       // Gán nhãn cho đỉnh.
    vertex->visited = false;     // Đặt trạng thái ban đầu là chưa duyệt.
    lstVertices[vertexCount++] = vertex; // Thêm đỉnh vào mảng và tăng số lượng đỉnh.
}

// Thêm cạnh vào ma trận kề
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1; // Đánh dấu có cạnh nối từ đỉnh `start` đến `end`.
    adjMatrix[end][start] = 1; // Vì đồ thị vô hướng, đánh dấu cạnh ngược lại.
}

// Hiển thị đỉnh
void displayVertex(int vertexIndex) {
    cout << lstVertices[vertexIndex]->label << " "; // In nhãn của đỉnh được chỉ định.
}

// Lấy đỉnh kề chưa được duyệt từ ma trận kề
int getAdjUnvisitedVertex(int vertexIndex) {
    for (int i = 0; i < vertexCount; i++) {              // Duyệt qua các đỉnh.
        if (adjMatrix[vertexIndex][i] == 1              // Kiểm tra nếu có cạnh.
            && !lstVertices[i]->visited) {              // Và đỉnh chưa được duyệt.
            return i;                                   // Trả về chỉ số của đỉnh.
        }
    }
    return -1; // Không tìm thấy đỉnh nào thỏa mãn.
}

// Tìm kiếm theo chiều rộng (BFS)
void breadthFirstSearch() {
    queue<int> bfsQueue;             // Tạo hàng đợi để lưu các đỉnh đang xử lý.

    lstVertices[0]->visited = true;  // Đánh dấu đỉnh đầu tiên là đã duyệt.
    displayVertex(0);                // Hiển thị nhãn đỉnh đầu tiên.
    bfsQueue.push(0);                // Đưa đỉnh đầu tiên vào hàng đợi.

    while (!bfsQueue.empty()) {      // Lặp lại khi hàng đợi không rỗng.
        int currentVertex = bfsQueue.front(); // Lấy đỉnh ở đầu hàng đợi.
        bfsQueue.pop();                       // Loại bỏ đỉnh đó khỏi hàng đợi.

        int unvisitedVertex;                  // Tìm đỉnh kề chưa duyệt.
        while ((unvisitedVertex = getAdjUnvisitedVertex(currentVertex)) != -1) {
            lstVertices[unvisitedVertex]->visited = true; // Đánh dấu đỉnh kề là đã duyệt.
            displayVertex(unvisitedVertex);               // Hiển thị nhãn đỉnh kề.
            bfsQueue.push(unvisitedVertex);               // Thêm đỉnh kề vào hàng đợi.
        }
    }

    // Reset trạng thái visited của tất cả các đỉnh sau khi duyệt xong.
    for (int i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    // Khởi tạo ma trận kề với giá trị 0 (không có cạnh nào ban đầu).
    memset(adjMatrix, 0, sizeof(adjMatrix));
    /*
	  3
	 /|\
	1 0 5
	|   |
	2   0
	|    \
	4     0
	*/
    // Thêm các đỉnh (ngày sinh).
    addVertex(3); // 0: Đỉnh đầu tiên.
    addVertex(1); // 1: Đỉnh thứ hai.
    addVertex(0); // 2: Đỉnh thứ ba.
    addVertex(5); // 3: Đỉnh thứ tư.
    addVertex(2); // 4: Đỉnh thứ năm.
    addVertex(0); // 5: Đỉnh thứ sáu.
    addVertex(0); // 6: Đỉnh thứ bảy.
    addVertex(4); // 7: Đỉnh thứ tám.

    // Thêm các cạnh.
    addEdge(0, 1); // Kết nối 3 - 1.
    addEdge(0, 2); // Kết nối 3 - 0.
    addEdge(0, 3); // Kết nối 3 - 5.
    addEdge(1, 4); // Kết nối 1 - 2.
    addEdge(2, 5); // Kết nối 0 - 0.
    addEdge(3, 6); // Kết nối 5 - 0.
    addEdge(4, 7); // Kết nối 2 - 4.

    // In kết quả tìm kiếm theo chiều rộng.
    cout << "\nTim kiem theo chieu rong: ";
    breadthFirstSearch();

    return 0; // Kết thúc chương trình.
}
