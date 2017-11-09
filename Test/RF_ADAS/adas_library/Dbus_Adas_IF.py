
import sys
import os
import dbus
import struct

from traceback import print_exc
g_FreeDesktopDBus = ''
g_AVMService = ''


#####################################
# connect to headunit and get service
#####################################
def connectToService(ip,port):

	os.environ['DBUS_SESSION_BUS_ADDRESS'] = 'tcp:host=' + ip + ',' + 'port=' + port + ',family=ipv4'
#	os.system('export')

	bus = dbus.SessionBus()

	try:
		#get org.freedesktop.dbus objet
		remote_object = bus.get_object('org.freedesktop.DBus',
										'/')
		global g_FreeDesktopDBus
		g_FreeDesktopDBus = dbus.Interface(remote_object,
									dbus_interface='org.freedesktop.DBus')

		#get AVMServiceInst0 objet
		remote_object = bus.get_object('com.harman.adas.AVMService_adas.AVMServiceInst0',
										'/adas/AVMServiceInst0')
		global g_AVMService
		g_AVMService = dbus.Interface(remote_object,
									dbus_interface='com.harman.adas.AVMService')

	except dbus.DBusException:
		print_exc()
		sys.exit(1)


#####################################
# org.freedesktop.dbus service 
# ListNames()
#####################################
def getListNames():

	global g_FreeDesktopDBus

	result = g_FreeDesktopDBus.ListNames()

	return result

#####################################
# org.freedesktop.dbus service 
# ListActivatableNames()
#####################################
def getListActivatableNames():

	global g_FreeDesktopDBus

	result = g_FreeDesktopDBus.ListActivatableNames()

	return result


#####################################
# org.freedesktop.dbus service 
# startServiceByName()
#####################################
def startServiceByName(a,b=1):

	global g_FreeDesktopDBus

	result = g_FreeDesktopDBus.StartServiceByName(a,b)

	return result

#####################################
# AVMServiceInst0 service 
# getAVMCamStatusAttribute()
#####################################
def getAVMCamStatusAttribute():

	global g_AVMService
	#arg name="value" type="(iiii)" direction="out"
	result = g_AVMService.getAVMCamStatusAttribute()
	
	return result

#####################################
# AVMServiceInst0 service 
# getInterfaceVersion()
#####################################
def getInterfaceVersion():

	global g_AVMService
	#arg name="value" type="uu" direction="out"
	result = g_AVMService.getInterfaceVersion()
	
	return result

#####################################
# AVMServiceInst0 service 
# getCTAStatusAttribute()
#####################################
def getCTAStatusAttribute():

	global g_AVMService
	#arg name="value" type="(ii)" direction="out"
	result = g_AVMService.getCTAStatusAttribute()
	
	return result

#####################################
# AVMServiceInst0 service 
# getAutoStatusAttribute()
#####################################
def getAutoStatusAttribute():

	global g_AVMService
	#arg name="value" type="i" direction="out"
	result = g_AVMService.getAutoStatusAttribute()
	
	return result

#####################################
# AVMServiceInst0 service 
# SwitchAVMView()
#####################################
def SwitchAVMView(a):

	global g_AVMService
	#arg name="_m_eAVMViewMode" type="i" direction="in"
	g_AVMService.SwitchAVMView(a)
	return 1

#####################################
# AVMServiceInst0 service 
# SwitchGuideline()
#####################################
def SwitchGuideline(a):

	global g_AVMService
	#arg name="_m_eAVMGuideLinewMode" type="i" direction="in" 
	g_AVMService.SwitchGuideline(a)
	return 1

#####################################
# AVMServiceInst0 service 
# SwitchCTA()
#####################################
def SwitchCTA(a):

	global g_AVMService
	#arg name="_m_eCATMode" type="i" direction="in"
	#arg name="_iErrCTA" type="y" direction="out"
	result = g_AVMService.SwitchCTA(a)
	
	return result

#####################################
# AVMServiceInst0 service 
# SwitchAutoCalibrationAuto()
#####################################
def SwitchAutoCalibrationAuto(a):

	global g_AVMService
	#arg name="_m_eAutoCaliMode" type="i" direction="in"
	#arg name="_iErrAutoCali" type="y" direction="out"
	result = g_AVMService.SwitchAutoCalibrationAuto(a)
	
	return result

#####################################
# AVMServiceInst0 service 
# SwitchAutoCalibrationManually()
#####################################
def SwitchAutoCalibrationManually(a):

	global g_AVMService
	#arg name="_m_eAutoCaliMode" type="i" direction="in"
	#arg name="_iErrAutoCali" type="y" direction="out"
	result = g_AVMService.SwitchAutoCalibrationManually(a)
	
	return result
#if __name__ == '__main__':
#    main()
