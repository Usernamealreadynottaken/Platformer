#pragma once

#include "formatted_debug_print.h"

#if ASSERTIONS_ENABLED

#define debugBreak() __asm { int 3 }

#define reportAssertionFailure(expr, file, line) \
	DebugPrintF("Expression: %s\nFile: %s\nLine: %d\n", expr, file, line); \

#define ASSERT(expr) \
	if (expr) { } \
	else { \
		reportAssertionFailure(#expr, __FILE__, __LINE__); \
		debugBreak(); \
	}

#else

#define ASSERT(expr)

#endif