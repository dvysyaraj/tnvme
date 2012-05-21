/*
 * Copyright (c) 2011, Intel Corporation.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "tnvme.h"
#include "../Exception/frmwkEx.h"
#include "grpNVMWriteUncorrectCmd.h"
#include "identify_r10b.h"

namespace GrpNVMWriteUncorrectCmd {


GrpNVMWriteUncorrectCmd::GrpNVMWriteUncorrectCmd(size_t grpNum, SpecRev specRev,
    ErrorRegs errRegs, int fd) :
    Group(grpNum, specRev, "GrpNVMWriteUncorrectCmd",
        "NVM cmd set compare test cases")
{
    // For complete details about the APPEND_TEST_AT_?LEVEL() macros:
    // "https://github.com/nvmecompliance/tnvme/wiki/Test-Numbering" and
    // "https://github.com/nvmecompliance/tnvme/wiki/Test-Strategy
    switch (mSpecRev) {
    case SPECREV_10b:
        APPEND_TEST_AT_XLEVEL(Identify_r10b, fd, GrpNVMWriteUncorrectCmd, errRegs)
        break;

    default:
    case SPECREVTYPE_FENCE:
        throw FrmwkEx(HERE, "Object created with unknown SpecRev=%d", specRev);
    }
}


GrpNVMWriteUncorrectCmd::~GrpNVMWriteUncorrectCmd()
{
    // mTests deallocated in parent
}

}   // namespace
