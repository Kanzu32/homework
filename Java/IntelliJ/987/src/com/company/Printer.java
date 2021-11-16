package com.company;

public class Printer {
	static void print(int x) {
		System.out.println(x);
	}

	static void print(double x) {
		System.out.println(x);
	}

	static void print(double[] x) {
		System.out.print("[");
		for (int i = 0; i < x.length; i++) {
			if (i != 0) System.out.print(",");
			System.out.print(x[i]);
		}
		System.out.print("]");
	}

	static void print(int[] x) {
		System.out.print("[");
		for (int i = 0; i < x.length; i++) {
			if (i != 0) System.out.print(",");
			System.out.print(x[i]);
		}
		System.out.print("]");
	}

}
