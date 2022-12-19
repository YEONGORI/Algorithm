// RGB 거리
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int red[1002];
int green[1002];
int blue[1002];

int pr[1002][3];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> red[i] >> green[i] >> blue[i];
    pr[1][0] = red[1];
    pr[1][1] = green[1];
    pr[1][2] = blue[1];

    for (int i=2;i<=n;i++) {
        pr[i][0] = min(pr[i-1][1], pr[i-1][2]) + red[i];
        pr[i][1] = min(pr[i-1][0], pr[i-1][2]) + green[i];
        pr[i][2] = min(pr[i-1][0], pr[i-1][1]) + blue[i];
    }

    cout << *min_element(pr[n], pr[n]+3);
    return (0);
}