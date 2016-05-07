#include <stdio.h>
#include "vars.h"

// PC main
int main(int argc, char **argv)
{
    claw_pool_vcreate(25);
    claw_pvar* my_arr;
    my_arr = claw_pool_vget_a(0);
    printf("%d", my_arr->size);
    
	return 0;
}
