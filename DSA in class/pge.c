#include<stdio.h>
#define size 5
int top=-1;
int arr[size];
void push(int x){
    if(top==size-1)
    printf("Stack overflow");
    else
    {
        top+=1;
        arr[top]=x;
    }
}
void pop()
{
    if(top==-1)
    printf("stack uderflow");
    else
    top=top-1;
}
 
  int pge(int x){int c=0;
    if(top==-1)
{
    push (x);
    return -1;
}
else if(x>arr[top])
{
    pop();
    return -1;

}
else{
    push(x);
    c=arr[top-1];
    return c;
}



  }
int main()
{int a[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",arr[i]);
a[i]=pge(arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;

}
