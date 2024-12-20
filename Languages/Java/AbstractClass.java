abstract class Animal {
    String name;
  
    abstract void sound();  // Abstract method 

    void sleep() {  // Concrete method
        System.out.println("Animal is sleeping");
    }
  
    // Constructor
    Animal(String name) {
        this.name = name;
    }
}

class Dog extends Animal {
    Dog(String name) {
        super(name);
    }

    void sound() {
        System.out.println(name + " barks");
    }
}

public class AbstractClass {
    
    public static void main(String[] args) {
        Dog dog = new Dog("Buddy");
        dog.sound();  // Outputs: Buddy barks
        dog.sleep();  // Outputs: Animal is sleeping
    }
}
