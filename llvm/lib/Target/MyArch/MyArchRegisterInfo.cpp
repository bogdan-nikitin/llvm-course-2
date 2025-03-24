#include "MyArch.h"
#include "MyArchFrameLowering.h"
#include "MyArchRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "MyArchGenRegisterInfo.inc"

MyArchRegisterInfo::MyArchRegisterInfo() : MyArchGenRegisterInfo(MyArch::R0) {
  MYARCH_DUMP_GREEN
}
