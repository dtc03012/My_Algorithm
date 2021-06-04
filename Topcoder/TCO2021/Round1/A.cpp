#include <string>
#define sz(x) (int)x.size()
using namespace std;


const int MAX = 111;
const int MID = 111;
class EllysBalancedStrings{
public:
	int dp[MAX][26][MAX*2];
	int getMin(string S){
		for(int e=0;e<MAX;e++){
			for(int p=0;p<26;p++){
				for(int q=0;q<MAX*2;q++){
					dp[e][p][q] = 1e9;
				}
			}
		}
		for(int e=0;e<26;e++) dp[0][e][MID] = 0;
		for(int e=1;e<=sz(S);e++){
			for(int q=0;q<26;q++){
				char xx = q + 'A';
				int cost = abs(S[e-1]-'A'-q);
				if(xx=='A'||xx=='E'||xx=='I'||xx=='O'||xx=='U'){
					for(int r=0;r<MAX*2;r++){
						for(int t=0;t<26;t++){
							dp[e][q][r+1] = min(dp[e][q][r+1],dp[e-1][t][r]+cost);
						}
					}
				}else{
					for(int r=1;r<MAX*2;r++){
						for(int t=0;t<26;t++){
							dp[e][q][r-1] = min(dp[e][q][r-1],dp[e-1][t][r]+cost);
						}
					}
				}
			}
		}
		int ans = 1e9;
		for(int e=0;e<26;e++) ans = min(ans,dp[sz(S)][e][MID]);
		return ans;
	}
};

int main(void){
	EllysBalancedStrings xx;
	string now = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%d\n",xx.getMin(now));
}