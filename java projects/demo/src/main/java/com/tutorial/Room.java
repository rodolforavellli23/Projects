package com.tutorial;

import static java.lang.System.*;

import java.text.NumberFormat;
import java.util.Scanner;

public class Room {
    private int guests;
    private double fee;
    private boolean smoker;
    private static NumberFormat currency = NumberFormat.getCurrencyInstance();

    public void readRoom (Scanner diskScanner) {
        guests = diskScanner.nextInt();
        fee = diskScanner.nextDouble();
        smoker = diskScanner.nextBoolean();
    }

    public void writeRoom () {
        out.print(guests);
        out.print("\t");
        out.print(currency.format(fee));
        out.print("\t");
        out.println(smoker? "yes" : "no");
    }
}
