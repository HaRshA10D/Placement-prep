#include <iostream>
using namespace std;
long getWays(long S[],long m,long n){
  long mat[n+1][m];
  for(long i=0;i<m;i++) mat[0][i] = 1;
  for(long i=1;i<=n;i++){
    for(long j=0;j<m;j++){
      long x,y;
      x = (i-S[j] >= 0)? mat[i-S[j]][j]: 0;
      y = (j >= 1)? mat[i][j-1]: 0;
      mat[i][j] = x + y;
    }
  }
  return mat[n][m-1];
}
int main(){
  long n = 5;
  long S[] = {1,2,3};
  long m = long(sizeof(S)/sizeof(S[0]));
  long ways = getWays(S,m,n);
  cout << ways << endl;
}
