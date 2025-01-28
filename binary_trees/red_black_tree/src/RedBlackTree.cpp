#include "RedBlackTree.hpp"
#include <iostream>

namespace RedBlackTree
{
    RedBlackTree::RedBlackTree() : root(nullptr)
    { }

    void RedBlackTree::Insert(const int data)
    {
        root = Insert(root, data);
    }

    void RedBlackTree::DeleteElement(const int data)
    {
        root = DeleteElement(root, data);
    }

    void RedBlackTree::LevelorderTraversal() const
    {

    }

    void RedBlackTree::PreorderTraversal() const
    {
        std::cout << "Preorder traversal: " << std::endl;
        PreorderTraversal(root);
        std::cout << std::endl;
    }

    void RedBlackTree::IterativePreorderTraversal() const
    {

    }

    void RedBlackTree::InorderTraversal() const
    {
        std::cout << "Inorder traversal: " << std::endl;
        InorderTraversal(root);
        std::cout << std::endl;
    }

    void RedBlackTree::IterativeInorderTraversal() const
    {

    }

    void RedBlackTree::PostorderTraversal() const
    {
        std::cout << "Postorder traversal: " << std::endl;
        PostorderTraversal(root);
        std::cout << std::endl;
    }

    void RedBlackTree::IterativePostorderTraversal() const
    {

    }

    [[nodiscard]] unsigned int RedBlackTree::Height() const
    {
        return Height(root);
    }

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
        ColorBalanceNode(node);

        return node;
    }

    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RedBlackTree::DeleteElement(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data)
    {
        return nullptr;
    }

    void RedBlackTree::PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }
    }

    void RedBlackTree::InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            InorderTraversal(node->left);
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
            InorderTraversal(node->right);
        }
    }

    void RedBlackTree::PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            std::cout << "(" << node->data << ", " << node->color.getColor() << ") ";
        }
    }

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
                    RRRotation(node);
                }
                else if (node->left != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node);
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
                    LLRotation(node);
                }
                else if (node->right != nullptr && node->right->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node);
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
                    RLRotation(node);
                }
                else if (node->left != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red:
                    // change colors
                    UncleRedRepaintNodes(node);
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
                    LRRotation(node);
                }
                else if (node->right != nullptr && node->left->color.getColor() == ComplexTypes::NodeColorClass::NodeColor::RED)
                {
                    // uncle exists and uncle is red
                    // change colors
                    UncleRedRepaintNodes(node);
                }
            }

            
        }
    }

    void RedBlackTree::LLRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeLeftChild = node->left;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeLeftChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->left = nodeLeftChild->right;
        nodeLeftChild->right = node;
        node = nodeLeftChild;
    }

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

    void RedBlackTree::RRRotation(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::TreeNode> nodeRightChild = node->right;

        node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        nodeRightChild->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);

        node->right = nodeRightChild->left;
        nodeRightChild->left = node;
        node = nodeRightChild;
    }

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

    void RedBlackTree::UncleRedRepaintNodes(std::shared_ptr<ComplexTypes::TreeNode>& node)
    {
        if (node != root)
        {
            node->color.setColor(ComplexTypes::NodeColorClass::NodeColor::RED);
        }

        node->right->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);
        node->left->color.setColor(ComplexTypes::NodeColorClass::NodeColor::BLACK);
    }
}