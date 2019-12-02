#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <unordered_set>

typedef unsigned int uint128_t __attribute__((mode(TI)));

uint128_t gcd (uint128_t a, uint128_t b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

uint32_t bitcnt(uint128_t x) {
	uint32_t res = 0;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}


int main()
{
	int T;
	std::cin >> T;
	for (int test = 0; test < T; ++test) {
		fprintf(stderr, "Case #%d:\n", test + 1);
		int M, N;
		int best = 0;
		int best_cnt = 0;
		std::cin >> M >> N;
		std::vector<std::string> s(M);
		for (int i = 0; i < M; ++i)
			std::cin >> s[i];
		best = 0;
		best_cnt = 0;
		uint32_t lim = 1;
		for (int i = 0; i < M; ++i)
			lim *= N;

		for (uint32_t mask = 0; mask < lim; ++mask) {
			std::vector<std::unordered_set<std::string>> v(N);
			uint32_t place = mask;
			for (int i = 0; i < M; ++i) {
				std::unordered_set<std::string> &to = v[place % N];
				std::string str = s[i];
				for (int j = 0; j <= str.size(); ++j)
					to.insert(str.substr(0, j));
				place /= N;
			}
			int sz = 0;
			for (auto &i : v)
				sz += i.size();
			if (best < sz) {
				best = sz;
				best_cnt = 1;
			} else if (best == sz)
				++best_cnt;
		}

		printf("Case #%d: ", test + 1);
		printf("%d %d\n", best, best_cnt);
	}

	return 0;
}