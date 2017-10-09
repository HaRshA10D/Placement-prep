#include<iostream>
using namespace std;
int swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int heapify(int a[],int i,int n)
{
  int l=2*i+1;
  int r=2*i+2;
int large;
if(l<n && a[l]>a[i])
 large=l;
else
large=i;

if(r<n && a[r]>a[i])
large=r;

if(large!=i)
{swap(&a[i],&a[large]);
heapify(a,large,n);
}

}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];

  for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  for(int i=n/2;i>0;i--)
  heapify(a,i,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";


}
