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
int go[MAX*4][2],n,t,seg[MAX*4],wh[MAX];
pi len[MAX*4];
void upd(int x){
	seg[x]--;
	for(int e=(x/2);e>=1;e/=2) seg[e]--;
}
void init(int node,int l,int r){
	if(l==r){
		wh[l] = node;
		return;
	}
	int mid = (l+r)/2;
	init(node*2,l,mid);
	init(node*2+1,mid+1,r);
}
int query(int l,int r){
	cout << "? " << l << " " << r << endl;
	int v;
	cin >> v;
	return v;
}
int dfs(int node,int l,int r,int k){
	int mid = (l+r)/2;
	if(seg[node*2]==-1) seg[node*2] = mid - l + 1 - query(l,mid);
	if(seg[node*2]<=k) return dfs(node*2,l,mid,k);
	if(seg[node*2+1]==-1) seg[node*2+1] = r - mid - query(mid+1,r);
	return dfs(node*2+1,mid+1,r,k-seg[node*2]);
}
void solve(int tc){
	memset(seg,-1,sizoef(have));
	cin >> n >> t;
	init(1,1,n);
	seg[1] = n - query(1,n);
	while(t--){
		int k;
		cin >> k;
		int st = dfs(1,1,n,k);
		cout << "! " << st << endl;
		upd(wh[st]);
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