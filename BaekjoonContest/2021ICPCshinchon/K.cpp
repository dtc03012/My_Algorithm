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

const int MAX = 202020;
int uf[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pair<pi,int> > x,y;
	for(int e=0;e<n;e++){
		uf[e] = e;
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		x.push_back(mk(mk(a,b),e));
		y.push_back(mk(mk(c,d),e));
	}
	sort(all(x));
	sort(all(y));
	int ll = -1,rr = -1;
	for(int e=0;e<sz(x);e++){
		if(ll==-1){
			ll = x[e].y;
			rr = x[e].x.y;
		}else{
			if(x[e].x.x<=rr){
				uf[x[e].y] = ll;
				rr = max(rr,x[e].x.y);
			}else{
				ll = x[e].y;
				rr = x[e].x.y;
			}
		}
	}
	ll = -1;rr = -1;
	for(int e=0;e<sz(y);e++){
		y[e].y = find(y[e].y);
		if(ll==-1){
			rr = y[e].x.y;
			ll = y[e].y;
		}else{
			if(y[e].x.x<=rr&&y[e].y!=ll){
				uf[y[e].y] = ll;
				rr = max(rr,y[e].x.y);
			}else{
				ll = y[e].y;
				rr = y[e].x.y;
			}
		}
	}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		if(find(x)==find(y)) printf("1\n");
		else printf("0\n");
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}