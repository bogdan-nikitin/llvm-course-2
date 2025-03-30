#ifndef LLVM_LIB_TARGET_MYARCH_MYARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_MYARCH_MYARCHTARGETMACHINE_H

#include "MyArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheMyArchTarget;

class MyArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  MyArchSubtarget Subtarget;

public:
  MyArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT, bool IsLittle);

  MyArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, const TargetOptions &Options,
                      std::optional<Reloc::Model> RM,
                      std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                      bool JIT);

  const MyArchSubtarget *getSubtargetImpl(const Function &) const override {
     MYARCH_DUMP_CYAN
     return &Subtarget;
   }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_MYARCH_MYARCHTARGETMACHINE_H
