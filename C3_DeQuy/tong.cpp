// S = 1 - (1/1+2) + (1/1+2+3)+...+(-1)^n+1 / 1+2+3+..+n
#include <iostream>
#include <cmath> 
using namespace std;
// Hàm đệ quy tính S(n)
float S(int n) {
    if (n == 1) {
        return 1.0; // Điều kiện dừng: S(1) = 1
    } else {
        return S(n - 1) + pow(-1, n + 1) / ( n * (n + 1) / 2 ); // Công thức đệ quy
    }
}
int main() {
    int n;
    cout << "Nhap n : "; cin >> n;
    S(n); 
    cout << "Tong : " << S(n);
}
