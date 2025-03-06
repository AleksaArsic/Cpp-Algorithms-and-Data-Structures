#pragma once
#include <array>

namespace ComplexTypes
{
	template<typename T>
	concept IntegralNumber = std::integral<T>;

	template <typename T, std::size_t Row, std::size_t Col>
	using Array2d = std::array<std::array<T, Col>, Row>;
}
