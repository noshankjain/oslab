#include<stdio.h>
int main()
{
    int ms, Fsize, NoFrames, NoProcess, RemFrames, i, j, x, y, pa, offset;
    int NoPages, PageTable[10];

    printf("\nEnter the memory size -- ");
    scanf("%d", &ms);

    printf("\nEnter the Frame size -- ");
    scanf("%d", &Fsize);

    NoFrames = ms/Fsize;
    printf("\n The no. of Frames available in memory are -- %d ", NoFrames);

    RemFrames = NoFrames;

       printf("\n Enter no. of pages required : ");
       scanf("%d", &NoPages);
        
        if(NoPages >RemFrames)
        {
            printf("\n Memory is Full");
            return (0);
        }
        RemFrames = RemFrames - NoPages;
        printf("\n ---Enter page table --- ");
        for(j=0;j<NoPages;j++)
            scanf("%d", &PageTable[j]);
            
        printf("\n ---page table --- ");
        printf(" \n| PNo || FNo |");
        for(j=0;j<NoPages;j++)
            printf(" \n| %d || %d |",j,PageTable[j]);
    	
    int yes=1;
    do
    {
    printf("\nEnter Logical Address to find Physical Address ");
    printf("\nEnter page number and offset -- ");
    scanf(" %d %d",&y, &offset);
    if( y>=NoPages || offset>=Fsize)
	{
        printf("\n trap: Page Number or offset illegal");
	  return(0);
	}
    else
    {
        pa = (PageTable[y]*Fsize) + offset;
        
        printf("Fsize=%d,offset=%d\n,frame no=%d",Fsize,offset,PageTable[y]);
        printf("\n The Physical Address is -- %d", pa);
    }
        printf("\nContinue : yes=1,no=0\n");
        scanf("%d",&yes);
        
    }while(yes==1);
    
    return 0;
}




output
Enter the memory size -- 32

Enter the Frame size -- 4

 The no. of Frames available in memory are -- 8 
 Enter no. of pages required : 4

 ---Enter page table --- 5
6
1
2

 ---page table ---  
| PNo || FNo | 
| 0 || 5 | 
| 1 || 6 | 
| 2 || 1 | 
| 3 || 2 |
Enter Logical Address to find Physical Address 
Enter page number and offset -- 0 0
Fsize=4,offset=0
,frame no=5
 The Physical Address is -- 20
Continue : yes=1,no=0
1

Enter Logical Address to find Physical Address 
Enter page number and offset -- 1 3
Fsize=4,offset=3
,frame no=6
 The Physical Address is -- 27
Continue : yes=1,no=0
0

