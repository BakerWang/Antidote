source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '8.0'

# ignore all warnings from all pods
inhibit_all_warnings!

def common_pods
    pod 'objcTox', :git => 'https://github.com/Antidote-for-Tox/objcTox.git', :commit => 'dd18363c863'
    pod 'UITextView+Placeholder', '~> 1.1.0'
    pod 'SDCAlertView', '~> 2.5.4'
end

target :Antidote do
    common_pods
end

target :AntidoteTests do
    common_pods
    pod 'FBSnapshotTestCase/Core'
end
