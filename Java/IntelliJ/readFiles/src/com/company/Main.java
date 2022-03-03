package com.company;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        String path = System.getProperty("user.dir") + "\\text";
        File file1 = new File(path, "a.txt");
        File file2 = new File(path, "b.txt");
        FileInputStream file1Stream;
        FileInputStream file2Stream;

        if (file1.length() > file2.length()) {
            file1Stream = new FileInputStream(file1);
            file2Stream = new FileInputStream(file2);
        } else {
            file1Stream = new FileInputStream(file2);
            file2Stream = new FileInputStream(file1);
        }

        int a;
        int count = 0;

        while ((a = file2Stream.read()) != -1) {
            int b = file1Stream.read();
            if (a != b) {
                System.out.print("a");
                if (a == 13) System.out.print("enter ");
                else if (a == 32) System.out.print("space ");
                else System.out.print((char)a + " ");

                System.out.print("b");
                if (b == 13) System.out.print("enter");
                else if (b == 32) System.out.print("space");
                else  System.out.print((char)b + "");
            }
            count++;
        }

        while ((a = file1Stream.read()) != -1) {
            System.out.println((char)a + " space");
            count++;
        }








    }
}
