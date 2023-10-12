#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[101][101];
int visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, big;

void dfs(int y, int x, int a)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= n || nx < 0 || ny >= n || ny < 0)
            continue;
        if(arr[ny][nx] <= a || visited[ny][nx])
            continue;
        visited[ny][nx] = true;
        dfs(ny, nx, a);
    }
    return;
}

int main()
{

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > big)
                big = arr[i][j];
        }
    }
    int result = 0;
    int cnt = 0;
    for(int a = 0; a < big; a++)
    {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j] && arr[i][j] > a)
                {
                    visited[i][j] = true;
                    dfs(i, j, a);
                    cnt++;
                }
            }
        }
        if(result < cnt)
            result = cnt;
    }
    cout << result;

}