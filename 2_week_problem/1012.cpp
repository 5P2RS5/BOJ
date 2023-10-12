#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, m, k;
int arr[51][51];
int visited[51][51];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int y, int x)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;
        if(arr[ny][nx] == 0 || visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
    return;
}

int main()
{
    int T;

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> n >> m >> k;
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        int result = 0;
        for(int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            arr[a][b] = 1;
        }
        for(int j = 0; j < n; j++)
        {
            for(int l = 0; l < m; l++)
            {
                if(arr[j][l] == 1 && !visited[j][l])
                {
                    visited[j][l] = true;
                    dfs(j, l);
                    result++;
                }
            }
        }
        cout << result << endl;
    }
}