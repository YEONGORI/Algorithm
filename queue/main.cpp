#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    cout << Q.size() << '\n';
    if (Q.empty())
        cout << "Q is empty\n";
    else
        cout << "Q is not empty\n";

    Q.pop();
    cout << Q.front() << '\n';
    cout << Q.back() << '\n';
    Q.push(40);
    Q.pop();
    cout << Q.front() << '\n';
}

// const int MX = 1000005;
// int dat[MX];
// int head = 0, tail = 0;

// void push(int x)
// {
//     dat[tail++] = x;
// }

// void pop()
// {
//     head++;
// }

// int front()
// {
//     return dat[head];
// }

// int back()
// {
//     return dat[tail - 1];
// }

// void test()
// {
//     push(10);
//     push(20);
//     push(30);
//     cout << front() << '\n'; // 10
//     cout << back() << '\n';  // 30
//     pop();
//     pop();
//     push(15);
//     push(25);
//     cout << front() << '\n'; // 30
//     cout << back() << '\n';  // 25
// }

// int main(void)
// {
//     test();
// }