public class Exercise28_01 {
  public static void main(String[] args) throws Exception {
    java.util.Scanner input = new java.util.Scanner(System.in);
    System.out.print("Enter a file name: ");
    java.io.File file = new java.io.File(input.nextLine());
   
    if (!file.exists()) {
      System.out.println("File does not exist");
      System.exit(1);
    }
    
    java.util.Scanner inFile = new java.util.Scanner(file);
    
    // Read the number of vertices
    String s = inFile.nextLine();
    int numberOfVertices = Integer.parseInt(s);
    System.out.println("The number of vertices is " 
      + numberOfVertices);
    
    java.util.List<AbstractGraph.Edge> list = new java.util.ArrayList<>();
    
    while (inFile.hasNext()) {
      s = inFile.nextLine();
      
      String[] tokens = s.split("[\\s+]");
      
      int startingVertex = Integer.parseInt(tokens[0].trim());
      for (int i = 1; i < tokens.length; i++) {
        int adjacentVertex = Integer.parseInt(tokens[i].trim());
        list.add(new AbstractGraph.Edge(startingVertex, adjacentVertex));
      }
    }
    
    Graph<Integer> graph = new UnweightedGraph<>(list, numberOfVertices);
    
    graph.printEdges();
    AbstractGraph<Integer>.Tree tree = graph.dfs(0);
    if (tree.getNumberOfVerticesFound() == numberOfVertices)
      System.out.println("The graph is connected");
    else
      System.out.println("The graph is not connected");
  }
}
