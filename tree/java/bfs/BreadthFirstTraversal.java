package tree.java.bfs;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import tree.java.BinaryTreeNode;

/**
 * Traversing the binary tree using breadth first traversal
 * meaning that we go level by level from left to right
 */
public class BreadthFirstTraversal<T> {
    public List<List<T>> traverse(BinaryTreeNode<T> root) {
        List<List<T>> elements = new ArrayList<>();
        Queue<BinaryTreeNode<T>> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty()) {
            List<T> levelElements = new ArrayList<>();
            int currentQueueSize = queue.size();

            while(currentQueueSize > 0) {
                BinaryTreeNode<T> currentItem = queue.poll();
                levelElements.add(currentItem.getVal());
                if(currentItem.getLeftNode() != null) {
                    queue.add(currentItem.getLeftNode());
                }
                if(currentItem.getRightNode() != null) {
                    queue.add(currentItem.getRightNode());
                }
                currentQueueSize--;
            }
            elements.add(levelElements);
        }
        
        return elements;
    }
}
