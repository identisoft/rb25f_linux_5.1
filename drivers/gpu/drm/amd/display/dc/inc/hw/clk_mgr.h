/*
 * Copyright 2012-16 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DAL_CLK_MGR_H__
#define __DAL_CLK_MGR_H__

#include "dm_services_types.h"
#include "dc.h"

struct clk_mgr {
	struct dc_context *ctx;
	struct clk_mgr_funcs *funcs;

	struct dc_clocks clks;
};

struct clk_mgr_funcs {
	void (*update_clocks)(struct clk_mgr *clk_mgr,
			struct dc_state *context,
			bool safe_to_lower);

	int (*get_dp_ref_clk_frequency)(struct clk_mgr *clk_mgr);

	void (*init_clocks)(struct clk_mgr *clk_mgr);

	/* Returns actual clk that's set */
	int (*set_dispclk)(struct clk_mgr *clk_mgr, int requested_dispclk_khz);
	int (*set_dprefclk)(struct clk_mgr *clk_mgr);
};



#endif /* __DAL_CLK_MGR_H__ */
