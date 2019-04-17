//
//  FMKLineNode.h
//  FMMapKit
//
//  Created by FengMap on 15/5/25.
//  Copyright (c) 2015年 FengMap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FMKNode.h"
#import "FMKTypes.h"

@class FMKImageMarker;
@class FMKSegment;

/**
 * 地图线
 */
@interface FMKLineMarker : FMKNode

/// 线标注物悬浮在模型之上，默认为NO
@property (nonatomic, getter=isFloatModelsEnable) BOOL floatModelsEnable;


/**
 添加构造线所用的线段标注
 若要添加带有高度的线标注物必须使用带有高度属性的segment

 @param segment 线段构造对象，用于构建线标注物
 */
- (void)addSegment:(FMKSegment *)segment;

/**
 删除构造线所用的线段标注

 @param segment 线段对象
 */
- (void)removeSegment:(FMKSegment *)segment;

/// 路径线上线段
@property (nonatomic, readonly) NSArray *segments;

/**
 *  添加路径动画
 *
 *  @param imageMarker 路径动画的图片标注物  图片标注物必须已经添加到layer层上且layer已添加到地图上
 */
- (void)addAnimationWithImageMarker:(FMKImageMarker *)imageMarker;

/// 类型
@property (nonatomic, assign) FMKLineType type;
/// 模式
@property (nonatomic, assign) FMKLineMode mode;
/// 路线粗细,默认为2
@property (nonatomic, assign) CGFloat width;
/// 路线颜色，默认为蓝色
@property (nonatomic, copy) UIColor *color;
/// 是否隐藏
@property (nonatomic, assign) BOOL hidden;
/// 线标注物的图片名称  图片需保存在FMBundle
@property (nonatomic, copy) NSString *imageName;
/// 线标注物外颜色
@property (nonatomic, strong) UIColor *lineOutColor;

- (void)refreshLine:(NSArray *)groupIDs isThreeDimension:(BOOL)isThreeDimension DEPRECATED_ATTRIBUTE;
/// 当前线标注物是否为高度调整设置模式
@property (nonatomic) BOOL isThreeDimension DEPRECATED_ATTRIBUTE;
@end
