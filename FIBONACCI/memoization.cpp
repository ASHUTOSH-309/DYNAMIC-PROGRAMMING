#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int fibMemo(int n, vector<int> &dp)
{
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];
    
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

int main()
{
    int n = 10;
    vector<int> dp(n + 1, -1); // Initialize a DP table with -1
    cout << "Fibonacci number is: " << fibMemo(n, dp);
}
