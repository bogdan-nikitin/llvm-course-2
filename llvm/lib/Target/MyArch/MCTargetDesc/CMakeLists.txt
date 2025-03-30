add_llvm_component_library(LLVMMyArchDesc
  MyArchMCTargetDesc.cpp
  MyArchMCAsmInfo.cpp
  MyArchInstPrinter.cpp
  MyArchMCCodeEmitter.cpp
  MyArchAsmBackend.cpp
  MyArchELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  MyArchInfo

  ADD_TO_COMPONENT
  MyArch
 )
