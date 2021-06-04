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

const lld mod = 998244353;
const int MAX = 1010;
vector<pi> v[MAX];
vector<int> k;
int uf[MAX];
int get_idx(int x){
	return lower_bound(all(k),x) - k.begin();
}
int find(int x){
	if(x!=uf[x]) return uf[x] = find(uf[x]);
	return x;
}
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
void solve(int tc){
	int c,n,m;
	cin >> c >> n >> m;
	k.clear();
	vector<pi> res;
	for(int e=1;e<=c;e++){
		uf[e] = e;
		v[e].clear();
		int kn;
		cin >> kn;
		for(int p=0;p<kn;p++){
			int l,r;
			cin >> l >> r;
			k.push_back(l);
			k.push_back(r);
			v[e].push_back(mk(l,r));
		}
	}
	sort(all(k));
	k.erase(unique(all(k)),k.end());
	for(int e=1;e<=c;e++){
		for(int p=0;p<sz(v[e]);p++){
			v[e][p].x = get_idx(v[e][p].x);
			v[e][p].y = get_idx(v[e][p].y);
		}
	}
	set<pair<int,pi> > s;
	for(int e=1;e<=c;e++){
		for(int p=0;p<sz(v[e]);p++){
			int ll = v[e][p].x,rr = v[e][p].y;
			if(sz(s)==0){
				s.insert(mk(ll,mk(rr,e)));
				continue;
			}
			set<pair<int,pi> >::iterator it = s.lower_bound(mk(ll+1,mk(-1,-1)));
			if(it!=s.begin()){
				it--;
				if(it->y.x<ll){
					it++;
				} 
			}
			if(it==s.end()){
				s.insert(mk(ll,mk(rr,e)));
				continue;
			}
			int lm = min(it->x,ll);
			for(;it!=s.end();){
				if(it->x>rr) break;
				int now = it->y.y;
				uf[find(now)] = e;
				rr = max(rr,it->y.x);
				s.erase(it++);
			}
			s.insert(mk(lm,mk(rr,e)));
		}
	}
	lld ans = 1;
	for(int e=1;e<=c;e++) if(find(e)==e) ans = (ans*m)%mod;
	int ll = 1;
	for(set<pair<int,pi> >::iterator it = s.begin();it!=s.end();it++){
		int lx = k[it->x];
		ans = (ans*calc(m,lx-ll))%mod;
		ll = k[it->y.x] + 1;
	}
	ans = (ans*calc(m,n+1-ll))%mod;
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