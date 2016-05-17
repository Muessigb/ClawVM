#include <stdio.h>
#include "vars.h"
#include "stack.h"
#include "maths.h"

// PC main
int main(int argc, char **argv)
{
    claw_pool_vcreate_n(20);
    claw_pool_vcreate_b(7);
    /*claw_ptr my_arr_addr1;
    claw_ptr my_arr_addr2;
    claw_pool_vget_a(0, &my_arr_addr1);
    claw_pool_vget_a(1, &my_arr_addr2);
    claw_pvar_n* my_arr1 = (claw_pvar_n*)(my_arr_addr1 + claw_pool);
    claw_pvar_b* my_arr2 = (claw_pvar_b*)(my_arr_addr2 + claw_pool);*/
    claw_pvar_n *my_arr1;
    claw_pvar_b *my_arr2;
    claw_pool_vget_na(0, &my_arr1);
    claw_pool_vget_ba(1, &my_arr2);
    my_arr1->data[5] = 42;
    my_arr2->data[3] = 37;
    claw_stack_push(989);
    claw_num sval1;
    claw_num sval2;
    claw_num sval3;
    claw_stack_peek(0, &sval1);
    claw_stack_pop(&sval2);
    claw_stack_push(15);
    claw_maths_icr();
    claw_stack_push(2);
    claw_maths_pow();
    claw_maths_sqrt();
    claw_maths_abs();
    claw_stack_push(26);
    claw_maths_add();
    claw_stack_push(28);
    claw_maths_sub();
    claw_stack_dup();
    claw_maths_mul();
    claw_stack_push(2);
    claw_maths_div();
    claw_maths_icr();
    claw_maths_dcr();
    claw_stack_push(10);
    claw_maths_rand();
    claw_maths_neg();
    claw_stack_push(45);
    claw_maths_sin();
    claw_maths_add();
    claw_maths_sub();
    claw_stack_push(12);
    claw_stack_push(21);
    claw_maths_add();
    claw_stack_pop(&sval3);
    
    printf("Size 1: %d\nSize 2: %d\nValue 1.5: %d\nValue 2.3: %d\nSValue 1: %d\nSValue 2: %d\nSValue 3: %d\n",
        //my_arr1.size, my_arr2.size, my_arr1.data[5], my_arr2.data[3], sval1, sval2, sval3);
        my_arr1->size, my_arr2->size, my_arr1->data[5], my_arr2->data[3], sval1, sval2, sval3);
        
    return 0;
}
