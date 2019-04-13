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
 *   解：利用以下性质：
 *   1、Tmax+1=Tmin,
 *   2、Tmin+Tmin会溢出最高位，得到0；
 *   3、再取逻辑非即可得到1.
 *   但是有一个问题即，除了输入Tmax,输入-1也会最终返回1.因此需要区分它们。
 *   它们的区别在于Tmax+1=Tmin，还需要Tmin+Tmin才转换为0，而-1+1直接等于0了。
 *   因此再逻辑与上x + 1 != 0,输入-1输出为0，而输入Tmax输出为1.
 */
int isTmax(int x) {
    int a = x +1;
    int b = a+a;
    int c = !b;
//    疑问：为何df,t1返回1，t2返回0？（似乎和优先级有关）
//    int d = (x + 1) + (x + 1);
//    int df = !d;
//    int t1 =!(x+1+x+1);
//    int t3 =!((x+1)+(x+1));
    int t2 = x + 1 != 0;
    return c&t2;
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
    int tmax = INT_MAX;
    int tmin = INT_MIN;
    int t= isTmax(tmax);
    return 0;
}