#include "AVLBinaryTree.hpp"
#include "LinkedListStack.hpp"
#include "LinkedListQueue.hpp"
#include <iostream>

namespace AVLBinaryTree
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    AVLTree::AVLTree() : root(nullptr)
    { }

    // Time complexity -> o(n)
    // Space complexity -> o(logn)
    void AVLTree::Insert(const int data)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> newNode = std::make_shared<ComplexTypes::AVLTreeNode>(data, 0U, nullptr, nullptr);

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            std::shared_ptr<ComplexTypes::AVLTreeNode> node = root;
            std::shared_ptr<ComplexTypes::AVLTreeNode> tail = nullptr;

            while (node != nullptr)
            {
                if (node->data > newNode->data)
                {
                    tail = node;
                    node = node->left;
                }
                else if (node->data < newNode->data)
                {
                    tail = node;
                    node = node->right;
                }
                else
                {
                    return; // Binary tree does not have duplicates
                }
            }

            (tail->data < newNode->data) ? tail->right = newNode : tail->left = newNode;

            (void)Height(root); // time - o(n), space - o(logn)
        }
    }

    // Time complexity -> we need to traverse through logn nodes, which is minimal height 'h' of the tree
    //                 -> o(h)
    //                 -> min - o(logn)
    //                 -> max - o(n)
    // Space complexity -> we need to traverse through logn nodes, which is minimal height 'h' of the tree
    //                 -> o(h)
    //                 -> min - o(logn)
    //                 -> max - o(1.44logn)
    void AVLTree::RInsert(const int data)
    {
        root = RInsert(root, data);
    }

    // Time complexity -> we need to find the element to delete recursively, which takes o(logn) time. 
    //                    we are searching for inorder succesor or inorder precessor which takes o(n) time.
    //                    overall performance is therefore o(n * logn).
    // Space complexity -> we need to find the element to delete recursively, which takes o(logn) space.
    //                     overall stack size is than the size of recursion, which is o(logn). 
    void AVLTree::DeleteElement(const int data)
    {
        root = DeleteElement(root, data);
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) -> we need additional n sized queue
    void AVLTree::LevelorderTraversal() const
    {
        std::cout << "Levelorder traversal: ";
        
        if (root != nullptr)
        {
            LinkedListQueue::Queue queue;

            queue.enqueue(root);

            while (!queue.isEmpty())
            {
                std::shared_ptr<ComplexTypes::AVLTreeNode> node = queue.dequeue();
                std::cout << "(" << node->data << ", " << node->height << ") ";

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

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::PreorderTraversal() const
    {
        std::cout << "Preorder traversal: ";
        PreorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::IterativePreorderTraversal() const
    {
        std::cout << "Iterative Preorder traversal: ";

        if (root != nullptr)
        {
            LinkedListStack::Stack stack;
            std::shared_ptr<ComplexTypes::AVLTreeNode> node = root;

            while (!stack.isEmpty() || node != nullptr)
            {
                if (node != nullptr)
                {
                    std::cout << "(" << node->data << ", " << node->height << ") ";
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

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::InorderTraversal() const
    {
        std::cout << "Inorder traversal: ";
        InorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::IterativeInorderTraversal() const
    {
        std::cout << "Iterative Inorder traversal: ";

        if (root != nullptr)
        {
            LinkedListStack::Stack stack;
            std::shared_ptr<ComplexTypes::AVLTreeNode> node = root;

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
                    std::cout << "(" << node->data << ", " << node->height << ") ";
                    node = node->right;
                }
            }
        }

        std::cout << std::endl;
    }

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::PostorderTraversal() const
    {
        std::cout << "Postorder traversal: ";
        PostorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::IterativePostorderTraversal() const
    {
        std::cout << "Iterative Postorder traversal: ";

        if (root != nullptr)
        {
            LinkedListStack::Stack stack;
            std::shared_ptr<ComplexTypes::AVLTreeNode> node = root;
            bool isAlreadyPushed = false;

            while (!stack.isEmpty() || node != nullptr)
            {
                if (node != nullptr)
                {
                    stack.push(node, false);
                    node = node->left;
                }
                else
                {
                    isAlreadyPushed = stack.isTopAlreadyPushed();
                    node = stack.pop();

                    if (isAlreadyPushed)
                    {
                        std::cout << "(" << node->data << ", " << node->height << ") ";
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

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    [[nodiscard]] unsigned int AVLTree::Height() const
    {
        return Height(root);
    }

    // Time complexity -> we need to traverse through logn nodes, which is minimal height 'h' of the tree
    //                 -> o(h)
    //                 -> min - o(logn)
    //                 -> max - o(1.44logn)
    // Space complexity -> we need to traverse through logn nodes, which is minimal height 'h' of the tree
    //                 -> o(h)
    //                 -> min - o(logn)
    //                 -> max - o(1.44logn)
    [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> AVLTree::RInsert(std::shared_ptr<ComplexTypes::AVLTreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            return std::make_shared<ComplexTypes::AVLTreeNode>(data, 1U, nullptr, nullptr); // o(1)
        }

        if (data < node->data)
        {
            node->left = RInsert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = RInsert(node->right, data);
        }

        node->height = Height(node);
        
        if (BalanceFactor(node) == 2L && BalanceFactor(node->left) == 1L) // o(2)
        {
            LLRotation(node); // o(1)
        }
        else if (BalanceFactor(node) == -2L && BalanceFactor(node->right) == -1L) // o(2)
        {
            RRRotation(node); // o(1)
        }
        else if (BalanceFactor(node) == 2L && BalanceFactor(node->left) == -1L) // o(2) 
        {
            LRRotation(node); // o(1)
        }
        else if (BalanceFactor(node) == -2L && BalanceFactor(node->right) == 1L) // o(2)
        {
            RLRotation(node); // o(1)
        }

        return node;
    }

    // Time complexity -> we need to find the element to delete recursively, which takes o(logn) time. 
    //                    we are searching for inorder succesor or inorder precessor which takes o(n) time.
    //                    overall performance is therefore o(n * logn).
    // Space complexity -> we need to find the element to delete recursively, which takes o(logn) space.
    //                     overall stack size is than the size of recursion, which is o(logn).                                        
    std::shared_ptr<ComplexTypes::AVLTreeNode> AVLTree::DeleteElement(std::shared_ptr<ComplexTypes::AVLTreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        if (node->data == data && node->left == nullptr && node->right == nullptr)
        {
            if (node == root)
            {
                root = nullptr;
            }

            node.reset();
            return nullptr;
        }

        if (node->data < data)
        {
            // right
            node->right = DeleteElement(node->right, data);
        }
        else if (node->data > data)
        {
            // left
            node->left = DeleteElement(node->left, data);
        }
        else
        {
            // match
            // we can take inorder precessor or inorder succesor,
            // for example depending on the height of left or right subtree.

            if (Height(node->left) > Height(node->right)) // o(2n)
            {
                std::shared_ptr<ComplexTypes::AVLTreeNode> precessor = InorderPrecessor(node); // o(n)

                node->data = precessor->data;
                node->left = DeleteElement(node->left, precessor->data);
            }
            else
            {
                std::shared_ptr<ComplexTypes::AVLTreeNode> successor = InorderSuccessor(node); // o(n)

                node->data = successor->data;
                node->right = DeleteElement(node->right, successor->data);
            }

            // update height
            node->height = Height(node); // o(n)

            // after deletion from right side we need to perform balancing
            // R1 = RR, R-1 = RL, or R0 = either(R1, R-1)
            // L1 = LL, L-1 = LR or L0 = either(L1, L-1)
            if ((BalanceFactor(node) == 2L) && (BalanceFactor(node->left) == 0L || BalanceFactor(node->left) == 1L)) // o(1)
            {
                LLRotation(node); // o(1)
            }
            else if (BalanceFactor(node) == 2L && BalanceFactor(node->left) == -1L) // o(1)
            {
                LRRotation(node); // o(1)
            }
            else if ((BalanceFactor(node) == -2L) && (BalanceFactor(node->right) == 0L || BalanceFactor(node->right) == -1L)) // o(1)
            {
                RRRotation(node); // o(1)
            }
            else if (BalanceFactor(node) == -2L && BalanceFactor(node->right) == 1L) // o(1)
            {
                RLRotation(node); // o(1)
            }
        }

        return node;
    }

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::PreorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        if (node != nullptr)
        {
            std::cout << "(" << node->data << ", " << node->height << ") ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }
    }

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::InorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        if (node != nullptr)
        {
            InorderTraversal(node->left);
            std::cout << "(" << node->data << ", " << node->height << ") ";
            InorderTraversal(node->right);
        }
    }

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    void AVLTree::PostorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        if (node != nullptr)
        {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            std::cout << "(" << node->data << ", " << node->height << ") ";
        }
    }

    // Time complexity -> we need to call it for n nodes
    //                 -> o(n)
    // Space complexity -> we need to traverse through n nodes, but the recursive call will have
    //                      at most log(n) pushed to stack, which is minimal height of the tree
    //                  -> o(logn) -> minimal
    //                  -> o(1.44logn) -> maximal
    [[nodiscard]] unsigned int AVLTree::Height(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        if (node != nullptr)
        {
            unsigned int x = Height(node->left) + 1;
            unsigned int y = Height(node->right) + 1;

            return (x > y) ? x : y;
        }
        else
        {
            return 0U;
        }
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    [[nodiscard]] int AVLTree::BalanceFactor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        unsigned int hl = (node != nullptr && node->left != nullptr) ? node->left->height : 0;
        unsigned int hr = (node != nullptr && node->right != nullptr) ? node->right->height : 0;

        return hl - hr;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void AVLTree::LLRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> tempNode = node->left;

        node->left = tempNode->right;
        tempNode->right = node;
        node = tempNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void AVLTree::RRRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> tempNode = node->right;

        node->right = tempNode->left;
        tempNode->left = node;
        node = tempNode;
    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void AVLTree::LRRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> tempNode = node;
        std::shared_ptr<ComplexTypes::AVLTreeNode> nodeLeftRight = node->left->right;

        tempNode->left->right = nodeLeftRight->left;
        nodeLeftRight->left = tempNode->left;
        tempNode->left = nodeLeftRight->right;
        nodeLeftRight->right = tempNode;
        node = nodeLeftRight;

    }

    // Time complexity -> o(1)
    // Space complexity -> o(1)
    void AVLTree::RLRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node)
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> tempNode = node;
        std::shared_ptr<ComplexTypes::AVLTreeNode> nodeRightLeft = node->right->left;

        tempNode->right->left = nodeRightLeft->right;
        nodeRightLeft->right = tempNode->right;
        tempNode->right = nodeRightLeft->left;
        nodeRightLeft->left = tempNode;
        node = nodeRightLeft;
    }

    // Time complexity -> o(logn)
    // Space complexity -> o(1)
    std::shared_ptr<ComplexTypes::AVLTreeNode> AVLTree::InorderPrecessor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> precessor = node->left;
        
        while (precessor != nullptr && precessor->right != nullptr)
        {
            precessor = precessor->right;
        }

        return precessor;
    }

    // Time complexity -> o(logn)
    // Space complexity -> o(1)
    std::shared_ptr<ComplexTypes::AVLTreeNode> AVLTree::InorderSuccessor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::AVLTreeNode> successor = node->right;

        while (successor != nullptr && successor->left != nullptr)
        {
            successor = successor->left;
        }

        return successor;
    }
}