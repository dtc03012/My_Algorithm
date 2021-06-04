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
int seg[MAX*4],start = 1,seg2[MAX*4];
void addn(int x,int v){
	x += start;
	seg2[x] = v;
	for(int e=(x/2);e>=1;e/=2) seg2[e] = seg2[e*2] + seg2[e*2+1];
}
int getn(int l,int r){
	l += start;
	r += start;
	int ans = 0;
	while(l<=r){
		if(l&1) ans += seg2[l++];
		if(!(r&1)) ans += seg2[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
int getn2(int l,int r){
	l += start;
	r += start;
	int ans = 1e9;
	while(l<=r){
		if(l&1) ans = min(ans,seg[l++]);
		if(!(r&1)) ans = min(ans,seg[r--]);
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
void solve(int tc){
	while(start<MAX) start *= 2;
	for(int p=0;p<start*2;p++) seg[p] = 1e9;
	int n;
	cin >> n;
	for(int e=1;e<=n;e++){
		cin >> seg[e+start];
		for(int p=(e+start)/2;p>=1;p/=2) seg[p] = min(seg[p*2],seg[p*2+1]);
	}
	for(int e=1;e<n;e++){
		cin >> seg2[e+start];
		for(int p=(e+start)/2;p>=1;p/=2) seg2[p] = seg2[p*2] + seg2[p*2+1];
	}
	int q;
	cin >> q;
	while(q--){
		string a;
		int x,t;
		cin >> a >> x >> t;
		if(a[0]=='U'){
			addn(x,t);
		}else{
			int vv = 1e9;
			{
				int ll = x,rr = n,mid,ans = x;
				while(ll<=rr){
					mid = (ll+rr)/2;
					if(getn(x,mid-1)<=t){
						ans = max(ans,mid);
						ll = mid + 1;
					}else{
						rr = mid - 1;
					}
				}
				vv = min(vv,getn2(x,ans));
			}
			{
				int ll = 1,rr = x,mid,ans = x;
				while(ll<=rr){
					mid = (ll+rr)/2;
					if(getn(mid,x-1)<=t){
						ans = min(ans,mid);
						rr = mid - 1;
					}else{
						ll = mid + 1;
					}
				}
				vv = min(vv,getn2(ans,x));
			}
			printf("%d\n",vv);
		}
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