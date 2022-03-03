package com.company;

import java.util.Scanner;

public class Main {

    public static Character player;
    public static Story story;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Ты оказался в подземелье. Убей босса для победы.");
        player = new Character(100, (int)(Math.random()*31)+10, (int)(Math.random()*41)+20);
        story = new Story();
        boolean storyEnded = false;
        while (true) {

            System.out.println("=====\nHP:" + player.HP + "\tATK:"
                    + player.ATK + "\tLUK:" + player.LUK + "\n=====");
            System.out.println("=============\n"
                    + story.current_situation.text + "\n==============");
            int in = input.nextInt();
            int result = 0;

            if (player.HP >= story.current_situation.requiredSTATS[in-1][0] &&
                player.ATK >= story.current_situation.requiredSTATS[in-1][1] &&
                player.LUK >= story.current_situation.requiredSTATS[in-1][2])
            {
                if (story.current_situation.isEnd) {
                    storyEnded = true;
                }
                player.HP += story.current_situation.dSTATS[in-1][0];
                player.ATK += story.current_situation.dSTATS[in-1][1];
                player.LUK += story.current_situation.dSTATS[in-1][2];
            } else {
                switch (story.current_situation.types[in-1]) {
                    case ("fight"):
                        player.HP -= (int)(Math.random()*20+3);
                        break;
                    case ("leave"):
                        player.LUK -= (int)(Math.random()*10+2);
                        break;
                    case ("luck"):
                        player.LUK += (int)(Math.random()*8+2);
                        player.HP -= (int)(Math.random()*8+5);
                        break;
                }
                result = 1;
            }


            if (!story.current_situation.descriptions[in-1].equals(""))
                System.out.println(story.current_situation.descriptions[in-1][result]);

            if (player.LUK < 0) {
                System.out.println("Отрицательная удача?? Да ты счастливчик.");
            }
            if (player.ATK < 10) {
                player.ATK = 10;
            }
            if (player.ATK > 100) {
                System.out.println("Атака выше 100?? Да ты в этом поджемелье сам босс...");
            }
            if (player.HP > 100) {
                System.out.println("Тормози! Выше 100 HP не полечишся.\nКарманов для зелий восстановления у тебя, к сожалению, тоже нет.");
                player.HP = 100;
            }

            if (player.HP <= 0) {
                System.out.println("К сожалению ты помер. В следующий раз повезёт. Наверно.");
                System.out.println("====================the end!===================");
                return;
            }
            else if (storyEnded) {
                System.out.println("====================the end!===================");
                return;
            }
            story.nextRoom();

        }

    }

}
