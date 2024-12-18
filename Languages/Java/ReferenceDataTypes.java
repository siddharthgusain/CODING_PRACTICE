public class ReferenceDataTypes {
    public static void main(String[] args) {
        int[] staticArray  = {1,2,3,4};
        staticArray[0] = 33;

        String stringObject = "Hello"; // Immutable
        System.out.println(stringObject.charAt(0)); 
        System.out.println(staticArray[0]); 
    }
}
