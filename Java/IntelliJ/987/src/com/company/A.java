package com.company;

public class A {
	static int a;

	static {
		if (a == 0) System.out.println("Hello world!");
	}

	public A() {
		System.out.println("ABB");
	}
	public A(int x) {
		if (x == 5) System.out.println("BiAi");
	}
	public A(B x) {
		System.out.println("BAb");
	}

}
