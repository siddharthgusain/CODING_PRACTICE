class Parent {
    int count;

    Parent(int count) {
        System.out.println("Parent Called");
        System.out.println(count);
        this.count = count;

    }

    protected void show() {
        System.out.println("Parent class method");
    }
}

class Child extends Parent {

    Child() {
        super(1);
        System.out.println("Child Called");
    }

    public void show() { // Can change the visibility to public
        System.out.println("Child class method");
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Child c = new Child();
        c.show();
    }
}
