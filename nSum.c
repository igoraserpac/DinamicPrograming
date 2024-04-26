#include <stdio.h>
#include <stdlib.h>

/*
    Problem: Find the sum of the first N numbers.

    Objective function: f(i) is the sum of the first i natural numbers

    Recurrence relation: f(n) = f(n-1) + n
*/

int nSum(int n){
    int vector[n];
    vector[0] = 0;
    for(int i = 0; i < n+1; i++){
        vector[i] = vector[i-1] + i;
    }
    return vector[n];
}

int main(){
    printf("sum of the first 1000 numbers: %d\n", nSum(1000));
}