#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	char c1, c2;
	int c3;
	int count = 0;
	int len1 = s1.length() < s2.length() ? s1.length() : s2.length();
	int len2 = s3.length() < s4.length() ? s3.length() : s4.length();
	for (int i = 0; i < len1; i++) {
		if (count == 0) {
			if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
				c1 = s1[i];
				count++;
			}
		}
		else {
			if (s1[i] == s2[i] && ((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0'&&s1[i] <= '9'))) {
				c2 = s1[i];
				break;
			}
		}
	}

	for (int i = 0; i < len2; i++) {
		if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
			c3 = i;
			break;
		}
	}

	string day;
	switch (c1) {
	case 'A':day = "MON"; break;
	case 'B':day = "TUE"; break;
	case 'C':day = "WED"; break;
	case 'D':day = "THU"; break;
	case 'E':day = "FRI"; break;
	case 'F':day = "SAT"; break;
	case 'G':day = "SUN"; break;
	}
	int hh, mm;
	if (c2 >= '0'&&c2 <= '9') {
		hh = c2 - '0';
	}
	else if (c2 >= 'A'&&c2 <= 'N') {
		hh = c2 - 'A' + 10;
	}
	mm = c3;

	printf("%s %02d:%02d", day.c_str(), hh, mm);
	return 0;
}