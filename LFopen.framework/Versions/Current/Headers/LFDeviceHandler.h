//
//  LFDeviceLib.h
//  LFDeviceLib
//
//  Created by Dulip Gayan Dasanayaka on 11/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFDeviceIOManager.h"
#import "XMLReader.h"
#import "LFBaseDeviceHandler.h"

#define ZERO_HEX                             0x00
#define START_BYTE                           0xF1





@interface LFDeviceHandler : LFBaseDeviceHandler<ExternalDeviceDelegate,LFXmlParseDelegate>
{
    @private
    LFDeviceIOManager *deviceConnector;
//    
//    id<DeviceCommunicationDelegate> delegate;
//    NSString *consolVersion;
//    NSMutableDictionary *dicResultFileData;
//    int deviceType;
//    int maxPacketSize;
//    
//    NSString *resultFileName;
}

//@property(nonatomic, assign) id<DeviceCommunicationDelegate> delegate;
//@property(nonatomic, retain) NSString *consolVersion;
//@property(nonatomic, retain) NSString *resultFileName;
//@property int deviceType;
//@property int maxPacketSize;
//
//+(LFDeviceHandler*) getInstence;
//-(void) sendPresetDataFile:(NSString*)fileData;
@end
