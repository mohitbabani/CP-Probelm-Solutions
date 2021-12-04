#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct matrix{
    ll arr[2][2];
};
matrix multiply(matrix a,matrix b){
    matrix res;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res.arr[i][j]=0;
            for(int k=0;k<2;k++){
                res.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            }
        }
    }
    return res;
}
matrix _power(matrix a,ll b){
    matrix res = {{{1,0},{0,1}}};
    while(b > 0){
        if(b & 1) res = multiply(res,a);
        a = multiply(a,a);
        b >>= 1;
    }
    return res;
}
void print(matrix m){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << m.arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    int a = round(4.2);
    
    cout  << a << " ";
    // int n;cin >> n;
    // matrix pn = _power({{{0,1},{1,1}}},n);
    // return _power({{{0,1},{1,1}}},n).arr[1][0];
}