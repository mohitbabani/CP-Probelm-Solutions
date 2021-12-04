#include <bits/stdc++.h>
int main() {
  int a[5][5];
  memset(a,0,sizeof(a));
  for(int i=0,j=4;i<5,j>=0;i++,j--){
    a[i][j] = 1;    
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      std::cout << a[i][j] << " ";
    }std::cout <<"\n";
  }
}