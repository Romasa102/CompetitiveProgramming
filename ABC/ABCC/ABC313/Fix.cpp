#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> deta(2, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> deta.at(j).at(i);
        }
    }
    int saikyou = 0;
    bool flag[n];
    for(int i = 0; i < n; i++){
        flag[i] = true;
    }
    for (int i = 0; i < m; i++)
    {
        flag[deta[0][i]-1] = false;
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if(flag[i])counter++;
    }
    if(counter >= 2){
        cout << -1 << endl;
    }else{
        for (int i = 0; i < n; i++)
        {
            if(flag[i])cout << i+1 << endl;
        }
        
    }
}