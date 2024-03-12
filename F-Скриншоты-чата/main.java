import java.util.*;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numberOfData = scanner.nextInt();

    for (int t = 0; t < numberOfData; t++) {
      int numberOfUsers = scanner.nextInt();
      int numberOfScreens = scanner.nextInt();

      Map<Integer, List<Integer>> values = new HashMap<>();
      int[] degree = new int[numberOfUsers + 1];

      for (int i = 0; i < numberOfScreens; i++) {
        int prev = scanner.nextInt();
        if (numberOfUsers > 1) {
          prev = scanner.nextInt();
        }
        for (int j = 2; j < numberOfUsers; j++) {
          int current = scanner.nextInt();
          values.computeIfAbsent(prev, k -> new ArrayList<>()).add(current);
          degree[current]++;
          prev = current;
        }
      }

      Queue<Integer> Q = new LinkedList<>();
      for (int i = 1; i < numberOfUsers + 1; i++) {
        if (degree[i] == 0) {
          Q.offer(i);
        }
      }

      int count = 0;
      while (!Q.isEmpty()) {
        int front = Q.poll();
        count++;
        for (int value : values.getOrDefault(front, Collections.emptyList())) {
          degree[value]--;
          if (degree[value] == 0) {
            Q.offer(value);
          }
        }
      }

      if (count == numberOfUsers || numberOfUsers == 1) {
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
    }
  }
}
