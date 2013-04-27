//
//  LFData.m
//  LFOpen
//
//  Created by Lee Sing Jie on 25/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFData.h"

#import <LFopen/LFopen.h>

@implementation LFData

- (id)initWithStreamData:(LFWorkoutStream *)streamData
{
    self = [super init];
    
    if (self) {
        self.incline = streamData.currentIncline;
        self.speed = streamData.currentSpeedKM;
        self.averageSpeed = (float)streamData.accumulatedDistance/streamData.elapsedWorkoutSeconds * 3600;
        self.timestamp = streamData.elapsedWorkoutSeconds;
        self.totalDistance = streamData.accumulatedDistance;
    }
    
    return self;
}

@end
