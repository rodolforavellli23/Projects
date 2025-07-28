package com.tutorial;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class SimpleFrame extends JFrame {
    
    JFrame SimpleFrame = new JFrame();

    SimpleFrame() {
        setTitle("Don't Click In The Button!");
        setLayout(new FlowLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        add(new JButton("PANIC"));
        setSize(300, 100);
        setLocation(800, 400);
        setVisible(true);
    }
}

class MostrarFrame {
    public static void main(String[] args) {
        new SimpleFrame();
    }
}
