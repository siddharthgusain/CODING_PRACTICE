package Trees;

import java.util.ArrayList;
import java.util.Stack;

public class GenericTree {
    private static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();
    }

    public static Node GenericTreeConstruction(int[] arr) {
        Node root = null;
        Stack<Node> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == -1) {
                st.pop();
            } else {
                Node newNode = new Node();
                newNode.data = arr[i];

                if (st.size() > 0) {
                    Node topNode = st.peek();
                    topNode.children.add(newNode);
                } else {
                    root = newNode;
                }

                st.push(newNode);
            }
        }

        return root;
    }

    public static void display(Node node) {
        String str = node.data + "->";
        for (Node child : node.children) {
            str += child.data + ",";
        }

        str += '.';

        System.out.println(str);

        for (Node child : node.children) {
            display(child);
        }
    }

    public static int getSize(Node root) {
        int size = 0;
        for (Node child : root.children) {
            int childSize = getSize(child);
            size = size + childSize;
        }

        return 1 + size;
    }

    public static int maximumOfTree(Node node) {

        int max = Integer.MIN_VALUE;
        for (Node child : node.children) {
            int childMax = maximumOfTree(child);
            max = Math.max(childMax, max);
        }

        max = Math.max(node.data, max);

        return max;
    }

    public static int heightOfGenericTree() {
        return 1;
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 50, -1, 60, -1, -1, 50, -1, 20 };
        Node root = GenericTreeConstruction(arr);
        display(root);
        System.out.println(getSize(root));
        System.out.println(maximumOfTree(root));
    }
}
