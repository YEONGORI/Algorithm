#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i=0; i<5; i++){
        int check = 1;
        for (int j=0; j<5; j++) {
            for (int k=0; k<5;k++) {
                if (places[i][j][k] == 'P') {
                    for (int di=0; di<4; di++){
                        int nx = j + dx[di];
                        int ny = k + dy[di];
                        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || places[i][nx][ny] == 'X')
                            continue;
                        if (places[i][nx][ny] == 'P') {
                            check = 0;
                            break;
                        }
                        if (places[i][nx][ny] == 'O') {
                            for (int fi=0; fi<4; fi++) {
                                int mx = nx + dx[fi];
                                int my = ny + dy[fi];
                                if (mx < 0 || mx >= 5 || my < 0 || my >= 5 || places[i][mx][my] == 'X')
                                    continue;
                                if (mx == j && my == k)
                                    continue;
                                if (places[i][mx][my] == 'P') {
                                    check = 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        answer.push_back(check);
    }
    return answer;
}