public class Hello {
    public static void main(String[] args) {
	    // Variables
	    String javaVersion = System.getProperty("java.version");
	    String javaRuntimeName = System.getProperty("java.runtime.name");
	    String javaVendor = System.getProperty("java.vendor");
	    String javaVmName = System.getProperty("java.vm.name");

	    // Output
	    System.out.println("\nHello, World! From Java " + javaVersion + "\n");
	    System.out.println("Java Runtime Name: " + javaRuntimeName);
	    System.out.println("Java Vendor: " + javaVendor);
	    System.out.println("Java VM Name: " + javaVmName);
    }
}
