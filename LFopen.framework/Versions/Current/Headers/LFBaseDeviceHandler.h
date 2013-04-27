//
//  LFBaseDeviceHandler.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFServiceProvider.h"

typedef enum LFDeviceCommand
{
    LFCommandGetNumberOfPresets = 1,
    LFCommandRetNumberOfPresets = 2,
    LFCommandGetPresetList = 3,
    LFCommandRetPresetList = 4,
    LFCommandGetPresetData = 5,
    LFCommandRetPresetData = 6,
    LFCommandGetPlayList = 7,
    LFCommandRetPlayList = 8,
    LFCommandSendResultFileName = 9,
    LFCommandSendResultFileData = 10,
    LFCommandGetVersion = 11,
    LFCommandRetVersion = 12,
    LFCommandGetConsoleVersion = 13,
    LFCommandRetConsoleVersion = 14,
    LFCommandGetMaxPacketSize = 15,
    LFCommandRetMaxPacketSize = 16,
    LFCommandReceivedStream = 17,
}LFDeviceCommand;

@interface LFBaseDeviceHandler : NSObject
{
    id<DeviceCommunicationDelegate> delegate;
    NSString *consoleVersion;
    NSMutableDictionary *dicResultFileData;
    int deviceType;
    int maxPacketSize;
    
    NSString *resultFileName;
}


@property(nonatomic, assign) id<DeviceCommunicationDelegate> delegate;
@property(nonatomic, retain) NSString *consoleVersion;
@property(nonatomic, retain) NSString *resultFileName;
@property int deviceType;
@property int maxPacketSize;

+(LFBaseDeviceHandler*) getInstence;
-(void) sendPresetDataFile:(NSString*)fileData;

@end
