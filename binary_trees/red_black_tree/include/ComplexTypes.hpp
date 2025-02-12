#pragma once
#include <memory>
#include <iostream>
#include <string_view>
#include <string>

namespace ComplexTypes
{
	class NodeColorClass final
	{
	public:

		enum class NodeColor
		{
			BLACK = 0,
			RED,
			INVALID_COLOR
		};

		NodeColorClass() = delete;
		NodeColorClass(NodeColor desiredColor);

		void setColor(NodeColor desiredColor);
		NodeColor getColor() const;
		friend std::ostream& operator<<(std::ostream& os, const NodeColorClass& color);

	private:

		NodeColor color;
	};

	struct TreeNode final
	{
		NodeColorClass color;
		int data;
		std::shared_ptr<ComplexTypes::TreeNode> left;
		std::shared_ptr<ComplexTypes::TreeNode> right;
	};

	struct Node final
	{
		bool isAlreadyStored;
		std::shared_ptr<ComplexTypes::TreeNode> treeNode;
		std::shared_ptr<ComplexTypes::Node> next;
	};
}