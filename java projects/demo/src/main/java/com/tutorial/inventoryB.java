package com.tutorial;

import static java.lang.System.*;

import java.text.NumberFormat;
import java.util.Scanner;

public class inventoryB {
    public static void main(String[] args) {
        final double priceBox = 3.25d;
        int close = 1;
        Scanner keyboard = new Scanner(System.in);
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        do {
            out.print("\n How many boxes do we have? ");
            String numBoxesIn = keyboard.next();

            try {
                int numBoxes = Integer.parseInt(numBoxesIn);
                String total = currency.format(numBoxes * priceBox);
                if (numBoxes * priceBox < 0) {
                    total = "minus " + currency.format(-1 * (numBoxes * priceBox)) + " , we've fallen into debt.";
                }
                out.print("\n The total price for all boxes will be ");
                out.print(total);
                out.println("\n\n Type 0 to exit: ");
                close = keyboard.nextInt();
            } catch (NumberFormatException e) {
                out.print("\n You have not typed a whole number.");
                out.print("\n You may only have a whole integer number of boxes.\n");
            } catch (Exception d) {
                out.println(d.getMessage());
            }
        } while (close != 0);
        keyboard.close();
    }
}
