/**
 *  0/1 knapsack memoization
 *
 *   in the knapsack memoization code we should alwas take the values
 *   which are always changing
 *
 *    from the recusive code we can see that n and w are changing
 *
 *
 *  because we want to store till n we take the size as n+1 and w+1
 *
 *
int t[n+1][w+1];

memset(t, -1, sizeof(t));

before calling any recusive function we check in the matrix if the value
is already present( not -1)

    changes in the recusive code
    1. make a global matrix of size greater than the constraints
    2. check if value being called for recusion is already present


    top down and memoized have the same complexity
    drawback is that the recusive stack can get full

 *
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t[102][1024];

memset(t, -1, sizeof(t));

int knapsack(int w[], int v[], int W, int n)
{
    // base condition
    if (n == 0 || W == 0)
        return 0;

    // check if recusive solution is already present
    if (t[n][W] != -1)
        return t[n][W];

    if (w[n - 1] <= W)
    {
        return t[n][W] = max(v[n - 1] + knapsack(w, v, W - w[n - 1], n - 1), knapsack(w, v, W, n - 1));
    }
    else if (w[n - 1] > W)
    {
        return t[n][W] = knapsack(w, v, W, n - 1);
    }
}
