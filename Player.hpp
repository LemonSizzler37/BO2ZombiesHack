#pragma once

#include <inttypes.h>
#include "Vector.hpp"

struct Player 
{
	char pad_0000[0x40]; 	// 0x0000
	struct Vec3 Postition; 	// 0x0040
	char pad_004C[0x238]; 	// 0x004C
	float paralyzerAmmo; 	// 0x0284
	char pad_0288[0x170]; 	// 0x0288
	int MagAmmo[17]; 	// 0x03F8
	char pad_043C[0x4]; 	// 0x043C
	int ClipAmmo[14]; 	// 0x0440
	char pad_0478[0x50D4]; 	// 0x0478
	char Username; 		// 0x554C
	char pad_554D[0x90]; 	// 0x554D
	int Money; 		// 0x55DD
};
