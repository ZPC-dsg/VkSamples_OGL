00001 #ifndef __glext_h_
00002 #define __glext_h_
00003
00004 #ifdef __cplusplus
00005 extern "C" {
	00006 #endif
		00007
		00008 /*
		00009 ** Copyright 1998, 1999, 2000, 2001, NVIDIA Corporation.
		00010 ** All rights Reserved.
		00011 **
		00012 ** THE INFORMATION CONTAINED HEREIN IS PROPRIETARY AND CONFIDENTIAL TO
		00013 ** NVIDIA, CORPORATION.  USE, REPRODUCTION OR DISCLOSURE TO ANY THIRD PARTY
		00014 ** IS SUBJECT TO WRITTEN PRE-APPROVAL BY NVIDIA, CORPORATION.
		00015 */
		00016
		00017 /*
		00018 ** License Applicability. Except to the extent portions of this file are
		00019 ** made subject to an alternative license as permitted in the SGI Free
		00020 ** Software License B, Version 1.1 (the "License"), the contents of this
		00021 ** file are subject only to the provisions of the License. You may not use
		00022 ** this file except in compliance with the License. You may obtain a copy
		00023 ** of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
		00024 ** Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
		00025 **
		00026 ** http://oss.sgi.com/projects/FreeB
		00027 **
		00028 ** Note that, as provided in the License, the Software is distributed on an
		00029 ** "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
		00030 ** DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
		00031 ** CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
		00032 ** PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
		00033 **
		00034 ** Original Code. The Original Code is: OpenGL Sample Implementation,
		00035 ** Version 1.2.1, released January 26, 2000, developed by Silicon Graphics,
		00036 ** Inc. The Original Code is Copyright (c) 1991-2000 Silicon Graphics, Inc.
		00037 ** Copyright in any portions created by third parties is as indicated
		00038 ** elsewhere herein. All Rights Reserved.
		00039 **
		00040 ** Additional Notice Provisions: This software was created using the
		00041 ** OpenGL(R) version 1.2.1 Sample Implementation published by SGI, but has
		00042 ** not been independently verified as being compliant with the OpenGL(R)
		00043 ** version 1.2.1 Specification.
		00044 */
		00045
		00046 #if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__)
		00047 #define WIN32_LEAN_AND_MEAN 1
		00048 #include <windows.h>
		00049 #endif
		00050
		00051 #ifndef APIENTRY
		00052 #define APIENTRY
		00053 #endif
		00054
		00055 /*************************************************************/
		00056
		00057 /* Header file version number, required by OpenGL ABI for Linux */
		00058 #define GL_GLEXT_VERSION 6
		00059
		00060 #ifndef GL_VERSION_1_2
		00061 #define GL_CONSTANT_COLOR                 0x8001
		00062 #define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
		00063 #define GL_CONSTANT_ALPHA                 0x8003
		00064 #define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
		00065 #define GL_BLEND_COLOR                    0x8005
		00066 #define GL_FUNC_ADD                       0x8006
		00067 #define GL_MIN                            0x8007
		00068 #define GL_MAX                            0x8008
		00069 #define GL_BLEND_EQUATION                 0x8009
		00070 #define GL_FUNC_SUBTRACT                  0x800A
		00071 #define GL_FUNC_REVERSE_SUBTRACT          0x800B
		00072 #define GL_CONVOLUTION_1D                 0x8010
		00073 #define GL_CONVOLUTION_2D                 0x8011
		00074 #define GL_SEPARABLE_2D                   0x8012
		00075 #define GL_CONVOLUTION_BORDER_MODE        0x8013
		00076 #define GL_CONVOLUTION_FILTER_SCALE       0x8014
		00077 #define GL_CONVOLUTION_FILTER_BIAS        0x8015
		00078 #define GL_REDUCE                         0x8016
		00079 #define GL_CONVOLUTION_FORMAT             0x8017
		00080 #define GL_CONVOLUTION_WIDTH              0x8018
		00081 #define GL_CONVOLUTION_HEIGHT             0x8019
		00082 #define GL_MAX_CONVOLUTION_WIDTH          0x801A
		00083 #define GL_MAX_CONVOLUTION_HEIGHT         0x801B
		00084 #define GL_POST_CONVOLUTION_RED_SCALE     0x801C
		00085 #define GL_POST_CONVOLUTION_GREEN_SCALE   0x801D
		00086 #define GL_POST_CONVOLUTION_BLUE_SCALE    0x801E
		00087 #define GL_POST_CONVOLUTION_ALPHA_SCALE   0x801F
		00088 #define GL_POST_CONVOLUTION_RED_BIAS      0x8020
		00089 #define GL_POST_CONVOLUTION_GREEN_BIAS    0x8021
		00090 #define GL_POST_CONVOLUTION_BLUE_BIAS     0x8022
		00091 #define GL_POST_CONVOLUTION_ALPHA_BIAS    0x8023
		00092 #define GL_HISTOGRAM                      0x8024
		00093 #define GL_PROXY_HISTOGRAM                0x8025
		00094 #define GL_HISTOGRAM_WIDTH                0x8026
		00095 #define GL_HISTOGRAM_FORMAT               0x8027
		00096 #define GL_HISTOGRAM_RED_SIZE             0x8028
		00097 #define GL_HISTOGRAM_GREEN_SIZE           0x8029
		00098 #define GL_HISTOGRAM_BLUE_SIZE            0x802A
		00099 #define GL_HISTOGRAM_ALPHA_SIZE           0x802B
		00100 #define GL_HISTOGRAM_LUMINANCE_SIZE       0x802C
		00101 #define GL_HISTOGRAM_SINK                 0x802D
		00102 #define GL_MINMAX                         0x802E
		00103 #define GL_MINMAX_FORMAT                  0x802F
		00104 #define GL_MINMAX_SINK                    0x8030
		00105 #define GL_TABLE_TOO_LARGE                0x8031
		00106 #define GL_UNSIGNED_BYTE_3_3_2            0x8032
		00107 #define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
		00108 #define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
		00109 #define GL_UNSIGNED_INT_8_8_8_8           0x8035
		00110 #define GL_UNSIGNED_INT_10_10_10_2        0x8036
		00111 #define GL_RESCALE_NORMAL                 0x803A
		00112 #define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
		00113 #define GL_UNSIGNED_SHORT_5_6_5           0x8363
		00114 #define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
		00115 #define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
		00116 #define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
		00117 #define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
		00118 #define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
		00119 #define GL_COLOR_MATRIX                   0x80B1
		00120 #define GL_COLOR_MATRIX_STACK_DEPTH       0x80B2
		00121 #define GL_MAX_COLOR_MATRIX_STACK_DEPTH   0x80B3
		00122 #define GL_POST_COLOR_MATRIX_RED_SCALE    0x80B4
		00123 #define GL_POST_COLOR_MATRIX_GREEN_SCALE  0x80B5
		00124 #define GL_POST_COLOR_MATRIX_BLUE_SCALE   0x80B6
		00125 #define GL_POST_COLOR_MATRIX_ALPHA_SCALE  0x80B7
		00126 #define GL_POST_COLOR_MATRIX_RED_BIAS     0x80B8
		00127 #define GL_POST_COLOR_MATRIX_GREEN_BIAS   0x80B9
		00128 #define GL_POST_COLOR_MATRIX_BLUE_BIAS    0x80BA
		00129 #define GL_COLOR_TABLE                    0x80D0
		00130 #define GL_POST_CONVOLUTION_COLOR_TABLE   0x80D1
		00131 #define GL_POST_COLOR_MATRIX_COLOR_TABLE  0x80D2
		00132 #define GL_PROXY_COLOR_TABLE              0x80D3
		00133 #define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
		00134 #define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
		00135 #define GL_COLOR_TABLE_SCALE              0x80D6
		00136 #define GL_COLOR_TABLE_BIAS               0x80D7
		00137 #define GL_COLOR_TABLE_FORMAT             0x80D8
		00138 #define GL_COLOR_TABLE_WIDTH              0x80D9
		00139 #define GL_COLOR_TABLE_RED_SIZE           0x80DA
		00140 #define GL_COLOR_TABLE_GREEN_SIZE         0x80DB
		00141 #define GL_COLOR_TABLE_BLUE_SIZE          0x80DC
		00142 #define GL_COLOR_TABLE_ALPHA_SIZE         0x80DD
		00143 #define GL_COLOR_TABLE_LUMINANCE_SIZE     0x80DE
		00144 #define GL_COLOR_TABLE_INTENSITY_SIZE     0x80DF
		00145 #define GL_CLAMP_TO_EDGE                  0x812F
		00146 #define GL_TEXTURE_MIN_LOD                0x813A
		00147 #define GL_TEXTURE_MAX_LOD                0x813B
		00148 #define GL_TEXTURE_BASE_LEVEL             0x813C
		00149 #define GL_TEXTURE_MAX_LEVEL              0x813D
		00150 #endif
		00151
		00152 #ifndef GL_ARB_multitexture
		00153 #define GL_TEXTURE0_ARB                   0x84C0
		00154 #define GL_TEXTURE1_ARB                   0x84C1
		00155 #define GL_TEXTURE2_ARB                   0x84C2
		00156 #define GL_TEXTURE3_ARB                   0x84C3
		00157 #define GL_TEXTURE4_ARB                   0x84C4
		00158 #define GL_TEXTURE5_ARB                   0x84C5
		00159 #define GL_TEXTURE6_ARB                   0x84C6
		00160 #define GL_TEXTURE7_ARB                   0x84C7
		00161 #define GL_TEXTURE8_ARB                   0x84C8
		00162 #define GL_TEXTURE9_ARB                   0x84C9
		00163 #define GL_TEXTURE10_ARB                  0x84CA
		00164 #define GL_TEXTURE11_ARB                  0x84CB
		00165 #define GL_TEXTURE12_ARB                  0x84CC
		00166 #define GL_TEXTURE13_ARB                  0x84CD
		00167 #define GL_TEXTURE14_ARB                  0x84CE
		00168 #define GL_TEXTURE15_ARB                  0x84CF
		00169 #define GL_TEXTURE16_ARB                  0x84D0
		00170 #define GL_TEXTURE17_ARB                  0x84D1
		00171 #define GL_TEXTURE18_ARB                  0x84D2
		00172 #define GL_TEXTURE19_ARB                  0x84D3
		00173 #define GL_TEXTURE20_ARB                  0x84D4
		00174 #define GL_TEXTURE21_ARB                  0x84D5
		00175 #define GL_TEXTURE22_ARB                  0x84D6
		00176 #define GL_TEXTURE23_ARB                  0x84D7
		00177 #define GL_TEXTURE24_ARB                  0x84D8
		00178 #define GL_TEXTURE25_ARB                  0x84D9
		00179 #define GL_TEXTURE26_ARB                  0x84DA
		00180 #define GL_TEXTURE27_ARB                  0x84DB
		00181 #define GL_TEXTURE28_ARB                  0x84DC
		00182 #define GL_TEXTURE29_ARB                  0x84DD
		00183 #define GL_TEXTURE30_ARB                  0x84DE
		00184 #define GL_TEXTURE31_ARB                  0x84DF
		00185 #define GL_ACTIVE_TEXTURE_ARB             0x84E0
		00186 #define GL_CLIENT_ACTIVE_TEXTURE_ARB      0x84E1
		00187 #define GL_MAX_TEXTURE_UNITS_ARB          0x84E2
		00188 #endif
		00189
		00190 #ifndef GL_ARB_transpose_matrix
		00191 #define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
		00192 #define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
		00193 #define GL_TRANSPOSE_TEXTURE_MATRIX_ARB   0x84E5
		00194 #define GL_TRANSPOSE_COLOR_MATRIX_ARB     0x84E6
		00195 #endif
		00196
		00197 #ifndef GL_ARB_multisample
		00198 #define GL_MULTISAMPLE_ARB                0x809D
		00199 #define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB   0x809E
		00200 #define GL_SAMPLE_ALPHA_TO_ONE_ARB        0x809F
		00201 #define GL_SAMPLE_COVERAGE_ARB            0x80A0
		00202 #define GL_SAMPLE_BUFFERS_ARB             0x80A8
		00203 #define GL_SAMPLES_ARB                    0x80A9
		00204 #define GL_SAMPLE_COVERAGE_VALUE_ARB      0x80AA
		00205 #define GL_SAMPLE_COVERAGE_INVERT_ARB     0x80AB
		00206 #define GL_MULTISAMPLE_BIT_ARB            0x20000000
		00207 #endif
		00208
		00209 #ifndef GL_ARB_texture_cube_map
		00210 #define GL_NORMAL_MAP_ARB                 0x8511
		00211 #define GL_REFLECTION_MAP_ARB             0x8512
		00212 #define GL_TEXTURE_CUBE_MAP_ARB           0x8513
		00213 #define GL_TEXTURE_BINDING_CUBE_MAP_ARB   0x8514
		00214 #define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
		00215 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
		00216 #define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
		00217 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
		00218 #define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
		00219 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
		00220 #define GL_PROXY_TEXTURE_CUBE_MAP_ARB     0x851B
		00221 #define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB  0x851C
		00222 #endif
		00223
		00224 #ifndef GL_ARB_texture_compression
		00225 #define GL_COMPRESSED_ALPHA_ARB           0x84E9
		00226 #define GL_COMPRESSED_LUMINANCE_ARB       0x84EA
		00227 #define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
		00228 #define GL_COMPRESSED_INTENSITY_ARB       0x84EC
		00229 #define GL_COMPRESSED_RGB_ARB             0x84ED
		00230 #define GL_COMPRESSED_RGBA_ARB            0x84EE
		00231 #define GL_TEXTURE_COMPRESSION_HINT_ARB   0x84EF
		00232 #define GL_TEXTURE_IMAGE_SIZE_ARB         0x86A0
		00233 #define GL_TEXTURE_COMPRESSED_ARB         0x86A1
		00234 #define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
		00235 #define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
		00236 #endif
		00237
		00238 #ifndef GL_EXT_abgr
		00239 #define GL_ABGR_EXT                       0x8000
		00240 #endif
		00241
		00242 #ifndef GL_EXT_blend_color
		00243 #define GL_CONSTANT_COLOR_EXT             0x8001
		00244 #define GL_ONE_MINUS_CONSTANT_COLOR_EXT   0x8002
		00245 #define GL_CONSTANT_ALPHA_EXT             0x8003
		00246 #define GL_ONE_MINUS_CONSTANT_ALPHA_EXT   0x8004
		00247 #define GL_BLEND_COLOR_EXT                0x8005
		00248 #endif
		00249
		00250 #ifndef GL_EXT_polygon_offset
		00251 #define GL_POLYGON_OFFSET_EXT             0x8037
		00252 #define GL_POLYGON_OFFSET_FACTOR_EXT      0x8038
		00253 #define GL_POLYGON_OFFSET_BIAS_EXT        0x8039
		00254 #endif
		00255
		00256 #ifndef GL_EXT_texture
		00257 #define GL_ALPHA4_EXT                     0x803B
		00258 #define GL_ALPHA8_EXT                     0x803C
		00259 #define GL_ALPHA12_EXT                    0x803D
		00260 #define GL_ALPHA16_EXT                    0x803E
		00261 #define GL_LUMINANCE4_EXT                 0x803F
		00262 #define GL_LUMINANCE8_EXT                 0x8040
		00263 #define GL_LUMINANCE12_EXT                0x8041
		00264 #define GL_LUMINANCE16_EXT                0x8042
		00265 #define GL_LUMINANCE4_ALPHA4_EXT          0x8043
		00266 #define GL_LUMINANCE6_ALPHA2_EXT          0x8044
		00267 #define GL_LUMINANCE8_ALPHA8_EXT          0x8045
		00268 #define GL_LUMINANCE12_ALPHA4_EXT         0x8046
		00269 #define GL_LUMINANCE12_ALPHA12_EXT        0x8047
		00270 #define GL_LUMINANCE16_ALPHA16_EXT        0x8048
		00271 #define GL_INTENSITY_EXT                  0x8049
		00272 #define GL_INTENSITY4_EXT                 0x804A
		00273 #define GL_INTENSITY8_EXT                 0x804B
		00274 #define GL_INTENSITY12_EXT                0x804C
		00275 #define GL_INTENSITY16_EXT                0x804D
		00276 #define GL_RGB2_EXT                       0x804E
		00277 #define GL_RGB4_EXT                       0x804F
		00278 #define GL_RGB5_EXT                       0x8050
		00279 #define GL_RGB8_EXT                       0x8051
		00280 #define GL_RGB10_EXT                      0x8052
		00281 #define GL_RGB12_EXT                      0x8053
		00282 #define GL_RGB16_EXT                      0x8054
		00283 #define GL_RGBA2_EXT                      0x8055
		00284 #define GL_RGBA4_EXT                      0x8056
		00285 #define GL_RGB5_A1_EXT                    0x8057
		00286 #define GL_RGBA8_EXT                      0x8058
		00287 #define GL_RGB10_A2_EXT                   0x8059
		00288 #define GL_RGBA12_EXT                     0x805A
		00289 #define GL_RGBA16_EXT                     0x805B
		00290 #define GL_TEXTURE_RED_SIZE_EXT           0x805C
		00291 #define GL_TEXTURE_GREEN_SIZE_EXT         0x805D
		00292 #define GL_TEXTURE_BLUE_SIZE_EXT          0x805E
		00293 #define GL_TEXTURE_ALPHA_SIZE_EXT         0x805F
		00294 #define GL_TEXTURE_LUMINANCE_SIZE_EXT     0x8060
		00295 #define GL_TEXTURE_INTENSITY_SIZE_EXT     0x8061
		00296 #define GL_REPLACE_EXT                    0x8062
		00297 #define GL_PROXY_TEXTURE_1D_EXT           0x8063
		00298 #define GL_PROXY_TEXTURE_2D_EXT           0x8064
		00299 #define GL_TEXTURE_TOO_LARGE_EXT          0x8065
		00300 #endif
		00301
		00302 #ifndef GL_EXT_texture3D
		00303 #define GL_PACK_SKIP_IMAGES               0x806B
		00304 #define GL_PACK_SKIP_IMAGES_EXT           0x806B
		00305 #define GL_PACK_IMAGE_HEIGHT              0x806C
		00306 #define GL_PACK_IMAGE_HEIGHT_EXT          0x806C
		00307 #define GL_UNPACK_SKIP_IMAGES             0x806D
		00308 #define GL_UNPACK_SKIP_IMAGES_EXT         0x806D
		00309 #define GL_UNPACK_IMAGE_HEIGHT            0x806E
		00310 #define GL_UNPACK_IMAGE_HEIGHT_EXT        0x806E
		00311 #define GL_TEXTURE_3D                     0x806F
		00312 #define GL_TEXTURE_3D_EXT                 0x806F
		00313 #define GL_PROXY_TEXTURE_3D               0x8070
		00314 #define GL_PROXY_TEXTURE_3D_EXT           0x8070
		00315 #define GL_TEXTURE_DEPTH                  0x8071
		00316 #define GL_TEXTURE_DEPTH_EXT              0x8071
		00317 #define GL_TEXTURE_WRAP_R                 0x8072
		00318 #define GL_TEXTURE_WRAP_R_EXT             0x8072
		00319 #define GL_MAX_3D_TEXTURE_SIZE            0x8073
		00320 #define GL_MAX_3D_TEXTURE_SIZE_EXT        0x8073
		00321 #endif
		00322
		00323 #ifndef GL_SGIS_texture_filter4
		00324 #define GL_FILTER4_SGIS                   0x8146
		00325 #define GL_TEXTURE_FILTER4_SIZE_SGIS      0x8147
		00326 #endif
		00327
		00328 #ifndef GL_EXT_subtexture
		00329 #endif
		00330
		00331 #ifndef GL_EXT_copy_texture
		00332 #endif
		00333
		00334 #ifndef GL_EXT_histogram
		00335 #define GL_HISTOGRAM_EXT                  0x8024
		00336 #define GL_PROXY_HISTOGRAM_EXT            0x8025
		00337 #define GL_HISTOGRAM_WIDTH_EXT            0x8026
		00338 #define GL_HISTOGRAM_FORMAT_EXT           0x8027
		00339 #define GL_HISTOGRAM_RED_SIZE_EXT         0x8028
		00340 #define GL_HISTOGRAM_GREEN_SIZE_EXT       0x8029
		00341 #define GL_HISTOGRAM_BLUE_SIZE_EXT        0x802A
		00342 #define GL_HISTOGRAM_ALPHA_SIZE_EXT       0x802B
		00343 #define GL_HISTOGRAM_LUMINANCE_SIZE_EXT   0x802C
		00344 #define GL_HISTOGRAM_SINK_EXT             0x802D
		00345 #define GL_MINMAX_EXT                     0x802E
		00346 #define GL_MINMAX_FORMAT_EXT              0x802F
		00347 #define GL_MINMAX_SINK_EXT                0x8030
		00348 #define GL_TABLE_TOO_LARGE_EXT            0x8031
		00349 #endif
		00350
		00351 #ifndef GL_EXT_convolution
		00352 #define GL_CONVOLUTION_1D_EXT             0x8010
		00353 #define GL_CONVOLUTION_2D_EXT             0x8011
		00354 #define GL_SEPARABLE_2D_EXT               0x8012
		00355 #define GL_CONVOLUTION_BORDER_MODE_EXT    0x8013
		00356 #define GL_CONVOLUTION_FILTER_SCALE_EXT   0x8014
		00357 #define GL_CONVOLUTION_FILTER_BIAS_EXT    0x8015
		00358 #define GL_REDUCE_EXT                     0x8016
		00359 #define GL_CONVOLUTION_FORMAT_EXT         0x8017
		00360 #define GL_CONVOLUTION_WIDTH_EXT          0x8018
		00361 #define GL_CONVOLUTION_HEIGHT_EXT         0x8019
		00362 #define GL_MAX_CONVOLUTION_WIDTH_EXT      0x801A
		00363 #define GL_MAX_CONVOLUTION_HEIGHT_EXT     0x801B
		00364 #define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
		00365 #define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
		00366 #define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
		00367 #define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
		00368 #define GL_POST_CONVOLUTION_RED_BIAS_EXT  0x8020
		00369 #define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
		00370 #define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
		00371 #define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023
		00372 #endif
		00373
		00374 #ifndef GL_SGI_color_matrix
		00375 #define GL_COLOR_MATRIX_SGI               0x80B1
		00376 #define GL_COLOR_MATRIX_STACK_DEPTH_SGI   0x80B2
		00377 #define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
		00378 #define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4
		00379 #define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
		00380 #define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
		00381 #define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
		00382 #define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
		00383 #define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
		00384 #define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
		00385 #define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB
		00386 #endif
		00387
		00388 #ifndef GL_SGI_color_table
		00389 #define GL_COLOR_TABLE_SGI                0x80D0
		00390 #define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
		00391 #define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
		00392 #define GL_PROXY_COLOR_TABLE_SGI          0x80D3
		00393 #define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
		00394 #define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
		00395 #define GL_COLOR_TABLE_SCALE_SGI          0x80D6
		00396 #define GL_COLOR_TABLE_BIAS_SGI           0x80D7
		00397 #define GL_COLOR_TABLE_FORMAT_SGI         0x80D8
		00398 #define GL_COLOR_TABLE_WIDTH_SGI          0x80D9
		00399 #define GL_COLOR_TABLE_RED_SIZE_SGI       0x80DA
		00400 #define GL_COLOR_TABLE_GREEN_SIZE_SGI     0x80DB
		00401 #define GL_COLOR_TABLE_BLUE_SIZE_SGI      0x80DC
		00402 #define GL_COLOR_TABLE_ALPHA_SIZE_SGI     0x80DD
		00403 #define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
		00404 #define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF
		00405 #endif
		00406
		00407 #ifndef GL_SGIS_pixel_texture
		00408 #define GL_PIXEL_TEXTURE_SGIS             0x8353
		00409 #define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
		00410 #define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
		00411 #define GL_PIXEL_GROUP_COLOR_SGIS         0x8356
		00412 #endif
		00413
		00414 #ifndef GL_SGIX_pixel_texture
		00415 #define GL_PIXEL_TEX_GEN_SGIX             0x8139
		00416 #define GL_PIXEL_TEX_GEN_MODE_SGIX        0x832B
		00417 #endif
		00418
		00419 #ifndef GL_SGIS_texture4D
		00420 #define GL_PACK_SKIP_VOLUMES_SGIS         0x8130
		00421 #define GL_PACK_IMAGE_DEPTH_SGIS          0x8131
		00422 #define GL_UNPACK_SKIP_VOLUMES_SGIS       0x8132
		00423 #define GL_UNPACK_IMAGE_DEPTH_SGIS        0x8133
		00424 #define GL_TEXTURE_4D_SGIS                0x8134
		00425 #define GL_PROXY_TEXTURE_4D_SGIS          0x8135
		00426 #define GL_TEXTURE_4DSIZE_SGIS            0x8136
		00427 #define GL_TEXTURE_WRAP_Q_SGIS            0x8137
		00428 #define GL_MAX_4D_TEXTURE_SIZE_SGIS       0x8138
		00429 #define GL_TEXTURE_4D_BINDING_SGIS        0x814F
		00430 #endif
		00431
		00432 #ifndef GL_SGI_texture_color_table
		00433 #define GL_TEXTURE_COLOR_TABLE_SGI        0x80BC
		00434 #define GL_PROXY_TEXTURE_COLOR_TABLE_SGI  0x80BD
		00435 #endif
		00436
		00437 #ifndef GL_EXT_cmyka
		00438 #define GL_CMYK_EXT                       0x800C
		00439 #define GL_CMYKA_EXT                      0x800D
		00440 #define GL_PACK_CMYK_HINT_EXT             0x800E
		00441 #define GL_UNPACK_CMYK_HINT_EXT           0x800F
		00442 #endif
		00443
		00444 #ifndef GL_EXT_texture_object
		00445 #define GL_TEXTURE_PRIORITY_EXT           0x8066
		00446 #define GL_TEXTURE_RESIDENT_EXT           0x8067
		00447 #define GL_TEXTURE_1D_BINDING_EXT         0x8068
		00448 #define GL_TEXTURE_2D_BINDING_EXT         0x8069
		00449 #define GL_TEXTURE_3D_BINDING_EXT         0x806A
		00450 #endif
		00451
		00452 #ifndef GL_SGIS_detail_texture
		00453 #define GL_DETAIL_TEXTURE_2D_SGIS         0x8095
		00454 #define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
		00455 #define GL_LINEAR_DETAIL_SGIS             0x8097
		00456 #define GL_LINEAR_DETAIL_ALPHA_SGIS       0x8098
		00457 #define GL_LINEAR_DETAIL_COLOR_SGIS       0x8099
		00458 #define GL_DETAIL_TEXTURE_LEVEL_SGIS      0x809A
		00459 #define GL_DETAIL_TEXTURE_MODE_SGIS       0x809B
		00460 #define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C
		00461 #endif
		00462
		00463 #ifndef GL_SGIS_sharpen_texture
		00464 #define GL_LINEAR_SHARPEN_SGIS            0x80AD
		00465 #define GL_LINEAR_SHARPEN_ALPHA_SGIS      0x80AE
		00466 #define GL_LINEAR_SHARPEN_COLOR_SGIS      0x80AF
		00467 #define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0
		00468 #endif
		00469
		00470 #ifndef GL_EXT_packed_pixels
		00471 #define GL_UNSIGNED_BYTE_3_3_2_EXT        0x8032
		00472 #define GL_UNSIGNED_SHORT_4_4_4_4_EXT     0x8033
		00473 #define GL_UNSIGNED_SHORT_5_5_5_1_EXT     0x8034
		00474 #define GL_UNSIGNED_INT_8_8_8_8_EXT       0x8035
		00475 #define GL_UNSIGNED_INT_10_10_10_2_EXT    0x8036
		00476 #endif
		00477
		00478 #ifndef GL_SGIS_texture_lod
		00479 #define GL_TEXTURE_MIN_LOD_SGIS           0x813A
		00480 #define GL_TEXTURE_MAX_LOD_SGIS           0x813B
		00481 #define GL_TEXTURE_BASE_LEVEL_SGIS        0x813C
		00482 #define GL_TEXTURE_MAX_LEVEL_SGIS         0x813D
		00483 #endif
		00484
		00485 #ifndef GL_SGIS_multisample
		00486 #define GL_MULTISAMPLE_SGIS               0x809D
		00487 #define GL_SAMPLE_ALPHA_TO_MASK_SGIS      0x809E
		00488 #define GL_SAMPLE_ALPHA_TO_ONE_SGIS       0x809F
		00489 #define GL_SAMPLE_MASK_SGIS               0x80A0
		00490 #define GL_1PASS_SGIS                     0x80A1
		00491 #define GL_2PASS_0_SGIS                   0x80A2
		00492 #define GL_2PASS_1_SGIS                   0x80A3
		00493 #define GL_4PASS_0_SGIS                   0x80A4
		00494 #define GL_4PASS_1_SGIS                   0x80A5
		00495 #define GL_4PASS_2_SGIS                   0x80A6
		00496 #define GL_4PASS_3_SGIS                   0x80A7
		00497 #define GL_SAMPLE_BUFFERS_SGIS            0x80A8
		00498 #define GL_SAMPLES_SGIS                   0x80A9
		00499 #define GL_SAMPLE_MASK_VALUE_SGIS         0x80AA
		00500 #define GL_SAMPLE_MASK_INVERT_SGIS        0x80AB
		00501 #define GL_SAMPLE_PATTERN_SGIS            0x80AC
		00502 #endif
		00503
		00504 #ifndef GL_EXT_rescale_normal
		00505 #define GL_RESCALE_NORMAL_EXT             0x803A
		00506 #endif
		00507
		00508 #ifndef GL_EXT_vertex_array
		00509 #define GL_VERTEX_ARRAY_EXT               0x8074
		00510 #define GL_NORMAL_ARRAY_EXT               0x8075
		00511 #define GL_COLOR_ARRAY_EXT                0x8076
		00512 #define GL_INDEX_ARRAY_EXT                0x8077
		00513 #define GL_TEXTURE_COORD_ARRAY_EXT        0x8078
		00514 #define GL_EDGE_FLAG_ARRAY_EXT            0x8079
		00515 #define GL_VERTEX_ARRAY_SIZE_EXT          0x807A
		00516 #define GL_VERTEX_ARRAY_TYPE_EXT          0x807B
		00517 #define GL_VERTEX_ARRAY_STRIDE_EXT        0x807C
		00518 #define GL_VERTEX_ARRAY_COUNT_EXT         0x807D
		00519 #define GL_NORMAL_ARRAY_TYPE_EXT          0x807E
		00520 #define GL_NORMAL_ARRAY_STRIDE_EXT        0x807F
		00521 #define GL_NORMAL_ARRAY_COUNT_EXT         0x8080
		00522 #define GL_COLOR_ARRAY_SIZE_EXT           0x8081
		00523 #define GL_COLOR_ARRAY_TYPE_EXT           0x8082
		00524 #define GL_COLOR_ARRAY_STRIDE_EXT         0x8083
		00525 #define GL_COLOR_ARRAY_COUNT_EXT          0x8084
		00526 #define GL_INDEX_ARRAY_TYPE_EXT           0x8085
		00527 #define GL_INDEX_ARRAY_STRIDE_EXT         0x8086
		00528 #define GL_INDEX_ARRAY_COUNT_EXT          0x8087
		00529 #define GL_TEXTURE_COORD_ARRAY_SIZE_EXT   0x8088
		00530 #define GL_TEXTURE_COORD_ARRAY_TYPE_EXT   0x8089
		00531 #define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
		00532 #define GL_TEXTURE_COORD_ARRAY_COUNT_EXT  0x808B
		00533 #define GL_EDGE_FLAG_ARRAY_STRIDE_EXT     0x808C
		00534 #define GL_EDGE_FLAG_ARRAY_COUNT_EXT      0x808D
		00535 #define GL_VERTEX_ARRAY_POINTER_EXT       0x808E
		00536 #define GL_NORMAL_ARRAY_POINTER_EXT       0x808F
		00537 #define GL_COLOR_ARRAY_POINTER_EXT        0x8090
		00538 #define GL_INDEX_ARRAY_POINTER_EXT        0x8091
		00539 #define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
		00540 #define GL_EDGE_FLAG_ARRAY_POINTER_EXT    0x8093
		00541 #endif
		00542
		00543 #ifndef GL_EXT_misc_attribute
		00544 #endif
		00545
		00546 #ifndef GL_SGIS_generate_mipmap
		00547 #define GL_GENERATE_MIPMAP_SGIS           0x8191
		00548 #define GL_GENERATE_MIPMAP_HINT_SGIS      0x8192
		00549 #endif
		00550
		00551 #ifndef GL_SGIX_clipmap
		00552 #define GL_LINEAR_CLIPMAP_LINEAR_SGIX     0x8170
		00553 #define GL_TEXTURE_CLIPMAP_CENTER_SGIX    0x8171
		00554 #define GL_TEXTURE_CLIPMAP_FRAME_SGIX     0x8172
		00555 #define GL_TEXTURE_CLIPMAP_OFFSET_SGIX    0x8173
		00556 #define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
		00557 #define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
		00558 #define GL_TEXTURE_CLIPMAP_DEPTH_SGIX     0x8176
		00559 #define GL_MAX_CLIPMAP_DEPTH_SGIX         0x8177
		00560 #define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
		00561 #define GL_NEAREST_CLIPMAP_NEAREST_SGIX   0x844D
		00562 #define GL_NEAREST_CLIPMAP_LINEAR_SGIX    0x844E
		00563 #define GL_LINEAR_CLIPMAP_NEAREST_SGIX    0x844F
		00564 #endif
		00565
		00566 #ifndef GL_SGIX_shadow
		00567 #define GL_TEXTURE_COMPARE_SGIX           0x819A
		00568 #define GL_TEXTURE_COMPARE_OPERATOR_SGIX  0x819B
		00569 #define GL_TEXTURE_LEQUAL_R_SGIX          0x819C
		00570 #define GL_TEXTURE_GEQUAL_R_SGIX          0x819D
		00571 #endif
		00572
		00573 #ifndef GL_SGIS_texture_edge_clamp
		00574 #define GL_CLAMP_TO_EDGE_SGIS             0x812F
		00575 #endif
		00576
		00577 #ifndef GL_SGIS_texture_border_clamp
		00578 #define GL_CLAMP_TO_BORDER_SGIS           0x812D
		00579 #endif
		00580
		00581 #ifndef GL_EXT_blend_minmax
		00582 #define GL_FUNC_ADD_EXT                   0x8006
		00583 #define GL_MIN_EXT                        0x8007
		00584 #define GL_MAX_EXT                        0x8008
		00585 #define GL_BLEND_EQUATION_EXT             0x8009
		00586 #endif
		00587
		00588 #ifndef GL_EXT_blend_subtract
		00589 #define GL_FUNC_SUBTRACT_EXT              0x800A
		00590 #define GL_FUNC_REVERSE_SUBTRACT_EXT      0x800B
		00591 #endif
		00592
		00593 #ifndef GL_EXT_blend_logic_op
		00594 #endif
		00595
		00596 #ifndef GL_SGIX_interlace
		00597 #define GL_INTERLACE_SGIX                 0x8094
		00598 #endif
		00599
		00600 #ifndef GL_SGIX_pixel_tiles
		00601 #define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
		00602 #define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
		00603 #define GL_PIXEL_TILE_WIDTH_SGIX          0x8140
		00604 #define GL_PIXEL_TILE_HEIGHT_SGIX         0x8141
		00605 #define GL_PIXEL_TILE_GRID_WIDTH_SGIX     0x8142
		00606 #define GL_PIXEL_TILE_GRID_HEIGHT_SGIX    0x8143
		00607 #define GL_PIXEL_TILE_GRID_DEPTH_SGIX     0x8144
		00608 #define GL_PIXEL_TILE_CACHE_SIZE_SGIX     0x8145
		00609 #endif
		00610
		00611 #ifndef GL_SGIS_texture_select
		00612 #define GL_DUAL_ALPHA4_SGIS               0x8110
		00613 #define GL_DUAL_ALPHA8_SGIS               0x8111
		00614 #define GL_DUAL_ALPHA12_SGIS              0x8112
		00615 #define GL_DUAL_ALPHA16_SGIS              0x8113
		00616 #define GL_DUAL_LUMINANCE4_SGIS           0x8114
		00617 #define GL_DUAL_LUMINANCE8_SGIS           0x8115
		00618 #define GL_DUAL_LUMINANCE12_SGIS          0x8116
		00619 #define GL_DUAL_LUMINANCE16_SGIS          0x8117
		00620 #define GL_DUAL_INTENSITY4_SGIS           0x8118
		00621 #define GL_DUAL_INTENSITY8_SGIS           0x8119
		00622 #define GL_DUAL_INTENSITY12_SGIS          0x811A
		00623 #define GL_DUAL_INTENSITY16_SGIS          0x811B
		00624 #define GL_DUAL_LUMINANCE_ALPHA4_SGIS     0x811C
		00625 #define GL_DUAL_LUMINANCE_ALPHA8_SGIS     0x811D
		00626 #define GL_QUAD_ALPHA4_SGIS               0x811E
		00627 #define GL_QUAD_ALPHA8_SGIS               0x811F
		00628 #define GL_QUAD_LUMINANCE4_SGIS           0x8120
		00629 #define GL_QUAD_LUMINANCE8_SGIS           0x8121
		00630 #define GL_QUAD_INTENSITY4_SGIS           0x8122
		00631 #define GL_QUAD_INTENSITY8_SGIS           0x8123
		00632 #define GL_DUAL_TEXTURE_SELECT_SGIS       0x8124
		00633 #define GL_QUAD_TEXTURE_SELECT_SGIS       0x8125
		00634 #endif
		00635
		00636 #ifndef GL_SGIX_sprite
		00637 #define GL_SPRITE_SGIX                    0x8148
		00638 #define GL_SPRITE_MODE_SGIX               0x8149
		00639 #define GL_SPRITE_AXIS_SGIX               0x814A
		00640 #define GL_SPRITE_TRANSLATION_SGIX        0x814B
		00641 #define GL_SPRITE_AXIAL_SGIX              0x814C
		00642 #define GL_SPRITE_OBJECT_ALIGNED_SGIX     0x814D
		00643 #define GL_SPRITE_EYE_ALIGNED_SGIX        0x814E
		00644 #endif
		00645
		00646 #ifndef GL_SGIX_texture_multi_buffer
		00647 #define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E
		00648 #endif
		00649
		00650 #ifndef GL_SGIS_point_parameters
		00651 #define GL_POINT_SIZE_MIN_EXT             0x8126
		00652 #define GL_POINT_SIZE_MIN_SGIS            0x8126
		00653 #define GL_POINT_SIZE_MAX_EXT             0x8127
		00654 #define GL_POINT_SIZE_MAX_SGIS            0x8127
		00655 #define GL_POINT_FADE_THRESHOLD_SIZE_EXT  0x8128
		00656 #define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
		00657 #define GL_DISTANCE_ATTENUATION_EXT       0x8129
		00658 #define GL_DISTANCE_ATTENUATION_SGIS      0x8129
		00659 #endif
		00660
		00661 #ifndef GL_SGIX_instruments
		00662 #define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
		00663 #define GL_INSTRUMENT_MEASUREMENTS_SGIX   0x8181
		00664 #endif
		00665
		00666 #ifndef GL_SGIX_texture_scale_bias
		00667 #define GL_POST_TEXTURE_FILTER_BIAS_SGIX  0x8179
		00668 #define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
		00669 #define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
		00670 #define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
		00671 #endif
		00672
		00673 #ifndef GL_SGIX_framezoom
		00674 #define GL_FRAMEZOOM_SGIX                 0x818B
		00675 #define GL_FRAMEZOOM_FACTOR_SGIX          0x818C
		00676 #define GL_MAX_FRAMEZOOM_FACTOR_SGIX      0x818D
		00677 #endif
		00678
		00679 #ifndef GL_SGIX_tag_sample_buffer
		00680 #endif
		00681
		00682 #ifndef GL_SGIX_reference_plane
		00683 #define GL_REFERENCE_PLANE_SGIX           0x817D
		00684 #define GL_REFERENCE_PLANE_EQUATION_SGIX  0x817E
		00685 #endif
		00686
		00687 #ifndef GL_SGIX_flush_raster
		00688 #endif
		00689
		00690 #ifndef GL_SGIX_depth_texture
		00691 #define GL_DEPTH_COMPONENT16_SGIX         0x81A5
		00692 #define GL_DEPTH_COMPONENT24_SGIX         0x81A6
		00693 #define GL_DEPTH_COMPONENT32_SGIX         0x81A7
		00694 #endif
		00695
		00696 #ifndef GL_SGIS_fog_function
		00697 #define GL_FOG_FUNC_SGIS                  0x812A
		00698 #define GL_FOG_FUNC_POINTS_SGIS           0x812B
		00699 #define GL_MAX_FOG_FUNC_POINTS_SGIS       0x812C
		00700 #endif
		00701
		00702 #ifndef GL_SGIX_fog_offset
		00703 #define GL_FOG_OFFSET_SGIX                0x8198
		00704 #define GL_FOG_OFFSET_VALUE_SGIX          0x8199
		00705 #endif
		00706
		00707 #ifndef GL_HP_image_transform
		00708 #define GL_IMAGE_SCALE_X_HP               0x8155
		00709 #define GL_IMAGE_SCALE_Y_HP               0x8156
		00710 #define GL_IMAGE_TRANSLATE_X_HP           0x8157
		00711 #define GL_IMAGE_TRANSLATE_Y_HP           0x8158
		00712 #define GL_IMAGE_ROTATE_ANGLE_HP          0x8159
		00713 #define GL_IMAGE_ROTATE_ORIGIN_X_HP       0x815A
		00714 #define GL_IMAGE_ROTATE_ORIGIN_Y_HP       0x815B
		00715 #define GL_IMAGE_MAG_FILTER_HP            0x815C
		00716 #define GL_IMAGE_MIN_FILTER_HP            0x815D
		00717 #define GL_IMAGE_CUBIC_WEIGHT_HP          0x815E
		00718 #define GL_CUBIC_HP                       0x815F
		00719 #define GL_AVERAGE_HP                     0x8160
		00720 #define GL_IMAGE_TRANSFORM_2D_HP          0x8161
		00721 #define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
		00722 #define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163
		00723 #endif
		00724
		00725 #ifndef GL_HP_convolution_border_modes
		00726 #define GL_IGNORE_BORDER_HP               0x8150
		00727 #define GL_CONSTANT_BORDER_HP             0x8151
		00728 #define GL_REPLICATE_BORDER_HP            0x8153
		00729 #define GL_CONVOLUTION_BORDER_COLOR_HP    0x8154
		00730 #endif
		00731
		00732 #ifndef GL_INGR_palette_buffer
		00733 #endif
		00734
		00735 #ifndef GL_SGIX_texture_add_env
		00736 #define GL_TEXTURE_ENV_BIAS_SGIX          0x80BE
		00737 #endif
		00738
		00739 #ifndef GL_EXT_color_subtable
		00740 #endif
		00741
		00742 #ifndef GL_PGI_vertex_hints
		00743 #define GL_VERTEX_DATA_HINT_PGI           0x1A22A
		00744 #define GL_VERTEX_CONSISTENT_HINT_PGI     0x1A22B
		00745 #define GL_MATERIAL_SIDE_HINT_PGI         0x1A22C
		00746 #define GL_MAX_VERTEX_HINT_PGI            0x1A22D
		00747 #define GL_COLOR3_BIT_PGI                 0x00010000
		00748 #define GL_COLOR4_BIT_PGI                 0x00020000
		00749 #define GL_EDGEFLAG_BIT_PGI               0x00040000
		00750 #define GL_INDEX_BIT_PGI                  0x00080000
		00751 #define GL_MAT_AMBIENT_BIT_PGI            0x00100000
		00752 #define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
		00753 #define GL_MAT_DIFFUSE_BIT_PGI            0x00400000
		00754 #define GL_MAT_EMISSION_BIT_PGI           0x00800000
		00755 #define GL_MAT_COLOR_INDEXES_BIT_PGI      0x01000000
		00756 #define GL_MAT_SHININESS_BIT_PGI          0x02000000
		00757 #define GL_MAT_SPECULAR_BIT_PGI           0x04000000
		00758 #define GL_NORMAL_BIT_PGI                 0x08000000
		00759 #define GL_TEXCOORD1_BIT_PGI              0x10000000
		00760 #define GL_TEXCOORD2_BIT_PGI              0x20000000
		00761 #define GL_TEXCOORD3_BIT_PGI              0x40000000
		00762 #define GL_TEXCOORD4_BIT_PGI              0x80000000
		00763 #define GL_VERTEX23_BIT_PGI               0x00000004
		00764 #define GL_VERTEX4_BIT_PGI                0x00000008
		00765 #endif
		00766
		00767 #ifndef GL_PGI_misc_hints
		00768 #define GL_PREFER_DOUBLEBUFFER_HINT_PGI   0x1A1F8
		00769 #define GL_CONSERVE_MEMORY_HINT_PGI       0x1A1FD
		00770 #define GL_RECLAIM_MEMORY_HINT_PGI        0x1A1FE
		00771 #define GL_NATIVE_GRAPHICS_HANDLE_PGI     0x1A202
		00772 #define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
		00773 #define GL_NATIVE_GRAPHICS_END_HINT_PGI   0x1A204
		00774 #define GL_ALWAYS_FAST_HINT_PGI           0x1A20C
		00775 #define GL_ALWAYS_SOFT_HINT_PGI           0x1A20D
		00776 #define GL_ALLOW_DRAW_OBJ_HINT_PGI        0x1A20E
		00777 #define GL_ALLOW_DRAW_WIN_HINT_PGI        0x1A20F
		00778 #define GL_ALLOW_DRAW_FRG_HINT_PGI        0x1A210
		00779 #define GL_ALLOW_DRAW_MEM_HINT_PGI        0x1A211
		00780 #define GL_STRICT_DEPTHFUNC_HINT_PGI      0x1A216
		00781 #define GL_STRICT_LIGHTING_HINT_PGI       0x1A217
		00782 #define GL_STRICT_SCISSOR_HINT_PGI        0x1A218
		00783 #define GL_FULL_STIPPLE_HINT_PGI          0x1A219
		00784 #define GL_CLIP_NEAR_HINT_PGI             0x1A220
		00785 #define GL_CLIP_FAR_HINT_PGI              0x1A221
		00786 #define GL_WIDE_LINE_HINT_PGI             0x1A222
		00787 #define GL_BACK_NORMALS_HINT_PGI          0x1A223
		00788 #endif
		00789
		00790 #ifndef GL_EXT_paletted_texture
		00791 #define GL_COLOR_INDEX1_EXT               0x80E2
		00792 #define GL_COLOR_INDEX2_EXT               0x80E3
		00793 #define GL_COLOR_INDEX4_EXT               0x80E4
		00794 #define GL_COLOR_INDEX8_EXT               0x80E5
		00795 #define GL_COLOR_INDEX12_EXT              0x80E6
		00796 #define GL_COLOR_INDEX16_EXT              0x80E7
		00797 #define GL_TEXTURE_INDEX_SIZE_EXT         0x80ED
		00798 #endif
		00799
		00800 #ifndef GL_EXT_clip_volume_hint
		00801 #define GL_CLIP_VOLUME_CLIPPING_HINT_EXT  0x80F0
		00802 #endif
		00803
		00804 #ifndef GL_SGIX_list_priority
		00805 #define GL_LIST_PRIORITY_SGIX             0x8182
		00806 #endif
		00807
		00808 #ifndef GL_SGIX_ir_instrument1
		00809 #define GL_IR_INSTRUMENT1_SGIX            0x817F
		00810 #endif
		00811
		00812 #ifndef GL_SGIX_calligraphic_fragment
		00813 #define GL_CALLIGRAPHIC_FRAGMENT_SGIX     0x8183
		00814 #endif
		00815
		00816 #ifndef GL_SGIX_texture_lod_bias
		00817 #define GL_TEXTURE_LOD_BIAS_S_SGIX        0x818E
		00818 #define GL_TEXTURE_LOD_BIAS_T_SGIX        0x818F
		00819 #define GL_TEXTURE_LOD_BIAS_R_SGIX        0x8190
		00820 #endif
		00821
		00822 #ifndef GL_SGIX_shadow_ambient
		00823 #define GL_SHADOW_AMBIENT_SGIX            0x80BF
		00824 #endif
		00825
		00826 #ifndef GL_EXT_index_texture
		00827 #endif
		00828
		00829 #ifndef GL_EXT_index_material
		00830 #define GL_INDEX_MATERIAL_EXT             0x81B8
		00831 #define GL_INDEX_MATERIAL_PARAMETER_EXT   0x81B9
		00832 #define GL_INDEX_MATERIAL_FACE_EXT        0x81BA
		00833 #endif
		00834
		00835 #ifndef GL_EXT_index_func
		00836 #define GL_INDEX_TEST_EXT                 0x81B5
		00837 #define GL_INDEX_TEST_FUNC_EXT            0x81B6
		00838 #define GL_INDEX_TEST_REF_EXT             0x81B7
		00839 #endif
		00840
		00841 #ifndef GL_EXT_index_array_formats
		00842 #define GL_IUI_V2F_EXT                    0x81AD
		00843 #define GL_IUI_V3F_EXT                    0x81AE
		00844 #define GL_IUI_N3F_V2F_EXT                0x81AF
		00845 #define GL_IUI_N3F_V3F_EXT                0x81B0
		00846 #define GL_T2F_IUI_V2F_EXT                0x81B1
		00847 #define GL_T2F_IUI_V3F_EXT                0x81B2
		00848 #define GL_T2F_IUI_N3F_V2F_EXT            0x81B3
		00849 #define GL_T2F_IUI_N3F_V3F_EXT            0x81B4
		00850 #endif
		00851
		00852 #ifndef GL_EXT_compiled_vertex_array
		00853 #define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT   0x81A8
		00854 #define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT   0x81A9
		00855 #endif
		00856
		00857 #ifndef GL_EXT_cull_vertex
		00858 #define GL_CULL_VERTEX_EXT                0x81AA
		00859 #define GL_CULL_VERTEX_EYE_POSITION_EXT   0x81AB
		00860 #define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC
		00861 #endif
		00862
		00863 #ifndef GL_SGIX_ycrcb
		00864 #define GL_YCRCB_422_SGIX                 0x81BB
		00865 #define GL_YCRCB_444_SGIX                 0x81BC
		00866 #endif
		00867
		00868 #ifndef GL_SGIX_fragment_lighting
		00869 #define GL_FRAGMENT_LIGHTING_SGIX         0x8400
		00870 #define GL_FRAGMENT_COLOR_MATERIAL_SGIX   0x8401
		00871 #define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
		00872 #define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
		00873 #define GL_MAX_FRAGMENT_LIGHTS_SGIX       0x8404
		00874 #define GL_MAX_ACTIVE_LIGHTS_SGIX         0x8405
		00875 #define GL_CURRENT_RASTER_NORMAL_SGIX     0x8406
		00876 #define GL_LIGHT_ENV_MODE_SGIX            0x8407
		00877 #define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
		00878 #define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
		00879 #define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
		00880 #define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
		00881 #define GL_FRAGMENT_LIGHT0_SGIX           0x840C
		00882 #define GL_FRAGMENT_LIGHT1_SGIX           0x840D
		00883 #define GL_FRAGMENT_LIGHT2_SGIX           0x840E
		00884 #define GL_FRAGMENT_LIGHT3_SGIX           0x840F
		00885 #define GL_FRAGMENT_LIGHT4_SGIX           0x8410
		00886 #define GL_FRAGMENT_LIGHT5_SGIX           0x8411
		00887 #define GL_FRAGMENT_LIGHT6_SGIX           0x8412
		00888 #define GL_FRAGMENT_LIGHT7_SGIX           0x8413
		00889 #endif
		00890
		00891 #ifndef GL_IBM_rasterpos_clip
		00892 #define GL_RASTER_POSITION_UNCLIPPED_IBM  0x19262
		00893 #endif
		00894
		00895 #ifndef GL_HP_texture_lighting
		00896 #define GL_TEXTURE_LIGHTING_MODE_HP       0x8167
		00897 #define GL_TEXTURE_POST_SPECULAR_HP       0x8168
		00898 #define GL_TEXTURE_PRE_SPECULAR_HP        0x8169
		00899 #endif
		00900
		00901 #ifndef GL_EXT_draw_range_elements
		00902 #define GL_MAX_ELEMENTS_VERTICES_EXT      0x80E8
		00903 #define GL_MAX_ELEMENTS_INDICES_EXT       0x80E9
		00904 #endif
		00905
		00906 #ifndef GL_WIN_phong_shading
		00907 #define GL_PHONG_WIN                      0x80EA
		00908 #define GL_PHONG_HINT_WIN                 0x80EB
		00909 #endif
		00910
		00911 #ifndef GL_WIN_specular_fog
		00912 #define GL_FOG_SPECULAR_TEXTURE_WIN       0x80EC
		00913 #endif
		00914
		00915 #ifndef GL_EXT_light_texture
		00916 #define GL_FRAGMENT_MATERIAL_EXT          0x8349
		00917 #define GL_FRAGMENT_NORMAL_EXT            0x834A
		00918 #define GL_FRAGMENT_COLOR_EXT             0x834C
		00919 #define GL_ATTENUATION_EXT                0x834D
		00920 #define GL_SHADOW_ATTENUATION_EXT         0x834E
		00921 #define GL_TEXTURE_APPLICATION_MODE_EXT   0x834F
		00922 #define GL_TEXTURE_LIGHT_EXT              0x8350
		00923 #define GL_TEXTURE_MATERIAL_FACE_EXT      0x8351
		00924 #define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
		00925 /* reuse GL_FRAGMENT_DEPTH_EXT */
		00926 #endif
		00927
		00928 #ifndef GL_SGIX_blend_alpha_minmax
		00929 #define GL_ALPHA_MIN_SGIX                 0x8320
		00930 #define GL_ALPHA_MAX_SGIX                 0x8321
		00931 #endif
		00932
		00933 #ifndef GL_EXT_bgra
		00934 #define GL_BGR_EXT                        0x80E0
		00935 #define GL_BGRA_EXT                       0x80E1
		00936 #endif
		00937
		00938 #ifndef GL_INTEL_texture_scissor
		00939 #endif
		00940
		00941 #ifndef GL_INTEL_parallel_arrays
		00942 #define GL_PARALLEL_ARRAYS_INTEL          0x83F4
		00943 #define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5
		00944 #define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
		00945 #define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
		00946 #define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8
		00947 #endif
		00948
		00949 #ifndef GL_HP_occlusion_test
		00950 #define GL_OCCLUSION_TEST_HP              0x8165
		00951 #define GL_OCCLUSION_TEST_RESULT_HP       0x8166
		00952 #endif
		00953
		00954 #ifndef GL_EXT_pixel_transform
		00955 #define GL_PIXEL_TRANSFORM_2D_EXT         0x8330
		00956 #define GL_PIXEL_MAG_FILTER_EXT           0x8331
		00957 #define GL_PIXEL_MIN_FILTER_EXT           0x8332
		00958 #define GL_PIXEL_CUBIC_WEIGHT_EXT         0x8333
		00959 #define GL_CUBIC_EXT                      0x8334
		00960 #define GL_AVERAGE_EXT                    0x8335
		00961 #define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
		00962 #define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
		00963 #define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT  0x8338
		00964 #endif
		00965
		00966 #ifndef GL_EXT_pixel_transform_color_table
		00967 #endif
		00968
		00969 #ifndef GL_EXT_shared_texture_palette
		00970 #define GL_SHARED_TEXTURE_PALETTE_EXT     0x81FB
		00971 #endif
		00972
		00973 #ifndef GL_EXT_separate_specular_color
		00974 #define GL_LIGHT_MODEL_COLOR_CONTROL_EXT  0x81F8
		00975 #define GL_SINGLE_COLOR_EXT               0x81F9
		00976 #define GL_SEPARATE_SPECULAR_COLOR_EXT    0x81FA
		00977 #endif
		00978
		00979 #ifndef GL_EXT_secondary_color
		00980 #define GL_COLOR_SUM_EXT                  0x8458
		00981 #define GL_CURRENT_SECONDARY_COLOR_EXT    0x8459
		00982 #define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
		00983 #define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
		00984 #define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
		00985 #define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
		00986 #define GL_SECONDARY_COLOR_ARRAY_EXT      0x845E
		00987 #endif
		00988
		00989 #ifndef GL_EXT_texture_perturb_normal
		00990 #define GL_PERTURB_EXT                    0x85AE
		00991 #define GL_TEXTURE_NORMAL_EXT             0x85AF
		00992 #endif
		00993
		00994 #ifndef GL_EXT_multi_draw_arrays
		00995 #endif
		00996
		00997 #ifndef GL_EXT_fog_coord
		00998 #define GL_FOG_COORDINATE_SOURCE_EXT      0x8450
		00999 #define GL_FOG_COORDINATE_EXT             0x8451
		01000 #define GL_FRAGMENT_DEPTH_EXT             0x8452
		01001 #define GL_CURRENT_FOG_COORDINATE_EXT     0x8453
		01002 #define GL_FOG_COORDINATE_ARRAY_TYPE_EXT  0x8454
		01003 #define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
		01004 #define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
		01005 #define GL_FOG_COORDINATE_ARRAY_EXT       0x8457
		01006 #endif
		01007
		01008 #ifndef GL_REND_screen_coordinates
		01009 #define GL_SCREEN_COORDINATES_REND        0x8490
		01010 #define GL_INVERTED_SCREEN_W_REND         0x8491
		01011 #endif
		01012
		01013 #ifndef GL_EXT_coordinate_frame
		01014 #define GL_TANGENT_ARRAY_EXT              0x8439
		01015 #define GL_BINORMAL_ARRAY_EXT             0x843A
		01016 #define GL_CURRENT_TANGENT_EXT            0x843B
		01017 #define GL_CURRENT_BINORMAL_EXT           0x843C
		01018 #define GL_TANGENT_ARRAY_TYPE_EXT         0x843E
		01019 #define GL_TANGENT_ARRAY_STRIDE_EXT       0x843F
		01020 #define GL_BINORMAL_ARRAY_TYPE_EXT        0x8440
		01021 #define GL_BINORMAL_ARRAY_STRIDE_EXT      0x8441
		01022 #define GL_TANGENT_ARRAY_POINTER_EXT      0x8442
		01023 #define GL_BINORMAL_ARRAY_POINTER_EXT     0x8443
		01024 #define GL_MAP1_TANGENT_EXT               0x8444
		01025 #define GL_MAP2_TANGENT_EXT               0x8445
		01026 #define GL_MAP1_BINORMAL_EXT              0x8446
		01027 #define GL_MAP2_BINORMAL_EXT              0x8447
		01028 #endif
		01029
		01030 #ifndef GL_EXT_texture_env_combine
		01031 #define GL_COMBINE_EXT                    0x8570
		01032 #define GL_COMBINE_RGB_EXT                0x8571
		01033 #define GL_COMBINE_ALPHA_EXT              0x8572
		01034 #define GL_RGB_SCALE_EXT                  0x8573
		01035 #define GL_ADD_SIGNED_EXT                 0x8574
		01036 #define GL_INTERPOLATE_EXT                0x8575
		01037 #define GL_CONSTANT_EXT                   0x8576
		01038 #define GL_PRIMARY_COLOR_EXT              0x8577
		01039 #define GL_PREVIOUS_EXT                   0x8578
		01040 #define GL_SOURCE0_RGB_EXT                0x8580
		01041 #define GL_SOURCE1_RGB_EXT                0x8581
		01042 #define GL_SOURCE2_RGB_EXT                0x8582
		01043 #define GL_SOURCE3_RGB_EXT                0x8583
		01044 #define GL_SOURCE4_RGB_EXT                0x8584
		01045 #define GL_SOURCE5_RGB_EXT                0x8585
		01046 #define GL_SOURCE6_RGB_EXT                0x8586
		01047 #define GL_SOURCE7_RGB_EXT                0x8587
		01048 #define GL_SOURCE0_ALPHA_EXT              0x8588
		01049 #define GL_SOURCE1_ALPHA_EXT              0x8589
		01050 #define GL_SOURCE2_ALPHA_EXT              0x858A
		01051 #define GL_SOURCE3_ALPHA_EXT              0x858B
		01052 #define GL_SOURCE4_ALPHA_EXT              0x858C
		01053 #define GL_SOURCE5_ALPHA_EXT              0x858D
		01054 #define GL_SOURCE6_ALPHA_EXT              0x858E
		01055 #define GL_SOURCE7_ALPHA_EXT              0x858F
		01056 #define GL_OPERAND0_RGB_EXT               0x8590
		01057 #define GL_OPERAND1_RGB_EXT               0x8591
		01058 #define GL_OPERAND2_RGB_EXT               0x8592
		01059 #define GL_OPERAND3_RGB_EXT               0x8593
		01060 #define GL_OPERAND4_RGB_EXT               0x8594
		01061 #define GL_OPERAND5_RGB_EXT               0x8595
		01062 #define GL_OPERAND6_RGB_EXT               0x8596
		01063 #define GL_OPERAND7_RGB_EXT               0x8597
		01064 #define GL_OPERAND0_ALPHA_EXT             0x8598
		01065 #define GL_OPERAND1_ALPHA_EXT             0x8599
		01066 #define GL_OPERAND2_ALPHA_EXT             0x859A
		01067 #define GL_OPERAND3_ALPHA_EXT             0x859B
		01068 #define GL_OPERAND4_ALPHA_EXT             0x859C
		01069 #define GL_OPERAND5_ALPHA_EXT             0x859D
		01070 #define GL_OPERAND6_ALPHA_EXT             0x859E
		01071 #define GL_OPERAND7_ALPHA_EXT             0x859F
		01072 #endif
		01073
		01074 #ifndef GL_APPLE_specular_vector
		01075 #define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0
		01076 #endif
		01077
		01078 #ifndef GL_APPLE_transform_hint
		01079 #define GL_TRANSFORM_HINT_APPLE           0x85B1
		01080 #endif
		01081
		01082 #ifndef GL_SGIX_fog_scale
		01083 #define GL_FOG_SCALE_SGIX                 0x81FC
		01084 #define GL_FOG_SCALE_VALUE_SGIX           0x81FD
		01085 #endif
		01086
		01087 #ifndef GL_SUNX_constant_data
		01088 #define GL_UNPACK_CONSTANT_DATA_SUNX      0x81D5
		01089 #define GL_TEXTURE_CONSTANT_DATA_SUNX     0x81D6
		01090 #endif
		01091
		01092 #ifndef GL_SUN_global_alpha
		01093 #define GL_GLOBAL_ALPHA_SUN               0x81D9
		01094 #define GL_GLOBAL_ALPHA_FACTOR_SUN        0x81DA
		01095 #endif
		01096
		01097 #ifndef GL_SUN_triangle_list
		01098 #define GL_RESTART_SUN                    0x01
		01099 #define GL_REPLACE_MIDDLE_SUN             0x02
		01100 #define GL_REPLACE_OLDEST_SUN             0x03
		01101 #define GL_TRIANGLE_LIST_SUN              0x81D7
		01102 #define GL_REPLACEMENT_CODE_SUN           0x81D8
		01103 #define GL_REPLACEMENT_CODE_ARRAY_SUN     0x85C0
		01104 #define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
		01105 #define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
		01106 #define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
		01107 #define GL_R1UI_V3F_SUN                   0x85C4
		01108 #define GL_R1UI_C4UB_V3F_SUN              0x85C5
		01109 #define GL_R1UI_C3F_V3F_SUN               0x85C6
		01110 #define GL_R1UI_N3F_V3F_SUN               0x85C7
		01111 #define GL_R1UI_C4F_N3F_V3F_SUN           0x85C8
		01112 #define GL_R1UI_T2F_V3F_SUN               0x85C9
		01113 #define GL_R1UI_T2F_N3F_V3F_SUN           0x85CA
		01114 #define GL_R1UI_T2F_C4F_N3F_V3F_SUN       0x85CB
		01115 #endif
		01116
		01117 #ifndef GL_SUN_vertex
		01118 #endif
		01119
		01120 #ifndef GL_EXT_blend_func_separate
		01121 #define GL_BLEND_DST_RGB_EXT              0x80C8
		01122 #define GL_BLEND_SRC_RGB_EXT              0x80C9
		01123 #define GL_BLEND_DST_ALPHA_EXT            0x80CA
		01124 #define GL_BLEND_SRC_ALPHA_EXT            0x80CB
		01125 #endif
		01126
		01127 #ifndef GL_INGR_color_clamp
		01128 #define GL_RED_MIN_CLAMP_INGR             0x8560
		01129 #define GL_GREEN_MIN_CLAMP_INGR           0x8561
		01130 #define GL_BLUE_MIN_CLAMP_INGR            0x8562
		01131 #define GL_ALPHA_MIN_CLAMP_INGR           0x8563
		01132 #define GL_RED_MAX_CLAMP_INGR             0x8564
		01133 #define GL_GREEN_MAX_CLAMP_INGR           0x8565
		01134 #define GL_BLUE_MAX_CLAMP_INGR            0x8566
		01135 #define GL_ALPHA_MAX_CLAMP_INGR           0x8567
		01136 #endif
		01137
		01138 #ifndef GL_INGR_interlace_read
		01139 #define GL_INTERLACE_READ_INGR            0x8568
		01140 #endif
		01141
		01142 #ifndef GL_EXT_stencil_wrap
		01143 #define GL_INCR_WRAP_EXT                  0x8507
		01144 #define GL_DECR_WRAP_EXT                  0x8508
		01145 #endif
		01146
		01147 #ifndef GL_EXT_422_pixels
		01148 #define GL_422_EXT                        0x80CC
		01149 #define GL_422_REV_EXT                    0x80CD
		01150 #define GL_422_AVERAGE_EXT                0x80CE
		01151 #define GL_422_REV_AVERAGE_EXT            0x80CF
		01152 #endif
		01153
		01154 #ifndef GL_NV_texgen_reflection
		01155 #define GL_NORMAL_MAP_NV                  0x8511
		01156 #define GL_REFLECTION_MAP_NV              0x8512
		01157 #endif
		01158
		01159 #ifndef GL_EXT_texture_cube_map
		01160 #define GL_NORMAL_MAP_EXT                 0x8511
		01161 #define GL_REFLECTION_MAP_EXT             0x8512
		01162 #define GL_TEXTURE_CUBE_MAP_EXT           0x8513
		01163 #define GL_TEXTURE_BINDING_CUBE_MAP_EXT   0x8514
		01164 #define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
		01165 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
		01166 #define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
		01167 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
		01168 #define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
		01169 #define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
		01170 #define GL_PROXY_TEXTURE_CUBE_MAP_EXT     0x851B
		01171 #define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT  0x851C
		01172 #endif
		01173
		01174 #ifndef GL_SUN_convolution_border_modes
		01175 #define GL_WRAP_BORDER_SUN                0x81D4
		01176 #endif
		01177
		01178 #ifndef GL_EXT_texture_env_add
		01179 #endif
		01180
		01181 #ifndef GL_EXT_texture_lod_bias
		01182 #define GL_MAX_TEXTURE_LOD_BIAS_EXT       0x84FD
		01183 #define GL_TEXTURE_FILTER_CONTROL_EXT     0x8500
		01184 #define GL_TEXTURE_LOD_BIAS_EXT           0x8501
		01185 #endif
		01186
		01187 #ifndef GL_EXT_texture_filter_anisotropic
		01188 #define GL_TEXTURE_MAX_ANISOTROPY_EXT     0x84FE
		01189 #define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
		01190 #endif
		01191
		01192 #ifndef GL_EXT_vertex_weighting
		01193 #define GL_MODELVIEW0_STACK_DEPTH_EXT     GL_MODELVIEW_STACK_DEPTH
		01194 #define GL_MODELVIEW1_STACK_DEPTH_EXT     0x8502
		01195 #define GL_MODELVIEW0_MATRIX_EXT          GL_MODELVIEW_MATRIX
		01196 #define GL_MODELVIEW_MATRIX1_EXT          0x8506
		01197 #define GL_VERTEX_WEIGHTING_EXT           0x8509
		01198 #define GL_MODELVIEW0_EXT                 GL_MODELVIEW
		01199 #define GL_MODELVIEW1_EXT                 0x850A
		01200 #define GL_CURRENT_VERTEX_WEIGHT_EXT      0x850B
		01201 #define GL_VERTEX_WEIGHT_ARRAY_EXT        0x850C
		01202 #define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT   0x850D
		01203 #define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT   0x850E
		01204 #define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
		01205 #define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510
		01206 #endif
		01207
		01208 #ifndef GL_NV_light_max_exponent
		01209 #define GL_MAX_SHININESS_NV               0x8504
		01210 #define GL_MAX_SPOT_EXPONENT_NV           0x8505
		01211 #endif
		01212
		01213 #ifndef GL_NV_vertex_array_range
		01214 #define GL_VERTEX_ARRAY_RANGE_NV          0x851D
		01215 #define GL_VERTEX_ARRAY_RANGE_LENGTH_NV   0x851E
		01216 #define GL_VERTEX_ARRAY_RANGE_VALID_NV    0x851F
		01217 #define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
		01218 #define GL_VERTEX_ARRAY_RANGE_POINTER_NV  0x8521
		01219 #endif
		01220
		01221 #ifndef GL_NV_vertex_array_range2
		01222 #define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533
		01223 #endif
		01224
		01225 #ifndef GL_NV_register_combiners
		01226 #define GL_REGISTER_COMBINERS_NV          0x8522
		01227 #define GL_VARIABLE_A_NV                  0x8523
		01228 #define GL_VARIABLE_B_NV                  0x8524
		01229 #define GL_VARIABLE_C_NV                  0x8525
		01230 #define GL_VARIABLE_D_NV                  0x8526
		01231 #define GL_VARIABLE_E_NV                  0x8527
		01232 #define GL_VARIABLE_F_NV                  0x8528
		01233 #define GL_VARIABLE_G_NV                  0x8529
		01234 #define GL_CONSTANT_COLOR0_NV             0x852A
		01235 #define GL_CONSTANT_COLOR1_NV             0x852B
		01236 #define GL_PRIMARY_COLOR_NV               0x852C
		01237 #define GL_SECONDARY_COLOR_NV             0x852D
		01238 #define GL_SPARE0_NV                      0x852E
		01239 #define GL_SPARE1_NV                      0x852F
		01240 #define GL_DISCARD_NV                     0x8530
		01241 #define GL_E_TIMES_F_NV                   0x8531
		01242 #define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
		01243 #define GL_UNSIGNED_IDENTITY_NV           0x8536
		01244 #define GL_UNSIGNED_INVERT_NV             0x8537
		01245 #define GL_EXPAND_NORMAL_NV               0x8538
		01246 #define GL_EXPAND_NEGATE_NV               0x8539
		01247 #define GL_HALF_BIAS_NORMAL_NV            0x853A
		01248 #define GL_HALF_BIAS_NEGATE_NV            0x853B
		01249 #define GL_SIGNED_IDENTITY_NV             0x853C
		01250 #define GL_SIGNED_NEGATE_NV               0x853D
		01251 #define GL_SCALE_BY_TWO_NV                0x853E
		01252 #define GL_SCALE_BY_FOUR_NV               0x853F
		01253 #define GL_SCALE_BY_ONE_HALF_NV           0x8540
		01254 #define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV   0x8541
		01255 #define GL_COMBINER_INPUT_NV              0x8542
		01256 #define GL_COMBINER_MAPPING_NV            0x8543
		01257 #define GL_COMBINER_COMPONENT_USAGE_NV    0x8544
		01258 #define GL_COMBINER_AB_DOT_PRODUCT_NV     0x8545
		01259 #define GL_COMBINER_CD_DOT_PRODUCT_NV     0x8546
		01260 #define GL_COMBINER_MUX_SUM_NV            0x8547
		01261 #define GL_COMBINER_SCALE_NV              0x8548
		01262 #define GL_COMBINER_BIAS_NV               0x8549
		01263 #define GL_COMBINER_AB_OUTPUT_NV          0x854A
		01264 #define GL_COMBINER_CD_OUTPUT_NV          0x854B
		01265 #define GL_COMBINER_SUM_OUTPUT_NV         0x854C
		01266 #define GL_MAX_GENERAL_COMBINERS_NV       0x854D
		01267 #define GL_NUM_GENERAL_COMBINERS_NV       0x854E
		01268 #define GL_COLOR_SUM_CLAMP_NV             0x854F
		01269 #define GL_COMBINER0_NV                   0x8550
		01270 #define GL_COMBINER1_NV                   0x8551
		01271 #define GL_COMBINER2_NV                   0x8552
		01272 #define GL_COMBINER3_NV                   0x8553
		01273 #define GL_COMBINER4_NV                   0x8554
		01274 #define GL_COMBINER5_NV                   0x8555
		01275 #define GL_COMBINER6_NV                   0x8556
		01276 #define GL_COMBINER7_NV                   0x8557
		01277 /* reuse GL_TEXTURE0_ARB */
		01278 /* reuse GL_TEXTURE1_ARB */
		01279 /* reuse GL_ZERO */
		01280 /* reuse GL_NONE */
		01281 /* reuse GL_FOG */
		01282 #endif
		01283
		01284 #ifndef GL_NV_fog_distance
		01285 #define GL_FOG_DISTANCE_MODE_NV           0x855A
		01286 #define GL_EYE_RADIAL_NV                  0x855B
		01287 #define GL_EYE_PLANE_ABSOLUTE_NV          0x855C
		01288 /* reuse GL_EYE_PLANE */
		01289 #endif
		01290
		01291 #ifndef GL_NV_texgen_emboss
		01292 #define GL_EMBOSS_LIGHT_NV                0x855D
		01293 #define GL_EMBOSS_CONSTANT_NV             0x855E
		01294 #define GL_EMBOSS_MAP_NV                  0x855F
		01295 #endif
		01296
		01297 #ifndef GL_NV_blend_square
		01298 #endif
		01299
		01300 #ifndef GL_NV_texture_env_combine4
		01301 #define GL_COMBINE4_NV                    0x8503
		01302 #define GL_SOURCE3_RGB_NV                 0x8583
		01303 #define GL_SOURCE3_ALPHA_NV               0x858B
		01304 #define GL_OPERAND3_RGB_NV                0x8593
		01305 #define GL_OPERAND3_ALPHA_NV              0x859B
		01306 #endif
		01307
		01308
		01309 #ifndef GL_MESA_resize_buffers
		01310 #endif
		01311
		01312 #ifndef GL_MESA_window_pos
		01313 #endif
		01314
		01315 #ifndef GL_EXT_texture_compression_s3tc
		01316 #define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
		01317 #define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
		01318 #define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
		01319 #define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
		01320 #endif
		01321
		01322 #ifndef GL_IBM_cull_vertex
		01323 #define GL_CULL_VERTEX_IBM                103050
		01324 #endif
		01325
		01326 #ifndef GL_IBM_multimode_draw_arrays
		01327 #endif
		01328
		01329 #ifndef GL_IBM_vertex_array_lists
		01330 #define GL_VERTEX_ARRAY_LIST_IBM          103070
		01331 #define GL_NORMAL_ARRAY_LIST_IBM          103071
		01332 #define GL_COLOR_ARRAY_LIST_IBM           103072
		01333 #define GL_INDEX_ARRAY_LIST_IBM           103073
		01334 #define GL_TEXTURE_COORD_ARRAY_LIST_IBM   103074
		01335 #define GL_EDGE_FLAG_ARRAY_LIST_IBM       103075
		01336 #define GL_FOG_COORDINATE_ARRAY_LIST_IBM  103076
		01337 #define GL_SECONDARY_COLOR_ARRAY_LIST_IBM 103077
		01338 #define GL_VERTEX_ARRAY_LIST_STRIDE_IBM   103080
		01339 #define GL_NORMAL_ARRAY_LIST_STRIDE_IBM   103081
		01340 #define GL_COLOR_ARRAY_LIST_STRIDE_IBM    103082
		01341 #define GL_INDEX_ARRAY_LIST_STRIDE_IBM    103083
		01342 #define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM 103084
		01343 #define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM 103085
		01344 #define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM 103086
		01345 #define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM 103087
		01346 #endif
		01347
		01348 #ifndef GL_SGIX_subsample
		01349 #define GL_PACK_SUBSAMPLE_RATE_SGIX       0x85A0
		01350 #define GL_UNPACK_SUBSAMPLE_RATE_SGIX     0x85A1
		01351 #define GL_PIXEL_SUBSAMPLE_4444_SGIX      0x85A2
		01352 #define GL_PIXEL_SUBSAMPLE_2424_SGIX      0x85A3
		01353 #define GL_PIXEL_SUBSAMPLE_4242_SGIX      0x85A4
		01354 #endif
		01355
		01356 #ifndef GL_SGIX_ycrcb_subsample
		01357 #endif
		01358
		01359 #ifndef GL_SGIX_ycrcba
		01360 #define GL_YCRCB_SGIX                     0x8318
		01361 #define GL_YCRCBA_SGIX                    0x8319
		01362 #endif
		01363
		01364 #ifndef GL_SGI_depth_pass_instrument
		01365 #define GL_DEPTH_PASS_INSTRUMENT_SGIX     0x8310
		01366 #define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX 0x8311
		01367 #define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX 0x8312
		01368 #endif
		01369
		01370 #ifndef GL_3DFX_texture_compression_FXT1
		01371 #define GL_COMPRESSED_RGB_FXT1_3DFX       0x86B0
		01372 #define GL_COMPRESSED_RGBA_FXT1_3DFX      0x86B1
		01373 #endif
		01374
		01375 #ifndef GL_3DFX_multisample
		01376 #define GL_MULTISAMPLE_3DFX               0x86B2
		01377 #define GL_SAMPLE_BUFFERS_3DFX            0x86B3
		01378 #define GL_SAMPLES_3DFX                   0x86B4
		01379 #define GL_MULTISAMPLE_BIT_3DFX           0x20000000
		01380 #endif
		01381
		01382 #ifndef GL_3DFX_tbuffer
		01383 #endif
		01384
		01385 #ifndef GL_EXT_multisample
		01386 #define GL_MULTISAMPLE_EXT                0x809D
		01387 #define GL_SAMPLE_ALPHA_TO_MASK_EXT       0x809E
		01388 #define GL_SAMPLE_ALPHA_TO_ONE_EXT        0x809F
		01389 #define GL_SAMPLE_MASK_EXT                0x80A0
		01390 #define GL_1PASS_EXT                      0x80A1
		01391 #define GL_2PASS_0_EXT                    0x80A2
		01392 #define GL_2PASS_1_EXT                    0x80A3
		01393 #define GL_4PASS_0_EXT                    0x80A4
		01394 #define GL_4PASS_1_EXT                    0x80A5
		01395 #define GL_4PASS_2_EXT                    0x80A6
		01396 #define GL_4PASS_3_EXT                    0x80A7
		01397 #define GL_SAMPLE_BUFFERS_EXT             0x80A8
		01398 #define GL_SAMPLES_EXT                    0x80A9
		01399 #define GL_SAMPLE_MASK_VALUE_EXT          0x80AA
		01400 #define GL_SAMPLE_MASK_INVERT_EXT         0x80AB
		01401 #define GL_SAMPLE_PATTERN_EXT             0x80AC
		01402 #endif
		01403
		01404 #ifndef GL_SGIX_vertex_preclip
		01405 #define GL_VERTEX_PRECLIP_SGIX            0x83EE
		01406 #define GL_VERTEX_PRECLIP_HINT_SGIX       0x83EF
		01407 #endif
		01408
		01409 #ifndef GL_SGIX_convolution_accuracy
		01410 #define GL_CONVOLUTION_HINT_SGIX          0x8316
		01411 #endif
		01412
		01413 #ifndef GL_SGIX_resample
		01414 #define GL_PACK_RESAMPLE_SGIX             0x842C
		01415 #define GL_UNPACK_RESAMPLE_SGIX           0x842D
		01416 #define GL_RESAMPLE_REPLICATE_SGIX        0x842E
		01417 #define GL_RESAMPLE_ZERO_FILL_SGIX        0x842F
		01418 #define GL_RESAMPLE_DECIMATE_SGIX         0x8430
		01419 #endif
		01420
		01421 #ifndef GL_SGIS_point_line_texgen
		01422 #define GL_EYE_DISTANCE_TO_POINT_SGIS     0x81F0
		01423 #define GL_OBJECT_DISTANCE_TO_POINT_SGIS  0x81F1
		01424 #define GL_EYE_DISTANCE_TO_LINE_SGIS      0x81F2
		01425 #define GL_OBJECT_DISTANCE_TO_LINE_SGIS   0x81F3
		01426 #define GL_EYE_POINT_SGIS                 0x81F4
		01427 #define GL_OBJECT_POINT_SGIS              0x81F5
		01428 #define GL_EYE_LINE_SGIS                  0x81F6
		01429 #define GL_OBJECT_LINE_SGIS               0x81F7
		01430 #endif
		01431
		01432 #ifndef GL_SGIS_texture_color_mask
		01433 #define GL_TEXTURE_COLOR_WRITEMASK_SGIS   0x81EF
		01434 #endif
		01435
		01436
		01437 /*************************************************************/
		01438
		01439 #ifndef GL_VERSION_1_2
		01440 #define GL_VERSION_1_2 1
		01441 #ifdef GL_GLEXT_PROTOTYPES
		01442 extern void APIENTRY glBlendColor(GLclampf, GLclampf, GLclampf, GLclampf);
	01443 extern void APIENTRY glBlendEquation(GLenum);
	01444 extern void APIENTRY glDrawRangeElements(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
	01445 extern void APIENTRY glColorTable(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	01446 extern void APIENTRY glColorTableParameterfv(GLenum, GLenum, const GLfloat*);
	01447 extern void APIENTRY glColorTableParameteriv(GLenum, GLenum, const GLint*);
	01448 extern void APIENTRY glCopyColorTable(GLenum, GLenum, GLint, GLint, GLsizei);
	01449 extern void APIENTRY glGetColorTable(GLenum, GLenum, GLenum, GLvoid*);
	01450 extern void APIENTRY glGetColorTableParameterfv(GLenum, GLenum, GLfloat*);
	01451 extern void APIENTRY glGetColorTableParameteriv(GLenum, GLenum, GLint*);
	01452 extern void APIENTRY glColorSubTable(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01453 extern void APIENTRY glCopyColorSubTable(GLenum, GLsizei, GLint, GLint, GLsizei);
	01454 extern void APIENTRY glConvolutionFilter1D(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	01455 extern void APIENTRY glConvolutionFilter2D(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01456 extern void APIENTRY glConvolutionParameterf(GLenum, GLenum, GLfloat);
	01457 extern void APIENTRY glConvolutionParameterfv(GLenum, GLenum, const GLfloat*);
	01458 extern void APIENTRY glConvolutionParameteri(GLenum, GLenum, GLint);
	01459 extern void APIENTRY glConvolutionParameteriv(GLenum, GLenum, const GLint*);
	01460 extern void APIENTRY glCopyConvolutionFilter1D(GLenum, GLenum, GLint, GLint, GLsizei);
	01461 extern void APIENTRY glCopyConvolutionFilter2D(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
	01462 extern void APIENTRY glGetConvolutionFilter(GLenum, GLenum, GLenum, GLvoid*);
	01463 extern void APIENTRY glGetConvolutionParameterfv(GLenum, GLenum, GLfloat*);
	01464 extern void APIENTRY glGetConvolutionParameteriv(GLenum, GLenum, GLint*);
	01465 extern void APIENTRY glGetSeparableFilter(GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
	01466 extern void APIENTRY glSeparableFilter2D(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
	01467 extern void APIENTRY glGetHistogram(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	01468 extern void APIENTRY glGetHistogramParameterfv(GLenum, GLenum, GLfloat*);
	01469 extern void APIENTRY glGetHistogramParameteriv(GLenum, GLenum, GLint*);
	01470 extern void APIENTRY glGetMinmax(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	01471 extern void APIENTRY glGetMinmaxParameterfv(GLenum, GLenum, GLfloat*);
	01472 extern void APIENTRY glGetMinmaxParameteriv(GLenum, GLenum, GLint*);
	01473 extern void APIENTRY glHistogram(GLenum, GLsizei, GLenum, GLboolean);
	01474 extern void APIENTRY glMinmax(GLenum, GLenum, GLboolean);
	01475 extern void APIENTRY glResetHistogram(GLenum);
	01476 extern void APIENTRY glResetMinmax(GLenum);
	01477 extern void APIENTRY glTexImage3D(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	01478 extern void APIENTRY glTexSubImage3D(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01479 extern void APIENTRY glCopyTexSubImage3D(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	01480 #endif /* GL_GLEXT_PROTOTYPES */
		01481 typedef void (APIENTRY* PFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	01482 typedef void (APIENTRY* PFNGLBLENDEQUATIONPROC) (GLenum mode);
	01483 typedef void (APIENTRY* PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
	01484 typedef void (APIENTRY* PFNGLCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
	01485 typedef void (APIENTRY* PFNGLCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat* params);
	01486 typedef void (APIENTRY* PFNGLCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint* params);
	01487 typedef void (APIENTRY* PFNGLCOPYCOLORTABLEPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	01488 typedef void (APIENTRY* PFNGLGETCOLORTABLEPROC) (GLenum target, GLenum format, GLenum type, GLvoid* table);
	01489 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat* params);
	01490 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
	01491 typedef void (APIENTRY* PFNGLCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data);
	01492 typedef void (APIENTRY* PFNGLCOPYCOLORSUBTABLEPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	01493 typedef void (APIENTRY* PFNGLCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* image);
	01494 typedef void (APIENTRY* PFNGLCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image);
	01495 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat params);
	01496 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat* params);
	01497 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERIPROC) (GLenum target, GLenum pname, GLint params);
	01498 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint* params);
	01499 typedef void (APIENTRY* PFNGLCOPYCONVOLUTIONFILTER1DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	01500 typedef void (APIENTRY* PFNGLCOPYCONVOLUTIONFILTER2DPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	01501 typedef void (APIENTRY* PFNGLGETCONVOLUTIONFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid* image);
	01502 typedef void (APIENTRY* PFNGLGETCONVOLUTIONPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat* params);
	01503 typedef void (APIENTRY* PFNGLGETCONVOLUTIONPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
	01504 typedef void (APIENTRY* PFNGLGETSEPARABLEFILTERPROC) (GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
	01505 typedef void (APIENTRY* PFNGLSEPARABLEFILTER2DPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column);
	01506 typedef void (APIENTRY* PFNGLGETHISTOGRAMPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
	01507 typedef void (APIENTRY* PFNGLGETHISTOGRAMPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat* params);
	01508 typedef void (APIENTRY* PFNGLGETHISTOGRAMPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
	01509 typedef void (APIENTRY* PFNGLGETMINMAXPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
	01510 typedef void (APIENTRY* PFNGLGETMINMAXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat* params);
	01511 typedef void (APIENTRY* PFNGLGETMINMAXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
	01512 typedef void (APIENTRY* PFNGLHISTOGRAMPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	01513 typedef void (APIENTRY* PFNGLMINMAXPROC) (GLenum target, GLenum internalformat, GLboolean sink);
	01514 typedef void (APIENTRY* PFNGLRESETHISTOGRAMPROC) (GLenum target);
	01515 typedef void (APIENTRY* PFNGLRESETMINMAXPROC) (GLenum target);
	01516 typedef void (APIENTRY* PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
	01517 typedef void (APIENTRY* PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
	01518 typedef void (APIENTRY* PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	01519 #endif
		01520
		01521 #ifndef GL_ARB_multitexture
		01522 #define GL_ARB_multitexture 1
		01523 #ifdef GL_GLEXT_PROTOTYPES
		01524 extern void APIENTRY glActiveTextureARB(GLenum);
	01525 extern void APIENTRY glClientActiveTextureARB(GLenum);
	01526 extern void APIENTRY glMultiTexCoord1dARB(GLenum, GLdouble);
	01527 extern void APIENTRY glMultiTexCoord1dvARB(GLenum, const GLdouble*);
	01528 extern void APIENTRY glMultiTexCoord1fARB(GLenum, GLfloat);
	01529 extern void APIENTRY glMultiTexCoord1fvARB(GLenum, const GLfloat*);
	01530 extern void APIENTRY glMultiTexCoord1iARB(GLenum, GLint);
	01531 extern void APIENTRY glMultiTexCoord1ivARB(GLenum, const GLint*);
	01532 extern void APIENTRY glMultiTexCoord1sARB(GLenum, GLshort);
	01533 extern void APIENTRY glMultiTexCoord1svARB(GLenum, const GLshort*);
	01534 extern void APIENTRY glMultiTexCoord2dARB(GLenum, GLdouble, GLdouble);
	01535 extern void APIENTRY glMultiTexCoord2dvARB(GLenum, const GLdouble*);
	01536 extern void APIENTRY glMultiTexCoord2fARB(GLenum, GLfloat, GLfloat);
	01537 extern void APIENTRY glMultiTexCoord2fvARB(GLenum, const GLfloat*);
	01538 extern void APIENTRY glMultiTexCoord2iARB(GLenum, GLint, GLint);
	01539 extern void APIENTRY glMultiTexCoord2ivARB(GLenum, const GLint*);
	01540 extern void APIENTRY glMultiTexCoord2sARB(GLenum, GLshort, GLshort);
	01541 extern void APIENTRY glMultiTexCoord2svARB(GLenum, const GLshort*);
	01542 extern void APIENTRY glMultiTexCoord3dARB(GLenum, GLdouble, GLdouble, GLdouble);
	01543 extern void APIENTRY glMultiTexCoord3dvARB(GLenum, const GLdouble*);
	01544 extern void APIENTRY glMultiTexCoord3fARB(GLenum, GLfloat, GLfloat, GLfloat);
	01545 extern void APIENTRY glMultiTexCoord3fvARB(GLenum, const GLfloat*);
	01546 extern void APIENTRY glMultiTexCoord3iARB(GLenum, GLint, GLint, GLint);
	01547 extern void APIENTRY glMultiTexCoord3ivARB(GLenum, const GLint*);
	01548 extern void APIENTRY glMultiTexCoord3sARB(GLenum, GLshort, GLshort, GLshort);
	01549 extern void APIENTRY glMultiTexCoord3svARB(GLenum, const GLshort*);
	01550 extern void APIENTRY glMultiTexCoord4dARB(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
	01551 extern void APIENTRY glMultiTexCoord4dvARB(GLenum, const GLdouble*);
	01552 extern void APIENTRY glMultiTexCoord4fARB(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
	01553 extern void APIENTRY glMultiTexCoord4fvARB(GLenum, const GLfloat*);
	01554 extern void APIENTRY glMultiTexCoord4iARB(GLenum, GLint, GLint, GLint, GLint);
	01555 extern void APIENTRY glMultiTexCoord4ivARB(GLenum, const GLint*);
	01556 extern void APIENTRY glMultiTexCoord4sARB(GLenum, GLshort, GLshort, GLshort, GLshort);
	01557 extern void APIENTRY glMultiTexCoord4svARB(GLenum, const GLshort*);
	01558 #endif /* GL_GLEXT_PROTOTYPES */
		01559 typedef void (APIENTRY* PFNGLACTIVETEXTUREARBPROC) (GLenum texture);
	01560 typedef void (APIENTRY* PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum texture);
	01561 typedef void (APIENTRY* PFNGLMULTITEXCOORD1DARBPROC) (GLenum target, GLdouble s);
	01562 typedef void (APIENTRY* PFNGLMULTITEXCOORD1DVARBPROC) (GLenum target, const GLdouble* v);
	01563 typedef void (APIENTRY* PFNGLMULTITEXCOORD1FARBPROC) (GLenum target, GLfloat s);
	01564 typedef void (APIENTRY* PFNGLMULTITEXCOORD1FVARBPROC) (GLenum target, const GLfloat* v);
	01565 typedef void (APIENTRY* PFNGLMULTITEXCOORD1IARBPROC) (GLenum target, GLint s);
	01566 typedef void (APIENTRY* PFNGLMULTITEXCOORD1IVARBPROC) (GLenum target, const GLint* v);
	01567 typedef void (APIENTRY* PFNGLMULTITEXCOORD1SARBPROC) (GLenum target, GLshort s);
	01568 typedef void (APIENTRY* PFNGLMULTITEXCOORD1SVARBPROC) (GLenum target, const GLshort* v);
	01569 typedef void (APIENTRY* PFNGLMULTITEXCOORD2DARBPROC) (GLenum target, GLdouble s, GLdouble t);
	01570 typedef void (APIENTRY* PFNGLMULTITEXCOORD2DVARBPROC) (GLenum target, const GLdouble* v);
	01571 typedef void (APIENTRY* PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
	01572 typedef void (APIENTRY* PFNGLMULTITEXCOORD2FVARBPROC) (GLenum target, const GLfloat* v);
	01573 typedef void (APIENTRY* PFNGLMULTITEXCOORD2IARBPROC) (GLenum target, GLint s, GLint t);
	01574 typedef void (APIENTRY* PFNGLMULTITEXCOORD2IVARBPROC) (GLenum target, const GLint* v);
	01575 typedef void (APIENTRY* PFNGLMULTITEXCOORD2SARBPROC) (GLenum target, GLshort s, GLshort t);
	01576 typedef void (APIENTRY* PFNGLMULTITEXCOORD2SVARBPROC) (GLenum target, const GLshort* v);
	01577 typedef void (APIENTRY* PFNGLMULTITEXCOORD3DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
	01578 typedef void (APIENTRY* PFNGLMULTITEXCOORD3DVARBPROC) (GLenum target, const GLdouble* v);
	01579 typedef void (APIENTRY* PFNGLMULTITEXCOORD3FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
	01580 typedef void (APIENTRY* PFNGLMULTITEXCOORD3FVARBPROC) (GLenum target, const GLfloat* v);
	01581 typedef void (APIENTRY* PFNGLMULTITEXCOORD3IARBPROC) (GLenum target, GLint s, GLint t, GLint r);
	01582 typedef void (APIENTRY* PFNGLMULTITEXCOORD3IVARBPROC) (GLenum target, const GLint* v);
	01583 typedef void (APIENTRY* PFNGLMULTITEXCOORD3SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
	01584 typedef void (APIENTRY* PFNGLMULTITEXCOORD3SVARBPROC) (GLenum target, const GLshort* v);
	01585 typedef void (APIENTRY* PFNGLMULTITEXCOORD4DARBPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	01586 typedef void (APIENTRY* PFNGLMULTITEXCOORD4DVARBPROC) (GLenum target, const GLdouble* v);
	01587 typedef void (APIENTRY* PFNGLMULTITEXCOORD4FARBPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	01588 typedef void (APIENTRY* PFNGLMULTITEXCOORD4FVARBPROC) (GLenum target, const GLfloat* v);
	01589 typedef void (APIENTRY* PFNGLMULTITEXCOORD4IARBPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
	01590 typedef void (APIENTRY* PFNGLMULTITEXCOORD4IVARBPROC) (GLenum target, const GLint* v);
	01591 typedef void (APIENTRY* PFNGLMULTITEXCOORD4SARBPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	01592 typedef void (APIENTRY* PFNGLMULTITEXCOORD4SVARBPROC) (GLenum target, const GLshort* v);
	01593 #endif
		01594
		01595 #ifndef GL_ARB_transpose_matrix
		01596 #define GL_ARB_transpose_matrix 1
		01597 #ifdef GL_GLEXT_PROTOTYPES
		01598 extern void APIENTRY glLoadTransposeMatrixfARB(const GLfloat*);
	01599 extern void APIENTRY glLoadTransposeMatrixdARB(const GLdouble*);
	01600 extern void APIENTRY glMultTransposeMatrixfARB(const GLfloat*);
	01601 extern void APIENTRY glMultTransposeMatrixdARB(const GLdouble*);
	01602 #endif /* GL_GLEXT_PROTOTYPES */
		01603 typedef void (APIENTRY* PFNGLLOADTRANSPOSEMATRIXFARBPROC) (const GLfloat* m);
	01604 typedef void (APIENTRY* PFNGLLOADTRANSPOSEMATRIXDARBPROC) (const GLdouble* m);
	01605 typedef void (APIENTRY* PFNGLMULTTRANSPOSEMATRIXFARBPROC) (const GLfloat* m);
	01606 typedef void (APIENTRY* PFNGLMULTTRANSPOSEMATRIXDARBPROC) (const GLdouble* m);
	01607 #endif
		01608
		01609 #ifndef GL_ARB_multisample
		01610 #define GL_ARB_multisample 1
		01611 #ifdef GL_GLEXT_PROTOTYPES
		01612 extern void APIENTRY glSampleCoverageARB(GLclampf, GLboolean);
	01613 extern void APIENTRY glSamplePassARB(GLenum);
	01614 #endif /* GL_GLEXT_PROTOTYPES */
		01615 typedef void (APIENTRY* PFNGLSAMPLECOVERAGEARBPROC) (GLclampf value, GLboolean invert);
	01616 typedef void (APIENTRY* PFNGLSAMPLEPASSARBPROC) (GLenum pass);
	01617 #endif
		01618
		01619 #ifndef GL_ARB_texture_env_add
		01620 #define GL_ARB_texture_env_add 1
		01621 #endif
		01622
		01623 #ifndef GL_ARB_texture_cube_map
		01624 #define GL_ARB_texture_cube_map 1
		01625 #endif
		01626
		01627 #ifndef GL_ARB_texture_compression
		01628 #define GL_ARB_texture_compression 1
		01629 #ifdef GL_GLEXT_PROTOTYPES
		01630 extern void APIENTRY glCompressedTexImage3DARB(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
	01631 extern void APIENTRY glCompressedTexImage2DARB(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid*);
	01632 extern void APIENTRY glCompressedTexImage1DARB(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid*);
	01633 extern void APIENTRY glCompressedTexSubImage3DARB(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
	01634 extern void APIENTRY glCompressedTexSubImage2DARB(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid*);
	01635 extern void APIENTRY glCompressedTexSubImage1DARB(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid*);
	01636 extern void APIENTRY glGetCompressedTexImageARB(GLenum, GLint, void*);
	01637 #endif /* GL_GLEXT_PROTOTYPES */
		01638 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid* data);
	01639 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
	01640 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid* data);
	01641 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid* data);
	01642 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
	01643 typedef void (APIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid* data);
	01644 typedef void (APIENTRY* PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint level, void* img);
	01645 #endif
		01646
		01647 #ifndef GL_EXT_abgr
		01648 #define GL_EXT_abgr 1
		01649 #endif
		01650
		01651 #ifndef GL_EXT_blend_color
		01652 #define GL_EXT_blend_color 1
		01653 #ifdef GL_GLEXT_PROTOTYPES
		01654 extern void APIENTRY glBlendColorEXT(GLclampf, GLclampf, GLclampf, GLclampf);
	01655 #endif /* GL_GLEXT_PROTOTYPES */
		01656 typedef void (APIENTRY* PFNGLBLENDCOLOREXTPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	01657 #endif
		01658
		01659 #ifndef GL_EXT_polygon_offset
		01660 #define GL_EXT_polygon_offset 1
		01661 #ifdef GL_GLEXT_PROTOTYPES
		01662 extern void APIENTRY glPolygonOffsetEXT(GLfloat, GLfloat);
	01663 #endif /* GL_GLEXT_PROTOTYPES */
		01664 typedef void (APIENTRY* PFNGLPOLYGONOFFSETEXTPROC) (GLfloat factor, GLfloat bias);
	01665 #endif
		01666
		01667 #ifndef GL_EXT_texture
		01668 #define GL_EXT_texture 1
		01669 #endif
		01670
		01671 #ifndef GL_EXT_texture3D
		01672 #define GL_EXT_texture3D 1
		01673 #ifdef GL_GLEXT_PROTOTYPES
		01674 extern void APIENTRY glTexImage3DEXT(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	01675 extern void APIENTRY glTexSubImage3DEXT(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01676 #endif /* GL_GLEXT_PROTOTYPES */
		01677 typedef void (APIENTRY* PFNGLTEXIMAGE3DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
	01678 typedef void (APIENTRY* PFNGLTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* pixels);
	01679 #endif
		01680
		01681 #ifndef GL_SGIS_texture_filter4
		01682 #define GL_SGIS_texture_filter4 1
		01683 #ifdef GL_GLEXT_PROTOTYPES
		01684 extern void APIENTRY glGetTexFilterFuncSGIS(GLenum, GLenum, GLfloat*);
	01685 extern void APIENTRY glTexFilterFuncSGIS(GLenum, GLenum, GLsizei, const GLfloat*);
	01686 #endif /* GL_GLEXT_PROTOTYPES */
		01687 typedef void (APIENTRY* PFNGLGETTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLfloat* weights);
	01688 typedef void (APIENTRY* PFNGLTEXFILTERFUNCSGISPROC) (GLenum target, GLenum filter, GLsizei n, const GLfloat* weights);
	01689 #endif
		01690
		01691 #ifndef GL_EXT_subtexture
		01692 #define GL_EXT_subtexture 1
		01693 #ifdef GL_GLEXT_PROTOTYPES
		01694 extern void APIENTRY glTexSubImage1DEXT(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
	01695 extern void APIENTRY glTexSubImage2DEXT(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01696 #endif /* GL_GLEXT_PROTOTYPES */
		01697 typedef void (APIENTRY* PFNGLTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid* pixels);
	01698 typedef void (APIENTRY* PFNGLTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
	01699 #endif
		01700
		01701 #ifndef GL_EXT_copy_texture
		01702 #define GL_EXT_copy_texture 1
		01703 #ifdef GL_GLEXT_PROTOTYPES
		01704 extern void APIENTRY glCopyTexImage1DEXT(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	01705 extern void APIENTRY glCopyTexImage2DEXT(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	01706 extern void APIENTRY glCopyTexSubImage1DEXT(GLenum, GLint, GLint, GLint, GLint, GLsizei);
	01707 extern void APIENTRY glCopyTexSubImage2DEXT(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	01708 extern void APIENTRY glCopyTexSubImage3DEXT(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	01709 #endif /* GL_GLEXT_PROTOTYPES */
		01710 typedef void (APIENTRY* PFNGLCOPYTEXIMAGE1DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	01711 typedef void (APIENTRY* PFNGLCOPYTEXIMAGE2DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	01712 typedef void (APIENTRY* PFNGLCOPYTEXSUBIMAGE1DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	01713 typedef void (APIENTRY* PFNGLCOPYTEXSUBIMAGE2DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	01714 typedef void (APIENTRY* PFNGLCOPYTEXSUBIMAGE3DEXTPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	01715 #endif
		01716
		01717 #ifndef GL_EXT_histogram
		01718 #define GL_EXT_histogram 1
		01719 #ifdef GL_GLEXT_PROTOTYPES
		01720 extern void APIENTRY glGetHistogramEXT(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	01721 extern void APIENTRY glGetHistogramParameterfvEXT(GLenum, GLenum, GLfloat*);
	01722 extern void APIENTRY glGetHistogramParameterivEXT(GLenum, GLenum, GLint*);
	01723 extern void APIENTRY glGetMinmaxEXT(GLenum, GLboolean, GLenum, GLenum, GLvoid*);
	01724 extern void APIENTRY glGetMinmaxParameterfvEXT(GLenum, GLenum, GLfloat*);
	01725 extern void APIENTRY glGetMinmaxParameterivEXT(GLenum, GLenum, GLint*);
	01726 extern void APIENTRY glHistogramEXT(GLenum, GLsizei, GLenum, GLboolean);
	01727 extern void APIENTRY glMinmaxEXT(GLenum, GLenum, GLboolean);
	01728 extern void APIENTRY glResetHistogramEXT(GLenum);
	01729 extern void APIENTRY glResetMinmaxEXT(GLenum);
	01730 #endif /* GL_GLEXT_PROTOTYPES */
		01731 typedef void (APIENTRY* PFNGLGETHISTOGRAMEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
	01732 typedef void (APIENTRY* PFNGLGETHISTOGRAMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat* params);
	01733 typedef void (APIENTRY* PFNGLGETHISTOGRAMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint* params);
	01734 typedef void (APIENTRY* PFNGLGETMINMAXEXTPROC) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid* values);
	01735 typedef void (APIENTRY* PFNGLGETMINMAXPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat* params);
	01736 typedef void (APIENTRY* PFNGLGETMINMAXPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint* params);
	01737 typedef void (APIENTRY* PFNGLHISTOGRAMEXTPROC) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	01738 typedef void (APIENTRY* PFNGLMINMAXEXTPROC) (GLenum target, GLenum internalformat, GLboolean sink);
	01739 typedef void (APIENTRY* PFNGLRESETHISTOGRAMEXTPROC) (GLenum target);
	01740 typedef void (APIENTRY* PFNGLRESETMINMAXEXTPROC) (GLenum target);
	01741 #endif
		01742
		01743 #ifndef GL_EXT_convolution
		01744 #define GL_EXT_convolution 1
		01745 #ifdef GL_GLEXT_PROTOTYPES
		01746 extern void APIENTRY glConvolutionFilter1DEXT(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	01747 extern void APIENTRY glConvolutionFilter2DEXT(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01748 extern void APIENTRY glConvolutionParameterfEXT(GLenum, GLenum, GLfloat);
	01749 extern void APIENTRY glConvolutionParameterfvEXT(GLenum, GLenum, const GLfloat*);
	01750 extern void APIENTRY glConvolutionParameteriEXT(GLenum, GLenum, GLint);
	01751 extern void APIENTRY glConvolutionParameterivEXT(GLenum, GLenum, const GLint*);
	01752 extern void APIENTRY glCopyConvolutionFilter1DEXT(GLenum, GLenum, GLint, GLint, GLsizei);
	01753 extern void APIENTRY glCopyConvolutionFilter2DEXT(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
	01754 extern void APIENTRY glGetConvolutionFilterEXT(GLenum, GLenum, GLenum, GLvoid*);
	01755 extern void APIENTRY glGetConvolutionParameterfvEXT(GLenum, GLenum, GLfloat*);
	01756 extern void APIENTRY glGetConvolutionParameterivEXT(GLenum, GLenum, GLint*);
	01757 extern void APIENTRY glGetSeparableFilterEXT(GLenum, GLenum, GLenum, GLvoid*, GLvoid*, GLvoid*);
	01758 extern void APIENTRY glSeparableFilter2DEXT(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*, const GLvoid*);
	01759 #endif /* GL_GLEXT_PROTOTYPES */
		01760 typedef void (APIENTRY* PFNGLCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* image);
	01761 typedef void (APIENTRY* PFNGLCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* image);
	01762 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat params);
	01763 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat* params);
	01764 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint params);
	01765 typedef void (APIENTRY* PFNGLCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint* params);
	01766 typedef void (APIENTRY* PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	01767 typedef void (APIENTRY* PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	01768 typedef void (APIENTRY* PFNGLGETCONVOLUTIONFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid* image);
	01769 typedef void (APIENTRY* PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat* params);
	01770 typedef void (APIENTRY* PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint* params);
	01771 typedef void (APIENTRY* PFNGLGETSEPARABLEFILTEREXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid* row, GLvoid* column, GLvoid* span);
	01772 typedef void (APIENTRY* PFNGLSEPARABLEFILTER2DEXTPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* row, const GLvoid* column);
	01773 #endif
		01774
		01775 #ifndef GL_EXT_color_matrix
		01776 #define GL_EXT_color_matrix 1
		01777 #endif
		01778
		01779 #ifndef GL_SGI_color_table
		01780 #define GL_SGI_color_table 1
		01781 #ifdef GL_GLEXT_PROTOTYPES
		01782 extern void APIENTRY glColorTableSGI(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	01783 extern void APIENTRY glColorTableParameterfvSGI(GLenum, GLenum, const GLfloat*);
	01784 extern void APIENTRY glColorTableParameterivSGI(GLenum, GLenum, const GLint*);
	01785 extern void APIENTRY glCopyColorTableSGI(GLenum, GLenum, GLint, GLint, GLsizei);
	01786 extern void APIENTRY glGetColorTableSGI(GLenum, GLenum, GLenum, GLvoid*);
	01787 extern void APIENTRY glGetColorTableParameterfvSGI(GLenum, GLenum, GLfloat*);
	01788 extern void APIENTRY glGetColorTableParameterivSGI(GLenum, GLenum, GLint*);
	01789 #endif /* GL_GLEXT_PROTOTYPES */
		01790 typedef void (APIENTRY* PFNGLCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
	01791 typedef void (APIENTRY* PFNGLCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, const GLfloat* params);
	01792 typedef void (APIENTRY* PFNGLCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, const GLint* params);
	01793 typedef void (APIENTRY* PFNGLCOPYCOLORTABLESGIPROC) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	01794 typedef void (APIENTRY* PFNGLGETCOLORTABLESGIPROC) (GLenum target, GLenum format, GLenum type, GLvoid* table);
	01795 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERFVSGIPROC) (GLenum target, GLenum pname, GLfloat* params);
	01796 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERIVSGIPROC) (GLenum target, GLenum pname, GLint* params);
	01797 #endif
		01798
		01799 #ifndef GL_SGIX_pixel_texture
		01800 #define GL_SGIX_pixel_texture 1
		01801 #ifdef GL_GLEXT_PROTOTYPES
		01802 extern void APIENTRY glPixelTexGenSGIX(GLenum);
	01803 #endif /* GL_GLEXT_PROTOTYPES */
		01804 typedef void (APIENTRY* PFNGLPIXELTEXGENSGIXPROC) (GLenum mode);
	01805 #endif
		01806
		01807 #ifndef GL_SGIS_pixel_texture
		01808 #define GL_SGIS_pixel_texture 1
		01809 #ifdef GL_GLEXT_PROTOTYPES
		01810 extern void APIENTRY glPixelTexGenParameteriSGIS(GLenum, GLint);
	01811 extern void APIENTRY glPixelTexGenParameterivSGIS(GLenum, const GLint*);
	01812 extern void APIENTRY glPixelTexGenParameterfSGIS(GLenum, GLfloat);
	01813 extern void APIENTRY glPixelTexGenParameterfvSGIS(GLenum, const GLfloat*);
	01814 extern void APIENTRY glGetPixelTexGenParameterivSGIS(GLenum, GLint*);
	01815 extern void APIENTRY glGetPixelTexGenParameterfvSGIS(GLenum, GLfloat*);
	01816 #endif /* GL_GLEXT_PROTOTYPES */
		01817 typedef void (APIENTRY* PFNGLPIXELTEXGENPARAMETERISGISPROC) (GLenum pname, GLint param);
	01818 typedef void (APIENTRY* PFNGLPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, const GLint* params);
	01819 typedef void (APIENTRY* PFNGLPIXELTEXGENPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
	01820 typedef void (APIENTRY* PFNGLPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, const GLfloat* params);
	01821 typedef void (APIENTRY* PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC) (GLenum pname, GLint* params);
	01822 typedef void (APIENTRY* PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC) (GLenum pname, GLfloat* params);
	01823 #endif
		01824
		01825 #ifndef GL_SGIS_texture4D
		01826 #define GL_SGIS_texture4D 1
		01827 #ifdef GL_GLEXT_PROTOTYPES
		01828 extern void APIENTRY glTexImage4DSGIS(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	01829 extern void APIENTRY glTexSubImage4DSGIS(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	01830 #endif /* GL_GLEXT_PROTOTYPES */
		01831 typedef void (APIENTRY* PFNGLTEXIMAGE4DSGISPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
	01832 typedef void (APIENTRY* PFNGLTEXSUBIMAGE4DSGISPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid* pixels);
	01833 #endif
		01834
		01835 #ifndef GL_SGI_texture_color_table
		01836 #define GL_SGI_texture_color_table 1
		01837 #endif
		01838
		01839 #ifndef GL_EXT_cmyka
		01840 #define GL_EXT_cmyka 1
		01841 #endif
		01842
		01843 #ifndef GL_EXT_texture_object
		01844 #define GL_EXT_texture_object 1
		01845 #ifdef GL_GLEXT_PROTOTYPES
		01846 extern GLboolean APIENTRY glAreTexturesResidentEXT(GLsizei, const GLuint*, GLboolean*);
	01847 extern void APIENTRY glBindTextureEXT(GLenum, GLuint);
	01848 extern void APIENTRY glDeleteTexturesEXT(GLsizei, const GLuint*);
	01849 extern void APIENTRY glGenTexturesEXT(GLsizei, GLuint*);
	01850 extern GLboolean APIENTRY glIsTextureEXT(GLuint);
	01851 extern void APIENTRY glPrioritizeTexturesEXT(GLsizei, const GLuint*, const GLclampf*);
	01852 #endif /* GL_GLEXT_PROTOTYPES */
		01853 typedef GLboolean(APIENTRY* PFNGLARETEXTURESRESIDENTEXTPROC) (GLsizei n, const GLuint* textures, GLboolean* residences);
	01854 typedef void (APIENTRY* PFNGLBINDTEXTUREEXTPROC) (GLenum target, GLuint texture);
	01855 typedef void (APIENTRY* PFNGLDELETETEXTURESEXTPROC) (GLsizei n, const GLuint* textures);
	01856 typedef void (APIENTRY* PFNGLGENTEXTURESEXTPROC) (GLsizei n, GLuint* textures);
	01857 typedef GLboolean(APIENTRY* PFNGLISTEXTUREEXTPROC) (GLuint texture);
	01858 typedef void (APIENTRY* PFNGLPRIORITIZETEXTURESEXTPROC) (GLsizei n, const GLuint* textures, const GLclampf* priorities);
	01859 #endif
		01860
		01861 #ifndef GL_SGIS_detail_texture
		01862 #define GL_SGIS_detail_texture 1
		01863 #ifdef GL_GLEXT_PROTOTYPES
		01864 extern void APIENTRY glDetailTexFuncSGIS(GLenum, GLsizei, const GLfloat*);
	01865 extern void APIENTRY glGetDetailTexFuncSGIS(GLenum, GLfloat*);
	01866 #endif /* GL_GLEXT_PROTOTYPES */
		01867 typedef void (APIENTRY* PFNGLDETAILTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat* points);
	01868 typedef void (APIENTRY* PFNGLGETDETAILTEXFUNCSGISPROC) (GLenum target, GLfloat* points);
	01869 #endif
		01870
		01871 #ifndef GL_SGIS_sharpen_texture
		01872 #define GL_SGIS_sharpen_texture 1
		01873 #ifdef GL_GLEXT_PROTOTYPES
		01874 extern void APIENTRY glSharpenTexFuncSGIS(GLenum, GLsizei, const GLfloat*);
	01875 extern void APIENTRY glGetSharpenTexFuncSGIS(GLenum, GLfloat*);
	01876 #endif /* GL_GLEXT_PROTOTYPES */
		01877 typedef void (APIENTRY* PFNGLSHARPENTEXFUNCSGISPROC) (GLenum target, GLsizei n, const GLfloat* points);
	01878 typedef void (APIENTRY* PFNGLGETSHARPENTEXFUNCSGISPROC) (GLenum target, GLfloat* points);
	01879 #endif
		01880
		01881 #ifndef GL_EXT_packed_pixels
		01882 #define GL_EXT_packed_pixels 1
		01883 #endif
		01884
		01885 #ifndef GL_SGIS_texture_lod
		01886 #define GL_SGIS_texture_lod 1
		01887 #endif
		01888
		01889 #ifndef GL_SGIS_multisample
		01890 #define GL_SGIS_multisample 1
		01891 #ifdef GL_GLEXT_PROTOTYPES
		01892 extern void APIENTRY glSampleMaskSGIS(GLclampf, GLboolean);
	01893 extern void APIENTRY glSamplePatternSGIS(GLenum);
	01894 #endif /* GL_GLEXT_PROTOTYPES */
		01895 typedef void (APIENTRY* PFNGLSAMPLEMASKSGISPROC) (GLclampf value, GLboolean invert);
	01896 typedef void (APIENTRY* PFNGLSAMPLEPATTERNSGISPROC) (GLenum pattern);
	01897 #endif
		01898
		01899 #ifndef GL_EXT_rescale_normal
		01900 #define GL_EXT_rescale_normal 1
		01901 #endif
		01902
		01903 #ifndef GL_EXT_vertex_array
		01904 #define GL_EXT_vertex_array 1
		01905 #ifdef GL_GLEXT_PROTOTYPES
		01906 extern void APIENTRY glArrayElementEXT(GLint);
	01907 extern void APIENTRY glColorPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
	01908 extern void APIENTRY glDrawArraysEXT(GLenum, GLint, GLsizei);
	01909 extern void APIENTRY glEdgeFlagPointerEXT(GLsizei, GLsizei, const GLboolean*);
	01910 extern void APIENTRY glGetPointervEXT(GLenum, GLvoid**);
	01911 extern void APIENTRY glIndexPointerEXT(GLenum, GLsizei, GLsizei, const GLvoid*);
	01912 extern void APIENTRY glNormalPointerEXT(GLenum, GLsizei, GLsizei, const GLvoid*);
	01913 extern void APIENTRY glTexCoordPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
	01914 extern void APIENTRY glVertexPointerEXT(GLint, GLenum, GLsizei, GLsizei, const GLvoid*);
	01915 #endif /* GL_GLEXT_PROTOTYPES */
		01916 typedef void (APIENTRY* PFNGLARRAYELEMENTEXTPROC) (GLint i);
	01917 typedef void (APIENTRY* PFNGLCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
	01918 typedef void (APIENTRY* PFNGLDRAWARRAYSEXTPROC) (GLenum mode, GLint first, GLsizei count);
	01919 typedef void (APIENTRY* PFNGLEDGEFLAGPOINTEREXTPROC) (GLsizei stride, GLsizei count, const GLboolean* pointer);
	01920 typedef void (APIENTRY* PFNGLGETPOINTERVEXTPROC) (GLenum pname, GLvoid** params);
	01921 typedef void (APIENTRY* PFNGLINDEXPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
	01922 typedef void (APIENTRY* PFNGLNORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
	01923 typedef void (APIENTRY* PFNGLTEXCOORDPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
	01924 typedef void (APIENTRY* PFNGLVERTEXPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid* pointer);
	01925 #endif
		01926
		01927 #ifndef GL_EXT_misc_attribute
		01928 #define GL_EXT_misc_attribute 1
		01929 #endif
		01930
		01931 #ifndef GL_SGIS_generate_mipmap
		01932 #define GL_SGIS_generate_mipmap 1
		01933 #endif
		01934
		01935 #ifndef GL_SGIX_clipmap
		01936 #define GL_SGIX_clipmap 1
		01937 #endif
		01938
		01939 #ifndef GL_SGIX_shadow
		01940 #define GL_SGIX_shadow 1
		01941 #endif
		01942
		01943 #ifndef GL_SGIS_texture_edge_clamp
		01944 #define GL_SGIS_texture_edge_clamp 1
		01945 #endif
		01946
		01947 #ifndef GL_SGIS_texture_border_clamp
		01948 #define GL_SGIS_texture_border_clamp 1
		01949 #endif
		01950
		01951 #ifndef GL_EXT_blend_minmax
		01952 #define GL_EXT_blend_minmax 1
		01953 #ifdef GL_GLEXT_PROTOTYPES
		01954 extern void APIENTRY glBlendEquationEXT(GLenum);
	01955 #endif /* GL_GLEXT_PROTOTYPES */
		01956 typedef void (APIENTRY* PFNGLBLENDEQUATIONEXTPROC) (GLenum mode);
	01957 #endif
		01958
		01959 #ifndef GL_EXT_blend_subtract
		01960 #define GL_EXT_blend_subtract 1
		01961 #endif
		01962
		01963 #ifndef GL_EXT_blend_logic_op
		01964 #define GL_EXT_blend_logic_op 1
		01965 #endif
		01966
		01967 #ifndef GL_SGIX_interlace
		01968 #define GL_SGIX_interlace 1
		01969 #endif
		01970
		01971 #ifndef GL_SGIX_pixel_tiles
		01972 #define GL_SGIX_pixel_tiles 1
		01973 #endif
		01974
		01975 #ifndef GL_SGIX_texture_select
		01976 #define GL_SGIX_texture_select 1
		01977 #endif
		01978
		01979 #ifndef GL_SGIX_sprite
		01980 #define GL_SGIX_sprite 1
		01981 #ifdef GL_GLEXT_PROTOTYPES
		01982 extern void APIENTRY glSpriteParameterfSGIX(GLenum, GLfloat);
	01983 extern void APIENTRY glSpriteParameterfvSGIX(GLenum, const GLfloat*);
	01984 extern void APIENTRY glSpriteParameteriSGIX(GLenum, GLint);
	01985 extern void APIENTRY glSpriteParameterivSGIX(GLenum, const GLint*);
	01986 #endif /* GL_GLEXT_PROTOTYPES */
		01987 typedef void (APIENTRY* PFNGLSPRITEPARAMETERFSGIXPROC) (GLenum pname, GLfloat param);
	01988 typedef void (APIENTRY* PFNGLSPRITEPARAMETERFVSGIXPROC) (GLenum pname, const GLfloat* params);
	01989 typedef void (APIENTRY* PFNGLSPRITEPARAMETERISGIXPROC) (GLenum pname, GLint param);
	01990 typedef void (APIENTRY* PFNGLSPRITEPARAMETERIVSGIXPROC) (GLenum pname, const GLint* params);
	01991 #endif
		01992
		01993 #ifndef GL_SGIX_texture_multi_buffer
		01994 #define GL_SGIX_texture_multi_buffer 1
		01995 #endif
		01996
		01997 #ifndef GL_EXT_point_parameters
		01998 #define GL_EXT_point_parameters 1
		01999 #ifdef GL_GLEXT_PROTOTYPES
		02000 extern void APIENTRY glPointParameterfEXT(GLenum, GLfloat);
	02001 extern void APIENTRY glPointParameterfvEXT(GLenum, const GLfloat*);
	02002 extern void APIENTRY glPointParameterfSGIS(GLenum, GLfloat);
	02003 extern void APIENTRY glPointParameterfvSGIS(GLenum, const GLfloat*);
	02004 #endif /* GL_GLEXT_PROTOTYPES */
		02005 typedef void (APIENTRY* PFNGLPOINTPARAMETERFEXTPROC) (GLenum pname, GLfloat param);
	02006 typedef void (APIENTRY* PFNGLPOINTPARAMETERFVEXTPROC) (GLenum pname, const GLfloat* params);
	02007 typedef void (APIENTRY* PFNGLPOINTPARAMETERFSGISPROC) (GLenum pname, GLfloat param);
	02008 typedef void (APIENTRY* PFNGLPOINTPARAMETERFVSGISPROC) (GLenum pname, const GLfloat* params);
	02009 #endif
		02010
		02011 #ifndef GL_SGIX_instruments
		02012 #define GL_SGIX_instruments 1
		02013 #ifdef GL_GLEXT_PROTOTYPES
		02014 extern GLint APIENTRY glGetInstrumentsSGIX(void);
	02015 extern void APIENTRY glInstrumentsBufferSGIX(GLsizei, GLint*);
	02016 extern GLint APIENTRY glPollInstrumentsSGIX(GLint*);
	02017 extern void APIENTRY glReadInstrumentsSGIX(GLint);
	02018 extern void APIENTRY glStartInstrumentsSGIX(void);
	02019 extern void APIENTRY glStopInstrumentsSGIX(GLint);
	02020 #endif /* GL_GLEXT_PROTOTYPES */
		02021 typedef GLint(APIENTRY* PFNGLGETINSTRUMENTSSGIXPROC) (void);
	02022 typedef void (APIENTRY* PFNGLINSTRUMENTSBUFFERSGIXPROC) (GLsizei size, GLint* buffer);
	02023 typedef GLint(APIENTRY* PFNGLPOLLINSTRUMENTSSGIXPROC) (GLint* marker_p);
	02024 typedef void (APIENTRY* PFNGLREADINSTRUMENTSSGIXPROC) (GLint marker);
	02025 typedef void (APIENTRY* PFNGLSTARTINSTRUMENTSSGIXPROC) (void);
	02026 typedef void (APIENTRY* PFNGLSTOPINSTRUMENTSSGIXPROC) (GLint marker);
	02027 #endif
		02028
		02029 #ifndef GL_SGIX_texture_scale_bias
		02030 #define GL_SGIX_texture_scale_bias 1
		02031 #endif
		02032
		02033 #ifndef GL_SGIX_framezoom
		02034 #define GL_SGIX_framezoom 1
		02035 #ifdef GL_GLEXT_PROTOTYPES
		02036 extern void APIENTRY glFrameZoomSGIX(GLint);
	02037 #endif /* GL_GLEXT_PROTOTYPES */
		02038 typedef void (APIENTRY* PFNGLFRAMEZOOMSGIXPROC) (GLint factor);
	02039 #endif
		02040
		02041 #ifndef GL_SGIX_tag_sample_buffer
		02042 #define GL_SGIX_tag_sample_buffer 1
		02043 #ifdef GL_GLEXT_PROTOTYPES
		02044 extern void APIENTRY glTagSampleBufferSGIX(void);
	02045 #endif /* GL_GLEXT_PROTOTYPES */
		02046 typedef void (APIENTRY* PFNGLTAGSAMPLEBUFFERSGIXPROC) (void);
	02047 #endif
		02048
		02049 #ifndef GL_SGIX_reference_plane
		02050 #define GL_SGIX_reference_plane 1
		02051 #ifdef GL_GLEXT_PROTOTYPES
		02052 extern void APIENTRY glReferencePlaneSGIX(const GLdouble*);
	02053 #endif /* GL_GLEXT_PROTOTYPES */
		02054 typedef void (APIENTRY* PFNGLREFERENCEPLANESGIXPROC) (const GLdouble* equation);
	02055 #endif
		02056
		02057 #ifndef GL_SGIX_flush_raster
		02058 #define GL_SGIX_flush_raster 1
		02059 #ifdef GL_GLEXT_PROTOTYPES
		02060 extern void APIENTRY glFlushRasterSGIX(void);
	02061 #endif /* GL_GLEXT_PROTOTYPES */
		02062 typedef void (APIENTRY* PFNGLFLUSHRASTERSGIXPROC) (void);
	02063 #endif
		02064
		02065 #ifndef GL_SGIX_depth_texture
		02066 #define GL_SGIX_depth_texture 1
		02067 #endif
		02068
		02069 #ifndef GL_SGIS_fog_function
		02070 #define GL_SGIS_fog_function 1
		02071 #ifdef GL_GLEXT_PROTOTYPES
		02072 extern void APIENTRY glFogFuncSGIS(GLsizei, const GLfloat*);
	02073 extern void APIENTRY glGetFogFuncSGIS(const GLfloat*);
	02074 #endif /* GL_GLEXT_PROTOTYPES */
		02075 typedef void (APIENTRY* PFNGLFOGFUNCSGISPROC) (GLsizei n, const GLfloat* points);
	02076 typedef void (APIENTRY* PFNGLGETFOGFUNCSGISPROC) (const GLfloat* points);
	02077 #endif
		02078
		02079 #ifndef GL_SGIX_fog_offset
		02080 #define GL_SGIX_fog_offset 1
		02081 #endif
		02082
		02083 #ifndef GL_HP_image_transform
		02084 #define GL_HP_image_transform 1
		02085 #ifdef GL_GLEXT_PROTOTYPES
		02086 extern void APIENTRY glImageTransformParameteriHP(GLenum, GLenum, GLint);
	02087 extern void APIENTRY glImageTransformParameterfHP(GLenum, GLenum, GLfloat);
	02088 extern void APIENTRY glImageTransformParameterivHP(GLenum, GLenum, const GLint*);
	02089 extern void APIENTRY glImageTransformParameterfvHP(GLenum, GLenum, const GLfloat*);
	02090 extern void APIENTRY glGetImageTransformParameterivHP(GLenum, GLenum, GLint*);
	02091 extern void APIENTRY glGetImageTransformParameterfvHP(GLenum, GLenum, GLfloat*);
	02092 #endif /* GL_GLEXT_PROTOTYPES */
		02093 typedef void (APIENTRY* PFNGLIMAGETRANSFORMPARAMETERIHPPROC) (GLenum target, GLenum pname, GLint param);
	02094 typedef void (APIENTRY* PFNGLIMAGETRANSFORMPARAMETERFHPPROC) (GLenum target, GLenum pname, GLfloat param);
	02095 typedef void (APIENTRY* PFNGLIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, const GLint* params);
	02096 typedef void (APIENTRY* PFNGLIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, const GLfloat* params);
	02097 typedef void (APIENTRY* PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC) (GLenum target, GLenum pname, GLint* params);
	02098 typedef void (APIENTRY* PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC) (GLenum target, GLenum pname, GLfloat* params);
	02099 #endif
		02100
		02101 #ifndef GL_HP_convolution_border_modes
		02102 #define GL_HP_convolution_border_modes 1
		02103 #endif
		02104
		02105 #ifndef GL_SGIX_texture_add_env
		02106 #define GL_SGIX_texture_add_env 1
		02107 #endif
		02108
		02109 #ifndef GL_EXT_color_subtable
		02110 #define GL_EXT_color_subtable 1
		02111 #ifdef GL_GLEXT_PROTOTYPES
		02112 extern void APIENTRY glColorSubTableEXT(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	02113 extern void APIENTRY glCopyColorSubTableEXT(GLenum, GLsizei, GLint, GLint, GLsizei);
	02114 #endif /* GL_GLEXT_PROTOTYPES */
		02115 typedef void (APIENTRY* PFNGLCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid* data);
	02116 typedef void (APIENTRY* PFNGLCOPYCOLORSUBTABLEEXTPROC) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	02117 #endif
		02118
		02119 #ifndef GL_PGI_vertex_hints
		02120 #define GL_PGI_vertex_hints 1
		02121 #endif
		02122
		02123 #ifndef GL_PGI_misc_hints
		02124 #define GL_PGI_misc_hints 1
		02125 #ifdef GL_GLEXT_PROTOTYPES
		02126 extern void APIENTRY glHintPGI(GLenum, GLint);
	02127 #endif /* GL_GLEXT_PROTOTYPES */
		02128 typedef void (APIENTRY* PFNGLHINTPGIPROC) (GLenum target, GLint mode);
	02129 #endif
		02130
		02131 #ifndef GL_EXT_paletted_texture
		02132 #define GL_EXT_paletted_texture 1
		02133 #ifdef GL_GLEXT_PROTOTYPES
		02134 extern void APIENTRY glColorTableEXT(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid*);
	02135 extern void APIENTRY glGetColorTableEXT(GLenum, GLenum, GLenum, GLvoid*);
	02136 extern void APIENTRY glGetColorTableParameterivEXT(GLenum, GLenum, GLint*);
	02137 extern void APIENTRY glGetColorTableParameterfvEXT(GLenum, GLenum, GLfloat*);
	02138 #endif /* GL_GLEXT_PROTOTYPES */
		02139 typedef void (APIENTRY* PFNGLCOLORTABLEEXTPROC) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid* table);
	02140 typedef void (APIENTRY* PFNGLGETCOLORTABLEEXTPROC) (GLenum target, GLenum format, GLenum type, GLvoid* data);
	02141 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (GLenum target, GLenum pname, GLint* params);
	02142 typedef void (APIENTRY* PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (GLenum target, GLenum pname, GLfloat* params);
	02143 #endif
		02144
		02145 #ifndef GL_EXT_clip_volume_hint
		02146 #define GL_EXT_clip_volume_hint 1
		02147 #endif
		02148
		02149 #ifndef GL_SGIX_list_priority
		02150 #define GL_SGIX_list_priority 1
		02151 #ifdef GL_GLEXT_PROTOTYPES
		02152 extern void APIENTRY glGetListParameterfvSGIX(GLuint, GLenum, GLfloat*);
	02153 extern void APIENTRY glGetListParameterivSGIX(GLuint, GLenum, GLint*);
	02154 extern void APIENTRY glListParameterfSGIX(GLuint, GLenum, GLfloat);
	02155 extern void APIENTRY glListParameterfvSGIX(GLuint, GLenum, const GLfloat*);
	02156 extern void APIENTRY glListParameteriSGIX(GLuint, GLenum, GLint);
	02157 extern void APIENTRY glListParameterivSGIX(GLuint, GLenum, const GLint*);
	02158 #endif /* GL_GLEXT_PROTOTYPES */
		02159 typedef void (APIENTRY* PFNGLGETLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, GLfloat* params);
	02160 typedef void (APIENTRY* PFNGLGETLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, GLint* params);
	02161 typedef void (APIENTRY* PFNGLLISTPARAMETERFSGIXPROC) (GLuint list, GLenum pname, GLfloat param);
	02162 typedef void (APIENTRY* PFNGLLISTPARAMETERFVSGIXPROC) (GLuint list, GLenum pname, const GLfloat* params);
	02163 typedef void (APIENTRY* PFNGLLISTPARAMETERISGIXPROC) (GLuint list, GLenum pname, GLint param);
	02164 typedef void (APIENTRY* PFNGLLISTPARAMETERIVSGIXPROC) (GLuint list, GLenum pname, const GLint* params);
	02165 #endif
		02166
		02167 #ifndef GL_SGIX_ir_instrument1
		02168 #define GL_SGIX_ir_instrument1 1
		02169 #endif
		02170
		02171 #ifndef GL_SGIX_calligraphic_fragment
		02172 #define GL_SGIX_calligraphic_fragment 1
		02173 #endif
		02174
		02175 #ifndef GL_SGIX_texture_lod_bias
		02176 #define GL_SGIX_texture_lod_bias 1
		02177 #endif
		02178
		02179 #ifndef GL_SGIX_shadow_ambient
		02180 #define GL_SGIX_shadow_ambient 1
		02181 #endif
		02182
		02183 #ifndef GL_EXT_index_texture
		02184 #define GL_EXT_index_texture 1
		02185 #endif
		02186
		02187 #ifndef GL_EXT_index_material
		02188 #define GL_EXT_index_material 1
		02189 #ifdef GL_GLEXT_PROTOTYPES
		02190 extern void APIENTRY glIndexMaterialEXT(GLenum, GLenum);
	02191 #endif /* GL_GLEXT_PROTOTYPES */
		02192 typedef void (APIENTRY* PFNGLINDEXMATERIALEXTPROC) (GLenum face, GLenum mode);
	02193 #endif
		02194
		02195 #ifndef GL_EXT_index_func
		02196 #define GL_EXT_index_func 1
		02197 #ifdef GL_GLEXT_PROTOTYPES
		02198 extern void APIENTRY glIndexFuncEXT(GLenum, GLclampf);
	02199 #endif /* GL_GLEXT_PROTOTYPES */
		02200 typedef void (APIENTRY* PFNGLINDEXFUNCEXTPROC) (GLenum func, GLclampf ref);
	02201 #endif
		02202
		02203 #ifndef GL_EXT_index_array_formats
		02204 #define GL_EXT_index_array_formats 1
		02205 #endif
		02206
		02207 #ifndef GL_EXT_compiled_vertex_array
		02208 #define GL_EXT_compiled_vertex_array 1
		02209 #ifdef GL_GLEXT_PROTOTYPES
		02210 extern void APIENTRY glLockArraysEXT(GLint, GLsizei);
	02211 extern void APIENTRY glUnlockArraysEXT(void);
	02212 #endif /* GL_GLEXT_PROTOTYPES */
		02213 typedef void (APIENTRY* PFNGLLOCKARRAYSEXTPROC) (GLint first, GLsizei count);
	02214 typedef void (APIENTRY* PFNGLUNLOCKARRAYSEXTPROC) (void);
	02215 #endif
		02216
		02217 #ifndef GL_EXT_cull_vertex
		02218 #define GL_EXT_cull_vertex 1
		02219 #ifdef GL_GLEXT_PROTOTYPES
		02220 extern void APIENTRY glCullParameterdvEXT(GLenum, GLdouble*);
	02221 extern void APIENTRY glCullParameterfvEXT(GLenum, GLfloat*);
	02222 #endif /* GL_GLEXT_PROTOTYPES */
		02223 typedef void (APIENTRY* PFNGLCULLPARAMETERDVEXTPROC) (GLenum pname, GLdouble* params);
	02224 typedef void (APIENTRY* PFNGLCULLPARAMETERFVEXTPROC) (GLenum pname, GLfloat* params);
	02225 #endif
		02226
		02227 #ifndef GL_SGIX_ycrcb
		02228 #define GL_SGIX_ycrcb 1
		02229 #endif
		02230
		02231 #ifndef GL_SGIX_fragment_lighting
		02232 #define GL_SGIX_fragment_lighting 1
		02233 #ifdef GL_GLEXT_PROTOTYPES
		02234 extern void APIENTRY glFragmentColorMaterialSGIX(GLenum, GLenum);
	02235 extern void APIENTRY glFragmentLightfSGIX(GLenum, GLenum, GLfloat);
	02236 extern void APIENTRY glFragmentLightfvSGIX(GLenum, GLenum, const GLfloat*);
	02237 extern void APIENTRY glFragmentLightiSGIX(GLenum, GLenum, GLint);
	02238 extern void APIENTRY glFragmentLightivSGIX(GLenum, GLenum, const GLint*);
	02239 extern void APIENTRY glFragmentLightModelfSGIX(GLenum, GLfloat);
	02240 extern void APIENTRY glFragmentLightModelfvSGIX(GLenum, const GLfloat*);
	02241 extern void APIENTRY glFragmentLightModeliSGIX(GLenum, GLint);
	02242 extern void APIENTRY glFragmentLightModelivSGIX(GLenum, const GLint*);
	02243 extern void APIENTRY glFragmentMaterialfSGIX(GLenum, GLenum, GLfloat);
	02244 extern void APIENTRY glFragmentMaterialfvSGIX(GLenum, GLenum, const GLfloat*);
	02245 extern void APIENTRY glFragmentMaterialiSGIX(GLenum, GLenum, GLint);
	02246 extern void APIENTRY glFragmentMaterialivSGIX(GLenum, GLenum, const GLint*);
	02247 extern void APIENTRY glGetFragmentLightfvSGIX(GLenum, GLenum, GLfloat*);
	02248 extern void APIENTRY glGetFragmentLightivSGIX(GLenum, GLenum, GLint*);
	02249 extern void APIENTRY glGetFragmentMaterialfvSGIX(GLenum, GLenum, GLfloat*);
	02250 extern void APIENTRY glGetFragmentMaterialivSGIX(GLenum, GLenum, GLint*);
	02251 extern void APIENTRY glLightEnviSGIX(GLenum, GLint);
	02252 #endif /* GL_GLEXT_PROTOTYPES */
		02253 typedef void (APIENTRY* PFNGLFRAGMENTCOLORMATERIALSGIXPROC) (GLenum face, GLenum mode);
	02254 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTFSGIXPROC) (GLenum light, GLenum pname, GLfloat param);
	02255 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, const GLfloat* params);
	02256 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTISGIXPROC) (GLenum light, GLenum pname, GLint param);
	02257 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, const GLint* params);
	02258 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTMODELFSGIXPROC) (GLenum pname, GLfloat param);
	02259 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTMODELFVSGIXPROC) (GLenum pname, const GLfloat* params);
	02260 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTMODELISGIXPROC) (GLenum pname, GLint param);
	02261 typedef void (APIENTRY* PFNGLFRAGMENTLIGHTMODELIVSGIXPROC) (GLenum pname, const GLint* params);
	02262 typedef void (APIENTRY* PFNGLFRAGMENTMATERIALFSGIXPROC) (GLenum face, GLenum pname, GLfloat param);
	02263 typedef void (APIENTRY* PFNGLFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, const GLfloat* params);
	02264 typedef void (APIENTRY* PFNGLFRAGMENTMATERIALISGIXPROC) (GLenum face, GLenum pname, GLint param);
	02265 typedef void (APIENTRY* PFNGLFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, const GLint* params);
	02266 typedef void (APIENTRY* PFNGLGETFRAGMENTLIGHTFVSGIXPROC) (GLenum light, GLenum pname, GLfloat* params);
	02267 typedef void (APIENTRY* PFNGLGETFRAGMENTLIGHTIVSGIXPROC) (GLenum light, GLenum pname, GLint* params);
	02268 typedef void (APIENTRY* PFNGLGETFRAGMENTMATERIALFVSGIXPROC) (GLenum face, GLenum pname, GLfloat* params);
	02269 typedef void (APIENTRY* PFNGLGETFRAGMENTMATERIALIVSGIXPROC) (GLenum face, GLenum pname, GLint* params);
	02270 typedef void (APIENTRY* PFNGLLIGHTENVISGIXPROC) (GLenum pname, GLint param);
	02271 #endif
		02272
		02273 #ifndef GL_IBM_rasterpos_clip
		02274 #define GL_IBM_rasterpos_clip 1
		02275 #endif
		02276
		02277 #ifndef GL_HP_texture_lighting
		02278 #define GL_HP_texture_lighting 1
		02279 #endif
		02280
		02281 #ifndef GL_EXT_draw_range_elements
		02282 #define GL_EXT_draw_range_elements 1
		02283 #ifdef GL_GLEXT_PROTOTYPES
		02284 extern void APIENTRY glDrawRangeElementsEXT(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid*);
	02285 #endif /* GL_GLEXT_PROTOTYPES */
		02286 typedef void (APIENTRY* PFNGLDRAWRANGEELEMENTSEXTPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid* indices);
	02287 #endif
		02288
		02289 #ifndef GL_WIN_phong_shading
		02290 #define GL_WIN_phong_shading 1
		02291 #endif
		02292
		02293 #ifndef GL_WIN_specular_fog
		02294 #define GL_WIN_specular_fog 1
		02295 #endif
		02296
		02297 #ifndef GL_EXT_light_texture
		02298 #define GL_EXT_light_texture 1
		02299 #ifdef GL_GLEXT_PROTOTYPES
		02300 extern void APIENTRY glApplyTextureEXT(GLenum);
	02301 extern void APIENTRY glTextureLightEXT(GLenum);
	02302 extern void APIENTRY glTextureMaterialEXT(GLenum, GLenum);
	02303 #endif /* GL_GLEXT_PROTOTYPES */
		02304 typedef void (APIENTRY* PFNGLAPPLYTEXTUREEXTPROC) (GLenum mode);
	02305 typedef void (APIENTRY* PFNGLTEXTURELIGHTEXTPROC) (GLenum pname);
	02306 typedef void (APIENTRY* PFNGLTEXTUREMATERIALEXTPROC) (GLenum face, GLenum mode);
	02307 #endif
		02308
		02309 #ifndef GL_SGIX_blend_alpha_minmax
		02310 #define GL_SGIX_blend_alpha_minmax 1
		02311 #endif
		02312
		02313 #ifndef GL_EXT_bgra
		02314 #define GL_EXT_bgra 1
		02315 #endif
		02316
		02317 #ifndef GL_INTEL_parallel_arrays
		02318 #define GL_INTEL_parallel_arrays 1
		02319 #ifdef GL_GLEXT_PROTOTYPES
		02320 extern void APIENTRY glVertexPointervINTEL(GLint, GLenum, const GLvoid**);
	02321 extern void APIENTRY glNormalPointervINTEL(GLenum, const GLvoid**);
	02322 extern void APIENTRY glColorPointervINTEL(GLint, GLenum, const GLvoid**);
	02323 extern void APIENTRY glTexCoordPointervINTEL(GLint, GLenum, const GLvoid**);
	02324 #endif /* GL_GLEXT_PROTOTYPES */
		02325 typedef void (APIENTRY* PFNGLVERTEXPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid** pointer);
	02326 typedef void (APIENTRY* PFNGLNORMALPOINTERVINTELPROC) (GLenum type, const GLvoid** pointer);
	02327 typedef void (APIENTRY* PFNGLCOLORPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid** pointer);
	02328 typedef void (APIENTRY* PFNGLTEXCOORDPOINTERVINTELPROC) (GLint size, GLenum type, const GLvoid** pointer);
	02329 #endif
		02330
		02331 #ifndef GL_HP_occlusion_test
		02332 #define GL_HP_occlusion_test 1
		02333 #endif
		02334
		02335 #ifndef GL_EXT_pixel_transform
		02336 #define GL_EXT_pixel_transform 1
		02337 #ifdef GL_GLEXT_PROTOTYPES
		02338 extern void APIENTRY glPixelTransformParameteriEXT(GLenum, GLenum, GLint);
	02339 extern void APIENTRY glPixelTransformParameterfEXT(GLenum, GLenum, GLfloat);
	02340 extern void APIENTRY glPixelTransformParameterivEXT(GLenum, GLenum, const GLint*);
	02341 extern void APIENTRY glPixelTransformParameterfvEXT(GLenum, GLenum, const GLfloat*);
	02342 #endif /* GL_GLEXT_PROTOTYPES */
		02343 typedef void (APIENTRY* PFNGLPIXELTRANSFORMPARAMETERIEXTPROC) (GLenum target, GLenum pname, GLint param);
	02344 typedef void (APIENTRY* PFNGLPIXELTRANSFORMPARAMETERFEXTPROC) (GLenum target, GLenum pname, GLfloat param);
	02345 typedef void (APIENTRY* PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC) (GLenum target, GLenum pname, const GLint* params);
	02346 typedef void (APIENTRY* PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC) (GLenum target, GLenum pname, const GLfloat* params);
	02347 #endif
		02348
		02349 #ifndef GL_EXT_pixel_transform_color_table
		02350 #define GL_EXT_pixel_transform_color_table 1
		02351 #endif
		02352
		02353 #ifndef GL_EXT_shared_texture_palette
		02354 #define GL_EXT_shared_texture_palette 1
		02355 #endif
		02356
		02357 #ifndef GL_EXT_separate_specular_color
		02358 #define GL_EXT_separate_specular_color 1
		02359 #endif
		02360
		02361 #ifndef GL_EXT_secondary_color
		02362 #define GL_EXT_secondary_color 1
		02363 #ifdef GL_GLEXT_PROTOTYPES
		02364 extern void APIENTRY glSecondaryColor3bEXT(GLbyte, GLbyte, GLbyte);
	02365 extern void APIENTRY glSecondaryColor3bvEXT(const GLbyte*);
	02366 extern void APIENTRY glSecondaryColor3dEXT(GLdouble, GLdouble, GLdouble);
	02367 extern void APIENTRY glSecondaryColor3dvEXT(const GLdouble*);
	02368 extern void APIENTRY glSecondaryColor3fEXT(GLfloat, GLfloat, GLfloat);
	02369 extern void APIENTRY glSecondaryColor3fvEXT(const GLfloat*);
	02370 extern void APIENTRY glSecondaryColor3iEXT(GLint, GLint, GLint);
	02371 extern void APIENTRY glSecondaryColor3ivEXT(const GLint*);
	02372 extern void APIENTRY glSecondaryColor3sEXT(GLshort, GLshort, GLshort);
	02373 extern void APIENTRY glSecondaryColor3svEXT(const GLshort*);
	02374 extern void APIENTRY glSecondaryColor3ubEXT(GLubyte, GLubyte, GLubyte);
	02375 extern void APIENTRY glSecondaryColor3ubvEXT(const GLubyte*);
	02376 extern void APIENTRY glSecondaryColor3uiEXT(GLuint, GLuint, GLuint);
	02377 extern void APIENTRY glSecondaryColor3uivEXT(const GLuint*);
	02378 extern void APIENTRY glSecondaryColor3usEXT(GLushort, GLushort, GLushort);
	02379 extern void APIENTRY glSecondaryColor3usvEXT(const GLushort*);
	02380 extern void APIENTRY glSecondaryColorPointerEXT(GLint, GLenum, GLsizei, GLvoid*);
	02381 #endif /* GL_GLEXT_PROTOTYPES */
		02382 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3BEXTPROC) (GLbyte red, GLbyte green, GLbyte blue);
	02383 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3BVEXTPROC) (const GLbyte* v);
	02384 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3DEXTPROC) (GLdouble red, GLdouble green, GLdouble blue);
	02385 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3DVEXTPROC) (const GLdouble* v);
	02386 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3FEXTPROC) (GLfloat red, GLfloat green, GLfloat blue);
	02387 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3FVEXTPROC) (const GLfloat* v);
	02388 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3IEXTPROC) (GLint red, GLint green, GLint blue);
	02389 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3IVEXTPROC) (const GLint* v);
	02390 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3SEXTPROC) (GLshort red, GLshort green, GLshort blue);
	02391 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3SVEXTPROC) (const GLshort* v);
	02392 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3UBEXTPROC) (GLubyte red, GLubyte green, GLubyte blue);
	02393 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3UBVEXTPROC) (const GLubyte* v);
	02394 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3UIEXTPROC) (GLuint red, GLuint green, GLuint blue);
	02395 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3UIVEXTPROC) (const GLuint* v);
	02396 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3USEXTPROC) (GLushort red, GLushort green, GLushort blue);
	02397 typedef void (APIENTRY* PFNGLSECONDARYCOLOR3USVEXTPROC) (const GLushort* v);
	02398 typedef void (APIENTRY* PFNGLSECONDARYCOLORPOINTEREXTPROC) (GLint size, GLenum type, GLsizei stride, GLvoid* pointer);
	02399 #endif
		02400
		02401 #ifndef GL_EXT_texture_perturb_normal
		02402 #define GL_EXT_texture_perturb_normal 1
		02403 #ifdef GL_GLEXT_PROTOTYPES
		02404 extern void APIENTRY glTextureNormalEXT(GLenum);
	02405 #endif /* GL_GLEXT_PROTOTYPES */
		02406 typedef void (APIENTRY* PFNGLTEXTURENORMALEXTPROC) (GLenum mode);
	02407 #endif
		02408
		02409 #ifndef GL_EXT_multi_draw_arrays
		02410 #define GL_EXT_multi_draw_arrays 1
		02411 #ifdef GL_GLEXT_PROTOTYPES
		02412 extern void APIENTRY glMultiDrawArraysEXT(GLenum, GLint*, GLsizei*, GLsizei);
	02413 extern void APIENTRY glMultiDrawElementsEXT(GLenum, const GLsizei*, GLenum, const GLvoid**, GLsizei);
	02414 #endif /* GL_GLEXT_PROTOTYPES */
		02415 typedef void (APIENTRY* PFNGLMULTIDRAWARRAYSEXTPROC) (GLenum mode, GLint* first, GLsizei* count, GLsizei primcount);
	02416 typedef void (APIENTRY* PFNGLMULTIDRAWELEMENTSEXTPROC) (GLenum mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount);
	02417 #endif
		02418
		02419 #ifndef GL_EXT_fog_coord
		02420 #define GL_EXT_fog_coord 1
		02421 #ifdef GL_GLEXT_PROTOTYPES
		02422 extern void APIENTRY glFogCoordfEXT(GLfloat);
	02423 extern void APIENTRY glFogCoordfvEXT(const GLfloat*);
	02424 extern void APIENTRY glFogCoorddEXT(GLdouble);
	02425 extern void APIENTRY glFogCoorddvEXT(const GLdouble*);
	02426 extern void APIENTRY glFogCoordPointerEXT(GLenum, GLsizei, const GLvoid*);
	02427 #endif /* GL_GLEXT_PROTOTYPES */
		02428 typedef void (APIENTRY* PFNGLFOGCOORDFEXTPROC) (GLfloat coord);
	02429 typedef void (APIENTRY* PFNGLFOGCOORDFVEXTPROC) (const GLfloat* coord);
	02430 typedef void (APIENTRY* PFNGLFOGCOORDDEXTPROC) (GLdouble coord);
	02431 typedef void (APIENTRY* PFNGLFOGCOORDDVEXTPROC) (const GLdouble* coord);
	02432 typedef void (APIENTRY* PFNGLFOGCOORDPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid* pointer);
	02433 #endif
		02434
		02435 #ifndef GL_REND_screen_coordinates
		02436 #define GL_REND_screen_coordinates 1
		02437 #endif
		02438
		02439 #ifndef GL_EXT_coordinate_frame
		02440 #define GL_EXT_coordinate_frame 1
		02441 #ifdef GL_GLEXT_PROTOTYPES
		02442 extern void APIENTRY glTangent3bEXT(GLbyte, GLbyte, GLbyte);
	02443 extern void APIENTRY glTangent3bvEXT(const GLbyte*);
	02444 extern void APIENTRY glTangent3dEXT(GLdouble, GLdouble, GLdouble);
	02445 extern void APIENTRY glTangent3dvEXT(const GLdouble*);
	02446 extern void APIENTRY glTangent3fEXT(GLfloat, GLfloat, GLfloat);
	02447 extern void APIENTRY glTangent3fvEXT(const GLfloat*);
	02448 extern void APIENTRY glTangent3iEXT(GLint, GLint, GLint);
	02449 extern void APIENTRY glTangent3ivEXT(const GLint*);
	02450 extern void APIENTRY glTangent3sEXT(GLshort, GLshort, GLshort);
	02451 extern void APIENTRY glTangent3svEXT(const GLshort*);
	02452 extern void APIENTRY glBinormal3bEXT(GLbyte, GLbyte, GLbyte);
	02453 extern void APIENTRY glBinormal3bvEXT(const GLbyte*);
	02454 extern void APIENTRY glBinormal3dEXT(GLdouble, GLdouble, GLdouble);
	02455 extern void APIENTRY glBinormal3dvEXT(const GLdouble*);
	02456 extern void APIENTRY glBinormal3fEXT(GLfloat, GLfloat, GLfloat);
	02457 extern void APIENTRY glBinormal3fvEXT(const GLfloat*);
	02458 extern void APIENTRY glBinormal3iEXT(GLint, GLint, GLint);
	02459 extern void APIENTRY glBinormal3ivEXT(const GLint*);
	02460 extern void APIENTRY glBinormal3sEXT(GLshort, GLshort, GLshort);
	02461 extern void APIENTRY glBinormal3svEXT(const GLshort*);
	02462 extern void APIENTRY glTangentPointerEXT(GLenum, GLsizei, const GLvoid*);
	02463 extern void APIENTRY glBinormalPointerEXT(GLenum, GLsizei, const GLvoid*);
	02464 #endif /* GL_GLEXT_PROTOTYPES */
		02465 typedef void (APIENTRY* PFNGLTANGENT3BEXTPROC) (GLbyte tx, GLbyte ty, GLbyte tz);
	02466 typedef void (APIENTRY* PFNGLTANGENT3BVEXTPROC) (const GLbyte* v);
	02467 typedef void (APIENTRY* PFNGLTANGENT3DEXTPROC) (GLdouble tx, GLdouble ty, GLdouble tz);
	02468 typedef void (APIENTRY* PFNGLTANGENT3DVEXTPROC) (const GLdouble* v);
	02469 typedef void (APIENTRY* PFNGLTANGENT3FEXTPROC) (GLfloat tx, GLfloat ty, GLfloat tz);
	02470 typedef void (APIENTRY* PFNGLTANGENT3FVEXTPROC) (const GLfloat* v);
	02471 typedef void (APIENTRY* PFNGLTANGENT3IEXTPROC) (GLint tx, GLint ty, GLint tz);
	02472 typedef void (APIENTRY* PFNGLTANGENT3IVEXTPROC) (const GLint* v);
	02473 typedef void (APIENTRY* PFNGLTANGENT3SEXTPROC) (GLshort tx, GLshort ty, GLshort tz);
	02474 typedef void (APIENTRY* PFNGLTANGENT3SVEXTPROC) (const GLshort* v);
	02475 typedef void (APIENTRY* PFNGLBINORMAL3BEXTPROC) (GLbyte bx, GLbyte by, GLbyte bz);
	02476 typedef void (APIENTRY* PFNGLBINORMAL3BVEXTPROC) (const GLbyte* v);
	02477 typedef void (APIENTRY* PFNGLBINORMAL3DEXTPROC) (GLdouble bx, GLdouble by, GLdouble bz);
	02478 typedef void (APIENTRY* PFNGLBINORMAL3DVEXTPROC) (const GLdouble* v);
	02479 typedef void (APIENTRY* PFNGLBINORMAL3FEXTPROC) (GLfloat bx, GLfloat by, GLfloat bz);
	02480 typedef void (APIENTRY* PFNGLBINORMAL3FVEXTPROC) (const GLfloat* v);
	02481 typedef void (APIENTRY* PFNGLBINORMAL3IEXTPROC) (GLint bx, GLint by, GLint bz);
	02482 typedef void (APIENTRY* PFNGLBINORMAL3IVEXTPROC) (const GLint* v);
	02483 typedef void (APIENTRY* PFNGLBINORMAL3SEXTPROC) (GLshort bx, GLshort by, GLshort bz);
	02484 typedef void (APIENTRY* PFNGLBINORMAL3SVEXTPROC) (const GLshort* v);
	02485 typedef void (APIENTRY* PFNGLTANGENTPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid* pointer);
	02486 typedef void (APIENTRY* PFNGLBINORMALPOINTEREXTPROC) (GLenum type, GLsizei stride, const GLvoid* pointer);
	02487 #endif
		02488
		02489 #ifndef GL_EXT_texture_env_combine
		02490 #define GL_EXT_texture_env_combine 1
		02491 #endif
		02492
		02493 #ifndef GL_APPLE_specular_vector
		02494 #define GL_APPLE_specular_vector 1
		02495 #endif
		02496
		02497 #ifndef GL_APPLE_transform_hint
		02498 #define GL_APPLE_transform_hint 1
		02499 #endif
		02500
		02501 #ifndef GL_SGIX_fog_scale
		02502 #define GL_SGIX_fog_scale 1
		02503 #endif
		02504
		02505 #ifndef GL_SUNX_constant_data
		02506 #define GL_SUNX_constant_data 1
		02507 #ifdef GL_GLEXT_PROTOTYPES
		02508 extern void APIENTRY glFinishTextureSUNX(void);
	02509 #endif /* GL_GLEXT_PROTOTYPES */
		02510 typedef void (APIENTRY* PFNGLFINISHTEXTURESUNXPROC) (void);
	02511 #endif
		02512
		02513 #ifndef GL_SUN_global_alpha
		02514 #define GL_SUN_global_alpha 1
		02515 #ifdef GL_GLEXT_PROTOTYPES
		02516 extern void APIENTRY glGlobalAlphaFactorbSUN(GLbyte);
	02517 extern void APIENTRY glGlobalAlphaFactorsSUN(GLshort);
	02518 extern void APIENTRY glGlobalAlphaFactoriSUN(GLint);
	02519 extern void APIENTRY glGlobalAlphaFactorfSUN(GLfloat);
	02520 extern void APIENTRY glGlobalAlphaFactordSUN(GLdouble);
	02521 extern void APIENTRY glGlobalAlphaFactorubSUN(GLubyte);
	02522 extern void APIENTRY glGlobalAlphaFactorusSUN(GLushort);
	02523 extern void APIENTRY glGlobalAlphaFactoruiSUN(GLuint);
	02524 #endif /* GL_GLEXT_PROTOTYPES */
		02525 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORBSUNPROC) (GLbyte factor);
	02526 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORSSUNPROC) (GLshort factor);
	02527 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORISUNPROC) (GLint factor);
	02528 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORFSUNPROC) (GLfloat factor);
	02529 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORDSUNPROC) (GLdouble factor);
	02530 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORUBSUNPROC) (GLubyte factor);
	02531 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORUSSUNPROC) (GLushort factor);
	02532 typedef void (APIENTRY* PFNGLGLOBALALPHAFACTORUISUNPROC) (GLuint factor);
	02533 #endif
		02534
		02535 #ifndef GL_SUN_triangle_list
		02536 #define GL_SUN_triangle_list 1
		02537 #ifdef GL_GLEXT_PROTOTYPES
		02538 extern void APIENTRY glReplacementCodeuiSUN(GLuint);
	02539 extern void APIENTRY glReplacementCodeusSUN(GLushort);
	02540 extern void APIENTRY glReplacementCodeubSUN(GLubyte);
	02541 extern void APIENTRY glReplacementCodeuivSUN(const GLuint*);
	02542 extern void APIENTRY glReplacementCodeusvSUN(const GLushort*);
	02543 extern void APIENTRY glReplacementCodeubvSUN(const GLubyte*);
	02544 extern void APIENTRY glReplacementCodePointerSUN(GLenum, GLsizei, const GLvoid**);
	02545 #endif /* GL_GLEXT_PROTOTYPES */
		02546 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUISUNPROC) (GLuint code);
	02547 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUSSUNPROC) (GLushort code);
	02548 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUBSUNPROC) (GLubyte code);
	02549 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUIVSUNPROC) (const GLuint* code);
	02550 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUSVSUNPROC) (const GLushort* code);
	02551 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUBVSUNPROC) (const GLubyte* code);
	02552 typedef void (APIENTRY* PFNGLREPLACEMENTCODEPOINTERSUNPROC) (GLenum type, GLsizei stride, const GLvoid** pointer);
	02553 #endif
		02554
		02555 #ifndef GL_SUN_vertex
		02556 #define GL_SUN_vertex 1
		02557 #ifdef GL_GLEXT_PROTOTYPES
		02558 extern void APIENTRY glColor4ubVertex2fSUN(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat);
	02559 extern void APIENTRY glColor4ubVertex2fvSUN(const GLubyte*, const GLfloat*);
	02560 extern void APIENTRY glColor4ubVertex3fSUN(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	02561 extern void APIENTRY glColor4ubVertex3fvSUN(const GLubyte*, const GLfloat*);
	02562 extern void APIENTRY glColor3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02563 extern void APIENTRY glColor3fVertex3fvSUN(const GLfloat*, const GLfloat*);
	02564 extern void APIENTRY glNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02565 extern void APIENTRY glNormal3fVertex3fvSUN(const GLfloat*, const GLfloat*);
	02566 extern void APIENTRY glColor4fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02567 extern void APIENTRY glColor4fNormal3fVertex3fvSUN(const GLfloat*, const GLfloat*, const GLfloat*);
	02568 extern void APIENTRY glTexCoord2fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02569 extern void APIENTRY glTexCoord2fVertex3fvSUN(const GLfloat*, const GLfloat*);
	02570 extern void APIENTRY glTexCoord4fVertex4fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02571 extern void APIENTRY glTexCoord4fVertex4fvSUN(const GLfloat*, const GLfloat*);
	02572 extern void APIENTRY glTexCoord2fColor4ubVertex3fSUN(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	02573 extern void APIENTRY glTexCoord2fColor4ubVertex3fvSUN(const GLfloat*, const GLubyte*, const GLfloat*);
	02574 extern void APIENTRY glTexCoord2fColor3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02575 extern void APIENTRY glTexCoord2fColor3fVertex3fvSUN(const GLfloat*, const GLfloat*, const GLfloat*);
	02576 extern void APIENTRY glTexCoord2fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02577 extern void APIENTRY glTexCoord2fNormal3fVertex3fvSUN(const GLfloat*, const GLfloat*, const GLfloat*);
	02578 extern void APIENTRY glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02579 extern void APIENTRY glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
	02580 extern void APIENTRY glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02581 extern void APIENTRY glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
	02582 extern void APIENTRY glReplacementCodeuiVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat);
	02583 extern void APIENTRY glReplacementCodeuiVertex3fvSUN(const GLenum*, const GLfloat*);
	02584 extern void APIENTRY glReplacementCodeuiColor4ubVertex3fSUN(GLenum, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
	02585 extern void APIENTRY glReplacementCodeuiColor4ubVertex3fvSUN(const GLenum*, const GLubyte*, const GLfloat*);
	02586 extern void APIENTRY glReplacementCodeuiColor3fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02587 extern void APIENTRY glReplacementCodeuiColor3fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*);
	02588 extern void APIENTRY glReplacementCodeuiNormal3fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02589 extern void APIENTRY glReplacementCodeuiNormal3fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*);
	02590 extern void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02591 extern void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*, const GLfloat*);
	02592 extern void APIENTRY glReplacementCodeuiTexCoord2fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02593 extern void APIENTRY glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*);
	02594 extern void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02595 extern void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*, const GLfloat*);
	02596 extern void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLenum, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	02597 extern void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLenum*, const GLfloat*, const GLfloat*, const GLfloat*, const GLfloat*);
	02598 #endif /* GL_GLEXT_PROTOTYPES */
		02599 typedef void (APIENTRY* PFNGLCOLOR4UBVERTEX2FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
	02600 typedef void (APIENTRY* PFNGLCOLOR4UBVERTEX2FVSUNPROC) (const GLubyte* c, const GLfloat* v);
	02601 typedef void (APIENTRY* PFNGLCOLOR4UBVERTEX3FSUNPROC) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	02602 typedef void (APIENTRY* PFNGLCOLOR4UBVERTEX3FVSUNPROC) (const GLubyte* c, const GLfloat* v);
	02603 typedef void (APIENTRY* PFNGLCOLOR3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	02604 typedef void (APIENTRY* PFNGLCOLOR3FVERTEX3FVSUNPROC) (const GLfloat* c, const GLfloat* v);
	02605 typedef void (APIENTRY* PFNGLNORMAL3FVERTEX3FSUNPROC) (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02606 typedef void (APIENTRY* PFNGLNORMAL3FVERTEX3FVSUNPROC) (const GLfloat* n, const GLfloat* v);
	02607 typedef void (APIENTRY* PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02608 typedef void (APIENTRY* PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat* c, const GLfloat* n, const GLfloat* v);
	02609 typedef void (APIENTRY* PFNGLTEXCOORD2FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	02610 typedef void (APIENTRY* PFNGLTEXCOORD2FVERTEX3FVSUNPROC) (const GLfloat* tc, const GLfloat* v);
	02611 typedef void (APIENTRY* PFNGLTEXCOORD4FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	02612 typedef void (APIENTRY* PFNGLTEXCOORD4FVERTEX4FVSUNPROC) (const GLfloat* tc, const GLfloat* v);
	02613 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	02614 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) (const GLfloat* tc, const GLubyte* c, const GLfloat* v);
	02615 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	02616 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) (const GLfloat* tc, const GLfloat* c, const GLfloat* v);
	02617 typedef void (APIENTRY* PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02618 typedef void (APIENTRY* PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat* tc, const GLfloat* n, const GLfloat* v);
	02619 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02620 typedef void (APIENTRY* PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
	02621 typedef void (APIENTRY* PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	02622 typedef void (APIENTRY* PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) (const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
	02623 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) (GLenum rc, GLfloat x, GLfloat y, GLfloat z);
	02624 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* v);
	02625 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) (GLenum rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	02626 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) (const GLenum* rc, const GLubyte* c, const GLfloat* v);
	02627 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) (GLenum rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	02628 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* c, const GLfloat* v);
	02629 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) (GLenum rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02630 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* n, const GLfloat* v);
	02631 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLenum rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02632 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
	02633 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) (GLenum rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	02634 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* tc, const GLfloat* v);
	02635 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (GLenum rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02636 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* tc, const GLfloat* n, const GLfloat* v);
	02637 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (GLenum rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	02638 typedef void (APIENTRY* PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (const GLenum* rc, const GLfloat* tc, const GLfloat* c, const GLfloat* n, const GLfloat* v);
	02639 #endif
		02640
		02641 #ifndef GL_EXT_blend_func_separate
		02642 #define GL_EXT_blend_func_separate 1
		02643 #ifdef GL_GLEXT_PROTOTYPES
		02644 extern void APIENTRY glBlendFuncSeparateEXT(GLenum, GLenum, GLenum, GLenum);
	02645 #endif /* GL_GLEXT_PROTOTYPES */
		02646 typedef void (APIENTRY* PFNGLBLENDFUNCSEPARATEEXTPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	02647 #endif
		02648
		02649 #ifndef GL_INGR_color_clamp
		02650 #define GL_INGR_color_clamp 1
		02651 #endif
		02652
		02653 #ifndef GL_INGR_interlace_read
		02654 #define GL_INGR_interlace_read 1
		02655 #endif
		02656
		02657 #ifndef GL_EXT_stencil_wrap
		02658 #define GL_EXT_stencil_wrap 1
		02659 #endif
		02660
		02661 #ifndef GL_EXT_422_pixels
		02662 #define GL_EXT_422_pixels 1
		02663 #endif
		02664
		02665 #ifndef GL_NV_texgen_reflection
		02666 #define GL_NV_texgen_reflection 1
		02667 #endif
		02668
		02669 #ifndef GL_SUN_convolution_border_modes
		02670 #define GL_SUN_convolution_border_modes 1
		02671 #endif
		02672
		02673 #ifndef GL_EXT_texture_env_add
		02674 #define GL_EXT_texture_env_add 1
		02675 #endif
		02676
		02677 #ifndef GL_EXT_texture_lod_bias
		02678 #define GL_EXT_texture_lod_bias 1
		02679 #endif
		02680
		02681 #ifndef GL_EXT_texture_filter_anisotropic
		02682 #define GL_EXT_texture_filter_anisotropic 1
		02683 #endif
		02684
		02685 #ifndef GL_EXT_vertex_weighting
		02686 #define GL_EXT_vertex_weighting 1
		02687 #ifdef GL_GLEXT_PROTOTYPES
		02688 extern void APIENTRY glVertexWeightfEXT(GLfloat);
	02689 extern void APIENTRY glVertexWeightfvEXT(const GLfloat*);
	02690 extern void APIENTRY glVertexWeightPointerEXT(GLsizei, GLenum, GLsizei, const GLvoid*);
	02691 #endif /* GL_GLEXT_PROTOTYPES */
		02692 typedef void (APIENTRY* PFNGLVERTEXWEIGHTFEXTPROC) (GLfloat weight);
	02693 typedef void (APIENTRY* PFNGLVERTEXWEIGHTFVEXTPROC) (const GLfloat* weight);
	02694 typedef void (APIENTRY* PFNGLVERTEXWEIGHTPOINTEREXTPROC) (GLsizei size, GLenum type, GLsizei stride, const GLvoid* pointer);
	02695 #endif
		02696
		02697 #ifndef GL_NV_light_max_exponent
		02698 #define GL_NV_light_max_exponent 1
		02699 #endif
		02700
		02701 #ifndef GL_NV_vertex_array_range
		02702 #define GL_NV_vertex_array_range 1
		02703 #ifdef GL_GLEXT_PROTOTYPES
		02704 extern void APIENTRY glFlushVertexArrayRangeNV(void);
	02705 extern void APIENTRY glVertexArrayRangeNV(GLsizei, const GLvoid*);
	02706 #endif /* GL_GLEXT_PROTOTYPES */
		02707 typedef void (APIENTRY* PFNGLFLUSHVERTEXARRAYRANGENVPROC) (void);
	02708 typedef void (APIENTRY* PFNGLVERTEXARRAYRANGENVPROC) (GLsizei size, const GLvoid* pointer);
	02709 #endif
		02710
		02711 #ifndef GL_NV_vertex_array_range
		02712 #define GL_NV_vertex_array_range2 1
		02713 #endif
		02714
		02715 #ifndef GL_NV_register_combiners
		02716 #define GL_NV_register_combiners 1
		02717 #ifdef GL_GLEXT_PROTOTYPES
		02718 extern void APIENTRY glCombinerParameterfvNV(GLenum, const GLfloat*);
	02719 extern void APIENTRY glCombinerParameterfNV(GLenum, GLfloat);
	02720 extern void APIENTRY glCombinerParameterivNV(GLenum, const GLint*);
	02721 extern void APIENTRY glCombinerParameteriNV(GLenum, GLint);
	02722 extern void APIENTRY glCombinerInputNV(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum);
	02723 extern void APIENTRY glCombinerOutputNV(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean);
	02724 extern void APIENTRY glFinalCombinerInputNV(GLenum, GLenum, GLenum, GLenum);
	02725 extern void APIENTRY glGetCombinerInputParameterfvNV(GLenum, GLenum, GLenum, GLenum, GLfloat*);
	02726 extern void APIENTRY glGetCombinerInputParameterivNV(GLenum, GLenum, GLenum, GLenum, GLint*);
	02727 extern void APIENTRY glGetCombinerOutputParameterfvNV(GLenum, GLenum, GLenum, GLfloat*);
	02728 extern void APIENTRY glGetCombinerOutputParameterivNV(GLenum, GLenum, GLenum, GLint*);
	02729 extern void APIENTRY glGetFinalCombinerInputParameterfvNV(GLenum, GLenum, GLfloat*);
	02730 extern void APIENTRY glGetFinalCombinerInputParameterivNV(GLenum, GLenum, GLint*);
	02731 #endif /* GL_GLEXT_PROTOTYPES */
		02732 typedef void (APIENTRY* PFNGLCOMBINERPARAMETERFVNVPROC) (GLenum pname, const GLfloat* params);
	02733 typedef void (APIENTRY* PFNGLCOMBINERPARAMETERFNVPROC) (GLenum pname, GLfloat param);
	02734 typedef void (APIENTRY* PFNGLCOMBINERPARAMETERIVNVPROC) (GLenum pname, const GLint* params);
	02735 typedef void (APIENTRY* PFNGLCOMBINERPARAMETERINVPROC) (GLenum pname, GLint param);
	02736 typedef void (APIENTRY* PFNGLCOMBINERINPUTNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	02737 typedef void (APIENTRY* PFNGLCOMBINEROUTPUTNVPROC) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
	02738 typedef void (APIENTRY* PFNGLFINALCOMBINERINPUTNVPROC) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	02739 typedef void (APIENTRY* PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat* params);
	02740 typedef void (APIENTRY* PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint* params);
	02741 typedef void (APIENTRY* PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLfloat* params);
	02742 typedef void (APIENTRY* PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (GLenum stage, GLenum portion, GLenum pname, GLint* params);
	02743 typedef void (APIENTRY* PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (GLenum variable, GLenum pname, GLfloat* params);
	02744 typedef void (APIENTRY* PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (GLenum variable, GLenum pname, GLint* params);
	02745 #endif
		02746
		02747 #ifndef GL_NV_fog_distance
		02748 #define GL_NV_fog_distance 1
		02749 #endif
		02750
		02751 #ifndef GL_NV_texgen_emboss
		02752 #define GL_NV_texgen_emboss 1
		02753 #endif
		02754
		02755 #ifndef GL_NV_blend_square
		02756 #define GL_NV_blend_square 1
		02757 #endif
		02758
		02759 #ifndef GL_NV_texture_env_combine4
		02760 #define GL_NV_texture_env_combine4 1
		02761 #endif
		02762
		02763 #ifndef GL_MESA_resize_buffers
		02764 #define GL_MESA_resize_buffers 1
		02765 #ifdef GL_GLEXT_PROTOTYPES
		02766 extern void APIENTRY glResizeBuffersMESA(void);
	02767 #endif /* GL_GLEXT_PROTOTYPES */
		02768 typedef void (APIENTRY* PFNGLRESIZEBUFFERSMESAPROC) (void);
	02769 #endif
		02770
		02771 #ifndef GL_MESA_window_pos
		02772 #define GL_MESA_window_pos 1
		02773 #ifdef GL_GLEXT_PROTOTYPES
		02774 extern void APIENTRY glWindowPos2dMESA(GLdouble, GLdouble);
	02775 extern void APIENTRY glWindowPos2dvMESA(const GLdouble*);
	02776 extern void APIENTRY glWindowPos2fMESA(GLfloat, GLfloat);
	02777 extern void APIENTRY glWindowPos2fvMESA(const GLfloat*);
	02778 extern void APIENTRY glWindowPos2iMESA(GLint, GLint);
	02779 extern void APIENTRY glWindowPos2ivMESA(const GLint*);
	02780 extern void APIENTRY glWindowPos2sMESA(GLshort, GLshort);
	02781 extern void APIENTRY glWindowPos2svMESA(const GLshort*);
	02782 extern void APIENTRY glWindowPos3dMESA(GLdouble, GLdouble, GLdouble);
	02783 extern void APIENTRY glWindowPos3dvMESA(const GLdouble*);
	02784 extern void APIENTRY glWindowPos3fMESA(GLfloat, GLfloat, GLfloat);
	02785 extern void APIENTRY glWindowPos3fvMESA(const GLfloat*);
	02786 extern void APIENTRY glWindowPos3iMESA(GLint, GLint, GLint);
	02787 extern void APIENTRY glWindowPos3ivMESA(const GLint*);
	02788 extern void APIENTRY glWindowPos3sMESA(GLshort, GLshort, GLshort);
	02789 extern void APIENTRY glWindowPos3svMESA(const GLshort*);
	02790 extern void APIENTRY glWindowPos4dMESA(GLdouble, GLdouble, GLdouble, GLdouble);
	02791 extern void APIENTRY glWindowPos4dvMESA(const GLdouble*);
	02792 extern void APIENTRY glWindowPos4fMESA(GLfloat, GLfloat, GLfloat, GLfloat);
	02793 extern void APIENTRY glWindowPos4fvMESA(const GLfloat*);
	02794 extern void APIENTRY glWindowPos4iMESA(GLint, GLint, GLint, GLint);
	02795 extern void APIENTRY glWindowPos4ivMESA(const GLint*);
	02796 extern void APIENTRY glWindowPos4sMESA(GLshort, GLshort, GLshort, GLshort);
	02797 extern void APIENTRY glWindowPos4svMESA(const GLshort*);
	02798 #endif /* GL_GLEXT_PROTOTYPES */
		02799 typedef void (APIENTRY* PFNGLWINDOWPOS2DMESAPROC) (GLdouble x, GLdouble y);
	02800 typedef void (APIENTRY* PFNGLWINDOWPOS2DVMESAPROC) (const GLdouble* v);
	02801 typedef void (APIENTRY* PFNGLWINDOWPOS2FMESAPROC) (GLfloat x, GLfloat y);
	02802 typedef void (APIENTRY* PFNGLWINDOWPOS2FVMESAPROC) (const GLfloat* v);
	02803 typedef void (APIENTRY* PFNGLWINDOWPOS2IMESAPROC) (GLint x, GLint y);
	02804 typedef void (APIENTRY* PFNGLWINDOWPOS2IVMESAPROC) (const GLint* v);
	02805 typedef void (APIENTRY* PFNGLWINDOWPOS2SMESAPROC) (GLshort x, GLshort y);
	02806 typedef void (APIENTRY* PFNGLWINDOWPOS2SVMESAPROC) (const GLshort* v);
	02807 typedef void (APIENTRY* PFNGLWINDOWPOS3DMESAPROC) (GLdouble x, GLdouble y, GLdouble z);
	02808 typedef void (APIENTRY* PFNGLWINDOWPOS3DVMESAPROC) (const GLdouble* v);
	02809 typedef void (APIENTRY* PFNGLWINDOWPOS3FMESAPROC) (GLfloat x, GLfloat y, GLfloat z);
	02810 typedef void (APIENTRY* PFNGLWINDOWPOS3FVMESAPROC) (const GLfloat* v);
	02811 typedef void (APIENTRY* PFNGLWINDOWPOS3IMESAPROC) (GLint x, GLint y, GLint z);
	02812 typedef void (APIENTRY* PFNGLWINDOWPOS3IVMESAPROC) (const GLint* v);
	02813 typedef void (APIENTRY* PFNGLWINDOWPOS3SMESAPROC) (GLshort x, GLshort y, GLshort z);
	02814 typedef void (APIENTRY* PFNGLWINDOWPOS3SVMESAPROC) (const GLshort* v);
	02815 typedef void (APIENTRY* PFNGLWINDOWPOS4DMESAPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	02816 typedef void (APIENTRY* PFNGLWINDOWPOS4DVMESAPROC) (const GLdouble* v);
	02817 typedef void (APIENTRY* PFNGLWINDOWPOS4FMESAPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	02818 typedef void (APIENTRY* PFNGLWINDOWPOS4FVMESAPROC) (const GLfloat* v);
	02819 typedef void (APIENTRY* PFNGLWINDOWPOS4IMESAPROC) (GLint x, GLint y, GLint z, GLint w);
	02820 typedef void (APIENTRY* PFNGLWINDOWPOS4IVMESAPROC) (const GLint* v);
	02821 typedef void (APIENTRY* PFNGLWINDOWPOS4SMESAPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
	02822 typedef void (APIENTRY* PFNGLWINDOWPOS4SVMESAPROC) (const GLshort* v);
	02823 #endif
		02824
		02825 #ifndef GL_IBM_cull_vertex
		02826 #define GL_IBM_cull_vertex 1
		02827 #endif
		02828
		02829 #ifndef GL_IBM_multimode_draw_arrays
		02830 #define GL_IBM_multimode_draw_arrays 1
		02831 #ifdef GL_GLEXT_PROTOTYPES
		02832 extern void APIENTRY glMultiModeDrawArraysIBM(GLenum, const GLint*, const GLsizei*, GLsizei, GLint);
	02833 extern void APIENTRY glMultiModeDrawElementsIBM(const GLenum*, const GLsizei*, GLenum, const GLvoid**, GLsizei, GLint);
	02834 #endif /* GL_GLEXT_PROTOTYPES */
		02835 typedef void (APIENTRY* PFNGLMULTIMODEDRAWARRAYSIBMPROC) (GLenum mode, const GLint* first, const GLsizei* count, GLsizei primcount, GLint modestride);
	02836 typedef void (APIENTRY* PFNGLMULTIMODEDRAWELEMENTSIBMPROC) (const GLenum* mode, const GLsizei* count, GLenum type, const GLvoid** indices, GLsizei primcount, GLint modestride);
	02837 #endif
		02838
		02839 #ifndef GL_IBM_vertex_array_lists
		02840 #define GL_IBM_vertex_array_lists 1
		02841 #ifdef GL_GLEXT_PROTOTYPES
		02842 extern void APIENTRY glColorPointerListIBM(GLint, GLenum, GLint, const GLvoid**, GLint);
	02843 extern void APIENTRY glSecondaryColorPointerListIBM(GLint, GLenum, GLint, const GLvoid**, GLint);
	02844 extern void APIENTRY glEdgeFlagPointerListIBM(GLint, const GLboolean**, GLint);
	02845 extern void APIENTRY glFogCoordPointerListIBM(GLenum, GLint, const GLvoid**, GLint);
	02846 extern void APIENTRY glIndexPointerListIBM(GLenum, GLint, const GLvoid**, GLint);
	02847 extern void APIENTRY glNormalPointerListIBM(GLenum, GLint, const GLvoid**, GLint);
	02848 extern void APIENTRY glTexCoordPointerListIBM(GLint, GLenum, GLint, const GLvoid**, GLint);
	02849 extern void APIENTRY glVertexPointerListIBM(GLint, GLenum, GLint, const GLvoid**, GLint);
	02850 #endif /* GL_GLEXT_PROTOTYPES */
		02851 typedef void (APIENTRY* PFNGLCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02852 typedef void (APIENTRY* PFNGLSECONDARYCOLORPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02853 typedef void (APIENTRY* PFNGLEDGEFLAGPOINTERLISTIBMPROC) (GLint stride, const GLboolean** pointer, GLint ptrstride);
	02854 typedef void (APIENTRY* PFNGLFOGCOORDPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02855 typedef void (APIENTRY* PFNGLINDEXPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02856 typedef void (APIENTRY* PFNGLNORMALPOINTERLISTIBMPROC) (GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02857 typedef void (APIENTRY* PFNGLTEXCOORDPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02858 typedef void (APIENTRY* PFNGLVERTEXPOINTERLISTIBMPROC) (GLint size, GLenum type, GLint stride, const GLvoid** pointer, GLint ptrstride);
	02859 #endif
		02860
		02861 #ifndef GL_SGIX_subsample
		02862 #define GL_SGIX_subsample 1
		02863 #endif
		02864
		02865 #ifndef GL_SGIX_ycrcba
		02866 #define GL_SGIX_ycrcba 1
		02867 #endif
		02868
		02869 #ifndef GL_SGIX_ycrcb_subsample
		02870 #define GL_SGIX_ycrcb_subsample 1
		02871 #endif
		02872
		02873 #ifndef GL_SGIX_depth_pass_instrument
		02874 #define GL_SGIX_depth_pass_instrument 1
		02875 #endif
		02876
		02877 #ifndef GL_3DFX_texture_compression_FXT1
		02878 #define GL_3DFX_texture_compression_FXT1 1
		02879 #endif
		02880
		02881 #ifndef GL_3DFX_multisample
		02882 #define GL_3DFX_multisample 1
		02883 #endif
		02884
		02885 #ifndef GL_3DFX_tbuffer
		02886 #define GL_3DFX_tbuffer 1
		02887 #ifdef GL_GLEXT_PROTOTYPES
		02888 extern void APIENTRY glTbufferMask3DFX(GLuint);
	02889 #endif /* GL_GLEXT_PROTOTYPES */
		02890 typedef void (APIENTRY* PFNGLTBUFFERMASK3DFXPROC) (GLuint mask);
	02891 #endif
		02892
		02893 #ifndef GL_EXT_multisample
		02894 #define GL_EXT_multisample 1
		02895 #ifdef GL_GLEXT_PROTOTYPES
		02896 extern void APIENTRY glSampleMaskEXT(GLclampf, GLboolean);
	02897 extern void APIENTRY glSamplePatternEXT(GLenum);
	02898 #endif /* GL_GLEXT_PROTOTYPES */
		02899 typedef void (APIENTRY* PFNGLSAMPLEMASKEXTPROC) (GLclampf value, GLboolean invert);
	02900 typedef void (APIENTRY* PFNGLSAMPLEPATTERNEXTPROC) (GLenum pattern);
	02901 #endif
		02902
		02903 #ifndef GL_SGI_vertex_preclip
		02904 #define GL_SGI_vertex_preclip 1
		02905 #endif
		02906
		02907 #ifndef GL_SGIX_convolution_accuracy
		02908 #define GL_SGIX_convolution_accuracy 1
		02909 #endif
		02910
		02911 #ifndef GL_SGIX_resample
		02912 #define GL_SGIX_resample 1
		02913 #endif
		02914
		02915 #ifndef GL_SGIS_point_line_texgen
		02916 #define GL_SGIS_point_line_texgen 1
		02917 #endif
		02918
		02919 #ifndef GL_SGIS_texture_color_mask
		02920 #define GL_SGIS_texture_color_mask 1
		02921 #ifdef GL_GLEXT_PROTOTYPES
		02922 extern void APIENTRY glTextureColorMaskSGIS(GLboolean, GLboolean, GLboolean, GLboolean);
	02923 #endif /* GL_GLEXT_PROTOTYPES */
		02924 typedef void (APIENTRY* PFNGLTEXTURECOLORMASKSGISPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	02925 #endif
		02926
		02927
		02928
		02929 /* added by Cass -- this part will be auto-generated in the future*/
		02930
		02931
		02932 /* Extensions */
		02933 #define GL_ARB_texture_border_clamp       1
		02934 #define GL_NV_evaluators                  1
		02935 #define GL_NV_fence                                               1
		02936 #define GL_NV_packed_depth_stencil                1
		02937 #define GL_NV_register_combiners2         1
		02938 #define GL_NV_texture_rectangle           1
		02939 #define GL_NV_texture_shader              1
		02940 #define GL_NV_vertex_program              1
		02941
		02942 /* ARB_texture_border_clamp */
		02943 #define GL_CLAMP_TO_BORDER_ARB            0x812D
		02944
		02945 /* NV_vertex_program */
		02946 #define GL_VERTEX_PROGRAM_NV              0x8620
		02947 #define GL_VERTEX_STATE_PROGRAM_NV        0x8621
		02948 #define GL_ATTRIB_ARRAY_SIZE_NV           0x8623
		02949 #define GL_ATTRIB_ARRAY_STRIDE_NV         0x8624
		02950 #define GL_ATTRIB_ARRAY_TYPE_NV           0x8625
		02951 #define GL_CURRENT_ATTRIB_NV              0x8626
		02952 #define GL_PROGRAM_LENGTH_NV              0x8627
		02953 #define GL_PROGRAM_STRING_NV              0x8628
		02954 #define GL_MODELVIEW_PROJECTION_NV        0x8629
		02955 #define GL_IDENTITY_NV                    0x862A
		02956 #define GL_INVERSE_NV                     0x862B
		02957 #define GL_TRANSPOSE_NV                   0x862C
		02958 #define GL_INVERSE_TRANSPOSE_NV           0x862D
		02959 #define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
		02960 #define GL_MAX_TRACK_MATRICES_NV          0x862F
		02961 #define GL_MATRIX0_NV                     0x8630
		02962 #define GL_MATRIX1_NV                     0x8631
		02963 #define GL_MATRIX2_NV                     0x8632
		02964 #define GL_MATRIX3_NV                     0x8633
		02965 #define GL_MATRIX4_NV                     0x8634
		02966 #define GL_MATRIX5_NV                     0x8635
		02967 #define GL_MATRIX6_NV                     0x8636
		02968 #define GL_MATRIX7_NV                     0x8637
		02969 #define GL_CURRENT_MATRIX_STACK_DEPTH_NV  0x8640
		02970 #define GL_CURRENT_MATRIX_NV              0x8641
		02971 #define GL_VERTEX_PROGRAM_POINT_SIZE_NV   0x8642
		02972 #define GL_VERTEX_PROGRAM_TWO_SIDE_NV     0x8643
		02973 #define GL_PROGRAM_PARAMETER_NV           0x8644
		02974 #define GL_ATTRIB_ARRAY_POINTER_NV        0x8645
		02975 #define GL_PROGRAM_TARGET_NV              0x8646
		02976 #define GL_PROGRAM_RESIDENT_NV            0x8647
		02977 #define GL_TRACK_MATRIX_NV                0x8648
		02978 #define GL_TRACK_MATRIX_TRANSFORM_NV      0x8649
		02979 #define GL_VERTEX_PROGRAM_BINDING_NV      0x864A
		02980 #define GL_PROGRAM_ERROR_POSITION_NV      0x864B
		02981 #define GL_VERTEX_ATTRIB_ARRAY0_NV        0x8650
		02982 #define GL_VERTEX_ATTRIB_ARRAY1_NV        0x8651
		02983 #define GL_VERTEX_ATTRIB_ARRAY2_NV        0x8652
		02984 #define GL_VERTEX_ATTRIB_ARRAY3_NV        0x8653
		02985 #define GL_VERTEX_ATTRIB_ARRAY4_NV        0x8654
		02986 #define GL_VERTEX_ATTRIB_ARRAY5_NV        0x8655
		02987 #define GL_VERTEX_ATTRIB_ARRAY6_NV        0x8656
		02988 #define GL_VERTEX_ATTRIB_ARRAY7_NV        0x8657
		02989 #define GL_VERTEX_ATTRIB_ARRAY8_NV        0x8658
		02990 #define GL_VERTEX_ATTRIB_ARRAY9_NV        0x8659
		02991 #define GL_VERTEX_ATTRIB_ARRAY10_NV       0x865A
		02992 #define GL_VERTEX_ATTRIB_ARRAY11_NV       0x865B
		02993 #define GL_VERTEX_ATTRIB_ARRAY12_NV       0x865C
		02994 #define GL_VERTEX_ATTRIB_ARRAY13_NV       0x865D
		02995 #define GL_VERTEX_ATTRIB_ARRAY14_NV       0x865E
		02996 #define GL_VERTEX_ATTRIB_ARRAY15_NV       0x865F
		02997 #define GL_MAP1_VERTEX_ATTRIB0_4_NV       0x8660
		02998 #define GL_MAP1_VERTEX_ATTRIB1_4_NV       0x8661
		02999 #define GL_MAP1_VERTEX_ATTRIB2_4_NV       0x8662
		03000 #define GL_MAP1_VERTEX_ATTRIB3_4_NV       0x8663
		03001 #define GL_MAP1_VERTEX_ATTRIB4_4_NV       0x8664
		03002 #define GL_MAP1_VERTEX_ATTRIB5_4_NV       0x8665
		03003 #define GL_MAP1_VERTEX_ATTRIB6_4_NV       0x8666
		03004 #define GL_MAP1_VERTEX_ATTRIB7_4_NV       0x8667
		03005 #define GL_MAP1_VERTEX_ATTRIB8_4_NV       0x8668
		03006 #define GL_MAP1_VERTEX_ATTRIB9_4_NV       0x8669
		03007 #define GL_MAP1_VERTEX_ATTRIB10_4_NV      0x866A
		03008 #define GL_MAP1_VERTEX_ATTRIB11_4_NV      0x866B
		03009 #define GL_MAP1_VERTEX_ATTRIB12_4_NV      0x866C
		03010 #define GL_MAP1_VERTEX_ATTRIB13_4_NV      0x866D
		03011 #define GL_MAP1_VERTEX_ATTRIB14_4_NV      0x866E
		03012 #define GL_MAP1_VERTEX_ATTRIB15_4_NV      0x866F
		03013 #define GL_MAP2_VERTEX_ATTRIB0_4_NV       0x8670
		03014 #define GL_MAP2_VERTEX_ATTRIB1_4_NV       0x8671
		03015 #define GL_MAP2_VERTEX_ATTRIB2_4_NV       0x8672
		03016 #define GL_MAP2_VERTEX_ATTRIB3_4_NV       0x8673
		03017 #define GL_MAP2_VERTEX_ATTRIB4_4_NV       0x8674
		03018 #define GL_MAP2_VERTEX_ATTRIB5_4_NV       0x8675
		03019 #define GL_MAP2_VERTEX_ATTRIB6_4_NV       0x8676
		03020 #define GL_MAP2_VERTEX_ATTRIB7_4_NV       0x8677
		03021 #define GL_MAP2_VERTEX_ATTRIB8_4_NV       0x8678
		03022 #define GL_MAP2_VERTEX_ATTRIB9_4_NV       0x8679
		03023 #define GL_MAP2_VERTEX_ATTRIB10_4_NV      0x867A
		03024 #define GL_MAP2_VERTEX_ATTRIB11_4_NV      0x867B
		03025 #define GL_MAP2_VERTEX_ATTRIB12_4_NV      0x867C
		03026 #define GL_MAP2_VERTEX_ATTRIB13_4_NV      0x867D
		03027 #define GL_MAP2_VERTEX_ATTRIB14_4_NV      0x867E
		03028 #define GL_MAP2_VERTEX_ATTRIB15_4_NV      0x867F
		03029
		03030 /* NV_evaluators */
		03031 #define GL_EVAL_2D_NV                     0x86C0
		03032 #define GL_EVAL_TRIANGULAR_2D_NV          0x86C1
		03033 #define GL_MAP_TESSELLATION_NV            0x86C2
		03034 #define GL_MAP_ATTRIB_U_ORDER_NV          0x86C3
		03035 #define GL_MAP_ATTRIB_V_ORDER_NV          0x86C4
		03036 #define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
		03037 #define GL_EVAL_VERTEX_ATTRIB0_NV         0x86C6
		03038 #define GL_EVAL_VERTEX_ATTRIB1_NV         0x86C7
		03039 #define GL_EVAL_VERTEX_ATTRIB2_NV         0x86C8
		03040 #define GL_EVAL_VERTEX_ATTRIB3_NV         0x86C9
		03041 #define GL_EVAL_VERTEX_ATTRIB4_NV         0x86CA
		03042 #define GL_EVAL_VERTEX_ATTRIB5_NV         0x86CB
		03043 #define GL_EVAL_VERTEX_ATTRIB6_NV         0x86CC
		03044 #define GL_EVAL_VERTEX_ATTRIB7_NV         0x86CD
		03045 #define GL_EVAL_VERTEX_ATTRIB8_NV         0x86CE
		03046 #define GL_EVAL_VERTEX_ATTRIB9_NV         0x86CF
		03047 #define GL_EVAL_VERTEX_ATTRIB10_NV        0x86D0
		03048 #define GL_EVAL_VERTEX_ATTRIB11_NV        0x86D1
		03049 #define GL_EVAL_VERTEX_ATTRIB12_NV        0x86D2
		03050 #define GL_EVAL_VERTEX_ATTRIB13_NV        0x86D3
		03051 #define GL_EVAL_VERTEX_ATTRIB14_NV        0x86D4
		03052 #define GL_EVAL_VERTEX_ATTRIB15_NV        0x86D5
		03053 #define GL_MAX_MAP_TESSELLATION_NV        0x86D6
		03054 #define GL_MAX_RATIONAL_EVAL_ORDER_NV     0x86D7
		03055
		03056 /* NV_fence */
		03057 #define GL_ALL_COMPLETED_NV               0x84F2
		03058 #define GL_FENCE_STATUS_NV                0x84F3
		03059 #define GL_FENCE_CONDITION_NV             0x84F4
		03060
		03061 /* NV_texture_rectangle */
		03062 #define GL_TEXTURE_RECTANGLE_NV           0x84F5
		03063 #define GL_TEXTURE_BINDING_RECTANGLE_NV   0x84F6
		03064 #define GL_PROXY_TEXTURE_RECTANGLE_NV     0x84F7
		03065 #define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV  0x84F8
		03066
		03067 /* NV_texture_shader */
		03068 #define GL_OFFSET_TEXTURE_RECTANGLE_NV    0x864C
		03069 #define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
		03070 #define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
		03071 #define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
		03072 #define GL_UNSIGNED_INT_S8_S8_8_8_NV      0x86DA
		03073 #define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV  0x86DB
		03074 #define GL_DSDT_MAG_INTENSITY_NV          0x86DC
		03075 #define GL_SHADER_CONSISTENT_NV           0x86DD
		03076 #define GL_TEXTURE_SHADER_NV              0x86DE
		03077 #define GL_SHADER_OPERATION_NV            0x86DF
		03078 #define GL_CULL_MODES_NV                  0x86E0
		03079 #define GL_OFFSET_TEXTURE_MATRIX_NV       0x86E1
		03080 #define GL_OFFSET_TEXTURE_SCALE_NV        0x86E2
		03081 #define GL_OFFSET_TEXTURE_BIAS_NV         0x86E3
		03082 #define GL_OFFSET_TEXTURE_2D_MATRIX_NV    GL_OFFSET_TEXTURE_MATRIX_NV
		03083 #define GL_OFFSET_TEXTURE_2D_SCALE_NV     GL_OFFSET_TEXTURE_SCALE_NV
		03084 #define GL_OFFSET_TEXTURE_2D_BIAS_NV      GL_OFFSET_TEXTURE_BIAS_NV
		03085 #define GL_PREVIOUS_TEXTURE_INPUT_NV      0x86E4
		03086 #define GL_CONST_EYE_NV                   0x86E5
		03087 #define GL_PASS_THROUGH_NV                0x86E6
		03088 #define GL_CULL_FRAGMENT_NV               0x86E7
		03089 #define GL_OFFSET_TEXTURE_2D_NV           0x86E8
		03090 #define GL_DEPENDENT_AR_TEXTURE_2D_NV     0x86E9
		03091 #define GL_DEPENDENT_GB_TEXTURE_2D_NV     0x86EA
		03092 #define GL_DOT_PRODUCT_NV                 0x86EC
		03093 #define GL_DOT_PRODUCT_DEPTH_REPLACE_NV   0x86ED
		03094 #define GL_DOT_PRODUCT_TEXTURE_2D_NV      0x86EE
		03095 #define GL_DOT_PRODUCT_TEXTURE_3D_NV      0x86EF
		03096 #define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
		03097 #define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
		03098 #define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
		03099 #define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
		03100 #define GL_HILO_NV                        0x86F4
		03101 #define GL_DSDT_NV                        0x86F5
		03102 #define GL_DSDT_MAG_NV                    0x86F6
		03103 #define GL_DSDT_MAG_VIB_NV                0x86F7
		03104 #define GL_HILO16_NV                      0x86F8
		03105 #define GL_SIGNED_HILO_NV                 0x86F9
		03106 #define GL_SIGNED_HILO16_NV               0x86FA
		03107 #define GL_SIGNED_RGBA_NV                 0x86FB
		03108 #define GL_SIGNED_RGBA8_NV                0x86FC
		03109 #define GL_SIGNED_RGB_NV                  0x86FE
		03110 #define GL_SIGNED_RGB8_NV                 0x86FF
		03111 #define GL_SIGNED_LUMINANCE_NV            0x8701
		03112 #define GL_SIGNED_LUMINANCE8_NV           0x8702
		03113 #define GL_SIGNED_LUMINANCE_ALPHA_NV      0x8703
		03114 #define GL_SIGNED_LUMINANCE8_ALPHA8_NV    0x8704
		03115 #define GL_SIGNED_ALPHA_NV                0x8705
		03116 #define GL_SIGNED_ALPHA8_NV               0x8706
		03117 #define GL_SIGNED_INTENSITY_NV            0x8707
		03118 #define GL_SIGNED_INTENSITY8_NV           0x8708
		03119 #define GL_DSDT8_NV                       0x8709
		03120 #define GL_DSDT8_MAG8_NV                  0x870A
		03121 #define GL_DSDT8_MAG8_INTENSITY8_NV       0x870B
		03122 #define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV   0x870C
		03123 #define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
		03124 #define GL_HI_SCALE_NV                    0x870E
		03125 #define GL_LO_SCALE_NV                    0x870F
		03126 #define GL_DS_SCALE_NV                    0x8710
		03127 #define GL_DT_SCALE_NV                    0x8711
		03128 #define GL_MAGNITUDE_SCALE_NV             0x8712
		03129 #define GL_VIBRANCE_SCALE_NV              0x8713
		03130 #define GL_HI_BIAS_NV                     0x8714
		03131 #define GL_LO_BIAS_NV                     0x8715
		03132 #define GL_DS_BIAS_NV                     0x8716
		03133 #define GL_DT_BIAS_NV                     0x8717
		03134 #define GL_MAGNITUDE_BIAS_NV              0x8718
		03135 #define GL_VIBRANCE_BIAS_NV               0x8719
		03136 #define GL_TEXTURE_BORDER_VALUES_NV       0x871A
		03137 #define GL_TEXTURE_HI_SIZE_NV             0x871B
		03138 #define GL_TEXTURE_LO_SIZE_NV             0x871C
		03139 #define GL_TEXTURE_DS_SIZE_NV             0x871D
		03140 #define GL_TEXTURE_DT_SIZE_NV             0x871E
		03141 #define GL_TEXTURE_MAG_SIZE_NV            0x871F
		03142
		03143 /* NV_register_combiners2 */
		03144 #define GL_PER_STAGE_CONSTANTS_NV         0x8535
		03145
		03146 /* NV_packed_depth_stencil */
		03147 #define GL_DEPTH_STENCIL_NV               0x84F9
		03148 #define GL_UNSIGNED_INT_24_8_NV           0x84FA
		03149
		03150
		03151 /* NV_vertex_program */
		03152 typedef GLboolean(APIENTRY* PFNGLAREPROGRAMSRESIDENTNVPROC) (GLsizei n, const GLuint* programs, GLboolean* residences);
	03153 typedef void (APIENTRY* PFNGLBINDPROGRAMNVPROC) (GLenum target, GLuint id);
	03154 typedef void (APIENTRY* PFNGLDELETEPROGRAMSNVPROC) (GLsizei n, const GLuint* programs);
	03155 typedef void (APIENTRY* PFNGLEXECUTEPROGRAMNVPROC) (GLenum target, GLuint id, const GLfloat* params);
	03156 typedef void (APIENTRY* PFNGLGENPROGRAMSNVPROC) (GLsizei n, GLuint* programs);
	03157 typedef void (APIENTRY* PFNGLGETPROGRAMPARAMETERDVNVPROC) (GLenum target, GLuint index, GLenum pname, GLdouble* params);
	03158 typedef void (APIENTRY* PFNGLGETPROGRAMPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat* params);
	03159 typedef void (APIENTRY* PFNGLGETPROGRAMIVNVPROC) (GLuint id, GLenum pname, GLint* params);
	03160 typedef void (APIENTRY* PFNGLGETPROGRAMSTRINGNVPROC) (GLuint id, GLenum pname, GLubyte* program);
	03161 typedef void (APIENTRY* PFNGLGETTRACKMATRIXIVNVPROC) (GLenum target, GLuint address, GLenum pname, GLint* params);
	03162 typedef void (APIENTRY* PFNGLGETVERTEXATTRIBDVNVPROC) (GLuint index, GLenum pname, GLdouble* params);
	03163 typedef void (APIENTRY* PFNGLGETVERTEXATTRIBFVNVPROC) (GLuint index, GLenum pname, GLfloat* params);
	03164 typedef void (APIENTRY* PFNGLGETVERTEXATTRIBIVNVPROC) (GLuint index, GLenum pname, GLint* params);
	03165 typedef void (APIENTRY* PFNGLGETVERTEXATTRIBPOINTERVNVPROC) (GLuint index, GLenum pname, GLvoid** pointer);
	03166 typedef GLboolean(APIENTRY* PFNGLISPROGRAMNVPROC) (GLuint id);
	03167 typedef void (APIENTRY* PFNGLLOADPROGRAMNVPROC) (GLenum target, GLuint id, GLsizei len, const GLubyte* program);
	03168 typedef void (APIENTRY* PFNGLPROGRAMPARAMETER4DNVPROC) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	03169 typedef void (APIENTRY* PFNGLPROGRAMPARAMETER4DVNVPROC) (GLenum target, GLuint index, const GLdouble* v);
	03170 typedef void (APIENTRY* PFNGLPROGRAMPARAMETER4FNVPROC) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	03171 typedef void (APIENTRY* PFNGLPROGRAMPARAMETER4FVNVPROC) (GLenum target, GLuint index, const GLfloat* v);
	03172 typedef void (APIENTRY* PFNGLPROGRAMPARAMETERS4DVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLdouble* v);
	03173 typedef void (APIENTRY* PFNGLPROGRAMPARAMETERS4FVNVPROC) (GLenum target, GLuint index, GLsizei count, const GLfloat* v);
	03174 typedef void (APIENTRY* PFNGLREQUESTRESIDENTPROGRAMSNVPROC) (GLsizei n, const GLuint* programs);
	03175 typedef void (APIENTRY* PFNGLTRACKMATRIXNVPROC) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
	03176 typedef void (APIENTRY* PFNGLVERTEXATTRIBPOINTERNVPROC) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid* pointer);
	03177 typedef void (APIENTRY* PFNGLVERTEXATTRIB1DNVPROC) (GLuint index, GLdouble x);
	03178 typedef void (APIENTRY* PFNGLVERTEXATTRIB1DVNVPROC) (GLuint index, const GLdouble* v);
	03179 typedef void (APIENTRY* PFNGLVERTEXATTRIB1FNVPROC) (GLuint index, GLfloat x);
	03180 typedef void (APIENTRY* PFNGLVERTEXATTRIB1FVNVPROC) (GLuint index, const GLfloat* v);
	03181 typedef void (APIENTRY* PFNGLVERTEXATTRIB1SNVPROC) (GLuint index, GLshort x);
	03182 typedef void (APIENTRY* PFNGLVERTEXATTRIB1SVNVPROC) (GLuint index, const GLshort* v);
	03183 typedef void (APIENTRY* PFNGLVERTEXATTRIB2DNVPROC) (GLuint index, GLdouble x, GLdouble y);
	03184 typedef void (APIENTRY* PFNGLVERTEXATTRIB2DVNVPROC) (GLuint index, const GLdouble* v);
	03185 typedef void (APIENTRY* PFNGLVERTEXATTRIB2FNVPROC) (GLuint index, GLfloat x, GLfloat y);
	03186 typedef void (APIENTRY* PFNGLVERTEXATTRIB2FVNVPROC) (GLuint index, const GLfloat* v);
	03187 typedef void (APIENTRY* PFNGLVERTEXATTRIB2SNVPROC) (GLuint index, GLshort x, GLshort y);
	03188 typedef void (APIENTRY* PFNGLVERTEXATTRIB2SVNVPROC) (GLuint index, const GLshort* v);
	03189 typedef void (APIENTRY* PFNGLVERTEXATTRIB3DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	03190 typedef void (APIENTRY* PFNGLVERTEXATTRIB3DVNVPROC) (GLuint index, const GLdouble* v);
	03191 typedef void (APIENTRY* PFNGLVERTEXATTRIB3FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	03192 typedef void (APIENTRY* PFNGLVERTEXATTRIB3FVNVPROC) (GLuint index, const GLfloat* v);
	03193 typedef void (APIENTRY* PFNGLVERTEXATTRIB3SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
	03194 typedef void (APIENTRY* PFNGLVERTEXATTRIB3SVNVPROC) (GLuint index, const GLshort* v);
	03195 typedef void (APIENTRY* PFNGLVERTEXATTRIB4DNVPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	03196 typedef void (APIENTRY* PFNGLVERTEXATTRIB4DVNVPROC) (GLuint index, const GLdouble* v);
	03197 typedef void (APIENTRY* PFNGLVERTEXATTRIB4FNVPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	03198 typedef void (APIENTRY* PFNGLVERTEXATTRIB4FVNVPROC) (GLuint index, const GLfloat* v);
	03199 typedef void (APIENTRY* PFNGLVERTEXATTRIB4SNVPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	03200 typedef void (APIENTRY* PFNGLVERTEXATTRIB4SVNVPROC) (GLuint index, const GLshort* v);
	03201 typedef void (APIENTRY* PFNGLVERTEXATTRIB4UBVNVPROC) (GLuint index, const GLubyte* v);
	03202 typedef void (APIENTRY* PFNGLVERTEXATTRIBS1DVNVPROC) (GLuint index, GLsizei count, const GLdouble* v);
	03203 typedef void (APIENTRY* PFNGLVERTEXATTRIBS1FVNVPROC) (GLuint index, GLsizei count, const GLfloat* v);
	03204 typedef void (APIENTRY* PFNGLVERTEXATTRIBS1SVNVPROC) (GLuint index, GLsizei count, const GLshort* v);
	03205 typedef void (APIENTRY* PFNGLVERTEXATTRIBS2DVNVPROC) (GLuint index, GLsizei count, const GLdouble* v);
	03206 typedef void (APIENTRY* PFNGLVERTEXATTRIBS2FVNVPROC) (GLuint index, GLsizei count, const GLfloat* v);
	03207 typedef void (APIENTRY* PFNGLVERTEXATTRIBS2SVNVPROC) (GLuint index, GLsizei count, const GLshort* v);
	03208 typedef void (APIENTRY* PFNGLVERTEXATTRIBS3DVNVPROC) (GLuint index, GLsizei count, const GLdouble* v);
	03209 typedef void (APIENTRY* PFNGLVERTEXATTRIBS3FVNVPROC) (GLuint index, GLsizei count, const GLfloat* v);
	03210 typedef void (APIENTRY* PFNGLVERTEXATTRIBS3SVNVPROC) (GLuint index, GLsizei count, const GLshort* v);
	03211 typedef void (APIENTRY* PFNGLVERTEXATTRIBS4DVNVPROC) (GLuint index, GLsizei count, const GLdouble* v);
	03212 typedef void (APIENTRY* PFNGLVERTEXATTRIBS4FVNVPROC) (GLuint index, GLsizei count, const GLfloat* v);
	03213 typedef void (APIENTRY* PFNGLVERTEXATTRIBS4SVNVPROC) (GLuint index, GLsizei count, const GLshort* v);
	03214 typedef void (APIENTRY* PFNGLVERTEXATTRIBS4UBVNVPROC) (GLuint index, GLsizei count, const GLubyte* v);
	03215
		03216 /* NV_evaluators */
		03217 typedef void (APIENTRY* PFNGLMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid* points);
	03218 typedef void (APIENTRY* PFNGLMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, const GLint* params);
	03219 typedef void (APIENTRY* PFNGLMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, const GLfloat* params);
	03220 typedef void (APIENTRY* PFNGLGETMAPCONTROLPOINTSNVPROC) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid* points);
	03221 typedef void (APIENTRY* PFNGLGETMAPPARAMETERIVNVPROC) (GLenum target, GLenum pname, GLint* params);
	03222 typedef void (APIENTRY* PFNGLGETMAPPARAMETERFVNVPROC) (GLenum target, GLenum pname, GLfloat* params);
	03223 typedef void (APIENTRY* PFNGLGETMAPATTRIBPARAMETERIVNVPROC) (GLenum target, GLuint index, GLenum pname, GLint* params);
	03224 typedef void (APIENTRY* PFNGLGETMAPATTRIBPARAMETERFVNVPROC) (GLenum target, GLuint index, GLenum pname, GLfloat* params);
	03225 typedef void (APIENTRY* PFNGLEVALMAPSNVPROC) (GLenum target, GLenum mode);
	03226
		03227 /* NV_fence */
		03228 typedef void (APIENTRY* PFNGLDELETEFENCESNVPROC) (GLsizei n, const GLuint* fences);
	03229 typedef void (APIENTRY* PFNGLGENFENCESNVPROC) (GLsizei n, GLuint* fences);
	03230 typedef GLboolean(APIENTRY* PFNGLISFENCENVPROC) (GLuint fence);
	03231 typedef GLboolean(APIENTRY* PFNGLTESTFENCENVPROC) (GLuint fence);
	03232 typedef void (APIENTRY* PFNGLGETFENCEIVNVPROC) (GLuint fence, GLenum pname, GLint* params);
	03233 typedef void (APIENTRY* PFNGLFINISHFENCENVPROC) (GLuint fence);
	03234 typedef void (APIENTRY* PFNGLSETFENCENVPROC) (GLuint fence, GLenum condition);
	03235
		03236
		03237 /* NV_register_combiners2 */
		03238 typedef void (APIENTRY* PFNGLCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, const GLfloat* params);
	03239 typedef void (APIENTRY* PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) (GLenum stage, GLenum pname, GLfloat* params);
	03240
		03241
		03242 #ifdef __cplusplus
		03243 }
03244 #endif
03245
03246 #endif
03247