// 세 수의 합
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int U[1002];
vector<int> two;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> U[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            two.push_back(U[i] + U[j]);
    sort(two.begin(), two.end());
    sort(U, U + n);
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (binary_search(two.begin(), two.end(), U[i] - U[j]))
            {
                cout << U[i];
                return (0);
            }
        }
    }
    return (0);
}