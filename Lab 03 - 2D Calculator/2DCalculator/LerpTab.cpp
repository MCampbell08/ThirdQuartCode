#include "LerpTab.h"
#include "RenderUI.h"
#include "Vec2.h"
#include <assert.h>

Vec2 lerp_1 = { 1, 1 };
Vec2 lerp_2 = { 1, 1 };
Vec2 lerp_aMinB = { 1, 1 };
Vec2 lerp_aVec = { 1, 1 };
Vec2 lerp_bVec = { 1, 1 };
Vec2 lerp_result = { 1, 1 };

void LerpTabCallback(const LerpData& data)
{
	lerp_1 = Vec2{ data.a_i, data.a_j };
	lerp_2 = Vec2{ data.b_i, data.b_j };
	lerp_aMinB = lerp_2 - lerp_1;
	lerp_aVec = lerp_1 * (1 - data.beta);
	lerp_bVec = lerp_2 * data.beta;
	lerp_result = lerp_aVec + lerp_bVec;
}

bool LerpTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setLerpData(&lerp_1.xy[0], &lerp_2.xy[0], &lerp_aMinB.xy[0], &lerp_aVec.xy[0], &lerp_bVec.xy[0], &lerp_result.xy[0], LerpTabCallback);
	return true;
}

bool LerpTab::Shutdown()
{
	return true;
}
