#include "enums.h"

#include <pybind11/pybind11.h>
#include <llvm/Demangle/MicrosoftDemangleNodes.h>
#include <llvm/Demangle/MicrosoftDemangle.h>

namespace py = pybind11;
namespace msdm = llvm::ms_demangle;

void define_enums(py::module &m) {
    py::enum_<msdm::Qualifiers>(m, "Qualifiers", py::arithmetic())
        .value("None_", msdm::Qualifiers::Q_None)
        .value("Const", msdm::Qualifiers::Q_Const)
        .value("Volatile", msdm::Qualifiers::Q_Volatile)
        .value("Far", msdm::Qualifiers::Q_Far)
        .value("Huge", msdm::Qualifiers::Q_Huge)
        .value("Unaligned", msdm::Qualifiers::Q_Unaligned)
        .value("Restrict", msdm::Qualifiers::Q_Restrict)
        .value("Pointer64", msdm::Qualifiers::Q_Pointer64);
    
    py::enum_<msdm::StorageClass>(m, "StorageClass")
        .value("None_", msdm::StorageClass::None)
        .value("PrivateStatic", msdm::StorageClass::PrivateStatic)
        .value("ProtectedStatic", msdm::StorageClass::ProtectedStatic)
        .value("PublicStatic", msdm::StorageClass::PublicStatic)
        .value("Global", msdm::StorageClass::Global)
        .value("FunctionLocalStatic", msdm::StorageClass::FunctionLocalStatic);

    py::enum_<msdm::PointerAffinity>(m, "PointerAffinity")
        .value("None_", msdm::PointerAffinity::None)
        .value("Pointer", msdm::PointerAffinity::Pointer)
        .value("Reference", msdm::PointerAffinity::Reference)
        .value("RValueReference", msdm::PointerAffinity::RValueReference);

    py::enum_<msdm::FunctionRefQualifier>(m, "FunctionRefQualifier")
        .value("None_", msdm::FunctionRefQualifier::None)
        .value("Reference", msdm::FunctionRefQualifier::Reference)
        .value("RValueReference", msdm::FunctionRefQualifier::RValueReference);

    py::enum_<msdm::CallingConv>(m, "CallingConv")
        .value("None_", msdm::CallingConv::None)
        .value("Cdecl", msdm::CallingConv::Cdecl)
        .value("Pascal", msdm::CallingConv::Pascal)
        .value("Thiscall", msdm::CallingConv::Thiscall)
        .value("Stdcall", msdm::CallingConv::Stdcall)
        .value("Fastcall", msdm::CallingConv::Fastcall)
        .value("Clrcall", msdm::CallingConv::Clrcall)
        .value("Eabi", msdm::CallingConv::Eabi)
        .value("Vectorcall", msdm::CallingConv::Vectorcall)
        .value("Regcall", msdm::CallingConv::Regcall)
        .value("Swift", msdm::CallingConv::Swift)
        .value("SwiftAsync", msdm::CallingConv::SwiftAsync);

    py::enum_<msdm::ReferenceKind>(m, "ReferenceKind")
        .value("None_", msdm::ReferenceKind::None)
        .value("LValueRef", msdm::ReferenceKind::LValueRef)
        .value("RValueRef", msdm::ReferenceKind::RValueRef);

    py::enum_<msdm::PrimitiveKind>(m, "PrimitiveKind")
        .value("Void", msdm::PrimitiveKind::Void)
        .value("Bool", msdm::PrimitiveKind::Bool)
        .value("Char", msdm::PrimitiveKind::Char)
        .value("Schar", msdm::PrimitiveKind::Schar)
        .value("Uchar", msdm::PrimitiveKind::Uchar)
        .value("Char8", msdm::PrimitiveKind::Char8)
        .value("Char16", msdm::PrimitiveKind::Char16)
        .value("Char32", msdm::PrimitiveKind::Char32)
        .value("Short", msdm::PrimitiveKind::Short)
        .value("Ushort", msdm::PrimitiveKind::Ushort)
        .value("Int", msdm::PrimitiveKind::Int)
        .value("Uint", msdm::PrimitiveKind::Uint)
        .value("Long", msdm::PrimitiveKind::Long)
        .value("Ulong", msdm::PrimitiveKind::Ulong)
        .value("Int64", msdm::PrimitiveKind::Int64)
        .value("Uint64", msdm::PrimitiveKind::Uint64)
        .value("Wchar", msdm::PrimitiveKind::Wchar)
        .value("Float", msdm::PrimitiveKind::Float)
        .value("Double", msdm::PrimitiveKind::Double)
        .value("Ldouble", msdm::PrimitiveKind::Ldouble)
        .value("Nullptr", msdm::PrimitiveKind::Nullptr);

    py::enum_<msdm::CharKind>(m, "CharKind")
        .value("Char", msdm::CharKind::Char)
        .value("Char16", msdm::CharKind::Char16)
        .value("Char32", msdm::CharKind::Char32)
        .value("Wchar", msdm::CharKind::Wchar);

    py::enum_<msdm::IntrinsicFunctionKind>(m, "IntrinsicFunctionKind")
        .value("None_", msdm::IntrinsicFunctionKind::None)
        .value("New", msdm::IntrinsicFunctionKind::New)
        .value("Delete", msdm::IntrinsicFunctionKind::Delete)
        .value("Assign", msdm::IntrinsicFunctionKind::Assign)
        .value("RightShift", msdm::IntrinsicFunctionKind::RightShift)
        .value("LeftShift", msdm::IntrinsicFunctionKind::LeftShift)
        .value("LogicalNot", msdm::IntrinsicFunctionKind::LogicalNot)
        .value("Equals", msdm::IntrinsicFunctionKind::Equals)
        .value("NotEquals", msdm::IntrinsicFunctionKind::NotEquals)
        .value("ArraySubscript", msdm::IntrinsicFunctionKind::ArraySubscript)
        .value("Pointer", msdm::IntrinsicFunctionKind::Pointer)
        .value("Dereference", msdm::IntrinsicFunctionKind::Dereference)
        .value("Increment", msdm::IntrinsicFunctionKind::Increment)
        .value("Decrement", msdm::IntrinsicFunctionKind::Decrement)
        .value("Minus", msdm::IntrinsicFunctionKind::Minus)
        .value("Plus", msdm::IntrinsicFunctionKind::Plus)
        .value("BitwiseAnd", msdm::IntrinsicFunctionKind::BitwiseAnd)
        .value("MemberPointer", msdm::IntrinsicFunctionKind::MemberPointer)
        .value("Divide", msdm::IntrinsicFunctionKind::Divide)
        .value("Modulus", msdm::IntrinsicFunctionKind::Modulus)
        .value("LessThan", msdm::IntrinsicFunctionKind::LessThan)
        .value("LessThanEqual", msdm::IntrinsicFunctionKind::LessThanEqual)
        .value("GreaterThan", msdm::IntrinsicFunctionKind::GreaterThan)
        .value("GreaterThanEqual", msdm::IntrinsicFunctionKind::GreaterThanEqual)
        .value("Comma", msdm::IntrinsicFunctionKind::Comma)
        .value("Parens", msdm::IntrinsicFunctionKind::Parens)
        .value("BitwiseNot", msdm::IntrinsicFunctionKind::BitwiseNot)
        .value("BitwiseXor", msdm::IntrinsicFunctionKind::BitwiseXor)
        .value("BitwiseOr", msdm::IntrinsicFunctionKind::BitwiseOr)
        .value("LogicalAnd", msdm::IntrinsicFunctionKind::LogicalAnd)
        .value("LogicalOr", msdm::IntrinsicFunctionKind::LogicalOr)
        .value("TimesEqual", msdm::IntrinsicFunctionKind::TimesEqual)
        .value("PlusEqual", msdm::IntrinsicFunctionKind::PlusEqual)
        .value("MinusEqual", msdm::IntrinsicFunctionKind::MinusEqual)
        .value("DivEqual", msdm::IntrinsicFunctionKind::DivEqual)
        .value("ModEqual", msdm::IntrinsicFunctionKind::ModEqual)
        .value("RshEqual", msdm::IntrinsicFunctionKind::RshEqual)
        .value("LshEqual", msdm::IntrinsicFunctionKind::LshEqual)
        .value("BitwiseAndEqual", msdm::IntrinsicFunctionKind::BitwiseAndEqual)
        .value("BitwiseOrEqual", msdm::IntrinsicFunctionKind::BitwiseOrEqual)
        .value("BitwiseXorEqual", msdm::IntrinsicFunctionKind::BitwiseXorEqual)
        .value("VbaseDtor", msdm::IntrinsicFunctionKind::VbaseDtor)
        .value("VecDelDtor", msdm::IntrinsicFunctionKind::VecDelDtor)
        .value("DefaultCtorClosure", msdm::IntrinsicFunctionKind::DefaultCtorClosure)
        .value("ScalarDelDtor", msdm::IntrinsicFunctionKind::ScalarDelDtor)
        .value("VecCtorIter", msdm::IntrinsicFunctionKind::VecCtorIter)
        .value("VecDtorIter", msdm::IntrinsicFunctionKind::VecDtorIter)
        .value("VecVbaseCtorIter", msdm::IntrinsicFunctionKind::VecVbaseCtorIter)
        .value("VdispMap", msdm::IntrinsicFunctionKind::VdispMap)
        .value("EHVecCtorIter", msdm::IntrinsicFunctionKind::EHVecCtorIter)
        .value("EHVecDtorIter", msdm::IntrinsicFunctionKind::EHVecDtorIter)
        .value("EHVecVbaseCtorIter", msdm::IntrinsicFunctionKind::EHVecVbaseCtorIter)
        .value("CopyCtorClosure", msdm::IntrinsicFunctionKind::CopyCtorClosure)
        .value("LocalVftableCtorClosure", msdm::IntrinsicFunctionKind::LocalVftableCtorClosure)
        .value("ArrayNew", msdm::IntrinsicFunctionKind::ArrayNew)
        .value("ArrayDelete", msdm::IntrinsicFunctionKind::ArrayDelete)
        .value("ManVectorCtorIter", msdm::IntrinsicFunctionKind::ManVectorCtorIter)
        .value("ManVectorDtorIter", msdm::IntrinsicFunctionKind::ManVectorDtorIter)
        .value("EHVectorCopyCtorIter", msdm::IntrinsicFunctionKind::EHVectorCopyCtorIter)
        .value("EHVectorVbaseCopyCtorIter", msdm::IntrinsicFunctionKind::EHVectorVbaseCopyCtorIter)
        .value("VectorCopyCtorIter", msdm::IntrinsicFunctionKind::VectorCopyCtorIter)
        .value("VectorVbaseCopyCtorIter", msdm::IntrinsicFunctionKind::VectorVbaseCopyCtorIter)
        .value("ManVectorVbaseCopyCtorIter", msdm::IntrinsicFunctionKind::ManVectorVbaseCopyCtorIter)
        .value("CoAwait", msdm::IntrinsicFunctionKind::CoAwait)
        .value("Spaceship", msdm::IntrinsicFunctionKind::Spaceship)
        .value("MaxIntrinsic", msdm::IntrinsicFunctionKind::MaxIntrinsic);

    py::enum_<msdm::SpecialIntrinsicKind>(m, "SpecialIntrinsicKind")
        .value("None_", msdm::SpecialIntrinsicKind::None)
        .value("Vftable", msdm::SpecialIntrinsicKind::Vftable)
        .value("Vbtable", msdm::SpecialIntrinsicKind::Vbtable)
        .value("Typeof", msdm::SpecialIntrinsicKind::Typeof)
        .value("VcallThunk", msdm::SpecialIntrinsicKind::VcallThunk)
        .value("LocalStaticGuard", msdm::SpecialIntrinsicKind::LocalStaticGuard)
        .value("StringLiteralSymbol", msdm::SpecialIntrinsicKind::StringLiteralSymbol)
        .value("UdtReturning", msdm::SpecialIntrinsicKind::UdtReturning)
        .value("Unknown", msdm::SpecialIntrinsicKind::Unknown)
        .value("DynamicInitializer", msdm::SpecialIntrinsicKind::DynamicInitializer)
        .value("DynamicAtexitDestructor", msdm::SpecialIntrinsicKind::DynamicAtexitDestructor)
        .value("RttiTypeDescriptor", msdm::SpecialIntrinsicKind::RttiTypeDescriptor)
        .value("RttiBaseClassDescriptor", msdm::SpecialIntrinsicKind::RttiBaseClassDescriptor)
        .value("RttiBaseClassArray", msdm::SpecialIntrinsicKind::RttiBaseClassArray)
        .value("RttiClassHierarchyDescriptor", msdm::SpecialIntrinsicKind::RttiClassHierarchyDescriptor)
        .value("RttiCompleteObjLocator", msdm::SpecialIntrinsicKind::RttiCompleteObjLocator)
        .value("LocalVftable", msdm::SpecialIntrinsicKind::LocalVftable)
        .value("LocalStaticThreadGuard", msdm::SpecialIntrinsicKind::LocalStaticThreadGuard);

    py::enum_<msdm::FuncClass>(m, "FuncClass", py::arithmetic())
        .value("None_", msdm::FuncClass::FC_None)
        .value("Public", msdm::FuncClass::FC_Public)
        .value("Protected", msdm::FuncClass::FC_Protected)
        .value("Private", msdm::FuncClass::FC_Private)
        .value("Global", msdm::FuncClass::FC_Global)
        .value("Static", msdm::FuncClass::FC_Static)
        .value("Virtual", msdm::FuncClass::FC_Virtual)
        .value("Far", msdm::FuncClass::FC_Far)
        .value("ExternC", msdm::FuncClass::FC_ExternC)
        .value("NoParameterList", msdm::FuncClass::FC_NoParameterList)
        .value("VirtualThisAdjust", msdm::FuncClass::FC_VirtualThisAdjust)
        .value("VirtualThisAdjustEx", msdm::FuncClass::FC_VirtualThisAdjustEx)
        .value("StaticThisAdjust", msdm::FuncClass::FC_StaticThisAdjust);

    py::enum_<msdm::TagKind>(m, "TagKind")
        .value("Class", msdm::TagKind::Class)
        .value("Struct", msdm::TagKind::Struct)
        .value("Union", msdm::TagKind::Union)
        .value("Enum", msdm::TagKind::Enum);

    py::enum_<msdm::NodeKind>(m, "NodeKind")
        .value("Unknown", msdm::NodeKind::Unknown)
        .value("Md5Symbol", msdm::NodeKind::Md5Symbol)
        .value("PrimitiveType", msdm::NodeKind::PrimitiveType)
        .value("FunctionSignature", msdm::NodeKind::FunctionSignature)
        .value("Identifier", msdm::NodeKind::Identifier)
        .value("NamedIdentifier", msdm::NodeKind::NamedIdentifier)
        .value("VcallThunkIdentifier", msdm::NodeKind::VcallThunkIdentifier)
        .value("LocalStaticGuardIdentifier", msdm::NodeKind::LocalStaticGuardIdentifier)
        .value("IntrinsicFunctionIdentifier", msdm::NodeKind::IntrinsicFunctionIdentifier)
        .value("ConversionOperatorIdentifier", msdm::NodeKind::ConversionOperatorIdentifier)
        .value("DynamicStructorIdentifier", msdm::NodeKind::DynamicStructorIdentifier)
        .value("StructorIdentifier", msdm::NodeKind::StructorIdentifier)
        .value("LiteralOperatorIdentifier", msdm::NodeKind::LiteralOperatorIdentifier)
        .value("ThunkSignature", msdm::NodeKind::ThunkSignature)
        .value("PointerType", msdm::NodeKind::PointerType)
        .value("TagType", msdm::NodeKind::TagType)
        .value("ArrayType", msdm::NodeKind::ArrayType)
        .value("Custom", msdm::NodeKind::Custom)
        .value("IntrinsicType", msdm::NodeKind::IntrinsicType)
        .value("NodeArray", msdm::NodeKind::NodeArray)
        .value("QualifiedName", msdm::NodeKind::QualifiedName)
        .value("TemplateParameterReference", msdm::NodeKind::TemplateParameterReference)
        .value("EncodedStringLiteral", msdm::NodeKind::EncodedStringLiteral)
        .value("IntegerLiteral", msdm::NodeKind::IntegerLiteral)
        .value("RttiBaseClassDescriptor", msdm::NodeKind::RttiBaseClassDescriptor)
        .value("LocalStaticGuardVariable", msdm::NodeKind::LocalStaticGuardVariable)
        .value("FunctionSymbol", msdm::NodeKind::FunctionSymbol)
        .value("VariableSymbol", msdm::NodeKind::VariableSymbol)
        .value("SpecialTableSymbol", msdm::NodeKind::SpecialTableSymbol);
}