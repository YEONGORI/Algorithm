// 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int n, m;
string tmp;
unordered_map<string, int>s;
vector<string> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> tmp;
		s[tmp] = i;
		v.push_back(tmp);
	}
	for (int i=0;i<m;i++) {
		cin >> tmp;
		if (isdigit(tmp[0]))
			cout << v[stoi(tmp) - 1] << '\n';
		else
			cout << s[tmp] << '\n';
	}
}