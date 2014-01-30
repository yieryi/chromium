// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/input_method/mock_input_method_manager.h"

namespace chromeos {
namespace input_method {

MockInputMethodManager::MockInputMethodManager()
    : add_observer_count_(0),
      remove_observer_count_(0),
      util_(&delegate_, whitelist_.GetSupportedInputMethods()) {
  active_input_method_ids_.push_back("xkb:us::eng");
}

MockInputMethodManager::~MockInputMethodManager() {
}

void MockInputMethodManager::AddObserver(
    InputMethodManager::Observer* observer) {
  ++add_observer_count_;
}

void MockInputMethodManager::AddCandidateWindowObserver(
    InputMethodManager::CandidateWindowObserver* observer) {
}

void MockInputMethodManager::RemoveObserver(
    InputMethodManager::Observer* observer) {
  ++remove_observer_count_;
}

void MockInputMethodManager::RemoveCandidateWindowObserver(
    InputMethodManager::CandidateWindowObserver* observer) {
}

scoped_ptr<InputMethodDescriptors>
MockInputMethodManager::GetSupportedInputMethods() const {
  scoped_ptr<InputMethodDescriptors> result(new InputMethodDescriptors);
  result->push_back(
      InputMethodUtil::GetFallbackInputMethodDescriptor());
  return result.Pass();
}

scoped_ptr<InputMethodDescriptors>
MockInputMethodManager::GetActiveInputMethods() const {
  scoped_ptr<InputMethodDescriptors> result(new InputMethodDescriptors);
  result->push_back(
      InputMethodUtil::GetFallbackInputMethodDescriptor());
  return result.Pass();
}

const std::vector<std::string>&
MockInputMethodManager::GetActiveInputMethodIds() const {
  return active_input_method_ids_;
}

size_t MockInputMethodManager::GetNumActiveInputMethods() const {
  return 1;
}

const InputMethodDescriptor* MockInputMethodManager::GetInputMethodFromId(
    const std::string& input_method_id) const {
  static const InputMethodDescriptor defaultInputMethod =
      InputMethodUtil::GetFallbackInputMethodDescriptor();
  for (size_t i = 0; i < active_input_method_ids_.size(); i++) {
    if (input_method_id == active_input_method_ids_[i]) {
      return &defaultInputMethod;
    }
  }
  return NULL;
}

void MockInputMethodManager::EnableLoginLayouts(
    const std::string& language_code,
    const std::string& initial_layout) {
}

bool MockInputMethodManager::EnableInputMethods(
    const std::vector<std::string>& new_active_input_method_ids) {
  return true;
}

bool MockInputMethodManager::EnableInputMethod(
    const std::string& new_active_input_method_id) {
  return true;
}

void MockInputMethodManager::ChangeInputMethod(
    const std::string& input_method_id) {
}

void MockInputMethodManager::ActivateInputMethodProperty(
    const std::string& key) {
}

void MockInputMethodManager::AddInputMethodExtension(
    const std::string& id,
    InputMethodEngineInterface* instance) {
}

void MockInputMethodManager::RemoveInputMethodExtension(const std::string& id) {
}

void MockInputMethodManager::GetInputMethodExtensions(
    InputMethodDescriptors* result) {
}

void MockInputMethodManager::SetEnabledExtensionImes(
    std::vector<std::string>* ids) {
}

void MockInputMethodManager::SetInputMethodDefault() {
}

bool MockInputMethodManager::SwitchToNextInputMethod() {
  return true;
}

bool MockInputMethodManager::SwitchToPreviousInputMethod(
    const ui::Accelerator& accelerator) {
  return true;
}

bool MockInputMethodManager::SwitchInputMethod(
    const ui::Accelerator& accelerator) {
  return true;
}

InputMethodDescriptor MockInputMethodManager::GetCurrentInputMethod() const {
  InputMethodDescriptor descriptor =
      InputMethodUtil::GetFallbackInputMethodDescriptor();
  if (!current_input_method_id_.empty()) {
    return InputMethodDescriptor(current_input_method_id_,
                                 descriptor.name(),
                                 descriptor.keyboard_layouts(),
                                 descriptor.language_codes(),
                                 true,
                                 GURL(),  // options page url.
                                 GURL());  // input view page url.
  }
  return descriptor;
}

InputMethodPropertyList
MockInputMethodManager::GetCurrentInputMethodProperties() const {
  return InputMethodPropertyList();
}

void MockInputMethodManager::SetCurrentInputMethodProperties(
    const InputMethodPropertyList& property_list) {
}

XKeyboard* MockInputMethodManager::GetXKeyboard() {
  return &xkeyboard_;
}

InputMethodUtil* MockInputMethodManager::GetInputMethodUtil() {
  return &util_;
}

ComponentExtensionIMEManager*
    MockInputMethodManager::GetComponentExtensionIMEManager() {
  return NULL;
}

void MockInputMethodManager::set_application_locale(const std::string& value) {
  delegate_.set_active_locale(value);
}

void MockInputMethodManager::set_hardware_keyboard_layout(
    const std::string& value) {
  delegate_.set_hardware_keyboard_layout(value);
}

bool MockInputMethodManager::IsLoginKeyboard(
    const std::string& layout) const {
  return true;
}
}  // namespace input_method
}  // namespace chromeos
