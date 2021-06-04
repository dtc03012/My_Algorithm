#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()



class HIndex{
public:
	int cheat(vector <int> realCitations, int budget, int citationPrice){
		int can = budget/citationPrice;
		sort(all(realCitations));
		int ll = 0,rr = 1e9,mid,ans = 0;
		while(ll<=rr){
			mid = (ll+rr)/2;
			if(solve(mid,realCitations,can)){
				ans = max(ans,mid);
				ll = mid + 1;
			}else rr = mid - 1;
		}
		return ans;
	}
	bool solve(int mid,vector<int>& realCitations,int can){
		int tot = 0;
		for(int e=sz(realCitations)-1;e>=0;e--){
			if(realCitations[e]>=mid){
				tot++;
				continue;
			}
			int diff = mid - realCitations[e];
			if(can>=diff){
				can -= diff;
				tot++;
			}else break;
		}
		if(tot>=mid) return true;
		return false;
	}
};

int main(void){
	HIndex a;
	vector<int> v = {25, 3, 5, 3, 8, 0};
	printf("%d\n",a.cheat(v,1447,1000));
}