#include<stdio.h>
 int main(){
    int n;
    printf("enter the value of n:");
    scanf("%d",&n);

        for(int j =1; j<=n; j++){
            for(int i = 1; i<=n;i++){
                if(i%2!=0){
                    printf("*");
                }
                
            }
            
           printf("*\n"); 
        }
     
    
 }