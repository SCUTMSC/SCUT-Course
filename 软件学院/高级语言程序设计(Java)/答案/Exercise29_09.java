public class Exercise29_09 {
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
    System.out.println("The number of vertices is " + numberOfVertices);
    
    java.util.List<WeightedEdge> list = 
      new java.util.ArrayList<WeightedEdge>();
    
    while (inFile.hasNext()) {
      s = inFile.nextLine();
      
      String[] triplets = s.split("[\\|]");
      
      for (String triplet: triplets) {
        String[] tokens = triplet.split("[,]");
        int u = Integer.parseInt(tokens[0].trim());
        int v = Integer.parseInt(tokens[1].trim());
        int w = Integer.parseInt(tokens[2].trim());
        
        list.add(new WeightedEdge(u, v, w));
        list.add(new WeightedEdge(v, u, w));
      }
    }
    
    WeightedGraph<Integer> graph = new WeightedGraph<Integer>(list, numberOfVertices);
    
    graph.printWeightedEdges();
    WeightedGraph<Integer>.MST tree = graph.getMinimumSpanningTree();
    System.out.println("Total weight in MST is " + tree.getTotalWeight());
    tree.printTree();
  }
}
