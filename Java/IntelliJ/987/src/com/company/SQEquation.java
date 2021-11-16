package com.company;

public class SQEquation {
	int a, b, c;
	public SQEquation (int a, int b, int c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	int val(int x) {
		return a*x*x + b*x + c;
	}
}
