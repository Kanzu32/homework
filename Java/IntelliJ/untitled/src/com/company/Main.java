package com.company;
import java.awt.*;
import java.util.Scanner;

class A{
    int a;
    String name;
}

class Main {
    public static void main(String[] args){
        new Thread(new Test()).start();
    }

    
}

class Test extends  Thread{
    @Override
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.print('*');
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}