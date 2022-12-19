// 좌표 압축
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr, sor;

int b_search(int tar)
{
    int st = 0, en = sor.size();
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (sor[mid] >= tar)
            en = mid;
        else
            st = mid + 1;
    }
    return (st);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        arr.push_back(x[i]);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        if (i == 0 || arr[i - 1] != arr[i])
            sor.push_back(arr[i]);

    for (int i = 0; i < n; i++)
        cout << b_search(x[i]) << ' ';

    return (0);
}

/*

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for(int i = 0; i < n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}

*/
