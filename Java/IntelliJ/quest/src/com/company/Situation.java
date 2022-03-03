package com.company;


import java.util.Scanner;

public class Situation {

	public String text;
	public int[][] dSTATS;
	public int[][] requiredSTATS;
	public int variants;
	public String[][] descriptions;
	public String[] types;
	public boolean isEnd = false;

	public Situation(String text, int variants, int[][] dSTATS, String[][] descriptions, int [][] requiredSTATS, String[] types) {
		this.text = text;
		this.dSTATS = dSTATS;
		this.variants = variants;
		this.descriptions = descriptions;
		this.requiredSTATS = requiredSTATS;
		this.types = types;
	}

	public Situation(String text, int variants, int[][] dSTATS, String[][] descriptions, int [][] requiredSTATS, String[] types, boolean isEnd) {
		this(text, variants, dSTATS, descriptions, requiredSTATS, types);
		this.isEnd = isEnd;

	}


}
