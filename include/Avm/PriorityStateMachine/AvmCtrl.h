#ifndef __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_CTRL_H_
#define __HARMAN_ADAS_APROJECT_GWMV2MH_AVM_CTRL_H_

#include "TraceMacros.h"
#include "AvmTyepDefine.h"
#include "AvmProxy.h"


using namespace std;
//using namespace Harman::Adas::AFramework::AFoundation;


namespace Harman {
namespace Adas {
namespace AProject {
namespace GWMV2MH {
//namespace AVM {


class CAvmCtrl
{
public:
	
	CAvmCtrl();		
	virtual ~CAvmCtrl();
	
	static CAvmCtrl* getInstance();	
	
	BOOLEAN initialize();
	VOID	updateState();
	

private:	
	static CAvmCtrl* m_pAvmCtrlInstance;
	CAvmProxy* m_pAvmProxy;
};


//} // namespace AVM
} // namespace GWMV2MH
} // namespace AProject
} // namespace Adas
} // namespace Harman





#endif //__HARMAN_ADAS_APROJECT_GWMV2MH_AVM_CTRL_H_
