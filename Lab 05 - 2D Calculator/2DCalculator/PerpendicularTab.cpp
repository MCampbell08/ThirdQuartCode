#include "PerpendicularTab.h"
#include "RenderUI.h"
#include "Vec2.h"
#include <assert.h>

Vec2 orig{ 1, 1 };
Vec2 norm{ 1, 1 };
Vec2 cw{ 1, 1 };
Vec2 ccw{ 1, 1 };

void PerpendicularTabTabCallback(const PerpendicularData& data)
{
	orig = Vec2{data.x, data.y};
	norm = orig.Normalize();
	cw = orig.PerpCW();
	ccw = orig.PerpCCW();
}

bool PerpendicularTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setPerpendicularData(&orig.xx, &norm.xx, &cw.xx, &ccw.xx, PerpendicularTabTabCallback);
	return true;
}

bool PerpendicularTab::Shutdown()
{
	return true;
}
