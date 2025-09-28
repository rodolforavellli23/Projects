public class Hello {
    public static void main(String[] args) {
        // Variables
        String javaVersion = System.getProperty("java.version");          // line one
        String javaVendor = System.getProperty("java.vendor");            // line two
        String javaVmName = System.getProperty("java.vm.name");           // line three
        String javaRuntimeName = System.getProperty("java.runtime.name"); // line four

        String line_one = "\nHello, World! From Java";
        String line_two = "Java Vendor:";
        String line_three = "Java VM Name:";
        String line_four = "Java Runtime Name:";

        int vers_len = javaVersion.length();
        int vend_len = javaVendor.length();
        int vmName_len = javaVmName.length();
        int rtName_len = javaRuntimeName.length();

        int ln_one_len = line_one.length();
        int ln_two_len = line_two.length() + 11;
        int ln_three_len = line_three.length() + 10;
        int ln_four_len  = line_four.length() +  5;

        // String Formatting

        // For Left Padding, use "%" + pad_amount + "s"; and
        // For Right Padding, use "%-" + pad_amount + "s"

        String to_line_one = String.format("%" + ln_one_len + "s" + " %-" + vers_len + "s \n", line_one, javaVersion);
        String to_line_two = String.format("%" + ln_two_len + "s" + " %-" + vend_len + "s", line_two, javaVendor);
        String to_line_three = String.format("%" + ln_three_len + "s" + " %-" + vmName_len + "s", line_three, javaVmName);
        String to_line_four  = String.format("%" + ln_four_len + "s" + " %-" + rtName_len + "s", line_four, javaRuntimeName);

        // Text Output
        System.out.println(to_line_one);
        System.out.println(to_line_two);
        System.out.println(to_line_three);
        System.out.println(to_line_four);
    }
}
