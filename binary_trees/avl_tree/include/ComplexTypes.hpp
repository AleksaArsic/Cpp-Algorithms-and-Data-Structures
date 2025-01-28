#pragma once
#include <memory>

namespace ComplexTypes
{
	struct AVLTreeNode final
	{
		int data;
		unsigned int height;
		std::shared_ptr<ComplexTypes::AVLTreeNode> left;
		std::shared_ptr<ComplexTypes::AVLTreeNode> right;
	};

	struct TreeNode final
	{
		bool alreadyPushed;
		std::shared_ptr<ComplexTypes::AVLTreeNode> treeNode;
		std::shared_ptr<ComplexTypes::TreeNode> next;
	};
}