#include "MCTargetDesc/MyArchMCTargetDesc.h"
#include "MyArch.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class MyArchELFObjectWriter : public MCELFObjectTargetWriter {
public:
  MyArchELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_MYARCH,
                                /*HasRelocationAddend*/ true) {}

  ~MyArchELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned MyArchELFObjectWriter::getRelocType(MCContext &Ctx,
                                             const MCValue &Target,
                                             const MCFixup &Fixup,
                                             bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool MyArchELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                    const MCSymbol &,
                                                    unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createMyArchELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<MyArchELFObjectWriter>(Is64Bit, OSABI);
}
