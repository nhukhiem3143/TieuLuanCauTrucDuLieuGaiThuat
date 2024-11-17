#include <iostream>
#include <cstdlib>
#include <stdbool.h>

#define MAX 8 // Số đỉnh tối đa trong đồ thị.

using namespace std;

// Cấu trúc đỉnh (vertex) với nhãn và trạng thái đã duyệt.
struct Vertex {
   int label;    // Nhãn của đỉnh.
   bool visited; // Trạng thái đã duyệt hay chưa.
};

// Ngăn xếp và các thao tác liên quan.
int stack[MAX];  // Ngăn xếp để hỗ trợ DFS.
int top = -1;    // Biến chỉ số ngăn xếp hiện tại.

// Danh sách các đỉnh và ma trận kề.
struct Vertex* lstVertices[MAX]; // Lưu trữ các đỉnh.
int adjMatrix[MAX][MAX];         // Ma trận kề.
int vertexCount = 0;             // Số đỉnh trong đồ thị.

// Hàm đẩy phần tử vào ngăn xếp.
void push(int item) { 
   stack[++top] = item; 
} 

// Hàm lấy phần tử trên cùng của ngăn xếp ra.
int pop() { 
   return stack[top--]; 
} 

// Hàm lấy giá trị phần tử trên cùng mà không xóa.
int peek() {
   return stack[top];
}

// Kiểm tra ngăn xếp có rỗng không.
bool isStackEmpty() {
   return top == -1;
}

// Thêm một đỉnh mới vào đồ thị.
void addVertex(int label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;          // Gán nhãn cho đỉnh.
   vertex->visited = false;        // Đặt trạng thái chưa được duyệt.
   lstVertices[vertexCount++] = vertex; // Lưu đỉnh vào danh sách.
}

// Thêm một cạnh giữa hai đỉnh.
void addEdge(int start, int end) {
   adjMatrix[start][end] = 1; // Đánh dấu cạnh từ đỉnh `start` đến `end`.
   adjMatrix[end][start] = 1; // Đánh dấu cạnh ngược lại vì đồ thị là vô hướng.
}

// Hiển thị nhãn của đỉnh theo chỉ số.
void displayVertex(int vertexIndex) {
   cout << lstVertices[vertexIndex]->label << " "; // In nhãn của đỉnh.
}

// Lấy đỉnh kề chưa được duyệt.
int getAdjUnvisitedVertex(int vertexIndex) {
   for(int i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i; // Trả về chỉ số của đỉnh kề chưa duyệt.
      }
   }
   return -1; // Không còn đỉnh nào kề chưa duyệt.
}

// Hàm tìm kiếm theo chiều sâu (DFS).
void depthFirstSearch() {
   lstVertices[0]->visited = true;  // Đánh dấu đỉnh đầu tiên đã được duyệt.
   displayVertex(0);                // Hiển thị đỉnh đầu tiên.
   push(0);                         // Đẩy đỉnh đầu tiên vào ngăn xếp.

   while(!isStackEmpty()) {
      int unvisitedVertex = getAdjUnvisitedVertex(peek()); // Tìm đỉnh kề chưa duyệt.

      if(unvisitedVertex == -1) { // Nếu không có đỉnh kề chưa duyệt.
         pop();                   // Loại bỏ đỉnh khỏi ngăn xếp.
      } else {
         lstVertices[unvisitedVertex]->visited = true; // Đánh dấu đỉnh đó đã duyệt.
         displayVertex(unvisitedVertex);              // Hiển thị đỉnh.
         push(unvisitedVertex);                       // Đẩy đỉnh vào ngăn xếp.
      }
   }

   // Reset trạng thái đã duyệt cho tất cả các đỉnh.
   for(int i = 0; i < vertexCount; i++) {
      lstVertices[i]->visited = false;
   }
}

int main() {
   // Khởi tạo ma trận kề (tất cả các phần tử ban đầu bằng 0).
   for(int i = 0; i < MAX; i++) {
      for(int j = 0; j < MAX; j++) {
         adjMatrix[i][j] = 0;
      }
   }
    /*
		  3
		  |
		  1
		  |
		  0
		  |
		  5
		  |
		  2
		  |
		  0
		  |
		  0
		  |
		  4
	*/
   // Thêm các đỉnh vào đồ thị (mô phỏng ngày sinh).
   addVertex(3);  // Đỉnh 0.
   addVertex(1);  // Đỉnh 1.
   addVertex(0);  // Đỉnh 2.
   addVertex(5);  // Đỉnh 3.
   addVertex(2);  // Đỉnh 4.
   addVertex(0);  // Đỉnh 5.
   addVertex(0);  // Đỉnh 6.
   addVertex(4);  // Đỉnh 7.

   // Thêm các cạnh (mô phỏng các kết nối giữa các đỉnh).
   addEdge(0, 1);  // 3 - 1
   addEdge(1, 2);  // 1 - 0
   addEdge(2, 3);  // 0 - 5
   addEdge(3, 4);  // 5 - 2
   addEdge(4, 5);  // 2 - 0
   addEdge(5, 6);  // 0 - 0
   addEdge(6, 7);  // 0 - 4

   // Thực hiện tìm kiếm theo chiều sâu.
   cout << "Tim kiem theo chieu sau (DFS): ";
   depthFirstSearch();

   return 0;
}
