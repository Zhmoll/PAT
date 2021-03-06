#include <cstdio>
#include <cstring>
#define INF 1000000000
int main() {
	int M;
	scanf("%d", &M);
	char ID_number[20];
	int Sign_in_time, Sign_out_time;
	int hh1, mm1, ss1, hh2, mm2, ss2;
	int first_signin = INF, last_signout = 0;
	char first_signin_id[20], last_signout_id[20];
	for (int i = 0; i < M; i++) {
		scanf("%s %d:%d:%d %d:%d:%d", &ID_number, &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
		Sign_in_time = hh1 * 3600 + mm1 * 60 + ss1;
		Sign_out_time = hh2 * 3600 + mm2 * 60 + ss2;
		if (Sign_in_time < first_signin) {
			first_signin = Sign_in_time;
			strcpy(first_signin_id, ID_number);
		}
		if (Sign_out_time > last_signout) {
			last_signout = Sign_out_time;
			strcpy(last_signout_id, ID_number);
		}
	}
	printf("%s %s", first_signin_id, last_signout_id);
	return 0;
}