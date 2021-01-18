/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Codingblocks;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Akash Verma
 */
public class bigInteger {
    
    
    static void fact(int N)
    {
       BigInteger b = new BigInteger("1");
       for(int i =2 ; i<=N;i++)
       {
           b=b.multiply(BigInteger.valueOf(i));
       }
       System.out.println(b);
    }
    static void playWithInt()
    {
        Scanner sc  = new Scanner(System.in);
        int s1=sc.nextInt();
        System.out.println(s1*s1);
        
        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("1234567891234");
        System.out.println(one.add(two));
        
        // read string as a big integer
        String s2 = sc.next();
        String s3 = sc.next();
        BigInteger three =  new BigInteger(s2);
        BigInteger p4  = new BigInteger(s3);
        System.out.println(three.multiply(p4));
        
        // take any base input 2 for binary 8 for octal 16 for hexa
        String s4 = sc.next();
        String s5 = sc.next();
        BigInteger p1  = new BigInteger(s4,2); //binary reading 
        BigInteger p2 = new BigInteger(s5,2);
        System.out.println(p1.multiply(p2));
        
        
        // computing GCD
        BigInteger b0 = new BigInteger("15");
        BigInteger b1 = new BigInteger("12");
        System.out.println(b0.gcd(b1));
        // next prime number
        System.out.println(b0.nextProbablePrime());
    }  
    public static void main(String args[])
    {
        //playWithInt();
        fact(5);
        
    }

}
