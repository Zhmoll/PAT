#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	int M;// being the total number of forwards
	int N;// the skip number of winners
	int S;// the index of the first winner (the indices start from 1)

	scanf("%d%d%d", &M, &N, &S);

	vector<string> forward;
	forward.push_back("");
	for (int i = 1; i <= M; i++) {
		string current;
		cin >> current;
		forward.push_back(current);
	}

	set<string> winner;
	for (int i = S; i <= M; i += N) {
		while (winner.find(forward[i]) != winner.end()) {
			i++;
			if (i > M) goto out;
		}
		if (winner.size() == 0)
			cout << forward[i];
		else
			cout << endl << forward[i];
		winner.insert(forward[i]);
	}
out:
	if (winner.size() == 0) {
		cout << "Keep going...";
	}
	return 0;
}