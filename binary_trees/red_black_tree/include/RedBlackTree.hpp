#pragma once
#include <memory>
#include "ComplexTypes.hpp"

namespace RedBlackTree
{
    class RedBlackTree final
    {
        public:
            RedBlackTree();

            void Insert(const int data);
            void DeleteElement(const int data);

            void LevelorderTraversal() const;
            void PreorderTraversal() const;
            void IterativePreorderTraversal() const;
            void InorderTraversal() const;
            void IterativeInorderTraversal() const;
            void PostorderTraversal() const;
            void IterativePostorderTraversal() const;

            [[nodiscard]] unsigned int Height() const;

        private:
            std::shared_ptr<ComplexTypes::TreeNode> root;

            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> Insert(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data);
            [[nodiscard]] std::shared_ptr<ComplexTypes::TreeNode> DeleteElement(std::shared_ptr<ComplexTypes::TreeNode>& node, const int data);

            void PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

            [[nodiscard]] unsigned int Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

            void ColorBalanceNode(std::shared_ptr<ComplexTypes::TreeNode>& node);

            void LLRotation(std::shared_ptr<ComplexTypes::TreeNode>& node);
            void LRRotation(std::shared_ptr<ComplexTypes::TreeNode>& node);
            void RRRotation(std::shared_ptr<ComplexTypes::TreeNode>& node);
            void RLRotation(std::shared_ptr<ComplexTypes::TreeNode>& node);

            void UncleRedRepaintNodes(std::shared_ptr<ComplexTypes::TreeNode>& node);
    };
}