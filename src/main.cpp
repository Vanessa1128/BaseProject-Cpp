#include <stdio.h>
#include "main.h"

#ifndef TEST
int main() {
    printf("Rule Breaker!!!\n");
    printf("5 + 2 = %d\n", addNumber(5, 2));
    printf("%d\n", getTriangleType(3, 4, 5));
    int Sum;
    Sum = sum(9, 10, 11);
    printf("sum func. result is: %d.", Sum);
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

int check(int num){
    if (num%2==0)
        printf("°¸¼Æ");
        return 0;
    if (num%2==1)
        printf("©_¼Æ");
        return 1;

}

