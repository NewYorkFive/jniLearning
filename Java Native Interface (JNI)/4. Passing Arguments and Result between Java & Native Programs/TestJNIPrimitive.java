public class TestJNIPrimitive{
	static {
		System.loadLibrary("myjni");
	}
	public static native double average(int n1, int n2);

	public static void main(String[] args) {
		System.out.println("static In Java, the average is " + TestJNIPrimitive.average(3,2));
	}
}