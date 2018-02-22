#include <stdio.h>

using namespace std;
int year[3], cnt[3]; int result, check;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &year[0], &year[1], &year[2]);
	while(1){
		check= 0; cnt[0]++; cnt[1]++; cnt[2]++; result++;
		if( cnt[0]> 15 ) cnt[0]= 1;
		if( cnt[1]> 28 ) cnt[1]= 1;
		if( cnt[2]> 19 ) cnt[2]= 1;
		for( int i=0 ; i< 3; i++ )
			if( year[i] != cnt[i] ) check= 1;

		if( !check ) {
			printf("%d", result); break;
		}
	}
	return 0;
}
