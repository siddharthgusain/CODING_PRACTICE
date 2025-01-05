import java.util.ArrayDeque;
import java.util.Queue;

public class QueueCollection {
    public static void main(String[] args) {
        Queue<Integer> queObj = new ArrayDeque<>();
        queObj.add(1);
        queObj.add(2);
        queObj.remove();
        System.out.println(queObj.poll());
    }
}

/*
 * Here if u see , new ArrayQueue() but assigning to type Queue<Integer>
 * This is similar to CPP ArrayQueue is Derived Class and we storing its Object
 * Pointer to queObj which is of Queue Class
 */

// Queue is Base class -> ArrayDeque is Derived
// In Java Queue is Interface -> We can't create object of interface as it has
// ony declaration of function, no definition