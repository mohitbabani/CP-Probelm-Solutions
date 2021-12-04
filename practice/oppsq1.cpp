#include<iostream>
using namespace std;
class Distance{
    int km,m;
    public:
        void input(){
            cin>>km>>m;
        }
        void output(){
            cout<<km<<" km "<<m<<" m\n";
        }
        Distance operator +=(Distance D){
            int temp=1000*(km+D.km) + (m+D.m);
            km = temp/1000;
            m = temp%1000;
            return *this;
        }
        bool operator > (Distance d){
            int d1 = 1000*km + m , d2 = 1000*d.km + d.m;
            if(d1>d2)
            return 1;
            else 
            return 0;        
        }
        bool operator < (Distance d){
            int d1 = 1000*km + m , d2 = 1000*d.km + d.m;
            if(d1<d2)
            return 1;
            else 
            return 0;        
        }
        bool operator == (Distance d){
            int d1 = 1000*km + m , d2 = 1000*d.km + d.m;
            if(d1==d2)
            return 1;
            else 
            return 0;        
        }
};
int main(){
    Distance d1,d2;
    d1.input();d2.input();
    cout<<(d1>d2)<<endl;
    cout<<(d1==d2)<<endl;
    cout<<(d1<d2)<<endl;
    d2 += d1;
    d2.output();
}