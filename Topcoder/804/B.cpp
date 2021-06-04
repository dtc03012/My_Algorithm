#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
typedef long long int lld;

const int MAX = 20;
const lld mod = 1e9 + 7;
class UnluckyNumber{
public:
	int n,m,k,z;
	vector<int> v[MAX];
	int vis[MAX][MAX];
	lld dp[MAX];
	UnluckyNumber(){
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
	}
	int numberOfColourings(int n, int m, int k, int z, vector <int> x, vector <int> y){
		for(int e=0;e<m;e++){
			int f1 = x[e] - 1;
			int f2 = y[e] - 1;
			vis[f1][f2] = 1;
			vis[f2][f1] = 1;
			v[f1].push_back(f2);
			v[f2].push_back(f1);
		}
		this->n = n;
		this->m = m;
		this->k = k;
		this->z = z;
		return (int)solve();
	}
	lld solve(){
		dp[0] = 1;
		for(int e=1;e<MAX;e++) dp[e] = (dp[e-1]*k)%mod;
		lld ans = dp[n];
		for(int e=1;e<(1<<n);e++){
			vector<int> k;
			for(int p=0;p<n;p++){
				if(e&(1<<p)) k.push_back(p);
			}
			int tot = 0;
			for(int p=0;p<sz(k);p++){
				for(int q=p+1;q<sz(k);q++){
					tot += vis[k[p]][k[q]];
				}
			}
			if(tot){
				if(tot%2==0){
					ans = (ans+dp[n-sz(k)])%mod;
				}else{
					ans = (ans-dp[n-sz(k)]+mod)%mod;
				}
			}
		}
		return ans;
	}
};

int main(void){
	UnluckyNumber xx;
	vector<int> x,y;
	printf("%d\n",xx.numberOfColourings(5,0,5,2,x,y));
}