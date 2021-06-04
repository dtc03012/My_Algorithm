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

const int MAX =101010;
vector<pi> v[MAX];
lld C[MAX];
priority_queue<pli> q;
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%lld",&C[e]);
	int qq;
	scanf("%d",&qq);
	for(int e=0;e<qq;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(mk(b,c));
		C[b] += c;
	}
	for(int e=1;e<=n;e++) q.push(mk(-C[e],e));	
	int pos = 0;
	lld mx = 0;
	while(pos<m){
		pli xx = q.top();q.pop();
		xx.x *= -1;
		if(C[xx.y]!=xx.x) continue;
		pos++;
		mx = max(mx,xx.x);
		for(int e=0;e<sz(v[xx.y]);e++){
			int nx = v[xx.y][e].x;
			int val = v[xx.y][e].y;
			C[nx] -= val;	
			q.push(mk(-C[nx],nx));
		}
	}
	printf("%lld",mx);
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