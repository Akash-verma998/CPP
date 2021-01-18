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
public class Julice { 
    static void compute(BigInteger n, BigInteger k)
    {
        BigInteger x,y;
        x = n.subtract(k);
        x = x.divide(BigInteger.valueOf(2));
        y = x.add(k);
        System.out.println(y);
        System.out.println(x);
    }
    public static void main(String args[])
    {
        BigInteger n,k,ans;
        Scanner sc = new Scanner(System.in);
        int test =10;
        while(test>0)
        {
            n = sc.nextBigInteger();
            k = sc.nextBigInteger();
            compute(n,k);
            test=test-1;
            
        }
        
    }   
}
