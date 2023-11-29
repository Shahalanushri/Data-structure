//BST insert,search,delete,traverse
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*lchild,*rchild;
};
void main()
{
struct node * insert(struct node*,int);
struct node * delete(struct node*,int);
int search(struct node *,int);
void inorder(struct node*);
int option,data,ans,item;
struct node*root=(struct node*)0;
do
{
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Traverse\n");
printf("5.Exit\n");
printf("Option:\n");
scanf("%d",&option);
switch(option)
{
case 1:printf("Data\n");
       scanf("%d",&data);
       root=insert(root,data);
       break;
case 2:printf("Data\n");
       scanf("%d",&data);
       root=delete(root,data);
       break;
case 3:printf("item to search:\n");
       scanf("%d",&data);
       ans=search(root,data);
       if(ans!=0)
       printf("Found\n");
       else
       printf("Not found\n");
       break;
case 4:inorder(root);
       break;
case 5:exit(0);
}
}
while(1);
}
//fuction to insert an item
struct node*insert(struct node *root,int data)
{
struct node*par=(struct node*)0,*t,*troot=root;
while(root!=(struct node*)0 && data!=root->data)
{
par=root;
if(data<root->data)
{
root=root->lchild;
}
else
{
root=root->rchild;
}
}
if(root!=(struct node *)0)
printf("Duplicate\n");
else
{
t=(struct node *)malloc(sizeof(struct node));
t->data=data;//node creation
t->lchild=t->rchild=(struct node *)0;
if(par==(struct node *)0)//first node
troot=t;
else if(data<par->data)
par->lchild=t;
else
par->rchild=t;
}
return troot;
}
//fuction to delete an item
struct node * delete(struct node * root,int data)
{
struct node * par=(struct node *)0,*t,*sucpar,*suc,*lchild,*rchild;
t=root;
while(root!=(struct node *)0 && root->data!=data)
{
par=root;
if(data<root->data)
root=root->lchild;
else
root=root->rchild;
}
if(root==(struct node *)0)
printf("Not found\n");
else
{
if(root->lchild==(struct node *)0 && root->rchild==(struct node *)0)
{
if(par==(struct node *)0)
t=(struct node *)0;
else if(root->data>par->data)
par->rchild=(struct node*)0;
else
par->lchild=(struct node *)0;
}
else if(root->lchild==(struct node *)0 || root ->rchild==(struct node *)0)
{
if(par==(struct node *)0)
t=root->lchild==(struct node *)0 ? root->rchild:root->lchild;
else if(data<par->data)
par->lchild=root->lchild==(struct node*)0 ? root->rchild:root->lchild;
else
par->rchild=root->lchild==(struct node*)0? root->rchild:root->lchild;
}
else
{
suc=root->rchild;
sucpar=root;
while(suc->lchild!=(struct node *)0)
{
sucpar=suc;
suc=suc->lchild;
}
root->data=suc->data;
if(suc->data<sucpar->data)
sucpar->lchild=suc->rchild;
else
sucpar->rchild=suc->rchild;
root=suc;
}
}
free(root);
return t;
}
//fuction to search an item in BST
int search(struct node*root,int data)
{
while(root!=(struct node*)0 && root->data!=data)
{
if(data<root->data)
root=root->lchild;
else
root=root->rchild;
}
if(root==(struct node*)0)
return 0;
else
return 1;
}

//fuction to traverse an item
void inorder(struct node * root)
{
if(root!=(struct node *)0)
{
inorder(root->lchild);
printf("%d\t",root->data);
inorder(root->rchild);
}
}
