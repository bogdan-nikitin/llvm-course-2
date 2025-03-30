#ifndef LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createMyArchMCCodeEmitter(const MCInstrInfo &MCII,
                                         MCContext &Ctx);
MCAsmBackend *createMyArchAsmBackend(const Target &T,
                                     const MCSubtargetInfo &STI,
                                     const MCRegisterInfo &MRI,
                                     const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter>
createMyArchELFObjectWriter(bool Is64Bit, uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for MyArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "MyArchGenRegisterInfo.inc"

// Defines symbolic names for the MyArch instructions.
#define GET_INSTRINFO_ENUM
#include "MyArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_MYARCH_MCTARGETDESC_MYARCHMCTARGETDESC_H
