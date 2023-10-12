#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
int visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m, t;
int cnt = 0;

void dfs(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= m || nx < 0 || ny >= n || ny < 0)
            continue;
        if(arr[ny][nx] == 1 || visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        cnt++;
        dfs(ny, nx);
    }
    return;
}

int main()
{

    cin >> n >> m >> t;
    for(int i = 0; i < t; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++)
        {
            for(int k = x1; k < x2; k++)
            {
                arr[j][k] = 1;
            }
        }
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == 0) {
                cnt = 1;
                visited[i][j] = true;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i : v)
        cout << i << " ";
}