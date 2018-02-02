#include "MatrixTransformationTab.h"
#include "RenderUI.h"
#include "Mat3.h"
#include "Vec2.h"
#include <assert.h>

Vec2 m_houseshape[8];
Mat3 m_matrices[20];
Mat3 mat3;

void MatrixTransformationCallback(const MatrixTransformData2D& data)
{
	mat3 = Mat3();
	m_houseshape[0] = { .35f, .35f };
	m_houseshape[1] = { .35f, -.35f };
	m_houseshape[2] = { .35f, -.35f };
	m_houseshape[3] = { -.35f, -.35f };
	m_houseshape[4] = { -.35f, -.35f };
	m_houseshape[5] = { -.35f, .35f };
	m_houseshape[6] = { -.35f, .35f };
	m_houseshape[7] = { .35f, .35f };

	m_matrices[data.selectedMatrix] = Mat3(cosf(data.rotate) * data.scaleX, -sinf(data.rotate), data.translateX, sinf(data.rotate), cosf(data.rotate)*data.scaleY,data.translateY, 0, 0, 1);

	for (int i = 0; i <= 20; ++i)
	{
		mat3 = mat3 * m_matrices[i];
	}
}

bool MatrixTransformationTab::Initialize(RenderUI * pRenderUI)
{
	assert(pRenderUI);
	pRenderUI->set2DMatrixVerticesTransformData(&m_houseshape[0].xx, 8, &m_matrices[0].topleft , &mat3.topleft, MatrixTransformationCallback);
	return true;
}

bool MatrixTransformationTab::Shutdown()
{
	return true;
}
