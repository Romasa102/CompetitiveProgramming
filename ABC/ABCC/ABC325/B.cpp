#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int W[N],X[N];
    for(int i = 0; i<N; i++){
        cin >> W[i] >> X[i];
    }
    int ans = 0;
    for(int i = 0; i<24; i++){
        int cur= 0; //number of people that could join if the meeting start from i o'clock;
        for(int j = 0;j < N; j++){
            if((i+X[j])%24 <= 17 && (i+X[j])%24>=9){//if the time is between 9 and 17
                cur+=W[j];//add up the number of people
            }
        }
        ans = max(ans,cur);//現在の答えより新しいのの方が大きかったら更新
    }
    cout << ans << endl;
}