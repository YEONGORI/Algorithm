#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> ST;

    for (auto c : s)
    {
        if (c == '(')
            ST.push(c);
        else if (c == ')')
        {
            if (ST.empty())
                return false;
            ST.pop();
        }
    }
    if (ST.empty())
        return true;
    return false;
}