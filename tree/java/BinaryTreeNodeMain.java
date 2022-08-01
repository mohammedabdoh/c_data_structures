package tree.java;

import tree.java.bfs.BreadthFirstTraversal;
import tree.java.dfs.traversals.InorderTraversal;
import tree.java.dfs.traversals.PostorderTraversal;
import tree.java.dfs.traversals.PreorderTraversal;
/**
 * 
 *                              F
 *                      B               G                        
 *                  A       D               I
 *                      C       E       H
 * 
 */
public class BinaryTreeNodeMain {
    public static void run() {
        
        BinaryTreeNode<Character> C = new BinaryTreeNode<>('C');
        BinaryTreeNode<Character> E = new BinaryTreeNode<>('E');
        BinaryTreeNode<Character> D = new BinaryTreeNode<>('D', C, E);
        BinaryTreeNode<Character> A = new BinaryTreeNode<>('A');
        BinaryTreeNode<Character> B = new BinaryTreeNode<>('B', A, D);
        BinaryTreeNode<Character> H = new BinaryTreeNode<>('H');
        BinaryTreeNode<Character> I = new BinaryTreeNode<>('I', H, null);
        BinaryTreeNode<Character> G = new BinaryTreeNode<>('G', null, I);
        BinaryTreeNode<Character> F = new BinaryTreeNode<>('F', B, G);

        PreorderTraversal<Character> preorderTraversal = new PreorderTraversal<>();
        PostorderTraversal<Character> postorderTraversal = new PostorderTraversal<>();
        InorderTraversal<Character> inorderTraversal = new InorderTraversal<>();
        BreadthFirstTraversal<Character> breadthFirstTraversal = new BreadthFirstTraversal<>();

        System.out.println("Preorder traversal: " + preorderTraversal.traverse(F));
        System.out.println("Postorder traversal: " + postorderTraversal.traverse(F));
        System.out.println("Inorder traversal: " + inorderTraversal.traverse(F));
        System.out.println("Breadth First traversal: " + breadthFirstTraversal.traverse(F));
    }
}
