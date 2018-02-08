#include <map>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Poly {
	int K = 0;
	map<int, double> term;
}poly[3];

int main() {
	int tmp_key;
	double tmp_value;
	for (int i = 0; i < 2; i++) {
		cin >> poly[i].K;
		for (int j = 0; j < poly[i].K; j++) {
			cin >> tmp_key >> tmp_value;
			poly[i].term.insert(std::pair<int, double>(tmp_key, tmp_value));
		}
	}

	for (map<int, double>::iterator it1 = poly[0].term.begin(); it1 != poly[0].term.end(); it1++) {
		for (map<int, double>::iterator it2 = poly[1].term.begin(); it2 != poly[1].term.end(); it2++) {
			int zhishu = it1->first + it2->first;
			double xishu = it1->second * it2->second;

			if (fabs(xishu) < 1e-5) continue;

			map<int, double>::iterator it = poly[2].term.find(zhishu);
			if (it != poly[2].term.end()) {
				// 存在了
				it->second += xishu;
				if (fabs(it->second) < 1e-5) {
					poly[2].term.erase(zhishu);
					poly[2].K--;
				}					
			}
			else {
				// 不存在
				poly[2].K++;
				poly[2].term.insert(std::pair<int, double>(zhishu, xishu));
			}
		}
	}

	cout << poly[2].K;

	if (poly[2].K) cout << " " << setiosflags(ios::fixed);

	map<int, double>::const_reverse_iterator it = poly[2].term.rbegin();
	for (int i = 0; i < poly[2].K; i++, it++) {
		cout << it->first << " " << setprecision(1) << it->second << setprecision(0);
		if (i != poly[2].K - 1) cout << " ";
	}

	return 0;
}