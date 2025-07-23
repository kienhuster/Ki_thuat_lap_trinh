#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
/*Bai 1:Viết hàm tìm x^n*/
/*Cach 1*/
double Ham_mu(double x, int n){
    int m = n < 0 ? - n : n;
    double a = 1.0;
    for(int i = 1; i <= m; i++){
        a *= x;
    }
    return (n < 0)? 1/a : a;
}
int main(){
   double x;
   int n = -3;
    cout<<"Nhap gia tri :";
    cin>> x;
    cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<< Ham_mu(x, n) <<endl;
    return 0;
}
//Cach 2 
double Pow(double x, int n){
     if (n == 0) return 1;
     if (n < 0 ) return 1 / Pow(x , -n);
     if(n & 1) return x * Pow(x , n-1);
     return Pow( x * x, n>>1 );
}
int main(){
    double x; 
    int n ;
    cout<<"Nhap gia tri : ";
    cin>>x;
    cout<<"Nhap n: ";
    cin>>n;
     cout<<"Gia tri cua "<< x <<"^"<< n <<" la: "<<Pow(x, n)<<endl;
}
/*Bai 2: Viết hàm tìm N!*/
int giaithua(int n){
    int a = 1;
    for(int i = 1; i <= n;i ++){
        a *= i;
    }
    return a;
}
int main(){
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
    return 0;
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
int main(){
    int t;
    cout<<" Nhap gia tri cua t: ";
    cin>>t;
    if( t < 0){
        cout<<" Khong hop le."<<endl;
    }
    else {
        cout<<" So Fibonacci tai "<< t <<" la: "<< Fib(t) <<endl;
    }
    return 0;
}
/*Bai 4: Viết hàm tìm số nghiệm và giá trị các nghiệm của phương trình bậc 2*/
/*Cach 1*/
void nghiemBac2(double a, double b, double c){
    if(a == 0){
        if(b == 0){
            if(c == 0){
                cout<<"Phuong trinh vo so nghiem."<<endl;
            } else {
                cout<<"Phuong trinh vo nghiem."<<endl;
            }
        } else {
            cout<<"Phuong trinh co 1 nghiem: "<<-c/b<<endl;
        }
    } else {
        double delta = b*b - 4*a*c;
        if(delta < 0){
            cout<<"Phuong trinh vo nghiem."<<endl;
        } else if(delta == 0){
            cout<<"Phuong trinh co nghiem kep: "<<-b/(2*a)<<endl;
        } else {
            cout<<"Phuong trinh co 2 nghiem phan biet: "
                <<(-b + sqrt(delta))/(2*a)<<" va "
                <<(-b - sqrt(delta))/(2*a)<<endl;
        }
    }
}

/*Cach 2:*/
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
int main(){
    double a, b, c, x1, x2;
    cout<<"Nhap he so cua phuong trinh: ";
    cin>>a>>b>>c;
    cout<<"Phuong trinh "<<a<<"x^2 + "<<b<<"x + "<<c;
    switch(Squareroot( a, b, c, &x1, &x2)){
        case 0 : cout<<" vo nghiem."; break;
        case 1 : cout<<" co x1 = x2 ="<< x1<<endl; break;
        default : cout<<" co x1 = "<<x1<<" va "<<" x2 = "<<x2<<endl;
    }
    return 0;
}
int main(){
    double a, b, c;
    cout<<"Nhap he so a, b, c: ";
    cin>>a>>b>>c;
    nghiemBac2(a, b, c);
    return 0;
}
/*Bai 5: Viết hàm tính oK và oF từ oC*/
//Cach 1
double chuyennhietoK( double c){
    return c * (9.0/5.0) +32;
}
double chuyennhietoF( double c){
    return c + 273.15;
}

//Cach 2
void chuyennhiet( double &k, double &f, double c){
    k = c * (9.0/5.0) +32;
    f = c + 273.15;
}

// Cach 3
void templow(double oC, double *oK, double *oF){
    *oK = oC + 273;
    *oF = oC * 1.8 + 32;
}
int main(){
    double k, f, c;
    cout<<"Nhap gia tri do oC: ";
    cin>>c;
    //1
    chuyennhiet(k,f,c);
    cout<<"Nhiet do oF: "<<f<<endl<<"Nhiet do oK: "<<k<<endl;
    //2
    templow(c, &k, &f);
    cout<<"Nhiet do oF: "<<f<<endl<<"Nhiet do oK: "<<k<<endl;
    return 0;
}

/*Bai 6: Viết hàm in mảng số nguyên có n phần tử */
//Cach 1:
void mang(int a[], int n){
    cout<<"Nhap cac phan tu cua mang: ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
}
void inMang(int a[], int n){
    cout<<"Cac phan tu cua mang la: ";
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
//Cach 2:
void nhapMang(int *a, int n){
    cout<<"Nhap cac phan tu cua mang: ";
    for(int i = 0; i < n; i++){
        cin>>*(a+i);

    }
}
void inMang(int *a, int n){
    cout<<"Cac phan tu cua mang la: ";
    for(int i = 0; i < n; i++){
        cout<<*(a+i)<<" ";
    }
}
//Cach 3
template< class T >
void printArray(T* a, int n) {//int* arr
    T* p = a;
    --n;
    cout << "{";
    while(p - a < n) {
        cout<<*p++<< "," ;
    }
    cout<<*p << "}";
}
int main(){
    int a[] = {1,2,4,4};
    printArray(a, 4);
    return 0;
}

int main(){
    int n;
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    /*Cach 1*/
    int a[1000];
    mang(a,n);
    inMang(a,n);
    /*Cach 2*/
    int *a = new int[n]; // Cấp phát động
    nhapMang(a, n);
    inMang(a, n);
    delete[] a;
    return 0;
}
/*Bai 7: Viết hàm tính tổng của mảng các số nguyên có n phần tử*/
//Cach 1:
void tong (int a[], int n ){
    cout<<"Nhap cac phan tu cua mang: ";
     int s = 0;
     for(int i=0; i < n; i++){
        s += a[i];
     }
     cout<<"Tong cua day "<<n<<" so nguyen la: "<<s<<endl;
}
int main(){
int n ;
int a[1000];
cout<<"Nhap so phan tu cua mang: ";
cin>>n;
tong(a,n);
return 0;
}
//cach 2:
void tong(int *a, int n){
    cout<<"Nhap cac phan tu cua mang: ";
    int s = 0;
    for(int i = 0; i < n; i++){
        s += *(a+i);
    }
    cout<<"Tong cua day "<<n<<" so nguyen la: "<<s<<endl;
}
int main(){
    int n;
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    tong(a,n);
    return 0;
}
/*Bai 8: Viết hàm tính trung bình cộng của mảng các số nguyên có n phần tử */
//Cach 1:
void trungbinh(int a[], int n ){  
     double s = 0.0;
     cout<<"Nhap cac phan tu cua mang: ";
     for(int i=0; i < n; i++){
        s += a[i];
     }
    cout<<"Trung cong cua mang "<<n<<" so nguyen la: "<<s/n<<endl;
}
int main(){
int n ;
int a[1000];
cout<<"Nhap so phan tu cua mang: ";
cin>>n;
trungbinh(a,n);
return 0;
}
//Cach 2:
void trungbinh(int *a,int n){
	cout<<"Nhap cac phan tu cua mang: ";
    double s = 0.0;
	for(int i = 0; i < n; i++){
		s += *(a+i);
	}
	cout<<"Trung binh cong cua mang "<<n<<" so nguyen la: "<<s/n;
}
int main(){
    int n;
    cout<<"Nhap so phan tu cua mang: ";
    cin>>n;
    int *a = new int[n];
    trungbinh(a,n);
    delete[] a;
    return 0;
}
/*Bai 9: Viết hàm tìm giá trị của đa thức bậc n tại x (hệ số của đa thức là một mảng số thực)*/
//Cach 1:
void nhapdathuc(double a[],int n){
    cout<<"Nhap cac he so cua da thuc:";
    for(int i = 0; i <=n ;i++){
        cin>>a[i];
    }
}
void taodathuc(double a[], int n, double x){
    nhapdathuc(a,n);
    double s = a[0];
    double b = 1.0;
    for(int i = 1; i <= n;i++){
        b *= x;
        s += a[i] * b;
    }
    cout<<"Gia tri cua da thuc tai "<<x<<" la: "<<s<<endl;
}
//Cach 2
double taodathuc(int n, double *a, double x){
    double y = 0.0;
    for( int i = n; i >= 0; i-- ){
        y = y * x + a[i];
    }
    return y;
}
//Cach 3
double taodathuc(int n, double *a, double x){
    double y = 0.0;
    for( int i = n; i >= 0; i-- ){
        y = y * x + *(a+i);
    }
    return y;
}
int main(){
    int n;
    double x;
    cout<<"Nhap bac cua da thuc: ";
    cin>>n;
    cout<<"Nhap gia tri cua an: ";
    cin>>x;
    double a[1000];
    taodathuc(a, n, x);
    return 0;
}
//Cach 2: 
void nhapdathuc(double *a, int n){
    cout<<"Nhap cac he so cua da thuc: ";
    for(int i = 0; i <= n; i++){
        cin>>*(a+i);
    }
}
void taodathuc(double *a, int n, double x){
    nhapdathuc(a, n);
    double s = *a;
    double b = 1.0;
    for(int i = 1; i <= n; i++){
        b *= x;
        s += *(a+i) * b;
    }
    cout<<"Gia tri cua da thuc tai "<<x<<" la: "<<s<<endl;
}
int main(){
    int n;
    double x;
    cout<<"Nhap bac cua da thuc: ";
    cin>>n;
    cout<<"Nhap gia tri cua x: ";
    cin>>x;
    double *a = new double[n+1];
    taodathuc(a, n, x);
    delete[] a;
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
int main(){
    char s[] = "2345.5";
    cout<<"So :"<<Todouble(s);
    return 0;
}
int main(){
    char *s = new char[100];
    cout<<"Nhap xau so: ";
    cin.getline(s, 100);
    int so = chuyenxauSangSo(s);
    if(so != -1){
        cout<<"Gia tri so nguyen: "<<so<<endl;
    }
    delete[] s;
    return 0;
}
//Cach 4

/* Bai 11: Viết hàm chuẩn hóa họ tên tiếng Việt*/
void toupper( char *s) {
    for (int i = 0; char c = s[i]; i++) {
        if (c >= 'a' && c <= 'z') {
            s[i] = c - 32; // Chuyển chữ thường thành chữ hoa
        }
    }
}
void tolower(char *s) {
    for (int i = 0; char c = s[i]; i++) {
        if (c >= 'A' && c <= 'Z') {
           s[i] = c + 32; // Chuyển chữ hoa thành chữ thường
        }
    }
}
void chuanhoatu( char *s){
    s[0] = toupper(s[0]); // Chữ đầu tiên viết hoa
for(int i = 1; char c = s[i]; i++){
        s[i] = tolower(s[i]); 
}
}
void chuanHoaTen(char* s) {
    string res = "", tu = "";
    int i = 0, n = strlen(s);

    for (; i < n; ) {
        // Bỏ dấu cách thừa
        for (; i < n && s[i] == ' '; i++);
        tu = "";
        for (; i < n && s[i] != ' '; i++) {
            tu += s[i];
        }
        if (!tu.empty()) {
            chuanhoatu(&tu[0]);       // chuẩn hóa từ
            if (!res.empty()) res += " ";
            res += tu;
        }
    }
    
}

int main() {
    char ten[];
    cout << "Nhap ho ten: ";
    getline(cin, ten);
    ten = chuanHoaTen(ten);
    cout << "Ho ten da chuan hoa: " << ten << endl;
    return 0;
}

// cach 2
char *VnName(char *s){
    const char spc = 32;
    char last = spc; int k = 0;
    for(int i = 0; char c = s[i];i++){
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
//Cach 3
char* VnName(char *s){
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

    s[last == spc? k-1:k] = 0;
    return s;
}
int main(){
    char name[100]=" NGguyen Trung   KIen  ";
    cout<<VnName(name)<<endl;
    return 0;
}
/*Bai 13: Viết hàm cho dãy n số Fibonacci đầu tiên  */
//
int* fibonanci(int n) {
    int* v = new int[n];
    v[0] = v[1] = 1;
    for (int t = 2; t < n; t++) {
        v[t] = v[t - 1] + v[t - 2];
    }
    return v;
}

int main() {
    int n;
    cout << "Nhap so luong so Fibonacci: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong so Fibonacci khong hop le." << endl;
    } else {
        int* fib = fibonanci(n);
        cout << "Day Fibonacci: ";
        for (int i = 0; i < n; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;
        delete[] fib; // giải phóng bộ nhớ
    }

    return 0;
}

/*Bai 14: Viết hàm tạo mảng n phần tử từ mảng số nguyên*/
void taoMang(int *a, int n) {
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
    }
}
void inMang(int *a, int n) {
    cout << "Cac phan tu cua mang la: ";
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    if (n <= 0) {
        cout << "So phan tu phai lon hon 0." << endl;
        return 0;
    }
    int *a = new int[n]; // Cấp phát động
    taoMang(a, n);
    inMang(a, n);
    delete[] a; // Giải phóng bộ nhớ
    return 0;
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
int main(){
    char s[] = "Kien";
    char* p = Toupper(s);
    cout <<"Xau moi: "<< p << endl;
    delete[] p;
    return 0;
}
/*Bai 16 :Viết hàm chuyển đổi số nguyên thành xâu ký tự nhị phân*/    
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
int main(){
    int x;
    cout << "Nhap gia tri can chuyen: ";
    cin >> x;
    char* s = soSangNhiPhan( x );
    cout << "Xau ki tu nhi phan cua "<< x << " la : " << s <<endl;
    delete[] s;
    return 0;
}
/*Bai 17: Viết hàm tìm tần suất của các ký tự trong xâu*/
int* Freq( const char* s){
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
    char s[] ="Hello";
    int* p = Freq(s);
    for(int i = 0; i < 256; i++){
        if( p[i] > 0 ){
            cout<<"Ky tu "<< (char) i << " xuat hien "<< p[i] <<endl;
        }
    }
    delete[] p;
    return 0;
}
int main() {
    int x;
    cout << "Nhap so nguyen: ";
    cin >> x;  
    char* s = soSangNhiPhan( x );
    cout << "Dang nhi phan: " << s << endl;
    delete[] s;
    return 0;
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

    return 0;
}







