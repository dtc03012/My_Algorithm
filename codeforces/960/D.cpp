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

lld cnt[64];
void solve(int tc){
	int q;
	scanf("%d",&q);
	for(int e=0;e<q;e++){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			lld x,k;
			scanf("%lld%lld",&x,&k);
			int nn = 0;
			while(x){
				nn++;
				x/=2;
			}
			cnt[nn] += k;
			lld md = (1ll<<(nn-1));
			cnt[nn] %= md;
			cnt[nn] = (cnt[nn]+md)%md;
		}else if(ty==2){
			lld x,k;
			scanf("%lld%lld",&x,&k);
			int nn = 0;
			while(x){
				nn++;
				x/=2;
			}
			lld xx = k;
			for(int p=nn;p<64;p++){
				lld md = (1ll<<(p-1));
				xx %= md;
				xx = (xx+md)%md;
				cnt[p] += xx;
				xx *= 2;
			}
		}else{
			lld x;
			scanf("%lld",&x);
			vector<lld> ans;
			lld tmp = x;
			int nn = 0;
			while(tmp){
				tmp/=2;
				nn++;
			}
			while(x){
				ans.push_back(x);
				if(x==1) break;
				lld md = (1ll<<(nn-2));
				lld nx = x - (md*2);
				nx = (nx+cnt[nn])%(md*2);
				nx = (nx+(md*2))%(md*2);
				nx = nx + (md*2);
				lld xx = (nx/2);
				xx = xx - md;
				xx = (xx-cnt[nn-1])%md;
				xx = (xx+md)%md;
				xx = xx + md;
				nn--;
				x = xx;
			}
			for(int e=0;e<sz(ans);e++) printf("%lld ",ans[e]);
			printf("\n");
		}
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}