//structure to represent an object of a set in linked representation 
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
 int value;
 struct rep *repptr;//pointer to header node of the list
 struct node *next;
 }node;
 //structure to represent header node of linked representation of set
 typedef struct
 {
  node *head;
  node *tail;
 }rep;
 //structure to store key and object node pointer
 typedef struct
 {
  int key;
  node *obj_node_ptr;
  struct noaddr *next;
 }noaddr;
 noaddr *ndr=0; //list to store keys and object node pointer
 //function to create a set for an object
    void makeset(int a) //create a object node pointer
    {
      noaddr *t=(noaddr*)malloc(sizeof(noaddr));
 //create a new set
      rep*newset=(rep*)malloc(sizeof(rep));
      node*n=(node*)malloc(sizeof(node));
 //fill values
      n->value=a;
      n->repptr=newset;
      n->next=0;
 //initialize head&tail
      newset->head=newset->tail=n;
 //to store object nodepointer&key
      t->obj_node_ptr=n;
      t->key=a;
      t->next=ndr;
      ndr=t;
      }
 // function nto return pointer of the representative(header)node of the set containing x
      rep*find(int x)
      {
      noaddr*t=ndr;
      while(t->key!=x&&t!=0)
      t=t->next;
      return t->obj_node_ptr->repptr;
      }                    
 // to find union of two sets corresponding to objects a given
      void unionset(int key1,int key2)
      {
       rep*set1,*set2;
       node*t1;
       set1=find(key1);
       set2=find(key2);
       if(set1==set2)
        printf("\n %d and %d belongs to same set \n",key1,key2);
       else
       {//changing the header pointer to obj of set 2 to that of set
       t1=set2->head;
       while(t1!=0)
       {
        t1->repptr=set1;
        t1=t1->next;
       }
       set1->tail->next=set2->head;
       set1->tail=set2->tail ;//set the tail of set 1 to tail of set 2
       }
       free(set2);
       }
              
//function to display a set
      void display_set(int a)
      {
       rep *r;
       node *t;
       r=find(a);
       t=r->head;
       printf("set members containing %d :",a);
       while(t!=0)
       {
       printf("%d  ",t->value);
       t=t->next;
       }
       }
     void main()
       {
       int opt,data,data1,data2;
       do
       {
        printf("\n1.Insert\n");
	printf("2.Find set\n");
	printf("3.Union set\n");
	printf("4.Display set\n");
	printf("5.Exit\n");
	printf("Enter your Option:\n");
	scanf("%d",&opt);
	switch(opt)
         {
          case 1:
          printf("Enter the data:");
          scanf("%d",&data);
          makeset(data);
          break;
          case 2:
          printf("enter set value:");
          scanf("%d",&data);
          printf("Reference of set containing %d is %x\n",data,find(data));
          break;
          case 3:
          printf("Enter the data:");
          scanf("%d%d",&data1,&data2);
          unionset(data1,data2);
          break;
          case 4:
          printf("Enter the data:");
          scanf("%d",&data);
          display_set(data);
          break;
          case 5:
          exit(0);
          }
          }
          while(1);
          }
       
        
