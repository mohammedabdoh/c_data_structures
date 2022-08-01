package tree.java.dfs.traversals;

import java.util.ArrayList;
import java.util.List;

import tree.java.BinaryTreeNode;

/**
 * Traversing a binary search tree in an inorder
 * mening that we start with the left subtree, then, traverse the root node
 * and, finally, traverse the right subtree
 */
public class InorderTraversal<T> {
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

        elements.add(root.getVal());
        
        buildElementsArray(root.getRightNode(), elements);
    }
}