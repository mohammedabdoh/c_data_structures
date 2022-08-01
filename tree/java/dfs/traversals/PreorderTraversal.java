package tree.java.dfs.traversals;

import java.util.ArrayList;
import java.util.List;

import tree.java.BinaryTreeNode;

/**
 * Traversing a binary search tree in a preorder
 * mening that we start with the root node, then, traverse the left subtree
 * and, finally, traverse the right subtree
 */
public class PreorderTraversal<T> {
    public List<T> traverse (BinaryTreeNode<T> root) {
        List<T> elements = new ArrayList<>();
        this.buildElementsArray(root, elements);
        return elements;
    }

    private void buildElementsArray (BinaryTreeNode<T> root, List<T> elements) {
        if(root == null) {
            return;
        }

        elements.add(root.getVal());

        buildElementsArray(root.getLeftNode(), elements);

        buildElementsArray(root.getRightNode(), elements);
    }
}