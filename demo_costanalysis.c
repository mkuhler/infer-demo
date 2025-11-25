#include <stdio.h>

/* 
* HOW TO RUN TESTS:
* infer --cost-only -- gcc -c demo_costanalysis.c
* python3 read_reports.py
*/

/* 
* COMPLEXITY: O(n)
* Single loop over n elements, linear time complexity.
*/
void sum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    printf("Sum: %d\n", sum);
}

/* 
* COMPLEXITY: O(n * m)
* Nested loop over n (outer loop) * m (inner loop)
* elements. Quadratic time complexity.
*/
void multiply_sum(int n, int m) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            total += i * j;
        }
    }
    printf("Total: %d\n", total);
}

/* 
* COMPLEXITY: O(1)
* Infer reports this complexity of this recursive 
* function as constant, either because its a very 
* small function call or it is bounded recursion on 
* the input used in analysis (5)
*/
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

/* 
* COMPLEXITY: O(1)
* No loops - constant cost
*/
int main() {
    sum(10);
    multiply_sum(5, 5);
    printf("Factorial: %d\n", factorial(5));
    return 0;
}
