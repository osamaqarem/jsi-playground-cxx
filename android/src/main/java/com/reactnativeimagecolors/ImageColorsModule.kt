package com.reactnativeimagecolors

import com.facebook.react.bridge.Promise
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod

class ImageColorsModule(reactContext: ReactApplicationContext) :
  ReactContextBaseJavaModule(reactContext) {

  private external fun nativeInstall(jsiPtr: Long)
  private external fun invalidate(jsiPtr: Long)

  override fun getName(): String {
    return "ImageColors"
  }

  companion object {
    init {
      System.loadLibrary("cpp")
    }
  }

  @ReactMethod
  fun test(source: String, promise: Promise) {
    promise.resolve("Hello")
  }


  override fun initialize() {
    super.initialize()
    reactApplicationContext.runOnJSQueueThread {
      nativeInstall(reactApplicationContext.javaScriptContextHolder.get())
    }
  }

  override fun onCatalystInstanceDestroy() {
    super.onCatalystInstanceDestroy()
    invalidate(reactApplicationContext.javaScriptContextHolder.get())
  }
}
