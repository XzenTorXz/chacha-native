#ifndef CHACHA_H
#define CHACHA_H

#include <nan.h>
#include "chacha20_complex.h"

class Chacha : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);

 private:
  Chacha();
  ~Chacha();

  static NAN_METHOD(New);
  static NAN_METHOD(Update);
  static v8::Persistent<v8::Function> constructor;
  chacha20_ctx ctx_;
};

#endif
