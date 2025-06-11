#include <stdio.h>

int main(){
	int i, m, n, tot, s[20];
	printf("ENTER MEOMERY\n");
	scanf("%d",&tot);
	printf("Enter no of processes\n Enter mem for OS");
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++){
		printf("SIZE OF PROCESS %d", i);
		scanf("%d", &s[i]);
	}
	tot = tot - m;
	for (i = 0; i < n; i++){
		if (tot >= s[i]){
			printf("ALloted memory to process %d\n", i);
			tot -= s[i];
		}
		else{
			printf("Proccess %d i sblsockeljd", i);
		}
	}
	printf("External fragmentation is %d\n", tot);

	return 0;
}	
