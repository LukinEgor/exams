using System;

namespace tree {
  class Program {
    public static void Main(string[] args){
      BinaryTree tree = new BinaryTree();
      while(true){
        Console.WriteLine("\n1.Print tree\n2.Add node\n3.Exit\n\nEnter action...\n");
        string input = Console.ReadLine();
        switch(input) {
          case "1":
            tree.Print();
            break;
          case "2":
            char ch = Console.ReadLine()[0];
            tree.Add(ch);
            break;
          case "3":
            return;
        }
      }
    }
  }

  public class BinaryTree {
    private Node _root;

    public void Add(char ch) {
      Node target = new Node(ch);

      if (_root == null) {
        _root = target;
        return;
      }

      AddChild(_root, target);
    }

    public void AddChild(Node parent, Node target) {
      if(parent.isAvailable(target)) {
        target.Parent = parent;
        parent.AddChild(target);
      } else {
        Node nextNode = target.Value < parent.Value ? parent.Left : parent.Right;
        AddChild(nextNode, target);
      }
    }

    public void Print() {
      Console.WriteLine("---\n");
      Console.WriteLine("Root {0}", _root.Value);
      PrintChild(_root);
    }
    public void PrintChild(Node node) {
      Console.WriteLine("---\n");
      if (node.Left != null) {
        Console.WriteLine("Left for {0}: {1}", node.Value, node.Left.Value);
        PrintChild(node.Left);
      } else {
        Console.WriteLine("stop left for {0}", node.Value);
      }

      if (node.Right != null) {
        Console.WriteLine("Right for {0}: {1}", node.Value, node.Right.Value);
        PrintChild(node.Right);
      } else {
        Console.WriteLine("stop right for {0}", node.Value);
      }
    }
  }

  public class Node {
    public Node Parent {get; set;}
    public Node Left {get; set;}
    public Node Right {get; set;}
    public char Value {get; set;}

    public Node(char v) {
      Value = v;
    }

    public bool isAvailable(Node node) {
      return Left == null && node.Value < Value || Right == null && node.Value >= Value;
    }

    public void AddChild(Node node) {
      if (node.Value < Value) {
        Left = node;
      } else {
        Right = node;
      }
    }
  }
}
