import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
// https://www.acmicpc.net/problem/1759

public class Main {
    static int N;
    static int M;
    static List<Character> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            list.add(st.nextToken().charAt(0));
        }
        Collections.sort(list);

        StringBuilder sb = new StringBuilder();

        comb(0, 0, sb);


    }

    private static void comb(int start, int depth, StringBuilder sb) {
        if (depth == N) {
            int[] result = countVowels(sb);
            if (result[0] >= 1 && result[1] >= 2) {
                System.out.println(sb);
            }
            return;
        }

        for (int i = start; i < M; i++) {
            sb.append(list.get(i));
            comb(i + 1, depth + 1, sb);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

    private static int[] countVowels(StringBuilder sb) {
        Set<Character> set = Set.of('a', 'e', 'i', 'o', 'u');
        int vowelCount = 0;
        int consonantCount = 0;
        for (int i = 0; i < sb.length(); i++) {
            if (set.contains(sb.charAt(i))) {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
        return new int[]{vowelCount, consonantCount};
    }
}