class StackUsingList<T>
{
    LinkedListForStack<T> storage;

    StackUsingList() {
        storage = new LinkedListForStack<T>();
    }

    void push(T value)
    {
        NodeForStack<T> elementToAdd = new NodeForStack<T>(value);
        storage.prepend(elementToAdd);
    }

    T pop()
    {
        if(isEmpty()) {
            return null;
        }
        
        NodeForStack<T> lastElement = storage.getHead();
        T lastElementValue = lastElement.data;
        
        storage.deleteNode(lastElement);

        return lastElementValue;
    }

    boolean isEmpty()
    {
        return storage.isEmpty();
    }

    void print()
    {
        NodeForStack<T> currentHead = storage.getHead();
        
        while (currentHead != null)
        {
            System.out.println("------");
            System.out.print("| ");
            System.out.print(currentHead.data);
            System.out.println("  |");
            
            currentHead = currentHead.nextNode;
        }
        System.out.println("------");
    }
}

class StackUsingListMain
{
    public static void main(String[] args) {
        
        StackUsingList<Integer>mystack = new StackUsingList<Integer>();

        mystack.push(1);
        mystack.push(2);
        mystack.pop();
        mystack.push(3);
        mystack.push(4);
        mystack.push(5);
        mystack.pop();
        mystack.push(11);
        mystack.pop();
        mystack.push(12);
        mystack.push(20);

        mystack.print();

        StackUsingList<Character> mystack2 = new StackUsingList<Character>();

        mystack2.push('a');
        mystack2.push('b');
        mystack2.pop();
        mystack2.push('c');
        mystack2.push('d');
        mystack2.push('e');
        mystack2.pop();
        mystack2.push('f');
        mystack2.pop();
        mystack2.push('g');
        mystack2.push('h');

        mystack2.print();
    }
}