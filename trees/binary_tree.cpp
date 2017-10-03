#include <iostream>
#include <climits>
using namespace std;
struct node{
  int data;
  node* left;
  node* right;
};
node* newNode(int val){
  node* now = new node();
  now->data = val;
  now->left = NULL;
  now->right = NULL;
  return now;
}
node* insertNode(node* root,int val){
  if(root==NULL) return newNode(val);
  if(val < root->data){
    root->left = insertNode(root->left,val);
  }
  else root->right = insertNode(root->right,val);
  return root;
}
void inOrder(node* root){
  if(root!=NULL){
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}
bool isBST(node* root,int min,int max){
  if(root == NULL) return true;
  if(root->data > max || root->data < min) return false;
  return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);
}
int height(node* root){
  if(root == NULL) return 0;
  else{
    int leftH = height(root->left);
    int rightH = height(root->right);
    if(leftH>rightH) return 1+leftH;
    return 1+rightH;
  }
}
void printGivelLevel(node* root,int level){
  if(root == NULL) return;
  if(level == 1) cout << root->data << " ";
  else if(level > 1){
    printGivelLevel(root->left,level-1);
    printGivelLevel(root->right,level-1);
  }
}
void levelOrder(node* root){
  int treeHeight = height(root);
  for(int i=1;i<=treeHeight;i++)
    printGivelLevel(root,i);
}
int main(){
  node* root = NULL;
  int n,temp;
  cout << "Enter inital no of nodes: ";
  cin >> n;
  cout << "Enter those " << n << " nodes : " << endl;
  for(int i=0;i<n;i++){
    cin >> temp;
    root = insertNode(root,temp);
  }
  cout << "Printing inorder: ";
  inOrder(root);
  cout << endl;
  cout << "BST check: " << isBST(root,INT_MIN,INT_MAX) << endl;
  cout << "Height: " << height(root)-1 << endl;
  cout << "Printing level order: ";
  levelOrder(root);
  cout << endl;
}
