#include <stdio.h>
#include "main.h"

#ifndef TEST
int power(int a,int b){
    int sum=1;
    while(b!=0)
    {
        sum*=a;
        b-=1;
    }
    return sum;
}
int main() {
    printf("Rule Breaker!!!\n");
    printf("5 + 2 = %d\n", addNumber(5, 2));
    printf("%d\n", getTriangleType(3, 4, 5));
<<<<<<< Updated upstream
    int Sum;
    Sum = sum(9, 10, 11);
    printf("sum func. result is: %d.", Sum);
=======
    printf("%d\n", power(2,10));
>>>>>>> Stashed changes
    return 0;

}
#endif // TEST

int addNumber(int a, int b) {
    return a + b;
}

int sum(int x, int y, int z){
    if(x>y)
        return x+y+z;
    else
        return y+z;
}

int getTriangleType(int a, int b, int c) {
    if (a > b && a > c) {
        int temp = c; c = a; a = temp;
    }
    else if (b > a && b > c) {
        int temp = c; c = b; b = temp;
    }

    if (a + b <= c) {
        return -2;
    }
    else if (a * a + b * b == c * c) {
        return 0;
    }
    else if (a * a + b * b > c * c) {
        return 1;
    }
    else if (a * a + b * b < c * c) {
        return -1;
    }
    return -3;
}

<<<<<<< Updated upstream
int check(int num){
    if (num%2==0)
        printf("even");
        return 0;
    if (num%2==1)
        printf("odd");
        return 1;

}

=======
>>>>>>> Stashed changes
