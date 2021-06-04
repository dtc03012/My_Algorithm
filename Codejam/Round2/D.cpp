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

const int MAX = 10;
string A[MAX],B[MAX];
int a1[MAX][MAX],b1[MAX][MAX],n,m,abit[MAX],bbit[MAX];
lld f,s,vis[MAX][(1<<MAX)];
void solve(int tc){
	memset(a1,0,sizeof(a1));
	memset(b1,0,sizeof(b1));
	memset(abit,0,sizeof(abit));
	memset(bbit,0,sizeof(bbit));
	memset(vis,0,sizeof(vis));
	cin >> n >> m >> f >> s;
	for(int e=0;e<n;e++) cin >> A[e];
	for(int e=0;e<n;e++) cin >> B[e];
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			if(A[e][p]=='M') a1[e][p] = 0;
			else a1[e][p] = 1;
			if(B[e][p]=='M') b1[e][p] = 0;
			else b1[e][p] = 1;
		}
	}
	for(int e=0;e<n;e++){
		int bit1 = 0,bit2 = 0;
		for(int p=0;p<m;p++){
			bit1 += (1<<p) * a1[e][p];
			bit2 += (1<<p) * b1[e][p];
		}
		abit[e] = bit1;
		bbit[e] = bit2;
	}
	for(int e=0;e<MAX;e++){
		for(int p=0;p<(1<<MAX);p++) vis[e][p] = 1e18;
	}
	priority_queue<pair<lld,pi> > q;
	q.push(mk(0,mk(0,abit[0])));
	vis[0][abit[0]] = 0;
	lld ans = 1e18;
	while(!q.empty()){
		lld dist = -q.top().x;
		int y = q.top().y.x;
		int bit = q.top().y.y;
		q.pop();
		if(vis[y][bit]!=dist) continue;
		vector<pair<lld,pi> > v;
		v.push_back(mk(dist,mk(bit&(1<<0),0)));
		v.push_back(mk(dist+s,mk((bit&(1<<0))^1,1)));
		v.push_back(mk(dist+f,mk((bit&(1<<0))^1,0)));
		for(int e=1;e<m;e++){
			vector<pair<lld,pi> > v2;
			for(int p=0;p<sz(v);p++){
				lld dist = v[p].x;
				int nbit = v[p].y.x;
				int xbit = v[p].y.y;
				int flag = b1[y][e-1];
				int flag2 = (bit&(1<<e)) > 0;
				if(nbit!=flag){
					v2.push_back(mk(dist+s,mk(flag2^1,xbit)));
					v2.push_back(mk(dist+2*s,mk(flag2,xbit^(1<<e))));
					v2.push_back(mk(dist+2*s+f,mk(flag2^1,xbit^(1<<e))));
					v2.push_back(mk(dist+s+f,mk(flag2,xbit)));
				}else{
					v2.push_back(mk(dist+f,mk(flag2^1,xbit)));
					v2.push_back(mk(dist+f+s,mk(flag2,xbit^(1<<e))));
					v2.push_back(mk(dist,mk(flag2,xbit)));
				}
			}
			v = v2;
		}
		for(int e=0;e<sz(v);e++){
			lld dist = v[e].x;
			int nbit = v[e].y.x;
			int xbit = v[e].y.y;
			if(nbit==b1[y][m-1]){
				int nxbit = xbit ^ abit[y+1];
				if(y+1==n){
					ans = min(ans,dist);
					continue;
				}
				if(vis[y+1][nxbit]>dist){
					vis[y+1][nxbit] = dist;
					q.push(mk(-dist,mk(y+1,nxbit)));
				}
			}
		}
	}
	cout << "Case #" << tc<< ": " << ans << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}