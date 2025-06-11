#include<stdio.h>
int main()
{
    int i, y, PhyAddre, offset;
    int NoSeg, SegmentTable[10][10];

    printf("\nEnter number segments -- ");
    scanf("%d", &NoSeg);
    printf("\nEnter the Segmentation Table data: Base value & Limit Value\n -- ");
    for(i=0;i<NoSeg;i++)
    scanf("%d%d", &SegmentTable[i][0],&SegmentTable[i][1]);

    printf("\n----Enter the Segmentation Table data---\n");
    printf("Segment NO || Base || Limit || \n");
    for(i=0;i<NoSeg;i++)
    printf("||   %d    ||  %d  ||  %d   || \n",i,SegmentTable[i][0],SegmentTable[i][1]);

     int yes=1;
    
do
    {
    printf("\nEnter Logical Address to find Physical Address ");
    printf("\nEnter segment number and offset\n ");
    scanf(" %d %d",&y, &offset);
    
    if(offset>SegmentTable[y][1])
    {
        printf("Trap : Addressing Error\n"); 
    }
    else
    {
    PhyAddre=SegmentTable[y][0]+offset;
    printf("\n The Physical Address is -- %d", PhyAddre);
    printf("\nContinue : yes=1,no=0\n");
        scanf("%d",&yes);
    }
    }while(yes==1);
    
    return 0;
}





output
Enter number segments -- 5

Enter the Segmentation Table data: Base value & Limit Value
 -- 219 600
2300 14
90 100
1327 580
1952 96

----Enter the Segmentation Table data---
Segment NO || Base || Limit || 
||   0    ||  219  ||  600   || 
||   1    ||  2300  ||  14   || 
||   2    ||  90  ||  100   || 
||   3    ||  1327  ||  580   || 
||   4    ||  1952  ||  96   || 

Enter Logical Address to find Physical Address 
Enter segment number and offset
 0 430

 The Physical Address is -- 649
Continue : yes=1,no=0
1

Enter Logical Address to find Physical Address 
Enter segment number and offset
 1 10

 The Physical Address is -- 2310
Continue : yes=1,no=0
1

Enter Logical Address to find Physical Address 
Enter segment number and offset
 2 500
Trap : Addressing Error

Enter Logical Address to find Physical Address 
Enter segment number and offset
 0
8

 The Physical Address is -- 227
Continue : yes=1,no=0
0

