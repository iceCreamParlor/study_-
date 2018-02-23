#include <stdio.h>
#include <vector>
#include <algorithm>



int main()
{
	freopen("input.txt", "r", stdin);
	
	int num=1;
	
	while( num ){
		std::vector<int> myvec;
		scanf("%d", &num);
		for(int i=0; i<num; i++){
			int temp; scanf("%d", &temp);
			myvec.push_back(temp);
		}
		for(int i=0; i<num-5; i++){
			for(int i2=i+1; i2< num-4; i2++){
				for(int i3=i2+1; i3< num-3; i3++){
					for(int i4=i3+1; i4< num-2; i4++){
						for(int i5=i4+1; i5< num-1; i5++){
							for(int i6=i5+1; i6< num; i6++){
								printf("%d ", myvec[i]);
								printf("%d ", myvec[i2]);
								printf("%d ", myvec[i3]);
								printf("%d ", myvec[i4]);
								printf("%d ", myvec[i5]);
								printf("%d ", myvec[i6]);
								printf("\n");
							}
						}
					}
				}		
			}
		}
		printf("\n");
	}
	return 0;
}
