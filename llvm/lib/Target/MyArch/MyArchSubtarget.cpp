#include "MyArch.h"
#include "MyArchSubtarget.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "myarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "MyArchGenSubtargetInfo.inc"

MyArchSubtarget::MyArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : MyArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  MYARCH_DUMP_CYAN
}
