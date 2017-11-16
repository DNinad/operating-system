#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	
	FILE *fp;
	int line_num = 1,count=0;
	int find_result = 0;
	char temp[512];
	
	//gcc users
	if((fp = fopen("1.txt", "r")) == NULL) {
		return(-1);
	}

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, "hii")) != NULL) {

			count++;
			printf("A match found on line: %d\n", line_num);
			find_result++;
		}
		line_num++;
		
	}
	printf("count %d\n", count);
	if(find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return(0);
}
