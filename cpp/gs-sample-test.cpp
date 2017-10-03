#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<long long int> factorsOf(long long int x){
  vector<long long int> facs;
  while(x%2==0){
    facs.push_back(2);
    x = x/2;
  }
  for(long long int i=3;i<=sqrt(x);i=i+2){
    while(x%i==0){
      facs.push_back(i);
      x = x/i;
    }
  }
  if(x>2) facs.push_back(x);
  return facs;
}
long long int commonFacs(vector<long long int> x,vector<long long int> y){
  long long int s1=0,s2=0,l=0,last,commons=1;
  vector<long long int> t;
  while(s1<x.size() && s2<y.size()){
    if(x[s1]<=y[s2]){
      t.push_back(x[s1]);
      cout << "adding: " << x[s1] << endl;
      s1++;
    }else{
      t.push_back(y[s2]);
      cout << "adding: " << y[s2] << endl;
      s2++;
    }
  }
  while(s1<x.size()){
    t.push_back(x[s1]);
    cout << "adding: " << x[s1] << endl;
    s1++;
  }
  while(s2<y.size()){
    t.push_back(y[s2]);
    cout << "adding: " << y[s2] << endl;
    s2++;
  }
  last = t[0];
  for(int i=0;i<t.size();i++){
    if(t[i]!=last){
      commons *= (l+1);
      l=1;
    }else l++;
    last = t[i];
  }
  commons *= (l+1);
  return commons;
}
int main(){
  long long int a[] = {34,54,24,67,89,345,234,23,567,445,578};
  long long int n = sizeof(a)/sizeof(long long int);
  vector<vector<long long int> > main;
  for(long long int i=0;i<n;i++){
    vector<long long int> temp = factorsOf(a[i]);
    main.push_back(temp);
  }
  long long int max = 0,now;
  for(long long int i=0;i<n-1;i++){
    for(long long int j=i+1;j<n;j++){
      now = commonFacs(main[i],main[j]);
      cout << "Numbers: " << a[i] << " " << a[j] << endl;
      cout << "product: " << a[i]*a[j] << " factors: " << now << endl;
      if(now>max) max = now;
    }
  }
  cout << max << endl;
  return 0;
}
