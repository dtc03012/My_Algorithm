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

const int MAX = 11;
int vis[MAX];
lld rcalc(lld pre1,lld pre2){
	int vis2[MAX];
	for(int p=0;p<10;p++) vis2[p] = vis[p];
	int cnt = 0;
	for(int p=0;p<10;p++) cnt += vis[p];
	int xx = cnt / 2;
	for(int p=0;p<10;p++){
		while(xx&&vis[p]){
			pre1 = pre1 * 10 + p;
			vis[p]--;
			xx--;
		}
	}
	xx = cnt / 2;
	for(int p=9;p>=0;p--){
		while(xx&&vis[p]){
			pre2 = pre2 * 10 + p;
			vis[p]--;
			xx--;
		}
	}
	for(int p=0;p<10;p++) vis[p] = vis2[p];
	return pre1 - pre2;
}
lld calc(lld pre1,lld pre2){
	int vis2[MAX];
	for(int e=0;e<MAX;e++) vis2[e] = vis[e];
	lld a = pre1,b = pre2;
	if(a==b){
		lld ans = 9e18;
		for(int p=0;p<10;p++){
			if(vis[p]>=2){
				int vis3[MAX];
				for(int e=0;e<MAX;e++) vis3[e] = vis[e];
				lld a1 = a,b1 = b;
				while(vis[p]>=4){
					vis[p] -= 2;
					a1 = a1*10 + p;
					b1 = b1*10 + p;
				}
				for(int q=0;q<10;q++){
					if(p!=q){
						while(vis[q]>=2){
							vis[q] -= 2;
							a1 = a1 * 10 + q;
							b1 = b1 * 10 + q;
						}
					}
				}
				for(int q=1;q<10;q++){
					for(int r=q-1;r>=0;r--){
						if(vis[q]&&vis[r]){
							vis[q]--;
							vis[r]--;
							lld a2 = a1 * 10 + q;
							lld b2 = b1 * 10 + r;
							ans = min(ans,rcalc(a2,b2));
							vis[q]++;
							vis[r]++;
						}
					}
				}
				for(int e=0;e<MAX;e++) vis[e] = vis3[e];
			}
		}
		for(int q=0;q<10;q++){
			while(vis[q]>=2){
				vis[q]-=2;
				a = a*10 + q;
				b = b*10 + q;
			}
		}
		for(int q=1;q<10;q++){
			for(int r=q-1;r>=0;r--){
				if(vis[q]&&vis[r]){
					vis[q]--;
					vis[r]--;
					lld a1 = a*10 + q;
					lld b1 = b*10 + r;
					ans = min(ans,rcalc(a1,b1));
					vis[q]++;
					vis[r]++;
				}
			}
		}
		for(int p=0;p<10;p++) vis[p] = vis2[p];
		if(ans==9e18) ans = 0;
		return ans;
	}else{
		lld ans = rcalc(a,b);
		for(int p=0;p<10;p++) vis[p] = vis2[p];
		return ans;
	}
}
void solve(int tc){
	string a;
	cin >> a;
	memset(vis,0,sizeof(vis));
	for(int e=0;e<sz(a);e++){
		vis[a[e]-'0']++;
	}
	cout << "Case #"<<tc<<": ";
	if(sz(a)%2==0){
		lld ans = 9e18;
		for(int e=1;e<10;e++){
			if(vis[e]){
				vis[e]--;
				for(int p=e;p>=1;p--){
					if(vis[p]){
						vis[p]--;
						lld k = calc(e,p);
						vis[p]++;
						ans = min(ans,k);
					}
				}
				vis[e]++;
			}
		}
		cout << ans << "\n";
	}else{
		lld ans = 9e18;
		for(int e=1;e<10;e++){
			if(vis[e]){
				vis[e]--;
				for(int p=0;p<10;p++){
					if(vis[p]){
						vis[p]--;
						for(int q=1;q<10;q++){
							if(vis[q]){
								vis[q]--;
								lld k = calc(e*10+p,q);
								ans = min(ans,k);
								vis[q]++;
							}
						}
						vis[p]++;
					}
				}
				vis[e]++;
			}
		}
		cout << ans << "\n";
	}
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