@echo off
echo == AOSL-C++ Code Generation ==
echo This script assume that http://www.codesynthesis.com/products/xsd/ was installed and available in the path.

set AOSL_XSD_PATH = "../../../language/aosl.xsd"
set AOSCPP_AOSL_INCLUDE_PATH = "../include/aoscpp/aosl"
set AOSCPP_AOSL_SOURCE_PATH = "../source/aosl"
set AOSL_FILE_PATTERN = "aosl_*.*"
set HEADER_FILE_PATTERN = "*.hpp"
set INLINE_FILE_PATTERN = "*.inl"
set BACKUP_PATH = "."

echo Backup non-generated files...
move %AOSCPP_AOSL_INCLUDE_PATH%/%AOSL_FILE_PATTERN% %BACKUP_PATH%

echo Remove the previously generated code...
del %AOSCPP_AOSL_SOURCE_PATH%*
del %AOSCPP_AOSL_INCLUDE_PATH%*

echo Generate the code...
xsd cxx-tree --options-file generate_cpp.cfg %AOSL_XSD_PATH%

echo Move headers in the include directory...
move %AOSCPP_AOSL_SOURCE_PATH%%HEADER_FILE_PATTERN% %AOSCPP_AOSL_INCLUDE_PATH%
move %AOSCPP_AOSL_SOURCE_PATH%%INLINE_FILE_PATTERN% %AOSCPP_AOSL_INCLUDE_PATH%

echo Restore the non-generated files...
move %BACKUP_PATH%%AOSL_FILE_PATTERN% %AOSCPP_AOSL_INCLUDE_PATH%

echo == AOSL-C++ Code Generation - Done. ==

