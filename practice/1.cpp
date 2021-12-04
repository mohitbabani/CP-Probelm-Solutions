#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define w(t) long long t ; cin>>t ; while(t--)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fi(itr,v) for(auto itr=v.begin();itr!=v.end();itr++)
#define data demo
using namespace std;
class data{
	const int x;
	public:
	demo():x(){
		cout<<"Default Constructor\n";
	}
	demo(int p): x(p){
		cout<<"Para const\n";
	}
	void putData(){
		cout<<"p = "<<x<<"\n";
	}
};
int main(){
	data d1;
	d1.putData();
	data d2(55);
	d2.putData();
}