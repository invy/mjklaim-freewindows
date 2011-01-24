"""
	AOS CPP : XSD to C++ Code Generation
	
	Python : 3.x
	
	This script assume that http://www.codesynthesis.com/products/xsd/ is available in the path.

"""

import os
import os.path
import sys
import shutil
import subprocess

# Path of the XSD file to use to generate the code
AOSL_XSD_PATH = "../../../language/aosl.xsd" 

# Path of the directory where the generated C++ header files have to be installed.
AOSCPP_AOSL_INCLUDE_PATH = os.path.abspath( "../include/aoscpp/aosl" )

# Path of the directory where the genreated C++ source files have to be installed.
AOSCPP_AOSL_SOURCE_PATH = "../source/aosl"

# Code Synthesis application name to use.
CODE_SYNTHESIS_GENERATOR = "xsd"

# Code Synthesis configuration file path.
CODE_SYNTHESIS_CONFIG_FILEPATH = "generate_cpp.cfg"

# Code Synthesis generator command and parameters
GENERATOR_COMMAND = [ CODE_SYNTHESIS_GENERATOR
					, "cxx-tree"
					, "--options-file"
					, CODE_SYNTHESIS_CONFIG_FILEPATH
					, AOSL_XSD_PATH
					]

subprocess.call( GENERATOR_COMMAND )


