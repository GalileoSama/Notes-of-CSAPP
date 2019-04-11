#include <stdio.h>
#include <limits.h>

//1
/*
 * 按位异或
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 *   解：~(~(x&~(x&y))&~(y&~(x&y))) ==>（若可用用或门）~x&y+x&~y
 */
int bitXor(int x, int y) {
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
 *   解：tmin为1000···000,共32位，1个1，31个0；故将 000···01的1左移31位即可。
 */
int tmin() {
    return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    return ~((x+1)+(x+1))&~(x+1);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    return 2;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return 2;
}
/**test**/
int main() {
//    int t = bitXor(4,5);
    int tmi = !((INT_MAX+1)+(INT_MAX+1));
    int tmax = INT_MAX +1;
    int tmin = INT_MIN;
    int t= isTmax(tmax);
    return 0;
}