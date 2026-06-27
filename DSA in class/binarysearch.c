#include<stdio.h>
void main()
{
    int a[5]={3,6,8,9,12};
    int beg, mid , end , item;
    beg = 0;
    end=4;
    mid = (end + beg)/2;
    printf("enter the element which you want to find");
    scanf("%d",&item);
    while(beg<= end){
        if(a[mid] == item )
        break;

              else if(a[mid]>item)
                end = mid -1 ;
              else
                  beg = mid + 1;
            mid=(beg + end)/2;
    }

    if(a[mid]==item)
    printf("element is found at %d location ", mid+1);
    else
    printf("element not found");

   getch();
   printf("hello");
    
    
    }