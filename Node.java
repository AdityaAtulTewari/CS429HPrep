public class Node
{
  Node left;
  Node right;
  int datum;
  public Node(Node left, Node right, int datum)
  {
    this.left = left;
    this.right = right;
    this.datum = datum;
  }

  public static Node insert(Node toins, Node root)
  {
    if(toins.datum == root.datum) return root;
    if(toins.datum < root.datum)
    {
      if(root.left == null)
      {
        root.left = toins;
        return root;
      }
      else
      {
        root.left = insert(toins, root.right);
        return root;
      }
    }
    else
    {
      if(root.right == null)
      {
        root.right = toins;
        return root;
      }
      else
      {
        root.right = insert(toins, root.right);
        return null;
      }
    }
  }




}
