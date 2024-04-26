#include <stdio.h>

/*
    Problem: Find the sum of the first N numbers.

    Objective function: f(i) is the sum of the first i natural numbers

    Recurrence relation: f(n) = f(n-1) + n
*/

long int nSum(long int n){
    long int vector[n+1];
    vector[0] = 0;
    for(long int i = 1; i < n+1; i++){
        vector[i] = vector[i-1] + i;
    }
    return vector[n];
}

int main(){
    long int n;
    printf("N: ");
    scanf("%ld", &n);
    printf("Sum of the first %ld numbers: %ld\n", n, nSum(n));
}