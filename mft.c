#include <stdio.h>
int main(){
	int totM,noPart, osM, intRem = 0;
	printf("ENTER TOTAL MEM AND NO OF PARTITIONS AND OSM TOO\n");
	scanf("%d %d %d", &totM, &noPart, &osM);
	totM -= osM;
	int sizePart = totM/noPart;
	for (int i = 0; i < noPart; i++){
		printf("ENTER PROCESS NO AND SIZE\n");
		int pNO, size;
		scanf("%d %d" &pNO, &size);
		if (size < sizePart){
			printf("process is allocated mem %d", i);
			intRem+=size;
		}
		else{
			printf("PROCESS BLAOCKED %d", i);
		}
	}
	printf("INTERNAL FRAG %d", intRem);
}
