// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: requestHeader.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_requestHeader_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_requestHeader_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_requestHeader_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_requestHeader_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_requestHeader_2eproto;
namespace header {
class requestHeader;
class requestHeaderDefaultTypeInternal;
extern requestHeaderDefaultTypeInternal _requestHeader_default_instance_;
}  // namespace header
PROTOBUF_NAMESPACE_OPEN
template<> ::header::requestHeader* Arena::CreateMaybeMessage<::header::requestHeader>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace header {

// ===================================================================

class requestHeader :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:header.requestHeader) */ {
 public:
  requestHeader();
  virtual ~requestHeader();

  requestHeader(const requestHeader& from);
  requestHeader(requestHeader&& from) noexcept
    : requestHeader() {
    *this = ::std::move(from);
  }

  inline requestHeader& operator=(const requestHeader& from) {
    CopyFrom(from);
    return *this;
  }
  inline requestHeader& operator=(requestHeader&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const requestHeader& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const requestHeader* internal_default_instance() {
    return reinterpret_cast<const requestHeader*>(
               &_requestHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(requestHeader& a, requestHeader& b) {
    a.Swap(&b);
  }
  inline void Swap(requestHeader* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline requestHeader* New() const final {
    return CreateMaybeMessage<requestHeader>(nullptr);
  }

  requestHeader* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<requestHeader>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const requestHeader& from);
  void MergeFrom(const requestHeader& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(requestHeader* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "header.requestHeader";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_requestHeader_2eproto);
    return ::descriptor_table_requestHeader_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kServiceNameFieldNumber = 2,
    kMethodNameFieldNumber = 3,
    kArgsFieldNumber = 4,
    kMessageLenFieldNumber = 1,
  };
  // bytes service_name = 2;
  void clear_service_name();
  const std::string& service_name() const;
  void set_service_name(const std::string& value);
  void set_service_name(std::string&& value);
  void set_service_name(const char* value);
  void set_service_name(const void* value, size_t size);
  std::string* mutable_service_name();
  std::string* release_service_name();
  void set_allocated_service_name(std::string* service_name);
  private:
  const std::string& _internal_service_name() const;
  void _internal_set_service_name(const std::string& value);
  std::string* _internal_mutable_service_name();
  public:

  // bytes method_name = 3;
  void clear_method_name();
  const std::string& method_name() const;
  void set_method_name(const std::string& value);
  void set_method_name(std::string&& value);
  void set_method_name(const char* value);
  void set_method_name(const void* value, size_t size);
  std::string* mutable_method_name();
  std::string* release_method_name();
  void set_allocated_method_name(std::string* method_name);
  private:
  const std::string& _internal_method_name() const;
  void _internal_set_method_name(const std::string& value);
  std::string* _internal_mutable_method_name();
  public:

  // bytes args = 4;
  void clear_args();
  const std::string& args() const;
  void set_args(const std::string& value);
  void set_args(std::string&& value);
  void set_args(const char* value);
  void set_args(const void* value, size_t size);
  std::string* mutable_args();
  std::string* release_args();
  void set_allocated_args(std::string* args);
  private:
  const std::string& _internal_args() const;
  void _internal_set_args(const std::string& value);
  std::string* _internal_mutable_args();
  public:

  // int32 message_len = 1;
  void clear_message_len();
  ::PROTOBUF_NAMESPACE_ID::int32 message_len() const;
  void set_message_len(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_message_len() const;
  void _internal_set_message_len(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:header.requestHeader)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr service_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr method_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr args_;
  ::PROTOBUF_NAMESPACE_ID::int32 message_len_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_requestHeader_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// requestHeader

// int32 message_len = 1;
inline void requestHeader::clear_message_len() {
  message_len_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 requestHeader::_internal_message_len() const {
  return message_len_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 requestHeader::message_len() const {
  // @@protoc_insertion_point(field_get:header.requestHeader.message_len)
  return _internal_message_len();
}
inline void requestHeader::_internal_set_message_len(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  message_len_ = value;
}
inline void requestHeader::set_message_len(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_message_len(value);
  // @@protoc_insertion_point(field_set:header.requestHeader.message_len)
}

// bytes service_name = 2;
inline void requestHeader::clear_service_name() {
  service_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& requestHeader::service_name() const {
  // @@protoc_insertion_point(field_get:header.requestHeader.service_name)
  return _internal_service_name();
}
inline void requestHeader::set_service_name(const std::string& value) {
  _internal_set_service_name(value);
  // @@protoc_insertion_point(field_set:header.requestHeader.service_name)
}
inline std::string* requestHeader::mutable_service_name() {
  // @@protoc_insertion_point(field_mutable:header.requestHeader.service_name)
  return _internal_mutable_service_name();
}
inline const std::string& requestHeader::_internal_service_name() const {
  return service_name_.GetNoArena();
}
inline void requestHeader::_internal_set_service_name(const std::string& value) {
  
  service_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void requestHeader::set_service_name(std::string&& value) {
  
  service_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:header.requestHeader.service_name)
}
inline void requestHeader::set_service_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  service_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:header.requestHeader.service_name)
}
inline void requestHeader::set_service_name(const void* value, size_t size) {
  
  service_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:header.requestHeader.service_name)
}
inline std::string* requestHeader::_internal_mutable_service_name() {
  
  return service_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* requestHeader::release_service_name() {
  // @@protoc_insertion_point(field_release:header.requestHeader.service_name)
  
  return service_name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void requestHeader::set_allocated_service_name(std::string* service_name) {
  if (service_name != nullptr) {
    
  } else {
    
  }
  service_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), service_name);
  // @@protoc_insertion_point(field_set_allocated:header.requestHeader.service_name)
}

// bytes method_name = 3;
inline void requestHeader::clear_method_name() {
  method_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& requestHeader::method_name() const {
  // @@protoc_insertion_point(field_get:header.requestHeader.method_name)
  return _internal_method_name();
}
inline void requestHeader::set_method_name(const std::string& value) {
  _internal_set_method_name(value);
  // @@protoc_insertion_point(field_set:header.requestHeader.method_name)
}
inline std::string* requestHeader::mutable_method_name() {
  // @@protoc_insertion_point(field_mutable:header.requestHeader.method_name)
  return _internal_mutable_method_name();
}
inline const std::string& requestHeader::_internal_method_name() const {
  return method_name_.GetNoArena();
}
inline void requestHeader::_internal_set_method_name(const std::string& value) {
  
  method_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void requestHeader::set_method_name(std::string&& value) {
  
  method_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:header.requestHeader.method_name)
}
inline void requestHeader::set_method_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  method_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:header.requestHeader.method_name)
}
inline void requestHeader::set_method_name(const void* value, size_t size) {
  
  method_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:header.requestHeader.method_name)
}
inline std::string* requestHeader::_internal_mutable_method_name() {
  
  return method_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* requestHeader::release_method_name() {
  // @@protoc_insertion_point(field_release:header.requestHeader.method_name)
  
  return method_name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void requestHeader::set_allocated_method_name(std::string* method_name) {
  if (method_name != nullptr) {
    
  } else {
    
  }
  method_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), method_name);
  // @@protoc_insertion_point(field_set_allocated:header.requestHeader.method_name)
}

// bytes args = 4;
inline void requestHeader::clear_args() {
  args_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& requestHeader::args() const {
  // @@protoc_insertion_point(field_get:header.requestHeader.args)
  return _internal_args();
}
inline void requestHeader::set_args(const std::string& value) {
  _internal_set_args(value);
  // @@protoc_insertion_point(field_set:header.requestHeader.args)
}
inline std::string* requestHeader::mutable_args() {
  // @@protoc_insertion_point(field_mutable:header.requestHeader.args)
  return _internal_mutable_args();
}
inline const std::string& requestHeader::_internal_args() const {
  return args_.GetNoArena();
}
inline void requestHeader::_internal_set_args(const std::string& value) {
  
  args_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void requestHeader::set_args(std::string&& value) {
  
  args_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:header.requestHeader.args)
}
inline void requestHeader::set_args(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  args_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:header.requestHeader.args)
}
inline void requestHeader::set_args(const void* value, size_t size) {
  
  args_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:header.requestHeader.args)
}
inline std::string* requestHeader::_internal_mutable_args() {
  
  return args_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* requestHeader::release_args() {
  // @@protoc_insertion_point(field_release:header.requestHeader.args)
  
  return args_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void requestHeader::set_allocated_args(std::string* args) {
  if (args != nullptr) {
    
  } else {
    
  }
  args_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), args);
  // @@protoc_insertion_point(field_set_allocated:header.requestHeader.args)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace header

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_requestHeader_2eproto
