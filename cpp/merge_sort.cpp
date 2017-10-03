#include <iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
  int n1 = mid-l+1,n2 = r-mid;
  int a[n1],b[n2];
  for(int i=0;i<n1;i++) a[i] = arr[l+i];
  for(int i=0;i<n2;i++) b[i] = arr[mid+i+1];
  int i=0,j=0,k=l;
  while(i < n1 && j < n2){
    if(a[i]>b[j]){
      arr[k] = b[j];
      j++;
    }else{
      arr[k] = a[i];
      i++;
    }
    k++;
  }
  while(i<n1){
    arr[k] = a[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k] = b[j];
    j++;
    k++;
  }
}
void merge_sort(int arr[],int l,int r){
  if(r > l){
    int mid = (l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
}
int main(){
  int a[] = {3,1,7,8,5,11,9,22,2};
  int n = int(sizeof(a)/sizeof(int));
  merge_sort(a,0,n-1);
  for(int i=0;i<n;i++) cout << a[i] << " ";
}
