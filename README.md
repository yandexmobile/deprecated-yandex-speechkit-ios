<p align="center" >
  <img src="http://storage.mds.yandex.net/get-speechkit/43542/yandex_speechkit_pic.pdf" alt="Yandex SpeechKit" title="Yandex SpeechKit Mobile SDK">
</p>

[Website](https://tech.yandex.ru/speechkit/mobilesdk/) |
[Documentation](https://tech.yandex.ru/speechkit/mobilesdk/doc/ios/stable/ref/concepts/About-docpage/) |
[Framework](https://storage.mds.yandex.net/get-speechkit/67393/YandexSpeechKit-3.12.2_5-ios.zip) |
[EULA](https://yandex.ru/legal/speechkit)

Use the SpeechKit library to integrate speech recognition, text-to-speech, music identification, and Yandex voice activation into your iOS mobile app. Voice control makes your app more user-friendly, especially for people who use it on the go or whose hands are busy. Without touching the screen, users can activate the desired feature with a single phrase.

SpeechKit supports the following languages for speech recognition and text-to-speech:
- Russian
- English
- Ukrainian
- Turkish

> If the language you need isn't supported, SpeechKit allows you to automatically switch to the Apple speech recognition system (this feature is available starting with iOS 10).

If the number of voice commands accessing your application does not exceed 10,000 per day, you can use the basic version of the SpeechKit Mobile SDK for free. If you have more requests, you can either pay for the amount over the limit, or switch to the commercial pricing plan. The commercial plan removes the restrictions and adds extra functionality. For instance, you can create unique voices and speech models for specific contexts.

## Where to start

- Find out what [SpeechKit](https://tech.yandex.com/speechkit/mobilesdk/) is, what functionality is available in the library, and how it can improve your application.
- Download [SpeechKit samples](https://github.com/yandexmobile/yandex-speechkit-samples-ios) and try to run them. This is a good way to quickly learn how to use the main components of the library.
- Read the [Quick Start](https://tech.yandex.ru/speechkit/mobilesdk/doc/ios/stable/quick-start/concepts/about-docpage/), which describes the configuration required for the library to work, along with recommended steps for fast and successful integration of SpeechKit in your application.
- Review the [Documentation](https://tech.yandex.ru/speechkit/mobilesdk/doc/ios/stable/ref/concepts/About-docpage/) for the library's API: the main classes and their functions, features, and restrictions.
- If you have previously used SpeechKit, we recommend that you also read the [Guide for migrating to SpeechKit 3.12.2](https://tech.yandex.ru/speechkit/mobilesdk/doc/intro/overview/concepts/speechkit-overview-versions-docpage/#3-12-2), which explains what has changed since the latest available version.

## Before you get started

Before you start working with APIs of Yandex services, you must create an API key:
- Go to the [Developer Dashboard](https://developer.tech.yandex.ru/).
- Click `Get key`.
- Enter a name for the key and select `SpeechKit Mobile SDK` in the list.
- Enter your information and the type of project.
- Click `Submit`.

After the API key is generated, you will be redirected to the `Developer Dashboard`. Under `Your API keys`, you can see all the keys that you have created.

## Installation

There are several ways to add SpeechKit to a project.

### Installing with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C and Swift that automates and simplifies the process of embedding third-party libraries in your application. To install CocoaPods, open the Terminal and type the command:

```bash
$ gem install cocoapods
```

#### Podfile

To integrate SpeechKit into your project using CocoaPods, create a `Podfile` file in the project directory:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target 'TargetName' do
pod 'YandexSpeechKit', '~> 3.12.2'
end
```

Then run the command:

```bash
$ pod install
```

### Adding SpeechKit directly

You can add SpeechKit directly to a project as a static library, without using a dependency manager.

To do this, [download the library](https://storage.mds.yandex.net/get-speechkit/67393/YandexSpeechKit-3.12.2_5-ios.zip). Put it in the directory that contains other third-party libraries, or create a directory in the project root and copy the library to it.

In the Xcode project settings, choose `Build Phases` -> `Link Library With Binaries`, then click `+` -> `Add other` and choose SpeechKit. Also add all the frameworks and libraries required by SpeechKit in the same section. For a complete list, see [Requirements](#requirements).

In `Build Phases` -> `Copy Bundle Resources`, add the bundle with the `YandexSpeechKit.bundle` resources, which is located in the `YandexSpeechKit.framework` directory.

In `Build Settings` -> `Search Path` -> `Framework Search Path`, set the path to the directory that contains SpeechKit.

## Requirements

Minimum system requirements:
- iOS 8.0
- Xcode 9+
- OS X 10.12

For the library to work, the following system frameworks and libraries are also necessary:
 - UIKit [required]
 - Foundation [required]
 - AVFoundation [required]
 - AudioToolbox [required]
 - CoreAudio [required]
 - SystemConfiguration [required]
 - CoreLocation [required]
 - QuartzCore [required]
 - CoreGraphics [required]
 - CFNetwork [required]
 - Security [required]
 - Speech [optional]
 - libz [required]
 - libc++ [required]

 > If you are using CocoaPods, all the listed dependencies will be set automatically. If you are adding SpeechKit directly to the project, you will need to add all the dependencies yourself (see [Adding SpeechKit directly](#adding-speechKit-directly)).

## Architecture

### Global settings

* `YSKSpeechKit`
  - `YSKLocationProvider`
  - `YSKEventLogger`
  - `YSKLogLevel`
* `YSKAudioSessionHandler`
  - `YSKAudioSessionSettings`
    - `YSKOtherAudioPolicy`

### Speech recognition

* `YSKOnlineRecognizer`
  - `YSKOnlineRecognizerSettings`
    - `YSKLanguage`
    - `YSKOnlineModel`
    - `YSKSoundFormat`
  - `YSKRecognizing`
  - `YSKRecognizerDelegate`
  - `YSKTrack`
    - `YSKArtist`
  - `YSKRecognition`
    - `YSKRecognitionHypothesis`
      - `YSKRecognitionWord`
    - `YSKBiometry`
      - `YSKBiometryGroup`
      - `YSKBiometryEmotion`
      - `YSKLanguageScore`
* `YSKRecognizerDialogController`
  - `YSKRecognizerDialogControllerDelegate`
  - `YSKDialogSkin`
   - `YSKDarkDialogSkin`
   - `YSKLightDialogSkin`
  - `YSKAudioProcessingMode`
  - `YSKRecognizerDialogEarcons`
    - `YSKSoundBuffer`
    - `YSKDefaultEarconsBundle`
* `YSKNativeRecognizer` _@available(iOS 10, *)_
  - `YSKNativeRecognizerSettings`
* `YSKRecognizerProxy`

### Speech synthesis

* `YSKOnlineVocalizer`
  - `YSKOnlineVocalizerSettings`
    - `YSKLanguage`
    - `YSKVoice`
    - `YSKEmotion`
    - `YSKSoundFormat`
    - `YSKSoundQuality`
  - `YSKVocalizing`
    - `YSKTextSynthesizingMode`
  - `YSKVocalizerDelegate`
  - `YSKSynthesis`
    - `YSKSoundBuffer`

### Voice activation

* `YSKPhraseSpotter`
  - `YSKPhraseSpotterSettings`
  - `YSKPhraseSpotterDelegate`

### Additional functionality

* `YSKAudioSource`
  - `YSKAutoAudioSource`
  - `YSKManualAudioSource`
  - `YSKAudioSourceSettings`
  - `YSKAudioSourceListener`
* `YSKUniProxySession`

## Usage

### YSKSpeechKit

Singleton class for configuring and controlling the library. You don't need to explicitly create or destroy instances of the `YSKSpeechKit` class. To access an object, use the `-sharedInstance` method, which creates an instance of the` YSKSpeechKit` class when accessed the first time. This instance is destroyed when the application closes.

Before using any of the SpeechKit functionality, you must configure `YSKSpeechKit` using the API key (for more information, see [Before you get started](#before-you-get-started)). To do this, call the `-apiKey` method in the application:
```swift
YSKSpeechKit.sharedInstance().apiKey = "developer_api_key"
```

### YSKAudioSessionHandler

Use this class to configure the application's audio session for recording and playing audio. The audio session is a singleton object that configures the audio context of the application so that it can interact with other applications that use audio. The application always uses a single instance of the audio session, so the audio session is configured and activated outside the realm of the `SpeechKit` library components. The `YSKAudioSessionHandler` class makes it easier to configure the audio session. If your application uses an audio session only when working with the `SpeechKit` library, we recommend using this class to configure the audio session. If your application uses the audio session outside of the library (for audio and video playback, recording audio, and so on), you can also use this class, or configure the audio session independently.
```swift
do {
    try YSKAudioSessionHandler.sharedInstance().activateAudioSession(with:settings)
}
catch {
    print("AVAudioSession deactivation did fail with error: \(error.localizedDescription)")
}
```

### YSKOnlineRecognizer

```swift
let settings = YSKOnlineRecognizerSettings(language: YSKLanguage.english(), model: YSKOnlineModel.queries()) // 1
let recognizer = YSKOnlineRecognizer(settings: settings)
recognizer.delegate = self
recognizer.prepare()
recognizer.startRecording() 
```

```swift
func recognizer(_ recognizer: YSKRecognizing, didReceivePartialResults results: YSKRecognition, withEndOfUtterance endOfUtterance: Bool) {
  print("Partial result: \(results.description)")

  if endOfUtterance {
    print("Recognition result: \(results.bestResultText)")
  }
}
```

### YSKOnlineVocalizer

```swift
let settings = YSKOnlineVocalizerSettings(language: YSKLanguage.english())
let vocalizer = YSKOnlineVocalizer(settings: settings)
vocalizer.delegate = self
vocalizer.prepare()
vocalizer.synthesize("What's up kid?", mode: .append)
```

## Credits

The SpeechKit Mobile SDK is created and developed by [Yandex](https://yandex.com/company/). 

## License

The licensing terms for using SpeechKit are described in the [Terms of Use](https://yandex.ru/legal/speechkit/?lang=en).
If you do not agree to any of the terms described in the license agreement, you cannot use SpeechKit.

## Contacts

- If you have any **general questions** about the library, look for answers in the [FAQ](https://tech.yandex.com/speechkit/mobilesdk/doc/intro/faq/concepts/faq-docpage/).
- If you **found a bug in the library**, _and you can provide the exact steps for reproducing it or logs containing the necessary data_, write to us via the [feedback form](https://tech.yandex.com/speechkit/mobilesdk/doc/intro/feedback/concepts/troubleshooting-docpage/).
- If you **need help**, contact us at speechkit@support.yandex.ru.
- If you need to increase the maximum number of requests for speech recognition and/or speech synthesis, send an inquiry to speechkit@support.yandex.ru.
