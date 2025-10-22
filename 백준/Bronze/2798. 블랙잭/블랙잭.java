import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.io.BufferedReader;

public class Main {
    static int MAX_VALUE = -1;
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        BlackJack(0, 0, 0);

        System.out.println(MAX_VALUE);
    }

    private static void BlackJack(int depth, int start, int sum) {
        if (depth == 3) {
            if (sum <= M && MAX_VALUE < sum) {
                MAX_VALUE = sum;
            }
            return;
        }
        for (int i = start; i < N; i++) {
            BlackJack(depth + 1, i + 1, sum + arr[i]);
        }
    }
}