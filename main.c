#include <stdio.h>
#include "vars.h"

// PC main
int main(int argc, char **argv)
{
    /*claw_pool_vcreate_l(10);
    claw_pool_vcreate_s(5);*/
    claw_pvar_l* my_arr1;
    claw_pvar_s* my_arr2;
    my_arr1 = claw_pool_vcreate_l(10); /*claw_pool_vget_la(0);*/
    my_arr2 = claw_pool_vcreate_s(5); /*claw_pool_vget_sa(1);*/
    my_arr1->data[5] = 420;
    my_arr2->data[3] = 37;
    printf("Size 1: %d\nSize 2: %d\nValue 1.5: %d\nValue 2.3: %d",
        my_arr1->size, my_arr2->size, my_arr1->data[5], my_arr2->data[3]);
    
    return 0;
}
