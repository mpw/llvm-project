//===-- SBCommandInterpreterRunOptions.cpp --------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "lldb/lldb-types.h"

#include "SBReproducerPrivate.h"

#include "lldb/API/SBCommandInterpreterRunOptions.h"
#include "lldb/Interpreter/CommandInterpreter.h"

#include <memory>

using namespace lldb;
using namespace lldb_private;

SBCommandInterpreterRunOptions::SBCommandInterpreterRunOptions() {
  LLDB_RECORD_CONSTRUCTOR_NO_ARGS(SBCommandInterpreterRunOptions);

  m_opaque_up.reset(new CommandInterpreterRunOptions());
}

SBCommandInterpreterRunOptions::~SBCommandInterpreterRunOptions() = default;

bool SBCommandInterpreterRunOptions::GetStopOnContinue() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetStopOnContinue);

  return m_opaque_up->GetStopOnContinue();
}

void SBCommandInterpreterRunOptions::SetStopOnContinue(bool stop_on_continue) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnContinue,
                     (bool), stop_on_continue);

  m_opaque_up->SetStopOnContinue(stop_on_continue);
}

bool SBCommandInterpreterRunOptions::GetStopOnError() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetStopOnError);

  return m_opaque_up->GetStopOnError();
}

void SBCommandInterpreterRunOptions::SetStopOnError(bool stop_on_error) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnError,
                     (bool), stop_on_error);

  m_opaque_up->SetStopOnError(stop_on_error);
}

bool SBCommandInterpreterRunOptions::GetStopOnCrash() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetStopOnCrash);

  return m_opaque_up->GetStopOnCrash();
}

void SBCommandInterpreterRunOptions::SetStopOnCrash(bool stop_on_crash) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnCrash,
                     (bool), stop_on_crash);

  m_opaque_up->SetStopOnCrash(stop_on_crash);
}

bool SBCommandInterpreterRunOptions::GetEchoCommands() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetEchoCommands);

  return m_opaque_up->GetEchoCommands();
}

void SBCommandInterpreterRunOptions::SetEchoCommands(bool echo_commands) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetEchoCommands,
                     (bool), echo_commands);

  m_opaque_up->SetEchoCommands(echo_commands);
}

bool SBCommandInterpreterRunOptions::GetEchoCommentCommands() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetEchoCommentCommands);

  return m_opaque_up->GetEchoCommentCommands();
}

void SBCommandInterpreterRunOptions::SetEchoCommentCommands(bool echo) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions,
                     SetEchoCommentCommands, (bool), echo);

  m_opaque_up->SetEchoCommentCommands(echo);
}

bool SBCommandInterpreterRunOptions::GetPrintResults() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetPrintResults);

  return m_opaque_up->GetPrintResults();
}

void SBCommandInterpreterRunOptions::SetPrintResults(bool print_results) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetPrintResults,
                     (bool), print_results);

  m_opaque_up->SetPrintResults(print_results);
}

bool SBCommandInterpreterRunOptions::GetAddToHistory() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetAddToHistory);

  return m_opaque_up->GetAddToHistory();
}

void SBCommandInterpreterRunOptions::SetAddToHistory(bool add_to_history) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetAddToHistory,
                     (bool), add_to_history);

  m_opaque_up->SetAddToHistory(add_to_history);
}

bool SBCommandInterpreterRunOptions::GetAutoHandleEvents() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetAutoHandleEvents);

  return m_opaque_up->GetAutoHandleEvents();
}

void SBCommandInterpreterRunOptions::SetAutoHandleEvents(
    bool auto_handle_events) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetAutoHandleEvents,
                     (bool), auto_handle_events);

  m_opaque_up->SetAutoHandleEvents(auto_handle_events);
}

bool SBCommandInterpreterRunOptions::GetSpawnThread() const {
  LLDB_RECORD_METHOD_CONST_NO_ARGS(bool, SBCommandInterpreterRunOptions,
                                   GetSpawnThread);

  return m_opaque_up->GetSpawnThread();
}

void SBCommandInterpreterRunOptions::SetSpawnThread(bool spawn_thread) {
  LLDB_RECORD_METHOD(void, SBCommandInterpreterRunOptions, SetSpawnThread,
                     (bool), spawn_thread);

  m_opaque_up->SetSpawnThread(spawn_thread);
}

lldb_private::CommandInterpreterRunOptions *
SBCommandInterpreterRunOptions::get() const {
  return m_opaque_up.get();
}

lldb_private::CommandInterpreterRunOptions &
SBCommandInterpreterRunOptions::ref() const {
  return *m_opaque_up;
}

namespace lldb_private {
namespace repro {

template <> void RegisterMethods<SBCommandInterpreterRunOptions>(Registry &R) {
  LLDB_REGISTER_CONSTRUCTOR(SBCommandInterpreterRunOptions, ());
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetStopOnContinue, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnContinue,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetStopOnError, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnError,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetStopOnCrash, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetStopOnCrash,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetEchoCommands, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetEchoCommands,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetEchoCommentCommands, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions,
                       SetEchoCommentCommands, (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetPrintResults, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetPrintResults,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetAddToHistory, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetAddToHistory,
                       (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetAutoHandleEvents, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions,
                       SetAutoHandleEvents, (bool));
  LLDB_REGISTER_METHOD_CONST(bool, SBCommandInterpreterRunOptions,
                             GetSpawnThread, ());
  LLDB_REGISTER_METHOD(void, SBCommandInterpreterRunOptions, SetSpawnThread,
                       (bool));
}

} // namespace repro
} // namespace lldb_private
