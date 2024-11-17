//Viết thủ tục đệ quy liệt kê N số Fibonacci đầu tiên?
#include <iostream>
using namespace std;

int fibo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
	return fibo(n - 1) + fibo(n - 2);
}
//fibo= | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55
// n =  | 1 | 2 | 3 | 4 | 5 | 6 | 7  | 8  | 9  | 10 
void lietke(int n) {
    for (int i = 1; i <= n; i++) {
        cout << fibo(i) << " "; // In số Fibonacci thứ i
    }
}
int main() {
    int n;
    cout << "Nhap n: "; cin >>n;
	lietke(n);
}

