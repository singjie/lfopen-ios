//
//  LFDeviceIOManager.h
//  LFDeviceLib
//
//  Created by Dulip Gayan Dasanayaka on 11/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h> 

@protocol ExternalDeviceDelegate <NSObject>
@required
-(void) didDataRecived:(NSInteger)bytesToRead;
-(void) spaceAvailableToWrite;
@end

@interface LFDeviceIOManager: NSObject <EAAccessoryDelegate, NSStreamDelegate>
{
    EASession *session;
    NSMutableData *dataToWrite;
    NSMutableData *readData;
    id<ExternalDeviceDelegate> delegate;
    //NSUInteger *bytesToRead;
}

@property(nonatomic, retain) EASession *session;
@property(nonatomic, retain) NSMutableData *dataToWrite;
@property(nonatomic, retain) NSMutableData *readData;
@property(nonatomic, assign) id<ExternalDeviceDelegate> delegate;
//@property(nonatomic, assign) NSUInteger *bytesToRead;

+(LFDeviceIOManager *) getSharedInstance;
-(void)writeData:(NSData*)data;
-(NSData *)readData:(NSUInteger)bytesToRead;
-(void)closeSession;

@end

