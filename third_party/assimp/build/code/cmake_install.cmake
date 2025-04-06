# Install script for directory: E:/software/assimp/assimp-5.2.4/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibassimp5.2.0-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/software/assimp/assimp-5.2.4/build/lib/Debug/assimp-vc143-mtd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/software/assimp/assimp-5.2.4/build/lib/Release/assimp-vc143-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/software/assimp/assimp-5.2.4/build/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/software/assimp/assimp-5.2.4/build/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibassimp5.2.0x" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/software/assimp/assimp-5.2.4/build/bin/Debug/assimp-vc143-mtd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/software/assimp/assimp-5.2.4/build/bin/Release/assimp-vc143-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/software/assimp/assimp-5.2.4/build/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/software/assimp/assimp-5.2.4/build/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/anim.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/aabb.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ai_assert.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/camera.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/color4.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/color4.inl"
    "E:/software/assimp/assimp-5.2.4/build/code/../include/assimp/config.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ColladaMetaData.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/commonMetaData.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/defs.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/cfileio.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/light.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/material.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/material.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/matrix3x3.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/matrix3x3.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/matrix4x4.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/matrix4x4.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/mesh.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ObjMaterial.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/pbrmaterial.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/GltfMaterial.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/postprocess.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/quaternion.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/quaternion.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/scene.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/metadata.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/texture.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/types.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/vector2.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/vector2.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/vector3.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/vector3.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/version.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/cimport.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/importerdesc.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Importer.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/DefaultLogger.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ProgressHandler.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/IOStream.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/IOSystem.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Logger.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/LogStream.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/NullLogger.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/cexport.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Exporter.hpp"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/DefaultIOStream.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/DefaultIOSystem.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ZipArchiveIOSystem.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SceneCombiner.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/fast_atof.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/qnan.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/BaseImporter.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Hash.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/MemoryIOWrapper.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ParsingUtils.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/StreamReader.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/StreamWriter.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/StringComparison.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/StringUtils.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SGSpatialSort.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/GenericProperty.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SpatialSort.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SkeletonMeshBuilder.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SmallVector.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SmoothingGroups.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/SmoothingGroups.inl"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/StandardShapes.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/RemoveComments.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Subdivision.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Vertex.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/LineSplitter.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/TinyFormatter.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Profiler.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/LogAux.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Bitmap.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/XMLTools.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/IOStreamBuffer.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/CreateAnimMesh.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/XmlParser.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/BlobIOSystem.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/MathFunctions.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Exceptional.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/ByteSwapper.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Base64.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Compiler/pushpack1.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Compiler/poppack1.h"
    "E:/software/assimp/assimp-5.2.4/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "E:/software/assimp/assimp-5.2.4/build/code/Debug/assimp-vc143-mtd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "E:/software/assimp/assimp-5.2.4/build/code/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

