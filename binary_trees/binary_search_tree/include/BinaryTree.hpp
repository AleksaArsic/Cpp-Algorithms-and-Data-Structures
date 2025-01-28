#pragma once
#include <memory>
#include <vector>
#include "ComplexTypes.hpp"

namespace BinaryTree
{
    class BinaryTree final
    {
        public:
            BinaryTree();

            void createTreeFromPreorder(std::vector<int> preorder);
            void createTreeFromPostorder(std::vector<int> postorder);
            void Insert(const int data);
            void RInsert(const int data);
            void DeleteElement(const int data);
            [[nodiscard]] bool Search(const unsigned int data) const;
            [[nodiscard]] bool RSearch(const unsigned int data) const;

            void InorderTraversal() const;
            void IterativeInorderTraversal() const;
            void PreorderTraversal() const;
            void IterativePreorderTraversal() const;
            void PostorderTraversal() const;
            void IterativePostorderTraversal() const;

            [[nodiscard]] unsigned int Height() const;

        private:
            std::shared_ptr<ComplexTypes::TreeNode> root;

            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> RInsert(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data);
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> DeleteElement(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data);
            [[nodiscard]] bool RSearch(const std::shared_ptr<ComplexTypes::TreeNode>& node, const unsigned int data) const;
            void InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> InorderSuccessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> InorderPrecessor(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

    };
}