#pragma once

#include <inttypes.h>
#include "Vector.hpp"
#include "VMatrix.hpp"

struct Entity
{
	char pad_0000[0x8]; 	// 0x0000
	int32_t Unknown; 	// 0x0008
	char pad_000C[0xC]; 	// 0x000C
	Vec3 Position; 		// 0x0018
	char pad_0024[0x1C]; 	// 0x0024
	float ViewAngle; 	// 0x0040
	char pad_0044[0xD8]; 	// 0x0044
	matrix3x4_t ViewMatrix; // 0x011C
	char pad_014C[0x5C]; 	// 0x014C
	int32_t Health; 	// 0x01A8
	int32_t NextHealth; 	// 0x01AC
	char pad_01B0[0x170]; 	// 0x01B0
}; //Size: 0x031C
