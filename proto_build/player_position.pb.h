// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: player_position.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_player_5fposition_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_player_5fposition_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "state.pb.h"
#include "vector.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_player_5fposition_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_player_5fposition_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_player_5fposition_2eproto;
class PlayerPosition;
class PlayerPositionDefaultTypeInternal;
extern PlayerPositionDefaultTypeInternal _PlayerPosition_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::PlayerPosition* Arena::CreateMaybeMessage<::PlayerPosition>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class PlayerPosition PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:PlayerPosition) */ {
 public:
  inline PlayerPosition() : PlayerPosition(nullptr) {};
  virtual ~PlayerPosition();

  PlayerPosition(const PlayerPosition& from);
  PlayerPosition(PlayerPosition&& from) noexcept
    : PlayerPosition() {
    *this = ::std::move(from);
  }

  inline PlayerPosition& operator=(const PlayerPosition& from) {
    CopyFrom(from);
    return *this;
  }
  inline PlayerPosition& operator=(PlayerPosition&& from) noexcept {
    if (GetArena() == from.GetArena()) {
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
  static const PlayerPosition& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PlayerPosition* internal_default_instance() {
    return reinterpret_cast<const PlayerPosition*>(
               &_PlayerPosition_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PlayerPosition& a, PlayerPosition& b) {
    a.Swap(&b);
  }
  inline void Swap(PlayerPosition* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PlayerPosition* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PlayerPosition* New() const final {
    return CreateMaybeMessage<PlayerPosition>(nullptr);
  }

  PlayerPosition* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PlayerPosition>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PlayerPosition& from);
  void MergeFrom(const PlayerPosition& from);
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
  void InternalSwap(PlayerPosition* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "PlayerPosition";
  }
  protected:
  explicit PlayerPosition(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_player_5fposition_2eproto);
    return ::descriptor_table_player_5fposition_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPlayerIdFieldNumber = 1,
    kTimestampFieldNumber = 5,
    kPositionFieldNumber = 2,
    kOrientationFieldNumber = 3,
    kStateFieldNumber = 4,
  };
  // string player_id = 1;
  void clear_player_id();
  const std::string& player_id() const;
  void set_player_id(const std::string& value);
  void set_player_id(std::string&& value);
  void set_player_id(const char* value);
  void set_player_id(const char* value, size_t size);
  std::string* mutable_player_id();
  std::string* release_player_id();
  void set_allocated_player_id(std::string* player_id);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_player_id();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_player_id(
      std::string* player_id);
  private:
  const std::string& _internal_player_id() const;
  void _internal_set_player_id(const std::string& value);
  std::string* _internal_mutable_player_id();
  public:

  // string timestamp = 5;
  void clear_timestamp();
  const std::string& timestamp() const;
  void set_timestamp(const std::string& value);
  void set_timestamp(std::string&& value);
  void set_timestamp(const char* value);
  void set_timestamp(const char* value, size_t size);
  std::string* mutable_timestamp();
  std::string* release_timestamp();
  void set_allocated_timestamp(std::string* timestamp);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_timestamp();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_timestamp(
      std::string* timestamp);
  private:
  const std::string& _internal_timestamp() const;
  void _internal_set_timestamp(const std::string& value);
  std::string* _internal_mutable_timestamp();
  public:

  // .Vec3 position = 2;
  bool has_position() const;
  private:
  bool _internal_has_position() const;
  public:
  void clear_position();
  const ::Vec3& position() const;
  ::Vec3* release_position();
  ::Vec3* mutable_position();
  void set_allocated_position(::Vec3* position);
  private:
  const ::Vec3& _internal_position() const;
  ::Vec3* _internal_mutable_position();
  public:
  void unsafe_arena_set_allocated_position(
      ::Vec3* position);
  ::Vec3* unsafe_arena_release_position();

  // .Vec3 orientation = 3;
  bool has_orientation() const;
  private:
  bool _internal_has_orientation() const;
  public:
  void clear_orientation();
  const ::Vec3& orientation() const;
  ::Vec3* release_orientation();
  ::Vec3* mutable_orientation();
  void set_allocated_orientation(::Vec3* orientation);
  private:
  const ::Vec3& _internal_orientation() const;
  ::Vec3* _internal_mutable_orientation();
  public:
  void unsafe_arena_set_allocated_orientation(
      ::Vec3* orientation);
  ::Vec3* unsafe_arena_release_orientation();

  // .State state = 4;
  void clear_state();
  ::State state() const;
  void set_state(::State value);
  private:
  ::State _internal_state() const;
  void _internal_set_state(::State value);
  public:

  // @@protoc_insertion_point(class_scope:PlayerPosition)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr player_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr timestamp_;
  ::Vec3* position_;
  ::Vec3* orientation_;
  int state_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_player_5fposition_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PlayerPosition

// string player_id = 1;
inline void PlayerPosition::clear_player_id() {
  player_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& PlayerPosition::player_id() const {
  // @@protoc_insertion_point(field_get:PlayerPosition.player_id)
  return _internal_player_id();
}
inline void PlayerPosition::set_player_id(const std::string& value) {
  _internal_set_player_id(value);
  // @@protoc_insertion_point(field_set:PlayerPosition.player_id)
}
inline std::string* PlayerPosition::mutable_player_id() {
  // @@protoc_insertion_point(field_mutable:PlayerPosition.player_id)
  return _internal_mutable_player_id();
}
inline const std::string& PlayerPosition::_internal_player_id() const {
  return player_id_.Get();
}
inline void PlayerPosition::_internal_set_player_id(const std::string& value) {
  
  player_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void PlayerPosition::set_player_id(std::string&& value) {
  
  player_id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:PlayerPosition.player_id)
}
inline void PlayerPosition::set_player_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  player_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:PlayerPosition.player_id)
}
inline void PlayerPosition::set_player_id(const char* value,
    size_t size) {
  
  player_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:PlayerPosition.player_id)
}
inline std::string* PlayerPosition::_internal_mutable_player_id() {
  
  return player_id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* PlayerPosition::release_player_id() {
  // @@protoc_insertion_point(field_release:PlayerPosition.player_id)
  return player_id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void PlayerPosition::set_allocated_player_id(std::string* player_id) {
  if (player_id != nullptr) {
    
  } else {
    
  }
  player_id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), player_id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:PlayerPosition.player_id)
}
inline std::string* PlayerPosition::unsafe_arena_release_player_id() {
  // @@protoc_insertion_point(field_unsafe_arena_release:PlayerPosition.player_id)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return player_id_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void PlayerPosition::unsafe_arena_set_allocated_player_id(
    std::string* player_id) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (player_id != nullptr) {
    
  } else {
    
  }
  player_id_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      player_id, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:PlayerPosition.player_id)
}

// .Vec3 position = 2;
inline bool PlayerPosition::_internal_has_position() const {
  return this != internal_default_instance() && position_ != nullptr;
}
inline bool PlayerPosition::has_position() const {
  return _internal_has_position();
}
inline const ::Vec3& PlayerPosition::_internal_position() const {
  const ::Vec3* p = position_;
  return p != nullptr ? *p : *reinterpret_cast<const ::Vec3*>(
      &::_Vec3_default_instance_);
}
inline const ::Vec3& PlayerPosition::position() const {
  // @@protoc_insertion_point(field_get:PlayerPosition.position)
  return _internal_position();
}
inline void PlayerPosition::unsafe_arena_set_allocated_position(
    ::Vec3* position) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(position_);
  }
  position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:PlayerPosition.position)
}
inline ::Vec3* PlayerPosition::release_position() {
  auto temp = unsafe_arena_release_position();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::Vec3* PlayerPosition::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:PlayerPosition.position)
  
  ::Vec3* temp = position_;
  position_ = nullptr;
  return temp;
}
inline ::Vec3* PlayerPosition::_internal_mutable_position() {
  
  if (position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Vec3>(GetArena());
    position_ = p;
  }
  return position_;
}
inline ::Vec3* PlayerPosition::mutable_position() {
  // @@protoc_insertion_point(field_mutable:PlayerPosition.position)
  return _internal_mutable_position();
}
inline void PlayerPosition::set_allocated_position(::Vec3* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(position_);
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(position)->GetArena();
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:PlayerPosition.position)
}

// .Vec3 orientation = 3;
inline bool PlayerPosition::_internal_has_orientation() const {
  return this != internal_default_instance() && orientation_ != nullptr;
}
inline bool PlayerPosition::has_orientation() const {
  return _internal_has_orientation();
}
inline const ::Vec3& PlayerPosition::_internal_orientation() const {
  const ::Vec3* p = orientation_;
  return p != nullptr ? *p : *reinterpret_cast<const ::Vec3*>(
      &::_Vec3_default_instance_);
}
inline const ::Vec3& PlayerPosition::orientation() const {
  // @@protoc_insertion_point(field_get:PlayerPosition.orientation)
  return _internal_orientation();
}
inline void PlayerPosition::unsafe_arena_set_allocated_orientation(
    ::Vec3* orientation) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(orientation_);
  }
  orientation_ = orientation;
  if (orientation) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:PlayerPosition.orientation)
}
inline ::Vec3* PlayerPosition::release_orientation() {
  auto temp = unsafe_arena_release_orientation();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::Vec3* PlayerPosition::unsafe_arena_release_orientation() {
  // @@protoc_insertion_point(field_release:PlayerPosition.orientation)
  
  ::Vec3* temp = orientation_;
  orientation_ = nullptr;
  return temp;
}
inline ::Vec3* PlayerPosition::_internal_mutable_orientation() {
  
  if (orientation_ == nullptr) {
    auto* p = CreateMaybeMessage<::Vec3>(GetArena());
    orientation_ = p;
  }
  return orientation_;
}
inline ::Vec3* PlayerPosition::mutable_orientation() {
  // @@protoc_insertion_point(field_mutable:PlayerPosition.orientation)
  return _internal_mutable_orientation();
}
inline void PlayerPosition::set_allocated_orientation(::Vec3* orientation) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(orientation_);
  }
  if (orientation) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(orientation)->GetArena();
    if (message_arena != submessage_arena) {
      orientation = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, orientation, submessage_arena);
    }
    
  } else {
    
  }
  orientation_ = orientation;
  // @@protoc_insertion_point(field_set_allocated:PlayerPosition.orientation)
}

// .State state = 4;
inline void PlayerPosition::clear_state() {
  state_ = 0;
}
inline ::State PlayerPosition::_internal_state() const {
  return static_cast< ::State >(state_);
}
inline ::State PlayerPosition::state() const {
  // @@protoc_insertion_point(field_get:PlayerPosition.state)
  return _internal_state();
}
inline void PlayerPosition::_internal_set_state(::State value) {
  
  state_ = value;
}
inline void PlayerPosition::set_state(::State value) {
  _internal_set_state(value);
  // @@protoc_insertion_point(field_set:PlayerPosition.state)
}

// string timestamp = 5;
inline void PlayerPosition::clear_timestamp() {
  timestamp_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& PlayerPosition::timestamp() const {
  // @@protoc_insertion_point(field_get:PlayerPosition.timestamp)
  return _internal_timestamp();
}
inline void PlayerPosition::set_timestamp(const std::string& value) {
  _internal_set_timestamp(value);
  // @@protoc_insertion_point(field_set:PlayerPosition.timestamp)
}
inline std::string* PlayerPosition::mutable_timestamp() {
  // @@protoc_insertion_point(field_mutable:PlayerPosition.timestamp)
  return _internal_mutable_timestamp();
}
inline const std::string& PlayerPosition::_internal_timestamp() const {
  return timestamp_.Get();
}
inline void PlayerPosition::_internal_set_timestamp(const std::string& value) {
  
  timestamp_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void PlayerPosition::set_timestamp(std::string&& value) {
  
  timestamp_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:PlayerPosition.timestamp)
}
inline void PlayerPosition::set_timestamp(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  timestamp_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:PlayerPosition.timestamp)
}
inline void PlayerPosition::set_timestamp(const char* value,
    size_t size) {
  
  timestamp_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:PlayerPosition.timestamp)
}
inline std::string* PlayerPosition::_internal_mutable_timestamp() {
  
  return timestamp_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* PlayerPosition::release_timestamp() {
  // @@protoc_insertion_point(field_release:PlayerPosition.timestamp)
  return timestamp_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void PlayerPosition::set_allocated_timestamp(std::string* timestamp) {
  if (timestamp != nullptr) {
    
  } else {
    
  }
  timestamp_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), timestamp,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:PlayerPosition.timestamp)
}
inline std::string* PlayerPosition::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_unsafe_arena_release:PlayerPosition.timestamp)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return timestamp_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void PlayerPosition::unsafe_arena_set_allocated_timestamp(
    std::string* timestamp) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (timestamp != nullptr) {
    
  } else {
    
  }
  timestamp_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      timestamp, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:PlayerPosition.timestamp)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_player_5fposition_2eproto