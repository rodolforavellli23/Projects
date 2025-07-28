package com.tutorial;
import javax.swing.JFrame;

/**
 * Java for dummies tutorial
 */

public class tutorial { 
    
    /**
     *  Will open a blank window.
     * 
     * @param args (Chapter 4)
     * @author rodolfo
     */
    public static void main (String[] args) {
        
        JFrame myFrame = new JFrame();
        String titleString = "Blank Frame";

        myFrame.setTitle(titleString);
        myFrame.setSize(300, 200);
        myFrame.setLocation(800, 400);
        myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myFrame.setVisible(true);
    }
}
