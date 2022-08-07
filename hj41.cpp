#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, a[10], t;

	while (cin >> n) {
		vector<int> f;

		for (int i = 0; i < n; i++) cin >> a[i];

		for (int i = 0; i < n; i++) {
			cin >> t;
			for (int j = 0; j < t; j++)
				f.push_back(a[i]);
		}

		set<int> s;
		s.insert(0);

		for (int i = 0; i < f.size(); i++) {
			set<int> ss(s);
			for (auto it = ss.begin(); it != ss.end(); it++) {
				s.insert(*it + f[i]);
			}
		}

		cout << s.size();
	}
	return 0;
}