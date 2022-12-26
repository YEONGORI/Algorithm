#include <string>
#include <vector>

using namespace std;

int arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    arr[1][1] = 1;
    for (auto p: puddles)
        arr[p[0]][p[1]] = -1;

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (arr[i][j] == -1 || (i==1 && j==1))
                continue;
            int a=arr[i-1][j], b=arr[i][j-1];
            if (a == -1)
                a = 0;
            if (b == -1)
                b = 0;
            arr[i][j] = (a + b) % 1000000007;
        }
    }
    
    return arr[m][n] % 1000000007;
}