#include<stdio.h>
int main()
{
 int i,n,m,tot,s[20];
 printf("enter total memory size: \n");
 scanf("%d",&tot);
 printf("enter no of processes: \n");
 scanf("%d",&n);
 printf("enter memory of OS: \n");
 scanf("%d",&m);
 for(i=0;i<n;i++)
 {
  printf("enter size of process %d: ",i);
  scanf("%d",&s[i]);
 }
 tot=tot-m;
 for(i=0;i<n;i++)
 {
  if(tot>=s[i])
  {
   printf("allocate memory to process %d\n",i);
   tot-=s[i];
  }
  else
  {
   printf("process %d is blocked\n",i);
  }
 }
 printf("external fragmentation is %d\n",tot);
 return 0;
}
