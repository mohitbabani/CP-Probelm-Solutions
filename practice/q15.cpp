#include<iostream>
using namespace std;
#define MAX 10
class Account{
    int accNo;
    string fn,ln;
    double bal;
    public:
    void input(){
        cout<<"Account no"<<endl;
        cin>>accNo;
        cout<<"Enter the name"<<endl;
        cin>>fn>>ln;
        cout<<"Initial Balance"<<endl;
        cin>>bal;
    }
    void output(){
        cout<<"Account no: "<<accNo<<endl;
        cout<<"Name: "<<fn<<" "<<ln<<endl;
        cout<<"Account Balance: "<<bal<<endl;
    }
    void deposit(int amount){
        bal += amount;
    }
    void withdrawal(int amount){
        bal -= amount;
    }
    void p100(Account customer[MAX]){
        for(int i=0;i<MAX;i++)
        if(customer[i].bal<100)
        customer[i].output();
    }
};
int main(){
    Account c[5];
    for(int i=0;i<5;i++){
    c[i].input();
    }
    
    return 0;
}
