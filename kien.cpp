#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<fstream>
#include <filesystem> 
using namespace std;
/*char *VnName(char *s){
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
double taodathuc(int n, double *a, double x){
    double y = 0.0;
    for( int i = n; i >= 0; i-- ){
        y = y * x + a[i];
    }
    return y;
}
int main(){
    //cout<<"~5="<<~5<<endl
    const char * filename = "kien.csv";


    double A[] = { 3, -4 , 1};
    double a = -1, b = 4;
    double dx = 0.1;
    ofstream ofs;
    ofs.open(filename);
    ofs << "x,y\n";
    for(double x = a; x <= b; x += dx){
        ofs << x << "," << taodathuc(2, A, x)<<endl;
    }
    ofs.close();
    cout<<"Data saved to file " << filename<<endl;
 cout << "Full path: " << std::filesystem::absolute(filename) << endl;
 return 0;
}
