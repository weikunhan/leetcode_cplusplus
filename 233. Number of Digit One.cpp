 /**
 * Calculate occurance on every digit, from
 * least important digit to most important digit
 * number = 1432
 * One's digit: n/10=143 143*1+1
 * Ten's digit: n/100=14 14*10+10
 * Hun's digit: n/1000=1 1*100+100
 * Tho's digit: 1432%1000+1=433
 * Sum all occurance on digits together
 
 For people who may not get the idea at the beginning (like me).

One's digit: 143 * 1 + 1 => (11, 21, 31, ... 1431) + 1
Ten's digit: 14* 10 + 10 => (110, 111, 112, ... 119, 210, 211, 212, .... 219, ....1419) + (10, 11, 12, ...19)
Hundreds's digit: 1*100 + 100 => (1100, 1101, 1102, ...1199) + (100, 101,.... 199)
Thousands's digit: 1432%100 + 1 => 1000, 1001, ... 1432
 */
public static int countDigitOne(int k) {
    int count = 0, factor = 1, n = k;
    while(n>0){
    	int m = n/10, r = n%10, amount;
    	
    	if(r == 0) amount = 0;
    	else if(r > 1) amount = factor;
    	else amount = k%factor+1;
 
    	count += m*factor + amount;
    	factor *= 10;
    	n = n/10;
    }
    return count;
}
