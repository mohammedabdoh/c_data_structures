package tree.java;

public class BinaryTreeNode<T> {
    private T val;
    private BinaryTreeNode<T> leftNode;
    private BinaryTreeNode<T> rightNode;
    
    public BinaryTreeNode(T val) {
        this.val = val;
    }

    public BinaryTreeNode(T val, BinaryTreeNode<T> leftNode, BinaryTreeNode<T> righNode) {
        this.val = val;
        this.leftNode = leftNode;
        this.rightNode = righNode;
    }

    public T getVal() {
        return val;
    }

    public BinaryTreeNode<T> getLeftNode() {
        return leftNode;
    }

    public BinaryTreeNode<T> getRightNode() {
        return rightNode;
    }
}
