#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10001

using namespace std;
vector<int> myvec;
int main()
{
	freopen("input.txt", "r", stdin);
	int num;
	scanf("%d", &num);
	for(int i=0 ; i< num ; i++){
		int temp; scanf("%d", &temp);
		myvec.push_back(temp);
	}
	if( next_permutation(myvec.begin(), myvec.end()) )
		for (auto itr= myvec.begin(); itr!= myvec.end(); ++itr)
			printf("%d ", *itr);
	else printf("-1");	
	return 0;
}
