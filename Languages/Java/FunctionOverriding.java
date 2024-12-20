class Animal {
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override // Override Annotation
    public void sound() {
        System.out.println("Dog barks");
    }
}

public class FunctionOverriding {
    public static void main(String[] args) {
        Animal animal = new Dog();
        animal.sound(); // Calls Dog's sound() due to Runtime polymorphism
    }
}

/*
 * Java has built-in dynamic dispatch for method calls, so there's no need for a
 * "virtual" keyword.
 * In the subclass, you can use the @Override annotation, which helps catch
 * errors at compile time if the method doesn't match the superclass method
 * signature.
 * Java automatically handles memory management with garbage collection, so you
 * don't need to manually delete objects.
 * The method in the subclass must have the same method signature (name, return
 * type, and parameters) as the method in the superclass.
 */