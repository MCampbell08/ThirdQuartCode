#include "AffineTransformationTab.h"
#include "RenderUI.h"
#include "Vec3.h"
#include "Mat3.h"	
#include <assert.h>

Vec3 vec0 = { 1, 1, 1 };
Vec3 vec1 = { 1, 1, 1 };
Vec3 vec2 = { 1, 1, 1 };
Vec3 vec3 = { 1, 1, 1 };
Vec3 vec4 = { 1, 1, 1 };
Mat3 mat = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
Vec3 resultVectors[5];

void AffineTransformationTabCallback(const AffineTransformationData& data)
{
	mat = Mat3{ data.data[0], data.data[1], data.data[2],
				data.data[3], data.data[4], data.data[5], 
				data.data[6], data.data[7], data.data[8] };
	vec0 = Vec3{ data.data[9], data.data[10], data.data[11] };
	vec1 = Vec3{ data.data[12], data.data[13], data.data[14] };
	vec2 = Vec3{ data.data[15], data.data[16], data.data[17] };
	vec3 = Vec3{ data.data[18], data.data[19], data.data[20] };
	vec4 = Vec3{ data.data[21], data.data[22], data.data[23] };
	resultVectors[0] = mat * vec0;
	resultVectors[1] = mat * vec1;
	resultVectors[2] = mat * vec2;
	resultVectors[3] = mat * vec3;
	resultVectors[4] = mat * vec4;
}

bool AffineTransformationTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->setAffineTransformationData(&resultVectors[0].xx, AffineTransformationTabCallback);
	return true;
}

bool AffineTransformationTab::Shutdown()
{
	return true;
}
