// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: light_buoy_colors.proto

#ifndef PROTOBUF_light_5fbuoy_5fcolors_2eproto__INCLUDED
#define PROTOBUF_light_5fbuoy_5fcolors_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace light_buoy_colors_msgs {
namespace msgs {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_light_5fbuoy_5fcolors_2eproto();
void protobuf_AssignDesc_light_5fbuoy_5fcolors_2eproto();
void protobuf_ShutdownFile_light_5fbuoy_5fcolors_2eproto();

class LightBuoyColors;

// ===================================================================

class LightBuoyColors : public ::google::protobuf::Message {
 public:
  LightBuoyColors();
  virtual ~LightBuoyColors();

  LightBuoyColors(const LightBuoyColors& from);

  inline LightBuoyColors& operator=(const LightBuoyColors& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LightBuoyColors& default_instance();

  void Swap(LightBuoyColors* other);

  // implements Message ----------------------------------------------

  LightBuoyColors* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LightBuoyColors& from);
  void MergeFrom(const LightBuoyColors& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string color_1 = 1;
  inline bool has_color_1() const;
  inline void clear_color_1();
  static const int kColor1FieldNumber = 1;
  inline const ::std::string& color_1() const;
  inline void set_color_1(const ::std::string& value);
  inline void set_color_1(const char* value);
  inline void set_color_1(const char* value, size_t size);
  inline ::std::string* mutable_color_1();
  inline ::std::string* release_color_1();
  inline void set_allocated_color_1(::std::string* color_1);

  // required string color_2 = 2;
  inline bool has_color_2() const;
  inline void clear_color_2();
  static const int kColor2FieldNumber = 2;
  inline const ::std::string& color_2() const;
  inline void set_color_2(const ::std::string& value);
  inline void set_color_2(const char* value);
  inline void set_color_2(const char* value, size_t size);
  inline ::std::string* mutable_color_2();
  inline ::std::string* release_color_2();
  inline void set_allocated_color_2(::std::string* color_2);

  // required string color_3 = 3;
  inline bool has_color_3() const;
  inline void clear_color_3();
  static const int kColor3FieldNumber = 3;
  inline const ::std::string& color_3() const;
  inline void set_color_3(const ::std::string& value);
  inline void set_color_3(const char* value);
  inline void set_color_3(const char* value, size_t size);
  inline ::std::string* mutable_color_3();
  inline ::std::string* release_color_3();
  inline void set_allocated_color_3(::std::string* color_3);

  // @@protoc_insertion_point(class_scope:light_buoy_colors_msgs.msgs.LightBuoyColors)
 private:
  inline void set_has_color_1();
  inline void clear_has_color_1();
  inline void set_has_color_2();
  inline void clear_has_color_2();
  inline void set_has_color_3();
  inline void clear_has_color_3();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* color_1_;
  ::std::string* color_2_;
  ::std::string* color_3_;
  friend void  protobuf_AddDesc_light_5fbuoy_5fcolors_2eproto();
  friend void protobuf_AssignDesc_light_5fbuoy_5fcolors_2eproto();
  friend void protobuf_ShutdownFile_light_5fbuoy_5fcolors_2eproto();

  void InitAsDefaultInstance();
  static LightBuoyColors* default_instance_;
};
// ===================================================================


// ===================================================================

// LightBuoyColors

// required string color_1 = 1;
inline bool LightBuoyColors::has_color_1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LightBuoyColors::set_has_color_1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LightBuoyColors::clear_has_color_1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LightBuoyColors::clear_color_1() {
  if (color_1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_1_->clear();
  }
  clear_has_color_1();
}
inline const ::std::string& LightBuoyColors::color_1() const {
  // @@protoc_insertion_point(field_get:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
  return *color_1_;
}
inline void LightBuoyColors::set_color_1(const ::std::string& value) {
  set_has_color_1();
  if (color_1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_1_ = new ::std::string;
  }
  color_1_->assign(value);
  // @@protoc_insertion_point(field_set:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
}
inline void LightBuoyColors::set_color_1(const char* value) {
  set_has_color_1();
  if (color_1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_1_ = new ::std::string;
  }
  color_1_->assign(value);
  // @@protoc_insertion_point(field_set_char:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
}
inline void LightBuoyColors::set_color_1(const char* value, size_t size) {
  set_has_color_1();
  if (color_1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_1_ = new ::std::string;
  }
  color_1_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
}
inline ::std::string* LightBuoyColors::mutable_color_1() {
  set_has_color_1();
  if (color_1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_1_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
  return color_1_;
}
inline ::std::string* LightBuoyColors::release_color_1() {
  clear_has_color_1();
  if (color_1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = color_1_;
    color_1_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void LightBuoyColors::set_allocated_color_1(::std::string* color_1) {
  if (color_1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete color_1_;
  }
  if (color_1) {
    set_has_color_1();
    color_1_ = color_1;
  } else {
    clear_has_color_1();
    color_1_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:light_buoy_colors_msgs.msgs.LightBuoyColors.color_1)
}

// required string color_2 = 2;
inline bool LightBuoyColors::has_color_2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LightBuoyColors::set_has_color_2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LightBuoyColors::clear_has_color_2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LightBuoyColors::clear_color_2() {
  if (color_2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_2_->clear();
  }
  clear_has_color_2();
}
inline const ::std::string& LightBuoyColors::color_2() const {
  // @@protoc_insertion_point(field_get:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
  return *color_2_;
}
inline void LightBuoyColors::set_color_2(const ::std::string& value) {
  set_has_color_2();
  if (color_2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_2_ = new ::std::string;
  }
  color_2_->assign(value);
  // @@protoc_insertion_point(field_set:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
}
inline void LightBuoyColors::set_color_2(const char* value) {
  set_has_color_2();
  if (color_2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_2_ = new ::std::string;
  }
  color_2_->assign(value);
  // @@protoc_insertion_point(field_set_char:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
}
inline void LightBuoyColors::set_color_2(const char* value, size_t size) {
  set_has_color_2();
  if (color_2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_2_ = new ::std::string;
  }
  color_2_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
}
inline ::std::string* LightBuoyColors::mutable_color_2() {
  set_has_color_2();
  if (color_2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_2_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
  return color_2_;
}
inline ::std::string* LightBuoyColors::release_color_2() {
  clear_has_color_2();
  if (color_2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = color_2_;
    color_2_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void LightBuoyColors::set_allocated_color_2(::std::string* color_2) {
  if (color_2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete color_2_;
  }
  if (color_2) {
    set_has_color_2();
    color_2_ = color_2;
  } else {
    clear_has_color_2();
    color_2_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:light_buoy_colors_msgs.msgs.LightBuoyColors.color_2)
}

// required string color_3 = 3;
inline bool LightBuoyColors::has_color_3() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LightBuoyColors::set_has_color_3() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LightBuoyColors::clear_has_color_3() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LightBuoyColors::clear_color_3() {
  if (color_3_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_3_->clear();
  }
  clear_has_color_3();
}
inline const ::std::string& LightBuoyColors::color_3() const {
  // @@protoc_insertion_point(field_get:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
  return *color_3_;
}
inline void LightBuoyColors::set_color_3(const ::std::string& value) {
  set_has_color_3();
  if (color_3_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_3_ = new ::std::string;
  }
  color_3_->assign(value);
  // @@protoc_insertion_point(field_set:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
}
inline void LightBuoyColors::set_color_3(const char* value) {
  set_has_color_3();
  if (color_3_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_3_ = new ::std::string;
  }
  color_3_->assign(value);
  // @@protoc_insertion_point(field_set_char:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
}
inline void LightBuoyColors::set_color_3(const char* value, size_t size) {
  set_has_color_3();
  if (color_3_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_3_ = new ::std::string;
  }
  color_3_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
}
inline ::std::string* LightBuoyColors::mutable_color_3() {
  set_has_color_3();
  if (color_3_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    color_3_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
  return color_3_;
}
inline ::std::string* LightBuoyColors::release_color_3() {
  clear_has_color_3();
  if (color_3_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = color_3_;
    color_3_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void LightBuoyColors::set_allocated_color_3(::std::string* color_3) {
  if (color_3_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete color_3_;
  }
  if (color_3) {
    set_has_color_3();
    color_3_ = color_3;
  } else {
    clear_has_color_3();
    color_3_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:light_buoy_colors_msgs.msgs.LightBuoyColors.color_3)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace light_buoy_colors_msgs

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_light_5fbuoy_5fcolors_2eproto__INCLUDED