#ifndef _DEFINE_HPP_
#define _DEFINE_HPP_

namespace Main
{
	constexpr int field_size_x = 35;
	constexpr int field_size_y = 35;

	constexpr int cell_size = 30;

	constexpr int window_width = field_size_x * cell_size;
	constexpr int window_height = field_size_y * cell_size;

	constexpr int render_delay = 80;
}

#endif // _DEFINE_HPP_
