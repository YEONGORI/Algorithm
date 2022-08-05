// 요세푸스 문제 (0)
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int n, k;
    cin >> n >> k;
    cout << '<';
    for (int i = 1; i <= n; i++)
        Q.push(i);
    while (Q.size() != 1) {
        int tmp = 0;
        for (int i = 0; i < k -1; i++) {
            // cout << "Q front: " << Q.front() << '\n';
            tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        cout << Q.front() << ", ";
        Q.pop();
    }
    cout << Q.front() << '>';
}