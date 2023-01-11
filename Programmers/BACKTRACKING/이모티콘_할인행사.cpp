#include <string>
#include <vector>

using namespace std;

int price, subscriber;
vector<int> discounted;

void calculate(vector<vector<int>> users, vector<int> emoticons)
{
    if (discounted.size() == emoticons.size())
    {
        int tmp_price = 0;
        int tmp_subscriber = 0;

        for (auto u : users)
        {
            int p = 0;
            for (int i = 0; i < emoticons.size(); i++)
            {
                if (u[0] <= discounted[i])
                    p = p + emoticons[i] * (100 - discounted[i]) / 100;
            }
            if (u[1] <= p)
                tmp_subscriber++;
            else
                tmp_price += p;
        }

        if (subscriber < tmp_subscriber)
        {
            subscriber = tmp_subscriber;
            price = tmp_price;
        }
        else if (subscriber == tmp_subscriber && price < tmp_price)
            price = tmp_price;
        return;
    }

    for (int i = 10; i <= 40; i += 10)
    {
        discounted.push_back(i);
        calculate(users, emoticons);
        discounted.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    calculate(users, emoticons);
    answer.push_back(subscriber);
    answer.push_back(price);

    return answer;
}