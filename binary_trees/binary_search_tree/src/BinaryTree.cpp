#include "BinaryTree.hpp"
#include "Stack.hpp"

namespace BinaryTree
{
    // Time complexity -> o(1)
    // Space complexity -> o(1)
    BinaryTree::BinaryTree() : root(nullptr)
    {
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) - n additional TreeNodes are created
    void BinaryTree::createTreeFromPreorder(std::vector<int> preorder)
    {
        LinkedListStack::Stack stack;
        std::shared_ptr<ComplexTypes::TreeNode> node = root;
        unsigned int i = 0;

        while(i < preorder.size())
        {
            std::shared_ptr<ComplexTypes::TreeNode> newNode = std::make_shared<ComplexTypes::TreeNode>(preorder[i], nullptr, nullptr);

            if (root == nullptr)
            {
                root = node = newNode;
                i++;
            }
            else
            {
                if (node->data > newNode->data)
                {
                    node->left = newNode;
                    stack.push(node);
                    node = node->left;
                    i++;
                }
                else
                {
                    std::shared_ptr<ComplexTypes::TreeNode> stackTop = stack.stackTop();

                    if (stackTop != nullptr && stackTop->data < newNode->data)
                    {
                        node = stack.pop();
                    }
                    else
                    {
                        node->right = newNode;
                        node = node->right;
                        i++;
                    }
                }
            }
        }
    }

    // Time complexity -> o(n)
    // Space complexity -> o(n) - n additional TreeNodes are created
    void BinaryTree::createTreeFromPostorder(std::vector<int> postorder)
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = root;
        LinkedListStack::Stack stack;
        int i = postorder.size() - 1;

        while(i >= 0L)
        {
            std::shared_ptr<ComplexTypes::TreeNode> newNode = std::make_shared<ComplexTypes::TreeNode>(postorder[i], nullptr, nullptr);

            if (root == nullptr)
            {
                root = node = newNode;
                --i;
            }
            else
            {
                if (newNode->data > node->data)
                {
                    node->right = newNode;
                    stack.push(node);
                    node = node->right;
                    --i;
                }
                else
                {
                    std::shared_ptr<ComplexTypes::TreeNode> stackTop = stack.stackTop();

                    if (stackTop != nullptr && newNode->data < stackTop->data)
                    {
                        node = stack.pop();
                    }
                    else
                    {
                        node->left = newNode;
                        node = node->left;
                        --i;
                    }
                }
            }
        }
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(1)
    void BinaryTree::Insert(const int data)
    {
        std::shared_ptr<ComplexTypes::TreeNode> newNode = std::make_shared<ComplexTypes::TreeNode>(data, nullptr, nullptr);

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
            std::shared_ptr<ComplexTypes::TreeNode> tail = nullptr;

            while (node != nullptr)
            {
                tail = node;

                if (data > node->data)
                {
                    node = node->right;
                }
                else if (data < node->data)
                {
                    node = node->left;
                }
                else
                {
                    return; // Binary trees do not have duplicates.
                }
            }

            (data > tail->data) ? tail->right = newNode : tail->left = newNode;
        }
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    void BinaryTree::RInsert(const int data)
    {        
        root = RInsert(root, data);
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    void BinaryTree::DeleteElement(const int data)
    {
        root = DeleteElement(root, data);
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] bool BinaryTree::Search(const unsigned int data) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> node = root;
        bool isDataFound = false;

        while (node != nullptr)
        {
            if (data < node->data)
            {
                node = node->left;
            }
            else if (data > node->data)
            {
                node = node->right;
            }
            else
            {
                isDataFound = true;
                break;
            }
        }

        return isDataFound;
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)    
    // Space complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    [[nodiscard]] bool BinaryTree::RSearch(const unsigned int data) const
    {
        return RSearch(root, data);
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::InorderTraversal() const
    {
        std::cout << "[BinaryTree] InorderTraversal(): ";
        InorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativeInorderTraversal() const
    {
        std::cout << "[BinaryTree] IterativeInorderTraversal(): ";

        if (root != nullptr)
        {
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
            LinkedListStack::Stack stack;

            if (node != nullptr)
            {
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
            }
        }
        
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PreorderTraversal() const
    {
        std::cout << "[BinaryTree] PreorderTraversal(): ";
        PreorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativePreorderTraversal() const
    {
        std::cout << "[BinaryTree] IterativePreorderTraversal(): ";

        if (root != nullptr)
        {
            LinkedListStack::Stack stack;
            std::shared_ptr<ComplexTypes::TreeNode> node = root;

            stack.push(node);

            while (!stack.isEmpty())
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
        }
        
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::PostorderTraversal() const
    {
        std::cout << "[BinaryTree] PostorderTraversal(): ";
        PostorderTraversal(root);
        std::cout << std::endl;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::IterativePostorderTraversal() const
    {
        std::cout << "[BinaryTree] IterativePostorderTraversal(): ";

        if (root != nullptr)
        {
            LinkedListStack::Stack stack;
            std::shared_ptr<ComplexTypes::TreeNode> node = root;
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
                        std::cout << node->data << " ";
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

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::Height() const
    {
        return Height(root);
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    std::shared_ptr<ComplexTypes::TreeNode> BinaryTree::RInsert(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            return std::make_shared<ComplexTypes::TreeNode>(data, nullptr, nullptr);
        }
        else
        {
            if (data < node->data)
            {
                node->left = RInsert(node->left, data);
            }
            else if(data > node->data)
            {
                node->right = RInsert(node->right, data);
            }
            
        }
        
        return node;
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    // Space complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> BinaryTree::DeleteElement(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->data == data && node->left == nullptr && node->right == nullptr)
        {
            node.reset();
            return nullptr;
        }

        // we should find the element that is equal to data
        // for that we need to traverse through the tree
        if (node->data > data)
        {
            node->left = DeleteElement(node->left, data);
        }
        else if (node->data < data)
        {
            node->right = DeleteElement(node->right, data);
        }
        else
        {
            // if we found the node that needs to be deleted
            // we need to find it's inorder precessor or successor,
            // make a swap of data, and delete precessor or succesor node.
            // if precessor or succesor have children, the process repeats 
            // until the precessor or succesor node is a leaf node.
            // it does not matter with which node we will replace the old (precessor or successor).
            // for the demonstrating purposes we will replace it with the precessor when
            // the height of the left subtree is greater than the height of the right subtree
            // and successor when it's the other way around

            if (Height(node->left) > Height(node->right))
            {
                std::shared_ptr<ComplexTypes::TreeNode> precessor = InorderPrecessor(node->left);

                node->data = precessor->data;
                node->left = DeleteElement(node->left, precessor->data);
            }
            else
            {
                std::shared_ptr<ComplexTypes::TreeNode> successor = InorderSuccessor(node->right);

                node->data = successor->data;
                node->right = DeleteElement(node->right, successor->data);
            }
        }

        return node;
    }

    // Time complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)    
    // Space complexity -> o(h) -> logn <= h <= n
    //                 -> min -> o(logn)
    //                 -> max -> o(n)
    [[nodiscard]] bool BinaryTree::RSearch(const std::shared_ptr<ComplexTypes::TreeNode>& node, const unsigned int data) const
    {
        if (node != nullptr)
        {
            if (data < node->data)
            {
                return RSearch(node->left, data);
            }
            else if (data > node->data)
            {
                return RSearch(node->right, data);
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    void BinaryTree::InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
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
    void BinaryTree::PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
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
    void BinaryTree::PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node != nullptr)
        {
            PostorderTraversal(node->left);
            PostorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    // Time Complexity -> o(logn)
    // Space Complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> BinaryTree::InorderSuccessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> successor = node;
       
        while (successor != nullptr && successor->left != nullptr)
        {
            successor = successor->left;
        }

        return successor;
    }

    // Time Complexity -> o(logn)
    // Space Complexity -> o(1)
    [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> BinaryTree::InorderPrecessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        std::shared_ptr<ComplexTypes::TreeNode> precessor = node;

        while (precessor != nullptr && precessor->right != nullptr)
        {
            precessor = precessor->right;
        }

        return precessor;
    }

    // Time complexity  -> o(n) -> need to call it for n nodes
    // Space complexity -> o(h) -> height of the tree dictates the size of the stack
    //                  -> logn <= h <= n
    //                  -> min -> o(logn)
    //                  -> max -> o(n)
    [[nodiscard]] unsigned int BinaryTree::Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const
    {
        if (node == nullptr)
        {
            return 0U;
        }

        unsigned int x = Height(node->left) + 1U;
        unsigned int y = Height(node->right) + 1U;

        return (x > y) ? x : y;
    }
}