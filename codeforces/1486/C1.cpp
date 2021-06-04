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

int a[] = {0,1,2,3,8,5,6,4,7};
int query(int l,int r){
	cout << "? " << l << " " <<r << endl;
	int k;
	cin >> k;
	return k;
	// vector<pi> k;
	// for(int p=l;p<=r;p++) k.push_back(mk(a[p],p));
	// sort(all(k));
	// printf("asdf %d\n",k[sz(k)-2].y);
	// return k[sz(k)-2].y;
}
void ans(int x){
	cout << "! " << x << endl;
	exit(0);
}
int x;
void dfs(int l,int r){
	if(l==r) ans(l);
	if(l+1==r){
		int k = query(l,r);
		if(l==k) ans(r);
		else ans(l);
	}
	int mid = (l+r)/2;
	if(x<=mid){
		int v = query(min(l,x),mid);
		if(v==x) dfs(l,mid);
		else dfs(mid,r);
	}else{
		if(l+2==r&&r==x) dfs(l,r-1);
		int v = query(mid+1,max(r,x));
		if(v==x) dfs(mid+1,r);
		else dfs(l,mid);
	}
}
void solve(int tc){
	int n;
	cin >> n;
	x = query(1,n);
	dfs(1,n);
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