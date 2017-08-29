#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node* createNode(int data){
	node* nd = new node;
	nd->data = data;
	nd->next = NULL;
	return nd;
}
node* createLl(node *head,int in[],int n){
	node **po = &head;
	for(int i=0;i<n;i++){
		*po = createNode(*(in+i));
		po = &((*po)->next);
	}
	cout << "list initaited" << endl;
	return head;
}
void printLl(node *head){
	cout << "Printing all: ";
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void searchLl(node* head,int se){
	int c = 1, f = 0;
	while(head != NULL){
		if(head->data==se){
			cout << "Found at " << c << endl;
			f = 1;
		}
		c++;
		head = head->next;
	}
	if(f==0){
		cout << se << " not found!!" << endl;
	}
}
int noelementsLl(node *head){
	int tot = 0; 
	while(head != NULL){
		head = head->next;
		tot++;
	}
	return tot;
}
node* addNode(node* head,int pos,int data){
	node* stor = head;
	for(int i=1;i<pos-1;i++){
		head = head->next;
	}
	node* newNode = createNode(data);
	if(pos == 1){
		newNode->next = head;
		head = newNode;
	}
	else if(head->next == NULL){
		head->next = newNode;
		head = stor;
	}else{
		newNode->next = head->next;
		head->next = newNode;
		head = stor;
	}
	return head;
}
node* deleteNode(node* head,int pos){
	node* stor = head;
	for(int i=1;i<pos-1;i++){
		head = head->next;
	}
	if(pos==1){
		head = stor->next;
		delete stor;
	}else if(pos==noelementsLl(head)){
		head->next = NULL;
		head = stor;
	}else{
		node* del = head->next;
		head->next = del->next;
		delete del;
		head = stor;
	}
	return head;
}
node* reverseLl(node* head){
	node* currNode = head;
	node* prevNode = NULL;
	node* nextNode = NULL;
	while(currNode != NULL){
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	return prevNode;
}
int main(){
	node *head = NULL;
	int n;
	cout << "Enter initial numbers:" << endl; 
	cin >> n;
	int in[n];
	cout << "Enter initial list contents:" << endl;
	for(int i=0;i<n;i++) cin >> in[i];
	head = createLl(head,in,n);
	int op=0,se,pos;
	while(op!=6){
		cout << "Choose your option: " << endl << "1.search\t2.delete\t3.add\t4.print list\t5.reverse\t6.exit" << endl;
		cin >> op;
		switch(op){
			case 1: cout << "Enter number to be searched: ";
					cin >> se;
					searchLl(head,se);
					break; 
			case 2: cout << "Enter position to be deleted under " << noelementsLl(head) << ": "; 
					cin >> pos;
					if(pos>noelementsLl(head)){
						cout << "Shame on you." << endl;
						break;
					}else head = deleteNode(head,pos);
					break;
			case 3: cout << "Enter position and number to be added under " << noelementsLl(head) << ": "; 
					cin >> pos >> se;
					if(pos>noelementsLl(head)+1){
						cout << "Don't do this to yourself." << endl;
						break;
					}else head = addNode(head,pos,se);
					break;
			case 4: printLl(head);
					break;
			case 5: cout << "Reversing the list!! why you do this?" << endl;
					head = reverseLl(head);
					break;
			case 6: cout << "Good bye!!" << endl; 
					break;
			default: cout << "Wrong option try again" << endl;
		}
	}
	return 0;
}
