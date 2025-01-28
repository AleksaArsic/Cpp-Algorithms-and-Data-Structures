#pragma once
#include "ComplexTypes.hpp"

namespace AVLBinaryTree
{
    class AVLTree final
    {
        public:
            AVLTree();

            void Insert(const int data);
            void RInsert(const int data);
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
            std::shared_ptr<ComplexTypes::AVLTreeNode> root;

            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> RInsert(std::shared_ptr<ComplexTypes::AVLTreeNode>& node, const int data);
            [[nodiscard]] std::shared_ptr<ComplexTypes::AVLTreeNode> DeleteElement(std::shared_ptr<ComplexTypes::AVLTreeNode>& node, const int data);

            void PreorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;
            void InorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;
            void PostorderTraversal(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;

            [[nodiscard]] unsigned int Height(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;
            [[nodiscard]] int BalanceFactor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;

            void LLRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node);
            void RRRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node);
            void LRRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node);
            void RLRotation(std::shared_ptr<ComplexTypes::AVLTreeNode>& node);

            std::shared_ptr<ComplexTypes::AVLTreeNode> InorderPrecessor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;
            std::shared_ptr<ComplexTypes::AVLTreeNode> InorderSuccessor(const std::shared_ptr<ComplexTypes::AVLTreeNode>& node) const;

    };
}