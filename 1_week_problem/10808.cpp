#include <iostream>
#include <string>
using namespace std;

int arr[26] = {0, };
int main()
{ 
    string temp;
    cin >>  temp;

    for(char i : temp)
    {
        arr[i - 'a']++;
    }
    for(int i = 0; i < 26; i++)
        cout << arr[i] << " ";
}