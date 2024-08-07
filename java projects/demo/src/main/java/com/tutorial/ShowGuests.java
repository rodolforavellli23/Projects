package com.tutorial;

import static java.lang.System.*;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class ShowGuests {
    public static void main(String args[]) throws IOException {
        int guests[] = new int[10];
        Scanner diskScanner = new Scanner(
                new File("/home/greenshoots/Documentos/GitHub/Projects/java projects/demo/src/Text/guestsList.txt"));

        for (int numRoom = 0; numRoom < 10; numRoom++) {
            guests[numRoom] = diskScanner.nextInt();
        }

        diskScanner.close();
        out.println("Room\tGuests");

        for (int numRoom = 0; numRoom < 10; numRoom++) {
            out.print(numRoom + 1);
            out.print("\t");
            out.println(guests[numRoom]);
        }
    }
}
