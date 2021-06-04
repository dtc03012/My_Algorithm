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

const lld mod = 1e9 + 7;
priority_queue<pi> q;
set<int> s;
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	lld ans = 0;
	for(int e=1;e<=n;e++){
		int r;
		scanf("%d",&r);
		q.push(mk(r,e));
	}
	s.insert(0);
	s.insert(n+1);
	while(!q.empty()){
		pi xv = q.top();q.pop();
		int pos = xv.y;
		lld val = xv.x;
		auto it = s.lower_bound(pos);
		int ll = *prev(it);
		int rr = *it;
		s.insert(pos);
		ll++;
		rr--;
		pos -= ll;
		rr -= ll;
		ll = 0;
		lld f1 = 0,xx = 0;
		if(rr-k+1>=pos){
			f1 = 1 + (rr-(pos+k)+1)/(k-1);
			xx = (rr-(pos+k)+1)%(k-1);
		}else{
			xx = (rr-pos)%(k-1);
		}
		lld tot = 0;
		if(pos-(k-1)<0){
			lld kk = (k-1) - xx;
			tot += 1ll * (pos+1) * f1;
			tot += max(0ll,pos+1-kk);
			ans += tot * val;
		}else{
			lld kk = (k-1) - xx;
			tot += 1ll * (k-1) * f1;
			tot += max(0ll,k - 1 - kk);
			lld vv = pos/(k-1);
			if((pos+1)%(k-1)) vv++;
			printf("%lld : %lld\n",val,vv);
			lld tot2 = tot * vv + 1;
			if((pos+1)%(k-1)){
				lld npos = pos%(k-1);
				lld nrr = rr - (pos - npos);
				lld f1 = 0,xx = 0;
				if(nrr-k+1>=npos){
					f1 = 1 + (nrr-(npos+k)+1)/(k-1);
					xx = (nrr-(npos+k)+1)%(k-1);
				}else{
					xx = (nrr-npos)%(k-1);
				}
				lld nkk = (k-1) - xx;
				tot2 += 1ll * (npos+1) * f1;
				tot2 += max(0ll,npos+1-nkk);
				ans += tot2 * val; 
			}else{
				ans += tot2 * val;
			}
		}
	}
	printf("%lld\n",ans);
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