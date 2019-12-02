#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

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
	scanf("%d", &T);
	for (int test = 0; test < T; ++test) {
		fprintf(stderr, "Case #%d:\n", test + 1);
		int N;
		scanf("%d", &N);
		std::vector<std::pair<int, int>> v(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &v[i].first);
			v[i].second = i;
		}
		int res = N * N * N;
		for (uint32_t mask = 0; mask < (1u << N); ++mask) {
			std::vector<std::pair<int, int>> l, r;
			for (int i = 0; i < N; ++i)
				if ((mask >> i) & 1)
					l.push_back(v[i]);
				else
					r.push_back(v[i]);
			sort(l.begin(), l.end());
			sort(r.rbegin(), r.rend());
			l.insert(l.end(), r.begin(), r.end());
			int ans = 0;
			for (int to = 0; to < N; ++to) {
				// std::cerr << "to = " << to << "; ans = " << ans << std::endl;
				// for (auto i : l)
				// 	std::cerr << "(" << i.first << "," << i.second << ") ";
				// std::cerr << std::endl;

				int i;
				for (i = to; i < N && l[i].second != to; ++i);
				assert(i != N);
				for (; i > to; --i) {
					std::swap(l[i], l[i - 1]);
					++ans;
				}
			}
			if (res > ans)
				res = ans;
		}

		printf("Case #%d: ", test + 1);
		printf("%d\n", res);
	}

	return 0;
}