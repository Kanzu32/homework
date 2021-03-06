package com.company;

import java.util.Scanner;

public class Story {

	public Situation current_situation;
	Scanner input = new Scanner(System.in);

	Situation[] situations = new Situation[] {
			new Situation("В комнате монстр.\n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{-5, 0, 2}, {0, 0, -2}},
					new String[][] {{"Молодец! замочил его!", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но монстр тебя задел"}},
					new int[][] {{0, 20, 0}, {0, 0, 10}}, new String[] {"fight", "leave"}),
			new Situation("В комнате монстр.\n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{-5, 0, 2}, {0, 0, -2}},
					new String[][] {{"Молодец! замочил его!", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но монстр тебя задел"}},
					new int[][] {{0, 20, 0}, {0, 0, 10}}, new String[] {"fight", "leave"}),
			new Situation("В комнате монстр.\n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{-5, 0, 2}, {0, 0, -2}},
					new String[][] {{"Молодец! замочил его!", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но монстр тебя задел"}},
					new int[][] {{0, 20, 0}, {0, 0, 10}}, new String[] {"fight", "leave"}),
			new Situation("В комнате сундук!\n(1) Открыть\n(2) Пройти мимо",
					1, new int[][] {{0, 0, 0}, {0, 0, 0}},
					new String[][] {{"Из сундука выскачил монстр, но ты среагировал вовремя", "Из сундука выскачил монстр, а с реакцией у тебя не очень"}, {"", ""}},
					new int[][] {{0, 20, 35}, {0, 0, 0}}, new String[] {"fight", "leave"}),
			new Situation("В комнате сундук!\n(1) Открыть\n(2) Пройти мимо",
					1, new int[][] {{15, 0, 3}, {0, 0, 0}},
					new String[][] {{"Лечащее зелье!", "Лечащее зелья, как ты думал, оказалость не очень лечебным."}, {"", ""}},
					new int[][] {{0, 0, 45}, {0, 0, 0}}, new String[] {"luck", "leave"}),
			new Situation("В комнате сундук!\n(1) Открыть\n(2) Пройти мимо",
					1, new int[][] {{0, 20, 0}, {0, 0, 0}},
					new String[][] {{"Внутри ружие покруче!", "Пусто..."}, {"", ""}},
					new int[][] {{0, 0, 45}, {0, 0, 0}}, new String[] {"luck", "leave"}),
			new Situation("В комнате монстр. Выглядит куда более сурово, чем остальные\n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{-10, 0, 3}, {0, 0, -2}},
					new String[][] {{"Молодец! замочил его!", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но монстр тебя задел"}},
					new int[][] {{0, 40, 0}, {0, 0, 40}}, new String[] {"fight", "leave"}),
			new Situation("В комнате гигантский монстр, но всё ещё не босс. \n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{-15, 0, 3}, {0, 0, -2}},
					new String[][] {{"Молодец! замочил его!", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но монстр тебя задел"}},
					new int[][] {{0, 60, 0}, {0, 0, 60}}, new String[] {"fight", "leave"}),
			new Situation("В комнате босс. \n(1) Сражаться\n(2) Убежать",
					1, new int[][] {{0, 0, 0}, {-15, 0, -2}},
					new String[][] {{"Видимо ты победил.", "Слабенький ты для него."}, {"Ты смог убежать.", "Ты убежал, но он тебя задел"}},
					new int[][] {{0, 70, 0}, {0, 0, 80}}, new String[] {"fight", "leave"}, true),
	};

	Story() { nextRoom();}

	public void nextRoom() {
		current_situation = situations[(int)(Math.random()*situations.length)];
	}
}