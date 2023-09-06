#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int box = 0;     // 배송할 택배의 갯수
    stack<int> D, P; // 집 별로 배송 혹은 회수할 택배의 갯수

    for (auto i : deliveries)
        D.push(i);
    for (auto i : pickups)
        P.push(i);

    while (!D.empty() && D.top() == 0) // 집만 있고 배달할 택배는 없는 집 제거
        D.pop();
    while (!P.empty() && P.top() == 0) // 집만 있고 회수할 택배는 없는 집 제거
        P.pop();

    while (!(D.empty() && P.empty()))
    {
        answer += max(D.size() * 2, P.size() * 2); // 가장 멀리 있는 집을 먼저 방문

        box = 0;
        while (!D.empty() && box <= cap)
        {
            if (D.top() + box <= cap) // D.top() 집에 배송할 택배를 전부 실을 수 있을 때
                box += D.top();
            else
            {
                D.top() -= (cap - box); // 일부만 실을 때
                break;
            }
            D.pop();
        }

        box = 0;
        while (!P.empty() && box <= cap)
        {
            if (P.top() + box <= cap) // P.top() 집에서 회수할 택배를 전부 실을 수 있을 때
                box += P.top();
            else
            {
                P.top() -= (cap - box); // 일부만 실을 때
                break;
            }
            P.pop();
        }
    }
    return answer;
}