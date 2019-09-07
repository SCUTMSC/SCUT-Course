/** Solution provided by Næsje Frode, April 2013 */

public class Exercise29_03 {
  public static void main(String[] args) {
  
    int [][] edges = new int[][]{
      {0, 1, 2}, {0, 3, 8}, 
      {1, 0, 2}, {1, 2, 7}, {1, 3, 3},
      {2, 1, 7}, {2, 3, 4}, {2, 4, 5},
      {3, 0, 8}, {3, 1, 3}, {3, 2, 4}, {3, 4, 6},
      {4, 2, 5}, {4, 3, 6}
    };
    
    Integer[][] adjacencyMatrix = {
    		{null,   2,null,   8,null},
    		{   2,null,   7,   3,null},
    		{null,   7,null,   4,   5},
    		{   8,   3,   4,null,   6},
    		{null,null,   5,   6,null}
    };
    
    System.out.println("\nSolution with adjacency matrix:");
    WeightedGraphAdj<Integer> graph = new WeightedGraphAdj<>(edges, 5);
    WeightedGraphAdj<Integer>.ShortestPathTree tree = graph.getShortestPathAdj(3, adjacencyMatrix);
    tree.printAllPaths();
  }
}
