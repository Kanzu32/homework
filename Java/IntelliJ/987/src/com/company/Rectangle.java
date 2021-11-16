package com.company;

public class Rectangle {
	public int a, b;

	public Rectangle (int a, int b) {
		this.a = a;
		this.b = b;
	}

	int getP() {
		return a*2+b*2;
	}

	int getS() {
		return a*b;
	}
}
