#include<bits/stdc++.h>
using namespace std;

void thap_hanoi(int n, int a, int b, int c){
    if(n == 1){
        cout << a << " -> " << c <<endl;
        return;
    }
    thap_hanoi(n - 1, a, c, b); // Chuyển N - 1 đĩa từ cọc 1 sang cọc 2, cọc 3 là trung gian.
    thap_hanoi(1, a, b, c); // Chuyển 1 đĩa còn lại từ cọc 1 sang cọc 3.
    thap_hanoi(n - 1, b, a, c); // Chuyển N - 1 đĩa từ cọc 2 sang cọc 3, cọc 1 là trung gian.
}
int main(){
    int n;
	cout << "Nhap n: "; cin >> n;
    int a = 1, b = 2, c = 3;
    thap_hanoi(n, a, b, c); // Giải bài toán với n đĩa.
}
