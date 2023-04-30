#include <bits/stdc++.h>
using namespace std;
int main(){
    int A[110];
    int N;
    int Bucket[110] = {0};
    int ans = 0;
    cin >> N;
    for(int i = 0;i < N; i++){
        cin >> A[i];
    }
    for(int i = 0;i < N; i++){
        Bucket[A[i]]++;
    }
    for(int i = 1; i < 110; i++){
        if(Bucket[i] > 0){
            ++ans;
        }
    }
    cout << ans << endl;
}