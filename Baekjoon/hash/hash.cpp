#include <iostream>
#include <hashtable.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

void unordered_set_example()
{
    unordered_set<int> s;
    s.insert(-10);
    s.insert(100);
    s.insert(15);

    cout << s.erase(100) << '\n';
    cout << s.erase(20) << '\n';

    if (s.find(15) != s.end())
        cout << "15 in s\n";
    else
        cout << "15 not in s\n";

    cout << s.size() << '\n';
    cout << s.count(50) << '\n';
    for (auto e : s)
        cout << e << ' ';
    cout << '\n';
}

void unordered_multiset_example()
{
    unordered_multiset<int> ms;
    ms.insert(-10);
    ms.insert(100);
    ms.insert(15);
    cout << ms.size() << '\n';
    for (auto e : ms)
        cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n';

    ms.erase(ms.find(-10));
    ms.insert(100);
    cout << ms.count(100) << '\n';
}

void unordered_map_example()
{
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165;

    cout << m.size() << '\n';
    m["hi"] = -7;
    if (m.find("hi") != m.end())
        cout << "hi in m\n";
    else
        cout << "hi not in m\n";
    m.erase("bkd");
    for (auto e : m)
        cout << e.first << ' ' << e.second << '\n';
}