#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,len;
char ch[110],to[]={"yhesocvxduiglbkrztnwjpfmaq"};
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i){
		gets(ch);len=strlen(ch);
		printf("Case #%d: ",i);
		for(int j=0;j<len;++j)
			if(ch[j]==' ')printf(" ");
			else printf("%c",to[ch[j]-'a']);
		printf("\n");
	}
	return 0;
}
