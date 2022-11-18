#pragma once

#include <inttypes.h>
#include "Vector.hpp"

#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )
#define PAD( size ) uint8_t MACRO_CONCAT( _pad, __COUNTER__ )[ size ];

struct Player 
{
	PAD(0x40)
	struct Vec3 Postition;
	PAD(0x238)
	float paralyzerAmmo;
	PAD(0x170)
	int MagAmmo[17];
	PAD(0x4)
	int ClipAmmo[14];
	PAD(0x50D4)
	char Username;
	PAD(0x90)
	int Money;
};