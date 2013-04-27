//
//  LFAverageSpeedPlot.m
//  LFOpen
//
//  Created by Lee Sing Jie on 25/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFAverageSpeedPlot.h"

#import "LFService.h"
#import <LFopen/LFopen.h>
#import "LFData.h"

@implementation LFAverageSpeedPlot

- (NSString *)xAxisTitle
{
    return @"Time (s)";
}

- (NSString *)yAxisTitle
{
    return @"Average Speed (km/h)";
}

- (CPTColor *)lineColor
{
    return [CPTColor redColor];
}

-(NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)idx
{
    NSArray *datasource = [[LFService sharedInstance] datasource];
    
    LFData *data = datasource[idx];
    
    switch (fieldEnum) {
        case CPTScatterPlotFieldX:
            return @(data.timestamp);
            break;
        case CPTScatterPlotFieldY:
            return @(data.averageSpeed);
            break;
        default:
            break;
    }
    
    return nil;
}

- (void)updateYRangeForXMin:(NSUInteger)min length:(NSUInteger)length
{
    NSArray *datas = [self.plotData subarrayWithRange:NSMakeRange(min, MIN(self.plotData.count - min, length))];
    
    float maxValue = FLT_MIN;
    
    if (datas.count == 0) {
        maxValue = 0;
    }
    
    for (LFData *data in datas) {
        maxValue = fmaxf(maxValue, data.averageSpeed);
    }
    
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)self.graph.defaultPlotSpace;
    
    plotSpace.yRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromFloat(0)
                                                    length:CPTDecimalFromFloat(maxValue * 1.1)];
}

@end
