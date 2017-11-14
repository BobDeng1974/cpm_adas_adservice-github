#include "RvcGuideLine.h"

#define ANGLE_MAX 40

using namespace Harman::Adas::AFramework::AGraphic;

namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

RvcGuideLine::RvcGuideLine()
	:CRunableBase("RvcGuideLine", FALSE)
{
	graphic1 = new CAdasGraphic();
}

RvcGuideLine::~RvcGuideLine()
{
	if(graphic1 != NULL)
	{
		delete graphic1;
		graphic1 = NULL;
	}
}

VOID RvcGuideLine::init()
{
	surfaceInfo.surfaceName = "guideline";
    surfaceInfo.surfaceId = 51;
    surfaceInfo.moduleType = MODULE_GUIDELINE;
    surfaceInfo.bActiveEGL = TRUE;
    surfaceInfo.viewPos.width = 1280;//width;
    surfaceInfo.viewPos.height = 720;//height;
    surfaceInfo.viewPos.viewPos.x = 0;
    surfaceInfo.viewPos.viewPos.y = 0;

    surfaceArry.push_back(surfaceInfo);

    if(graphic1 != NULL)
    {
        graphic1->createSurface(surfaceArry);
    }

    if(graphic1 != NULL)
    {
        graphic1->showGuideLine(surfaceInfo.surfaceId, 0.0);
    }
}

VOID RvcGuideLine::update()
{
	Int32 angle = 0;
	while(1)
	{
		while(ANGLE_MAX - angle)
		{
			graphic1->showGuideLine(surfaceInfo.surfaceId, angle);
			angle++;
		}	
		while(ANGLE_MAX + angle)
		{
			graphic1->showGuideLine(surfaceInfo.surfaceId, angle);
			angle--;
		}

		usleep(50000);
	}
}

}
}
}
}