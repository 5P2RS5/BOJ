#include <iostream>
using namespace std;

int arr[21];

int main()
{
    int n, m, k;
    
    int l, r;
    int mid;
    
    cin >> n >> m >> k;
    l = 1;
    mid = m;
    r = l + m - 1;

    int result = 0;
    for(int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        while(temp > r || temp < l)
        {
            if(temp < l)
            {
                l -= 1;
                r -= 1;
            }
            else
            {
                l += 1;
                r += 1;
            }
            result++;
        }
    }
    cout << result << endl;
}