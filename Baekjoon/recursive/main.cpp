#include <bits/stdc++.h>

using namespace std;

int plusN(int n)
{
    if (n == 0)
        return 0;
    return (n + plusN(n - 1));
}

void ntoOne(int n)
{
    if (n == 0)
        return;
    cout << n;
    return ntoOne(n - 1);
}

int main(void)
{
    cout << plusN(10);
    cout << "\n\n";
    ntoOne(9);
}