#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)x.size()

int cnt[26];
class Pancakes{
public:
	vector<string> makePancakes(int N, int P){
		int st = 0,cut = 0;
		vector<string> ans;
		while(cut<N){
			int vis[26];
			memset(vis,0,sizeof(vis));
			string xx = "";
			for(int p=0;p<P;p++){
				if(cnt[st]==0&&vis[st]==0){
					xx += char(st+'A');
					cnt[st]++;
					vis[st]++;
				}
				else if(cnt[st]==1&&vis[st]==0){ 
					xx += char(st+'a');
					cnt[st]++;
					vis[st]++;
					cut++;
				}
				else xx += char('-');
				st = (st+1)%N;
			}
			ans.push_back(xx);
		}
		return ans;
	}
};

int main(void){
	Pancakes gh;
	vector<string> vv = gh.makePancakes(5,4);
	for(int e=0;e<sz(vv);e++) cout << vv[e] << "\n";
}