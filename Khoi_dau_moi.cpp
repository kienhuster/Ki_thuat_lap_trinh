#include<iostream>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
/*
typedef struct coordinate_struct {
    int x; // hoành độ
    int y; // tung độ
} coord;
int main() {
    coord points[] = {
        { 10, 10 },
        { 45, 45 },
        { 90, 10 }
    };

    // Truy cập các trường của phần tử mảng
    for (int i = 0; i < 3; i++) {
        cout << "x = " << points[i].x << ", y = " << points[i].y << endl;
    }

    // Sử dụng toán tử gán
    coord org;
    org.x = 0;
    org.y = 0;
    points[0] = org;

    // Truy cập các trường của con trỏ
    for (int i = 0; i < 3; i++) {
        coord* p = points + i;
        cout << "x = " << p->x << ", y = " << p->y << endl;
    }

    return 0;
}
int main(){
    ifstream file;
    
    file.open("13.3.cautruc.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file 13.3.cautruc.txt" << endl;
        return 1;
    }
    int n ;
    file >> n;
    cout<<"Gia tri cua n: "<<n<<endl;
    file.close();
    system("Pause");
}*/
/*
typedef struct wagon { // đại diện cho toa tàu
    int places;// tạo chỗ ngồi
    wagon* next; // con trỏ đến toa kế tiếp
} wagon;
typedef struct train { // đại diện cho cả đoàn tàu
    wagon* head; // con trỏ tói toa đầu tàu
    wagon* tail; // con trỏ tơi toa cuối cùng
} train;
void init_train(train* obj) { // khởi tạo toa tàu ban đầu
    obj->head = obj->tail = 0; // con trỏ = nullptr
}
void dispose_train(train* obj) { // Giải phóng bộ nhớ xóa toàn bộ toa tàu
    while (obj->head) {// Lặp đến khi con tro = nullptr hay là không còn toa nào
        wagon* p = obj->head; // p trỏ tạm đến toa đầu tiên
        obj->head = p->next; // chuyển con trỏ head sang toa kế tiếp
        delete[] p;//xóa toa để tránh rò gỉ
    }
}
    void append_train(train* obj, int places) {// Thêm toa vào đoàn tàu
        // Tạo một con trỏ wagon
        wagon* p = new wagon(); 
        p->places = places;// gán số lượng chỗ ngồi
        p->next = 0;// toa chưa nối với toa nào
        
        // Gắn wagon vào cuối tàu
        if (obj->tail != 0) { // nếu tàu đã có toa
            obj->tail->next = p;// nối toa cuối cùng với toa mới
        }
        else {// nếu chưa có toa nào 
            obj->head = p;// toa mới là toa đầu tiên
        }
        obj->tail = p;
}
int main() {
    // Tạo đoàn tàu
    train train;
    init_train(&train);
    for (int i = 0; i < 10; i++) {
        append_train(&train, 40);
    }
    
    // Soát vé
    

    // Giải phóng bộ nhớ
    dispose_train(&train);
    return 0;
}
int main(){
    int x;
    cout<<"Nhap gia tri cua x: ";
    cin>>x;
     const double eps = 1e-8;
    if(x < 0){
        cout<<"Khong the tinh can bac 2 cua so am."<<endl;
        return 0;
    }
    double a = 1.00, p ;
     while(fabs(p-a)>1e-8){
        p = a;
        a = (a + x/a)*0.5;
     }
    cout<<"Can bac 2 cua "<<x<<" la: "<<a<<endl;

}*/
double Ham_mu(double x, int n){
    int m = n < 0 ? - n : n;
    double a = 1.0;
    for(int i = 1; i <= m; i++){
        a *= x;
    }
    return (n < 0)? 1/a : a;
}
double Pow(double x, int n){
     if (n == 0) return 1;
     if (n < 0 ) return 1 / Pow(x , -n);
     if(n & 1) return x * Pow(x , n-1);
     return Pow( x * x, n>>1 );
}
int main(){
    /*Bai 1*/
   double x;
   int n = -3;
    cout<<"Nhap gia tri :";
    cin>> x;
    cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<< Ham_mu(x, n) <<endl;
    cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<< Pow(x, n) <<endl;

    return 0;
}
