#include "MatrixMultiplicationTab.h"
#include "RenderUI.h"
#include "Vec2.h"
#include "Mat2.h"
#include <assert.h>

Vec2 vec =			{ 1, 1 };
Mat2 mat =			{ 1, 1, 1, 1 };
Vec2 resultVector = { 1, 1 };


void MatrixMultiplicationCallback(const LinearTransformationData& data)
{
	vec = Vec2{ data.v0, data.v1 };
	mat = Mat2{ data.m00,  data.m01,  data.m10,  data.m11 };
	resultVector = mat * vec;
}

bool MatrixMultiplicationTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setLinearTransformationData( &resultVector.xx, MatrixMultiplicationCallback);
	return true;
}

bool MatrixMultiplicationTab::Shutdown()
{
	return true;
}
