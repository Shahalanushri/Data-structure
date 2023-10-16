#include<stdio.h>
void main()
{
  void readarray(int[],int);
  void printarray(int[],int);
  void sortarray(int[],int);
  void merge(int[],int[],int[],int,int);
  int ar1[100],ar2[100],ar3[200],m,n;
  printf("no of elements in first array:\n");
  scanf("%d",&m);
  printf("enter elements in first array:\n");
  readarray(ar1,m);
  printf("no of elements in second array:\n");
  scanf("%d",&n);
  printf("enter the elements of second array:\n");
  readarray(ar2,n);
  sortarray(ar1,m);
  sortarray(ar2,n);
  merge(ar1,ar2,ar3,m,n);
  printf("merge array\n");
  printarray(ar3,m+n);
}
void readarray(int x[],int n)
{
  int i;
  for(i=0;i<n;i++)
  scanf("%d",&x[i]);
  } 
void printarray(int x[],int n)
  {
  int i;
  for(i=0;i<n;i++)
  printf("%d\t",x[i]);
  printf("\n");
  }
void sortarray(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  for(j=i+1;j<n;j++)
  if(a[i]>a[j])
  {
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
   }  
} //merge 2 arrays
void merge(int ar1[],int ar2[],int ar3[],int m,int n)
{
 int i,j,k;
 i=j=k=0;
 while(i<m&&j<n)//compare&copy elements
  if(ar1[i]<ar2[j])
  ar3[k++]=ar1[i++];
 else
  ar3[k++]=ar2[j++];  
  while(i<m)
  ar3[k++]=ar1[i++];
  while(i<n)
   ar3[k++]=ar2[j++];
   return;
}
  
