/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and user id here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	return ~(~x|~y); //套用逻辑公式 
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	return (x>>(n<<3))&0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  	return (x>>n)&(~(((1<<31)>>n)<<1));
	//return (x>>n)&((x<<(30-n))+~0); // (~(((1<<31)>>n)<<1)) 和 ((x<<(30-n))+~0) 效果相同
	//其中(~(((1<<31)>>n)<<1))操作是为获得00...0111..1的序列，前n位为0
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  	int temp=(((1<<8)|1)<<8|1)<<8|1;//00000001 00000001 00000001 00000001 00000001. 一个字节一组
	int val=x&temp; 		//每个字节的第一位
	val+=val+(x>>1)&temp;		//每个字节的第二位
	val+=val+(x>>2)&temp;
	val+=val+(x>>3)&temp;
	val+=val+(x>>4)&temp;
	val+=val+(x>>5)&temp;
	val+=val+(x>>6)&temp;
	val+=val+(x>>7)&temp;
	val=val+val>>16;
	val=val+val>>8;
	return val&0xff;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return ~(((~x+1)|x)>>31)&1;			//法1
	/*	1、当x == 0 的时候，(~x+1)|x == 00...0。全部为0.
		2、当x != 0 的时候，~x+1 和 x 中必定有一个数的最高位为1。
		x的最高位为0时，不确定x是否等于0，但是当x!=0时一定有：
		(~x+1)的最高位为1，因为取反加1不可能让非零的x得到最高位0.*/
  	//当x == 0 的时候，(~x+1)|x == 00...0。
  	//当x != 0 d的时候，~x+1 和 x 中至少有一个数的最高位不为0；
	//x的最高位为1时，题目显然成立
	//x的最高位为0时，不确定x是否等于0，但是当x!=0时一定有：(~x+1)的最高位为1，因为取反加1不可能让非零的x得到最高位0.
  return (~(((x>>31)&1)|(((~x+1)>>31)&1)))&1;	//法2
  
  int negMask = (x>>31)&1;
  int posMask = ((~x+1)>>31)&1;
  return (~(negMask|posMask))&1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int mask = (~0)<<(n+(~0));	//1111..1000..0，后面是n-1个0，（作为检测是否越界的工具）
  int a = x&mask;		//if x is negative,use !(a^mask) confirm true or not. 判断负数是否越界	
  int b = ~x&mask;		//if x is positive,use !(b^mask) confirm true or not. 判断正数是否越界
  return (!(a^mask))|(!(b^mask));	//没有发生越界的话，返回为真
					//理由如下：
					//1、!(a^mask)==1的话，负数端未越界，!(a^mask)==1等价于a==mask.
					//2、!(b^mask)==1的话，正数端未越界，!(b^mask)==1等价于b==mask.
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero //主要解决此问题
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int s = x>>31;		//如果 x 是负数的话，s=0xffffffff; 否则 s = 0x00000000;
    int mask = (1<<n)+~0;	//000...0100...0,后面有n个0；
				//再将其减去1 “(+(-1)的方式达到减一的目的)” 得到：000...011..1,后面有n个1.
    int neg_fix = s&mask;	//计算偏移值,正数偏移值为0，负数偏移值为 000...011...1,后面有n个1。
    return (x+neg_fix)>>n;	
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
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return (~((x>>31)&1))|!x;
  //(~((x>>31)&1))用来判断正数，!x用来判断0
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int sx = (x>>31)&1;
  int sy = (y>>31)&1;
  int p = (!(sx^sy))&((x+(~y))>>31);	//通过最低一位bit来作为判断依据
  return (sx&!sy)|p;
  //当 x<0&&y>=0 时，用(sx&!sy)来判断。
  //当 x,y 同号的时候，用 p = ((x+(~y))>>31)&(!(sx^sy)); 来判断。
	//理由如下：
	//1、!(sx^sy) 用来限定 x 和 y 同号；同号的话 !(sx^sy) ==1.
	//2、(x+(~y))>>31 用来检验 x-y+1 是不是负数，是负数的话 y>=x;成立
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
//解决此题就是，找出x的二进制表示中的最高位的1所在的位置。
int ilog2(int x) {
  int val=0; 
  val=(!!(x>>16))<<4;  			//检测x的前16位是否存在‘1’.存在：val = 16; 否则 val = 0; 将二进制序列分割成两半。
  val=val+((!!(x>>(val+8)))<<3);	//根据上一步，如果前16位存在‘1’，则判断前8位是否存在‘1’，存在的话，val = val + 8;
					//否则 val = val + 0;
  val=val+((!!(x>>(val+4)))<<2);  
  val=val+((!!(x>>(val+2)))<<1);  
  val=val+(!!(x>>(val+1)));  
  val=val+(!!val)+(~0)+(!(1^x));  
  return val; 
  
  /*int mask0 = ~((1<<16)-1);
  int val = 0;
  int mask1,mask2,mask3,mask4;
  val = (!!(x&mask))<<4;
  val = val+*/
  
  
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int frac = 0x007fffff&uf;		//取Frac部分
  int exp = 0x7f800000&uf;		//用来判断阶码部分是否全为1
  if((exp==0x7f800000)&&frac）		//如果阶码全为1，且尾数部分全为0，返回uf.
	return uf;
  else return uf^0x80000000; 		//否则的话返回 -uf.
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int s = x&0x80000000;
  int exp = 0, i = 0, frac;
  int temp = x;
  int shiftLeft, isCarryOut, mask, tmask;
  int flag = 0;
  if(!x) return 0;				//如果x等于0，返回0.
  if(x == 0x80000000) return 0xcf000000;	//不对称，所以单独考虑最小得负数
  if(s) temp = -x;				//当x为负数的时候，用其相反数来求指数的值。
  while(i<31){					//循环求指数的大小
	if((temp>>i)&1) exp = i;
	i++;
  }
  if(exp<=23){ frac = (temp<<(23-exp))&0x007fffff; }	//如果指数小于等于23，则尾数部分可以通过，|x|左移来得到.
  else{	//指数大于23
	shiftLeft = exp-23;			//左移的位数
	mask = (1<<shiftLeft)-1;		//用作保存被舍去的数位。000...0111...1
	tmask = 1<<(shiftLeft-1);		//用作和被舍去的数位进行比较，决定如何舍入。000...0100...0
	isCarryOut = mask&temp;			//判断是否要进位。保存舍去的数位。
	frac = (temp>>shiftLeft)&0x007fffff;	//尾数部分。
	if((isCarryOut > tmask)||((frac&1)&&(isCarryOut == tmask))){
		flag = 1;			//符合舍入规则，令flag等于0.
	}
  }
  return s+((exp+127)<<23)+frac+flag;		//组装返回值.
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int s, exp;
  s = uf&0x80000000;			//符号位
  exp = uf&0x7f800000;			//指数部分
  if(exp==0x7f800000) return uf;	//NaN时，返回原值
  else
	if(exp!=0) return uf+0x00800000; //指数部分不为0时，指数部分加1
  return s+((uf&0x007fffff)<<1);	 //指数部分为0时，尾数部分左移1位
}
