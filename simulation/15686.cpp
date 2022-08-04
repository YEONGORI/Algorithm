// 치킨 배달
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Pos {
  int x, y;
};
int N, M;
int MIN = 2147483640;
bool selected[13];
vector<Pos> house;
vector<Pos> chicken;
vector<Pos> picked;

void get_distance(void) {
  int res = 0;
  for (int i = 0; i < (int)house.size(); i++) {
    int tmp = 2147483640;
    for (int j = 0; j < (int)picked.size(); j++)
      tmp = min(
          tmp, (abs(house[i].x - picked[j].x) + abs(house[i].y - picked[j].y)));
    res += tmp;
  }
  MIN = min(MIN, res);
}

void pick_chicken(int x, int k) {
  if (k == M)
    get_distance();
  for (int i = x; i < (int)chicken.size(); i++) {
    if (selected[i])
      continue;
    selected[i] = 1;
    picked.push_back({chicken[i].x, chicken[i].y});
    pick_chicken(i, k + 1);
    selected[i] = 0;
    picked.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tmp;
      if (tmp == 1)
        house.push_back({i, j});
      if (tmp == 2)
        chicken.push_back({i, j});
    }
  }
  pick_chicken(0, 0);
  cout << MIN;
  return (0);
}
