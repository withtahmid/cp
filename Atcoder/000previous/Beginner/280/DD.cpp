// C++ implementation of the above approach
 
#include "bits/stdc++.h"
using namespace std;
 
// Array that stores the factorial
// till 20
long long fact[21];
 
// Function to pre-compute
// the factorial till 20
void preCompute()
{
 
    // Precomputing factorials
    fact[0] = 1;
 
    for (int i = 1; i < 18; i++)
        fact[i] = (fact[i - 1] * i);
}
 
// Function to return the next
// factorial number greater than N
void nextFactorial(int N)
{
    // Traverse the factorial array
    for (int i = 0; i < 21; i++) {
 
// Find the next just greater
// factorial than N
        if (N < fact[i]) {
 
            cout << fact[i];
            break;
        }
    }
}
 
// Driver Code
int main()
{
    // Function to precalculate
    // the factorial till 20
    preCompute();
 
    int N = 120;
 
    // Function call
    nextFactorial(N);
 
    return 0;
}