#include<iostream>
#include<algorithm>
using namespace std;
void swap(int *a,int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void reverse(int a[],int start,int end){
  while(start<end){
      swap(&a[start],&a[end]);
      start++;
      end--;
  }
}
int main()
 {
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int a[n];
        for(int j=0;j<n;j++) cin >> a[j];
        sort(a,a+n);
        reverse(a,n/2,n-1);
        for(int j=0;j<n;j++) cout << a[j] << " ";
        cout << endl;
    }
	return 0;
}
