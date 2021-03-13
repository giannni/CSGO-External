#pragma once

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <thread>
#include <cmath>
#include <intrin.h>
#include <inttypes.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include "triggerbot.h"
#include "radar.h"
#include "aimbot.h"
#include "memory.h"
#include "entity.h"
#include "vector.h"

typedef struct 
{
	float Matrix[3][4];
} Matrix3x4_t;