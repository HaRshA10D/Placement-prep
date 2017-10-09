#include <iostream>
#include <string.h>
using namespace std;
void swap(char *a,char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}
void permute(char *s,int l,int r){
  if(l == r){
    cout << s << endl;
  }else{
    for(int i=l;i<=r;i++){
      swap(s+l,s+i);
      permute(s,l+1,r);
      swap(s+l,s+i);
    }
  }
}
int main(){
  char s[100];
  cin >> s;
  int n = strlen(s);
  cout << "All permutations" << endl;
  permute(s,0,n-1);
}
