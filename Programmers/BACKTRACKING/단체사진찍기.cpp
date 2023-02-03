#include <string>
#include <vector>

using namespace std;

char converting(int n)
{
    if (n == 0)
        return 'A';
    if (n == 1)
        return 'C';
    if (n == 2)
        return 'F';
    if (n == 3)
        return 'J';
    if (n == 4)
        return 'M';
    if (n == 5)
        return 'N';
    if (n == 6)
        return 'R';
    return 'T';
}

int confirm(string c, char friends[8])
{
    int start = 0, end = 0, mid = 0;
    for (int i = 0; i < 8; i++)
    {
        if (friends[i] == c[0])
            start = i;
        if (friends[i] == c[2])
            end = i;
    }
    mid = start - end;
    if (mid < 0)
        mid *= -1;
    return mid - 1;
}

void checking(vector<string> &data, bool pick[8], char friends[8], int &answer)
{
    int check = 0;

    for (auto c : data)
    {
        if (c[3] == '=')
        {
            if (confirm(c, friends) == c[4] - '0')
                check++;
        }
        else if (c[3] == '<')
        {
            if (confirm(c, friends) < c[4] - '0')
                check++;
        }
        else if (c[3] == '>')
        {
            if (confirm(c, friends) > c[4] - '0')
                check++;
        }
    }
    if (check == data.size())
        answer++;
}

void sorting(vector<string> &data, int depth, bool pick[8], char friends[8], int &answer)
{
    if (depth == 8)
    {
        checking(data, pick, friends, answer);
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (!pick[i])
        {
            pick[i] = 1;
            friends[depth] = converting(i);
            sorting(data, depth + 1, pick, friends, answer);
            pick[i] = 0;
            friends[depth] = 0;
        }
    }
}

int solution(int n, vector<string> data)
{
    int answer = 0;
    bool pick[8];
    char friends[8];
    for (int i = 0; i < 8; i++)
    {
        friends[i] = '0';
        pick[i] = 0;
    }
    sorting(data, 0, pick, friends, answer);
    return answer;
}