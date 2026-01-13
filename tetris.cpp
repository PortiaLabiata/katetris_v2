#include "tetris.hpp"
#include "peripherals.hpp"

using namespace OSAL;

namespace Tetris {

void piece_t::draw() {
	OS::lock_guard_t guard(disp->dirty_queue);
	for (size_t i = 0; i < _piece_size; i++) {
		const auto& point = data[i];
		auto *block = disp->dirty_queue.emplace(
					(center.x+point.x)*_block_size,
					(center.y+point.y)*_block_size, 
					_block_size, _block_size);
		if (block) {
			block->fill(dirty_t::encode_color(r, g, b));
		}
	}
}

}
