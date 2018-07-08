public class TestJNIInstanceVariable {
	static {
		System.loadLibrary("myjni");
	}

	private int number = 88;
	private String message = "Hello from Java";
	private native void modifyInstanceVariable();

	public static void main(String[] args) {
		TestJNIInstanceVariable test = new TestJNIInstanceVariable();
		test.modifyInstanceVariable();
		System.out.println("In Java , int is " + test.number);
		System.out.println("In Java, String is " + test.message);
	}
}