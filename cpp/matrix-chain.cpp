#include<iostream>
#include<limits.h>
using namespace std;
int matmuldy(int a[],int n){
  int m[n-1][n-1];
  for(int i=0;i<n-1;i++) m[i][i] = 0;
  for(int l=1;l<n-1;l++){
    for(int j=0;j<n-l-1;j++){
      int k = j+l,q;
      m[j][k] = INT_MAX;
      for(int z=j;z<k;z++){
        q = m[j][z]+m[z+1][k]+a[j]*a[z+1]*a[k+1];
        cout << a[j] << " " << a[z+1] << " " << a[k+1] << " " << endl;
        if(q<m[j][k]) m[j][k]=q;
      }
      cout << j << "," << k << " is: " << m[j][k] << endl;
    }
  }
  return m[0][n-2];
}
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  cout << matmuldy(a,n) << endl;
}
