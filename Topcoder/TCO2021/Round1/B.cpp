#include <string>
#define sz(x) (int)x.size()
using namespace std;


const int MAX = 111;
class EllysTwinLetters{
public:
	int dp[MAX][26][2];
	int getMin(string S){
		for(int e=0;e<MAX;e++){
			for(int p=0;p<26;p++){
				dp[e][p][0] = dp[e][p][1] = 1e9;
			}
		}
		for(int e=0;e<26;e++) dp[0][e][1] = 0;
		for(int e=1;e<=sz(S);e++){
			for(int p=0;p<26;p++){
				int cost = abs(S[e-1]-'A'-p);
				for(int q=0;q<26;q++){
					dp[e][p][0] = min(dp[e][p][0],dp[e-1][q][1]+cost);
					if(p==q&&e>1) dp[e][p][1] = min(dp[e][p][1],min(dp[e-1][q][0],dp[e-1][q][1])+cost);
				}
			}
		}
		int ans = 1e9;
		for(int e=0;e<26;e++) ans = min(ans,dp[sz(S)][e][1]);
		return ans;
	}
};

int main(void){
	EllysTwinLetters gh;
	string now = "FROMALLTHETHINGSIVELOSTMYMINDIMISSTHEMOST";
	printf("%d\n",gh.getMin(now));
}