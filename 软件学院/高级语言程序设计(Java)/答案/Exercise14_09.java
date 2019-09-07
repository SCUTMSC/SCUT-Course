import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Exercise14_09 extends Application {
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {       
    GridPane pane = new GridPane();
        
    pane.add(new FanPane(), 0, 0);
    pane.add(new FanPane(), 1, 0);
    pane.add(new FanPane(), 0, 1);
    pane.add(new FanPane(), 1, 1);
   
    // Create a scene and place it in the stage
    Scene scene = new Scene(pane, 200, 200);
    primaryStage.setTitle("Exercise14_09"); // Set the stage title
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
} 

class FanPane extends Pane {
  double radius = 50;
  
  public FanPane() {
    Circle circle = new Circle(60, 60, radius);
    circle.setStroke(Color.BLACK);
    circle.setFill(Color.WHITE);
    getChildren().add(circle);
    Arc arc1 = new Arc(60, 60, 40, 40, 30, 35);
    arc1.setFill(Color.RED); // Set fill color
    arc1.setType(ArcType.ROUND);
    Arc arc2 = new Arc(60, 60, 40, 40, 30 + 90, 35);
    arc2.setFill(Color.RED); // Set fill color
    arc2.setType(ArcType.ROUND);
    Arc arc3 = new Arc(60, 60, 40, 40, 30 + 180, 35);
    arc3.setFill(Color.RED); // Set fill color
    arc3.setType(ArcType.ROUND);
    Arc arc4 = new Arc(60, 60, 40, 40, 30 + 270, 35);
    arc4.setFill(Color.RED); // Set fill color
    arc4.setType(ArcType.ROUND);

    getChildren().addAll(arc1, arc2, arc3, arc4);    
  }
}
