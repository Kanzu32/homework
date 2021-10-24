package com.company;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println(sum(input.nextInt()));



    }

    static public int sum(int x) {
        int count = 0;

        for (int i = x-1; i > 99; i--) {

            if ((i%10 + i%100/10 + i%1000/100) % 13 == 0) {
                count++;
            }
        }
        return count;
    }
}