import javax.swing.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

public class Main {
	public static void main(String[] args) {
		/* Declare components to be composed together */
		
		// Large font
		Font largeFont = new Font("Arial", Font.PLAIN, 32);
		
		// Small font
		Font smallFont = new Font("Arial", Font.PLAIN, 18);

		// Declare the data entry panel that will hold the labels and entry fields
		JPanel panel1 = new JPanel(new GridBagLayout());

		// Declare the labels
		JLabel nameLabel = new JLabel("Enter your name");
		JLabel ageLabel = new JLabel("Enter your age");
		JLabel heightLabel = new JLabel("Enter your height");

		// Declare the text fields
		JTextField field1 = new JTextField(50);
		JTextField field2 = new JTextField(50);
		JTextField field3 = new JTextField(50);
	
		/* Format components to be added */
		
		// Panel format
		panel1.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 100));
		panel1.setPreferredSize(new Dimension(600, 400));
		
		// Name format
		nameLabel.setFont(largeFont);
		field1.setFont(smallFont);

		// Age format
		ageLabel.setFont(largeFont);
		field2.setFont(smallFont);
		
		// Height format
		heightLabel.setFont(largeFont);
		field3.setFont(smallFont);

		/* Declare GridBagConstraints */
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridx = 0;                        // All components in column 0
		gbc.gridy = GridBagConstraints.RELATIVE; // Stack vertically
		gbc.anchor = GridBagConstraints.WEST; // Align items to the left
		gbc.weightx = 0.0;                    // Do not stretch items horizontally
		gbc.fill = GridBagConstraints.NONE;   // Maintain component native sizes
		gbc.insets = new Insets(5, 0, 5, 0);  // Vertical spacing between components

		/* Compose data entry panel using gbc */
		
		// Name data entry
		panel1.add(nameLabel, gbc);
		panel1.add(field1, gbc);
		
		// Age data entry
		panel1.add(ageLabel, gbc);
		panel1.add(field2, gbc);
		
		// Height data entry
		panel1.add(heightLabel, gbc);
		panel1.add(field3, gbc);

		// Show the window we declared above
		int result = JOptionPane.showConfirmDialog(
				null, panel1, "Enter Values", JOptionPane.OK_CANCEL_OPTION
		);

		// Show the output window
		if (result == JOptionPane.OK_OPTION) {
			// Check if results are valid
			try {
				// Get the data
				String name = field1.getText().trim();
				String age = field2.getText().trim();
				String height = field3.getText().trim();

				// Conver age and height
				int myAge = Integer.parseInt(age);
				double myHeight = Double.parseDouble(height);
				
				// Format output message
				String message = "Hello " + name + "!\n" + 
						 "Your Age:  " + myAge + " years old\n" + 
						 "Your Height:  " + myHeight + " cm tall\n";

				// Display Message
				JOptionPane.showMessageDialog(null, message);
			} 
			catch (NumberFormatException e) {
				JOptionPane.showMessageDialog(null, "Error: " + e);
			}

		}
	}
}
