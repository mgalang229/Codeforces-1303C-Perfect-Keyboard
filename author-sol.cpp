#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	string s;
	cin >> s;
	bool used[26];
	memset(used, false, sizeof(used));
	used[s[0]-'a'] = true;
	string t(1, s[0]);
	int pos = 0;
	for (int i = 1; i < (int) s.size(); i++) {
		if (used[s[i]-'a']) {
			if (pos > 0 && t[pos-1] == s[i]) {
				pos--;
			} else if (pos + 1 < (int) t.size() && t[pos+1] == s[i]) {
				pos++;
			} else {
				cout << "NO\n";
				return;
			}
		} else {
			if (pos == 0) {
				t = s[i] + t;
			} else if (pos == (int) t.size() - 1) {
				t += s[i];
				pos++;
			} else {
				cout << "NO\n";
				return;
			}
		}
		used[s[i]-'a'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (!used[i]) {
			t += char(i + 'a');
		}
	}
	cout << "YES\n" << t << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
