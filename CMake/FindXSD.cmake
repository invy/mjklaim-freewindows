# Locate Xsd from code synthesis include paths and binary
# Xsd can be found at http://codesynthesis.com/products/xsd/
# Original version Written by Frederic Heem, frederic.heem _at_ telsey.it
# Additions by Joël Lamotte, mjklaim _at_ gmail.com

# This module defines
# XSD_INCLUDE_DIR, where to find elements.hxx, etc.
# XSD_EXECUTABLE, where is the xsd compiler
# XSD_FOUND, If false, don't try to use xsd

FIND_PATH(XSD_INCLUDE_DIR cxx/parser/elements.hxx
  $ENV{XSDDIR}/include
  $ENV{CODESYNTH}/include/xsd
  /usr/local/include/xsd
  /usr/include/xsd
)

#
FIND_PROGRAM(XSD_EXECUTABLE 
  NAMES 
    xsd
  PATHS
	"[HKEY_CURRENT_USER\\xsd\\bin"
    $ENV{XSDDIR}/bin 
    /usr/local/bin
    /usr/bin
)

# if the include and the program are found then we have it
IF(XSD_INCLUDE_DIR)

  message( STATUS "Found XSD include dir : " ${XSD_INCLUDE_DIR} )
  
  IF(XSD_EXECUTABLE)
    SET( XSD_FOUND "YES" )
	message( STATUS "Found XSD binaries : " ${XSD_EXECUTABLE} )
  ENDIF(XSD_EXECUTABLE)
  
ENDIF(XSD_INCLUDE_DIR)


find_package( xercesc )
if( NOT XERCESC_FOUND )
	message( SEND_ERROR "XSD requires Xerces library, NOT FOUND!" )
endif()

set( XSD_DEPENDENCIES_LIBRARIES ${XERCESC_LIBRARIES} )

MARK_AS_ADVANCED(
  XSD_INCLUDE_DIR
  XSD_DEPENDENCIES_LIBRARIES
  XSD_EXECUTABLE
) 