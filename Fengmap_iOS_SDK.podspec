

Pod::Spec.new do |s|

  s.name         = "Fengmap_iOS_SDK"
  s.version      = "2.2.2"
  s.summary      = "蜂鸟视图地图端 iOS SDK"
  s.homepage     = "https://www.fengmap.com"
  s.license      = 'MIT'
  s.author       = { "fengmap-devs" => "developer@fengmap.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/fengmap-devs/Fengmap_iOS_SDK.git", :tag => "#{s.version}" }
  s.resource = "FMBundle.bundle"
  s.frameworks = "OpenGLES", "CoreGraphics", "GLKit"
  s.library   = "z", "c++"
  s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC", "ENABLE_BITCODE" => "YES"}
  s.vendored_libraries = 'Fengmap_iOS_SDK/libFMMapKit.a'
  s.public_header_files = 'Fengmap_iOS_SDK/include/FMMapKit/*.h'
  s.source_files = 'Fengmap_iOS_SDK/include/FMMapKit/*.h'
  
end
