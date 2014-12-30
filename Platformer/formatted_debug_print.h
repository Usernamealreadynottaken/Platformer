#pragma once

#include <stdio.h>
#include <Windows.h>
#include "types.h"

int VDebugPrintF(const char * format, va_list arg_list)
{
	const uint32 MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	int chars_written = vsnprintf_s(s_buffer, MAX_CHARS, format, arg_list);
	OutputDebugString(s_buffer);

	return chars_written;
}

int DebugPrintF(const char * format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);

	int chars_written = VDebugPrintF(format, arg_list);

	va_end(arg_list);
	return chars_written;
}