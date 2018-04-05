#include<iostream>
using namespace std;

class node{
     public:
     node *parent;
     node *left;
     node *right;
     int data;
    node(){
     parent=left=right=NULL;
     data=0;
    }
};

class BStree{
     public:
     node *root;

    BStree()
    {
    root=NULL;
    }


 void insert(int x){
   node *temp=new node;
   temp->data=x;
   temp->parent=temp->left=temp->right=NULL;

   if(root==NULL)
   { root=temp;
   }
   else{ node *curr;
         curr=root;
        while(1){
            if(x<curr->data){

               if(curr->left==NULL){
                  temp->parent=curr;
                  curr->left=temp;
               break;
               }
              else{curr=curr->left;}
            }
           else {
                    if(curr->right==NULL)
                       {
                       temp->parent=curr;
                       curr->right=temp;
                     break;}
                   else{curr=curr->right;}
                  }

        }
     }
 }

 void display(node *temp){

      if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right);
}

node* searchNode(int dt)
{
 node * check = root;
 if(check == NULL)
     return NULL;
 else
  while(true)
  {
   if(check->data == dt)
   {
     cout << "\nNode found.\n";
     return check;
   }
   else if(check->data > dt)
   {
    if(check->left == NULL)
      {
       cout << "\nNOT FOUND.\n";
       return NULL;
      }
    else
       check = check->left;
   }
   else
   {
    if(check->right == NULL)
    {
      cout << "\nNOT FOUND.\n";
      return NULL;
    }
    else
      check = check->right;
   }

  }

}
void deleteNode(int s)
{
  node*curr=searchNode(s);
 if(curr==NULL){
 cout<<"The Node is not in the tree.";
 }
 else
 { 
  if(curr->right==NULL && curr->left==NULL)
  {
    if(curr->parent->right==curr)
      curr->parent->right=NULL;
    else if(curr->parent->left==curr)
      curr->parent->left=NULL;
  }
  else if(curr->right==NULL && curr->left!=NULL) 
  {
    if(curr->parent->right==curr)
    {
      curr->parent->right=curr->left;
      curr->left->parent=curr->parent;
    }
    else if(curr->parent->left==curr)
    {
      curr->parent->left=curr->left;
      curr->left->parent=curr->parent;
    }
  }  
  else if(curr->right!=NULL && curr->left==NULL) 
  {
    if(curr->parent->right==curr)
      {
       curr->parent->right=curr->right;
       curr->right->parent=curr->parent;
      }
    else if(curr->parent->left==curr)
    {
      curr->parent->left=curr->right;
      curr->right->parent=curr->parent;
    }
  }
  else
  {
    node*replacement=curr->left;
    while(replacement->right!=NULL)
    {
      replacement=replacement->right;
    }
    curr->data=replacement->data;
    deleteNode(replacement->data);
  } 
  }
}




 };

 int main(){
 BStree b;
 cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DISPLAY";
 cout<<"\n3.SEARCH";
 cout<<"\n4.DELETE";
 cout<<"\n5.EXIT";

int ch,x;
do{
  cout<<"\nenter your choice (1-4): ";
  cin>>ch;
  switch(ch){
  case 1:cout<<"\nenter the data you want to enter :";
         cin>>x;
         b.insert(x);break;
  case 2:b.display(b.root);break;
  case 3:cout<<"\nenter the data you want to search :";
         cin>>x;
         b.searchNode(x);break;
case 4:cout<<"\nenter the data you want to delete :";
         cin>>x;
         b.deleteNode(x);break;
  deafult:cout<<"\ntype 1,2,3 or 4 ";break;
  }
}while(ch!=5);
return 0;
}


