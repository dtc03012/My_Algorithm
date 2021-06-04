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

const int MAX = 101010;
vector<int> v[26];
int ll[MAX],rr[MAX],vis[MAX],ck[MAX];
void solve(int tc){
	int n,q;
	cin >> n >> q;
	string a;
	cin >> a;
	for(int e=1;e<=sz(a);e++){
		int xx = a[e-1] - 'A';
		v[xx].push_back(e);
	}
	for(int e=0;e<26;e++){
		memset(vis,0,sizeof(vis));
		for(int p=0;p<sz(v[e]);p++){
			vis[v[e][p]] = 1;
			ck[v[e][p]] = 1;
		}
		int lx = 0,cn = 0;
		for(int p=1;p<=n;p++){
			if(vis[p]&&vis[lx]==0) cn++;
			ll[p] += cn;
			if(ck[p]) lx = p; 
		}
		lx = n + 1;
		cn = 0;
		for(int p=n;p>=1;p--){
			if(vis[p]&&vis[lx]==0) cn++;
			rr[p] += cn;
			if(ck[p]) lx = p;
		}
	}
	for(int e=0;e<q;e++){
		int l,r;
		cin >> l >> r;
		int ans = ll[l-1] + rr[r+1];
		cout << ans << "\n"; 
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}