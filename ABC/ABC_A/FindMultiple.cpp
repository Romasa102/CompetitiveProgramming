#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int X = A/C;
    int ans = 0;
    if(A%C != 0){
        ans = (X+1)*C;
    }else{
        ans = X*C;
    }
    if(ans >= A && ans <= B){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}