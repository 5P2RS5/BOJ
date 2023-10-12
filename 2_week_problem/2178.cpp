#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> v;
string temp;
int n, m;
bool visited[101][101];
int cost[101][101] = {0, };
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    cost[a][b] = 1;
    visited[a][b] = true;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny >= n || nx >= m || nx < 0 || ny < 0)
                continue;
            if(visited[ny][nx] == true || v[ny][nx] == '0')
                continue;
            
            q.push({ny, nx});
            cost[ny][nx] = cost[y][x] + 1;
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }    
    bfs(0, 0);
    cout << cost[n-1][m-1]; 
}