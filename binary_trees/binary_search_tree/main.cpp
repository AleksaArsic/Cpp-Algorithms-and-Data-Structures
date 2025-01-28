#include <iostream>
#include <memory>
#include <vector>
//#include "Queue.hpp"
#include "Stack.hpp"
#include "BinaryTree.hpp"

#if 0
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
#endif

void testStack(LinkedListStack::Stack& stack)
{
    std::cout << "********************************************* TEST STACK *********************************************" << std::endl;
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

    std::cout << "******************************************************************************************************" << std::endl;
}

void testFirstTree(BinaryTree::BinaryTree& tree)
{
    std::cout << "********************************************* TEST TREE *********************************************" << std::endl;

    std::vector<int> vecTreeNodes = { 12, 8, 3, 55, 18, 62, 44, 23, 3, 0, 5 };

    for (unsigned int i = 0; i < vecTreeNodes.size(); ++i)
    {
        tree.Insert(vecTreeNodes[i]);
    }

    tree.RInsert(-1);
    tree.RInsert(-2);
    tree.RInsert(7);
    tree.RInsert(7);
    tree.RInsert(77);

    tree.InorderTraversal();
    tree.IterativeInorderTraversal();

    tree.DeleteElement(55);

    if (tree.Search(77))
    {
        std::cout << "Node with data: " << 77 << " is found." << std::endl;
    }
    else
    {
        std::cout << "Node with data: " << 77 << " is not found." << std::endl;
    }

    if (tree.Search(33))
    {
        std::cout << "Node with data: " << 33 << " is found." << std::endl;
    }
    else
    {
        std::cout << "Node with data: " << 33 << " is not found." << std::endl;
    }

    if (tree.RSearch(77))
    {
        std::cout << "Node with data: " << 77 << " is found." << std::endl;
    }
    else
    {
        std::cout << "Node with data: " << 77 << " is not found." << std::endl;
    }

    if (tree.RSearch(33))
    {
        std::cout << "Node with data: " << 33 << " is found." << std::endl;
    }
    else
    {
        std::cout << "Node with data: " << 33 << " is not found." << std::endl;
    }

    std::cout << "Height of a Tree: " << tree.Height() << std::endl;
    tree.InorderTraversal();
    tree.IterativeInorderTraversal();

    std::cout << "*****************************************************************************************************" << std::endl;
}

void testSecondTree(BinaryTree::BinaryTree& tree)
{
    std::cout << "********************************************* TEST TREE *********************************************" << std::endl;

    std::vector<int> preorder = { 30, 20, 10, 15, 25, 40, 50, 45 };

    std::cout << "Preorder vector: ";
    for (unsigned int i = 0; i < preorder.size(); ++i)
    {
        std::cout << preorder[i] << " ";
    }
    std::cout << std::endl;

    tree.createTreeFromPreorder(preorder);
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();

    std::cout << "*****************************************************************************************************" << std::endl;
}

void testThirdTree(BinaryTree::BinaryTree& tree)
{
    std::cout << "********************************************* TEST TREE *********************************************" << std::endl;

    std::vector<int> postorder = { 15, 10, 25, 20, 45, 50, 40, 30 };

    std::cout << "Postorder vector: ";
    for (unsigned int i = 0; i < postorder.size(); ++i)
    {
        std::cout << postorder[i] << " ";
    }
    std::cout << std::endl;

    tree.createTreeFromPostorder(postorder);
    tree.PostorderTraversal();
    tree.IterativePostorderTraversal();
    tree.PreorderTraversal();
    tree.IterativePreorderTraversal();

    std::cout << "*****************************************************************************************************" << std::endl;
}

int main()
{
    LinkedListStack::Stack stack;
    BinaryTree::BinaryTree firstTree;
    BinaryTree::BinaryTree secondTree;
    BinaryTree::BinaryTree thirdTree;

    testStack(stack);
    testFirstTree(firstTree);
    testSecondTree(secondTree);
    testThirdTree(thirdTree);
    
    return 0;
}