package tree.java.dfs.traversals;

import java.util.ArrayList;
import java.util.List;

import tree.java.BinaryTreeNode;

/**
 * Traversing a binary search tree in a postorder
 * mening that we start with the left subtree, then, traverse the right subtree
 * and, finally, traverse the root node
 */
public class PostorderTraversal<T> {
    public List<T> traverse (BinaryTreeNode<T> root) {
        List<T> elements = new ArrayList<>();
        this.buildElementsArray(root, elements);
        return elements;
    }

    private void buildElementsArray (BinaryTreeNode<T> root, List<T> elements) {
        if(root == null) {
            return;
        }

        buildElementsArray(root.getLeftNode(), elements);
        
        buildElementsArray(root.getRightNode(), elements);
        
        elements.add(root.getVal());
    }
}