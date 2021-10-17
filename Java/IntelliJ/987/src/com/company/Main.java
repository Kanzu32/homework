package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();

        if ((a+b)>c && (a+c)>b && (c+b)>a) {

            if ( ((a*a + b*b) == c*c) || ((a*a + c*c) == b*b) || ((c*c + b*b) == a*a) ) {
                System.out.println("right");
            }
            else if ( ((a*a + b*b) < c*c || (a*a + c*c) < b*b || (c*c + b*b) < a*a) ) {
                System.out.println("obtuse");
            } else {
                System.out.println("acute");
            }

        } else System.out.println("impossible");
    }
}
