#include"bits/stdc++.h"
using namespace std;
int main(){
    double x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    d = sqrt(d);
    double R = max(r1,r2);
    double r = min(r1,r2);
    cout.precision(17);
    cout << fixed;
    if(d > R+r){
        cout << (d - R - r)/2;
        return 0;
    }
    if(R > d + r){
        cout << (R - d - r)/2;
        return 0;
    }
    cout << 0;
    return 0;
}