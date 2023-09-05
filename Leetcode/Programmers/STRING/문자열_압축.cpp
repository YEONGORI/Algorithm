#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int len = s.size();
    int answer = len;

    for (int i = 1; i <= len / 2; i++)
    {
        int already_comp = 0, comp_len = 0;
        string prev = "";
        for (int j = 0; j < len; j += i)
        {
            string cur = s.substr(j, i);
            if (prev == "")
                comp_len += i;
            else if (cur.compare(prev) == 0)
            {
                if (!already_comp++)
                    comp_len++;
                if ((already_comp + 1) % 10 == 0 && (already_comp + 1) / 10 == 1)
                    comp_len++;
            }
            else
            {
                comp_len += cur.size();
                already_comp = 0;
            }
            prev = cur;
        }
        answer = min(answer, comp_len);
    }
    return answer;
}