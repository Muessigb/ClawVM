#include <stdio.h>
#include "config.h"
#include "types.h"
#include "vars.h"
#include "stack.h"
#include "maths.h"

// PC main
int main(int argc, char **argv)
{
    claw_pool_vcreate_n(20);
    claw_pool_vcreate_b(7);
    
    claw_callback cbw, cbr;
    cbw.address = 21;
    cbw.function.id = 42;
    cbw.function.source = 3;
    
    claw_stack_push_c(&cbw);
    
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
    claw_maths(CLAW_MATHS_ICR);
    claw_stack_push(2);
    claw_maths(CLAW_MATHS_POW);
    claw_maths(CLAW_MATHS_SQRT);
    claw_maths(CLAW_MATHS_ABS);
    claw_stack_push(26);
    claw_maths(CLAW_MATHS_ADD);
    claw_stack_push(28);
    claw_maths(CLAW_MATHS_SUB);
    claw_stack_dup();
    claw_maths(CLAW_MATHS_MUL);
    claw_stack_push(2);
    claw_maths(CLAW_MATHS_DIV);
    claw_maths(CLAW_MATHS_ICR);
    claw_maths(CLAW_MATHS_DCR);
    claw_stack_push(10);
    claw_maths(CLAW_MATHS_RAND);
    claw_maths(CLAW_MATHS_NEG);
    claw_stack_push(45);
    claw_maths(CLAW_MATHS_COS);
    claw_maths(CLAW_MATHS_ADD);
    claw_maths(CLAW_MATHS_SUB);
    claw_stack_push(12);
    claw_stack_push(21);
    claw_maths(CLAW_MATHS_ADD);
    claw_stack_pop(&sval3);
    claw_stack_drp();
    
    claw_stack_pop_c(&cbr);
    
    printf("Size 1: %d\nSize 2: %d\nValue 1.5: %d\nValue 2.3: %d\nSValue 1: %d\nSValue 2: %d\nSValue 3: %d\nCallback Address: %d\nCallback Function~, Source ID: %d,%d\n",
        my_arr1->size, my_arr2->size, my_arr1->data[5], my_arr2->data[3], sval1, sval2, sval3, cbr.address, cbr.function.id, cbr.function.source);
        
    return 0;
}
