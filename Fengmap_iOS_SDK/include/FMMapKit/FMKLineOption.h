//
//  FMKLineOption.h
//  FMMapKit
//
//  Created by smallLabel on 2017/10/23.
//  Copyright © 2017年 Fengmap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FMKTypes.h"


/**
 导航模块线类型
 */
@interface FMKLineOption : NSObject

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

/// 线标注物悬浮在模型之上，默认为YES
@property (nonatomic, getter=isFloatModelsEnable) BOOL floatModelsEnable;

@end
