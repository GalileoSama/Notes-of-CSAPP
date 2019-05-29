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
/* 未验证
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    return !((x+0x55555555)+1);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~x+1;
}

//3
/* （收益匪浅）思想：利用相加的两个数会否溢出到符号位，来设定上下界（略抽象）。
 *  上界：高于上界的数与上界相机会溢出到符号位，使符号位y由0变为1；
 *  下界：低于下界的数与下界相加不会溢出到符号位，符号位本来就为1，不变。
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int sign = 1 << 31;
    int upperBound = ~(sign|0x39);
    int lowerBound = ~0x30;
    
  return 2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return 2;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
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