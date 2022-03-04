#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

vvl memo;

ll solve(int n, int m) {
	if (1 == n) {
		return m;
	}

	if (memo[n][m] < 0) {
		memo[n][m] = 0;

		const auto& other = n - 1;
		auto left = m - 1;
		while (other <= left) {
			memo[n][m] += solve(other, left);
			left -= 1;
		}
	}

	return memo[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	memo = vvl(30, vl(30, -1));

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << '\n';
	}

	return 0;
}