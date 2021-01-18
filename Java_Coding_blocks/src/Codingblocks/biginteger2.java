/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Codingblocks;

/**
 *
 * @author Akash Verma
 */
/* big integer class in java | powerful lot of inbuilt function
1. Modular fuction
2. GCD
3. Base conversion
4. Power calculation
5. Prime generation
and more
*/
import java.util.*;
import java.math.BigInteger;
public class biginteger2 {
    static void playWithBigInt()
    {
        Scanner sc = new Scanner(System.in);
        String s1= sc.next();
        BigInteger b1 =  new BigInteger(s1);
        BigInteger b2 =  new BigInteger("123456754321456345675432");
        b1 = b1.add(b2); //multiply for *
        System.out.println(b2);
        
        //Bits counts - total set bits;
        
        System.out.println(b1.bitCount());
        //total number of bits
        System.out.println(b1.bitLength());
        
        //integer to big int
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(a+b);
        
        BigInteger b3 = BigInteger.valueOf(a);
        BigInteger b4 = BigInteger.valueOf(b);
        
        //print gcd
        System.out.println(b3.gcd(b4));
        
        //base conversion
        BigInteger b5 = new BigInteger("1001",2); //return 13
        System.out.println(b5);
        
        //power of number
        System.out.println(b3.pow(a));
    }
    
    static BigInteger fact(int N)
    {
        BigInteger b = new BigInteger("1");
        for(int i=2;i<=N;i++)
        {
            b = b.multiply(BigInteger.valueOf(i));
        }
        return b;
    }
    public static void main(String args[])
    {
        playWithBigInt();
        BigInteger ans=fact(129);
        System.out.println(ans);
    }
    
}
