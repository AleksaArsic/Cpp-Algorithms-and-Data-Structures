#pragma once
#include <iostream>
#include <memory>
#include "Queue.hpp"

namespace BinaryTree
{
    class BinaryTree
    {
        public:
            BinaryTree();

            void createTree();
            void PreorderTraversal() const;
            void InorderTraversal() const;
            void PostorderTraversal() const;
            void LevelorderTraversal() const;
            void IterativePreorderTraversal() const;
            void IterativeInorderTraversal() const;
            void IterativePostorderTraversal() const;
            [[nodiscard]] unsigned int Height() const;
            [[nodiscard]] unsigned int CountNodes() const;
            [[nodiscard]] unsigned int CountLeafNodes() const;
            [[nodiscard]] unsigned int CountDeg1Nodes() const;
            [[nodiscard]] unsigned int CountDeg2Nodes() const;
            [[nodiscard]] unsigned int CountDeg1or2Nodes() const;

        private:
            std::shared_ptr<ComplexTypes::TreeNode> root;

            void PreorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void InorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            void PostorderTraversal(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

            [[nodiscard]] unsigned int Height(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int CountNodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int CountLeafNodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int CountDeg1Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int CountDeg2Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;
            [[nodiscard]] unsigned int CountDeg1or2Nodes(const std::shared_ptr<ComplexTypes::TreeNode>& node) const;

    };

}