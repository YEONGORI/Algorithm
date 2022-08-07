#include <iostream>
#include <vector>

using namespace std;

int n = 10;
int arr[1000001] = {012, 421, 046, 674, 103, 502, 007, 100, 021, 545};
int d = 3;
int p10[3];

int digitNum(int x, int a) {
    return (x / p10[a]) % 10;
}

vector<int> l[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p10[0] = 1;
    for (int i =1; i < d; i++) p10[i] = p10[i - 1] * 10;
    for (int i =0; i<d;i++) {
        for (int j = 0; j < 10; j++) l[j].clear();
        for (int j = 0; j < n; j++)
            l[digitNum(arr[j], i)].push_back(arr[j]);
        int aidx = 0;
        for (int j=0;j<10;j++) {
            for (auto x: l[j]) arr[aidx++] = x;
        }
    }
    for (int i=0; i<n;i++) cout << arr[i] << ' ';
}