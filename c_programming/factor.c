#include<stdio.h>

int main(){
    int n =200 ;
    // scanf(" enter the value of n :%d",&n);
   int temp =  n;
 
    for(int i = temp; i >=1; i--){
        if(temp%2==0){
            printf(" %d ",temp/2);
            temp = temp / 2;
            printf("2");
        }
        if(temp %10 == 0){
            printf(" %d ",temp/10);
            temp = temp/10;
            printf("10");

        }
        // else if(temp %3 == 0){
        //     printf(" %d ",temp/3);
        //     temp = temp/3;
        //     printf("3");


        // } else if(temp %5 == 0){
        //     printf(" %d ",temp/3);
        //     temp = temp/5;
        //     printf("5");

        // }
        // else if(temp %7 == 0){
        //     printf(" %d ",temp/3);
        //     temp = temp/5;
        //     printf("7");

        // }



    }
    return 0;
}