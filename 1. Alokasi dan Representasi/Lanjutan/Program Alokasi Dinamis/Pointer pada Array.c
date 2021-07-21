/*F.S :
 *saat *(ptr+i)
 *my_arr[0] = 1 ptr + 0 = 1
 *my_arr[1] = 23 ptr + 1 = 23
 *my_arr[2] = 17 ptr + 2 = 17
 *my_arr[3] = 4 ptr + 3 = 4
 *my_arr[4] = -5 ptr + 4 = -5
 *my_arr[5] = 100 ptr + 5 = 100
 *
 *saat *ptr++
 *my_arr[0] = 1 ptr + 0 = 1
 *my_arr[1] = 23 ptr + 1 = 23
 *my_arr[2] = 17 ptr + 2 = 17
 *my_arr[3] = 4 ptr + 3 = 4
 *my_arr[4] = -5 ptr + 4 = -5
 *my_arr[5] = 100 ptr + 5 = 100
 *
 *saat *(++ptr)
 *my_arr[0] = 1 ptr + 0 = 23
 *my_arr[1] = 23 ptr + 1 = 17
 *my_arr[2] = 17 ptr + 2 = 4
 *my_arr[3] = 4 ptr + 3 = -5
 *my_arr[4] = -5 ptr + 4 = 100
 *my_arr[5] = 100 ptr + 5 = 113  //pindah alamat, alamatnya berisi nilai 113
 */

#include <stdio.h>

int main()
{
    int my_arr[] = {1,23,17,4,-5,100};
    int *ptr;

    int i;
    ptr = &my_arr[0];
    for(i = 0; i < 6; i++){
        printf("my_arr[%d] = %d ",i,my_arr[i]);
        printf("ptr + %d = %d\n",i,*(++ptr)); // coba ubah jadi *ptr++ dan *(++ptr) dan *(ptr+i)

    }
    return 0;
}
