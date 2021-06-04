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

const int MAX = 202;
const int NMAX = 1e5 + 100;
const lld mod = 1e9 + 7;
int arr[MAX][MAX],arr2[MAX][MAX];
int cnt[NMAX],num[NMAX],n1[NMAX],n2[NMAX],p1[NMAX],p2[NMAX],dp[(1<<21)];
void solve(int tc){
	memset(cnt,0,sizeof(cnt));
	memset(num,0,sizeof(num));
	memset(n1,0,sizeof(n1));
	memset(n2,0,sizeof(n2));
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	memset(dp,0,sizeof(dp));
	int n,m,b;
	cin >> n >> m >> b;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++) cin >> arr[e][p];
	}
	if(n>m){
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				arr2[p][e] = arr[e][p];
			}
		}
		swap(n,m);
		for(int e=0;e<n;e++){
			for(int p=0;p<m;p++){
				arr[e][p] = arr2[e][p];
			}
		}
	}
	lld ans = 0;
	for(int e=1;e<(1<<n);e++){
		vector<int> v;
		for(int p=0;p<n;p++) if(e&(1<<p)) v.push_back(p);
		vector<int> nv;
		int xx = 0;
		for(int p=0;p<m;p++){
			int vv = 0;
			for(int q=0;q<sz(v);q++) vv += arr[v[q]][p];
			if(vv<=b){
				nv.push_back(vv);
				xx += vv;
			}
		}
		if(xx<b) continue;
		if(m>40){
			cnt[0] = 1;
			num[0] = e;
			int lim = 0;
			for(int p=0;p<sz(nv);p++){
				for(int q=lim;q>=0;q--){
					if(num[q]==e){
						if(q+nv[p]<=b){
							if(num[q+nv[p]]!=e){
								num[q+nv[p]] = e;
								cnt[q+nv[p]] = 0;
							}
							cnt[q+nv[p]] = (cnt[q+nv[p]] + cnt[q])%mod;
							lim = max(lim,q+nv[p]);
						}
					}
				}
			}
			if(num[b]==e) ans = (ans+cnt[b])%mod;
		}else{
			int mid = sz(nv)/2;
			int tt = 0,xx = 2;
			for(int p=1;p<(1<<mid);p++){
				if(p==xx){
					tt++;
					xx *= 2;
				}
				dp[p] = dp[p^(1<<tt)] + nv[tt];
				if(dp[p]<=b){
					if(p1[dp[p]]!=e){
						p1[dp[p]] = e;
						n1[dp[p]] = 0;
					}
					n1[dp[p]]++;
				}
			}
			p1[0] = e;
			n1[0] = 1;
			if(p1[b]==e) ans = (ans+n1[b])%mod;
			tt = 0;xx = 2;
			int rmid = sz(nv) - mid;
			for(int p=1;p<(1<<rmid);p++){
				if(p==xx){
					tt++;
					xx *= 2;
				}
				dp[p] = dp[p^(1<<tt)] + nv[tt+mid];
				if(dp[p]<=b){
					if(p1[b-dp[p]]==e){
						ans = (ans+n1[b-dp[p]])%mod;
					}
				}
			}
		}
 	}
 	cout << ans << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}