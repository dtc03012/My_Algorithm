#include "stone.h"
#include <vector>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#define all(v) v.begin(), v.end()
using namespace std;
std::vector<int> find_stone(int N){
    /// write your code here
    std::random_device rd;
    std::default_random_engine rng(rd());
    vector<int> loc;
    vector<int> xx;
    for(int e=-1;e>=-3;e--) xx.push_back(e);
    for(int e=1;e<=N;e++){
    	shuffle(all(xx),rng);
		vector<int> k;
		k.push_back(xx[0]);
		k.push_back(xx[1]);
		k.push_back(xx[2]);
		k.push_back(e);
		int rr = investigate(k); // 1
		if(rr==4){
			vector<int> k;
			k.push_back(-4);
			k.push_back(e);
			int rr = investigate(k); // 2
			if(rr==1) loc.push_back(4);
			else loc.push_back(5);
		}else{
			vector<int> k;
			k.push_back(xx[0]);
			k.push_back(xx[1]);
			k.push_back(e);
			int rr = investigate(k); // 2
			if(rr==3){
				loc.push_back(-xx[2]);
			}else{
				vector<int> k;
				k.push_back(xx[0]);
				k.push_back(e);
				int rr = investigate(k); // 3
				if(rr==1) loc.push_back(-xx[0]);
				else loc.push_back(-xx[1]);
			}
		}
    }
    return loc;
}
