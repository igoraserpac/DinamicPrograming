#include <stdio.h>

/*
    Problem: 
        Climbing Stairs (k steps)

        You are climbing a stair case. It takes n steps to reach the top.
        Each time you can either climb 1..k steps.
        In how many distincts ways can you climb to the top?

    Objective function: 
        f(i) is the number of distinct way to climb to the i-th stair.

    Recurrence relation: 
        f(n) = f(n-1) + f(n-2) + ... + f(n-k)
*/

long int climbingStairs(long int n, long int k){
    if(n < 2) return 1;
    long int vector[n+1];
    vector[0] = 1;
    vector[1] = 1;
    for(long int i = 3; i < n+1; i++){
        for(long int j = 1; j < k; j++){
            if(i-j < 0) continue;
            vector[i] += vector[i-j];
        }
    }
    return vector[n];
}
 
int main(){
    long int n, k;
    printf("N: ");
    scanf("%ld", &n);
    printf("K: ");
    scanf("%ld", &k);
    printf("Number of ways to climb to the %ld th stair: %ld\n", n, climbingStairs(n, k));
    return 0;
}