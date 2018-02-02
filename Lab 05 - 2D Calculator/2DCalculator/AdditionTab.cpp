#include "AdditionTab.h"
#include "RenderUI.h"
#include "Vec2.h"
#include <assert.h>
#include "GameLogger.h"
#include "ConfigReader.h"
#include "KeyValuePairs.h"

Vec2 left   { 1, 1 };
Vec2 right  { 1, 1 };
Vec2 result { 1, 1 };
const char* tabName = "2DCalculator.AdditionTab";

void AdditionTabCallback(const BasicVectorEquationInfo& data)
{
	left  = Vec2{ data.scalar1 * data.x1, data.scalar2 * data.y1 };
	right = Vec2{ data.scalar1 * data.x2, data.scalar2 *  data.y2 };
	result = data.add ? (left + right) : (left - right);
}

bool AdditionTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setBasicVectorEquationData(AdditionTabCallback, &left.xx, &right.xx, &result.xx);
	return true;
}

bool AdditionTab::Shutdown()
{
	return true;
}
