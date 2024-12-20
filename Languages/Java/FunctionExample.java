public class FunctionExample {
    private int add(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        System.out.println("Hello World");
        FunctionExample obj = new FunctionExample();
        System.out.println(obj.add(1, 2));
    }
}