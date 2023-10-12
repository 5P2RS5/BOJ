#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 9; i++)    
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    do{
        int sum = 0;
        for(int i = 0; i < 7; i++)
        {
            sum += v[i];
        }
        if(sum == 100)
        {
            for(int i = 0; i < 7; i++)
                cout << v[i] << endl;
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));
}