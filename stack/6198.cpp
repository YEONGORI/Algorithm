// 옥상 정원 꾸미기
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    long long total = 0;
    stack<int> S;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        while (!S.empty() && h >= S.top())
            S.pop();
        S.push(h);
        total += S.size() - 1;
    }
    cout << total;
    return 0;
}
// 결국 슈도코드 참고하였음
// 스택의 크기가 보이는 건물의 갯수라는 생각을 떠올리지 못함