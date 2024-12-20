interface Animal {
    void sound(); // Abstract method -> similar to pure virtual function

    default void sleep() { // Default method
        System.out.println("Animal is sleeping");
    }
}

class Dog implements Animal { // implements keyword
    public void sound() {
        System.out.println("Dog barks");
    }
}

public class Interface {

    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.sound(); // Outputs: Dog barks
        dog.sleep(); // Outputs: Animal is sleeping
    }
}
