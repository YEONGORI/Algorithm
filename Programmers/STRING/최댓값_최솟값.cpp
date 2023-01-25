#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "", buf;
    istringstream str(s);
    vector<int> splited;

    int MIN = 2147483647, MAX = -2147483648;
    while (getline(str, buf, ' ')) {
        int n = stoi(buf);
        splited.push_back(n);
        if (MAX < n)
            MAX = n;
        if (MIN > n)
            MIN = n;
    }

    answer += to_string(MIN);
    answer += " ";
    answer += to_string(MAX);
    return answer;
}

// #include <string>
// #include <vector>
// #include <sstream>

// using namespace std;

// string solution(string s)
// {
//     string answer = "";
//     int num = 0, min = 2147483647, max = -2147483648, isM = 1;
//     stringstream smax, smin;
//     string strmax, strmin;
//     vector<int> V;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == ' ')
//         {
//             V.push_back(num * isM);
//             num = 0;
//             isM = 1;
//         }
//         else if (s[i] == '-')
//             isM = -1;
//         else
//             num = num * 10 + (s[i] - '0');
//     }
//     V.push_back(num * isM);
//     for (auto i : V)
//     {
//         if (i > max)
//             max = i;
//         if (i < min)
//             min = i;
//     }

//     smax << max;
//     smax >> strmax;
//     smin << min;
//     smin >> strmin;
//     answer += strmin;
//     answer += " ";
//     answer += strmax;
//     return answer;
// }
