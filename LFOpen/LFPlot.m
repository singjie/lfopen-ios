//
//  LFPlot.m
//  LFOpen
//
//  Created by Lee Sing Jie on 22/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import "LFPlot.h"

#import "LFService.h"

@interface LFPlot ()

@property (nonatomic, assign) float plotYMax;
@property (nonatomic, assign) float plotYMin;

@end

@implementation LFPlot

static NSInteger const kMaxDataPoints = 10;

- (NSArray *)plotData
{
    NSArray *datasource = [[LFService sharedInstance] datasource];
    
    return datasource;
}

- (void)updateRanges
{
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)self.graph.defaultPlotSpace;
    NSUInteger location       = (self.plotData.count >= kMaxDataPoints ? self.plotData.count - kMaxDataPoints : 0);
    
    plotSpace.xRange = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromUnsignedInteger(location)
                                                    length:CPTDecimalFromUnsignedInteger(kMaxDataPoints - 1)];
    
    [self updateYRangeForXMin:location length:kMaxDataPoints-1];
}

- (void)updateYRangeForXMin:(NSUInteger)min length:(NSUInteger)length
{
    
}

- (void)renderInView:(CPTGraphHostingView *)hostingView withTheme:(CPTTheme *)theme
{
    self.graph = [[CPTXYGraph alloc] init];
    
    [self.graph applyTheme:theme];
    
    hostingView.hostedGraph = self.graph;
    
    CPTScatterPlot *boundLinePlot = [[CPTScatterPlot alloc] init];
    boundLinePlot.dataSource     = self;
    boundLinePlot.cachePrecision = CPTPlotCachePrecisionAuto;
    [self.graph addPlot:boundLinePlot];
    
    
    CPTMutableLineStyle *lineStyle = [boundLinePlot.dataLineStyle mutableCopy];
    lineStyle.lineWidth         = 2.0f;
    lineStyle.lineColor         = [self lineColor];
    boundLinePlot.dataLineStyle = lineStyle;
    
    // Setup plot space
    CPTXYPlotSpace *plotSpace = (CPTXYPlotSpace *)self.graph.defaultPlotSpace;
    plotSpace.allowsUserInteraction = NO;
    plotSpace.xRange                = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromFloat(0.0) length:CPTDecimalFromFloat(10.0)];
    plotSpace.yRange                = [CPTPlotRange plotRangeWithLocation:CPTDecimalFromFloat(0.0) length:CPTDecimalFromFloat(10.0)];
    
    CPTXYAxisSet *axisSet = (CPTXYAxisSet *)self.graph.axisSet;
    CPTXYAxis *y = axisSet.yAxis;
    y.title = [self yAxisTitle];
    CPTXYAxis *x = axisSet.xAxis;
    x.title = [self xAxisTitle];
    y.axisConstraints = [CPTConstraints constraintWithLowerOffset:0.0];
}

- (void)reloadData
{
    [self updateRanges];
    
    [self.graph reloadData];
}

- (NSUInteger)numberOfRecordsForPlot:(CPTPlot *)plot
{
    return self.plotData.count;
}

-(NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)idx
{
    NSAssert(NO, @"Please override method in subclass");
    return nil;
}

- (NSString *)xAxisTitle
{
    NSAssert(NO, @"Please override method in subclass");
    return nil;
}

- (NSString *)yAxisTitle
{
    NSAssert(NO, @"Please override method in subclass");
    return nil;
}

- (CPTColor *)lineColor
{
    NSAssert(NO, @"Please override method in subclass");
    return nil;
}

@end
