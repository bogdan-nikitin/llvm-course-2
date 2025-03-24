#include "MyArch.h"
#include "TargetInfo/MyArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "MyArchGenRegisterInfo.inc"

static MCRegisterInfo *createMyArchMCRegisterInfo(const Triple &TT) {
  MYARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMyArchMCRegisterInfo(X, MyArch::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyArchTargetMC() {
  MYARCH_DUMP_MAGENTA
  Target &TheMyArchTarget = getTheMyArchTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMyArchTarget, createMyArchMCRegisterInfo);
}
