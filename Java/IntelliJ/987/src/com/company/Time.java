package com.company;

public class Time {
	int hour, min, sec;

	Time(int time) {
		this.hour = time/3600;
		this.min = (time%3600)/60;
		this.sec = time%3600%60;
	}

	public String toString() {
		return hour + ":" + min + ":" + sec;
	}
}
