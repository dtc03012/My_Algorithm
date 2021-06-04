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
vector<pair<int,pi> > que;
vector<int> idx;
int start = 1;
lld segX1[MAX*4],segX2[MAX*4],segY1[MAX*4],segY2[MAX*4];
void upd(lld* seg,int x,int v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
lld getn(lld* seg,int l,int r){
	l += start;
	r += start;
	lld ans = 0;
	while(l<=r){
		if(l&1) ans += seg[l++];
		if(!(r&1)) ans += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return ans;
}
int get_idx(int x){
	return lower_bound(all(idx),x) - idx.begin();
}
int A[MAX],B[MAX];
void solve(int tc){
	while(start<MAX) start *= 2;
	int n,m,q;
	cin >> n >> m >> q;
	for(int e=0;e<q;e++){
		int a,b,c;
		cin >> a >>b >> c;
		que.push_back(mk(a,mk(b,c)));
		idx.push_back(c);
	}
	idx.push_back(0);
	for(int e=1;e<=n;e++) upd(segX1,0,1);
	for(int e=1;e<=m;e++) upd(segY1,0,1);
	sort(all(idx));
	idx.erase(unique(all(idx)),idx.end());
	lld ans = 0;
	for(int e=0;e<sz(que);e++){
		int ty = que[e].x;
		int X = que[e].y.x;
		int Y = que[e].y.y;
		if(ty==1){
			int f1 = get_idx(A[X]);
			int f2 = get_idx(Y);
			if(A[X]<Y){
				lld num1 = getn(segY2,f1,f2);
				lld num2 = getn(segY1,f1,f2);
				lld num3 = getn(segY1,0,f1-1);
				ans -= num1;
				ans += num2*Y;
				ans += num3*(Y-A[X]);
			}else{
				lld num1 = getn(segY2,f2,f1);
				lld num2 = getn(segY1,f2,f1);
				lld num3 = getn(segY1,0,f2-1);
				ans -= num2*A[X];
				ans += num1;
				ans += num3*(Y-A[X]);
			}
			upd(segX1,f1,-1);
			upd(segX2,f1,-A[X]);
			A[X] = Y;
			upd(segX1,f2,1);
			upd(segX2,f2,A[X]);
		}else{
			int f1 = get_idx(B[X]);
			int f2 = get_idx(Y);
			if(B[X]<Y){
				lld num1 = getn(segX2,f1,f2);
				lld num2 = getn(segX1,f1,f2);
				lld num3 = getn(segX1,0,f1-1);
				ans -= num1;
				ans += num2*Y;
				ans += num3*(Y-B[X]);
			}else{
				lld num1 = getn(segX2,f2,f1);
				lld num2 = getn(segX1,f2,f1);
				lld num3 = getn(segX1,0,f2-1);
				ans -= num2*B[X];
				ans += num1;
				ans += num3*(Y-B[X]);
			}
			upd(segY1,f1,-1);
			upd(segY2,f1,-B[X]);
			B[X] = Y;
			upd(segY1,f2,1);
			upd(segY2,f2,B[X]);
		}
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