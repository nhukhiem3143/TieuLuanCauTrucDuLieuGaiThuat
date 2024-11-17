#include <iostream>
#define MAX 8
using namespace std;

// Khai báo mảng
int mang[MAX] = {0, 0, 0, 1, 2, 3, 4, 5};

// Hàm tìm kiếm nhị phân
int tim(int duLieu) {
    int chiMucDuoi = 0; // chỉ mục ban đầu
    int chiMucTren = MAX - 1; // chỉ mục cuối
    int chiMucGiua = -1;
    int soLanSoSanh = 0;
    int viTri = -1;

    while (chiMucDuoi <= chiMucTren) {
        cout << "So sanh lan thu " << (soLanSoSanh + 1) << endl;
        cout << "Chi muc ban dau : " << chiMucDuoi << ", mang[" << chiMucDuoi << "] = " << mang[chiMucDuoi] << endl;
        cout << "Chi muc cuoi : " << chiMucTren << ", mang[" << chiMucTren << "] = " << mang[chiMucTren] << endl;
        soLanSoSanh++;

        // Ước lượng giá trị tại vị trí trung vi
        chiMucGiua = chiMucDuoi + (chiMucTren - chiMucDuoi) / 2;

        // Tìm thấy dữ liệu
        if (mang[chiMucGiua] == duLieu) {
            viTri = chiMucGiua;
            break;
        } else {
            // Nếu dữ liệu là lớn hơn
            if (mang[chiMucGiua] < duLieu) {
                // Tìm kiếm dữ liệu phần lớn hơn
                chiMucDuoi = chiMucGiua + 1;
            }
            // Nếu dữ liệu là nhỏ hơn
            else {
                // Tìm kiếm dữ liệu phần nhỏ hơn
                chiMucTren = chiMucGiua - 1;
            }
        }
    }
    cout << "So phep tinh so sanh thuc hien: " << soLanSoSanh << endl;
    return viTri;
}

// Hàm in mảng
void inMang() {
    cout << "[";
    for (int i = 0; i < MAX; i++) {
        cout << mang[i] << " ";
    }
    cout << "]\n";
}

int main() {
    int n;
    
    // In mảng ban đầu
    cout << "Mang du lieu nhap vao: ";
    inMang();
    cout << "===========================================\n";

    // Nhập giá trị cần tìm
    cout << "Nhap gia tri can tim: "; cin >> n;

    // Tìm vị trí của phần tử nhập vào
    int viTri = tim(n);
    
	 cout << "===========================================\n";
    // Nếu phần tử được tìm thấy
    if (viTri != -1)
        cout << "\nTim thay phan tu tai vi tri: " << (viTri + 1) << endl;
    else
        cout << "\nKhong tim thay phan tu." << endl;

    return 0;
}
