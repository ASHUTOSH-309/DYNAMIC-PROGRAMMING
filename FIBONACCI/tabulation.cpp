#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int CalculateFibN(int N)
{
    if (N <= 1)
        return N;

    int ans;
    int prev1=1;
    int  prev2=0;
    for (int i = 2; i <= N; i++){
        ans=prev1+prev2;
        prev2=prev1;
        prev1=ans;
    }

    return ans;
}

