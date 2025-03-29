add_llvm_component_library(LLVMMyArchDesc
  MyArchMCTargetDesc.cpp
  MyArchMCAsmInfo.cpp

  LINK_COMPONENTS
  MC
  Support
  MyArchInfo

  ADD_TO_COMPONENT
  MyArch
 )
