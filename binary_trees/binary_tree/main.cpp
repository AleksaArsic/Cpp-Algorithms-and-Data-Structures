#include <iostream>
#include <memory>
#include "Queue.hpp"
#include "Stack.hpp"
#include "BinaryTree.hpp"

void testQueue(LinkedListQueue::Queue& queue)
{
    std::cout << queue << std::endl;
    std::cout << "queue.isEmpty() = " << queue.isEmpty() << std::endl;
    std::cout << "queue.isFull() = " << queue.isFull() << std::endl;
    std::cout << "queue.dequeue() = " << queue.dequeue() << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;


    for (unsigned int i = 0; i < 12; ++i)
    {
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>(i + 1, nullptr, nullptr);
        queue.enqueue(treeNode);
        std::cout << queue << std::endl;
    }

    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;

    std::cout << "Dequeueing: " << std::endl;
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::cout << queue.dequeue()->data << " ";
    }
    std::cout << std::endl;

    std::cout << "After dequeueing: " << queue << std::endl;
    std::cout << "queue.first() = " << queue.first() << std::endl;
    std::cout << "queue.last() = " << queue.last() << std::endl;
}

void testStack(LinkedListStack::Stack& stack)
{
    std::cout << stack << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.pop() = " << stack.pop() << std::endl;

    for (unsigned int i = 0; i < 12; ++i)
    {
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = std::make_shared<ComplexTypes::TreeNode>(i + 1, nullptr, nullptr);
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
        std::shared_ptr<ComplexTypes::TreeNode> poppedNode = stack.pop();

        if (poppedNode != nullptr)
        {
            std::cout << poppedNode->data << " ";
        }
        std::cout << stack << std::endl;
    }
    std::cout << std::endl;

    std::shared_ptr<ComplexTypes::TreeNode> stackTopNode = stack.stackTop();

    if (stackTopNode != nullptr)
    {
        std::cout << "stack.stackTop() = " << stackTopNode->data << std::endl;
    }
    std::cout << "stack.isFull() = " << stack.isFull() << std::endl;
    std::cout << "stack.isEmpty() = " << stack.isEmpty() << std::endl;

}

int main()
{
    LinkedListQueue::Queue queue;
    LinkedListStack::Stack stack;
    BinaryTree::BinaryTree tree;

    testQueue(queue);
    testStack(stack);

    tree.createTree();
    
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();

    tree.InorderTraversal();
    tree.IterativeInorderTraversal();

    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();

    tree.LevelorderTraversal();
    
    std::cout << "Height of a Tree: " << tree.Height() << std::endl;
    std::cout << "Number of nodes in a Tree: " << tree.CountNodes() << std::endl;
    std::cout << "Number of leafs in a Tree: " << tree.CountLeafNodes() << std::endl;
    std::cout << "Number of Degree 1 nodes in a Tree: " << tree.CountDeg1Nodes() << std::endl;
    std::cout << "Number of Degree 2 nodes in a Tree: " << tree.CountDeg2Nodes() << std::endl;
    std::cout << "Number of Degree 1 or Degree 2 nodes in a Tree: " << tree.CountDeg1or2Nodes() << std::endl;

    return 0;
}