#include <stdio.h>
#include <conio.h>
unsigned int fact(int x){
  return(x*fact(x-1));
}

int main(){  
    int x,y=10;
    x=4;
    y=fact(x);
    printf("%d\n",y);
  
getch();
return 0;
}