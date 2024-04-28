#include <stdio.h>

/*
    Problem: 
        Paid Staircase (reconstruct version)

        You are climbing a stair case. It takes n steps to reach the top and you
        have to pay p[i] to step on i-th stair.
        Each time you can either climb 1 ro 2 steps.
        What is the cheapest amount you have to pay to get to the top and what is
        the path pf minimum cost?

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
    long int minimum[n+1], previous[n+1];
    minimum[0] = 0; minimum[1] = price[1];
    previous[0] = 0; previous[1] = 0;
    for(long int i = 2; i < n+1; i++){
        minimum[i] = price[i] + min(minimum[i-1], minimum[i-2]);
        if(min(minimum[i-1], minimum[i-2]) == minimum[i-1]) previous[i] = i-1;
        else previous[i] = i-2;
    }
    long int last = n;
    printf("Path of minimum cost: ");
    while(last != 0){
        printf("%ld <- ", last);
        last = previous[last];
    }
    printf("0\n");
    return minimum[n];
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
    return 0;
}