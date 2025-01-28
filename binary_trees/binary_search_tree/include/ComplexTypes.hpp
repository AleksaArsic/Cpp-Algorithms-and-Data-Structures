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
		bool isAlreadyPushed;
		std::shared_ptr<TreeNode> dataNode;
		std::shared_ptr<Node> next;
	};
}