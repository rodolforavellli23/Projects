import javax.swing.*;
import java.awt.*;

public class UserEntryDialog extends JDialog {

    private JTextField nameField;
    private JTextField ageField;
    private JTextField heightField;

    private boolean confirmed = false;

    private boolean validateInput() {
        if (nameField.getText().trim().isEmpty()) {
            JOptionPane.showMessageDialog(this, "Name cannot be empty.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        try {
            Integer.parseInt(ageField.getText().trim());
            Double.parseDouble(heightField.getText().trim());
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Please enter valid numeric values for age and height.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        return true;
    }

    public UserEntryDialog(Frame owner) {
        super(owner, "Enter Values", true); // true = Modal dialog

        // Component Initialization
        Font largeFont = new Font("Arial", Font.PLAIN, 32);
        Font smallFont = new Font("Arial", Font.PLAIN, 24);

        JLabel nameLabel = new JLabel("Enter your name");
        JLabel ageLabel = new JLabel("Enter your age");
        JLabel heightLabel = new JLabel("Enter your height");

        nameLabel.setFont(largeFont);
        ageLabel.setFont(largeFont);
        heightLabel.setFont(largeFont);

        nameField = new JTextField(25);
        ageField = new JTextField(25);
        heightField = new JTextField(25);

        nameField.setFont(smallFont);
        ageField.setFont(smallFont);
        heightField.setFont(smallFont);

        // Form Panel Setup
        JPanel formPanel = new JPanel(new GridBagLayout());
        formPanel.setBorder(BorderFactory.createEmptyBorder(15, 20, 15, 20));
	formPanel.setPreferredSize(new Dimension(500, 320));

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = GridBagConstraints.RELATIVE;
        gbc.anchor = GridBagConstraints.WEST;
	gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.weightx = 1.0;
        gbc.insets = new Insets(4, 0, 8, 0);

        formPanel.add(nameLabel, gbc);
        formPanel.add(nameField, gbc);
        formPanel.add(ageLabel, gbc);
        formPanel.add(ageField, gbc);
        formPanel.add(heightLabel, gbc);
        formPanel.add(heightField, gbc);

        // Custom Buttons Panel
        JButton okButton = new JButton("OK");
        JButton cancelButton = new JButton("Cancel");

        Dimension buttonSize = new Dimension(110, 40);
        Font buttonFont = new Font("Arial", Font.BOLD, 14);

        okButton.setPreferredSize(buttonSize);
        okButton.setFont(buttonFont);
        cancelButton.setPreferredSize(buttonSize);
        cancelButton.setFont(buttonFont);

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 10));
        buttonPanel.add(okButton);
        buttonPanel.add(cancelButton);

        // Button Action Handling
        okButton.addActionListener(e -> {
            if (validateInput()) {
                confirmed = true;
                dispose();
            }
        });

        cancelButton.addActionListener(e -> dispose());

        // Main Dialog Layout Structure
        setLayout(new BorderLayout());
        add(formPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);

	// Set OK button as default ENTER key action
	getRootPane().setDefaultButton(okButton);
        setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
	pack();
        setLocationRelativeTo(owner); // Center relative to parent window
    }

    // Result dialog window
    public static JDialog resultDialog(Window owner, String userName, int userAge, double userHeight) {
	// Set outDialog's fonts
	Font resultFont = new Font("Arial", Font.PLAIN, 32);
        Font closeButtonFont = new Font("Arial", Font.BOLD, 18);

	// Set modal
	Dialog.ModalityType modal = Dialog.ModalityType.APPLICATION_MODAL;

	// Use labels to print nicely the results on the result
        JLabel userNameLabel = new JLabel("Hello " + userName + "!");
        JLabel userAgeLabel = new JLabel("You're " + userAge + " years old");
        JLabel userHeightLabel = new JLabel("You're " + userHeight + " cm tall");

        userNameLabel.setFont(resultFont);
        userAgeLabel.setFont(resultFont);
        userHeightLabel.setFont(resultFont);

        // Result Panel Setup
        JPanel resultPanel = new JPanel(new GridBagLayout());
        resultPanel.setBorder(BorderFactory.createEmptyBorder(15, 20, 15, 20));
	resultPanel.setPreferredSize(new Dimension(500, 320));

        GridBagConstraints gbc_out = new GridBagConstraints();
        gbc_out.gridx = 0;
        gbc_out.gridy = GridBagConstraints.RELATIVE;
	gbc_out.gridwidth = GridBagConstraints.REMAINDER;
        gbc_out.anchor = GridBagConstraints.WEST;
        gbc_out.weightx = 1.0;
        gbc_out.insets = new Insets(4, 0, 8, 0);
	
	resultPanel.add(userNameLabel, gbc_out);
	resultPanel.add(userAgeLabel, gbc_out);
	resultPanel.add(userHeightLabel, gbc_out);

	// Button Panel Setup
        JButton closeButton = new JButton("Close");
        Dimension closeButtonSize = new Dimension(110, 40);

        closeButton.setPreferredSize(closeButtonSize);
        closeButton.setFont(closeButtonFont);

        JPanel outButtonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        outButtonPanel.add(closeButton);

	// Create JDialog
	JDialog outDialog = new JDialog(owner, "Result", modal);
        
	// Button Action Handling
        closeButton.addActionListener(e -> outDialog.dispose());
	
	// outDialog layout structure
	outDialog.setLayout(new BorderLayout());
	outDialog.add(resultPanel, BorderLayout.CENTER);
	outDialog.add(outButtonPanel, BorderLayout.SOUTH);
	// Set OK button as default ENTER key action
	outDialog.getRootPane().setDefaultButton(closeButton);
        outDialog.pack();
        outDialog.setLocationRelativeTo(owner); // Center relative to parent window
	outDialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);

	return outDialog;
    }

    // Getters for form data
    public boolean isConfirmed() { return confirmed; }
    public String getNameValue() { return nameField.getText().trim(); }
    public int getAgeValue() { return Integer.parseInt(ageField.getText().trim()); }
    public double getHeightValue() { return Double.parseDouble(heightField.getText().trim()); }

    // Program entry point
    public static void main(String[] args) {
        // Run on Event Dispatch Thread (EDT)
        SwingUtilities.invokeLater(() -> {
            UserEntryDialog dialog = new UserEntryDialog(null);
            dialog.setVisible(true);

            if (dialog.isConfirmed()) {
		JDialog myResultDialog = resultDialog(
				dialog, /* Pass dialog as the parent window */
				dialog.getNameValue(), 
				dialog.getAgeValue(), 
				dialog.getHeightValue()
		);

		myResultDialog.setVisible(true);
            }
	
	    // Cleanly terminate the JVM process after the user closes the dialogs
            System.exit(0);
        });
    }
}
