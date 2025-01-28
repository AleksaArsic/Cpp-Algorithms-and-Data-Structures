#pragma once
#include <memory>

namespace ComplexTypes
{
    struct TreeNode final
    {
        int data;
        std::shared_ptr<TreeNode> left;
        std::shared_ptr<TreeNode> right;
    };

    struct Node final
    {
        std::shared_ptr<TreeNode> data;
        std::shared_ptr<Node> next;
    };

    struct StackNode final
    {
        bool isAlreadyPushed;
        std::shared_ptr<TreeNode> data;
        std::shared_ptr<StackNode> next;
    };
}