//
//  LFPlot.h
//  LFOpen
//
//  Created by Lee Sing Jie on 22/4/13.
//  Copyright (c) 2013 Lee Sing Jie. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CorePlot-CocoaTouch.h"

@interface LFPlot : NSObject <CPTPlotDataSource>

@property (nonatomic, strong) CPTGraph *graph;

- (NSArray *)plotData;

- (void)renderInView:(CPTGraphHostingView *)hostingView withTheme:(CPTTheme *)theme;
- (void)reloadData;

// Must override methods
- (CPTColor *)lineColor;
- (NSString *)xAxisTitle;
- (NSString *)yAxisTitle;
- (NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)idx;

- (void)updateRanges;
- (void)updateYRangeForXMin:(NSUInteger)min length:(NSUInteger)length;

@end
