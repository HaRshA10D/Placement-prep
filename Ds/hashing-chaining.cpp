#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
  int data;
  node* next;
};
int hash(int x, int h){
  return x%h;
}
node* createNode(int data){
	node* nd = new node;
	nd->data = data;
	nd->next = NULL;
	return nd;
}
node* addData(node* head,int data){
  node** po = &head;
  while(*po != NULL) po = &((*po)->next);
  *po = createNode(data);
  return head;
}
void printRow(node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void searchData(node* head,int se,int ro){
  cout << "Searching in row " << ro << endl;
	int c = 1, f = 0;
	while(head != NULL){
		if(head->data==se){
			cout << "Found at " << c << endl;
			f = 1;
		}
		c++;
		head = head->next;
	}
	if(f==0) cout << se << "not found!!" << endl;
}
node* deleteData(node* head,int data){
  int f = 0;
  if(head != NULL and head->data == data){
    head = head->next;
    f = 1;
  }
  node* stor = head;
  node* prev;
  while(head != NULL and f == 0){
    if(head->data == data){
      prev->next = head->next;
      free(head);
      f = 1;
    }
    prev = head;
    head = head->next;
  }
  if(f==0) cout << "Don't play with me! I am smarter than you" << endl;
  else cout << "Chill man! deleted." << endl;
  return stor;
}
int main(){
  int n;
  cout << "Enter hashing code function mod value: ";
  cin >> n;
  node *a[n];
  for(int i=0;i<n;i++) a[i] = NULL;
  int op = 0, x, k;
	while(op!=5){
		cout << "Choose your option: " << endl << "1.add\t2.delete\t3.print hash table\t4.search\t5.exit" << endl;
		cin >> op;
		switch(op){
			case 1: cout << "Enter data for storing: ";
              cin >> x;
              k = hash(x,n);
              a[k] = addData(a[k],x);
              break;
      case 2: cout << "Enter data for deleting: ";
              cin >> x;
              k = hash(x,n);
              a[k] = deleteData(a[k],x);
              break;
      case 3: cout << "Printing table" << endl;
              for(int i=0;i<n;i++){
                cout << "Row no " << i << " : ";
                printRow(a[i]);
              }
              break;
      case 4: cout << "Seach for data you want: ";
              cin >> x;
              k = hash(x,n);
              searchData(a[k],x,k);
              break;
			case 5: cout << "Good bye!!" << endl;
					    break;
			default: cout << "Do you have eyes dumbass!!" << endl;
		}
	}
  return 0;
}
