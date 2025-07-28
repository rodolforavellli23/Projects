package com.tutorial;
import java.util.Scanner;

public class tutorial_1 {
    /**
     * return string
     * 
     * @param args (chapter 6)
     * @author rodolfo
     */
    public static void main(String args[]) {
        Scanner keyboard = new Scanner(System.in);
        char reply;
        
        do {
            System.out.println("\nPlease type your character\n\nIt must be either \'y\' or \'n\'");
            reply = keyboard.findWithinHorizon(".", 0).charAt(0);       
            
        } while (reply != 'y' && reply != 'n');

        keyboard.close();

        if (reply == 'y') {
            System.out.println("\nYou typed \'y\'");
        } else {
            System.out.println("\nYou typed \'n\'");
        }
    }
}
