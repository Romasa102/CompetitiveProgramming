#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N,Q;
    cin >> N >> Q;
    long long A[200100];
    for (long long i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A,A + N,greater<long long>());
    for (long long i = 0; i < Q; i++)
    {
        long long x;
        cin >> x;
        for (long long j = 0; j < N; j++)
        {
            if(x > A[j]){
                cout << j << endl;
                break;
            }else if(j == N - 1){
              cout << j + 1 << endl;
            }
        }
    }
    
}