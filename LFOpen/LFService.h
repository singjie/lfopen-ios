//
//  LFService.h
//  LFOpen
//
//  Created by Lee Sing Jie on 20/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <LFopen/LFopen.h>

@class LFData;

typedef NS_OPTIONS(NSUInteger, LFServiceStatus)
{
    LFServiceStatusDisconnected = 0,
    LFServiceStatusConnected = 1,
    LFServiceStatusActive = 2
};

@interface LFService : NSObject <DeviceCommunicationDelegate>

@property (nonatomic, assign) LFServiceStatus status;

+ (id)sharedInstance;

- (void)registerService;
// Access data via datasource. Elements are of class LFData.
- (NSArray *)datasource;

@end
