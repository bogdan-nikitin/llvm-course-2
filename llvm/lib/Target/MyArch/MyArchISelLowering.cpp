#include "MyArch.h"
#include "MyArchISelLowering.h"
#include "MyArchRegisterInfo.h"
#include "MyArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "MyArch-lower"

using namespace llvm;

MyArchTargetLowering::MyArchTargetLowering(const TargetMachine &TM,
                                     const MyArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  MYARCH_DUMP_RED
  addRegisterClass(MVT::i32, &MyArch::GPRRegClass);
}

const char *MyArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  MYARCH_DUMP_RED
  switch (Opcode) {
  case MyArchISD::CALL:
    return "MyArchISD::CALL";
  case MyArchISD::RET:
    return "MyArchISD::RET";
  }
  return nullptr;
}
