package com.tutorial;

import static java.lang.System.*;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class showRoom {
    public static void main(String args[]) throws IOException {
        Room rooms[] = new Room[10];
        Scanner diskScanner = new Scanner(new File("/home/rodolfo/Documentos/Projetos/java projects/demo/src/Text/guestsList.txt"));

        for (int numRoom = 0; numRoom < 10; numRoom++) {
            rooms[numRoom] = new Room();
            rooms[numRoom].readRoom(diskScanner);
        }

        out.println("Room\tGuests\tFee\t\tSmoker?");
        out.println("=======================================");
        for (int numRoom = 0; numRoom < 10; numRoom++) {
            out.print(numRoom + "\t");
            rooms[numRoom].writeRoom();
        }        
    }
}
