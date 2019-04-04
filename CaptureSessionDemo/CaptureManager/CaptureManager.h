//
//  CaptureManager.h
//  CaptureSessionDemo
//
//  Created by Jtg_yao on 2019/4/4.
//  Copyright © 2019年 jzg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol CaptureManagerDelegate <NSObject>

/** 输出流 */
- (void)captureOutput:(AVCaptureFileOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;

@end

@interface CaptureManager : NSObject

// 输出 delegate
@property (nonatomic,assign) id <CaptureManagerDelegate> delegate;

// Device orientation
@property (nonatomic,strong) CMMotionManager *motionManager;


// Session management (会话管理)
@property (nonatomic) dispatch_queue_t sesstionQueue; // Communicate with the session and other session objects on this queue.

// 管理捕获对象AVCaptureInput的视频和音频的输入,协调捕获的输出AVCaptureOutput
@property (nonatomic,strong) AVCaptureSession *sesstion;

// 音、视频的输入
@property (nonatomic,strong) AVCaptureDeviceInput *videoDeviceInput;
// 音、视频的输出
@property (nonatomic,strong) AVCaptureVideoDataOutput *videoDataOutput;

// 输出管理队列
@property (nonatomic) dispatch_queue_t videoDataOutputQueue;

// 相机拍摄预览图层
@property (nonatomic,strong) AVCaptureVideoPreviewLayer *previewLayer;
@property (nonatomic) UIInterfaceOrientation interfaceOrientation;


// Utilities.
@property (nonatomic) UIBackgroundTaskIdentifier backgroundRecordingID;


// init CaptureSessionManager functions
- (void)setup;
- (void)teardown;
//添加暂停和启动方法
- (void)cameraRun;
- (void)cameraStop;

// functions
- (void)cameraToggle;
+ (AVCaptureVideoOrientation)interfaceOrientationToVideoOrientation:(UIInterfaceOrientation)orientation;

@end

NS_ASSUME_NONNULL_END
