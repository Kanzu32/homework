package com.company;
import java.lang.String;
import java.lang.System;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        for (int i = 1000; i-7 > 0; i-=7) {
            System.out.println(i + " - 7" + " = " + (i-7));
            Thread.sleep(500);

        }
    }
}
