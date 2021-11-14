package com.company;

import java.util.Locale;

public class Vector2D {
	public double vX;
	public double vY;

	Vector2D() {
		this.vX = 1;
		this.vY = 1;
	}

	Vector2D(double vX, double vY) {
		this.vX = vX;
		this.vY = vY;
	}

	Vector2D(Vector2D vector) {
		this.vX = vector.vX;
		this.vY = vector.vY;
	}

	void print() {
		System.out.println("(" + String.format(Locale.US, "%.2f", this.vX) + ", " + String.format(Locale.US, "%.2f", this.vY) + ")");
	}

}
