#include "MyArchRegisterInfo.h"
#include "MyArch.h"
#include "MyArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "MyArchGenRegisterInfo.inc"

MyArchRegisterInfo::MyArchRegisterInfo() : MyArchGenRegisterInfo(MyArch::R0) {
  MYARCH_DUMP_GREEN
}

const MCPhysReg *
MyArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  MYARCH_DUMP_GREEN
  return CSR_MyArch_SaveList;
}

BitVector MyArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  MYARCH_DUMP_GREEN
  MyArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(MyArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(MyArch::R2);
  }
  return Reserved;
}

bool MyArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool MyArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                             int SPAdj, unsigned FIOperandNum,
                                             RegScavenger *RS) const {
  MYARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register MyArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  MYARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? MyArch::R2 : MyArch::R1;
}

const uint32_t *
MyArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                         CallingConv::ID CC) const {
  MYARCH_DUMP_GREEN
  return CSR_MyArch_RegMask;
}
