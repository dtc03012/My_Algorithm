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

const int MAX = 202020;
int cnt[MAX],vis1[MAX],vis2[MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<=n;e++){
		cnt[e] = 0;
		vis1[e] = 0;
		vis2[e] = 0;
	}
	set<int> s1,s2;
	for(int e=1;e<=n;e++){
		s1.insert(e);
		s2.insert(e);
	}
	int ll = -1,lst = -1;
	for(int e=0;e<n;e++){
		int r;
		cin >> r;
		if(r!=ll){
			if(lst==-1){
				lst = 0;
				ll = r;
				continue;
			}
			vis1[lst] = ll;
			vis2[lst] = ll;
			s1.erase(ll);
			s2.erase(ll);
			set<int>::iterator it1 = s1.begin();
			set<int>::iterator it2 = s2.lower_bound(ll);
			it2--;
			for(int p=lst+1;p<e;p++){
				vis1[p] = *it1;
				s1.erase(it1++);
			}
			for(int p=lst+1;p<e;p++){
				vis2[p] = *it2;
				s2.erase(it2--);
			}
			lst = e;
			ll = r;
		}
	}
	vis1[lst] = ll;
	vis2[lst] = ll;
	s1.erase(ll);
	s2.erase(ll);
	if(sz(s1)){
		set<int>::iterator it1 = s1.begin();
		set<int>::iterator it2 = s2.lower_bound(ll);
		it2--; 
		for(int p=lst+1;p<n;p++){
			vis1[p] = *it1;
			s1.erase(it1++);
		}
		for(int p=lst+1;p<n;p++){
			vis2[p] = *it2;
			if(it2==s2.begin()) break;
			s2.erase(it2--);
		}
	}
	for(int e=0;e<n;e++) cout << vis1[e] << " ";
	cout << "\n";
	for(int e=0;e<n;e++) cout << vis2[e] << " ";
	cout << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}