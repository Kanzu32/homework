package com.company;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		System.out.println(n);
		boolean fl = false;

		for (int i = 2; i < Math.sqrt(n)+1; i++) {
			if (n%i == 0) {
				fl = true;
			}
		}

		if (n <= 1) {
			fl = true;
		}

		if (fl) {
			System.out.println("composite");
		} else {
			System.out.println("prime");
		}
	}
}