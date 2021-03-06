#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
struct person {
	int arrive;
	int hh, mm, ss;
	int process;
};
bool cmp(person &a, person &b) {
	return a.arrive < b.arrive;
}
vector<person> vi;
vector<int> window;
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	vi.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &vi[i].hh, &vi[i].mm, &vi[i].ss, &vi[i].process);
		if (vi[i].process > 60) vi[i].process = 60;
		vi[i].arrive = vi[i].hh * 3600 + vi[i].mm * 60 + vi[i].ss;
	}
	sort(vi.begin(), vi.end(), cmp);

	window.resize(K, 8 * 3600);
	int wait = 0;
	int count = 0;
	for (int i = 0; i < vi.size(); i++) {
		if (vi[i].arrive > 17 * 3600) break;
		count++;
		int minfinish = window[0];
		int posi = 0;
		for (int j = 1; j < K; j++) {
			if (window[j] < minfinish) {
				minfinish = window[j];
				posi = j;
			}
		}
		if (minfinish <= vi[i].arrive) {
			window[posi] = vi[i].arrive + vi[i].process * 60;
		}
		else {
			wait += minfinish - vi[i].arrive;
			window[posi] += vi[i].process * 60;
		}
	}
	printf("%.1lf", (double)wait / 60 / count);
	return 0;
}