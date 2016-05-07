#include <stdio.h>
#include "vars.h"

// PC main
int main(int argc, char **argv)
{
    claw_pool_vcreate(26);
    claw_pvar_l* my_arr;
    my_arr = claw_pool_vget_lr(0);
    my_arr->data[5] = 420;
    printf("%d\n%d", my_arr->size, my_arr->data[5]);
    
	return 0;
}
