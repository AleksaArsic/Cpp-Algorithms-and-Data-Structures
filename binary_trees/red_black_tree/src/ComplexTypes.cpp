#include "ComplexTypes.hpp"

namespace ComplexTypes
{
	NodeColorClass::NodeColorClass(NodeColor desiredColor)
	{
		setColor(desiredColor);
	}

	void NodeColorClass::setColor(NodeColor desiredColor)
	{
		color = desiredColor;
	}

	NodeColorClass::NodeColor NodeColorClass::getColor() const
	{
		return color;
	}

	std::ostream& operator<<(std::ostream& os, const NodeColorClass& c)
	{
		switch (c.color)
		{
			case NodeColorClass::NodeColor::BLACK:
				os << "BLACK";
				break;
			case NodeColorClass::NodeColor::RED:
				os << "RED";
				break;
			default:
				os << "INVALID_COLOR";
				break;
		}

		return os;
	}
}