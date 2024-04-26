// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: movement.proto

#include "movement.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr Movement::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        player_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        timestamp_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        orientation_{nullptr},
        progess_vector_{nullptr},
        state_{static_cast< ::State >(0)} {}

template <typename>
PROTOBUF_CONSTEXPR Movement::Movement(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MovementDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MovementDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MovementDefaultTypeInternal() {}
  union {
    Movement _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MovementDefaultTypeInternal _Movement_default_instance_;
static ::_pb::Metadata file_level_metadata_movement_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_movement_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_movement_2eproto = nullptr;
const ::uint32_t TableStruct_movement_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::Movement, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_.player_id_),
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_.orientation_),
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_.progess_vector_),
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_.state_),
    PROTOBUF_FIELD_OFFSET(::Movement, _impl_.timestamp_),
    ~0u,
    0,
    1,
    ~0u,
    ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 13, -1, sizeof(::Movement)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::_Movement_default_instance_._instance,
};
const char descriptor_table_protodef_movement_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\016movement.proto\032\013state.proto\032\014vector.pr"
    "oto\"\202\001\n\010Movement\022\021\n\tplayer_id\030\001 \001(\t\022\032\n\013o"
    "rientation\030\002 \001(\0132\005.Vec3\022\035\n\016progess_vecto"
    "r\030\003 \001(\0132\005.Vec3\022\025\n\005state\030\004 \001(\0162\006.State\022\021\n"
    "\ttimestamp\030\005 \001(\tb\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_movement_2eproto_deps[2] =
    {
        &::descriptor_table_state_2eproto,
        &::descriptor_table_vector_2eproto,
};
static ::absl::once_flag descriptor_table_movement_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_movement_2eproto = {
    false,
    false,
    184,
    descriptor_table_protodef_movement_2eproto,
    "movement.proto",
    &descriptor_table_movement_2eproto_once,
    descriptor_table_movement_2eproto_deps,
    2,
    1,
    schemas,
    file_default_instances,
    TableStruct_movement_2eproto::offsets,
    file_level_metadata_movement_2eproto,
    file_level_enum_descriptors_movement_2eproto,
    file_level_service_descriptors_movement_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_movement_2eproto_getter() {
  return &descriptor_table_movement_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_movement_2eproto(&descriptor_table_movement_2eproto);
// ===================================================================

class Movement::_Internal {
 public:
  using HasBits = decltype(std::declval<Movement>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(Movement, _impl_._has_bits_);
  static const ::Vec3& orientation(const Movement* msg);
  static void set_has_orientation(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static const ::Vec3& progess_vector(const Movement* msg);
  static void set_has_progess_vector(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
};

const ::Vec3& Movement::_Internal::orientation(const Movement* msg) {
  return *msg->_impl_.orientation_;
}
const ::Vec3& Movement::_Internal::progess_vector(const Movement* msg) {
  return *msg->_impl_.progess_vector_;
}
void Movement::clear_orientation() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.orientation_ != nullptr) _impl_.orientation_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
void Movement::clear_progess_vector() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.progess_vector_ != nullptr) _impl_.progess_vector_->Clear();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
Movement::Movement(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Movement)
}
inline PROTOBUF_NDEBUG_INLINE Movement::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        player_id_(arena, from.player_id_),
        timestamp_(arena, from.timestamp_) {}

Movement::Movement(
    ::google::protobuf::Arena* arena,
    const Movement& from)
    : ::google::protobuf::Message(arena) {
  Movement* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.orientation_ = (cached_has_bits & 0x00000001u)
                ? CreateMaybeMessage<::Vec3>(arena, *from._impl_.orientation_)
                : nullptr;
  _impl_.progess_vector_ = (cached_has_bits & 0x00000002u)
                ? CreateMaybeMessage<::Vec3>(arena, *from._impl_.progess_vector_)
                : nullptr;
  _impl_.state_ = from._impl_.state_;

  // @@protoc_insertion_point(copy_constructor:Movement)
}
inline PROTOBUF_NDEBUG_INLINE Movement::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        player_id_(arena),
        timestamp_(arena) {}

inline void Movement::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, orientation_),
           0,
           offsetof(Impl_, state_) -
               offsetof(Impl_, orientation_) +
               sizeof(Impl_::state_));
}
Movement::~Movement() {
  // @@protoc_insertion_point(destructor:Movement)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Movement::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.player_id_.Destroy();
  _impl_.timestamp_.Destroy();
  delete _impl_.orientation_;
  delete _impl_.progess_vector_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void Movement::Clear() {
// @@protoc_insertion_point(message_clear_start:Movement)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.player_id_.ClearToEmpty();
  _impl_.timestamp_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      ABSL_DCHECK(_impl_.orientation_ != nullptr);
      _impl_.orientation_->Clear();
    }
    if (cached_has_bits & 0x00000002u) {
      ABSL_DCHECK(_impl_.progess_vector_ != nullptr);
      _impl_.progess_vector_->Clear();
    }
  }
  _impl_.state_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Movement::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 2, 35, 2> Movement::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Movement, _impl_._has_bits_),
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Movement_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // string player_id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Movement, _impl_.player_id_)}},
    // .Vec3 orientation = 2;
    {::_pbi::TcParser::FastMtS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(Movement, _impl_.orientation_)}},
    // .Vec3 progess_vector = 3;
    {::_pbi::TcParser::FastMtS1,
     {26, 1, 1, PROTOBUF_FIELD_OFFSET(Movement, _impl_.progess_vector_)}},
    // .State state = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Movement, _impl_.state_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(Movement, _impl_.state_)}},
    // string timestamp = 5;
    {::_pbi::TcParser::FastUS1,
     {42, 63, 0, PROTOBUF_FIELD_OFFSET(Movement, _impl_.timestamp_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // string player_id = 1;
    {PROTOBUF_FIELD_OFFSET(Movement, _impl_.player_id_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // .Vec3 orientation = 2;
    {PROTOBUF_FIELD_OFFSET(Movement, _impl_.orientation_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // .Vec3 progess_vector = 3;
    {PROTOBUF_FIELD_OFFSET(Movement, _impl_.progess_vector_), _Internal::kHasBitsOffset + 1, 1,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // .State state = 4;
    {PROTOBUF_FIELD_OFFSET(Movement, _impl_.state_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // string timestamp = 5;
    {PROTOBUF_FIELD_OFFSET(Movement, _impl_.timestamp_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::TcParser::GetTable<::Vec3>()},
    {::_pbi::TcParser::GetTable<::Vec3>()},
  }}, {{
    "\10\11\0\0\0\11\0\0"
    "Movement"
    "player_id"
    "timestamp"
  }},
};

::uint8_t* Movement::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Movement)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string player_id = 1;
  if (!this->_internal_player_id().empty()) {
    const std::string& _s = this->_internal_player_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Movement.player_id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .Vec3 orientation = 2;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        2, _Internal::orientation(this),
        _Internal::orientation(this).GetCachedSize(), target, stream);
  }

  // .Vec3 progess_vector = 3;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        3, _Internal::progess_vector(this),
        _Internal::progess_vector(this).GetCachedSize(), target, stream);
  }

  // .State state = 4;
  if (this->_internal_state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
        4, this->_internal_state(), target);
  }

  // string timestamp = 5;
  if (!this->_internal_timestamp().empty()) {
    const std::string& _s = this->_internal_timestamp();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Movement.timestamp");
    target = stream->WriteStringMaybeAliased(5, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Movement)
  return target;
}

::size_t Movement::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Movement)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string player_id = 1;
  if (!this->_internal_player_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_player_id());
  }

  // string timestamp = 5;
  if (!this->_internal_timestamp().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_timestamp());
  }

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    // .Vec3 orientation = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size +=
          1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.orientation_);
    }

    // .Vec3 progess_vector = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size +=
          1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.progess_vector_);
    }

  }
  // .State state = 4;
  if (this->_internal_state() != 0) {
    total_size += 1 +
                  ::_pbi::WireFormatLite::EnumSize(this->_internal_state());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Movement::_class_data_ = {
    Movement::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* Movement::GetClassData() const {
  return &_class_data_;
}

void Movement::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Movement*>(&to_msg);
  auto& from = static_cast<const Movement&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Movement)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_player_id().empty()) {
    _this->_internal_set_player_id(from._internal_player_id());
  }
  if (!from._internal_timestamp().empty()) {
    _this->_internal_set_timestamp(from._internal_timestamp());
  }
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_mutable_orientation()->::Vec3::MergeFrom(
          from._internal_orientation());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_internal_mutable_progess_vector()->::Vec3::MergeFrom(
          from._internal_progess_vector());
    }
  }
  if (from._internal_state() != 0) {
    _this->_internal_set_state(from._internal_state());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Movement::CopyFrom(const Movement& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Movement)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Movement::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* Movement::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void Movement::InternalSwap(Movement* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.player_id_, &other->_impl_.player_id_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.timestamp_, &other->_impl_.timestamp_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Movement, _impl_.state_)
      + sizeof(Movement::_impl_.state_)
      - PROTOBUF_FIELD_OFFSET(Movement, _impl_.orientation_)>(
          reinterpret_cast<char*>(&_impl_.orientation_),
          reinterpret_cast<char*>(&other->_impl_.orientation_));
}

::google::protobuf::Metadata Movement::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_movement_2eproto_getter, &descriptor_table_movement_2eproto_once,
      file_level_metadata_movement_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"