#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

set<int> arr[2];
vector<vector<int> > ans;
vector<int> tmp;
void solve(int tc){
	string a;
	cin >> a;
	if(a[0]=='1'){
		printf("-1\n");
	}else{
		for(int e=0;e<sz(a);e++) arr[a[e]-'0'].insert(e);
		bool suc = true;
		while(true){
			if(sz(arr[0])==0&&sz(arr[1])==0) break;
			if(sz(arr[0])==0){
				suc = false;
				break;
			}
			tmp.clear();
			set<int>::iterator it = arr[0].begin();
			tmp.push_back(*it);
			int xx = *it;
			arr[0].erase(it);
			while(sz(arr[0])&&sz(arr[1])){
				set<int>::iterator it1 = arr[1].lower_bound(xx);
				if(it1==arr[1].end()) break;
				set<int>::iterator it2 = arr[0].lower_bound(*it1);
				if(it2==arr[0].end()) break;
				tmp.push_back(*it1);
				tmp.push_back(*it2);
				xx = *it2;
				arr[1].erase(it1);
				arr[0].erase(it2); 
			}
			ans.push_back(tmp);
		}
		if(!suc){
			printf("-1\n");
		}else{
			printf("%d\n",sz(ans));
			for(int e=0;e<sz(ans);e++){
				printf("%d ",sz(ans[e]));
				for(int p=0;p<sz(ans[e]);p++) printf("%d ",ans[e][p]+1);
				printf("\n");
			}
		}
	}
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