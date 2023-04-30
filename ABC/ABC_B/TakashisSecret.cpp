#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,X;
    cin >> N >> X;
    int A[110000] = {0};
    int CheckNow = X;
    bool B[110000] = {0};
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    while(true)
    {
        if(B[CheckNow]){
            break;
        }else{
            B[CheckNow] = true;
            CheckNow = A[CheckNow];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if(B[i]){
            ans++;
        }
    }
    
    cout << ans << endl;
}