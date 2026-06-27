#include<stdio.h>

int main(){
   int candidate1 = 0;
   int candidate2= 0;
     int num[17]= {1,1,1,1,1,1,2,2,2,3,4,5,5,6,7,7,8};
  int n = sizeof(num)/sizeof(num[0]);
  int count1=0;
  int count2 = 0;
  for(int i = 0; i<n ; i++){
    if( candidate1 == num[i]){
        count1++;

    }
    else if( candidate2== num[i]){
        count2++;

    }
    else if(count1==0){
        candidate1=num[i];
        count1=1;
    }
    else if(count2==0){
        candidate2=num[i];
        count2=1;
    }
    
  }
}