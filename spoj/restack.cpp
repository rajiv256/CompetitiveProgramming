#include <bits/stdc++.h>
 

using namespace std;

 

int main()

{

//ifstream in("restack.in");

//ofstream out("restack.out");

 

int N;

cin >> N;

vector<int> A(N + 1), B(N + 1);

for (int i = 0; i < N; i++)

{

cin >> A[i] >> B[i];

}

A[N] = A[0];

B[N] = B[0];

vector<int> S(N);

S[0] = A[0] - B[0];

for (int i = 1; i < N; i++)

S[i] = A[i] + S[i - 1] - B[i];

nth_element(S.begin(), S.begin() + N / 2, S.end());

int m = S[N / 2];

long long ans = 0;

for (int i = 0; i < N; i++)

ans += abs(S[i] - m);

cout << ans << endl;

return 0;

}
