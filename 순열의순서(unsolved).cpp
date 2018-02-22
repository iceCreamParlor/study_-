#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> myvec;
int factorial(int n){
	return ( n==1 || n==0 )? 1: factorial(n-1)* n;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int num, cmd; scanf("%d %d", &num, &cmd); 
	int cnt= 0;
	if( cmd== 1 ){
		scanf("%d", &cnt);
		for( int i=1; i<= num; i++ ){
			myvec.push_back( i );
		}
		for( int i=0; i< cnt-1; i++ ){
			std::next_permutation( myvec.begin(), myvec.end() );
		}
		for( auto itr= myvec.begin(); itr!= myvec.end(); ++itr )
			printf("%d ", *itr);
	}
	else if( cmd== 2 ){
		for( int i= num; i> 0; i-- ){
			int temp; scanf("%d", &temp);
			cnt += (temp-1)* factorial(i-1);
		}
		
		printf("%d", cnt+1);
	}
	return 0;
}
