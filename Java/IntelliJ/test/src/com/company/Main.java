package com.company;
import java.util.Scanner;
import java.lang.String;

public class Main {

    public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        while (n > 0) {
            if (n == 100) {
                System.out.print("C");
                n -= 100;
            } else if (n >= 90) {
                System.out.print("XC");
                n -= 90;
            } else if (n >= 50) {
                System.out.print("L");
                n -= 50;
            } else if (n >= 40) {
                System.out.print("XL");
                n -= 40;
            } else if (n >= 10) {
                System.out.print("X");
                n -= 10;
            } else if (n == 5) {
                System.out.print("V");
                n = 0;
            } else if (n >= 6 && n < 9) {
                String repeated = new String(new char[n-5]).replace("\0", "I");
                System.out.print("V" + repeated);
                n = 0;
            } else if (n == 9) {
                System.out.print("IX");
                n = 0;
            } else if (n < 4) {
                String repeated = new String(new char[n]).replace("\0", "I");
                System.out.print(repeated);
                n = 0;
            } else if (n == 4) {
                System.out.print("IV");
                n = 0;
            }
         }

    }
}
