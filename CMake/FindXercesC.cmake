
# - Find Xerces-C
# The following setings are defined
# XERCESC_ROOT_DIR, the root of the include and lib directory
# XERCESC_INCLUDE_DIR, the full path of the include dir (ADVANCED)
# XERCESC_LIBRARIES, the name of the xerces-c library (ADVANCED)

# Original version Written by Frederic Heem, frederic.heem _at_ telsey.it
# Additions by Joël Lamotte, mjklaim _at_ gmail.com

#####
# Find Xerces-C

# Look for a root installation
FIND_PATH(XERCESC_ROOT_DIR include/xercesc/parsers/SAXParser.hpp
	/usr
	$ENV{CODESYNTH}
	$ENV{XSDDIR}
  DOC "The root of an installed xerces-c installation"
)

# try to find the header
FIND_PATH(XERCESC_INCLUDE_DIR xercesc/parsers/SAXParser.hpp 
  ${XERCESC_ROOT_DIR}/include
  /usr/include 
  /usr/local/include
)

if( MSVC )
# make sure we use the right compiler version

	if( MSVC80 )
		set( XERCESC_COMPILER_PREFIX vc-8.0 )
	elseif( MSVC90 )
		set( XERCESC_COMPILER_PREFIX vc-9.0 )
	elseif( MSVC10 )
		set( XERCESC_COMPILER_PREFIX vc-10.0 )
	else( MSVC10 )
		message( FATAL_ERROR "Unknown MSVC version!" )
	endif( MSVC80 ) 
		
endif( MSVC )

# Find the library
FIND_LIBRARY(XERCESC_LIBRARY
   NAMES xerces-c xerces-c_3
   PATHS 
     ${XERCESC_ROOT_DIR}/lib
	 ${XERCESC_ROOT_DIR}/lib/${XERCESC_COMPILER_PREFIX}
     ${XERCESC_ROOT_DIR}/lib64/${XERCESC_COMPILER_PREFIX}
     /usr/lib 
     /usr/local/lib
   DOC "The name of the xerces-c library"
)
IF (XERCESC_ROOT_DIR)
  IF (XERCESC_INCLUDE_DIR AND XERCESC_LIBRARY)
    SET (XERCESC_FOUND TRUE)
    SET (XERCESC_LIBRARIES "${XERCESC_LIBRARY}")
    # FIXME: There should be a better way of handling this?
    # FIXME: How can we test to see if the lib dir isn't 
    # FIXME: one of the default dirs?
    LINK_DIRECTORIES(${XERCESC_ROOT_DIR}/lib)
  ENDIF (XERCESC_INCLUDE_DIR AND XERCESC_LIBRARY)
ENDIF (XERCESC_ROOT_DIR)

IF (XERCESC_FOUND)
  IF (NOT XERCESC_FIND_QUIETLY)
    MESSAGE (STATUS "Found Xerces-C: ${XERCESC_LIBRARY}")
  ENDIF (NOT XERCESC_FIND_QUIETLY)
ELSE (XERCESC_FOUND)
  IF (XERCESC_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find Xerces-C")
  ENDIF (XERCESC_FIND_REQUIRED)
ENDIF (XERCESC_FOUND)

MARK_AS_ADVANCED(
  XERCESC_INCLUDE_DIR
  XERCESC_LIBRARY
)