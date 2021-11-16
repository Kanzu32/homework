package com.company;

import java.util.Locale;

public class Vector2D {
	public double vX;
	public double vY;
	static int count = 0;

	Vector2D() {
		this.vX = 1;
		this.vY = 1;
		count++;
	}

	Vector2D(double vX, double vY) {
		this.vX = vX;
		this.vY = vY;
		count++;
	}

	Vector2D(Vector2D vector) {
		this.vX = vector.vX;
		this.vY = vector.vY;
		count++;
	}

	void print() {
		System.out.println("(" + String.format(Locale.US, "%.2f", this.vX) + ", " + String.format(Locale.US, "%.2f", this.vY) + ")");
	}

	void add(Vector2D vector) {
		this.vX += vector.vX;
		this.vY += vector.vY;
	}

	void sub(Vector2D vector) {
		this.vX -= vector.vX;
		this.vY -= vector.vY;
	}

	void scale(double num) {
		this.vX *= num;
		this.vY *= num;
	}
	@Override
	public String toString() {
		return "(" + String.format(Locale.US, "%.2f", this.vX) + ", " + String.format(Locale.US, "%.2f", this.vY) + ")";
	}

	public double length() {
		return Math.sqrt(vX*vX + vY*vY);
	}

	void normalized() {
		double l = this.length();
		vX /= l;
		vY /= l;
	}

	double dotProduct(Vector2D vector) {
		return this.vX * vector.vX + this.vY * vector.vY;
	}
}
