#include<stdio.h>
int main()
{
   int a[50],num, x,y,temp;
   printf("enter the number of element that you want to insert ");
   scanf("%d",&num);

   printf("enter the elements of array");
   //insertion
   for(x=0; x< num;x++){
    scanf("%d",&a[x]);
                   }

for(x=0;x<num-1;x++)
{
    for(y=0; y<num-x-1;y++){
        if(a[y]>a[y+1]){
            temp=a[y];
            a[y]=a[y+1];
            a[y+1]=temp;
        }
    }
}
printf("array after implementing bubble sort");
for(x=0;x<num;x++){
    printf("\n%d",a[x]);
}

    return 0;

}