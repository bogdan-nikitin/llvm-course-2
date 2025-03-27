include "llvm/Target/Target.td"
include "MyArchRegisterInfo.td"
include "MyArchInstrInfo.td"
 
def MyArchInstrInfo : InstrInfo;
def MyArch : Target {
  let InstructionSet = MyArchInstrInfo;
}
