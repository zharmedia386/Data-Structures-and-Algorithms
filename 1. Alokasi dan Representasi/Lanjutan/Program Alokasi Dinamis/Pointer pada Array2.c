/*F.S :
 *pada alamat 6487552, nilai yang ditunjuk p adalah 10
 *pada alamat 6487556, nilai yang ditunjuk p adalah 11
 *pada alamat 6487560, nilai yang ditunjuk p adalah 12
 */

#include<stdio.h>

int main(){
	int arr[] = {10,11,12};
	int *p = arr;

	int i;
	for(i = 0; i < 4; i++){
		printf("%d\n",*p++);
	}
	return 0;
}
