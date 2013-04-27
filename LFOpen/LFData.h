//
//  LFData.h
//  LFOpen
//
//  Created by Lee Sing Jie on 25/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LFWorkoutStream;

@interface LFData : NSObject

@property (nonatomic, assign) float incline;
@property (nonatomic, assign) float speed;
@property (nonatomic, assign) float averageSpeed;
@property (nonatomic, assign) float totalDistance;
@property (nonatomic, assign) NSTimeInterval timestamp;

- (id)initWithStreamData:(LFWorkoutStream *)streamData;

@end
