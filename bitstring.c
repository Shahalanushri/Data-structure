//set operations
#include<stdio.h>
typedef struct
{
unsigned char x:1;}bit;
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
 void readset(bit[],int n);
 void printset(bit[]);
 void unionset(bit[],bit[],bit[]);
 void intersect(bit[],bit[],bit[]);
 void difference(bit[],bit[],bit[]);
 bit a[10]={0},b[10]={0},c[10]={0};
 int n;
 printf("No of elements in set A:");
 scanf("%d",&n);
 readset(a,n);
 printf("No of elements in set B:");
 scanf("%d",&n);
 readset(b,n);
 printf("set A:");
 printset(a);//print a
 printf("set B:");
 printset(b);//print b
 unionset(a,b,c);
 printf("A U B=");
 printset(c);
 intersect(a,b,c);
 printf("A intersect B=");
 printset(c);
 difference(a,b,c);
 printf("A-B=");
 printset(c);
 }
 //to rear a set and store as bit string 
 void readset(bit a[],int n)
 {
 int i,x,k;
 printf("Enter %d elements:",n);
 for(i=0;i<n;++i)
 {
 scanf("%d",&x);
 for(k=0;k<size;++k)
 if(uset[k]==x)//if x is a member of universal set
 {
 //set 1 corresponding to x in a[]
 a[k].x=1;
 break;
 }
 }
 return;
 }
 //to print a ser from bit string representation 
 void printset(bit a[])
 {
 int k;
 printf("{");
 for(k=0;k<size;++k)
 {
 if(a[k].x==1)
 printf("%d,",uset[k]);
 }
 printf("\b}\n");
 return;
 }
 //to find union of two sets using bitstring
 void unionset(bit a[],bit b[],bit c[])
 {
 int k;
 for(k=0;k<size;++k)
 c[k].x=a[k].x | b[k].x;
 return;
 }
 
 void intersect(bit a[],bit b[],bit c[])
 {
 int k;
 for(k=0;k<size;++k)
 c[k].x=a[k].x & b[k].x;
 return;
 }
 //to find difference of 2 sets
 void difference(bit a[],bit b[],bit c[])
 {
 int k;
 for(k=0;k<size;++k)
 if(a[k].x==1)
 c[k].x=a[k].x ^ b[k].x;
 return;
 }
   
