#include <cstdio>

int t[33];
char s[333];

void test()
{
	gets(s);
	for(int i = 0; s[i]; i++) if(s[i] != ' ') s[i] = 'a' + t[s[i]-'a'];
	printf("%s\n", s);
}

int main()
{
	t[0] = 24;
	t[1] = 7;
	t[2] = 4;
	t[3] = 18;
	t[4] = 14;
	t[5] = 2;
	t[6] = 21;
	t[7] = 23;
	t[8] = 3;
	t[9] = 20;
	t[10] = 8;
	t[11] = 6;
	t[12] = 11;
	t[13] = 1;
	t[14] = 10;
	t[15] = 17;
	t[16] = 25;
	t[17] = 19;
	t[18] = 13;
	t[19] = 22;
	t[20] = 9;
	t[21] = 15;
	t[22] = 5;
	t[23] = 12;
	t[24] = 0;
	t[25] = 16;
	int tt;
	scanf("%d ", &tt);
	for(int t = 1; t <= tt; t++)
	{
		printf("Case #%d: ", t);
		test();
	}
}
