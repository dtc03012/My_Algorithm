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

const int MAX = 17;
lld ten[MAX],kk[MAX];
lld dp[MAX][(1<<MAX)][10];
int arr[MAX];
void solve(int tc){
	kk[0] = 1;
	for(int e=1;e<MAX;e++) kk[e] = kk[e-1] * e;
	ten[0] = 1;
	for(int e=1;e<MAX;e++) ten[e] = (ten[e-1]*10);
	memset(dp,-1,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	lld f1 = 1;
	for(int e=1;e<=n;e++) f1 = (f1*e);
	lld ans = 0;
	lld wh = -1;
	for(int e=1;e<=n;e++){
		if(arr[e]==1) ans += kk[n-1];
		else if(arr[e]==2){
			int xx = 0;
			for(int p=1;p<=n;p++) if(arr[p]%2==0&&p!=e) xx++;
			ans += kk[n-2]*xx;
		}else if(arr[e]==3){
			int tot = 0;
			for(int p=1;p<=n;p++) if(p!=e) tot += arr[p];
			if(tot%3==0) ans += kk[n-1];
		}else if(arr[e]==4){
			for(int p=1;p<=n;p++){
				if(p==e) continue;
				for(int q=1;q<=n;q++){
					if(p==q||q==e) continue;
					if((arr[p]*10+arr[q])%4==0) ans += kk[n-3];
				}
				if(arr[p]%4==0&&n==2) ans += kk[n-2];
			}
		}else if(arr[e]==5){
			int xx = 0;
			for(int p=1;p<=n;p++) if(arr[p]%5==0&&p!=e) xx++;
			ans += kk[n-2]*xx;
		}else if(arr[e]==6){
			int tot = 0;
			for(int p=1;p<=n;p++) if(p!=e) tot += arr[p];
			if(tot%3==0){
				int xx = 0;
				for(int q=1;q<=n;q++) if(q!=e&&arr[q]%2==0) xx++;
				ans += kk[n-2]*xx;
			}
		}else if(arr[e]==7){
			if(wh==-1){
				vector<int> v;
				for(int p=1;p<=n;p++) if(e!=p) v.push_back(arr[p]);
				memset(dp,0,sizeof(dp));
				dp[0][0][0] = 1;
				int len = sz(v);
				for(int p=1;p<=len;p++){
					int xx = v[p-1];
					for(int q=0;q<(1<<len);q++){
						for(int r=0;r<len;r++){
							if((q&(1<<r))==0){
								for(int x=0;x<10;x++){
									int now = ((ten[r]*xx)+x)%7;
									dp[p][q^(1<<r)][now] += dp[p-1][q][x];
								}
							}
						}
					}
				}
				wh = dp[len][(1<<len)-1][0];
			}
			ans += wh;
		}else if(arr[e]==8){
			for(int p=1;p<=n;p++){
				if(p==e) continue;
				for(int q=1;q<=n;q++){
					if(p==q||q==e) continue;
					if((arr[p]*10+arr[q])%8==0&&n==3) ans += kk[n-3];
					for(int r=1;r<=n;r++){
						if(r==e||p==r||q==r) continue;
						int xx = (arr[p]*100+arr[q]*10+arr[r]);
						if(xx%8==0) ans += kk[n-4];
					}
				}
				if(arr[p]%8==0&&n==2) ans += kk[n-2];
			}
		}else if(arr[e]==9){
			int tot = 0;
			for(int p=1;p<=n;p++) if(e!=p) tot += arr[p];
			if(tot%9==0) ans += kk[n-1];
		}
	}
	ld xx = (ld)ans/(ld)f1;
	printf("%.9Lf",xx);
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