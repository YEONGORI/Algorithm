// 최대 힙
#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt, tmp;
int max_heap[100002];

void push(int x)
{
    max_heap[++cnt] = x;
    int p = cnt;
    while (p != 1)
    {
        int pp = p / 2;
        if (max_heap[pp] > max_heap[p])
            break;
        swap(max_heap[p], max_heap[pp]);
        p = pp;
    }
}

void top_pop(void)
{
    if (cnt)
    {
        cout << max_heap[1] << '\n';
        max_heap[1] = max_heap[cnt--];
        int p = 1;
        while (2 * p <= cnt)
        {
            int left_c = p * 2, right_c = p * 2 + 1, max_c = left_c;
            if (max_heap[left_c] < max_heap[right_c])
                max_c = right_c;
            if (max_heap[p] > max_heap[max_c])
                break;
            swap(max_heap[p], max_heap[max_c]);
            p = max_c;
        }
    }
    else
        cout << 0 << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> tmp;
        if (tmp)
            push(tmp);
        else
            top_pop();
    }
}