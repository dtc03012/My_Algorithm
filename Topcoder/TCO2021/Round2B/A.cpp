#include <bits/stdc++.h>


using namespace std;
typedef long long int lld;


const int MAX = 18;
class AlternateOddEven{
public:
	lld dp[MAX][10],dp2[MAX];
	lld can(lld x){
		if(x<10) return x;
		vector<int> k;
		while(x){
			k.push_back(x%10);
			x /= 10;
		}
		lld tot = 0;
		int ll = -1;
		for(int e=(int)k.size()-1;e>=0;e--){
			if(ll==-1){
				tot += dp2[e];
				for(int p=1;p<k[e];p++) tot += dp[e+1][p];
			}else{
				if(k[e]==0){
					if((ll%2)==0) break;
				}
				if(e==0){
					for(int p=0;p<=k[e];p++){
						if((ll%2)!=(p%2)) tot++;
					}
				}else{
					for(int p=0;p<k[e];p++){
						if((ll%2)!=(p%2)){
							tot += dp[e+1][p];
						}
					}
					if((ll%2)==(k[e]%2)) break;
				}
			}
			ll = k[e];
		}
		return tot;
	}
	void init(){
		memset(dp2,0,sizeof(dp2));
		memset(dp,0,sizeof(dp));
		for(int e=0;e<=9;e++) dp[1][e] = 1;
		dp2[1] = 9;
		for(int e=2;e<MAX;e++){
			dp2[e] = dp2[e-1];
			for(int p=0;p<10;p++){
				for(int q=0;q<10;q++){
					if((q%2)!=(p%2)){
						dp[e][p] += dp[e-1][q];
					}
				}
				if(p) dp2[e] += dp[e][p];
			}
		}
	}
	long long kth(long long K){
		init();
		lld ll = 0,rr = 1e17,mid,ans = 1e17;
		while(ll<=rr){
			mid = (ll+rr)/2;
			if(can(mid)>=K){
				ans = min(ans,mid);
				rr = mid - 1;
			}else ll = mid + 1;
		}
		return ans;
	}
};


int main(void){
	AlternateOddEven xx;
	cout << xx.kth(600000000000) << "\n";
}