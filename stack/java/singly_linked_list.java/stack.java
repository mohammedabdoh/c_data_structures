import java.util.ArrayList;

class Stack<T>
{
    int top;
    ArrayList<T> storage;

    Stack() {
        top = -1;
        storage = new ArrayList<T>();
    }

    void push(T value)
    {
        storage.add(++top, value);;
    }

    T pop()
    {
        if(isEmpty()) {
            return null;
        }
        T lastElementValue = storage.get(top);
        
        storage.remove(top);
        top--;

        return lastElementValue;
    }

    boolean isEmpty()
    {
        return storage.size() == 0;
    }

    void print()
    {
        int i = top;
        while (i >= 0)
        {
            System.out.println("------");
            System.out.print("| ");
            System.out.print(storage.get(i));
            System.out.println("  |");

            i--;
        }
        System.out.println("------");
    }
}

class StackMain
{
    public static void main(String[] args) {
        
        Stack<Integer>mystack = new Stack<Integer>();

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

        Stack<Character> mystack2 = new Stack<Character>();

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