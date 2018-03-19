import java.util.*;

public class Main{
    public static void main(String[] argc){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int odd = 0;
        int egg = 0;
        for (int i = 0; i < n; ++i) {
            int a = sc.nextInt();
            if (a % 2 != 0) {
                ++egg;
            } else {
                ++odd;
            }
        }
        int ans = odd < egg ? odd : egg;
        odd -= ans;
        egg -= ans;
        ans += egg / 3;
        System.out.println(ans);
    }
}
