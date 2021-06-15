#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;
class ContainsItsAverage{
public:
	vector <int> missing(vector <int> seq){
		vector<int> res;
		int len = (int)seq.size();
		lld tot = 0;
		for(int e=0;e<len;e++) tot += seq[e];
		for(int e=0;e<len;e++){
			lld xx = 1ll * seq[e] * (len + 1) - tot;
			res.push_back(int(xx));
		}
		if(tot%len==0) res.push_back(tot/len);
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		return res;
	}
};

int main(){
	ContainsItsAverage gh;
	vector<int> v = {500000, 400000, 200000, 100000};
	vector<int> res = gh.missing(v);
	for(int e=0;e<(int)res.size();e++) cout << res[e] << "\n";
}