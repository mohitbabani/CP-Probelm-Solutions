#include<iostream>
using namespace std;
class complex
{
	private:
		int a,b;
	public:
		void setData(int x,int y)
		{a=x;b=y;}
		void showData()
		{cout<<a<<" + i"<<b<<endl;} 
		friend complex operator+(complex,complex);
		complex operator +=(complex z){
			
		}
};


		
int main()
{
	complex c1,c2;
	c1.setData(1,3);
	c2.setData(2,5);
    c1+=c2;
	c1.showData();
}
complex operator +(complex z1,complex z2)
		{
			complex temp;
			temp.a=z1.a + z2.a;
			temp.b=z1.b + z2.b;
			return (temp);
		}