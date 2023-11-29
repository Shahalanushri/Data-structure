//doubly linked list operations
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
	};
	int main()
	{
	struct node*insert(struct node*,int);
	struct node*delete(struct node*,int);
	struct node*search(struct node*,int);
	int option,data;
	struct node*dl=(struct node*)0,*ans;
	do
	{
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Search\n");
	printf("4.Exit\n");
	printf("Option:\n");
	scanf("%d",&option);
	switch(option)
	{
	case 1:printf("Data: \n");
		   scanf("%d",&data);
		   dl=insert(dl,data);
		   break;
	case 2:printf("Item: \n");
		   scanf("%d",&data);
		   dl=delete(dl,data);
		   break;
	case 3:printf("item:\n");
		   scanf("%d",&data);
		   ans=search(dl,data);
		   if(ans==(struct node*)0)
		   printf("not found\n");
		   else
		   printf("found\n");
		   break;
	case 4:exit(0);
}
}
while(1);
}
// fuction to insert an item
	struct node*insert(struct node*dl,int item)
	{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=item;
	t->left=(struct node *)0;
	t->right=dl;
	if(dl!=(struct node *)0)
	dl->left=t;
	return t;
	}
//fuction to search an item in doubly linked list
	struct node*search(struct node*dl,int item)
	{
	while(dl!=(struct node*)0 && dl->data!=item)
	dl=dl->right;
	return dl;
	}
//fuction to delete an item
	struct node*delete(struct node*dl,int item)
	{
	struct node*t;
	t=search(dl,item);
	if(t==(struct node*)0)
	printf("Not found\n");
	else
	{   //remove one and only node
	if(t->left==(struct node*)0 && (t->right==(struct node *)0))//case of 1st node
	dl==(struct node*)0;
	else if(t->left==(struct node*)0) //first node removal
	{
	t->right->left=t->left;
	dl=dl->right;
	}
	else if(t->right==(struct node*)0) //last node removal
	t->left->right=t->right;
	else//removal of interior node
	{
	t->left->right=t->right;
	t->right->left=t->left;
	}
	free(t);
	printf("%d deleted\n",item);
	}
	return dl; 
}
		          
		     
	  
