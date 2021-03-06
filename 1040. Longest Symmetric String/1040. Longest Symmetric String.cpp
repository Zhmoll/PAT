#include <iostream>
#include <string>
using namespace std;
bool dp[1001][1001];
int main() {
	string S;
	getline(cin, S);
	fill(dp[0], dp[0] + 1001 * 1001, false);
	int ans = 1;
	for (int i = 0; i < S.length(); i++) {
		dp[i][i] = true;
		if (i < S.length() - 1) {
			if (S[i] == S[i + 1]) {
				dp[i][i + 1] = true;
				ans = 2;
			}
		}
	}
	for (int L = 3; L <= S.length(); L++) {
		for (int i = 0; i + L - 1 < S.length(); i++) {
			int j = i + L - 1;
			if (S[i] == S[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
				ans = L;
			}
		}
	}
	cout << ans;
	return 0;
}