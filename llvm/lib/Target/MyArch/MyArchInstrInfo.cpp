#include "MyArchInstrInfo.h"
#include "MyArch.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "MyArchGenInstrInfo.inc"

#define DEBUG_TYPE "MyArch-inst-info"

MyArchInstrInfo::MyArchInstrInfo() : MyArchGenInstrInfo() { MYARCH_DUMP_GREEN }
