#ifndef RVC_GUIDELINE_H_
#define  RVC_GUIDELINE_H_
#include "AFoundation.h"
#include "AGraphic.h"

using namespace std;
using namespace Harman::Adas::AFramework::AFoundation;
using namespace Harman::Adas::AFramework::AGraphic;


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {

class RvcGuideLine : public CRunableBase
{
public:
	RvcGuideLine();
	virtual ~RvcGuideLine();

protected:
	virtual VOID init();
	virtual VOID update();  

private:

	CAdasGraphic* graphic1;

	tsurfaceInfo surfaceInfo;

    tsurfaceList surfaceArry;
		
};

}
}
}
}




#endif
