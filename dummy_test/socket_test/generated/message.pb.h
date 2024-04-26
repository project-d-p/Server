// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_message_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "movement.pb.h"
#include "player_position.pb.h"
#include "attach.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_message_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_message_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_message_2eproto;
class Message;
struct MessageDefaultTypeInternal;
extern MessageDefaultTypeInternal _Message_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Message final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Message) */ {
 public:
  inline Message() : Message(nullptr) {}
  ~Message() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Message(::google::protobuf::internal::ConstantInitialized);

  inline Message(const Message& from)
      : Message(nullptr, from) {}
  Message(Message&& from) noexcept
    : Message() {
    *this = ::std::move(from);
  }

  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }
  inline Message& operator=(Message&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Message& default_instance() {
    return *internal_default_instance();
  }
  enum MessageTypeCase {
    kMovement = 1,
    kPlayerPosition = 2,
    kAttach = 3,
    MESSAGE_TYPE_NOT_SET = 0,
  };

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
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Message* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Message* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Message>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Message& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Message& from) {
    Message::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Message* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Message";
  }
  protected:
  explicit Message(::google::protobuf::Arena* arena);
  Message(::google::protobuf::Arena* arena, const Message& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMovementFieldNumber = 1,
    kPlayerPositionFieldNumber = 2,
    kAttachFieldNumber = 3,
  };
  // .Movement movement = 1;
  bool has_movement() const;
  private:
  bool _internal_has_movement() const;

  public:
  void clear_movement() ;
  const ::Movement& movement() const;
  PROTOBUF_NODISCARD ::Movement* release_movement();
  ::Movement* mutable_movement();
  void set_allocated_movement(::Movement* value);
  void unsafe_arena_set_allocated_movement(::Movement* value);
  ::Movement* unsafe_arena_release_movement();

  private:
  const ::Movement& _internal_movement() const;
  ::Movement* _internal_mutable_movement();

  public:
  // .PlayerPosition player_position = 2;
  bool has_player_position() const;
  private:
  bool _internal_has_player_position() const;

  public:
  void clear_player_position() ;
  const ::PlayerPosition& player_position() const;
  PROTOBUF_NODISCARD ::PlayerPosition* release_player_position();
  ::PlayerPosition* mutable_player_position();
  void set_allocated_player_position(::PlayerPosition* value);
  void unsafe_arena_set_allocated_player_position(::PlayerPosition* value);
  ::PlayerPosition* unsafe_arena_release_player_position();

  private:
  const ::PlayerPosition& _internal_player_position() const;
  ::PlayerPosition* _internal_mutable_player_position();

  public:
  // .Attachment attach = 3;
  bool has_attach() const;
  private:
  bool _internal_has_attach() const;

  public:
  void clear_attach() ;
  const ::Attachment& attach() const;
  PROTOBUF_NODISCARD ::Attachment* release_attach();
  ::Attachment* mutable_attach();
  void set_allocated_attach(::Attachment* value);
  void unsafe_arena_set_allocated_attach(::Attachment* value);
  ::Attachment* unsafe_arena_release_attach();

  private:
  const ::Attachment& _internal_attach() const;
  ::Attachment* _internal_mutable_attach();

  public:
  void clear_message_type();
  MessageTypeCase message_type_case() const;
  // @@protoc_insertion_point(class_scope:Message)
 private:
  class _Internal;
  void set_has_movement();
  void set_has_player_position();
  void set_has_attach();

  inline bool has_message_type() const;
  inline void clear_has_message_type();

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 3, 3,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    union MessageTypeUnion {
      constexpr MessageTypeUnion() : _constinit_{} {}
        ::google::protobuf::internal::ConstantInitialized _constinit_;
      ::Movement* movement_;
      ::PlayerPosition* player_position_;
      ::Attachment* attach_;
    } message_type_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];

    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_message_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Message

// .Movement movement = 1;
inline bool Message::has_movement() const {
  return message_type_case() == kMovement;
}
inline bool Message::_internal_has_movement() const {
  return message_type_case() == kMovement;
}
inline void Message::set_has_movement() {
  _impl_._oneof_case_[0] = kMovement;
}
inline ::Movement* Message::release_movement() {
  // @@protoc_insertion_point(field_release:Message.movement)
  if (message_type_case() == kMovement) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.movement_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.message_type_.movement_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::Movement& Message::_internal_movement() const {
  return message_type_case() == kMovement ? *_impl_.message_type_.movement_ : reinterpret_cast<::Movement&>(::_Movement_default_instance_);
}
inline const ::Movement& Message::movement() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Message.movement)
  return _internal_movement();
}
inline ::Movement* Message::unsafe_arena_release_movement() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Message.movement)
  if (message_type_case() == kMovement) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.movement_;
    _impl_.message_type_.movement_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Message::unsafe_arena_set_allocated_movement(::Movement* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_message_type();
  if (value) {
    set_has_movement();
    _impl_.message_type_.movement_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Message.movement)
}
inline ::Movement* Message::_internal_mutable_movement() {
  if (message_type_case() != kMovement) {
    clear_message_type();
    set_has_movement();
    _impl_.message_type_.movement_ = CreateMaybeMessage<::Movement>(GetArena());
  }
  return _impl_.message_type_.movement_;
}
inline ::Movement* Message::mutable_movement() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::Movement* _msg = _internal_mutable_movement();
  // @@protoc_insertion_point(field_mutable:Message.movement)
  return _msg;
}

// .PlayerPosition player_position = 2;
inline bool Message::has_player_position() const {
  return message_type_case() == kPlayerPosition;
}
inline bool Message::_internal_has_player_position() const {
  return message_type_case() == kPlayerPosition;
}
inline void Message::set_has_player_position() {
  _impl_._oneof_case_[0] = kPlayerPosition;
}
inline ::PlayerPosition* Message::release_player_position() {
  // @@protoc_insertion_point(field_release:Message.player_position)
  if (message_type_case() == kPlayerPosition) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.player_position_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.message_type_.player_position_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::PlayerPosition& Message::_internal_player_position() const {
  return message_type_case() == kPlayerPosition ? *_impl_.message_type_.player_position_ : reinterpret_cast<::PlayerPosition&>(::_PlayerPosition_default_instance_);
}
inline const ::PlayerPosition& Message::player_position() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Message.player_position)
  return _internal_player_position();
}
inline ::PlayerPosition* Message::unsafe_arena_release_player_position() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Message.player_position)
  if (message_type_case() == kPlayerPosition) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.player_position_;
    _impl_.message_type_.player_position_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Message::unsafe_arena_set_allocated_player_position(::PlayerPosition* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_message_type();
  if (value) {
    set_has_player_position();
    _impl_.message_type_.player_position_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Message.player_position)
}
inline ::PlayerPosition* Message::_internal_mutable_player_position() {
  if (message_type_case() != kPlayerPosition) {
    clear_message_type();
    set_has_player_position();
    _impl_.message_type_.player_position_ = CreateMaybeMessage<::PlayerPosition>(GetArena());
  }
  return _impl_.message_type_.player_position_;
}
inline ::PlayerPosition* Message::mutable_player_position() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::PlayerPosition* _msg = _internal_mutable_player_position();
  // @@protoc_insertion_point(field_mutable:Message.player_position)
  return _msg;
}

// .Attachment attach = 3;
inline bool Message::has_attach() const {
  return message_type_case() == kAttach;
}
inline bool Message::_internal_has_attach() const {
  return message_type_case() == kAttach;
}
inline void Message::set_has_attach() {
  _impl_._oneof_case_[0] = kAttach;
}
inline ::Attachment* Message::release_attach() {
  // @@protoc_insertion_point(field_release:Message.attach)
  if (message_type_case() == kAttach) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.attach_;
    if (GetArena() != nullptr) {
      temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
    }
    _impl_.message_type_.attach_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::Attachment& Message::_internal_attach() const {
  return message_type_case() == kAttach ? *_impl_.message_type_.attach_ : reinterpret_cast<::Attachment&>(::_Attachment_default_instance_);
}
inline const ::Attachment& Message::attach() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:Message.attach)
  return _internal_attach();
}
inline ::Attachment* Message::unsafe_arena_release_attach() {
  // @@protoc_insertion_point(field_unsafe_arena_release:Message.attach)
  if (message_type_case() == kAttach) {
    clear_has_message_type();
    auto* temp = _impl_.message_type_.attach_;
    _impl_.message_type_.attach_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Message::unsafe_arena_set_allocated_attach(::Attachment* value) {
  // We rely on the oneof clear method to free the earlier contents
  // of this oneof. We can directly use the pointer we're given to
  // set the new value.
  clear_message_type();
  if (value) {
    set_has_attach();
    _impl_.message_type_.attach_ = value;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Message.attach)
}
inline ::Attachment* Message::_internal_mutable_attach() {
  if (message_type_case() != kAttach) {
    clear_message_type();
    set_has_attach();
    _impl_.message_type_.attach_ = CreateMaybeMessage<::Attachment>(GetArena());
  }
  return _impl_.message_type_.attach_;
}
inline ::Attachment* Message::mutable_attach() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::Attachment* _msg = _internal_mutable_attach();
  // @@protoc_insertion_point(field_mutable:Message.attach)
  return _msg;
}

inline bool Message::has_message_type() const {
  return message_type_case() != MESSAGE_TYPE_NOT_SET;
}
inline void Message::clear_has_message_type() {
  _impl_._oneof_case_[0] = MESSAGE_TYPE_NOT_SET;
}
inline Message::MessageTypeCase Message::message_type_case() const {
  return Message::MessageTypeCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_message_2eproto_2epb_2eh
