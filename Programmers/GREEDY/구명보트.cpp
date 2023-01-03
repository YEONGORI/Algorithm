#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0, NthPeople = 0;
    sort(people.begin(), people.end());

    while (people.size() > NthPeople)
    {
        int back = people.back();
        people.pop_back();
        if (people[NthPeople] + back <= limit)
        {
            answer++;
            NthPeople++;
        }
        else
            answer++;
    }

    return answer;
}