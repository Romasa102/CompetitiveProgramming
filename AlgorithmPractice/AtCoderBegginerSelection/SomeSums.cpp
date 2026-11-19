#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int N,A,B;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i++){
        int M = i;
        int sum = 0;
        sum = 0;
        while(M > 0){
            sum += M % 10;
            M /= 10;            
        }
        if(A <= sum && sum <= B){
            ans += i;
        }
    }
    cout << ans << endl;
}