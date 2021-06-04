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

struct line{
	lld x,y;
	lld getx(lld v){
		return x*v + y;
	}
};
struct Node{
	int lc,rc;
	lld s,e;
	line v;
};
struct lichao{
	vector<Node> v;
	void init(lld s,lld e){
		v.push_back({-1,-1,s,e,{0,(lld)-1e18}});
	}
	void update(line now){
		update(0,now);
	}
	void update(int node,line now){
		lld ll = v[node].s,rr = v[node].e;
		line low = now;
		line high = v[node].v;
		if(low.getx(ll)>high.getx(ll)) swap(low,high);
		if(low.getx(rr)<=high.getx(rr)){
			v[node].v = high;
			return;
		}
		lld mid = (ll+rr)/2;
		if(low.getx(mid)<high.getx(mid)){
			v[node].v = high;
			if(v[node].rc==-1){
				v[node].rc = sz(v);
				v.push_back({-1,-1,mid+1,rr,{0,(lld)-1e18}});
			}
			update(v[node].rc,low);
		}else{
			v[node].v = low;
			if(v[node].lc==-1){
				v[node].lc = sz(v);
				v.push_back({-1,-1,ll,mid,{0,(lld)-1e18}});
			}
			update(v[node].lc,high);
		}
	}
	lld query(lld x){
		return query(0,x);
	}
	lld query(int node,lld x){
		if(node==-1) return -1e18;
		lld ll = v[node].s,rr = v[node].e;
		line now = v[node].v;
		lld mid = (ll+rr)/2;
		if(x<=mid) return max(query(v[node].lc,x),now.getx(x));
		else return max(query(v[node].rc,x),now.getx(x));
	}
};

const int MAX = 303;
lichao seg[MAX];
int arr[MAX][MAX];
lld sum[MAX][MAX][MAX],dp[MAX][MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		for(int p=e;p<=n;p++){
			scanf("%d",&arr[e][p]);
			arr[e][p] += arr[e-1][p];
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=e;p<=n;p++) dp[e][p] = -1e18;
	}
	for(int e=1;e<=n;e++){
		int t;
		scanf("%d",&t);
		seg[e].init(0,1e9);
		while(t--){
			lld V,C;
			scanf("%lld%lld",&V,&C);
			seg[e].update({V,-C});
		}
	}
	for(int e=1;e<=n;e++){
		for(int p=e;p>=1;p--){
			for(int q=e;q<=n;q++) sum[p][q][e] = sum[p][q-1][e] + arr[e][q] - arr[p-1][q];
		}
	}
	for(int e=0;e<n;e++){
		for(int q=1;q<=n;q++){
			if(q+e>=n+1) break;
			for(int p=q;p<=q+e;p++){
				lld lv = dp[q][p-1] + dp[p+1][q+e];
				lld xx = sum[q][q+e][p]
				;
				dp[q][q+e] = max(dp[q][q+e],lv+seg[p].query(xx));
			}
		}
	}
	printf("%lld\n",dp[1][n]);
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