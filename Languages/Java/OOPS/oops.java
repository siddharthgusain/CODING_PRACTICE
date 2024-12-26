package OOPS;

class Student {
    private int roll;
    private String name;

    Student(int roll, String name) {
        this.name = name;
        this.roll = roll;
    }

    // There is no Destructor in Java

    public String getName() {
        return this.name;
    }

    public int getRoll() {
        return this.roll;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }
}

// Client Code
public class oops {
    public static void main(String[] args) {
        Student stObj = new Student(1, "siddharth");
        System.out.println(stObj.getName());

        Student obj2 = stObj; // Shallow Copy
        System.out.println(obj2.getName());
    }
}
