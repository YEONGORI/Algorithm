// 수 고르기
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, st, en;
long long minmin = 0x7fffffff;
int arr[100002];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0;i<n;i++)
		cin >> arr[i];
	sort(arr, arr+n);
	for (int st=0; st<n;st++) {
		while (en < n && arr[en]-arr[st] < m)
			en++;
		if (en == n) break;
		if (arr[en]-arr[st] < minmin)
			minmin = arr[en]-arr[st];
	}

	cout << minmin << '\n';
	return (0);
}

