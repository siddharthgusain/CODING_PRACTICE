package BIT_manipulation;

class Basic {
    public static void main(String[] args) {
        int n = 3; // 00000011
        int k = 3;
        // Binary of 1 -> 00000001
        int bitOnMask = 1 << k; // 00000100
        int bitOffMask = ~(1 << k); // 11111011
        int bitToggleMask = 1 << k; // 00000100
        int checkBitMask = 1 << k; // 11111011

        System.out.println(n | bitOnMask);
        System.out.println(n & bitOffMask);
        System.out.println(n ^ bitToggleMask);

        int result = n & checkBitMask;

        if (result == 0)
            System.out.println("Bit is Off");
        else
            System.out.println("Bit is On");
    }
}