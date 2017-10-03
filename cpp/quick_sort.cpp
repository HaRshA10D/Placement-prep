#include <iostream>
using namespace std;
void swap(int* a,int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int arr[],int l,int r){
  int pivot = arr[r];
  int j = l-1;
  for(int i=l;i<r;i++){
    if(arr[i] <= pivot){
      j++;
      swap(arr+i,arr+j);
    }
  }
  swap(arr+r,arr+j+1);
  return j+1;
}
void quick_sort(int arr[],int l,int r){
  if(r > l){
    int pivot = partition(arr,l,r);
    quick_sort(arr,l,pivot-1);
    quick_sort(arr,pivot+1,r);
  }
}
int main(){
  int a[] = {3,1,7,8,5,11,9,22,2};
  int n = int(sizeof(a)/sizeof(int));
  quick_sort(a,0,n-1);
  for(int i=0;i<n;i++) cout << a[i] << " ";
}
