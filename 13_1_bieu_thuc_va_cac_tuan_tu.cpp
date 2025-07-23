#include<iostream>
#include<cmath>
#include<string>
using namespace std;
/* Bai 1:In giá trị của N!​ */
int main(){
    int n = 10, x = 1;
    for(int i = 1 ; i <= n; i++){
        x *= i;
    }
    cout<<"Giai thua cua "<<n<<" la: "<<x<<endl;
    return 0;
}
/*Bai 2: n giá trị của x^n*/
int main(){
    int n = -3;
    int x;
    int m = (n < 0)? -n : n;
    while(true){
        cout<<"Nhap gia tri cua x:";
        cin>>x;
     double a = 1.0;
    for(int i = 1; i <= m ; i++){
        a *= x;
    }
    cout<<"Gia cua "<<x<<"^"<<n<<" la: "<<(n < 0? 1/a : a)<<endl;}
    return 0;
}
/* Bai 3: Tinh tong cua 1+1/2+...+(1/2)^n */
int main(){
    int n = 10;
    float x = 0.5, s = 0, a = 1;
    for(int i = 0; i <= n ; i++){
         s = x * s + a;
    }
    cout<< "Tong cua 1+1/2+...+(1/2)^" << n <<" la: "<< s <<endl;
    return 0;
}
/*Bai 4: Xác định tính nguyên tố của số nguyên x​*/
int main(){
    int x;
    cout<<"Nhap gia tri cua x: ";
    cin>>x;
    if(x<2){
        cout<<"Khong phai la so nguyen to."<<endl;
    } else {
        int m = 0; // bien dem so uoc
       for(int i = 2; i < x; i++){
        if(x % i == 0){
            m++;
            break;
        }
       }
       /*if(m == 0){
            cout<<x<<" la so nguyen to."<<endl;
        } else {
            cout<<x<<" khong phai la so nguyen to."<<endl;
        }*/
       cout << x << ((m) ? " khong":"" )<< " la so nguyen to. ";
    }
    return 0;
}
/*Bai 5: Tính tổ hợp ​C(k, n)*/
//Cach 1
int main(){
   //int n=5,k=2,a=1,b=1;
   int n, k, a = 1, b = 1;
    cout<<"Nhap gia tri cua n: ";
    cin>>n;
    cout<<"Nhap gia tri cua k: ";
    cin>>k;
    if(k > n || k < 0 || n < 0){
        cout<<"Gia tri cua k phai nho hon hoac bang n va lon hon hoac bang 0."<<endl;
        return 0;
    }
    for(int i = n; i > n-k ; i--){
        a *= i;
    }
    for(int i = 1; i <= k ; i++){
        b *= i;
    }
    double c = a/b;
    cout<<"C("<< k <<","<< n <<") = "<< c <<endl;
    return 0;
}
//Cach 2
int main(){
    int n, k, a = 1, b = 1;
    cout<<"Nhap gia tri cua n: ";
    cin>>n;
    cout<<"Nhap gia tri cua k: ";
    cin>>k;
    if(k > n || k < 0 || n < 0){
        cout<<"Gia tri cua k phai nho hon hoac bang n va lon hon hoac bang 0."<<endl;
        return 0;
    }
    int g = 1 , gk = 1, gnk = 1;
    for( int i = 1; i <= n ; i++){
        g *= i;
        if( k == i ) gk = g;
        if( n - k == i ) gnk = g;
    }
    cout<<"C("<<k<<","<<n<<") = "<< g/gk/gnk <<endl;
    return 0;
}
   /*Bai 6: In giá trị nhị phân của số nguyên 1 byte ra màn hình​*/
int main(){
int x = 9;
cout<<" Gia tri cua x: "<<x<<endl;
int a = 1 << 7;
cout<<"Giá trị nhị phân của "<< x <<" la : ";
for(int i = 0 ; i < 8; i++){
    cout<< (x & a ? '1' : '0');
     a >>= 1;
}
return 0;
}
/*Bai 7: Nhập dãy số nguyên cho đến khi giá trị nhập vào bằng 0, in ra số nhỏ nhất và lớn nhất (trừ số 0)​*/
int main(){
    int x, min, max, dem = 0;
    cout<<"Nhap cac so nguyen (nhap 0 de ket thuc): ";
   while(true){
        cin>>x;
        if(x == 0 ) break;
        if(dem == 0){
            min = max = x ;
        }
        else{
            if(x < min) min = x;
            if(x > max) max = x;
        } 
        dem++;      
    }
    if(dem == 0){
        cout<<"Khong co so nao duoc nhap."<<endl;
    }
    else{
    cout<<"So nho nhat la: "<< min <<endl;
    cout<<"So lon nha la: "<< max <<endl;
    }
    return 0;
}
/*Bai 8: Nhập dãy số nguyên cho đến khi giá trị nhập vào bằng 0, in ra số số chẵn, số số lẻ và số các số chia hết cho 8 (trừ số 0)​*/
int main(){
    int x;
    cout<<"Nhap cac so nguyen (nhap 0 de ket thuc):";
    int chan = 0, le = 0 , chc8 = 0; 
    while(true){
        cin>>x;
        if(x == 0) break;
        if(x % 2 == 0){
            chan++;
        if(x % 8 == 0) chc8++;
        }
        else{
            le++;
        }
    }
    if(chan == 0 && le == 0 && chc8 == 0){
        cout<<"Khong co so nao duoc nhap."<<endl;
        return 0;
    }
    else{
    cout<<"So so chan: "<< chan <<endl;
    cout<<"So so le: "<< le <<endl;
    cout<<"So so chia het cho 8: "<< chc8 <<endl;
    }
    return 0;

}
/*Bai 9: In N số đầu tiên của dãy Fibonacci​*/
int main(){
    int n;
    cout<<"Nhap so luong so Fibonacci : ";
    cin>>n;
    int a = 0, b = 1 , c;
    if(n <= 0){
        cout<<"So luong so Fibonacci khong hop le."<<endl;
    }
    else if(n == 1){
        cout<<a<<endl;
    }
    else if(n == 2){
        cout<<a<<" "<<b<<endl;
    }
    else{
        cout<<a<<" "<<b<<" ";
     for(int i = 0 ; i < n-2; i++){
        c = a + b;
        cout<<c<<" ";
        a = b;  
        b = c;
     }
    }   
    return 0;
}    
/*Bai 10: Xác định một số nguyên nhập từ bàn phím có nằm trong dãy Fibonacci hay không​*/
//Cach 1
int main(){
    int x, a = 0, b = 1, c = 0, dem = 0;
    cout<<"Nhap gia tri : ";
    cin>> x;
    while(x >= c){
        if(x == a || x == b || x == c){ 
            dem++; 
            break;
        }
        c = a + b;
        a = b;  
        b = c;
     }
    cout<< x <<(dem ? "" : " khong")<< " thuoc day fibonanci"<<endl;
    return 0;
}
//Cach 2
int main(){
    int x, a = 0 , b = 1, c;
    bool found = false;
    cout<<"Nhap gia tri : ";
    cin>> x;
    while(x >= c){
          if(x == a || x == b || x == c){ 
            found = true; 
            break;
        }
        c = a + b;
        a = b;  
        b = c;
     }
     cout<< x <<(found ? "" : " khong")<< " thuoc day fibonanci"<<endl;
     return 0;
}

/*Bai 11:Tính căn bậc 2 của số nguyên bất kỳ bằng Babylonian Method với sai số 1E-8​*/
int main(){
    int x;
    cout<< "Nhap gia tri cua x: ";
    cin>> x;
     const double eps = 1e-8;
    if(x < 0){
        cout<< "Khong the tinh can bac 2 cua so am." <<endl;
        return 0;
    }
    double a = 1.00, p ;
     while(( p - a ) > eps || ( p - a ) < eps ){
        p = a;
        a = (a + x/a) * 0.5;
     }
    cout<<"Can bac 2 cua "<< x <<" la: "<< a <<endl;
    return 0;
}
/*Bai 12: Nhập vào 4 số nguyên có 1 chữ số. In ra căn bậc 2 của số nguyên tạo thành từ 4 chữ số đó.​*/
int main(){
       int x = 0, a;
       cout<<"Nhap vao 4 so nguyen: ";
    for (int i = 0; i < 4; i++) {
        cin >> a;
        x = 10 * x + a;
    }
    cout << "Gia tri so nguyen tao thanh tu 4 chu so tren la: "<< x <<endl;
    const double eps = 1e-8;
    double b = 1.0, p = 0.0;

    while (fabs( p - b ) > eps) {
        p = b;
        b = ( b + x / b ) * 0.5;  
    }
    cout << "Can bac 2 cua " << x << " la: " << b << endl;
    return 0;
}

/*Bai 13: In ra màn hình các số từ 1 đến M x N dưới dạng ma trận​*/
int main() {
    int m, n;
    cout << "Nhap so dong: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    if (m <= 0 || n <= 0) {
        cout << "So dong va so cot phai lon hon 0." << endl;
        return 0;
    }

    int value = 1;  
    cout << "Ma tran la:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << value++ << " ";  
        }
        cout << endl; 
    }
    return 0;
}

/*Bai 14 :Tìm dạng của tam giác nếu biết bình phương 3 cạnh của tam giác đó​*/
int main(){
    int a = 12, b = 6, c = 6;
    int can = (b == c) + (a == c) * 2 + (a == b) * 4;
    int vuong = (a == b + c)+(b == a + c) * 2 + (c == a + b) * 4;
    int flag = vuong | can;
    cout<< "Tam giac ";
    switch (flag){
        case 0: cout<< "thuong " ; break;
        case 7: cout<< "deu "; break;
        default:
        if(vuong) cout<< "vuong ";
        if(can) cout<< "can ";    
    }
    cout<< "tai " <<(char)(flag / 2 + 65);
    return 0;
}
/*15: In các chữ cái hoa, chữ cái thường và các chữ số kèm theo mã ASCII của chúng​*/
int main(){
    for(int i = 65; i <= 90; i++){
        cout<<"Ky tu "<<char(i)<<" co ma ASCII la: "<<i<<endl;
    }
    for(int i = 97; i <= 122; i++){
        cout<<"Ky tu "<<char(i)<<" co ma ASCII la: "<<i<<endl;
    }
    for(int i = 48; i <= 57; i++){
        cout<<"Ky tu "<<char(i)<<" co ma ASCII la: "<<i<<endl;
    }
    return 0;
}