#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define pt pair<int,int>

int grid[100][100];
int dist[100][100];
bool ok[100][100];

int r,c,m;
vector<pt> ls;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
pt curr;

bool valid(pt p){ // true iff every neighbor q has a neighbor s which is not surrounded by mines and dist[s] = dist[q]-1
   if (p==curr) return false;
   
   for(int i=0; i<8; i++){
      pt q(p.first+dx[i],p.second+dy[i]);
	  if (q.first<0 || q.first>=r || q.second<0 || q.second>=c) continue;
	  
	  bool flag=false;
	  for(int j=0; j<8; j++){
	     pt s(q.first+dx[j],q.second+dy[j]);
		 if (s.first<0 || s.first>=r || s.second<0 || s.second>=c) continue;
		 if (s==p) continue;
		 if (grid[s.first][s.second]=='*') continue;
		 if (ok[s.first][s.second] && dist[s.first][s.second]==dist[q.first][q.second]-1){
		    flag=true; break;
		 }
	  }
	  if (!flag) return false;
   }
   return true;
}

bool process(int ind, int cnt){
   if (cnt==m){
	  return true;
   }
   for(int i=ind; i<ls.size(); i++){
      if (ls[i]==curr) continue;
	  
	  grid[ls[i].first][ls[i].second]='*';
	  // modify ok[][]
	  bool prev_ok=ok[ls[i].first][ls[i].second];
	  ok[ls[i].first][ls[i].second]=false;
	  bool prev[8];
	  for(int j=0; j<8; j++){
		 pt nxt(ls[i].first+dx[j],ls[i].second+dy[j]);
		 if (nxt.first<0 || nxt.first>=r || nxt.second<0 || nxt.second>=c) continue;
		 prev[j]=ok[nxt.first][nxt.second];
	     ok[nxt.first][nxt.second]=false;
	  }
	  
	  if (valid(ls[i])){
	     //printf("[%d,%d]\n",ls[i].first,ls[i].second);
	     if (process(i+1,cnt+1)) return true;
	  }
	  
	  ok[ls[i].first][ls[i].second]=prev_ok;
	  grid[ls[i].first][ls[i].second]='.';
	  // restore ok[][]
	  for(int j=0; j<8; j++){
	     pt nxt(ls[i].first+dx[j],ls[i].second+dy[j]);
		 if (nxt.first<0 || nxt.first>=r || nxt.second<0 || nxt.second>=c) continue;
		 ok[nxt.first][nxt.second]=prev[j];
	  }
   }
}


bool attempt(int x, int y, int border){ // place mines at the border
   //cout<<x<<" "<<y<<" "<<r<<" "<<c<<" "<<m<<endl;
   curr=pt(x,y);
   
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	     dist[i][j]=-1;
		 ok[i][j]=true; // assuming the rxc subgrid is not surrounded by mines
		 grid[i][j]='.';
	  }
   }
   if (border==1){
      for(int i=0; i<r; i++){
         ok[i][0]=ok[i][c-1]=false;
      }
      for(int i=0; i<c; i++){
         ok[0][i]=ok[r-1][i]=false;
      }
   }
   else if (border==2){
      for(int i=0; i<r; i++){
         ok[i][c-1]=false;
      }
      for(int i=0; i<c; i++){
         ok[r-1][i]=false;
      }
   }
   else if (border==3){
      for(int i=0; i<r; i++){
         ok[i][0]=ok[i][c-1]=false;
      }
      for(int i=0; i<c; i++){
         ok[r-1][i]=false;
      }
   }
   else if (border==4){
      for(int i=0; i<r; i++){
         ok[i][c-1]=false;
      }
      for(int i=0; i<c; i++){
         ok[0][i]=ok[r-1][i]=false;
      }
   }
   else if (border==5){
      for(int i=0; i<r; i++) ok[i][c-1]=false;
   }
   else if (border==6){
      for(int i=0; i<c; i++) ok[r-1][i]=false;
   }
   else if (border==7){
      for(int i=0; i<r; i++) ok[i][0]=ok[i][c-1]=false;
   }
   else if (border==8){
      for(int i=0; i<c; i++) ok[0][i]=ok[r-1][i]=false;
   }
   if (!ok[x][y]){
      if (m+1==r*c){
	     for(int i=0; i<r; i++){
		    for(int j=0; j<c; j++){
			   if (i==x && j==y) grid[i][j]='c';
			   else grid[i][j]='*';
			}
		 }
		 return true;
	  }
	  return false;
   }
   /*
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++) printf("%d",ok[i][j]);
	  puts("");
   }
   puts("");*/
   queue<pt> q; q.push(pt(x,y));
   dist[x][y]=0;
   while(!q.empty()){
      pt here=q.front(); q.pop();
	  for(int i=0; i<8; i++){
	     pt next(here.first+dx[i],here.second+dy[i]);
		 if (next.first<0 || next.first>=r && next.second<0 || next.second>=c) continue;
		 if (dist[next.first][next.second]==-1){
		    dist[next.first][next.second]=1+dist[here.first][here.second];
			q.push(next);
		 }
	  }
   }
   
   ls.clear();
   for(int i=0; i<r; i++) ls.push_back(pt(i,0));
   for(int i=1; i<c; i++) ls.push_back(pt(r-1,i));
   for(int i=r-2; i>=0; i--) ls.push_back(pt(i,c-1));
   for(int i=c-2; i>0; i--) ls.push_back(pt(0,i));
   
   return process(0,0);
}

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      printf("Case #%d:\n",cs+1);
      int R,C,M; scanf("%d%d%d",&R,&C,&M);
	  r=R; c=C; m=M;
	  bool flag=false; pt x;
	  for(int i=0; i<r; i++){
	     for(int j=0; j<c; j++){
		    if (attempt(i,j,0)){
			   flag=true; x=pt(i,j); goto exit1;
			}
		 }
	  }
	  exit1:
	  if (flag){
	     for(int i=0; i<r; i++){
		    for(int j=0; j<c; j++){
			   if (pt(i,j)==x) putchar('c');
			   else putchar(grid[i][j]);
			}
			puts("");
		 }
	     continue;
	  }
	  flag=false; // intentionally redundant
	  for(int ii=1; ii+1<R; ii++){
	     for(int jj=1; jj+1<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,1)){
				     flag=true; x=pt(i,j); goto exit2;
				  }
			   }
			}
		 }
	  }
	  exit2:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i>0 && i<=r && j>0 && j<=c){
			      if (pt(i-1,j-1)==x) putchar('c');
				  else putchar(grid[i-1][j-1]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  
	  //   |
	  // __|
	  
	  flag=false; // intentionally redundant
	  for(int ii=1; ii<R; ii++){
	     for(int jj=1; jj<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,2)){
				     flag=true; x=pt(i,j); goto exit3;
				  }
			   }
			}
		 }
	  }
	  exit3:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j<c){
			      if (pt(i,j)==x) putchar('c');
				  else putchar(grid[i][j]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  
	  // |    |
	  // |____|
	  
	  flag=false; // intentionally redundant
	  for(int ii=1; ii<R; ii++){
	     for(int jj=1; jj+1<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,3)){
				     flag=true; x=pt(i,j); goto exit4;
				  }
			   }
			}
		 }
	  }
	  exit4:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j>0 && j<=c){
			      if (pt(i,j-1)==x) putchar('c');
				  else putchar(grid[i][j-1]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  
	  // __
	  //   |
	  // __|
	  flag=false; // intentionally redundant
	  for(int ii=1; ii+1<R; ii++){
	     for(int jj=1; jj<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,4)){
				     flag=true; x=pt(i,j); goto exit5;
				  }
			   }
			}
		 }
	  }
	  exit5:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i>0 && i<=r && j<c){
			      if (pt(i-1,j)==x) putchar('c');
				  else putchar(grid[i-1][j]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  //    |
	  //    |
	  //    |
	  flag=false; // intentionally redundant
	  for(int ii=R; ii<=R; ii++){
	     for(int jj=1; jj<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,5)){
				     flag=true; x=pt(i,j); goto exit6;
				  }
			   }
			}
		 }
	  }
	  exit6:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j<c){
			      if (pt(i,j)==x) putchar('c');
				  else putchar(grid[i][j]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  //
	  // _________
	  //
	  flag=false; // intentionally redundant
	  for(int ii=1; ii<R; ii++){
	     for(int jj=C; jj<=C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,6)){
				     flag=true; x=pt(i,j); goto exit7;
				  }
			   }
			}
		 }
	  }
	  exit7:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j<c){
			      if (pt(i,j)==x) putchar('c');
				  else putchar(grid[i][j]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  
	  flag=false; // intentionally redundant
	  for(int ii=R; ii<=R; ii++){
	     for(int jj=1; jj+1<C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,7)){
				     flag=true; x=pt(i,j); goto exit8;
				  }
			   }
			}
		 }
	  }
	  exit8:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j<c){
			      if (pt(i,j)==x) putchar('c');
				  else putchar(grid[i][j-1]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  
	  flag=false; // intentionally redundant
	  for(int ii=1; ii+1<R; ii++){
	     for(int jj=C; jj<=C; jj++){
		    r=ii; c=jj;
			m=M-(R*C-r*c);
			if (m<0) continue;
			for(int i=0; i<r; i++){
			   for(int j=0; j<c; j++){
			      if (attempt(i,j,8)){
				     flag=true; x=pt(i,j); goto exit9;
				  }
			   }
			}
		 }
	  }
	  exit9:
	  if (flag){
	     for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
			   if (i<r && j<c){
			      if (pt(i,j)==x) putchar('c');
				  else putchar(grid[i-1][j]);
			   }
			   else putchar('*');
			}
			puts("");
		 }
		 continue;
	  }
	  puts("Impossible");
   }
}