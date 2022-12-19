// 시리얼 번호
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> l;

bool cmp_ascii(const string &s1, const string& s2) {
    for (int i=0; s1[i]; i++)
        if (s1[i] != s2[i])
            return s1[i] < s2[i];
    return false;
}

bool cmp_len(const string& s1, const string& s2) {
    return s1.length() < s2.length();
}

bool cmp_sum(const string &s1, const string& s2) {
    int size_1 = 0, size_2 = 0;
    if (s1.length() == s2.length()) {
        for (int i=0;s1[i];i++)
            if (s1[i] >= '0' && s1[i] <= '9')
                size_1 += s1[i] - '0';
        for (int j=0;s2[j];j++)
            if (s2[j] >= '0' && s2[j] <= '9')
                size_2 += s2[j] - '0';
        if (size_1 == size_2)
            return cmp_ascii(s1, s2);
        return (size_1 < size_2);
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string str;
    for (int i=0;i<n;i++) {
        cin >> str;
        l.push_back(str);
    }
    stable_sort(l.begin(), l.end(), cmp_len);
    stable_sort(l.begin(), l.end(), cmp_sum);
    for (string s: l)
        cout << s << '\n';
}