#include "DotProductTab.h"
#include "RenderUI.h"
#include "Vec2.h"
#include <assert.h>

Vec2 vec1  = { 1, 1 };
Vec2 vec2 = { 1, 1 };
Vec2 proj  = { 1, 1 };
Vec2 rej   = { 1, 1 };

void DotProductTabCallback(const DotProductData& data)
{
	vec1  = { data.v1i, data.v1j };
	vec2 = { data.v2i, data.v2j };
	if (!data.projectOntoLeftVector) {
		proj = vec1.Proj(vec2);
		rej = vec1.Rej(vec2);
	}
	else 
	{
		proj = vec2.Proj(vec1);
		rej = vec2.Rej(vec1);
	}
}

bool DotProductTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setDotProductData(&vec1.xy[0], &vec2.xy[0], &proj.xy[0], &rej.xy[0], DotProductTabCallback);
	return true;
}

bool DotProductTab::Shutdown()
{
	return true;
}
