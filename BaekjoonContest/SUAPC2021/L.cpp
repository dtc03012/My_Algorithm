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

const int MAX = 2020;
string arr[MAX];
set<pi> row[MAX],col[MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		cin >> arr[e];
		for(int p=0;p<n;p++){
			if(arr[e][p]=='X'){
				row[e].insert(mk(p,0));
				col[p].insert(mk(e,0));
			}else if(arr[e][p]=='O'){
				row[e].insert(mk(p,1));
				col[p].insert(mk(e,1));
			}
		}
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			if(arr[e][p]=='.'){
				bool suc = true;
				if(sz(row[e])){
					set<pi>::iterator it1 = row[e].lower_bound(mk(p,-1));
					if(it1==row[e].end()){
						it1--;
						if(it1->y==1) suc = false;
						it1++;
					}else{
						if(it1->y==1) suc = false;
						if(it1!=row[e].begin()){
							it1--;
							if(it1->y==1) suc = false;
							it1++;
						}
					}
				}
				if(sz(col[p])){
					set<pi>::iterator it1 = col[p].lower_bound(mk(e,-1));
					if(it1==col[p].end()){
						it1--;
						if(it1->y==1) suc = false;
						it1++;
					}else{
						if(it1->y==1) suc = false;
						if(it1!=col[p].begin()){
							it1--;
							if(it1->y==1) suc = false;
							it1++;
						}
					}
				}
				if(suc) arr[e][p] = 'B';
			}
		}
	}
	for(int e=0;e<n;e++) cout << arr[e] << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}