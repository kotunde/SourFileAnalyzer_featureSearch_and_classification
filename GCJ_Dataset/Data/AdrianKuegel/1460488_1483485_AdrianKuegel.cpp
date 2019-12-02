#include <stdio.h>

char encoded[1000] = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv";

char plain[1000] = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up";

char code[256];
char used[26];

int main() {
	for (int i=0; plain[i]; i++)
	{
		if (encoded[i] != ' ') {
			code[encoded[i]] = plain[i];
			used[plain[i]-'a'] = 1;
		}
	}
	for (int i=0; i<26; ++i)
	{
		if (!code[i + 'a']) {
			for (int j=0; j<26; j++) if (!used[j] && j != i) code[i + 'a'] = j + 'a';
		}
	}
	int tc;
	scanf("%d", &tc);
	char g[200];
	gets(g);
	for (int scen=1; scen<=tc; ++scen)
	{
		gets(g);
		printf("Case #%d: ", scen);
		for (int i=0; g[i]; ++i) {
			if (g[i] != ' ') g[i] = code[g[i]];
			printf("%c", g[i]);
		}
		puts("");
	}
	return 0;
}
