#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
/*Lập chương trình thực hiện các bước sau:
Tính giá trị của một hàm y = f(x) bất kỳ trong khoảng [a, b] với dx = 0.01
Lưu giá trị của các tọa độ thành 2 cột x, y vào file result.txt*/
typedef struct ham{
    double x;
    double y;
} ham;
double f(double x){
    return x*x+1;
}
int main(){
    
    ofstream file;
    file.open("cautruc.txt");
    if(!file.is_open()){
        cout << "mo file";
    }
    file<<" moeee" ;
    file.close();
    system("pause");
    return 0;
}
/*Lập trình cho đoàn tàu với các yêu cầu sau:
Định nghĩa toa tàu gồm: loại toa, số chỗ, số hành khách
Định nghĩa đoàn tàu gồm: số hiệu, số toa và danh sách các toa
Viết hàm tạo một toa tàu
Viết hàm tạo một đoàn tàu
Viết hàm giải phóng bộ nhớ
Viết hàm gắn một toa vào cuối đoàn tàu
Viết hàm cho số chỗ còn trống trong toa tàu thứ k (k bắt đầu từ 1)
Kiểm tra chương trình với thao tác soát vé để tính số hành khách trên tàu*/
struct toatau {
    string type;      // Loại toa
    int slot;         // Số chỗ ngồi
    int human;        // Số hành khách
    toatau* next;     // Con trỏ đến toa kế tiếp
};

struct doantau {
    string sohieu;    // Số hiệu đoàn tàu
    int sotoa;        // Số toa
    toatau* head;     // Toa đầu
    toatau* tail;     // Toa cuối
};
// Khởi tạo đoàn tàu
void init_toa(doantau* tt) {
    tt->head = tt->tail = nullptr;
    tt->sotoa = 0;
}

// Tạo một toa tàu 
void tao_toa(toatau*& p, string type, int slot, int human) {
    p = new toatau();
    if (p == nullptr) return;
    p->type = type;
    p->slot = slot;
    p->human = human;
    p->next = nullptr;
}

// Tạo một đoàn tàu 
void tao_doantau(doantau*& tt, toatau* p, string sohieu) {
    tt = new doantau();
    tt->sohieu = sohieu;
    tt->sotoa = 1;
    tt->head = tt->tail = p;
}
// Giải phóng bộ nhớ đoàn tàu
void giaiphong(doantau* tt) {
    while (tt->head) {
        toatau* p = tt->head;
        tt->head = p->next;
        delete p;
    }
    tt->tail = nullptr;
    tt->sotoa = 0;
}

// Gắn thêm một toa vào cuối đoàn tàu
void gan_toa(doantau* tt, toatau* p) {
    if (tt->head == nullptr) {
        tt->head = tt->tail = p;
    } else {
        tt->tail->next = p;
        tt->tail = p;
    }
    tt->sotoa++;
}

// Tính số chỗ còn trống trong toa thứ k (k >= 1)
int cho_con_trong(doantau* tt, int k) {
    if (k <= 0 || k > tt->sotoa) return -1;
    toatau* p = tt->head;
    for (int i = 1; i < k && p != nullptr; i++) {
        p = p->next;
    }
    if (p == nullptr) return -1;
    return p->slot - p->human;
}

// Tính tổng số hành khách trên tàu
int tong_hanh_khach(doantau* tt) {
    int tong = 0;
    toatau* p = tt->head;
    while (p != nullptr) {
        tong += p->human;
        p = p->next;
    }
    return tong;
}
int main() {
    doantau* tau ;
    init_toa(tau);
    toatau* toa1, * toa2, * toa3;

    // Tạo các toa
    tao_toa(toa1, "ghế thuong", 50, 30);
    tao_toa(toa2, "giường nằm", 40, 38);
    tao_toa(toa3, "vip", 60, 45);

    // Tạo đoàn tàu và gắn toa
    tao_doantau(tau, toa1, "T123");
    gan_toa(tau, toa2);
    gan_toa(tau, toa3);

    // In số chỗ còn trống ở toa thứ 2
    int k = 2;
    int trong = cho_con_trong(tau, k);
    if (trong != -1)
        cout << "Toa " << k << " con trong: " << trong << " cho\n";
    else
        cout << "Toa " << k << " khong ton tai\n";

    // Soát vé: Tổng số hành khách
    cout << "Tong hanh khach tren tau: " << tong_hanh_khach(tau) << endl;

    // Giải phóng bộ nhớ
    giaiphong(tau);
    delete tau;
    return 0;
}
