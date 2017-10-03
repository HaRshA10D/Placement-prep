#include<iostream>
#include<vector>
using namespace std;
struct uniformString{
    int value;
    int length;
};
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
  a.clear();
  for(int i=0;i<10;i++) a.push_back((i+1)*10);
  for(int i=0;i<10;i++) cout << a[i] << " ";
  cout << endl;
  cout << a.at(6) << " " << a.front() << " " << a.back() << endl;
  std::string m = "harsha";
  cout << m.substr(2,1) << endl;
  std::vector<std::string> v;
  v.push_back("harsha");
  cout << (int('z')-96)%26 << int('a') << endl;
  char arr[26] = " ";
  cout << (arr[0]==' ') << endl;
  int me = 'z';
  cout << me << endl;
  std::string am = "aa";
  vector<char> amv(am.begin(),am.end());
  amv.erase(amv.begin()+0);
  amv.erase(amv.begin()+0);
  for(vector<char>::iterator it=amv.begin();it!=amv.end();++it){
    cout << *it;
  }
  cout << char(99) << endl;
  int *ep,ea;
  ep = &ea;
  *ep = 7;
  cout << ea << endl;
  uniformString temp;
  temp->value = 5;
  temp->length = 6;
  
  return 0;
}
