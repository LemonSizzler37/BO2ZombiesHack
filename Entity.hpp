#pragma once

#include <inttypes.h>
#include "Vector.hpp"
#include "VMatrix.hpp"

struct Entity
{
	char pad_0000[8]; //0x0000
	int32_t Unknown; //0x0008
	char pad_000C[12]; //0x000C
	Vec3 Position; //0x0018
	char pad_0024[28]; //0x0024
	float ViewAngle; //0x0040
	char pad_0044[216]; //0x0044
	matrix3x4_t ViewMatrix; //0x011C
	char pad_014C[92]; //0x014C
	int32_t Health; //0x01A8
	int32_t NextHealth; //0x01AC
	char pad_01B0[368]; //0x01B0
}; //Size: 0x031C