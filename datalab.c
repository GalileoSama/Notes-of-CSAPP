#include <stdio.h>

//1
/*
 * 按位异或
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
//~(~(x&~(x&y))&~(y&~(x&y))) ==>（若可用用或门）~x&y+x&~y
    int t1 = ~(x&y);
    int t2 = x&t1;
    int t3 = ~t2;
    int t4 = t1&y;
    int t5 = ~t4;
    int t6 = t3&t5;
    int t7 = ~t6;
    return t7;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

    return 2;

}

int main() {
    int t = bitXor(4,5);

    return 0;
}