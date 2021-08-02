#include "example.h"
#include "curl/curl.h"
#include <iostream>
#include <future>
#include <thread>

using namespace facebook;
using namespace std;

template<typename... ParamTypes>
function<void(int, function<void(ParamTypes... paramTypes)>,
              ParamTypes... paramTypes)> setTimeout = [](
        int ms,
        function<void(ParamTypes... paramTypes)> cb,
        ParamTypes... paramTypes
) {
    async(launch::async, [=]() {
        this_thread::sleep_for(chrono::milliseconds(ms));
        cb(paramTypes...);
    });
};

void installImageColors(jsi::Runtime &jsiRuntime) {
    cout << "installImageColors" << "\n";

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
                    auto results = a->getNumber() * b->getNumber();

                    setTimeout<int>(3000, [&results](int hmm) {
                        results = 500;
                    }, 10);

                    return results;
                } else {
                    // TODO: async operation
                    // get back on JS thread
                    //  jsInvoker->invokeAsync(move(retainedFunc));
//                async(launch::async, [=]() {
//
//                });

                    return jsi::Value::undefined();
                }
            }
    );

    jsiRuntime.global().setProperty(jsiRuntime, "multiply", move(multiply));
}


void cleanUpImageColors() {
    cout << "cleanUpImageColors" << "\n";
}

