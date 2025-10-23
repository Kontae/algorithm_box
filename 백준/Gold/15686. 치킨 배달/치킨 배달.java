// https://www.acmicpc.net/problem/15686

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int N, M;
    static List<Point> house = new ArrayList<>();
    static List<Point> chicken = new ArrayList<>();
    static int answer = Integer.MAX_VALUE;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int val = Integer.parseInt(st.nextToken());
                if (val == 1) {
                    house.add(new Point(i, j));
                } else if (val == 2) {
                    chicken.add(new Point(i, j));
                }
            }
        }
        comb(0, 0, new ArrayList<>());

        System.out.println(answer);
    }

    // selectedChicken : 조합으로 뽑은 M개의 치킨집들 좌표
    private static void comb(int start, int depth, List<Point> selectedChicken) {
        if (depth == M) {
            int dist = calculateDistance(selectedChicken);
            if (answer > dist) {
                answer = dist;
            }
            return;
        }
        for (int i = start; i < chicken.size(); i++) {
            selectedChicken.add(chicken.get(i));
            comb(i + 1, depth + 1, selectedChicken);
            selectedChicken.remove(selectedChicken.size() - 1);
        }
    }

    private static int calculateDistance(List<Point> selectedChicken) {
        int total = 0;
        for (Point h : house) {
            int minDistance = Integer.MAX_VALUE;
            for (Point sc : selectedChicken) {
                int distance = Math.abs(h.x - sc.x) + Math.abs(h.y - sc.y);
                if (minDistance > distance) {
                    minDistance = distance;
                }
            }
            total += minDistance;
        }
        return total;
    }
}