#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
typedef pair<int,int> pi;
#define x first
#define y second

const int MAX = 10101;
const lld mod = 1e9 + 7;
class BlackAndWhiteTree{
public:
	long long x, pr;
	long long get_random() {
	    x = x % 1000000007;
	    long long temp = (x*x + pr) % 1000000007;
	    pr = x;
	    x = temp;
	    return x;
	}
	vector<int> v[MAX];
	pi dep[MAX];
	int n;
	int dfs(int x,int lx){
		dep[x] = mk(0,0);
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e];
			if(nx!=lx){
				int kk = dfs(nx,x) + 1;
				if(kk>dep[x].x){
					dep[x].y = dep[x].x;
					dep[x].x = kk;
				}else if(kk>dep[x].y){
					dep[x].y = kk;
				}
			}
		}
		return dep[x].x;
	}
	int dfs2(int x,int lx,int dist){
		int ans = 0;
		if(dep[x].x<=dist) ans = 1;
		for(int e=0;e<sz(v[x]);e++){
			int nx = v[x][e];
			if(nx!=lx){
				pi orgx = dep[x];
				pi orgy = dep[nx];
				if(dep[nx].x+1==dep[x].x){
					int nkk = dep[x].y + 1;
					if(nkk>dep[nx].x){
						dep[nx].y = dep[nx].x;
						dep[nx].x = nkk;
					}else if(nkk>dep[nx].y){
						dep[nx].y = nkk;
					}
				}else{
					int nkk = dep[x].x + 1;
					if(nkk>dep[nx].x){
						dep[nx].y = dep[nx].x;
						dep[nx].x = nkk;
					}else if(nkk>dep[nx].y){
						dep[nx].y = nkk;
					}
				}
				ans += dfs2(nx,x,dist);
				dep[x] = orgx;
				dep[nx] = orgy;
			}
		} 
		return ans;
	}
	bool can(int dist){
		dfs(1,-1);
		int tot = dfs2(1,-1,dist);
		if(tot>=(n/2)) return true;
		return false;
	}
	long long maxDistance(int T, int N, long long Seed){
	    x=Seed;
	    pr=0;
	    lld vv = 1;
	    this->n = N;
	    for(int test_case=1;test_case<=T;++test_case)
	    {
	        // start with an empty tree
	        for(int e=1;e<=N;e++){
	        	v[e].clear();
	        }
	        for(int i=1;i<N;++i)
	        {   
	            int co = (i+1)/2;
	            int v1 = i+1;
	            int v2 = i - co + (get_random()%co) + 1;
	            // add edge (v1, v2)
	            v[v1].push_back(v2);
	            v[v2].push_back(v1);
	        }
	        // solve the generated tree
	     	int ll = 1,rr = N,mid,ans = N + 1;
	     	while(ll<=rr){
	     		mid = (ll+rr)/2;
	     		if(can(mid)){
	     			ans = min(ans,mid);
	     			rr = mid - 1;
	     		}else ll = mid + 1;
	     	}
	     	cout << ans << "\n";
	     	vv = (vv*ans)%mod;
	    }
	    return vv;
	}
};


int main(void){
	BlackAndWhiteTree xx;
	printf("%lld\n",xx.maxDistance(20,10,12345));
}