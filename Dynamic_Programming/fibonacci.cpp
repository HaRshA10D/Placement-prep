#include <iostream>
using namespace std;
int fib(int n){
  int store[n+1];
  store[0] = 0;
  store[1] = 1;
  for(int i=2;i<=n;i++){
    store[i] = store[i-1] + store[i-2];
  }
  return store[n];
}
int main(){
  int n;
  cout << "Enter number to find fabonacci for: ";
  cin >> n;
  cout << "Result: " << fib(n) << endl;
}
