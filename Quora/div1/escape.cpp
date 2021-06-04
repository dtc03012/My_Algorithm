#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 1010;
string arr[MAX];
int vis[MAX][MAX],val[MAX][MAX],can[MAX][MAX];
void solve(int tc){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int sy,sx,ey,ex;
	for(int e=0;e<n;e++){
		cin >> arr[e];
		for(int p=0;p<m;p++){
			if(arr[e][p]=='S'){
				sy = e;
				sx = p;
			}else if(arr[e][p]=='E'){
				ey = e;
				ex = p;
			}
		}
	}
	priority_queue<pair<int,pi> > pq;
	memset(can,-1,sizeof(can));
	while(k--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		can[a][b] = c;
		pq.push(mk(c,mk(a,b)));
	}
	while(!pq.empty()){
		int dist = pq.top().x;
		int y = pq.top().y.x;
		int x = pq.top().y.y;
		pq.pop();
		if(can[y][x]!=dist) continue;
		for(int e=0;e<4;e++){
			int ny = y + dy[e];
			int nx = x + dx[e];
			if(isrange(ny,nx,n,m)&&dist-1>can[ny][nx]&&arr[ny][nx]!='#'){
				can[ny][nx] = dist - 1;
				pq.push(mk(can[ny][nx],mk(ny,nx)));
			}
		}
	}
	if(can[sy][sx]>=0){
		printf("IMPOSSIBLE");
		return;
	}
	queue<pi> q;
	q.push(mk(sy,sx));
	for(int e=0;e<n;e++) for(int p=0;p<m;p++) val[e][p] = 1e9;
	val[sy][sx] = 0;
	while(!q.empty()){
		int y = q.front().x;
		int x = q.front().y;
		q.pop();
		for(int e=0;e<4;e++){
			int ny = y + dy[e];
			int nx = x + dx[e];
			if(isrange(ny,nx,n,m)&&can[ny][nx]==-1&&val[ny][nx]==1e9&&arr[ny][nx]!='#'){
				val[ny][nx] = val[y][x] + 1;
				q.push(mk(ny,nx));
			}
		}
	}
	if(val[ey][ex]==1e9){
		printf("IMPOSSIBLE");
		return;
	}
	printf("%d\n",val[ey][ex]);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}