#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
/*Bai 1:Viết hàm tìm x^n*/
//Cach 1
double Ham_mu(double x, int n){
    int m = n < 0 ? - n : n;
    double a = 1.0;
    for(int i = 1; i <= m; i++){
        a *= x;
    }
    return (n < 0)? 1/a : a;
}
//Cach 2 
double Pow(double x, int n){
     if (n == 0) return 1;
     if (n < 0 ) return 1 / Pow(x , -n);
     if(n & 1) return x * Pow(x , n-1);
     return Pow( x * x, n>>1 );
}
/*Bai 2: Viết hàm tìm N!*/
int giaithua(int n){
    int a = 1;
    for(int i = 1; i <= n;i ++){
        a *= i;
    }
    return a;
}
/*Bai 3: Viết hàm tìm số Fibonacci tại t*/
int Fib( int t){
    int a[1000];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i < 1000, i++){
        a[i] = a[i-2] + a[i-1] ;
    }
    return a[t];
}
/*Bai 4: Viết hàm tìm số nghiệm và giá trị các nghiệm của phương trình bậc 2*/

int Squareroot(double a, double b, double c, double * x1, double * x2){
    double d = b * b - 4 * a * c;
    if(d < 0) return 0;
    a *= 2;
    if(d == 0 ){
        *x1 = *x2 = - b / a;
        return 1;
    } 
    d = sqrt(d);
    *x1 = (-b - d)/a;
    *x2 = (-b + d)/a;
    return 2;
}
/*Bai 5: Viết hàm tính oK và oF từ oC*/
//Cach 1
double chuyen_nhiet_oK( double c){
    return c + 273.15;
}
double chuyen_nhiet_oF( double c){
    return c * (9.0/5.0) +32;
}

//Cach 2
void chuyen_nhiet( double c, double &k, double &f ){
    f = c * (9.0/5.0) +32;
    k = c + 273.15;
}

// Cach 3
void chuyen_nhiet(double c, double *k, double *f){
    *k = c + 273.15;
    *f = c * (9.0/5.0) + 32;
}

/*Bai 6: Viết hàm in mảng số nguyên có n phần tử */
//Cach 1
void inMang(int *a, int n){
    cout << "{ ";
    for(int i = 0; i < n - 1; i++){
        cout<<*(a + i)<<", ";
    }
    cout<< *(a + n - 1) << " }";
}
//Cach 2
template< class T >
void printArray(T* a, int n) {//int* arr
    T* p = a;
    --n;
    cout << "{ ";
    while(p - a < n) {
        cout<< *p++ << ", " ;
    }
    cout<< *p << " }";
}
/*Bai 7: Viết hàm tính tổng của mảng các số nguyên có n phần tử*/
//Cach 1:
int tong (int *a, int n ){
     int s = 0;
     for(int i = 0; i < n; i++){
        s += a[i];
     }
     return s;
}
//cach 2:
int tong_day(int *a, int n){
    int* p = a;
    int s = 0;
    while( p - a < n){
        s += *p;
        p++ ;
    }
   return s;
}


/*Bai 8: Viết hàm tính trung bình cộng của mảng các số nguyên có n phần tử */
//Cach 1:
double trungbinh(int *a, int n ){  
     double s = 0.0;
     for(int i = 0; i < n; i++){
        s += a[i];
     }
    return s/n;
}
//Cach 2:
double trungbinh_cong(int *a, int n){
    int* p = a;
    double s = 0.0;
    while( p - a < n){
        s += *p;
        p++ ;
    }
   return s/n;
}
/*Bai 9: Viết hàm tìm giá trị của đa thức bậc n tại x (hệ số của đa thức là một mảng số thực)*/
//Cach 1
double taodathuc1( int n, double *a , double x){
   double y = 0.0;
    for( int i = 0; i < n ; i++ ){
        y = y * x + a[i];
    }
    return y;
}
//Cach 2
double taodathuc2( int n, double *a , double x){
   double y = 0.0;
   double* p = a;
    while( p - a < n ){
        y = y * x + *p;
        p++;
    }
    return y;
}
/*Bai 10: Viết hàm đổi xâu ký tự sang số*/
//Cach 1
double Todouble(const char*s){
    double a = 0, b = 0;
    for(int i = 0; char c = s[i]; i++){
        if(c == '.'){
            b = 1;
            continue;
        }
        if( c > '9' || c < '0') break;
        a = a * 10 + (c & 15);
        if(b) b = b * 10;
        /*a = (a << 1) + (a << 3) + (c & 15);
        if(b) b = (b << 1)+ (b << 3);*/
    }
    return b > 1?(double) a/b : a;
}
//Cach 2
double Todouble(const char*s){
    double a = 0, b = 0;
    while( char c = *s++ ){
        if(c == '.'){
            b = 1;
            continue;
        }
        if( c > '9' || c < '0') break;
        a = a * 10 + (c & 15);
        if(b) b = b * 10;
        /*a = (a << 1) + (a << 3) + (c & 15);
        if(b) b = (b << 1)+ (b << 3);*/
    }
    return b > 1?(double) a/b : a;
}
/* Bai 11: Viết hàm chuẩn hóa họ tên tiếng Việt*/

// cach 1
char* VnName( char* s){
    const char spc = 32;
    char last = spc; int k = 0;
    for(int i = 0; char c = s[i]; i++){
       /* if(last == spc && c == spc) continue;
        if(last == spc && c != spc) {
            if(c >= 'a' && c <= 'z') c -= spc ;
            s[k++]= last = c; continue;
        }
        if( last != spc && c == spc){
            s[k++] = last = c; continue;
        }
        if(last != spc && c != spc){
            if(c >= 'A' && c <= 'Z') c += spc;
            s[k++] = last = c; continue;
        }
    }*/
   if(last == spc ){
    if(c == spc) continue;
    if(c >= 'a' && c <= 'z' ) c -= spc ;
   }
   else{
    if(c >= 'A' && c <= 'Z') c += spc;
   }
   s[k++] = last = c;
}

    s[last == spc? k-1:k] = 0;
    return s;
}
//Cach 2
char* Vn_Name( char* s){
    const char spc = 32;
    char last = spc; int k = 0;
     char* p = s;
    while( char c = *p++ ){
    if(last == spc ){
     if(c == spc) continue;
     if(c >= 'a' && c <= 'z' ) c -= spc ;
   }
    else{
     if(c >= 'A' && c <= 'Z') c += spc;
   }
    s[k++] = last = c;
}

    s[last == spc? k-1 : k] = 0;
    return s;
}
/*Bai 13: Viết hàm cho dãy n số Fibonacci đầu tiên  */
//
int* fibonanci(int n) {
    int* v = new int[n];
    v[0] =0;
    v[1] = 1;
    for (int t = 2; t < n; t++) {
        v[t] = v[t - 1] + v[t - 2];
    }
    return v;
}
/*Bai 14: Viết hàm tạo mảng n phần tử từ mảng số nguyên*/
int* taoMang(int n) {
    int* a = new int[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
        return a;
    }
}
/*Bai 15: Viết hàm tạo xâu mới chuyển các chữ cái thường thành chữ cái viết hoa từ xâu đầu vào*/
char* Toupper(const char* s){
    int len = strlen(s);
    char * r = new char[len +1];
    *(r + len) = 0;
    for(int i = 0 ; char c = s[i]; i++){
        if( c >= 'a' && c <= 'z'){
            c -= 32;
            r[i] = c;
        } else {
            r[i] = c;
        }
    }
    return r;
}
/*Bai 16 :Viết hàm chuyển đổi số nguyên thành xâu ký tự nhị phân*/    
//Cach 1
char* soSangNhiPhan( int x ) {
    int a = x;
    int kitu = 0;
   while( a > 0 ){
    a /= 2;
    kitu++;
   }
    char* s = new char[kitu + 1];
    *(s + kitu) = 0;
   for (int i = kitu - 1; i >= 0; i--) {
        s[i] = (x % 2) + '0';//+48
        x >>= 1;
    }
    return s;
}
//Cach 2
char* sosangNhiPhan( int x ) {
    int n = sizeof(x) * 8 + 1;
    char* s = new char[n];
    int k = 0;
    do{
        s[k++] = (x % 2) + '0';
        x >>= 1;
    }while(x != 0);
    s[k]= 0; 
    k--;
    for (int i = 0 ; i < k ; i++){
        char c = s[i]; 
        s[i] = s[k];
        s[k] = c;
        k--;
    }
    return s;
}
/*Bai 17: Viết hàm tìm tần suất của các ký tự trong xâu*/
int* Freq( const char* s ){
    int* p = new int[256];
    for(int i = 0; i < 256; i++){
        p[i] = 0;
    }
    while( int index = *s++ ){
        p[index]++;
    }
    return p;
}
int main(){
/*Bai 1*/
   double x;
   int n = -3;
    cout<<"Nhap gia tri :";
    cin>> x;
    cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<< Ham_mu(x, n) <<endl;//Cach 1
    cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<< Pow(x, n) <<endl;//Cach 2
/*Bai 2*/
    int n;
    cout<<" Nhap gia tri cua n: ";
    cin>>n;
    if(n < 0){
        cout<<" Khong the tinh giai thua ."<<endl;
    }
    else if(n == 0){
        cout<<" 0! = 1 "<<endl;
    }
    else{
        cout<< n <<"! = "<< giaithua(n) <<endl;
    }
/*Bai 3*/
    int t;
    cout<<" Nhap gia tri cua t(nho hon 1000): ";
    cin>>t;
    if( t < 0){
        cout<<" Khong hop le."<<endl;
    }
    else {
        cout<<" So Fibonacci tai "<< t <<" la: "<< Fib(t) <<endl;
    }
/*Bai 4*/
double a, b, c, x1, x2;
    cout<<"Nhap he so cua phuong trinh: ";
    cin>>a>>b>>c;
    cout<<"Phuong trinh "<< a <<"x^2 + "<< b <<"x + "<<c;
    switch(Squareroot( a, b, c, &x1, &x2)){
        case 0 : cout<<" vo nghiem."; break;
        case 1 : cout<<" co x1 = x2 ="<< x1 << endl; break;
        default : cout<<" co x1 = "<< x1 <<" va "<<" x2 = "<< x2 <<endl;
    }
/*Bai 5*/
 double k, f, oc;
    cout<<"Nhap gia tri do oC: ";
    cin>>c;
    //1
     cout<<"Nhiet do oF: "<< chuyen_nhiet_oF(oc) << endl << "Nhiet do oK: "<< chuyen_nhiet_oK(oc) << endl;
    //2
    chuyen_nhiet(oc, k, f);
    cout<<"Nhiet do oF: "<< f << endl <<"Nhiet do oK: "<< k << endl;
    //3
    chuyen_nhiet(oc, &k, &f);
    cout<<"Nhiet do oF: "<< f << endl <<"Nhiet do oK: "<< k << endl;
/*Bai 6*/
int m[] = {1,2,4,4};
    //1
    inMang(m , 4);
    //2
    printArray(m , 4);
/*Bai 7*/
    //1
    cout<<"Tong cua mang: "<< tong(m,4) << endl;
    //2
    cout<<"Tong cua mang: "<< tong_day(m,4) << endl;
/*Bai 8 */
    //1
    cout<<"Trung binh cong cua mang: "<<trungbinh(m,4)<<endl;
    //2
    cout<<"Trung binh cong cua mang: "<<trungbinh(m,4)<<endl;
    trungbinh_cong(m,4);
/*Bai 9*/
double r[] = {1,2,3,4};
    double x1 = 2;
    int sl = 4;
    cout<<"Gia tri cua bieu thuc ";
    for(int i = 0; i < sl - 1; i++){
        cout<< r[i] <<"."<< "x^"<< --sl <<" + ";
    }
    cout<< r[n - 1] <<" la: "<< taodathuc1(sl,r,x1)<<" "<<taodathuc2(sl,r,x1)<< endl;
/*Bai 10*/
char so_so[] = "2345.5";
    cout<<"So :"<<Todouble(so_so);
/*Bai 11*/
 char name[100]=" NGguyen Trung   KIen  ";
 cout<<"Ten duoc chuan hoa:"<<endl;
    cout<< VnName(name) << endl;
    cout<< Vn_Name(name) << endl;
/*Bai 13*/
int nFib;
    cout << "Nhap so luong so Fibonacci: ";
    cin >> nFib;

    if (nFib <= 0) {
        cout << "So luong so Fibonacci khong hop le." << endl;
    } else {
        int* fib = fibonanci(nFib);
        cout << "Day Fibonacci: ";
        for (int i = 0; i < nFib; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;
        delete[] fib; // giải phóng bộ nhớ
  }
/*Bai 14*/
int* arr = taoMang(4);
    inMang(arr,4);
    delete[] arr;
/*Bai 15*/
char xau_chucai[] = "Kien";
    char* p = Toupper(xau_chucai);
    cout <<"Xau moi: "<< p << endl;
    delete[] p;
/*Bai 16*/
int so;
    cout << "Nhap gia tri can chuyen: ";
    cin >> so;
    //1
    char* ki_tu = soSangNhiPhan( so );
    cout << "Xau ki tu nhi phan cua "<< so << " la : " << ki_tu <<endl;
    //2
    char* ki_Tu = sosangNhiPhan( so );
    cout << "Xau ki tu nhi phan cua "<< so << " la : " << ki_Tu <<endl;
    delete[] ki_tu;
/*Bai 17*/
  char Xau_kitu[] ="HelloWorld";
    int* freq = Freq(Xau_kitu);
    for(int i = 0; i < 256; i++){
        if( p[i] > 0 ){
            cout<<"Ky tu "<< (char) i << " xuat hien "<< freq[i] <<endl;
        }
    }
    delete[] freq;
return 0;
}










