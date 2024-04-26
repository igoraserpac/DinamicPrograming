#include <stdio.h>

/*
    Problem: 
        Climbing Stairs (k steps)

        You are climbing a stair case. It takes n steps to reach the top.
        Each time you can either climb 1..k steps.
        You are not allowed to step on red steps
        In how many distincts ways can you climb to the top?

    Objective function: 
        f(i) is the number of distinct way to climb to the i-th stair.

    Recurrence relation: 
        f(n) = f(n-1) + f(n-2) + ... + f(n-k) if n is not red;
        0 if n is red
*/

long int climbingStairs(long int n, long int k, int *red){
    long int vector[n+1];
    vector[0] = 1;
    for(long int i = 1; i < n+1; i++){
        vector[i] = 0;
        for(long int j = 1; j < k+1; j++){
            if(i-j < 0) continue;
            if(red[i]) vector[i] = 0;
            else vector[i] += vector[i-j];
        }
    }
    return vector[n];
}

int main(){
    long int n, k, nRed;
    printf("N: ");
    scanf("%ld", &n);
    printf("K: ");
    scanf("%ld", &k);
    printf("Number of red steps: ");
    scanf("%ld", &nRed);
    int red[n+1];
    for(int i = 0; i < n+1; i++){
        red[i] = 0;
    }
    printf("Red steps: ");
    for(int i = 0; i < nRed; i++){
        long int t;
        scanf("%ld", &t);
        red[t] = 1;
    }
    printf("Number of ways to climb to the %ldth stair: %ld\n", n, climbingStairs(n, k, red));
    return 0;
}