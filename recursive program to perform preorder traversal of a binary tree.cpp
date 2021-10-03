#include<iostream>
using namespace std;
struct node {
   int data;
   struct node *left;
   struct node *right;
};
struct node *createNode(int p) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->data = p;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}
void preorder(struct node *root) {
   if (root != NULL) {
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}
struct node* insert(struct node* node, int val) {
   if (node == NULL) 
   return createNode(val);
   if (val < node->data)
   node->left = insert(node->left, val);
   else if (val > node->data)
   node->right = insert(node->right, val);
   return node;
}
int main() {
   int flag,n,a;
   struct node *root = NULL;
    
   cout<<"Enter the root node: \n";
   cin>>a;
   cout<<"Your elements will be added in the order of level wise and from left to right.\n ";
   root = insert(root,a);
   cout<<" Do you want to add more elements in the tree? Choose 1 for yes and 0 for no.\n";
    cin>>flag;
   while (flag==1)
   {

       cout<<"Enter the element: \n";
       cin>>n;
       insert(root,n);
       cout<<"Do you want to add more elements in the tree? Choose 1 for yes and 0 for no.\n";
       cin>>flag;

   }

   cout<<"\n Pre-Order traversal of a Binary Tree is: ";
   preorder(root);
   return 0;
}

