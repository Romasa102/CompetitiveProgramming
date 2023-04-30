#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int S[30];
    bool D[30] = {false};
    for(int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    int size;
    for (int a = 1; a < 300; a++)
    {
        for (int b = 1; b < 300; b++)
        {
            size = (4 * a * b) + (3 * a) + (3 * b);
            for (int i = 0; i < N; i++)
            {
                if(S[i] == size){
                    D[i] = true;
                }
            }
        }        
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if(D[i]){
            count++;
        }
    }
    cout << N - count << endl;
}