#include "osal.hpp"
#include "peripherals.hpp"
#include "sched.hpp"
#include "tetris.hpp"
#include "env.hpp"
#include "keypad.hpp"

using namespace OSAL;
using namespace OS;
using namespace Tetris;

#if !SITL
using namespace HAL;

TASK_FUNC(blink_task) {
	ioline_t led_line{GPIOC, 13U};
	led_line.cfg(linemode_t::out_pp);
	while (1) {
		led_line.toggle();
		osal->delay(500);
	}
}
#endif

TASK_FUNC(video_task) {
	disp->init();
	disp->clear();
	while (1) {
		disp->flush();
		osal->delay(10);
	}
}

static piece_t piece;
TASK_FUNC(main_task) {
	const size_t size = 16;
	size_t x = size;
	osal->delay(2000);

	piece = t_piece;
	while (1) {
#if SITL == ON
		extern disp_pc_t disp_pc;
		if (disp_pc.deinit_flag)
			disp_pc.deinit();
#endif
		piece.center.y++;
		piece.draw();
		osal->delay(1000);
	}
}

TASK_FUNC(keypad_task) {
	keypad->init();
	while (1) {
		const auto mask = keypad->read();		
		if (mask.bits.enter)
			;
		if (mask.bits.right) 
			piece.center.x++;
		if (mask.bits.left)
			piece.center.x--;
		if (mask.bits.down)
			piece.center.y++;

		osal->delay(20);
	}
}

int main(void) {
	osal->init();

	sched->create_task({
		.func = video_task,
		.name = "video",
		.prio = 1,
		.stack_size = 512,
	});

	sched->create_task({
		.func = keypad_task,
		.name = "keypad",
		.prio = 1,
		.stack_size = 512,
	});

#if !SITL
	sched->create_task({
		.func = blink_task,
		.name = "blink",
		.prio = 3,
		.stack_size = 64,
	});
#endif
	sched->init();

	while (1) {}
}
