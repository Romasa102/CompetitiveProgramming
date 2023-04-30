#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B;
    cin >> A >> B;
    int dif = A - B;
    int ans = 1;
    for (int i = 0; i < dif; i++)
    {
        ans *= 32;
    }
    cout << ans << endl;
}