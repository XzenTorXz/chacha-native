#include <nan.h>
#include "chacha.h"
using namespace v8;

void InitAll(Handle<Object> exports) {
  Chacha::Init(exports);
}

NODE_MODULE(addon, InitAll)
