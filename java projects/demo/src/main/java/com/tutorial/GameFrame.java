package com.tutorial;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class GameFrame extends JFrame implements ActionListener {

    private static final long serialVersionUID = 1L;
    //variables
    int randonNum = new Random().nextInt(10) + 1;
    int guessNum = 0;
    //components for the GameFrame window
    JTextField textField = new JTextField(5);
    JButton button = new JButton("Guess");
    JLabel label = new JLabel(guessNum + " kguesses");
    //Declaration of the window layout
    public GameFrame() {
        setTitle("Guessing Game");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        add(textField);
        add(button);
        add(label);
        button.addActionListener(this);
        pack();
        setSize(300, 100);
        setLocation(800, 400);
        setVisible(true);
    }
    //JButton event logic
    @Override
    public void actionPerformed(ActionEvent e) {
        
        String textFieldText = textField.getText();
        
        if (Integer.parseInt(textFieldText) == randonNum) {
            button.setEnabled(false);
            textField.setText(textField.getText() + " Yes!");
            setTitle("Congratulations!");
            textField.setEnabled(false);
        } else {
            textField.setText("");
            textField.requestFocus();
        }
        
        guessNum++;
        String guessString = (guessNum == 1)? "guess":"guesses";
        label.setText(guessNum + guessString);
    }
    
}

/**
 * ShowGameFrame - Spaws GameFrame window
 */
class ShowGameFrame {

    public static void main(String args[]){
        new GameFrame();
    } 
}
