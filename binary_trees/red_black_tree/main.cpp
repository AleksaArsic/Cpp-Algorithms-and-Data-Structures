#include <iostream>
#include <memory>
#include <vector>
#include "LinkedListQueue.hpp"
#include "LinkedListStack.hpp"
#include "RedBlackTree.hpp"

void testRedBlackTree(RedBlackTree::RedBlackTree& tree)
{
    std::cout << "********************************************* TEST TREE *********************************************" << std::endl;

    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(30);
    tree.Insert(50);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(70);
    tree.Insert(80);
    tree.Insert(4);
    tree.Insert(8);

    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();
    tree.InorderTraversal();
    tree.IterativeInorderTraversal();
    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();
    tree.LevelorderTraversal();

    std::cout << "Height of a Tree: " << tree.Height() << std::endl;

    std::cout << "Delete element." << std::endl;

    tree.DeleteElement(40);
    tree.DeleteElement(70);
    tree.DeleteElement(8);
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();
    tree.InorderTraversal();
    tree.IterativeInorderTraversal();
    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();
    tree.LevelorderTraversal();

    std::cout << "*****************************************************************************************************" << std::endl;
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
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>
                                                                (ComplexTypes::NodeColorClass::NodeColor::RED, i + 1, nullptr, nullptr);
        stack.push(treeNode);
        std::cout << stack << std::endl;
    }

    std::cout << "stack.stackTop() = (" << stack.stackTop()->data << ", " << stack.stackTop()->color << ")" << std::endl;
    std::cout << "stack.peek(3) = (" << stack.peek(3)->data << ", " << stack.peek(3)->color << ")" << std::endl;
    std::cout << "stack.peek(5) = (" << stack.peek(5)->data << ", " << stack.peek(5)->color << ")" << std::endl;
    std::cout << "stack.peek(9) = (" << stack.peek(9)->data << ", " << stack.peek(9)->color << ")" << std::endl;
    std::cout << "stack.peek(10) = (" << stack.peek(10)->data << ", " << stack.peek(10)->color << ")" << std::endl;
    std::cout << "stack.peek(0) = (" << stack.peek(0)->data << ", " << stack.peek(0)->color << ")" << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    for (unsigned int i = 0; i < 14; ++i)
    {
        std::shared_ptr<ComplexTypes::TreeNode> poppedNode = stack.pop();

        if (poppedNode != nullptr)
        {
            std::cout << "Popped node: (" << poppedNode->data << ", " << poppedNode->color << ") " << std::endl;
        }
        std::cout << stack << std::endl;
    }
    std::cout << std::endl;

    std::shared_ptr<ComplexTypes::TreeNode> stackTopNode = stack.stackTop();

    if (stackTopNode != nullptr)
    {
        std::cout << "stack.stackTop() = (" << stackTopNode->data << ", " << stackTopNode->color << ")" << std::endl;
    }
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

    std::cout << "******************************************************************************************************" << std::endl;
}

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
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>
                                                             (ComplexTypes::NodeColorClass::NodeColor::RED, i + 1, nullptr, nullptr);
        queue.enqueue(treeNode);
        std::cout << queue << std::endl;
    }

    std::cout << "queue.first() = (" << queue.first()->data << ", " << queue.first()->color << ")" << std::endl;
    std::cout << "queue.last() = (" << queue.last()->data << ", " << queue.last()->color << ")" << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::shared_ptr<ComplexTypes::TreeNode> dequeuedNode = queue.dequeue();

        if (dequeuedNode != nullptr)
        {
            std::cout << "Popped node: (" << dequeuedNode->data << ", " << dequeuedNode->color << ") " << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << queue << std::endl;
    if (queue.first() != nullptr)
    {
        std::cout << "queue.first() = (" << queue.first()->data << ", " << queue.first()->color << ")" << std::endl;
    }
    else
    {
        std::cout << "queue.first() = nullptr" << std::endl;
    }

    if (queue.last() != nullptr)
    {
        std::cout << "queue.last() = (" << queue.last()->data << ", " << queue.last()->color << ")" << std::endl;
    }
    else
    {
        std::cout << "queue.last() = nullptr" << std::endl;
    }

    std::cout << "******************************************************************************************************" << std::endl;
}

int main()
{
    LinkedListStack::Stack stack;
    LinkedListQueue::Queue queue;
    RedBlackTree::RedBlackTree redBlackTree;
    
    testStack(stack);
    testQueue(queue);
    testRedBlackTree(redBlackTree);

    return 0;
}