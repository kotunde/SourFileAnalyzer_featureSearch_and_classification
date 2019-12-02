#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;


const int maxn=400000;
const int maxe=2000000;
const int INF=2100000000;

int dis[maxn],pre[maxn],gap[maxn],arc[maxn],f[maxe],cap[maxe],first[maxn],next[maxe],vv[maxe];
int q[maxn],vis[maxn];

int sap(int s,int t,int n)
{
    int j,mindis,ans=0,front=0,rear=1,u,v,low;
    bool found;

    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memset(vis,0,sizeof(vis));
    memset(arc,0,sizeof(arc));
    memset(f,0,sizeof(f));

    u=s;low=INF;pre[s]=s;

    while(dis[s]<n)
    {
        found=false;

        for(int &e=arc[u];e;e=next[e])if(dis[vv[e]]==dis[u]-1&&cap[e]>f[e])
        {
            found=true;v=vv[e];

            low=low<cap[e]-f[e]?low:cap[e]-f[e];
            pre[v]=u;u=v;
            
            if(u==t)
            {
                while(u-s)
                {
                    u=pre[u];
                    f[arc[u]]+=low;
                    f[arc[u]^1]-=low;
                }

                ans+=low;low=INF;    
            }
            break;
        }

        if(found)
            continue;

        mindis=n;
        for(int e=first[u];e;e=next[e])
            if(mindis>dis[vv[e]]&&cap[e]>f[e])
            {
                mindis=dis[vv[j=e]];
                arc[u]=e;
            };

        gap[dis[u]]--;
        if(gap[dis[u]]==0)
            return ans;

        dis[u]=mindis+1;
        gap[dis[u]]++;

        u=pre[u];
    }
    return ans;
}

inline void add(int u,int v,int c,int &e)
{
    next[e]=first[u],vv[e]=v,cap[e]=c,first[u]=e++;
    next[e]=first[v],vv[e]=u,cap[e]=0,first[v]=e++;
}
int W,H,B;
int is[1100][1100];
int main()
{
	int t,i,j,k,ii=0;

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	cin>>t;
	while(t--)
	{
		cin>>W>>H>>B;

		memset(is,0,sizeof(is));
	
		int num=0;

		int X0,Y0,X1,Y1;

		int e=2;

		memset(first,0,sizeof(first));
		for(i=0;i<B;i++)
		{
			scanf("%d%d%d%d",&X0,&Y0,&X1,&Y1);
			for(int i1=X0;i1<=X1;i1++)
				for(int j1=Y0;j1<=Y1;j1++)
					is[i1][j1]=1;
		}
		int st=W*H*2+1,ed=st+1;

		for(i=0;i<W;i++)if(!is[i][0])
			add(st,(i+1)*2-1,1,e);
		for(i=0;i<W;i++)if(!is[i][H-1])
			add(((H-1)*W+i+1)*2,ed,1,e);

		int u,v;
		for(i=0;i<W;i++)
		{
			for(j=0;j<H;j++)if(!is[i][j])
			{
				u=(j*W+i+1);
				if(j+1<H&&!is[i][j+1])
				{
					v=u+W;
					add(u*2,v*2-1,1,e);
				}
				if(j-1>=0&&!is[i][j-1])
				{
					v=u-W;
					add(u*2,v*2-1,1,e);
				}
				if(i+1<W&&!is[i+1][j])
				{
					v=u+1;
					add(u*2,v*2-1,1,e);
				}
				if(i-1>=0&&!is[i-1][j])
				{
					v=u-1;
					add(u*2,v*2-1,1,e);
				}
				add(u*2-1,u*2,1,e);
			}
		}
		printf("Case #%d: %d\n",++ii,sap(st,ed,ed));
	}
}
