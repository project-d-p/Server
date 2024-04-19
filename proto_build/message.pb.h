// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_2eproto

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
#include "movement.pb.h"
#include "player_position.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_2eproto;
class Message;
class MessageDefaultTypeInternal;
extern MessageDefaultTypeInternal _Message_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Message* Arena::CreateMaybeMessage<::Message>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Message PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Message) */ {
 public:
  inline Message() : Message(nullptr) {};
  virtual ~Message();

  Message(const Message& from);
  Message(Message&& from) noexcept
    : Message() {
    *this = ::std::move(from);
  }

  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }
  inline Message& operator=(Message&& from) noexcept {
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
  static const Message& default_instance();

  enum MessageTypeCase {
    kMovement = 1,
    kPlayerPosition = 2,
    MESSAGE_TYPE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Message* internal_default_instance() {
    return reinterpret_cast<const Message*>(
               &_Message_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Message& a, Message& b) {
    a.Swap(&b);
  }
  inline void Swap(Message* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Message* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Message* New() const final {
    return CreateMaybeMessage<Message>(nullptr);
  }

  Message* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Message>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
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
  void InternalSwap(Message* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Message";
  }
  protected:
  explicit Message(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_message_2eproto);
    return ::descriptor_table_message_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMovementFieldNumber = 1,
    kPlayerPositionFieldNumber = 2,
  };
  // .Movement movement = 1;
  bool has_movement() const;
  private:
  bool _internal_has_movement() const;
  public:
  void clear_movement();
  const ::Movement& movement() const;
  ::Movement* release_movement();
  ::Movement* mutable_movement();
  void set_allocated_movement(::Movement* movement);
  private:
  const ::Movement& _internal_movement() const;
  ::Movement* _internal_mutable_movement();
  public:
  void unsafe_arena_set_allocated_movement(
      ::Movement* movement);
  ::Movement* unsafe_arena_release_movement();

  // .PlayerPosition player_position = 2;
  bool has_player_position() const;
  private:
  bool _internal_has_player_position() const;
  public:
  void clear_player_position();
  const ::PlayerPosition& player_position() const;
  ::PlayerPosition* release_player_position();
  ::PlayerPosition* mutable_player_position();
  void set_allocated_player_position(::PlayerPosition* player_position);
  private:
  const ::PlayerPosition& _internal_player_position() const;
  ::PlayerPosition* _internal_mutable_player_position();
  public:
  void unsafe_arena_set_allocated_player_position(
      ::PlayerPosition* player_position);
  ::PlayerPosition* unsafe_arena_release_player_position();

  void clear_message_type();
  MessageTypeCase message_type_case() const;
  // @@protoc_insertion_point(class_scope:Message)
 private:
  class _Internal;
  void set_has_movement();
  void set_has_player_position();

  inline bool has_message_type() const;
  inline void clear_has_message_type();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union MessageTypeUnion {
    MessageTypeUnion() {}
    ::Movement* movement_;
    ::PlayerPosition* player_position_;
  } message_type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_message_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Message

// .Movement movement = 1;
inline bool Message::_internal_has_movement() const {
  return message_type_case() == kMovement;
}
inline bool Message::has_movement() const {
  return _internal_has_movement();
}
inline void Message::set_has_movement() {
  _oneof_case_[0] = kMovement;
}
inline ::Movement* Message::release_movement() {
  // @@protoc_insertion_point(field_release:Message.movement)
  if (_internal_has_movement()) {
    clear_has_message_type();
      ::Movement* temp = message_type_.movement_;
    if (GetArena() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    message_type_.movement_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::Movement& Message::_internal_movement() const {
  return _internal_has_movement()
      ? *message_type_.movement_
      : *reinterpret_cast< ::Movement*>(&::_Movement_default_instance_);
}
inline const ::Movement& Message::movement() const {
  // @@protoc_insertion_point(field_get:Message.movement)
  return _internal_movement();
}
inline ::Movement* Message::unsafe_arena_release_movement() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Message.movement)
  if (_internal_has_movement()) {
    clear_has_message_type();
    ::Movement* temp = message_type_.movement_;
    message_type_.movement_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Message::unsafe_arena_set_allocated_movement(::Movement* movement) {
  clear_message_type();
  if (movement) {
    set_has_movement();
    message_type_.movement_ = movement;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Message.movement)
}
inline ::Movement* Message::_internal_mutable_movement() {
  if (!_internal_has_movement()) {
    clear_message_type();
    set_has_movement();
    message_type_.movement_ = CreateMaybeMessage< ::Movement >(GetArena());
  }
  return message_type_.movement_;
}
inline ::Movement* Message::mutable_movement() {
  // @@protoc_insertion_point(field_mutable:Message.movement)
  return _internal_mutable_movement();
}

// .PlayerPosition player_position = 2;
inline bool Message::_internal_has_player_position() const {
  return message_type_case() == kPlayerPosition;
}
inline bool Message::has_player_position() const {
  return _internal_has_player_position();
}
inline void Message::set_has_player_position() {
  _oneof_case_[0] = kPlayerPosition;
}
inline ::PlayerPosition* Message::release_player_position() {
  // @@protoc_insertion_point(field_release:Message.player_position)
  if (_internal_has_player_position()) {
    clear_has_message_type();
      ::PlayerPosition* temp = message_type_.player_position_;
    if (GetArena() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    message_type_.player_position_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::PlayerPosition& Message::_internal_player_position() const {
  return _internal_has_player_position()
      ? *message_type_.player_position_
      : *reinterpret_cast< ::PlayerPosition*>(&::_PlayerPosition_default_instance_);
}
inline const ::PlayerPosition& Message::player_position() const {
  // @@protoc_insertion_point(field_get:Message.player_position)
  return _internal_player_position();
}
inline ::PlayerPosition* Message::unsafe_arena_release_player_position() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Message.player_position)
  if (_internal_has_player_position()) {
    clear_has_message_type();
    ::PlayerPosition* temp = message_type_.player_position_;
    message_type_.player_position_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Message::unsafe_arena_set_allocated_player_position(::PlayerPosition* player_position) {
  clear_message_type();
  if (player_position) {
    set_has_player_position();
    message_type_.player_position_ = player_position;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Message.player_position)
}
inline ::PlayerPosition* Message::_internal_mutable_player_position() {
  if (!_internal_has_player_position()) {
    clear_message_type();
    set_has_player_position();
    message_type_.player_position_ = CreateMaybeMessage< ::PlayerPosition >(GetArena());
  }
  return message_type_.player_position_;
}
inline ::PlayerPosition* Message::mutable_player_position() {
  // @@protoc_insertion_point(field_mutable:Message.player_position)
  return _internal_mutable_player_position();
}

inline bool Message::has_message_type() const {
  return message_type_case() != MESSAGE_TYPE_NOT_SET;
}
inline void Message::clear_has_message_type() {
  _oneof_case_[0] = MESSAGE_TYPE_NOT_SET;
}
inline Message::MessageTypeCase Message::message_type_case() const {
  return Message::MessageTypeCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_2eproto