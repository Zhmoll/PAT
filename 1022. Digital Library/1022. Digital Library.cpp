#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
map<string, set<int>> titlemap;
map<string, set<int>> authormap;
map<string, set<int>> keywordsmap;
map<string, set<int>> publishermap;
map<string, set<int>> yearmap;

int main() {
	int N;
	cin >> N;
	int id;
	string title, author, keyword, publisher, year;
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &id);
		getline(cin, title);
		titlemap[title].insert(id);
		getline(cin, author);
		authormap[author].insert(id);
		while (cin >> keyword) {
			keywordsmap[keyword].insert(id);
			if (getchar() == '\n') break;
		}
		getline(cin, publisher);
		publishermap[publisher].insert(id);
		getline(cin, year);
		yearmap[year].insert(id);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int q;
		string str;
		scanf("%d: ", &q);
		getline(cin, str);
		cout << q << ": " << str << endl;
		
		set<int>::iterator it, itend;
		switch (q) {
		case 1: {
			it = titlemap[str].begin();
			itend = titlemap[str].end();
			break;
		}
		case 2: {
			it = authormap[str].begin();
			itend = authormap[str].end();
			break;
		}
		case 3: {
			it = keywordsmap[str].begin();
			itend = keywordsmap[str].end();
			break;
		}
		case 4: {
			it = publishermap[str].begin();
			itend = publishermap[str].end();
			break;
		}
		case 5: {
			it = yearmap[str].begin();
			itend = yearmap[str].end();
			break;
		}
		}

		if (it == itend) {
			cout << "Not Found" << endl;
		}
		for (; it != itend; it++) {
			printf("%07d\n", *it);
		}
	}
	return 0;
}