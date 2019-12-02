#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

const int MAX_NODE_SIZE = 150000;
const int INF = 1<<25;

//int cap[MAX_NODE_SIZE][MAX_NODE_SIZE];
//int parent[MAX_NODE_SIZE];
pair<int, int> parent[MAX_NODE_SIZE]; // parent node, edge ref in adj-list
int flow[MAX_NODE_SIZE];
int vis[MAX_NODE_SIZE];

struct node{
	int to, rev, cap;
	node(int to, int rev, int cap):to(to), rev(rev), cap(cap){}
	node(){}
};

void getPath_FloodFill(int src,int sink,vector< vector<node> > &adj)	{

	memset(flow,0,sizeof(flow));
	memset(vis,0,sizeof(vis));
	flow[src]=INF;
	stack<int> stk;  // stack of index
	stk.push(src);
	vis[src]=1;

	while(!stk.empty())	{

		int cur = stk.top();
		stk.pop();

		for(int i=0;i<adj[cur].size();i++)	{
			int to = adj[cur][i].to;
			int cap = adj[cur][i].cap;
			int rev = adj[cur][i].rev;
			if(!vis[to] && flow[to] < min(flow[cur],cap))	{
				flow[to] = min(flow[cur],cap);
				//parent[to] = cur;
				parent[to] = make_pair(cur, i);
				stk.push(to);
				vis[to]=1;
				if(to==sink) return;
			}
		}

	}

}

#define IN(x,y) ((w*(y)+(x))*2)
#define OUT(x,y) (((w*(y)+(x))*2)+1)

void addEdge(int src,int sink, int forwardCap, int revCap,vector< vector<node> > &adj)	{
	int rev = adj[sink].size();
	int revRev = adj[src].size();
	adj[src].push_back(node(sink, rev, forwardCap));
	adj[sink].push_back(node(src, revRev, revCap));
}

int maxFlow(int src,int sink,vector< vector<node> > &adj)	{

	if(src==sink) return INF;

	int tot=0;
	while(1)	{
		getPath_FloodFill(src,sink,adj);
		//cerr << flow[sink] << endl;
		if(flow[sink]<=0) break;
		tot+=flow[sink];
		for(int cur=sink; cur!=src; cur=parent[cur].first)	{
			int p = parent[cur].first;
			int pind = parent[cur].second;
			int cind = adj[p][pind].rev;
			adj[cur][cind].cap += flow[sink];
			adj[p][pind].cap -= flow[sink];
			//cap[cur][parent[cur]] += flow[sink];
			//cap[parent[cur]][cur] -= flow[sink];
		}
	}
	return tot;
}

struct B{
	int x0,y0,x1,y1;
};

int w,h;

vector<B> v;

bool blocked(int x, int y) {
	for(int i=0;i<v.size();i++) {
		if(x>=v[i].x0 && x<=v[i].x1 && y>=v[i].y0 && y<=v[i].y1)
			return true;
	}
	return false;
}

int dx[]={0,1};
int dy[]={1,0};

int main() {
#ifdef LARGE
	freopen("c_large.i", "rt", stdin);
	freopen("c_large.o", "wt", stdout);
#elif SMALL
	freopen("c_small_2.i", "rt", stdin);
	freopen("c_small_2.o", "wt", stdout);
#else
	freopen("c_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int b;
		cin>>w>>h>>b;
		v.resize(b);
		for(int i=0;i<b;i++) {
			cin>>v[i].x0>>v[i].y0>>v[i].x1>>v[i].y1;
		}
		int src = w*h*2, dst = w*h*2+1;
		int n = dst+1;
		vector< vector<node> > adj(n);
		for(int x=0;x<w;x++) {
		  	for(int y=0;y<h;y++) {
		  		if(blocked(x, y))
		  			continue;
		  		addEdge(IN(x,y), OUT(x,y), 1, 0, adj);
				//cap[IN(x,y)][OUT(x,y)] = 1;
				for(int k=0;k<2;k++) {
					int nx = x+dx[k], ny=y+dy[k];
					if(nx < 0 || nx >= w || ny < 0 || ny >= h || blocked(nx, ny))
						continue;
					//cap[OUT(x, y)][IN(nx, ny)] = INF;
					addEdge(OUT(x, y), IN(nx, ny), INF, INF, adj);
					addEdge(OUT(nx, ny), IN(x, y), INF, INF, adj);
				}
		  	}
		}
		for(int x=0;x<w;x++) {
			if(!blocked(x, 0))
				//cap[src][IN(x,0)] = 1;
				addEdge(src, IN(x,0), 1, 0, adj);
			if(!blocked(x, h-1))
				//cap[OUT(x, h-1)][dst] = 1;
				addEdge(OUT(x, h-1), dst, 1, 0, adj);
		}
		cout<<"Case #"<<tt<<": "<<maxFlow(src, dst, adj)<<endl;
	}

	return 0;
}
