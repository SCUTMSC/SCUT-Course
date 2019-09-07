import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

/**
 * Use the old Graph.java, AbstractGraph.java, UnweightedGraph.java. Need to
 * replace it in the future.
 */
public class Exercise28_21 extends Application {
  private List<MyCircle> circles = new ArrayList<MyCircle>();

  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    // Create a scene and place it in the stage
    Scene scene = new Scene(new MyCirclePane(), 250, 450);
    primaryStage.setTitle("Exercise28_21"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
  }

  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
   */
  public static void main(String[] args) {
    launch(args);
  }

  class MyCirclePane extends Pane {
    int colorIndex = 0;
    private Color[] colorList = {Color.BLACK, Color.BLUE, Color.GREEN, Color.CYAN, 
      Color.YELLOW, Color.ORANGE, Color.RED};

    public MyCirclePane() {
      this.setOnMouseClicked(e -> {
        if (!isInsideAnyCircle(e.getX(), e.getY())) { // Add a new circle
          circles.add(new MyCircle(e.getX(), e.getY()));
          repaint();
        }
      });
    }

    private boolean isInsideAnyCircle(double x, double y) {
      for (MyCircle circle : circles)
        if (circle.contains(x, y))
          return true;

      return false;
    }

    protected void repaint() {
      if (circles.size() == 0)
        return; // Nothing to paint

      // Build the edges
      List<AbstractGraph.Edge> edges = new ArrayList<>();
      for (int i = 0; i < circles.size(); i++)
        for (int j = i + 1; j < circles.size(); j++)
          if (circles.get(i).overlaps(circles.get(j))) {
            edges.add(new AbstractGraph.Edge(i, j));
            edges.add(new AbstractGraph.Edge(j, i));
          }

      // Create a graph with circles as vertices
      Exercise28_04.MyGraph<MyCircle> graph = new Exercise28_04.MyGraph<MyCircle>(
          circles, edges);

      List<List<Integer>> connectedComponents = graph.getConnectedComponents();

      for (List<Integer> list : connectedComponents) {
        Color color = colorList[(colorIndex++) % colorList.length];
        for (int i : list) {
          MyCircle circle = circles.get(i);
          double radius = circle.radius;

          Circle c = new Circle(circle.x, circle.y, radius);
          c.setFill(color);
          getChildren().add(c);
        }
      }
    }
  }
    
  private static class MyCircle {
    double radius = 20;
    double x, y;

    MyCircle(double x, double y) {
      this.x = x;
      this.y = y;
    }

    public boolean contains(double x1, double y1) {
      double d = distance(x, y, x1, y1);
      return d <= radius;
    }

    public boolean overlaps(MyCircle circle) {
      return distance(this.x, this.y, circle.x, circle.y) <= radius
        + circle.radius;
    }

    private static double distance(double x1, double y1, double x2, double y2) {
      return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
  }
}
