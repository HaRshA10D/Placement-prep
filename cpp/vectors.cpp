#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> a,b;
  for(int i=0;i<5;i++) a.push_back(i*i);
  for(int i=0;i<5;i++) cout << a[i] << " ";
  cout << endl;
  for(vector<int>::iterator ia=a.begin();ia!=a.end();++ia) cout << *ia << " ";
  cout << endl;
  for(vector<int>::reverse_iterator ia=a.rbegin();ia!=a.rend();++ia) cout << *ia << " ";
  cout << endl;
  cout << "Size: " << a.size() << endl;
  cout << "Capacity: " << a.capacity() << endl;
  cout << "Max size: " << a.max_size() << endl;
  for(int i=0;i<10;i++) b.push_back((i+1)*10);
  for(int i=0;i<10;i++) cout << b[i] << " ";
  cout << endl;
  cout << b.at(6) << " " << b.front() << " " << b.back() << endl;
  return 0;
}
