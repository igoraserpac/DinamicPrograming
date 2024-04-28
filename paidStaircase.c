#include <stdio.h>

/*
    Problem: 
        Paid Staircase

        You are climbing a stair case. It takes n steps to reach the top and you
        have to pay p[i] to step on i-th stair.
        Each time you can either climb 1 ro 2 steps.
        What is the cheapest amount you have to pay to get to the top?

    Objective function: 
        f(i) is the minimum price to climb to the i-th stair.

    Recurrence relation: 
        f(n) = p[n] + min(f(n-1), f(n-2))
*/

long int min(long int a, long int b){
    if(a<b) return a;
    return b;
}

long int paidStaircase(long int n, int *price){
    long int minimum[n+1];
    minimum[0] = 0;
    minimum[1] = price[1];
    for(long int i = 2; i < n+1; i++){
        minimum[i] = price[i] + min(minimum[i-1], minimum[i-2]);
    }
    return minimum[n];
}

long int improvedPaidStaircase(long int n, int *price){
    long int a = 0, b = price[1], c;
    for(long int i = 2; i < n+1; i++){
        c = price[i] + min(a, b);
        a = b;
        b = c;
    }
    return c;
}

int main(){
    long int n;
    printf("N: ");
    scanf("%ld", &n);
    int price[n+1];
    price[0] = 0;
    for(int i = 1; i < n+1; i++){
        long int t;
        printf("Price of the %d step: ", i);
        scanf("%ld", &t);
        price[i] = t;
    }
    printf("Minimum price to climb to the %ldth stair: %ld\n", n, paidStaircase(n, price));
    printf("Minimum price to climb to the %ldth stair: %ld (version with memory optimization)\n", n, improvedPaidStaircase(n, price));
    return 0;
}