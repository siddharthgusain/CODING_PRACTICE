public class SimpleClass {
    String name;
    int age;

    SimpleClass() {
    }// Automatically Created -> Default constructor

    SimpleClass(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public static void main(String[] args) {
        SimpleClass s = new SimpleClass("Siddharth", 26);

        System.out.println(s.name);
        System.out.println(s.age);
    }
}
