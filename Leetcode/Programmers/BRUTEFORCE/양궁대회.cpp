#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int rScore;
int aScore;
int maxGap;

vector<int> answer(1, -1);

bool minimum(vector<int> &rInfo)
{
    for (int i = 10; i >= 0; i--)
    {
        if (rInfo[i] > answer[i])
            return true;
        else if (rInfo[i] < answer[i])
            return false;
    }
}

void calculate(vector<int> &rInfo, vector<int> &aInfo)
{
    rScore = 0;
    aScore = 0;
    for (int i = 0; i < 11; i++)
    {
        if (rInfo[i] > aInfo[i])
            rScore += 10 - i;
        else if (aInfo[i] > 0)
            aScore += 10 - i;
    }
    int gap = rScore - aScore;
    if (gap > 0 && gap >= maxGap)
    {
        if (maxGap == gap && !minimum(rInfo))
            return;
        maxGap = gap;
        answer = rInfo;
    }
}

void dfs(int depth, int arrow, vector<int> &rInfo, vector<int> &aInfo)
{
    if (depth == 11 || arrow == 0)
    {
        rInfo[10] += arrow;
        calculate(rInfo, aInfo);
        rInfo[10] -= arrow;
        return;
    }
    if (aInfo[depth] < arrow)
    {
        rInfo[depth] += aInfo[depth] + 1;
        dfs(depth + 1, arrow - aInfo[depth] - 1, rInfo, aInfo);
        rInfo[depth] -= aInfo[depth] + 1;
    }
    dfs(depth + 1, arrow, rInfo, aInfo);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> rInfo(11, 0);

    dfs(0, n, rInfo, info);
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}