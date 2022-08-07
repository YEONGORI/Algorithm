// 수 정렬하기(5)
#include <iostream>

using namespace std;

int num[2000002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        num[1000000 + tmp]++;
    }
    for (int i = 0; i < 2000002; i++)
    {
        if (num[i])
        {
            for (int j = 0; j < num[i]; j++)
                cout << i - 1000000 << '\n';
        }
    }
}