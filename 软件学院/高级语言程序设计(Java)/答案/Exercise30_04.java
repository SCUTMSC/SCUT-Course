import java.util.concurrent.*;

public class Exercise30_04 {
  private Integer sum = new Integer(0);

  public static void main(String[] args) {
    Exercise30_04 test = new Exercise30_04();
    System.out.println("What is sum ? " + test.sum);
  }

  public Exercise30_04() {
    ExecutorService executor = Executors.newFixedThreadPool(1000);

    for (int i = 0; i < 1000; i++) {
      executor.execute(new SumTask());
    }

    executor.shutdown();

    while(!executor.isTerminated()) {
    }
  }

  class SumTask implements Runnable {
    public void run() {
      int value = sum.intValue() + 1;
      sum = new Integer(value);
    }
  }
}
