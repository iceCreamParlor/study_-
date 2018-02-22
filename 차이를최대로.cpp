#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> myvec; int result; int maxim;

int main()
{
	freopen("input.txt", "r", stdin);
	int num; scanf("%d", &num);
	int check[num];	
	for(int i=1; i<=num; i++){
		int temp; scanf("%d", &temp);
		myvec.push_back(temp);
	}
	sort(myvec.begin(), myvec.end());
	do{
		result= 0;	
		for( int i=0; i<num-1; i++ )
			result += abs( myvec[i]- myvec[i+1] );		
		if( maxim< result ) maxim= result;
	}	while( next_permutation(myvec.begin(), myvec.end()) );
	printf("%d", maxim);
	return 0;
}