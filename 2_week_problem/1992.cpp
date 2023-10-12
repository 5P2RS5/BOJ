#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

string quad(int y, int x, int size)
{
    if(size <= 1)
        return string(1, v[y][x]);
    
    char init = v[y][x];
    bool isSame = true;
    for(int i = y; i < y + size; i++)
    {
        for(int j = x; j < x + size; j++)
        {
            if(v[i][j] != init)
            {
                string temp = "(";
                temp += quad(y, x, size / 2);
                temp += quad(y, x + size / 2, size / 2);
                temp += quad(y + size / 2, x, size / 2);
                temp += quad(y + size / 2, x + size / 2, size / 2);
                temp += ")";
                return temp;
            }
        }
    }
    return string(1, v[y][x]);
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    string answer;
    answer = quad(0, 0, n);
    cout << answer;
}