#include <iostream>
#include <memory>
#include <vector>
//#include "LinkedListQueue.hpp"
//#include "LinkedListStack.hpp"
#include "RedBlackTree.hpp"

void testRedBlackTree(RedBlackTree::RedBlackTree& tree)
{
    std::cout << "********************************************* TEST TREE *********************************************" << std::endl;

    tree.Insert(30);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(35);
#if 0
    tree.Insert(45);
    tree.Insert(60);
    tree.Insert(70);
    tree.Insert(80);
    tree.Insert(4);
    tree.Insert(8);
#endif
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();
    tree.InorderTraversal();
    tree.IterativeInorderTraversal();
    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();
    tree.LevelorderTraversal();

    std::cout << "Height of a Tree: " << tree.Height() << std::endl;

    std::cout << "Delete element." << std::endl;

    tree.DeleteElement(22);
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();
    tree.InorderTraversal();
    tree.IterativeInorderTraversal();
    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();
    tree.LevelorderTraversal();

    std::cout << "*****************************************************************************************************" << std::endl;
}

#if 0

void testQueue(LinkedListQueue::Queue& queue)
{
    std::cout << "********************************************* TEST QUEUE *********************************************" << std::endl;

    std::cout << queue << std::endl;
    std::cout << "queue.isEmpty() = " << queue.isEmpty() << std::endl;
    std::cout << "queue.isFull() = " << queue.isFull() << std::endl;
    std::cout << "queue.dequeue() = " << queue.dequeue() << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;


    for (unsigned int i = 0; i < 12; ++i)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> treeNode = std::make_shared<ComplexTypes::AVLTreeNode>(i + 1, 1U, nullptr, nullptr);
        queue.enqueue(treeNode);
        std::cout << queue << std::endl;
    }

    std::cout << "queue.first() = (" << queue.first()->data << ", " << queue.first()->height << ")" << std::endl;
    std::cout << "queue.last() = (" << queue.last()->data << ", " << queue.last()->height << ")" << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> dequeuedNode = queue.dequeue();

        if (dequeuedNode != nullptr)
        {
            std::cout << dequeuedNode->data << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << queue << std::endl;
    std::cout << "queue.first() = (" << queue.first()->data << ", " << queue.first()->height << ")" << std::endl;
    std::cout << "queue.last() = (" << queue.last()->data << ", " << queue.last()->height << ")" << std::endl;

    std::cout << "******************************************************************************************************" << std::endl;
}

void testStack(LinkedListStack::Stack& stack)
{
    std::cout << "********************************************* TEST STACK *********************************************" << std::endl;
    std::cout << stack << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.pop() = " << stack.pop() << std::endl;

    for (unsigned int i = 0; i < 12; ++i)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> treeNode = std::make_shared<ComplexTypes::AVLTreeNode>(i + 1, 1U, nullptr, nullptr);
        stack.push(treeNode);
        std::cout << stack << std::endl;
    }

    std::cout << "stack.stackTop() = " << stack.stackTop()->data << std::endl;
    std::cout << "stack.peek(3) = " << stack.peek(3)->data << std::endl;
    std::cout << "stack.peek(5) = " << stack.peek(5)->data << std::endl;
    std::cout << "stack.peek(9) = " << stack.peek(9)->data << std::endl;
    std::cout << "stack.peek(10) = " << stack.peek(10)->data << std::endl;
    std::cout << "stack.peek(0) = " << stack.peek(0)->data << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    for (unsigned int i = 0; i < 14; ++i)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> poppedNode = stack.pop();

        if (poppedNode != nullptr)
        {
            std::cout << "Popped node: (" << poppedNode->data << ", " << poppedNode->height << ") " << std::endl;
        }
        std::cout << stack << std::endl;
    }
    std::cout << std::endl;

    std::shared_ptr<ComplexTypes::AVLTreeNode> stackTopNode = stack.stackTop();

    if (stackTopNode != nullptr)
    {
        std::cout << "stack.stackTop() = " << stackTopNode->data << std::endl;
    }
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    std::cout << "******************************************************************************************************" << std::endl;
}
#endif

int main()
{
    RedBlackTree::RedBlackTree redBlackTree;
    
    testRedBlackTree(redBlackTree);

#if 0
    LinkedListQueue::Queue queue;
    LinkedListStack::Stack stack;

    testQueue(queue);
    testStack(stack);
#endif

    std::cout << "Hello from Red-black Tree main()." << std::endl;

    return 0;
}