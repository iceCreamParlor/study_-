#include <stdio.h>
#include <vector>
#include <algorithm>
std::vector<int> myvec;
int main()
{
	freopen("input.txt", "r", stdin);
	int num; scanf("%d", &num);
	for(int i=1; i<= num; i++)
		myvec.push_back(i);
	do{
		for( auto itr= myvec.begin(); itr!= myvec.end(); ++itr )
			printf("%d ", *itr);
		printf("\n");
	}while( std::next_permutation(myvec.begin(), myvec.end()) );
	return 0;
}
