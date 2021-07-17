#include "example.h"
#include <iostream>

using namespace facebook;

void installImageColors(jsi::Runtime &jsiRuntime) {
    std::cout << "installImageColors" << "\n";

    auto multiply = jsi::Function::createFromHostFunction(
            jsiRuntime,
            jsi::PropNameID::forAscii(jsiRuntime, "multiply"),
            2,
            [](
                    jsi::Runtime &runtime,
                    const jsi::Value &thisValue,
                    const jsi::Value *arguments,
                    size_t count
            ) -> jsi::Value {
                auto a = &arguments[0];
                auto b = &arguments[1];

                if (a->isNumber() && b->isNumber()) {
                    return a->getNumber() * b->getNumber();
                }

                return jsi::Value::undefined();
            }
    );

    jsiRuntime.global().setProperty(jsiRuntime, "multiply", std::move(multiply));
}


void cleanUpImageColors() {
    std::cout << "cleanUpImageColors" << "\n";
}
