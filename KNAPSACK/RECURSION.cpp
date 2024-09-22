#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int KnapSackRecursion(vector<int> &weights, vector<int> &values, int totalItems, int KnapSackCapacity)
{
    if (totalItems == 0 || KnapSackCapacity == 0) return 0;

    if (weights[totalItems - 1] > KnapSackCapacity){
        return KnapSackRecursion(weights, values, totalItems - 1, KnapSackCapacity);
    }
    return max(values[totalItems - 1] + KnapSackRecursion(weights, values, totalItems - 1, KnapSackCapacity - weights[totalItems - 1]),
               KnapSackRecursion(weights, values, totalItems - 1, KnapSackCapacity));
}

int main()
{
    vector<int> weights = {2, 4, 5, 9};
    vector<int> values = {3, 4, 5, 6};

    int totalItems = weights.size();
    int KnapSackCapacity = 9;

    cout << KnapSackRecursion(weights, values, totalItems, KnapSackCapacity);
    return 0;
}