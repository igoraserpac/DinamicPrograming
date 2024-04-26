#include <stdio.h>

/*
    Problem: 
        Climbing Stairs

        You are climbing a stair case. It takes n steps to reach the top.
        Each time you can either climb 1 or 2 steps.
        In how many distincts ways can you climb to the top?

    Objective function: 
        f(i) is the number of distinct way to climb to the i-th stair.

    Recurrence relation: 
        f(n) = f(n-1) + f(n-2)
*/

long int climbingStairs(long int n){
    if(n < 2) return 1;
    long int vector[n+1];
    vector[0] = 1;
    vector[1] = 1;
    for(long int i = 2; i < n+1; i++){
        vector[i] = vector[i-1] + vector[i-2];
    }
    return vector[n];
}

int main(){
    long int n;
    printf("N: ");
    scanf("%ld", &n);
    printf("Number of ways to climb to the %ld th stair: %ld\n", n, climbingStairs(n));
}