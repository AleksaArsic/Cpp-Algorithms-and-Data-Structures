#include "BinaryTree.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

namespace BinaryTree
{
    // Time Complexity -> o(1)
    // Space Complexity -> o(1)
    BinaryTree::BinaryTree() : root(nullptr)
    { }

    // Time Complexity -> o(1)
    // Space Complexity -> o(n) -> creating n treeNodes and n Nodes = 2n ~ n
    void BinaryTree::createTree()
    {
        LinkedListQueue::Queue queue;
        int data;

        std::cout << "Enter root node value: ";
        std::cin >> data;

        std::shared_ptr<ComplexTypes::TreeNode> treeRoot = std::make_shared<ComplexTypes::TreeNode>(data, nullptr, nullptr);
        std::shared_ptr<ComplexTypes::TreeNode> treeNode = nullptr;
        std::shared_ptr<ComplexTypes::TreeNode> node;

        root = treeRoot;
        queue.enqueue(treeRoot);

        while (!queue.isEmpty())
        {
            node = queue.dequeue();

            std::cout << "Enter left child of " << node->data << ": ";
            std::cin >> data;

            if (data != -1)
            {
                treeNode = std::make_shared<ComplexTypes::TreeNode>(data, nullptr, nullptr);
                node->left = treeNode;
                queue.enqueue(treeNode);
            }

            std::cout << "Enter right child of " << node->data << ": ";
            std::cin >> data;

            if (data != -1)
            {
                treeNode = std::make_shared<ComplexTypes::TreeNode>(data, nullptr, nullptr);
                node->right = treeNode;
                queue.enqueue(treeNode);
            }
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PreorderTraversal() const
    {
        std::cout << "Preorder traversal: " << std::endl;
        PreorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::InorderTraversal() const
    {
        std::cout << "Inorder traversal: " << std::endl;
        InorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PostorderTraversal() const
    {
        std::cout << "Postorder traversal: " << std::endl;
        PostorderTraversal(root);
        std::cout << std::endl;
    }

    // Time Complexity -> o(n) -> while executes for n TreeNode times
    // Space Complexity -> o(1)
    void BinaryTree::LevelorderTraversal() const
    {
        std::cout << "Level traversal: " << std::endl;

        LinkedListQueue::Queue queue;

        if (root != nullptr)
        {
            queue.enqueue(root);

            while (!queue.isEmpty())
            {
                std::shared_ptr<ComplexTypes::TreeNode> treeNode = queue.dequeue();

                std::cout << treeNode->data << " ";

                if (treeNode->left != nullptr)
                {
                    queue.enqueue(treeNode->left);
                }
                if (treeNode->right != nullptr)
                {
                    queue.enqueue(treeNode->right);
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativePreorderTraversal() const
    {
        std::cout << "Iterative Preorder traversal: " << std::endl;

        LinkedListStack::Stack stack;
        std::shared_ptr<ComplexTypes::TreeNode> node = root;

        while (!stack.isEmpty() || node != nullptr)
        {
            if (node != nullptr)
            {
                std::cout << node->data << " ";

                stack.push(node);
                node = node->left;
            }
            else
            {
                node = stack.pop();
                node = node->right;
            }
        }


        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativeInorderTraversal() const
    {
        std::cout << "Iterative Inorder traversal: " << std::endl;

        std::shared_ptr<ComplexTypes::TreeNode> node = root;
        LinkedListStack::Stack stack;

        while (!stack.isEmpty() || node != nullptr)
        {
            if (node != nullptr)
            {
                stack.push(node);
                node = node->left;
            }
            else
            {
                node = stack.pop();
                std::cout << node->data << " ";
                node = node->right;
            }
        }

        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativePostorderTraversal() const
    {
        std::cout << "Iterative Postorder traversal: " << std::endl;

        std::shared_ptr<ComplexTypes::TreeNode> node = root;
        LinkedListStack::Stack stack;
        bool alreadyPushed = false;

        while (!stack.isEmpty() || node != nullptr)
        {
            if (node != nullptr)
            {
                stack.push(node, false);
                node = node->left;
            }
            else
            {
                alreadyPushed = stack.isTopAlreadyPushed();
                node = stack.pop();
                if (alreadyPushed == false)
                {
                    stack.push(node, true);
                    node = node->right;
                }
                else
                {
                    std::cout << node->data << " ";
                    node = nullptr;
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            std::cout << node->data << " ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            InorderTraversal(node->left);
            std::cout << node->data << " ";
            InorderTraversal(node->right);
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::Height() const
    {
        return Height(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountNodes() const
    {
        return CountNodes(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountLeafNodes() const
    {
        return CountLeafNodes(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg1Nodes() const
    {
        return CountDeg1Nodes(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg2Nodes() const
    {
        return CountDeg2Nodes(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg1or2Nodes() const
    {
        return CountDeg1or2Nodes(root);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        unsigned int x = 0;
        unsigned int y = 0;

        if (node == nullptr)
        {
            return 0;
        }

        x = Height(node->left);
        y = Height(node->right);

        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountNodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        unsigned int x = 0;
        unsigned int y = 0;

        if (node != nullptr)
        {
            x = CountNodes(node->left);
            y = CountNodes(node->right);

            return x + y + 1;
        }

        return 0;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountLeafNodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        unsigned int x = 0;
        unsigned int y = 0;

        if (node != nullptr)
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                return CountLeafNodes(node->left) + CountLeafNodes(node->right) + 1;
            }
            else
            {
                return CountLeafNodes(node->left) + CountLeafNodes(node->right);
            }
        }

        return 0;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg1Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            // Logical XOR operation
            //if ((node->left != nullptr && node->right == nullptr) || 
            //    (node->left == nullptr && node->right != nullptr))
            //if(!node->left != !node->right) // XOR
            if(node->left != nullptr ^ node->right != nullptr) // XOR
            {
                return CountDeg1Nodes(node->left) + CountDeg1Nodes(node->right) + 1;
            }
            else
            {
                return CountDeg1Nodes(node->left) + CountDeg1Nodes(node->right);
            }
        }

        return 0;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg2Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            if (node->left != nullptr && node->right != nullptr)
            {
                return CountDeg2Nodes(node->left) + CountDeg2Nodes(node->right) + 1;
            }
            else
            {
                return CountDeg2Nodes(node->left) + CountDeg2Nodes(node->right);
            }
        }

        return 0;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::CountDeg1or2Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            if (node->left != nullptr || node->right != nullptr)
            {
                return CountDeg1or2Nodes(node->left) + CountDeg1or2Nodes(node->right) + 1;
            }
            else
            {
                return CountDeg1or2Nodes(node->left) + CountDeg1or2Nodes(node->right);
            }
        }

        return 0;
    }
}