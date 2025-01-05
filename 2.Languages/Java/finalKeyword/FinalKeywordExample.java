public final class FinalKeywordExample { // can't be extended
    final int MAX_VALUE = 10; // Constant
    final int[] arr = { 1, 23, 4 };

    final void change() { // Final Method can't be overridden by Child class
        // this.arr = new int[5]; // not possible
        arr[0] = 22; // possible
    }

}

// theres no const keyword in java