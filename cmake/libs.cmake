IF(CMAKE_SYSTEM_NAME MATCHES "Windows")	
	IF(CMAKE_CL_64)
		SET(libplatform "x64")
		SET(binplatform "x64")
		MESSAGE(STATUS "use x64 lib ")
	ELSE()
		SET(libplatform "win32")
		SET(binplatform "")
		MESSAGE(STATUS "use win32 lib ")
	ENDIF(CMAKE_CL_64)
		
	ADD_LIBRARY(Ws2_32 SHARED IMPORTED)
	SET_PROPERTY(TARGET Ws2_32 PROPERTY IMPORTED_IMPLIB ws2_32.lib)	
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")