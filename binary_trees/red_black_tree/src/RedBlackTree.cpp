#include "RedBlackTree.hpp"
#include "LinkedListStack.hpp"
#include "LinkedListQueue.hpp"
#include <iostream>

namespace RedBlackTree
{
    // Time complexity -> o(1)
    // Space complexity -> o(n)
    RedBlackTree::RedBlackTree() : root(nullptr)
    { }

    // Time complexity -> minimal - o(logn)
    //                 -> maximal - o(2logn)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::Insert(const int data)
    {
        root = Insert(root, data);
    }

    // Time complexity -> o(logn * logn) = o(2logn)
    // Space complexity -> recursion will occur maximally for the height of the tree
    //                      we have nested recursion for finding inorder replacement
    //                  -> minimal - o(logn * logn) = o(2logn)
    //                  -> maximal - o(logn * 2logn) = (3logn)
    void RedBlackTree::DeleteElement(const int data)
    {
        root = DeleteElement(root, data);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n)
    void RedBlackTree::LevelorderTraversal() const
    {
        std::cout << "Levelorder traversal: " << std::endl;

        if (root != nullptr)
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
            LinkedListQueue::Queue queue;

            queue.enqueue(root);

            while (!queue.isEmpty())
            {
                node = queue.dequeue();
                std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";

                if (node->left != nullptr)
                {
                    queue.enqueue(node->left);
                }

                if (node->right != nullptr)
                {
                    queue.enqueue(node->right);
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::PreorderTraversal() const
    {
        std::cout << "Preorder traversal: " << std::endl;
        PreorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::IterativePreorderTraversal() const
    {
        std::cout << "Iterative Preorder traversal: " << std::endl;

        if (root != nullptr)
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
            LinkedListStack::Stack stack; 

            while (!stack.isEmpty() || node != nullptr)
            {
                if (node != nullptr)
                {
                    std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
                    stack.push(node);
                    node = node->left;
                }
                else
                {
                    node = stack.pop();
                    node = node->right;
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::InorderTraversal() const
    {
        std::cout << "Inorder traversal: " << std::endl;
        InorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::IterativeInorderTraversal() const
    {
        std::cout << "Iterative Inorder traversal: " << std::endl;

        if (root != nullptr)
        {
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
                    std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
                    node = node->right;
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::PostorderTraversal() const
    {
        std::cout << "Postorder traversal: " << std::endl;
        PostorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::IterativePostorderTraversal() const
    {
        std::cout << "Iterative Postorder traversal: " << std::endl;

        if (root != nullptr)
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
            LinkedListStack::Stack stack;
            bool isAlreadyPushed = false;

            while (!stack.isEmpty() || node != nullptr)
            {
                if (node != nullptr)
                {
                    stack.push(node);
                    node = node->left;
                }
                else
                {
                    isAlreadyPushed = stack.isTopAlreadyPushed();
                    node = stack.pop();

                    if (isAlreadyPushed == true)
                    {
                        std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
                        node = nullptr;
                    }
                    else
                    {
                        stack.push(node, true);
                        node = node->right;
                    }
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    [[nodiscard]] unsigned int RedBlackTree::Height() const
    {
        return Height(root);
    }

    // Time complexity -> minimal - o(logn)
    //                 -> maximal - o(2logn)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RedBlackTree::Insert(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            // by default we insert "RED" node into the Red-Black Tree
            return std::make_shared<ComplexTypes::TreeNode>(ComplexTypes::NodeColorClass::NodeColor::RED, data, nullptr, nullptr);
        }

        if (node->data > data)
        {
            node->left = Insert(node->left, data);
        }
        else if(node->data < data)
        {
            node->right = Insert(node->right, data);
        }

        // perform color balancing
        ColorBalanceNode(node); // o(1)

        return node;
    }

    // Time complexity -> o(logn * logn) = o(2logn)
    // Space complexity -> recursion will occur maximally for the height of the tree
    //                      we have nested recursion for finding inorder replacement
    //                  -> minimal - o(logn * logn) = o(2logn)
    //                  -> maximal - o(logn * 2logn) = (3logn)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RedBlackTree::DeleteElement(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->data == data && node->left == nullptr && node->right == nullptr)
        {
            node.reset();
            return node;
        }

        if (node->data > data)
        {
            // move left
            node->left = DeleteElement(node->left, data);
        }
        else if (node->data < data)
        {
            // move right
            node->right = DeleteElement(node->right, data);
        }
        else
        {
            // match
            // when deleting node, we move the inorder successor or inorder precessor data
            // to the node we want to delete and physically delete the node of inorder successor or inorder precessor
            // based on the height of the left and right subtree determine which inorder replacement to take
            std::shared_ptr<ComplexTypes::TreeNode> inorderReplacement = nullptr;

            if (Height(node->left) > Height(node->right))
            {
                // take the inorder precessor
                inorderReplacement = InorderPrecessor(node); // minimal - o(logn)
                node->left = DeleteElement(node->left, inorderReplacement->data);
            }
            else
            {
                // take the inorder successor
                inorderReplacement = InorderSucessor(node); // minimal - o(logn)
                node->right = DeleteElement(node->right, inorderReplacement->data);
            }

            node->data = inorderReplacement->data;

            // perform color balancing
            ColorBalanceNode(node); // o(1)
        }

        return node;
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            InorderTraversal(node->left);
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
            InorderTraversal(node->right);
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    void RedBlackTree::PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> minimal - o(logn)
    //                  -> maximal - o(2logn)
    [[nodiscard]] unsigned int RedBlackTree::Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node == nullptr)
        {
            return 0U;
        }

        unsigned int x = Height(node->left) + 1;
        unsigned int y = Height(node->right) + 1;

        return (x > y) ? x : y;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::ColorBalanceNode(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        // Check if the node and parent are of the color "RED"
        // If they are, perform rotations.
        // When performing rotations, take into the consideration
        // the color of the uncle.
        if (node == root)
        {
            node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);
        }

        if (node->right != nullptr && node->right->right != nullptr)
        {
            if (node->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED &&
                node->right->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
            {
                if (node->left == nullptr || node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::BLACK)
                {
                    // uncle does not exist or uncle is black:
                    // perform RR rotation
                    RRRotation(node); // o(1)
                }
                else if (node->left != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node); // o(1)
                }
            }
        }

        if (node->left != nullptr && node->left->left != nullptr)
        {
            if (node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED &&
                node->left->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
            {
                if (node->right == nullptr || node->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::BLACK)
                {
                    // uncle does not exists or uncle is black:
                    // perform LL rotation
                    LLRotation(node); // o(1)
                }
                else if (node->right != nullptr && node->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node); // o(1)
                }
            }
        }
        
        if (node->right != nullptr && node->right->left != nullptr)
        {
            if (node->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED &&
                node->right->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
            {
                if (node->left == nullptr || node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::BLACK)
                {
                    // uncle does not exists or uncle is black:
                    // perform RL rotation
                    RLRotation(node); // o(1)
                }
                else if (node->left != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node); // o(1)
                }
            }
            
        }
        
        if (node->left != nullptr && node->left->right != nullptr)
        {
            if (node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED &&
                node->left->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
            {
                if (node->right == nullptr || node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::BLACK)
                {
                    // uncle does not exists or uncle is black:
                    // perform LR rotation
                    LRRotation(node); // o(1)
                }
                else if (node->right != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red
                    // change colors
                    UncleRedRepaintNodes(node); // o(1)
                }
            }
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::LLRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeLeftChild = node->left;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeLeftChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->left = nodeLeftChild->right;
        nodeLeftChild->right = node;
        node = nodeLeftChild;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::LRRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeLeftRightChild = node->left->right;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeLeftRightChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->left->right = nodeLeftRightChild->left;
        nodeLeftRightChild->left = node->left;
        node->left = nodeLeftRightChild->right;
        nodeLeftRightChild->right = node;
        node = nodeLeftRightChild;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::RRRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeRightChild = node->right;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeRightChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->right = nodeRightChild->left;
        nodeRightChild->left = node;
        node = nodeRightChild;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::RLRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeRightLeftChild = node->right->left;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeRightLeftChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->right->left = nodeRightLeftChild->right;
        nodeRightLeftChild->right = node->right;
        node->right = nodeRightLeftChild->left;
        nodeRightLeftChild->left = node;
        node = nodeRightLeftChild;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void RedBlackTree::UncleRedRepaintNodes(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        if (node != root)
        {
            node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        }

        node->right->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);
        node->left->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);
    }

    // Time complexity -> minimal - o(logn)
    //                 -> maximal - o(2logn)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RedBlackTree::InorderPrecessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> precessor = node->left;

        if (precessor != nullptr)
        {
            while (precessor->right != nullptr)
            {
                precessor = precessor->right;
            }
        }

        return precessor;
    }

    // Time complexity -> minimal - o(logn)
    //                 -> maximal - o(2logn)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RedBlackTree::InorderSucessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> succesor = node->right;

        if (succesor != nullptr)
        {
            while (succesor->left != nullptr)
            {
                succesor = succesor->left;
            }
        }

        return succesor;
    }
}