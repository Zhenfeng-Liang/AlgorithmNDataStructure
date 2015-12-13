/*
Given the nth and (n+1)th terms, the (n+2)th can be computed by the following relation 
   Tn+2 = (Tn+1)2 + Tn
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int A, B, N;
    
    cin >> A;
    cin >> B;
    cin >> N;
    
    vector<unsigned long long> cache;
    cache.push_back(A);
    cache.push_back(B);
    
    N = N - 2;
    //cout << A << "," << B << endl;
    unsigned long long res;
    
    for(int i = 0; i < N; i++)
    {
        cout << cache[(i % 2)] << "," << cache[((i + 1) % 2)] << endl;
        res = cache[i % 2] + cache[(i + 1) % 2] * cache[(i + 1) % 2];
        cache[i % 2] = res;
        cout << res << endl;
    }
    
    cout << res << endl;
    
    return 0;
}
