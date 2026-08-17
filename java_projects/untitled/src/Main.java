public class Main {
	
	/* Padding Function */
	public static String pad(int size, String myPad) {
		String myOutput = "";

		for(int i = 0; i < size; i++) {
			myOutput += myPad;
		}

		return myOutput;
	}

	/* Entry Point */
	public static void main(String[] args) {
		
		/* Unlike in C, args[0] is the first argument, and
		 * not the name of the program itself.
		 *
		 */

		String myArg = "";
		String startPad = pad(4, "*") + pad(1, " ");
		String endPad = pad(1, " ") + pad(4, "*");
		String vers = System.getProperty("java.version");

		if(args.length < 1) {
			System.out.println("\n" + 
					   startPad + 
					   "Hello world! From Java v." + 
					   vers + 
					   endPad + 
					   "\n");
		} else {
			myArg = String.valueOf(args[0]);

			System.out.println("\n" + 
					   startPad + 
					   myArg + 
					   " From Java v." + 
					   vers + 
					   endPad + 
					   "\n");
		}
	}
}
