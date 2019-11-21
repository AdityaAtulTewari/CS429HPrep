public class Helper {
  public static void main(String[] args)
  {
    Node n0 = new Node(null, null, 0);
    Node n1 = new Node(null, null, 1);
    Node n2 = new Node(null, null, 2);
    Node nn1 = new Node(null, null, -1);
    Node nn2 = new Node(null, null, -2);
    Node nn3 = new Node(null, null, -3);
    Node nn4 = new Node(null, null, -4);
    Node root = Node.insert(n1, n0);
    root = Node.insert(nn1, root);
    root = Node.insert(n2, root);
    root = Node.insert(nn1, root);
    root = Node.insert(nn2, root);
    root = Node.insert(nn3, root);
    root = Node.insert(nn4, root);
    System.out.println("Useful: " + root.datum);
    System.out.println("Useful: " + root.left.datum);
  }

}

