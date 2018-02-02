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
	pRenderUI->setLerpData(&lerp_1.xx, &lerp_2.xx, &lerp_aMinB.xx, &lerp_aVec.xx, &lerp_bVec.xx, &lerp_result.xx, LerpTabCallback);
	return true;
}

bool LerpTab::Shutdown()
{
	return true;
}
