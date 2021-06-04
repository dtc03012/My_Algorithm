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
lld arr[MAX],que[MAX];
bool comp(pli a,pli b){
	if(a.x!=b.x) return a.x < b.x;
	return a.y < b.y;
}
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++){
		scanf("%lld",&arr[e]);
		arr[e] += arr[e-1];
	}
	lld modn = arr[n];
	vector<pli> v;
	lld lx = -2e9;
	for(int e=1;e<=n;e++){
		if(arr[e]>lx){
			v.push_back(mk(arr[e],e-1));
			lx = arr[e];
		}
	}
	lld mx = v[sz(v)-1].x;
	for(int e=1;e<=m;e++){
		scanf("%lld",&que[e]);
		if(modn>0){
			if(que[e]>mx){
				lld xx = que[e] - mx;
				xx /= modn;
				if((que[e]-mx)%modn) xx++;
				lld now = que[e] - xx*modn;
				int wh = lower_bound(all(v),mk(now,-1),comp) - v.begin();
				printf("%lld ",xx*n+v[wh].y);
			}else{
				int wh = lower_bound(all(v),mk(que[e],-1),comp) - v.begin();
				printf("%d ",v[wh].y);
			}
		}else{
			int wh = lower_bound(all(v),mk(que[e],-1),comp) - v.begin();
			if(wh==sz(v)) printf("-1 ");
			else printf("%d ",v[wh].y);
		}
	}
	printf("\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}