/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file defines constants and macros for introspecting and
 *      manipulating CHIP versions.
 *
 *      The constants and macros defined here may be used to, for ,
 *      example, conditionally-compile older, newer, or changed CHIP
 *      APIs based on the CHIP version. For example:
 *
 *          @code
 *          #if CHIP_VERSION_CODE >= CHIP_VERSION_CODE_ENCODE(1, 5, 0)
 *              ...
 *          #else
 *              ...
 *          #endif
 *          @endcode
 *
 */

#pragma once

#define _CHIP_VERSION_CODE_MAJOR_WIDTH     8
#define _CHIP_VERSION_CODE_MINOR_WIDTH     8
#define _CHIP_VERSION_CODE_PATCH_WIDTH     8

#define _CHIP_VERSION_CODE_MAJOR_MASK     ((1 << _CHIP_VERSION_CODE_MAJOR_WIDTH)  - 1)
#define _CHIP_VERSION_CODE_MINOR_MASK     ((1 << _CHIP_VERSION_CODE_MINOR_WIDTH)  - 1)
#define _CHIP_VERSION_CODE_PATCH_MASK     ((1 << _CHIP_VERSION_CODE_PATCH_WIDTH)  - 1)

#define _CHIP_VERSION_CODE_MAJOR_SHIFT    24
#define _CHIP_VERSION_CODE_MINOR_SHIFT    16
#define _CHIP_VERSION_CODE_PATCH_SHIFT     8

/**
 *  @def CHIP_VERSION_CODE_ENCODE(major, minor, patch)
 *
 *  @brief
 *    Encode a CHIP version code from its constituent @a major, @a minor, and @a patch
 *    components.
 *
 *    This macro may be used in conjunction with CHIP_VERSION_CODE to, for
 *    example, conditionally-compile older, newer, or changed CHIP APIs based
 *    on the CHIP version. For example:
 *
 *        @code
 *        #if CHIP_VERSION_CODE >= CHIP_VERSION_CODE_ENCODE(1, 5, 0)
 *            ...
 *        #else
 *            ...
 *        #endif
 *        @endcode
 *
 */
#define CHIP_VERSION_CODE_ENCODE(major, minor, patch)                                       ((((major)  & _CHIP_VERSION_CODE_MAJOR_MASK)  << _CHIP_VERSION_CODE_MAJOR_SHIFT)  |      (((minor)  & _CHIP_VERSION_CODE_MINOR_MASK)  << _CHIP_VERSION_CODE_MINOR_SHIFT)  |      (((patch)  & _CHIP_VERSION_CODE_PATCH_MASK)  << _CHIP_VERSION_CODE_PATCH_SHIFT))

/**
 *  @def CHIP_VERSION_CODE_DECODE_MAJOR(code)
 *
 *  @brief
 *    Decode a CHIP major version component from a CHIP version @a code.
 *
 */
#define CHIP_VERSION_CODE_DECODE_MAJOR(code)  (((code) >> _CHIP_VERSION_CODE_MAJOR_SHIFT)  & _CHIP_VERSION_CODE_MAJOR_MASK)

/**
 *  @def CHIP_VERSION_CODE_DECODE_MINOR(code)
 *
 *  @brief
 *    Decode a CHIP minor version component from a CHIP version @a code.
 *
 */
#define CHIP_VERSION_CODE_DECODE_MINOR(code)  (((code) >> _CHIP_VERSION_CODE_MINOR_SHIFT)  & _CHIP_VERSION_CODE_MINOR_MASK)

/**
 *  @def CHIP_VERSION_CODE_DECODE_PATCH(code)
 *
 *  @brief
 *    Decode a CHIP patch version component from a CHIP version @a code.
 *
 */
#define CHIP_VERSION_CODE_DECODE_PATCH(code)  (((code) >> _CHIP_VERSION_CODE_PATCH_SHIFT)  & _CHIP_VERSION_CODE_PATCH_MASK)

/**
 *  @def CHIP_VERSION_MAJOR
 *
 *  @brief
 *    The CHIP version major component, as an unsigned integer.
 *
 */
#define CHIP_VERSION_MAJOR               0

/**
 *  @def CHIP_VERSION_MINOR
 *
 *  @brief
 *    The CHIP version minor component, as an unsigned integer.
 *
 */
#define CHIP_VERSION_MINOR               0

/**
 *  @def CHIP_VERSION_PATCH
 *
 *  @brief
 *    The CHIP version patch component, as an unsigned integer.
 *
 */
#define CHIP_VERSION_PATCH               0

/**
 *  @def CHIP_VERSION_EXTRA
 *
 *  @brief
 *    The CHIP version extra component, as a quoted C string.
 *
 */
#define CHIP_VERSION_EXTRA               ""

/**
 *  @def CHIP_VERSION_STRING
 *
 *  @brief
 *    The CHIP version, as a quoted C string.
 *
 */
#define CHIP_VERSION_STRING              "0.0.0"

/**
 *  @def CHIP_VERSION_CODE
 *
 *  @brief
 *    The CHIP version, including the major, minor, and patch components,
 *    encoded as an unsigned integer.
 *
 *    This macro may be used in conjunction with CHIP_VERSION_CODE_ENCODE
 *    to, for example, conditionally-compile older, newer, or changed CHIP
 *    APIs based on the CHIP version. For example:
 *
 *        @code
 *        #if CHIP_VERSION_CODE >= CHIP_VERSION_CODE_ENCODE(1, 5, 0)
 *            ...
 *        #else
 *            ...
 *        #endif
 *        @endcode
 *
 */
#define CHIP_VERSION_CODE   CHIP_VERSION_CODE_ENCODE(CHIP_VERSION_MAJOR, CHIP_VERSION_MINOR, CHIP_VERSION_PATCH)
