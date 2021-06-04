#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)

class TIEFighterAssembly{
	public:
		int assemble(string a){
			int f1 = 0,f2 = 0,f3 = 0;
			for(int e=0;e<sz(a);e++){
				if(a[e]=='|') f1++;
				if(a[e]=='0') f3++;
				if(a[e]=='-') f2++;
			}
			return min({f1/2,f2/2,f3});
		}
};
void solve(int tc){
	printf("%d\n",TIEFighterAssembly::assemble(string("||--O")));	
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}