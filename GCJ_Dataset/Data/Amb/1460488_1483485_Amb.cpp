#include<cstdio>
#include<cstring>
using namespace std;

char str[1005];
char code[] = "yhesocvxduiglbkrztnwjpfmaq";
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A_small.out","w",stdout);
	
	int t, cas=0;
	scanf("%d",&t); getchar();
	while(t--){
		gets(str);
		printf("Case #%d: ", ++cas);
		for(int i=0;str[i];i++){
			if(str[i]==' ') putchar(' ');
			else{
				putchar(code[str[i]-'a']);
			}
		}puts("");
	}
}