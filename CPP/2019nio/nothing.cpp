#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<long long> A(N,0), B(N,0), C(N,0);
    for(int i=0; i<N; i++) {
        int t; long long x;
        cin >> t >> x;
        if(t == 0) A.push_back(x);
        else if(t == 1) B.push_back(x);
        else C.push_back(x);
    }
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    sort(C.begin(), C.end(), greater<long long>());

    vector<long long> X(N+1, 0), Y(N+1, 0);
    X[1] = A[0];
    for(int i=2; i<=N; i++) X[i] = X[i-1] + A[i-1];

    long long val = 0, cnt = C[0];
    int idx1 = 0, idx2 = 1;
    for(int i=2; i<=N; i++) {
        if(cnt == 0) {
            cnt += C[idx2]; idx2++;
        }
        else {
            val += B[idx1]; idx1++;
            cnt--;
        }
        Y[i] = val;
    }

    long long ans = -1;
    for(int i=0; i<=M; i++) {
        // cout << i << ' ' << X[i] << ' ' << Y[N-i] << endl;
        ans = max(ans, X[i]+Y[M-i]);
    }
    cout << ans << endl;
}
