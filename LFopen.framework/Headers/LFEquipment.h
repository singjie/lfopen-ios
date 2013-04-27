//
//  LFEquipment.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 8/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LFEquipment : NSObject
{
    NSString *buildVersion;
    NSString *devicetype;
    NSString *manufaturedId;
    NSString *softwareVersion;
    NSString *osVersion;
    NSString *mibVersion;
    NSString *mortorControllVersion;;
}

@property (nonatomic, retain) NSString *buildVersion;
@property (nonatomic, retain) NSString *devicetype;
@property (nonatomic, retain) NSString *manufaturedId;
@property (nonatomic, retain) NSString *softwareVersion;
@property (nonatomic, retain) NSString *osVersion;
@property (nonatomic, retain) NSString *mibVersion;
@property (nonatomic, retain) NSString *mortorControllVersion;;

@end
