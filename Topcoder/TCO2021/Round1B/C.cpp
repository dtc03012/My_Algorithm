#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

const int MAX = 222;
const lld mod = 1e9 + 7;
lld dp[MAX][MAX][MAX],row[MAX][MAX][MAX],col[MAX][MAX][MAX],d1[MAX][MAX][MAX],d2[MAX][MAX][MAX];
class Antiqueen{
public:
	void init(int k,int n,int m){
		for(int e=1;e<=n;e++){
			lld f1 = 0;
			for(int p=1;p<=m;p++) f1 += dp[e][p][k];
			f1 %= mod;
			for(int p=1;p<=m;p++) row[e][p][k] = f1;
		}
		for(int p=1;p<=m;p++){
			lld f1 = 0;
			for(int e=1;e<=n;e++) f1 += dp[e][p][k];
			f1 %= mod;
			for(int e=1;e<=n;e++) col[e][p][k] = f1;
		}
		{
			int x = m,y = 1;
			while(y<=n){
				lld f1 = 0;
				for(int e=y,p=x;e<=n&&p<=m;e++,p++){
					f1 += dp[e][p][k];
				}
				f1 %= mod;
				for(int e=y,p=x;e<=n&&p<=m;e++,p++){
					d1[e][p][k] = f1;
				}
				if(x==1) y++;
				else x--;
			}
		}
		{
			int x = 1,y = 1;
			while(y<=n){
				lld f1 = 0;
				for(int e=y,p=x;e<=n&&p>=1;e++,p--){
					f1 += dp[e][p][k];
				}
				f1 %= mod;
				for(int e=y,p=x;e<=n&&p>=1;e++,p--){
					d2[e][p][k] = f1;
				}
				if(x==m) y++;
				else x++;
			}
		}
	}
	int countPaths(int R, int C, int N){
		int n = R;
		int m = C;
		int k = N;
		lld tot = n * m;
		for(int e=1;e<=n;e++){
			for(int p=1;p<=m;p++){
				dp[e][p][0] = 1;
			}
		}
		init(0,n,m); 
		for(int t=1;t<=k;t++){
			lld ntot = 0;
			for(int e=1;e<=n;e++){
				for(int p=1;p<=m;p++){
					lld vv = tot;
					vv -= row[e][p][t-1];
					vv -= col[e][p][t-1];
					vv -= d1[e][p][t-1];
					vv -= d2[e][p][t-1];
					vv += dp[e][p][t-1]*3;
					vv = (vv%mod+mod)%mod;
					dp[e][p][t] = vv;
					ntot = (ntot+vv)%mod;
				}
			}
			tot = ntot;
			init(t,n,m);
		}
		lld ans = 0;
		for(int e=1;e<=n;e++){
			for(int p=1;p<=m;p++){
				ans = (ans+dp[e][p][k])%mod;
			}
		}
		return (int)ans;
	}
};

int main(void){
	Antiqueen gh;
	printf("%d\n",gh.countPaths(2,4,100));
}