#include <Windows.h>
#include <math.h>
#include <float.h>
#include "Player.hpp"
#include "Entity.hpp"
#include "Vector.hpp"
#include "QAngle.hpp"

struct t6zmVariables 
{
	// Player:

	// pitch, yaw, roll, -90 <= x <= 90, -180 <= y <= 180
	struct QAngle* viewAngles;
	// add to viewAngles
	struct QAngle* unobfuscateVector;

	Player* startOfPlayer;

	// Zombie:

	int* zombieAmount;
	Entity* startOfZombie;
	// sizeof(zombie) = 0x31C;
} var;

HMODULE hMod = 0;

DWORD CALLBACK deepwebhax()
{
	var.viewAngles =		(struct QAngle*)0x2D3EFB3C;
	var.unobfuscateVector = (struct QAngle*)0x1276720;
	var.startOfPlayer =		(Player*)0x02346A88;

	var.zombieAmount =		(int*)0x103DAC8;
	var.startOfZombie =		(Entity*)0x021C9B28;

	struct Player* local = var.startOfPlayer;

	struct Vec3 olVec = { 0 };
	BOOL canAimbot = 1;

	while (!(GetAsyncKeyState(VK_END) & 0x8000))
	{
		if (canAimbot == 1 && *var.zombieAmount != 0)
		{
			struct Vec3 deltaVec = { 0 };
			float deltaVecLength = FLT_MAX;

			struct Entity* Zombie = var.startOfZombie;

			for (int zombieCounter = 0; zombieCounter < *var.zombieAmount; Zombie++)
			{
				if (Zombie->Health == 0 || Zombie->Unknown != 0)
					continue;

				struct Vec3 zmPosVec = Zombie->ViewMatrix.GetOrigin() + 20.0f;
				struct Vec3 currVec = zmPosVec - local->Postition;
				float currLength = currVec.Length();
				if (currLength < deltaVecLength)
				{
					deltaVecLength = currLength;
					deltaVec = currVec;
				}

				zombieCounter++;
			}

			if (deltaVecLength != FLT_MAX)
			{
				var.viewAngles->pitch = -asinf(deltaVec.z / (float)deltaVecLength) * (float)(180.0f / 3.14159) - var.unobfuscateVector->pitch;
				var.viewAngles->yaw = atan2f(deltaVec.y, deltaVec.x) * (float)(180.0f / 3.14159) - var.unobfuscateVector->yaw;
			}
		}

		if ((GetAsyncKeyState(VK_DOWN) & 1))
			canAimbot ^= 1;

		if ((GetAsyncKeyState(VK_UP) & 1))
		{
			QAngle angles = *var.viewAngles + *var.unobfuscateVector;
			local->Postition.x += cosf((angles.yaw) / (float)(180.0f / 3.14159)) * 100.0f;
			local->Postition.y += sinf((angles.yaw) / (float)(180.0f / 3.14159)) * 100.0f;
			local->Postition.z += -sinf((angles.pitch) / (float)(180.0f / 3.14159)) * 150.0f;
		}

		if ((GetAsyncKeyState(VK_HOME) & 1))
			olVec = local->Postition;
		else if ((GetAsyncKeyState(VK_INSERT) & 1))
			local->Postition = olVec;

		local->Money = 69420;

		for (int i = 0; i < 14; i++)
			local->ClipAmmo[i] = 69;

		for (int i = 0; i < 17; i++)
			local->MagAmmo[i] = 420;

		local->paralyzerAmmo = 60.0f;

		local->Username = 0;
	}

	FreeLibraryAndExitThread(hMod, 0);
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		hMod = hModule;
		HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)deepwebhax, NULL, 0, NULL);
		if (hThread != INVALID_HANDLE_VALUE && hThread != 0)
			CloseHandle(hThread);
		break;
	}
	return TRUE;
}