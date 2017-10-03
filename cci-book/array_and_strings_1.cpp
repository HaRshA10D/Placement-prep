#include<iostream>
#include<algorithm>
using namespace std;
bool checkUnique(std::string x){
  for(int i=0;i<x.length()-1;i++){
    if(x.at(i)==x.at(i+1)) return false;
  }
  return true;
}
int main(){
  cout << "Input string:" << endl;
  std::string x;
  cin >> x;
  sort(x.begin(),x.end());
  cout << "Unique test: " << checkUnique(x) << endl;
  std::string a("harsha");
  a.at(0)='v';
  cout << a;
  return 0;
}
