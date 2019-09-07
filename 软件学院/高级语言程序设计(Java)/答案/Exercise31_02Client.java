import java.io.*;
import java.net.*;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Exercise31_02Client extends Application {
  // Text field for receiving radius
  private TextField tfWeight = new TextField();
  private TextField tfHeight = new TextField();
  private Button btSubmit= new Button("Submit");

  // Text area to display contents
  private TextArea ta = new TextArea();

  // IO streams
  DataOutputStream osToServer;
  DataInputStream isFromServer;
  
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) {
    ta.setWrapText(true);
   
    GridPane gridPane = new GridPane();
    gridPane.add(new Label("Weight in pounds"), 0, 0);
    gridPane.add(new Label("Height in inches"), 0, 1);
    gridPane.add(tfWeight, 1, 0);
    gridPane.add(tfHeight, 1, 1);
    gridPane.add(btSubmit, 2, 1);
    
    tfWeight.setAlignment(Pos.BASELINE_RIGHT);
    tfHeight.setAlignment(Pos.BASELINE_RIGHT);
    
    tfWeight.setPrefColumnCount(5);
    tfHeight.setPrefColumnCount(5);
            
    BorderPane pane = new BorderPane();
    pane.setCenter(new ScrollPane(ta));
    pane.setTop(gridPane);
    
    // Create a scene and place it in the stage
    Scene scene = new Scene(pane, 200, 200);
    primaryStage.setTitle("Exercise31_02Client"); // Set the stage title
    primaryStage.setScene(scene); // Place the scene in the stage
    primaryStage.show(); // Display the stage
    
    btSubmit.setOnAction(e -> connectToServer());
    
    try {
      // Create a socket to connect to the server
      Socket connectToServer = new Socket("localhost", 8000);
      //Socket connectToServer = new Socket("130.254.204.36", 8000);
      //Socket connectToServer = new Socket(
      //  "drake.Armstrong.edu", 8000);

      // Create an input stream to receive data from the server
      isFromServer = new DataInputStream(
        connectToServer.getInputStream());

      // Create an output stream to send data to the server
      osToServer =
        new DataOutputStream(connectToServer.getOutputStream());
    }
    catch (IOException ex) {
      ta.appendText(ex.toString() + '\n');
    }
  }
    
  public void connectToServer() {
    try {
      // Get the weight from the text field
      double weight = Double.parseDouble(tfWeight.getText().trim());

      // Get the height from the text field
      double height = Double.parseDouble(tfHeight.getText());

      // Send the weight to the server
      osToServer.writeDouble(weight);

      // Send the height to the server
      osToServer.writeDouble(height);

      osToServer.flush();

      // Get BMI from the server
     String report = isFromServer.readUTF();

      ta.appendText("Weight: " + weight + "\nHeight: " + height + "\n");
      ta.appendText(report + '\n');
    }
    catch (IOException ex) {
      System.err.println(ex);
    }
  }
  
  /**
   * The main method is only needed for the IDE with limited
   * JavaFX support. Not needed for running from the command line.
   */
  public static void main(String[] args) {
    launch(args);
  }
}
